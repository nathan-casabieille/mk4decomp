#!/usr/bin/env python3
"""Per-function asm diff between rebuilt MK4.exe and the original.

Compares each named function (from config/symbols.yaml) at its original
VA in the matching build vs in game/MK4.EXE. Reports a unified-style
diff per function and a summary with match counts.

Usage:
    python3 tools/decomp/diff.py <original.exe> <rebuilt.exe>

For one-shot single-function diff:
    python3 tools/decomp/diff.py <original.exe> <rebuilt.exe> --addr 0x004acc50
"""
import argparse
import struct
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent.parent
SYMBOLS_FILE = ROOT / "config" / "symbols.yaml"


def load_symbols():
    try:
        import yaml
    except ImportError:
        print("ERROR: install pyyaml - `pip install pyyaml`", file=sys.stderr)
        sys.exit(1)
    with open(SYMBOLS_FILE) as f:
        data = yaml.safe_load(f)
    return data.get("functions", [])


def read_pe_section_offset(pe_path: Path):
    """Return (file_offset, virtual_address_absolute, size) of the .text section.

    virtual_address_absolute = ImageBase + RVA, so callers can pass the
    full VA (e.g. 0x004572d0) into the (va - v_addr) math.
    """
    with open(pe_path, "rb") as f:
        f.seek(0x3c)
        pe_off = struct.unpack("<I", f.read(4))[0]
        f.seek(pe_off + 4)
        coff = f.read(20)
        n_sections = struct.unpack_from("<H", coff, 2)[0]
        opt_size  = struct.unpack_from("<H", coff, 16)[0]
        # Read ImageBase from optional header (offset 28 inside opt for PE32)
        f.seek(pe_off + 4 + 20 + 28)
        image_base = struct.unpack("<I", f.read(4))[0]
        f.seek(pe_off + 4 + 20 + opt_size)
        for _ in range(n_sections):
            section = f.read(40)
            name = section[:8].rstrip(b"\0").decode()
            if name == ".text":
                v_size, v_addr = struct.unpack_from("<II", section, 8)
                raw_size, raw_off = struct.unpack_from("<II", section, 16)
                return raw_off, v_addr + image_base, raw_size
    raise SystemExit(f".text not found in {pe_path}")


def fetch_bytes(pe_path: Path, va: int, size: int) -> bytes:
    raw_off, v_addr, _ = read_pe_section_offset(pe_path)
    file_off = (va - v_addr) + raw_off
    with open(pe_path, "rb") as f:
        f.seek(file_off)
        return f.read(size)


def disasm(byte_blob: bytes, base_va: int) -> str:
    """Pipe bytes through objdump for inline disasm."""
    try:
        out = subprocess.check_output([
            "i686-w64-mingw32-objdump",
            "--disassemble-all",
            "--target=binary",
            "-m", "i386",
            "--adjust-vma=" + hex(base_va),
            "/dev/stdin",
        ], input=byte_blob, stderr=subprocess.DEVNULL)
    except FileNotFoundError:
        out = b"<i686-w64-mingw32-objdump not in PATH>\n"
    return out.decode(errors="replace")


def diff_one(original_pe, rebuilt_pe, name, addr, size):
    orig = fetch_bytes(original_pe, addr, size)
    rebuilt = fetch_bytes(rebuilt_pe, addr, size)
    if orig == rebuilt:
        return True, ""

    # Quick byte-level summary.
    n_diffs = sum(a != b for a, b in zip(orig, rebuilt))
    return False, f"  {name} @ {addr:#x}: {n_diffs}/{size} bytes differ\n"


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument("original")
    ap.add_argument("rebuilt")
    ap.add_argument("--addr", help="Single function VA in hex (full disasm)")
    args = ap.parse_args()
    original = Path(args.original)
    rebuilt = Path(args.rebuilt)

    if args.addr:
        addr = int(args.addr, 16)
        # We don't know size without symbols.yaml - print 256 bytes.
        size = 256
        orig = fetch_bytes(original, addr, size)
        rebuilt_bytes = fetch_bytes(rebuilt, addr, size)
        print("=" * 70)
        print(f"ORIGINAL @ {addr:#x}")
        print("=" * 70)
        print(disasm(orig, addr))
        print("=" * 70)
        print(f"REBUILT @ {addr:#x}")
        print("=" * 70)
        print(disasm(rebuilt_bytes, addr))
        return

    syms = load_symbols()
    matched = 0
    diffs = []
    for s in syms:
        addr = int(s["addr"], 16) if isinstance(s["addr"], str) else s["addr"]
        size = s.get("size", 0)
        if size == 0:
            continue
        ok, msg = diff_one(original, rebuilt, s["name"], addr, size)
        if ok:
            matched += 1
        else:
            diffs.append(msg)

    print(f"Matched: {matched} / {len(syms)} functions")
    if diffs:
        print()
        print("Mismatches:")
        for d in diffs[:50]:
            print(d, end="")
        if len(diffs) > 50:
            print(f"  ... and {len(diffs) - 50} more")


if __name__ == "__main__":
    main()
