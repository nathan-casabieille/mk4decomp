#!/usr/bin/env python3
"""Pre-populate reloc_sites.yaml with per-site overrides for ALL `$L*` local
labels in a specified OBJ, so that bulk conversion of that OBJ's source file
doesn't desync from extras_map's cached name->addr mappings.

The override mechanism is name-independent: it pins `obj#sec#va: target_addr`.
Target addresses come from reading orig MK4.EXE bytes at the reloc site
(DIR32/REL32 decode), which is the ground truth.

After running this on misc_matchesQQ.obj, bulk conversion of QQ.c functions
can proceed: any `$L*` reloc lookup uses the pre-pinned per-site value
instead of the stale extras_map entry.

Usage: python3 tools/decomp/pin_local_labels.py engine/misc_matchesQQ.obj
"""
import argparse, os, re, struct, sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).parent))
from synthesize import parse_obj_full, ORIG_EXE, OBJ_DIR, parse_pe_sections

ROOT = Path(__file__).resolve().parent.parent.parent
SITES = ROOT / "config" / "reloc_sites.yaml"
SYMS = ROOT / "config" / "symbols.yaml"


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("obj_relative", help="Relative path under build/obj (e.g. engine/misc_matchesQQ.obj)")
    ap.add_argument("--dry-run", action="store_true")
    args = ap.parse_args()

    obj_path = ROOT / "build" / "obj" / args.obj_relative
    if not obj_path.exists():
        print(f"ERROR: {obj_path} not found")
        sys.exit(1)

    with open(ORIG_EXE, "rb") as f:
        orig = f.read()
    _ib, pe_sections = parse_pe_sections(orig)
    text_sec = next(s for s in pe_sections if s["name"] == ".text")

    import yaml
    with open(SYMS) as f:
        ydat = yaml.safe_load(f)
    name_to_entry = {e["name"]: e for e in ydat["functions"]}

    with open(obj_path, "rb") as f:
        obj_data = f.read()
    syms, sections = parse_obj_full(obj_data)

    def resolve_yaml(obj_name):
        n = obj_name[1:] if obj_name.startswith("_") else obj_name
        if n in name_to_entry:
            return n
        n2 = re.sub(r"@\d+$", "", n)
        return n2 if n2 in name_to_entry else None

    # Walk yaml-known functions; for each $L* reloc within, compute orig target.
    new_entries = {}
    for sym in syms:
        if sym is None:
            continue
        cl = resolve_yaml(sym["name"])
        if cl is None or sym["sec"] <= 0:
            continue
        if sym["sec"] > len(sections):
            continue
        sec_idx = sym["sec"]
        sec = sections[sec_idx - 1]
        value = sym["value"]
        entry = name_to_entry[cl]
        target_va = entry["addr"]
        target_size = entry["size"]
        if value + target_size > len(sec["content"]):
            continue

        for r in sec["relocs"]:
            if not (value <= r["va"] < value + target_size):
                continue
            if r["sym_idx"] >= len(syms):
                continue
            ref_sym = syms[r["sym_idx"]]
            if ref_sym is None:
                continue
            ref_name = ref_sym["name"]
            ref_clean = ref_name[1:] if ref_name.startswith("_") else ref_name
            if not ref_clean.startswith("$L"):
                continue
            off_in_fn = r["va"] - value
            if off_in_fn + 4 > target_size:
                continue
            addend = struct.unpack_from("<I", sec["content"], r["va"])[0]
            file_off = (target_va - text_sec["vaddr"]) + text_sec["raddr"]
            orig_slot = struct.unpack_from("<I", orig, file_off + off_in_fn)[0]
            rtype = r["type"]
            if rtype == 6:  # DIR32
                ref_va = (orig_slot - addend) & 0xFFFFFFFF
            elif rtype == 20:  # REL32
                ref_va = (orig_slot + target_va + off_in_fn + 4 - addend) & 0xFFFFFFFF
            else:
                continue
            key = f"{args.obj_relative}#{sec_idx}#{r['va']:#x}"
            new_entries[key] = ref_va

    print(f"Found {len(new_entries)} $L* reloc sites in {args.obj_relative}")

    # Merge into reloc_sites.yaml
    existing_lines = SITES.read_text().splitlines()
    existing_keys = {}
    for line in existing_lines:
        m = re.match(r"^([^:]+):\s*(\d+)\s*$", line)
        if m:
            existing_keys[m.group(1).strip()] = int(m.group(2))

    added = 0
    for key, val in new_entries.items():
        if key in existing_keys and existing_keys[key] == val:
            continue
        if key in existing_keys and existing_keys[key] != val:
            print(f"  conflict: {key} existing={hex(existing_keys[key])} new={hex(val)}")
            continue
        added += 1

    print(f"Adding {added} new entries")
    if args.dry_run:
        return

    # Append new entries, then sort + dedupe
    merged = dict(existing_keys)
    for key, val in new_entries.items():
        if key not in merged:
            merged[key] = val

    with open(SITES, "w") as f:
        for key in sorted(merged):
            f.write(f"{key}: {merged[key]}\n")
    print(f"Wrote {SITES}")


if __name__ == "__main__":
    main()
