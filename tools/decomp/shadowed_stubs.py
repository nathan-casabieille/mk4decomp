#!/usr/bin/env python3
"""Find calls that reach a WEAK NO-OP while the same address is already
converted under a different name.

The trap this catches (measured 2026-08-30): src/engine/mstack_push_call_call_pop.c
called `func_00405A40()` - an auto-split placeholder whose name ENCODES the
address 0x405a40 - while that exact address was fully converted as
`ChainWalkPushPop`. The placeholder resolves to the weak no-op in
engine_autostubs.c, so three node-destroy brackets ran without their owner
resolver and destroyed whatever g_fightGroupHead happened to hold.

Nothing else flags this. The build links, the name exists, nm shows a T, and
check_impl.py answers about the name you ASK for - not about the address.

Two detectors, because the names come from two places:
  1. placeholder names that encode an address (func_00XXXXXX, FUN_00XXXXXX,
     sub_XXXXXX) - the address comes from the NAME, since these are usually
     absent from symbols.yaml entirely (func_00405A40 was);
  2. symbols.yaml entries that give one address several names.

Usage:
  build/venv/bin/python tools/decomp/shadowed_stubs.py
  build/venv/bin/python tools/decomp/shadowed_stubs.py --self-test
      re-runs detector 1 against the pre-fix content of the file that carried
      the original bug (git show HEAD~1), so a future refactor cannot quietly
      turn this script into a no-op.
"""
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
SRCS = ROOT / 'tools/decomp/native_full_srcs.txt'
SYMS = ROOT / 'config/symbols.yaml'
CHECK = ROOT / 'tools/decomp/check_impl.py'

PLACEHOLDER = re.compile(r'^(?:func_|FUN_|sub_)0*([0-9A-Fa-f]{5,8})$')


def strip_comments(txt):
    txt = re.sub(r'/\*.*?\*/', ' ', txt, flags=re.DOTALL)
    return re.sub(r'//[^\n]*', ' ', txt)


def called_names(text):
    return {m.group(1) for m in
            re.finditer(r'\b([A-Za-z_]\w*)\s*\(', strip_comments(text))}


def symbols_by_addr():
    out = {}
    for m in re.finditer(r'-\s+addr:\s*(0x[0-9a-fA-F]+)\s*\n\s+name:\s*(\S+)',
                         SYMS.read_text(errors='ignore')):
        out.setdefault(int(m.group(1), 16), []).append(m.group(2))
    return out


def impl_status(names):
    if not names:
        return {}
    res = subprocess.run([sys.executable, str(CHECK)] + sorted(names),
                         capture_output=True, text=True, cwd=ROOT)
    out = {}
    for line in res.stdout.splitlines():
        f = line.split()
        if len(f) >= 2:
            out[f[1]] = f[0]
    return out


def scan(sources):
    """sources: list of (label, text). Returns list of findings."""
    by_addr = symbols_by_addr()
    calls = {}
    for label, text in sources:
        for name in called_names(text):
            calls.setdefault(name, set()).add(label)

    candidates = {}          # name -> (addr, canonical names at that addr)
    for name in calls:
        m = PLACEHOLDER.match(name)
        if m:
            addr = int(m.group(1), 16)
            canon = [n for n in by_addr.get(addr, []) if n != name]
            if canon:
                candidates[name] = (addr, canon)
            continue
        for addr, names in by_addr.items():
            if name in names and len(names) > 1:
                candidates[name] = (addr, [n for n in names if n != name])
                break

    wanted = set(candidates)
    for _, canon in candidates.values():
        wanted.update(canon)
    status = impl_status(wanted)

    findings = []
    for name, (addr, canon) in sorted(candidates.items()):
        if status.get(name) == 'REAL':
            continue
        real = [c for c in canon if status.get(c) == 'REAL']
        if real:
            findings.append((name, addr, status.get(name, '?'), real,
                             sorted(calls[name])))
    return findings


def report(findings, what):
    if not findings:
        print(f'no shadowed conversions in {what}')
        return 0
    print(f'{len(findings)} SHADOWED conversion(s) in {what} - a call reaches '
          f'a no-op while the same address is converted elsewhere:\n')
    for name, addr, st, real, files in findings:
        print(f'  {name} (0x{addr:06x}) is {st}, but {" / ".join(real)} is REAL')
        for f in files:
            print(f'      called from {f}')
    return 1


def main():
    if '--self-test' in sys.argv:
        path = 'src/engine/mstack_push_call_call_pop.c'
        # the fix landed in the working tree; the bug is in the last commit
        for rev in ('HEAD', 'HEAD~1', 'HEAD~2'):
            text = subprocess.run(['git', 'show', f'{rev}:{path}'],
                                  capture_output=True, text=True, cwd=ROOT).stdout
            if 'func_00405A40();' in text:
                found = scan([(f'{rev}:{path}', text)])
                ok = any(f[0] == 'func_00405A40' for f in found)
                print(f'self-test against {rev}: '
                      f'{"PASS - the known bug is flagged" if ok else "FAIL - NOT flagged"}')
                report(found, f'{rev}:{path}')
                return 0 if ok else 1
        print('self-test: could not find the pre-fix revision to test against')
        return 1

    linked = [l.strip() for l in SRCS.read_text().splitlines()
              if l.strip() and not l.lstrip().startswith('#')]
    sources = [(rel, (ROOT / rel).read_text(errors='ignore'))
               for rel in linked if (ROOT / rel).exists()]
    return report(scan(sources), 'the native-full source list')


if __name__ == '__main__':
    raise SystemExit(main())
