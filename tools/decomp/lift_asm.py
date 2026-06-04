#!/usr/bin/env python3
"""asm -> portable-C lifter for NON_MATCHING twins (Phase 3).

Converts the SIMPLE, recurring naked-function body shapes into
behavior-equivalent C, wrapped as

    #ifdef NON_MATCHING
        <lifted C>
    #else
        <original naked __asm - untouched>
    #endif

so the matching build stays byte-identical while the portable build gets
a real C body. See tools/decomp/AGENT_PORTABLE_MIGRATION.md (Phase 3).

SAFETY: the lifter only emits C for a function it FULLY understands; any
unsupported instruction / operand / structure makes it bail (skip), so it
never emits wrong C for a shape it does not model. The original asm is
preserved both as the matching #else and (commented) above the C, so
every conversion is human-reviewable. Validate every batch with
`make matching` (MD5-identical) + `make portable-check`.

Scope:
  - 32-bit regs (eax ebx ecx edx esi edi); bail on 8/16-bit subregs.
  - operands: dword [g_symbol], dword [reg*4 + 0xNN] (node field via the
    seam, emitted as MK4_NODE_AT), immediates. Bail otherwise.
  - mnemonics: mov add sub and or xor shl shr sar inc dec neg; push/pop of
    a bare reg are ignored (callee-save). Bail on imul/call/lea/...
  - structure:
      * straight-line  -> `ret` or one `jmp <Sym>` (tail-call).
      * single forward conditional (je/jne/jz/jnz) to ONE local label,
        where BOTH arms are straight-line and terminate (ret or jmp Sym)
        -> `if (cond) {...} else {...}`. The flag is taken from the last
        dec/inc/arith/test/cmp before the jump (movs preserve flags).
  - correctness: every memory READ is snapshotted into a temp, so later
    stores cannot corrupt earlier-loaded values.

Usage:
  python3 tools/decomp/lift_asm.py                 # dry-run, whole tree
  python3 tools/decomp/lift_asm.py FILE...         # dry-run, these files
  python3 tools/decomp/lift_asm.py --apply FILE... # rewrite in place

FINDING (2026-06-04): run dry across the whole tree, this lifter converts
0 functions BEYOND the few hand-done templates. The bail histogram shows
why: ~3500 functions bail on `structure` (multi-label / multi-branch
control flow - the cooperative-task FSMs), plus lea / call / _emit / esp
args. The simple straight-line + single-branch shapes are essentially
exhausted (they were the easy ones, already converted). CONCLUSION: a
bespoke pattern lifter has a low ceiling on this corpus; the bulk needs a
real CFG-structuring decompiler. The realistic scalable path is a Ghidra
headless pipeline (decompile -> rename to our symbols -> route node access
through MK4_NODE_AT -> drop into #ifdef NON_MATCHING). This file remains
the safe validator + the home for any future shape that does recur.
"""
import re
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
REGS = ('eax', 'ebx', 'ecx', 'edx', 'esi', 'edi')
CONDJ = ('je', 'jne', 'jz', 'jnz')

FN_RE = re.compile(
    r'(?P<indent>[ \t]*)__declspec\(\s*naked\s*\)\s+void\s+'
    r'(?P<name>\w+)\s*\(\s*void\s*\)\s*\{', re.MULTILINE)

BAILS = {}


class Bail(Exception):
    pass


def body_span(src, open_brace_idx):
    depth, i = 1, open_brace_idx
    while i < len(src) and depth:
        if src[i] == '{':
            depth += 1
        elif src[i] == '}':
            depth -= 1
        i += 1
    return i - 1


def parse_asm(body):
    """Return a list of ('label', name) / ('insn', mnem, [ops]) items."""
    m = re.search(r'__asm\s*\{(.*)\}', body, re.DOTALL)
    if not m:
        raise Bail('no __asm')
    items = []
    for ln in m.group(1).splitlines():
        ln = ln.strip()
        if not ln or ln.startswith(';'):
            continue
        if ln.endswith(':'):
            items.append(('label', ln[:-1].strip()))
            continue
        p = ln.split(None, 1)
        mnem = p[0].lower()
        ops = [o.strip() for o in p[1].split(',')] if len(p) > 1 else []
        items.append(('insn', mnem, ops))
    return items


def imm(tok):
    tok = tok.strip()
    if re.fullmatch(r'0x[0-9a-fA-F]+', tok):
        return '0x%xu' % int(tok, 16)
    if re.fullmatch(r'-?\d+', tok):
        return '%du' % (int(tok) & 0xffffffff)
    return None


