# -*- coding: utf-8 -*-
# @category MK4
# @runtime Jython

from ghidra.app.decompiler import DecompInterface
from ghidra.util.task import ConsoleTaskMonitor

# String "c:\source\mk4\win\geogfx\%s" at VA 0x004f6584
GEOGFX_FMT = toAddr(0x004f6584)
print("\nReferences to geogfx format string @ %s" % GEOGFX_FMT)
print("=" * 70)

decompiler = DecompInterface()
decompiler.openProgram(currentProgram)

seen = set()
for ref in getReferencesTo(GEOGFX_FMT):
    func = getFunctionContaining(ref.getFromAddress())
    if not func or func.getEntryPoint() in seen:
        continue
    seen.add(func.getEntryPoint())
    print("\n--- caller: %s @ %s (size 0x%x) ---" % (
        func.getName(), func.getEntryPoint(),
        func.getBody().getNumAddresses()))
    result = decompiler.decompileFunction(func, 60, ConsoleTaskMonitor())
    if result.decompileCompleted():
        print(result.getDecompiledFunction().getC())
    else:
        print("DECOMPILE FAILED")
