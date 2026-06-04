// Dump every global/data symbol Ghidra knows as "name<TAB>VA" so the
// post-processor can reconcile decompiled global names BY ADDRESS (Ghidra's
// names do not reliably match ours - e.g. Ghidra calls 0x542044
// "g_currentNodeIdx" while our g_currentNodeIdx is 0x54205c).
// Run:
//   analyzeHeadless analysis/ghidra MK4 -process MK4.EXE -readOnly -noanalysis \
//     -scriptPath tools/decomp -postScript MK4DumpSymbols.java <outfile>
// @category MK4
import ghidra.app.script.GhidraScript;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolIterator;
import ghidra.program.model.symbol.SymbolType;
import java.io.PrintWriter;

public class MK4DumpSymbols extends GhidraScript {
    public void run() throws Exception {
        String out = getScriptArgs()[0];
        PrintWriter w = new PrintWriter(out);
        int n = 0;
        SymbolIterator it = currentProgram.getSymbolTable().getAllSymbols(true);
        for (Symbol s : it) {
            SymbolType t = s.getSymbolType();
            // data labels + functions; skip locals/params/registers
            if (t == SymbolType.LABEL || t == SymbolType.FUNCTION) {
                w.println(s.getName() + "\t" + s.getAddress().getOffset());
                n++;
            }
        }
        w.close();
        println("MK4SYM wrote " + n + " symbols -> " + out);
    }
}
