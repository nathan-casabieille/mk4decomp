# -*- coding: utf-8 -*-
# @category MK4
# @runtime Jython
#
# Decompile one or more functions by virtual address.
# Pass addresses as -scriptPostArgs (hex with or without 0x prefix).
#
# Example:
#   analyzeHeadless ... -postScript decompile_at.py 0x4acc50 4ad210

from ghidra.app.decompiler import DecompInterface
from ghidra.util.task import ConsoleTaskMonitor

args = getScriptArgs()
if not args:
    print("decompile_at.py: no addresses given (pass via -scriptPostArgs)")

decompiler = DecompInterface()
decompiler.openProgram(currentProgram)

for raw in args:
    s = raw.lower()
    s = s[2:] if s.startswith("0x") else s
    va = int(s, 16)
    addr = toAddr(va)
    func = getFunctionAt(addr) or getFunctionContaining(addr)
    print("\n" + "=" * 80)
    if not func:
        print("[no function at %s]" % addr)
        continue
    print("function: %s @ %s   size: 0x%x bytes" % (
        func.getName(), func.getEntryPoint(),
        func.getBody().getNumAddresses()))
    print("=" * 80)
    result = decompiler.decompileFunction(func, 60, ConsoleTaskMonitor())
    if result.decompileCompleted():
        print(result.getDecompiledFunction().getC())
    else:
        print("DECOMPILE FAILED: " + result.getErrorMessage())
