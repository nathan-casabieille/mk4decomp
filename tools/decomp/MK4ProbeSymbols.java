// Probe: dump every symbol (ALL types) as "type<TAB>name<TAB>hexVA", and
// report what data type / symbol sits at a few specific addresses. Used to
// decide how to reconcile Ghidra's `_g_*` overlap-global names by address.
// @category MK4
import ghidra.app.script.GhidraScript;
import ghidra.program.model.symbol.Symbol;
import ghidra.program.model.symbol.SymbolIterator;
import ghidra.program.model.listing.Data;
import ghidra.program.model.address.Address;
import java.io.PrintWriter;

public class MK4ProbeSymbols extends GhidraScript {
    public void run() throws Exception {
        String out = getScriptArgs()[0];
        PrintWriter w = new PrintWriter(out);
        int n = 0;
        SymbolIterator it = currentProgram.getSymbolTable().getAllSymbols(true);
        for (Symbol s : it) {
            w.println(s.getSymbolType() + "\t" + s.getName(true) + "\t"
                      + Long.toHexString(s.getAddress().getOffset()));
            n++;
        }
        w.close();
        println("MK4PROBE wrote " + n + " symbols -> " + out);

        // What is at the addresses our extras_map calls g_xformScratch94 /
        // g_vtxValid, and what does Ghidra's decompiler-visible data there
        // look like (containing Data + its type + componenter)?
        long[] probes = { 0x541f94L, 0x7afff0L, 0x7affd0L };
        for (long a : probes) {
            Address ad = toAddr(a);
            Symbol[] syms = currentProgram.getSymbolTable().getSymbols(ad);
            StringBuilder sb = new StringBuilder("MK4PROBE @" + Long.toHexString(a) + " syms=[");
            for (Symbol s : syms) sb.append(s.getName()).append("(").append(s.getSymbolType()).append(") ");
            sb.append("]");
            Data d = getDataContaining(ad);
            if (d != null) {
                sb.append(" dataAt=" + d.getMinAddress() + " type=" + d.getDataType().getName()
                          + " len=" + d.getLength());
            }
            println(sb.toString());
        }
    }
}
