"""Per-site reloc address learner.

For every relocation in our compiled OBJs, read the corresponding 4-byte
slot in game/MK4.EXE and back-compute the target VA. Records as
config/reloc_sites.yaml keyed by (obj_path, sec_idx, reloc_va).

This is a ONE-TIME bootstrap step. Once reloc_sites.yaml is checked into
the repo, the synthesizer no longer needs orig MK4.EXE to resolve
relocations - it uses the recorded per-site address table.

The need for a per-site table (rather than a name->addr table) comes
from cases where the same symbol name in the source maps to multiple
distinct VAs in orig (e.g. g_currentNodeIdx used at 0x542044, 0x542048,
0x54205c at different reference sites). The proper long-term fix is to
rename each ambiguous reference to a unique name; until then, the
per-site table provides the disambiguation.

Usage: python3 tools/decomp/learn_sites.py
"""
import os, struct, sys, yaml, re
from pathlib import Path
sys.path.insert(0, 'tools/decomp')
from synthesize import parse_obj_full, build_global_symbol_map, ORIG_EXE, OBJ_DIR, parse_pe_sections

ROOT = Path('.')
SITES = ROOT / 'config' / 'reloc_sites.yaml'

with open(ORIG_EXE,'rb') as f: orig = f.read()
ib, pe_sections = parse_pe_sections(orig)
text_sec = next(s for s in pe_sections if s['name'] == '.text')

with open('config/symbols.yaml') as f: ydat = yaml.safe_load(f)
name_to_entry = {e['name']: e for e in ydat['functions']}
addr_to_name, name_to_addr = build_global_symbol_map()

sites = {}  # key: f"{obj_path}#{sec_idx}#{offset}" -> target_va
for root, dirs, files in os.walk(OBJ_DIR):
    for fn in files:
        if not fn.endswith('.obj'): continue
        obj_path = os.path.join(root, fn)
        rel_obj_path = os.path.relpath(obj_path, str(OBJ_DIR))
        with open(obj_path,'rb') as f: obj = f.read()
        syms, sections = parse_obj_full(obj)
        sec_idx_to_va = {}
        for sym in syms:
            if sym is None: continue
            n = sym['name']
            cl = n[1:] if n.startswith('_') else n
            if cl in name_to_entry and sym['sec'] > 0:
                sec_idx_to_va[sym['sec'] - 1] = name_to_entry[cl]['addr'] - sym['value']

        for sym in syms:
            if sym is None: continue
            n = sym['name']
            cl = n[1:] if n.startswith('_') else n
            if cl not in name_to_entry: continue
            sec_idx = sym['sec']
            if sec_idx <= 0 or sec_idx > len(sections): continue
            sec = sections[sec_idx - 1]
            value = sym['value']
            target_va = name_to_entry[cl]['addr']
            target_size = name_to_entry[cl]['size']

            for r in sec['relocs']:
                if value <= r['va'] < value + target_size:
                    off_in_fn = r['va'] - value
                    if off_in_fn + 4 > target_size: continue
                    if r['sym_idx'] >= len(syms): continue
                    ref_sym = syms[r['sym_idx']]
                    if ref_sym is None: continue

                    # Record orig's actual target VA at this site
                    addend = struct.unpack_from('<I', sec['content'], r['va'])[0]
                    file_off = (target_va - text_sec['vaddr']) + text_sec['raddr']
                    orig_slot = struct.unpack_from('<I', orig, file_off + off_in_fn)[0]

                    if r['type'] == 6:  # DIR32
                        ref_va = (orig_slot - addend) & 0xffffffff
                    elif r['type'] == 20:  # REL32
                        ref_va = (orig_slot + target_va + off_in_fn + 4 - addend) & 0xffffffff
                    else:
                        continue

                    # Sanity
                    if ref_va > 0x1000000:
                        continue
                    key = f'{rel_obj_path}#{sec_idx}#{r["va"]:#x}'
                    sites[key] = ref_va

print(f'Sites recorded: {len(sites)}')
with open(SITES,'w') as f:
    yaml.dump(sites, f)
print(f'Wrote {SITES}')
