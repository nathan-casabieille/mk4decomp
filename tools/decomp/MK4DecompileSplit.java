// Boundary-aware decompile: force a function at EXACTLY our VA + size, even
// when Ghidra merged it into a larger containing function (the name_mismatch
// cases where getFunctionContaining returns the wrong, larger body).
//
// Run headless:
//   analyzeHeadless analysis/ghidra MK4 -process MK4.EXE -readOnly \
//     -scriptPath tools/decomp -postScript MK4DecompileSplit.java \
//     <outdir> <addr:size>...
// Writes <outdir>/<addr>.c (raw Ghidra C) per function. -readOnly discards
// the in-memory function-table edits after the run.
// @category MK4
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.cmd.function.CreateFunctionCmd;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.symbol.SourceType;
import java.io.File;
import java.io.PrintWriter;

public class MK4DecompileSplit extends GhidraScript {
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String outdir = args[0];
        new File(outdir).mkdirs();

        DecompInterface dec = new DecompInterface();
        dec.openProgram(currentProgram);
        FunctionManager fm = currentProgram.getFunctionManager();

        int ok = 0;
        for (int i = 1; i < args.length; i++) {
            String[] parts = args[i].split(":");
            String addrStr = parts[0];
            long size = Long.parseLong(parts[1]);
            Address addr = toAddr(addrStr);
            Address end = addr.add(size - 1);

            // Remove any function that overlaps our exact [addr, end] range so
            // a fresh function can be created at our boundary. Re-find each
            // pass (removal invalidates iterators).
            for (int guard = 0; guard < 8; guard++) {
                Function ov = fm.getFunctionContaining(addr);
                if (ov == null) ov = fm.getFunctionContaining(end);
                if (ov == null) {
                    // also catch a function starting inside our range
                    Function in = fm.getFunctionAt(addr);
                    if (in != null && in.getBody().getNumAddresses() == size) break;
                    Function nxt = fm.getFunctionContaining(addr.add(1));
                    if (nxt == null) break;
                    ov = nxt;
                }
                if (ov.getEntryPoint().equals(addr)
                        && ov.getBody().getNumAddresses() == size) break;
                fm.removeFunction(ov.getEntryPoint());
            }

            try {
                if (getInstructionAt(addr) == null) disassemble(addr);
                AddressSet body = new AddressSet(addr, end);
                CreateFunctionCmd cmd = new CreateFunctionCmd(
                    null, addr, body, SourceType.USER_DEFINED);
                cmd.applyTo(currentProgram, monitor);
            } catch (Exception e) {
                println("MK4SPLIT CREATEERR " + addrStr + " " + e.getMessage());
            }

            Function fn = fm.getFunctionAt(addr);
            if (fn == null) { println("MK4SPLIT NOFUNC " + addrStr); continue; }
            DecompileResults res = dec.decompileFunction(fn, 60, monitor);
            if (res == null || !res.decompileCompleted()) {
                println("MK4SPLIT FAIL " + addrStr); continue;
            }
            String c = res.getDecompiledFunction().getC();
            PrintWriter w = new PrintWriter(
                outdir + "/" + addrStr.replace("0x", "") + ".c");
            w.println("/* ghidra name: " + fn.getName()
                      + " body=" + fn.getBody().getNumAddresses() + " */");
            w.print(c);
            w.close();
            println("MK4SPLIT OK " + addrStr + " " + fn.getName()
                    + " body=" + fn.getBody().getNumAddresses());
            ok++;
        }
        println("MK4SPLIT DONE " + ok + "/" + (args.length - 1));
    }
}
