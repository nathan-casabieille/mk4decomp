# -*- coding: utf-8 -*-
# @category MK4
# @runtime Jython
#
# Create functions at given addresses (if Ghidra hasn't auto-created them)
# and summarize each. Useful for vtable / function-pointer-table targets.

from ghidra.app.cmd.function import CreateFunctionCmd

args = getScriptArgs()


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
        kept = [s if len(s) <= 50 else s[:47] + "..." for s in strings[:6]]
        print("  strings: %s" % " | ".join(repr(s) for s in kept))
    if seen_callees:
        names = []
        for ep in seen_callees:
            cf = getFunctionAt(ep)
            if cf:
                names.append("%s @ %s" % (cf.getName(), ep))
        print("  calls  : %s" % ", ".join(names[:6]))


for raw in args:
    s = raw.lower()
    s = s[2:] if s.startswith("0x") else s
    va = int(s, 16)
    addr = toAddr(va)
    func = getFunctionAt(addr) or getFunctionContaining(addr)
    if not func:
        cmd = CreateFunctionCmd(addr)
        if cmd.applyTo(currentProgram):
            func = getFunctionAt(addr)
    if not func:
        print("\n[no function at %s - CreateFunctionCmd failed]" % addr)
        continue
    summarize(func)
