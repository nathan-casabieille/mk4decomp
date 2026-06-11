#!/usr/bin/env python3
"""Re-route raw packed-ptr derefs in NON_MATCHING twins through the seam.

Transforms, inside #ifdef NON_MATCHING twin bodies only:
    *(T *)(EXPR * 4)        -> *MK4_NODE(T, EXPR)
    *(T *)(EXPR * 4 + OFF)  -> MK4_NODE_AT(T, EXPR, OFF)
which is the IDENTITY of the raw form under the verifier/matching (MK4_NODE(idx)
== (T*)(idx*4) there) but arena-correct under MK4_ARENA. EXPR may contain nested
parens / casts (e.g. the arena read of g_currentNodeIdx); balanced-paren scan
handles that. Lvalue `*(T*)(...) = x` becomes `MK4_NODE_AT(...) = x` / `*MK4_NODE(...) = x`
- still a valid lvalue. Returns count of rewrites.
"""
import re, sys
TYPES = r'(?:unsigned int|int|uint|undefined4|u32|short|u16|unsigned short|byte|char|u8|unsigned char)'
CAST = re.compile(r'\*\(\s*(' + TYPES + r')\s*\*\s*\)\s*\(')

def match_paren(s, i):                 # s[i] == '(' ; return index after matching ')'
    d = 0
    while i < len(s):
        if s[i] == '(': d += 1
        elif s[i] == ')':
            d -= 1
            if d == 0: return i
        i += 1
    return -1

def split_times4(inner):
    """If inner is `<expr> * 4` or `<expr> * 4 + <off>` at top level, return
    (expr, off_or_None). Scan for the LAST top-level '* 4'."""
    depth = 0; i = 0; cut = -1
    while i < len(inner):
        c = inner[i]
        if c == '(': depth += 1
        elif c == ')': depth -= 1
        elif depth == 0 and c == '*':
            m = re.match(r'\*\s*4\b', inner[i:])
            if m: cut = i; cutend = i + m.end()
        i += 1
    if cut < 0: return None
    expr = inner[:cut].strip()
    rest = inner[cutend:].strip()
    if rest == '': return (expr, None)
    m = re.match(r'\+\s*(.+)$', rest)
    if m: return (expr, m.group(1).strip())
    return None                         # e.g. `* 4 * something` - leave alone

def transform_block(blk):
    out = []; i = 0; n = 0
    while True:
        m = CAST.search(blk, i)
        if not m:
            out.append(blk[i:]); break
        T = m.group(1)
        popen = m.end() - 1
        pclose = match_paren(blk, popen)
        if pclose < 0:
            out.append(blk[i:m.end()]); i = m.end(); continue
        inner = blk[popen+1:pclose]
        sp = split_times4(inner)
        out.append(blk[i:m.start()])
        if sp is None:
            out.append(blk[m.start():pclose+1])
        else:
            expr, off = sp
            if off is None:
                out.append('*MK4_NODE(%s, %s)' % (T, expr))
            else:
                out.append('MK4_NODE_AT(%s, %s, %s)' % (T, expr, off))
            n += 1
        i = pclose + 1
    return ''.join(out), n

def process(path):
    s = open(path).read()
    total = 0; res = []; i = 0
    for m in re.finditer(r'#ifdef NON_MATCHING\b', s):
        j = s.find('#else', m.end())
        if j < 0: j = s.find('#endif', m.end())
        if j < 0: continue
        res.append(s[i:m.end()])
        body, n = transform_block(s[m.end():j])
        res.append(body); total += n; i = j
    res.append(s[i:])
    if total:
        # ensure MK4_NODE_AT/MK4_NODE are reachable (ghidra_types.h -> mem_model.h)
        out = ''.join(res)
        open(path, 'w').write(out)
    return total

if __name__ == '__main__':
    for p in sys.argv[1:]:
        n = process(p)
        print('%-55s %d rewrites' % (p, n))
