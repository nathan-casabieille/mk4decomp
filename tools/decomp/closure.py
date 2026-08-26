#!/usr/bin/env python3
"""
Static call-closure over the original MK4.EXE.

Disassembles each function listed in config/symbols.yaml, collects direct
`call rel32` / `jmp rel32` targets that land on another known function, and
BFS-walks the graph from a chosen root. Cross-references the result against
the native port's live weak-stub frontier so the output is a work-list ordered
by how close each blocker sits to the root.

  closure.py MainLoopStep         # closure + live-stub blockers
  closure.py MainLoopStep --all   # every function in the closure
"""
import argparse, collections, pathlib, re, sys

import capstone, yaml

ROOT = pathlib.Path(__file__).resolve().parents[2]
IMAGE_BASE = 0x00400000


def load_image():
    """Return (bytes, va_of_byte0) for the .text-bearing image."""
    exe = ROOT / "game" / "MK4.EXE"
    data = exe.read_bytes()
    # PE section table -> find the section holding 0x401000
    e_lfanew = int.from_bytes(data[0x3c:0x40], "little")
    nsec = int.from_bytes(data[e_lfanew + 6:e_lfanew + 8], "little")
    opt = int.from_bytes(data[e_lfanew + 20:e_lfanew + 22], "little")
    tab = e_lfanew + 24 + opt
    secs = []
    for i in range(nsec):
        s = data[tab + 40 * i: tab + 40 * (i + 1)]
        vaddr = int.from_bytes(s[12:16], "little")
        vsize = int.from_bytes(s[8:12], "little")
        praw = int.from_bytes(s[20:24], "little")
        secs.append((IMAGE_BASE + vaddr, vsize, praw))
    return data, secs


def read_va(data, secs, va, n):
    for base, size, praw in secs:
        if base <= va < base + size:
            off = praw + (va - base)
            return data[off:off + n]
    return b""


def build_graph(funcs, data, secs):
    """name -> set(callee names), via direct rel32 call/jmp."""
    md = capstone.Cs(capstone.CS_ARCH_X86, capstone.CS_MODE_32)
    by_addr = {f["addr"]: f["name"] for f in funcs}
    graph = collections.defaultdict(set)
    for f in funcs:
        code = read_va(data, secs, f["addr"], f["size"])
        if not code:
            continue
        for ins in md.disasm(code, f["addr"]):
            if ins.mnemonic not in ("call", "jmp"):
                continue
            op = ins.op_str.strip()
            if not op.startswith("0x"):
                continue          # register / memory indirect - not resolvable
            tgt = int(op, 16)
            if tgt in by_addr and by_addr[tgt] != f["name"]:
                graph[f["name"]].add(by_addr[tgt])
    return graph


def live_stubs():
    """Functions native-full resolves ONLY through a weak stub.

    A name in the stub files is not by itself a blocker: as soon as its real TU
    joins native_full_srcs.txt the strong definition wins at link time and the
    stub is inert. So subtract every name that some linked source actually
    defines - what is left is the true frontier.
    """
    # engine_autostubs.c is the GENERATED hollow frontier: every body is
    # `{return 0;}`, so anything it covers is genuinely unimplemented. The
    # hand-written stub files are the opposite - they hold the port's real
    # native replacements (the SDL clock, the SDL present path, the 64-bit CRT
    # helpers), which are weak only so a converted TU can take over later.
    # Counting those as blockers would report work that is already done.
    sdl = ROOT / "src" / "platform" / "sdl"
    pat = r"weak\)\)\s+(?:unsigned\s+|long\s+)*\w+\s+(\w+)\s*\("
    named = set(re.findall(pat, (sdl / "engine_autostubs.c").read_text(errors="ignore")))
    for f in sdl.glob("*.c"):
        if f.name != "engine_autostubs.c":
            named -= set(re.findall(pat, f.read_text(errors="ignore")))
    srcs = [ROOT / l.strip() for l in
            (ROOT / "tools" / "decomp" / "native_full_srcs.txt").read_text().split("\n")
            if l.strip()]
    blob = "".join(p.read_text(errors="ignore") for p in srcs if p.exists())
    return {n for n in named
            if not re.search(r"(?m)^[a-zA-Z_].*\b%s\s*\([^;]*\)\s*\{" % re.escape(n),
                             blob)}


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("root", nargs="?", default="MainLoopStep")
    ap.add_argument("--all", action="store_true")
    ap.add_argument("--max-depth", type=int, default=99)
    args = ap.parse_args()

    cfg = yaml.safe_load((ROOT / "config" / "symbols.yaml").read_text())
    funcs = [f for f in cfg["functions"] if f.get("size")]
    data, secs = load_image()
    graph = build_graph(funcs, data, secs)

    if args.root not in {f["name"] for f in funcs}:
        sys.exit("unknown root: %s" % args.root)

    depth = {args.root: 0}
    q = collections.deque([args.root])
    while q:
        n = q.popleft()
        if depth[n] >= args.max_depth:
            continue
        for c in sorted(graph.get(n, ())):
            if c not in depth:
                depth[c] = depth[n] + 1
                q.append(c)

    stubs = live_stubs()

    fmeta = {f["name"]: f for f in funcs}
    print("closure of %s: %d functions" % (args.root, len(depth)))
    if args.all:
        for n in sorted(depth, key=lambda n: (depth[n], n)):
            print("  d%-2d %-52s %s" % (depth[n], n, fmeta[n].get("file", "?")))
        return

    blockers = sorted((d, n) for n, d in depth.items() if n in stubs)
    print("live-stub blockers on this path: %d" % len(blockers))
    for d, n in blockers:
        f = fmeta[n]
        print("  d%-2d %-52s %5dB  %s" % (d, n, f["size"], f.get("file", "?")))


if __name__ == "__main__":
    main()
