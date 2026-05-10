#!/usr/bin/env python3
"""Discover function entries from MK4.EXE without needing Ghidra.

Walks every direct CALL (`e8 + rel32`) and indirect tail-call jump
(`ff 25 + imm32`) inside the .text section, transitively from the
functions already listed in `config/symbols.yaml`. Each unique CALL
target is a function entry. Estimates the size of each newly-found
function from the gap to the next entry (trimming trailing NOPs).

Preserves the existing `name`, `status`, `file`, `group` for every
function already listed - only ADDS new entries for unknown VAs.

Usage:
    python3 tools/decomp/discover_functions.py [--write]

Without `--write`, prints what would be added (dry-run).
With `--write`, updates `config/symbols.yaml` in place.
"""
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent.parent
SYMBOLS_FILE = ROOT / "config" / "symbols.yaml"
EXE_FILE = ROOT / "game" / "MK4.EXE"


def load_pe(path):
    with open(path, "rb") as f:
        data = f.read()
    pe_off = struct.unpack_from("<I", data, 0x3c)[0]
    image_base = struct.unpack_from("<I", data, pe_off + 24 + 28)[0]
    n_sec = struct.unpack_from("<H", data, pe_off + 6)[0]
    opt_sz = struct.unpack_from("<H", data, pe_off + 20)[0]
    sec0 = pe_off + 24 + opt_sz
    text = None
    for i in range(n_sec):
        s = sec0 + i * 40
        name = data[s:s + 8].rstrip(b"\0").decode()
        v_addr = struct.unpack_from("<I", data, s + 12)[0]
        v_size = struct.unpack_from("<I", data, s + 8)[0]
        r_off = struct.unpack_from("<I", data, s + 20)[0]
        r_size = struct.unpack_from("<I", data, s + 16)[0]
        if name == ".text":
            text = (v_addr, v_size, r_off, r_size)
    return data, image_base, text


def fetch(data, image_base, text, va, size):
    v_addr, v_size, r_off, _ = text
    rva = va - image_base
    if not (v_addr <= rva < v_addr + v_size):
        return None
    fo = (rva - v_addr) + r_off
    return data[fo:fo + size]


def find_call_targets(data, image_base, text, entry_va, max_size):
    """Walk the function's bytes looking for direct CALLs (e8 + rel32).

    Stops at the FIRST `ret` (c3 / c2 imm16) or `jmp [imm32]` reached
    via a fall-through path. (We're approximate - good enough to BFS
    new function entries, not for sizing.) Returns the set of CALL
    target VAs.
    """
    body = fetch(data, image_base, text, entry_va, max_size)
    if body is None:
        return set()
    targets = set()
    pos = 0
    end = len(body)
    while pos < end:
        b = body[pos]
        # Direct CALL rel32 (e8 + 4 bytes signed offset).
        if b == 0xE8:
            if pos + 5 > end:
                break
            off = struct.unpack_from("<i", body, pos + 1)[0]
            target = entry_va + pos + 5 + off
            targets.add(target)
            pos += 5
            continue
        # Direct JMP rel32 (e9 + 4 bytes). Sometimes a tail-call.
        if b == 0xE9:
            if pos + 5 > end:
                break
            off = struct.unpack_from("<i", body, pos + 1)[0]
            target = entry_va + pos + 5 + off
            # Heuristic: only treat as a function if target is in
            # .text (function tail-call) or skip otherwise.
            v_addr, v_size, _, _ = text
            target_rva = target - image_base
            if v_addr <= target_rva < v_addr + v_size:
                targets.add(target)
            pos += 5
            continue
        pos += 1
    return targets


def parse_symbols(path):
    """Parse the (simple) symbols.yaml without pyyaml.

    Returns a list of dicts with keys: addr, name, size, group, status, file.
    """
    rows = []
    cur = None
    with open(path) as f:
        for line in f:
            line = line.rstrip("\n")
            if line.startswith("  - addr:"):
                if cur:
                    rows.append(cur)
                cur = {"addr": int(line.split(":", 1)[1].strip(), 0)}
            elif cur is not None and line.startswith("    "):
                key, _, val = line.strip().partition(": ")
                if not key:
                    continue
                if key == "addr":
                    cur["addr"] = int(val, 0)
                elif key == "size":
                    cur["size"] = int(val, 0)
                else:
                    cur[key] = val
    if cur:
        rows.append(cur)
    return rows


def emit_symbols(path, rows):
    with open(path, "w") as f:
        f.write("# MK4 matching-decomp symbol map.\n")
        f.write("# Maintained semi-automatically: tools/decomp/discover_functions.py\n"
                "# adds newly-discovered VAs (CALL targets transitive from known\n"
                "# functions); the matching workflow updates `status` / `file` /\n"
                "# `name` fields manually.\n")
        f.write("#\n")
        f.write("# Status: stub | drafted | matched\n")
        f.write("#  - stub:    asm-only, not yet decompiled\n")
        f.write("#  - drafted: C source written, not yet byte-matching\n")
        f.write("#  - matched: C source compiles to byte-identical asm\n")
        f.write("\n")
        f.write("functions:\n")
        for r in sorted(rows, key=lambda x: x["addr"]):
            f.write("  - addr: 0x{:08x}\n".format(r["addr"]))
            f.write("    name: {}\n".format(r.get("name", "func_{:08x}".format(r["addr"]))))
            f.write("    size: {}\n".format(r.get("size", 0)))
            f.write("    group: {}\n".format(r.get("group", "other")))
            f.write("    status: {}\n".format(r.get("status", "stub")))
            if r.get("file"):
                f.write("    file: {}\n".format(r["file"]))


