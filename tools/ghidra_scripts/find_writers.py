# -*- coding: utf-8 -*-
# @category MK4
# @runtime Jython
#
# Find all functions that write to one or more given addresses.
# Useful for locating producer functions when the consumer is known.
#
# Usage:
#   -postScript find_writers.py 0x00f85b40 [<addr> ...]

from ghidra.program.model.symbol import RefType


def is_write(ref):
    rt = ref.getReferenceType()
    return rt.isWrite() or rt == RefType.WRITE


args = getScriptArgs()
if not args:
    print("usage: find_writers.py <addr> [<addr> ...]")

for raw in args:
    s = raw.lower()
    s = s[2:] if s.startswith("0x") else s
    va = int(s, 16)
    addr = toAddr(va)

    sym = currentProgram.getSymbolTable().getPrimarySymbol(addr)
    name = sym.getName() if sym else "<no symbol>"

    print("\n" + "=" * 70)
    print("WRITES to %s (%s)" % (addr, name))
    print("=" * 70)

    refs = list(getReferencesTo(addr))
    write_refs = [r for r in refs if is_write(r)]
    read_refs = [r for r in refs if not is_write(r)]

    print("  total refs : %d  (writes: %d, reads: %d)\n" % (
        len(refs), len(write_refs), len(read_refs)))

    # Group write refs by containing function
    by_func = {}
    for ref in write_refs:
        site = ref.getFromAddress()
        func = getFunctionContaining(site)
        if func is None:
            by_func.setdefault(("<no function>", None), []).append(site)
        else:
            by_func.setdefault((func.getName(), func.getEntryPoint()), []).append(site)

    if not by_func:
        print("  (no writes found)")
        continue

    # Sort: by function entry point
    items = sorted(by_func.items(), key=lambda kv: (kv[0][1].getOffset() if kv[0][1] else 0))
    for (fname, fep), sites in items:
        if fep:
            func = getFunctionAt(fep)
            sz = func.getBody().getNumAddresses() if func else 0
            print("  %s @ %s  size=0x%x  writes=%d" % (
                fname, fep, sz, len(sites)))
            for site in sites[:3]:
                print("        @%s" % site)
            if len(sites) > 3:
                print("        ... and %d more sites" % (len(sites) - 3))
        else:
            print("  <no function>  writes=%d" % len(sites))
            for site in sites[:5]:
                print("        @%s" % site)
