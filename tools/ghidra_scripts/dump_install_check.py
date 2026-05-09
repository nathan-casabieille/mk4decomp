# -*- coding: utf-8 -*-
# @category MK4
# @runtime Jython
#
# Find functions that reference the install-check error string,
# decompile them, and print the result.

from ghidra.app.decompiler import DecompInterface
from ghidra.util.task import ConsoleTaskMonitor

STRING_VA = 0x004f474c   # "Mortal Kombat 4 is not installed."

print("\n" + "=" * 80)
print("MK4 install check — decompilation")
print("=" * 80)

addr = toAddr(STRING_VA)
refs = getReferencesTo(addr)
print("References to %s: %d\n" % (addr, len(refs)))

decompiler = DecompInterface()
decompiler.openProgram(currentProgram)

seen = set()
for ref in refs:
    func = getFunctionContaining(ref.getFromAddress())
    if not func or func.getEntryPoint() in seen:
        continue
    seen.add(func.getEntryPoint())

    print("-" * 80)
    print("function: %s @ %s" % (func.getName(), func.getEntryPoint()))
    print("size:     0x%x bytes" % func.getBody().getNumAddresses())
    print("-" * 80)
    result = decompiler.decompileFunction(func, 60, ConsoleTaskMonitor())
    if result.decompileCompleted():
        print(result.getDecompiledFunction().getC())
    else:
        print("DECOMPILE FAILED: " + result.getErrorMessage())
    print("")
