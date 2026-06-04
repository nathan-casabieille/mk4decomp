// Decompile a set of functions to C, for the NON_MATCHING port pipeline.
// Run headless:
//   analyzeHeadless analysis/ghidra MK4 -process MK4.EXE -readOnly -noanalysis \
//     -scriptPath tools/decomp -postScript MK4Decompile.java <outdir> <addr>...
// Writes <outdir>/<addr>.c (raw Ghidra C) per function found.
// @category MK4
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressFactory;
import java.io.File;
import java.io.PrintWriter;

public class MK4Decompile extends GhidraScript {
    public void run() throws Exception {
        String[] args = getScriptArgs();
        String outdir = args[0];
        new File(outdir).mkdirs();

        DecompInterface dec = new DecompInterface();
        dec.openProgram(currentProgram);
        FunctionManager fm = currentProgram.getFunctionManager();
        AddressFactory af = currentProgram.getAddressFactory();

        int ok = 0;
        for (int i = 1; i < args.length; i++) {
            Address addr = toAddr(args[i]);
            Function fn = (addr == null) ? null : fm.getFunctionAt(addr);
            if (fn == null && addr != null) fn = fm.getFunctionContaining(addr);
            // NOFUNC: the saved project did not auto-analyze this VA, but
            // symbols.yaml says it is a function - disassemble + create it
            // (in-memory; -readOnly discards the change after the run).
            if (fn == null && addr != null) {
                try {
                    if (getInstructionAt(addr) == null) disassemble(addr);
                    fn = createFunction(addr, null);
                } catch (Exception e) { /* fall through to NOFUNC */ }
            }
            if (fn == null) {
                println("MK4DEC NOFUNC " + args[i]);
                continue;
            }
            DecompileResults res = dec.decompileFunction(fn, 60, monitor);
            if (res == null || !res.decompileCompleted()) {
                println("MK4DEC FAIL " + args[i]); continue;
            }
            String c = res.getDecompiledFunction().getC();
            PrintWriter w = new PrintWriter(outdir + "/" + args[i].replace("0x", "") + ".c");
            w.println("/* ghidra name: " + fn.getName() + " */");
            w.print(c);
            w.close();
            println("MK4DEC OK " + args[i] + " " + fn.getName());
            ok++;
        }
        println("MK4DEC DONE " + ok + "/" + (args.length - 1));
    }
}
