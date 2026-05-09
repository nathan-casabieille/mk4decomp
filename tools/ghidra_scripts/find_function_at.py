# -*- coding: utf-8 -*-
# @category MK4
# @runtime Jython
#
# Print the function containing each given VA.
# Usage: -postScript find_function_at.py 0x4b075e ...

args = getScriptArgs()
for raw in args:
    s = raw.lower()
    s = s[2:] if s.startswith("0x") else s
    va = int(s, 16)
    addr = toAddr(va)
    func = getFunctionContaining(addr)
    if func:
        print("VA %s -> %s @ %s (size 0x%x)" % (
            addr, func.getName(), func.getEntryPoint(),
            func.getBody().getNumAddresses()))
    else:
        print("VA %s -> (no function)" % addr)