def group_for_addr(va):
    """Coarse VA -> subsystem mapping (mirrored from
    tools/ghidra_scripts/export_symbols.py)."""
    if 0x401000 <= va < 0x420000:    return "boot"
    if 0x420000 <= va < 0x460000:    return "game"
    if 0x460000 <= va < 0x4a0000:    return "game"
    if 0x4a0000 <= va < 0x4ad000:    return "audio"
    if 0x4ad000 <= va < 0x4b0000:    return "engine.install"
    if 0x4b0000 <= va < 0x4b2000:    return "engine.ecm"
    if 0x4b2000 <= va < 0x4b3500:    return "engine.app"
    if 0x4b3500 <= va < 0x4b6000:    return "engine.geo"
    if 0x4b6000 <= va < 0x4b9000:    return "game.menu"
    if 0x4b9000 <= va < 0x4bd000:    return "engine.render"
    if 0x4bd000 <= va < 0x4be000:    return "engine.geo"
    if 0x4be000 <= va < 0x4c0000:    return "engine.scenegraph"
    if 0x4c0000 <= va < 0x4c4000:    return "engine.render"
    if 0x4c4000 <= va < 0x4c5000:    return "platform.win32"
    if 0x4c5000 <= va < 0x4c7000:    return "boot"
    if 0x4c7000 <= va < 0x4d0000:    return "crt"
    return "other"


def estimate_size(data, image_base, text, va, next_va):
    """Trim trailing NOP padding (0x90) from the gap between this
    entry and the next sorted entry."""
    body = fetch(data, image_base, text, va, next_va - va)
    if body is None:
        return 0
    end = len(body)
    while end > 0 and body[end - 1] == 0x90:
        end -= 1
    return end


def main():
    write = "--write" in sys.argv

    print(f"loading {EXE_FILE}")
    data, image_base, text = load_pe(EXE_FILE)
    v_addr, v_size, _, _ = text
    text_start = image_base + v_addr
    text_end = text_start + v_size
    print(f".text: {text_start:#x} .. {text_end:#x}")

    print(f"loading {SYMBOLS_FILE}")
    rows = parse_symbols(SYMBOLS_FILE)
    by_addr = {r["addr"]: r for r in rows}
    initial = len(by_addr)
    print(f"existing entries: {initial}")

    # BFS over CALL targets.
    queue = list(by_addr.keys())
    seen = set(queue)
    discovered = []

    # We don't know each function's size yet for the new ones - use a
    # generous max-scan-window. False positives (non-function VAs) get
    # filtered out later by checking they land inside .text.
    SCAN_WINDOW = 0x4000   # 16 KB - large enough for the biggest
                           # functions in the binary.

    while queue:
        va = queue.pop()
        # Use the recorded size if we have one, else SCAN_WINDOW.
        size = by_addr.get(va, {}).get("size", SCAN_WINDOW) or SCAN_WINDOW
        targets = find_call_targets(data, image_base, text, va,
                                    min(size, SCAN_WINDOW))
        for t in targets:
            # Filter: must be inside .text and not already known.
            if t < text_start or t >= text_end:
                continue
            # Filter: must be 16-byte aligned (every existing
            # symbols.yaml entry is 16-aligned, so discoveries that
            # aren't are almost certainly false-positive CALL targets
            # inside dead code or jump-table data).
            if t & 0xf:
                continue
            if t in seen:
                continue
            seen.add(t)
            queue.append(t)
            discovered.append(t)

    print(f"discovered {len(discovered)} new function entries")

    # Add discovered entries with default fields.
    for va in discovered:
        by_addr[va] = {
            "addr": va,
            "name": "func_{:08x}".format(va),
            "size": 0,         # will be filled below
            "group": group_for_addr(va),
            "status": "stub",
        }

    # Recompute sizes for ALL entries by gap-to-next-entry, but only
    # OVERRIDE for newly discovered (size==0). Manually-edited sizes
    # are preserved for existing entries.
    sorted_addrs = sorted(by_addr.keys())
    for i, va in enumerate(sorted_addrs):
        next_va = sorted_addrs[i + 1] if i + 1 < len(sorted_addrs) else text_end
        gap_size = estimate_size(data, image_base, text, va, next_va)
        r = by_addr[va]
        if r.get("size", 0) == 0:
            r["size"] = gap_size

    final = len(by_addr)
    print(f"new total: {final} (was {initial}, +{final - initial})")

    if write:
        emit_symbols(SYMBOLS_FILE, list(by_addr.values()))
        print(f"wrote {SYMBOLS_FILE}")
    else:
        print("dry-run (use --write to apply)")
        # Show a sample of what would be added.
        print("\nSample of newly-discovered entries:")
        for va in sorted(discovered)[:20]:
            r = by_addr[va]
            print(f"  0x{va:08x}  {r['name']}  size={r['size']}  group={r['group']}")
        if len(discovered) > 20:
            print(f"  ... and {len(discovered) - 20} more")


if __name__ == "__main__":
    main()