class Sim:
    """Simulates a straight-line block over a register expr state."""
    def __init__(self, reg=None):
        self.reg = dict(reg) if reg else {}
        self.stmts = []
        self.ntmp = [0]
        self.flag = None     # ('zero', expr) | ('cmp', a, b)

    def share_counter(self, other):
        self.ntmp = other.ntmp

    def tmp(self, expr):
        n = 't%d' % self.ntmp[0]
        self.ntmp[0] += 1
        self.stmts.append('unsigned int %s = %s;' % (n, expr))
        return n

    def regval(self, r):
        if r not in self.reg:
            raise Bail('uninit %s' % r)
        return self.reg[r]

    def mem_lvalue(self, op):
        m = re.fullmatch(r'dword ptr \[(g_\w+)\]', op)
        if m:
            return m.group(1)
        m = re.fullmatch(
            r'dword ptr \[(eax|ebx|ecx|edx|esi|edi)\*4 \+ (0x[0-9a-fA-F]+)\]', op)
        if m:
            return 'MK4_NODE_AT(unsigned int, %s, 0x%x)' % (
                self.regval(m.group(1)), int(m.group(2), 16))
        raise Bail('mem %s' % op)

    def rvalue(self, op):
        if op in REGS:
            return self.regval(op)
        i = imm(op)
        if i is not None:
            return i
        return self.tmp(self.mem_lvalue(op))   # snapshot reads

    def step(self, mnem, ops):
        if mnem in ('push', 'pop'):
            if ops and ops[0] in REGS:
                return
            raise Bail('%s %s' % (mnem, ops))
        if mnem == 'mov':
            dst, src = ops
            if dst in REGS:
                self.reg[dst] = self.rvalue(src)
            else:
                self.stmts.append('%s = %s;' % (self.mem_lvalue(dst), self.rvalue(src)))
            return
        if mnem in ('add', 'sub', 'and', 'or', 'xor'):
            dst, src = ops
            if dst not in REGS:
                raise Bail('%s mem' % mnem)
            c = {'add': '+', 'sub': '-', 'and': '&', 'or': '|', 'xor': '^'}[mnem]
            self.reg[dst] = '(%s %s %s)' % (self.regval(dst), c, self.rvalue(src))
            self.flag = ('zero', self.reg[dst])
            return
        if mnem in ('shl', 'shr', 'sar'):
            dst, src = ops
            cnt = imm(src)
            if dst not in REGS or cnt is None:
                raise Bail('shift')
            if mnem == 'sar':
                self.reg[dst] = '((int)%s >> %s)' % (self.regval(dst), cnt)
            else:
                self.reg[dst] = '(%s %s %s)' % (self.regval(dst),
                                                '>>' if mnem == 'shr' else '<<', cnt)
            return
        if mnem in ('inc', 'dec', 'neg'):
            dst = ops[0]
            if dst not in REGS:
                raise Bail('%s mem' % mnem)
            if mnem == 'inc':
                self.reg[dst] = '(%s + 1u)' % self.regval(dst)
            elif mnem == 'dec':
                self.reg[dst] = '(%s - 1u)' % self.regval(dst)
            else:
                self.reg[dst] = '(0u - %s)' % self.regval(dst)
            self.flag = ('zero', self.reg[dst])
            return
        if mnem == 'test':
            a, b = ops
            if a == b:
                self.flag = ('zero', self.rvalue(a))
            else:
                self.flag = ('zero', '(%s & %s)' % (self.rvalue(a), self.rvalue(b)))
            return
        if mnem == 'cmp':
            a, b = ops
            self.flag = ('cmp', self.rvalue(a), self.rvalue(b))
            return
        raise Bail('mnem %s' % mnem)

    def run_block(self, insns):
        """Run insns; return terminator: ('ret',) or ('jmp', sym) or None."""
        term = None
        for k, it in enumerate(insns):
            mnem, ops = it[1], it[2]
            if mnem == 'ret':
                term = ('ret',)
                if k != len(insns) - 1:
                    raise Bail('ret mid-block')
                break
            if mnem == 'jmp':
                tgt = ops[0] if ops else ''
                if not re.fullmatch(r'[A-Za-z_]\w*', tgt):
                    raise Bail('jmp %s' % tgt)
                term = ('jmp', tgt)
                if k != len(insns) - 1:
                    raise Bail('jmp mid-block')
                break
            if mnem in CONDJ:
                raise Bail('nested cond')
            self.step(mnem, ops)
        return term


def cond_expr(flag, cc):
    if flag is None:
        raise Bail('cond without flag')
    taken_eq = cc in ('je', 'jz')      # taken when "equal"/zero
    if flag[0] == 'zero':
        return '%s %s 0' % (flag[1], '==' if taken_eq else '!=')
    # cmp a, b
    return '%s %s %s' % (flag[1], '==' if taken_eq else '!=', flag[2])


