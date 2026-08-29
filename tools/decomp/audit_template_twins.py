#!/usr/bin/env python3
"""Report linked twins whose C bodies are IDENTICAL to each other.

A family of wrappers written from one template and never specialised reads
as a correct family until you check the original bytes. src/engine/mstack_calls.c
held ten of them and SEVEN were wrong: same shape, but each real wrapper
saves a different global and loads a different boot-chain argument. One of
the wrong ones was the step that prepends a built scene node under its
parent list.

Identical is not automatically a bug - the four
GuardedSeq_MStackCall_then_CallSetPause_* wrappers really are the same two
calls in the original. This reports families to CHECK, and checking means
disassembling one and comparing: for a push/load/call/pop wrapper the saved
slot, the source global and the callee are all in the first instructions.

`make template-twins-audit`.
"""
import pathlib, re, hashlib, collections, sys
root = pathlib.Path('.')
srcs = [l.strip() for l in (root/'tools/decomp/native_full_srcs.txt').read_text().split('\n') if l.strip()]
groups = collections.defaultdict(list)
for s in srcs:
    p = root / s
    if not p.exists(): continue
    t = p.read_text(errors='ignore')
    for m in re.finditer(r'^(?:static\s+)?\w[\w \*]*\b(\w+)\(void\)\s*\{', t, re.M):
        a = m.start()
        i, depth = t.index('{', m.end()-1), 0
        j = i
        while j < len(t):
            if t[j] == '{': depth += 1
            elif t[j] == '}':
                depth -= 1
                if depth == 0: break
            j += 1
        body = t[i:j+1]
        if body.count('\n') < 4 or '__asm' in body:
            continue
        key = hashlib.sha1(re.sub(r'\s+', ' ', body).encode()).hexdigest()[:12]
        groups[key].append((s, m.group(1)))
n = 0
for k, v in sorted(groups.items(), key=lambda kv: -len(kv[1])):
    if len(v) < 3: continue
    n += 1
    print(f'{len(v)} identical bodies:')
    for s, fn in v[:12]:
        print(f'    {s}: {fn}')
print(f'\n{n} template families of 3 or more')
