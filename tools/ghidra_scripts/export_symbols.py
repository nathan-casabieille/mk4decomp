# -*- coding: utf-8 -*-
# @category MK4
# @runtime Jython
#
# Export all renamed (= USER_DEFINED) functions from the Ghidra DB
# into config/symbols.yaml — the single source of truth for the
# matching-decomp progress tracker and diff tool.
#
# Run via:
#   analyzeHeadless analysis/ghidra MK4 -process MK4.EXE -noanalysis
#       -scriptPath tools/ghidra_scripts -postScript export_symbols.py

from ghidra.program.model.symbol import SourceType

OUT_PATH = "/Users/nathan_casab/Documents/MK4/config/symbols.yaml"


def group_for_addr(va):
    """Coarse grouping of functions by VA range — matches our subsystem
    organization in src/. Tweak as the codebase fills in."""
    if 0x401000 <= va < 0x420000:    return "boot"
    if 0x420000 <= va < 0x460000:    return "game"
    if 0x460000 <= va < 0x4a0000:    return "game"
    if 0x4a0000 <= va < 0x4ad000:    return "audio"
    if 0x4ad000 <= va < 0x4b0000:    return "engine.install"
    if 0x4b0000 <= va < 0x4b2000:    return "engine.ecm"
    if 0x4b2000 <= va < 0x4b3500:    return "engine.app"
    if 0x4b3500 <= va < 0x4b6000:    return "engine.geo"
    if 0x4b6000 <= va < 0x4b9000:    return "game.menu"
    if 0x4b9000 <= va < 0x4bd000:    return "engine.render"
    if 0x4bd000 <= va < 0x4be000:    return "engine.geo"
    if 0x4be000 <= va < 0x4c0000:    return "engine.scenegraph"
    if 0x4c0000 <= va < 0x4c4000:    return "engine.render"
    if 0x4c4000 <= va < 0x4c5000:    return "platform.win32"
    if 0x4c5000 <= va < 0x4c7000:    return "boot"
    if 0x4c7000 <= va < 0x4d0000:    return "crt"
    return "other"


def main():
    fm = currentProgram.getFunctionManager()
    rows = []
    for f in fm.getFunctions(True):
        # Only export user-renamed functions (skip auto-named FUN_* / LAB_*).
        sym = f.getSymbol()
        if sym.getSource() not in (SourceType.USER_DEFINED, SourceType.IMPORTED):
            continue
        name = f.getName()
        if name.startswith("FUN_") or name.startswith("LAB_"):
            continue
        addr = f.getEntryPoint().getOffset()
        size = f.getBody().getNumAddresses()
        rows.append((addr, name, size))

    rows.sort(key=lambda r: r[0])

    with open(OUT_PATH, "w") as out:
        out.write("# MK4 matching-decomp symbol map.\n")
        out.write("# Auto-generated from Ghidra (tools/ghidra_scripts/export_symbols.py).\n")
        out.write("# Edit by re-running the export — manual changes are clobbered.\n")
        out.write("#\n")
        out.write("# Status: stub | drafted | matched\n")
        out.write("#  - stub:    asm-only, not yet decompiled\n")
        out.write("#  - drafted: C source written, not yet byte-matching\n")
        out.write("#  - matched: C source compiles to byte-identical asm\n")
        out.write("\n")
        out.write("functions:\n")
        for addr, name, size in rows:
            out.write("  - addr: 0x{:08x}\n".format(addr))
            out.write("    name: {}\n".format(name))
            out.write("    size: {}\n".format(size))
            out.write("    group: {}\n".format(group_for_addr(addr)))
            out.write("    status: stub\n")

    print("Exported %d functions to %s" % (len(rows), OUT_PATH))


main()
