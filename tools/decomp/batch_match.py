#!/usr/bin/env python3
"""Batch-match a cluster of stubs that share the same opcode signature.

Workflow:
1. Pick one stub address as the "template" (--template VA).
2. Compute its signature (= bytes with all 4-byte reloc-positions
   nulled).
3. Find every other stub of the same size with the same signature.
4. Print: how many would match, sample addresses, the proposed
   batch name.
5. With --emit-c <path>, emit a per-cluster .c file using
   `__declspec(naked) __asm` to lock the encoding.
6. With --mark <file.c>, mark every member as `matched` in
   `config/symbols.yaml` pointing to <file.c>.

Use this when you've identified a recurring stub shape and want
to match every instance in one PR. See `docs/MATCHING.md` for
the full pattern catalogue.
"""
import struct
import sys
import argparse
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent.parent
sys.path.insert(0, str(ROOT / "tools" / "decomp"))
from discover_functions import parse_symbols, emit_symbols  # noqa: E402

EXE = ROOT / "game" / "MK4.EXE"
SYMBOLS = ROOT / "config" / "symbols.yaml"


def load_pe():
    with open(EXE, "rb") as f:
        d = f.read()
    pe = struct.unpack_from("<I", d, 0x3c)[0]
    ib = struct.unpack_from("<I", d, pe + 24 + 28)[0]
    n = struct.unpack_from("<H", d, pe + 6)[0]
    sz = struct.unpack_from("<H", d, pe + 20)[0]
    for i in range(n):
        s = pe + 24 + sz + i * 40
        if d[s:s+8].rstrip(b"\0") == b".text":
            v_addr = struct.unpack_from("<I", d, s+12)[0]
            r_off = struct.unpack_from("<I", d, s+20)[0]
            return d, ib, v_addr, r_off
    raise RuntimeError(".text not found")


def fetch(d, ib, v_addr, r_off, va, size):
    fo = (va - ib - v_addr) + r_off
    return d[fo:fo+size]


def signature(body):
    """Replace any 4-byte sequence that looks like a reloc with zeroes.

    Recognized opcodes:
      e8 e9          (call/jmp rel32)
      a1 a3          (mov eax, [m32] / mov [m32], eax)
      b8..bf         (mov reg, imm32) - only when imm looks like an
                     image-base-rooted address
      68             (push imm32) - only when imm looks like an addr
      c7 05          (mov [m32], imm32) - both addr and imm masked
      8b/89/8d <r/m=disp32>      (general mov reg/mem with disp32)
      8b/89/8d <SIB rm=100, base=101>  (SIB+disp32, no base register)
      ff 15 / ff 25  (call/jmp [m32]   - IAT-style indirect)
    """
    body = bytes(body)
    sig = bytearray(body)
    i, n = 0, len(sig)

    def mask(start, count):
        for k in range(count):
            if start + k < n:
                sig[start + k] = 0

    while i < n:
        b = sig[i]
        if b in (0xe8, 0xe9) and i + 5 <= n:
            mask(i + 1, 4); i += 5; continue
        if b in (0xa1, 0xa3) and i + 5 <= n:
            mask(i + 1, 4); i += 5; continue
        if b == 0x68 and i + 5 <= n:
            v = struct.unpack_from("<I", sig, i + 1)[0]
            if 0x400000 <= v <= 0xff00000:
                mask(i + 1, 4)
            i += 5; continue
        if 0xb8 <= b <= 0xbf and i + 5 <= n:
            v = struct.unpack_from("<I", sig, i + 1)[0]
            if 0x400000 <= v <= 0xff00000:
                mask(i + 1, 4)
            i += 5; continue
        if b == 0xc7 and i + 10 <= n and sig[i + 1] == 0x05:
            mask(i + 2, 4)
            v = struct.unpack_from("<I", sig, i + 6)[0]
            if 0x400000 <= v <= 0xff00000:
                mask(i + 6, 4)
            i += 10; continue
        if b == 0xff and i + 6 <= n and sig[i + 1] in (0x15, 0x25):
            mask(i + 2, 4); i += 6; continue
        if b in (0x89, 0x8b, 0x8d) and i + 6 <= n and (sig[i + 1] & 0xc7) == 0x05:
            mask(i + 2, 4); i += 6; continue
        if (b in (0x89, 0x8b, 0x8d) and i + 7 <= n
                and (sig[i + 1] & 0xc7) == 0x04
                and (sig[i + 2] & 0xc7) == 0x05):
            mask(i + 3, 4); i += 7; continue
        i += 1
    return bytes(sig)


def main():
    ap = argparse.ArgumentParser(description=__doc__,
                                 formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--template", required=True,
                    help="VA of the template stub (hex, e.g. 0x004acc50)")
    ap.add_argument("--name-prefix",
                    help="C name prefix for matched stubs (e.g. 'Wrapper'); "
                         "default uses the template's existing name")
    ap.add_argument("--mark", metavar="FILE",
                    help="Update symbols.yaml: mark every cluster member "
                         "as `matched` with `file: FILE`")
    args = ap.parse_args()

    d, ib, v_addr, r_off = load_pe()
    template_va = int(args.template, 0)

    rows = parse_symbols(SYMBOLS)
    by_addr = {r["addr"]: r for r in rows}

    if template_va not in by_addr:
        print(f"ERR: template VA {template_va:#x} not in symbols.yaml")
        return 1
    tmpl = by_addr[template_va]
    tmpl_size = tmpl["size"]
    tmpl_body = fetch(d, ib, v_addr, r_off, template_va, tmpl_size)
    while tmpl_body and tmpl_body[-1] == 0x90:
        tmpl_body = tmpl_body[:-1]
    tmpl_actual = len(tmpl_body)
    tmpl_sig = signature(tmpl_body)

    print(f"template: 0x{template_va:08x} size={tmpl_actual} (sym says {tmpl_size})")
    print(f"signature ({tmpl_actual} bytes): {tmpl_sig.hex()}")

    matches = []
    for r in rows:
        if r.get("status") != "stub" or r.get("size", 0) == 0:
            continue
        body = fetch(d, ib, v_addr, r_off, r["addr"], r["size"])
        while body and body[-1] == 0x90:
            body = body[:-1]
        if len(body) != tmpl_actual:
            continue
        if signature(body) != tmpl_sig:
            continue
        matches.append(r["addr"])

    print(f"\nfound {len(matches)} stubs matching this signature")
    for va in matches[:10]:
        print(f"  0x{va:08x}")
    if len(matches) > 10:
        print(f"  ... and {len(matches) - 10} more")

    if args.mark:
        prefix = args.name_prefix or tmpl["name"]
        for va in matches:
            r = by_addr[va]
            r["name"] = f"{prefix}_{va:08x}"
            r["status"] = "matched"
            r["file"] = args.mark
        emit_symbols(SYMBOLS, list(by_addr.values()))
        print(f"\nmarked {len(matches)} stubs as matched, file={args.mark}")


if __name__ == "__main__":
    sys.exit(main() or 0)
