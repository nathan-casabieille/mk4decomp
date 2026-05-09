# -*- coding: utf-8 -*-
# @category MK4
# @runtime Jython

from ghidra.app.decompiler import DecompInterface
from ghidra.util.task import ConsoleTaskMonitor

# String "ESF_Open()" at VA 0x004f47c0 (file off 0xf25c0)
ESF_OPEN_STR = toAddr(0x004f47c0)
print("\nReferences to ESF_Open string @ %s" % ESF_OPEN_STR)
print("=" * 70)

decompiler = DecompInterface()
decompiler.openProgram(currentProgram)

seen = set()
for ref in getReferencesTo(ESF_OPEN_STR):
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
