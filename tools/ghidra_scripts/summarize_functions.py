# -*- coding: utf-8 -*-
# @category MK4
# @runtime Jython
#
# One-liner summary of one or more functions. Fast triage: name, size,
# Win32 imports (the most diagnostic field), top strings.
#
# Usage: -postScript summarize_functions.py 0x4c4470 0x4b5230 ...

from ghidra.program.model.symbol import RefType


def get_string_at(prog, addr):
    data = prog.getListing().getDataAt(addr)
    if data is not None and data.hasStringValue():
        return data.getValue()
    return None


def summarize(func):
    body = func.getBody()
    listing = currentProgram.getListing()

    imports = []
    strings = []
    n_callees = 0
    seen_callees = set()

    for instr in listing.getInstructions(body, True):
        for ref in instr.getReferencesFrom():
            rt = ref.getReferenceType()
            to = ref.getToAddress()
            if rt.isCall():
                cf = getFunctionAt(to) or getFunctionContaining(to)
                if cf is not None and cf.getEntryPoint() not in seen_callees:
                    seen_callees.add(cf.getEntryPoint())
                    n_callees += 1
                    if cf.isThunk() or cf.isExternal():
                        imports.append(cf.getName())
            elif rt.isData() or rt.isRead():
                s = get_string_at(currentProgram, to)
                if s is not None and len(s.strip()) > 1:
                    strings.append(s)

    print("\n%s @ %s  (size 0x%x, callees %d)" % (
        func.getName(), func.getEntryPoint(),
        body.getNumAddresses(), n_callees))
    if imports:
        print("  imports: %s" % ", ".join(sorted(set(imports))))
    if strings:
        kept = []
        for s in strings[:6]:
            kept.append(s if len(s) <= 50 else s[:47] + "...")
        print("  strings: %s" % " | ".join(repr(s) for s in kept))


args = getScriptArgs()
print("=" * 78)
print("Function summaries (%d)" % len(args))
print("=" * 78)
for raw in args:
    s = raw.lower()
    s = s[2:] if s.startswith("0x") else s
    va = int(s, 16)
    addr = toAddr(va)
    func = getFunctionAt(addr) or getFunctionContaining(addr)
    if not func:
        print("\n[no function at %s]" % addr)
        continue
    summarize(func)