def term_stmts(term):
    if term is None:
        raise Bail('block falls through')
    if term[0] == 'ret':
        return []
    return ['%s();' % term[1]]


def lift_function(items):
    labels = [(i, it[1]) for i, it in enumerate(items) if it[0] == 'label']
    condjs = [(i, it[1]) for i, it in enumerate(items)
              if it[0] == 'insn' and it[1] in CONDJ]

    if not labels and not condjs:
        # straight-line
        sim = Sim()
        term = sim.run_block(items)
        body = list(sim.stmts) + term_stmts(term)
        return body

    if len(labels) == 1 and len(condjs) == 1:
        lab_i, lab_name = labels[0]
        cj_i, cj_cc = condjs[0]
        cj_tgt = items[cj_i][2][0]
        if cj_tgt != lab_name:
            raise Bail('cond target != label')
        if not (cj_i < lab_i):
            raise Bail('backward branch')
        prefix = items[:cj_i]
        ft_block = items[cj_i + 1:lab_i]      # not-taken (fallthrough)
        lab_block = items[lab_i + 1:]         # taken (label)
        if any(it[0] == 'label' for it in ft_block + lab_block):
            raise Bail('label in arm')
        if not ft_block or not lab_block:
            raise Bail('empty arm')

        sim = Sim()
        if sim.run_block(prefix) is not None:
            raise Bail('prefix terminates')
        cond = cond_expr(sim.flag, cj_cc)

        taken = Sim(sim.reg); taken.share_counter(sim); taken.flag = sim.flag
        t_term = taken.run_block(lab_block)
        nottaken = Sim(sim.reg); nottaken.share_counter(sim); nottaken.flag = sim.flag
        n_term = nottaken.run_block(ft_block)

        body = list(sim.stmts)
        body.append('if (%s) {' % cond)
        body += ['    ' + s for s in taken.stmts] + ['    ' + s for s in term_stmts(t_term)]
        body.append('} else {')
        body += ['    ' + s for s in nottaken.stmts] + ['    ' + s for s in term_stmts(n_term)]
        body.append('}')
        return body

    raise Bail('structure: %d labels %d cond' % (len(labels), len(condjs)))


def emit_c(name, body, orig_asm):
    inner = '\n'.join('    ' + s for s in body) if body else ''
    cmt = '/* lifted from asm (see #else for the matching form):\n'
    for ln in orig_asm:
        if ln[0] == 'label':
            cmt += ' *   %s:\n' % ln[1]
        else:
            cmt += ' *   %s %s\n' % (ln[1], ', '.join(ln[2]))
    cmt += ' */'
    return '%s\nvoid %s(void) {\n%s\n}' % (cmt, name, inner)


def process_file(path, apply):
    src = path.read_text()
    edits, results = [], []
    for m in FN_RE.finditer(src):
        if src[:m.start()].rstrip().endswith('#else'):
            continue                       # already wrapped
        end = body_span(src, m.end())
        body = src[m.end():end]
        try:
            items = parse_asm(body)
            c_body = lift_function(items)
        except Bail as b:
            key = re.sub(r'[0-9].*', '', str(b)).strip() or str(b)
            BAILS[key] = BAILS.get(key, 0) + 1
            continue
        c_code = emit_c(m.group('name'), c_body, items)
        edits.append((m.start(), end + 1, c_code))
        results.append((m.group('name'), c_code))

    if apply and edits:
        for start, end, c_code in reversed(edits):
            block = src[start:end]
            indent = re.match(r'[ \t]*', block).group(0)
            src = (src[:start] + indent + '#ifdef NON_MATCHING\n' + c_code +
                   '\n#else\n' + block.lstrip() + '\n#endif' + src[end:])
        path.write_text(src)
    return results


def main():
    args = [a for a in sys.argv[1:] if a != '--apply']
    apply = '--apply' in sys.argv
    files = [Path(a) for a in args] if args else sorted((ROOT / 'src').rglob('*.c'))
    total = 0
    for f in files:
        try:
            res = process_file(f, apply)
        except Exception:
            continue
        for name, c_code in res:
            total += 1
            if not apply:
                print('=== %s  [%s] ===' % (name, f.relative_to(ROOT)))
                print(c_code)
                print()
    print('%s %d function(s)%s' % ('APPLIED' if apply else 'LIFTABLE', total,
                                   '' if apply else ' (dry-run)'))
    if not apply and BAILS:
        print('\nbail reasons (top):')
        for k, v in sorted(BAILS.items(), key=lambda kv: -kv[1])[:15]:
            print('  %5d  %s' % (v, k))


if __name__ == '__main__':
    main()
