# -*- coding: utf-8 -*-
# @category MK4
# @runtime Jython
#
# Comprehensive inspection of one or more functions:
#   - basic info (name, address, size, signature)
#   - callers (who calls this function)
#   - callees (what it calls — both internal and Win32 imports)
#   - strings it references
#
# Use this to triage a function before deciding to decompile + rename.
# Pass addresses as -scriptPostArgs.

from ghidra.program.model.symbol import RefType
from ghidra.program.model.address import AddressSet


def get_string_at(prog, addr):
    data = prog.getListing().getDataAt(addr)
    if data is not None and data.hasStringValue():
        return data.getValue()
    return None


def inspect(func):
    body = func.getBody()
    print("=" * 72)
    print("function : %s" % func.getName())
    print("entry    : %s" % func.getEntryPoint())
    print("size     : 0x%x bytes" % body.getNumAddresses())
    print("signature: %s" % func.getSignature().getPrototypeString(False))
    print("=" * 72)

    # Callers
    refs = getReferencesTo(func.getEntryPoint())
    callers = {}
    for ref in refs:
        if ref.getReferenceType().isCall():
            ca = ref.getFromAddress()
            cf = getFunctionContaining(ca)
            if cf is not None:
                callers.setdefault(cf, []).append(ca)
    print("\nCallers (%d):" % len(callers))
    if not callers:
        print("  (none — possibly entry point or vtable target)")
    for cf, sites in sorted(callers.items(), key=lambda kv: kv[0].getEntryPoint().getOffset()):
        print("  %s  %-32s  (%d call site%s)" % (
            cf.getEntryPoint(), cf.getName(),
            len(sites), "" if len(sites) == 1 else "s"))

    # Callees (functions called from within this function)
    callees = {}
    strings_used = []
    listing = currentProgram.getListing()
    for instr in listing.getInstructions(body, True):
        for ref in instr.getReferencesFrom():
            rt = ref.getReferenceType()
            to = ref.getToAddress()
            if rt.isCall():
                cf = getFunctionAt(to) or getFunctionContaining(to)
                if cf is not None:
                    callees.setdefault(cf, 0)
                    callees[cf] += 1
            elif rt.isData() or rt.isRead():
                s = get_string_at(currentProgram, to)
                if s is not None and len(s.strip()) > 1:
                    strings_used.append((instr.getAddress(), to, s))
    print("\nCallees (%d distinct):" % len(callees))
    for cf, n in sorted(callees.items(), key=lambda kv: -kv[1])[:40]:
        # Mark imports vs internal
        is_import = cf.isThunk() or cf.isExternal()
        tag = "[import]" if is_import else "[       ]"
        print("  %s %s  %-30s x%d" % (tag, cf.getEntryPoint(), cf.getName(), n))

    print("\nStrings referenced (%d):" % len(strings_used))
    for site, target, s in strings_used[:30]:
        snippet = s if len(s) <= 60 else s[:57] + "..."
        print("  @%s -> %s : %r" % (site, target, snippet))


args = getScriptArgs()
for raw in args:
    s = raw.lower()
    s = s[2:] if s.startswith("0x") else s
    va = int(s, 16)
    addr = toAddr(va)
    func = getFunctionAt(addr) or getFunctionContaining(addr)
    if not func:
        print("no function at %s" % addr)
        continue
    print("")
    inspect(func)
