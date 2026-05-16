"""Learn unresolved symbol addresses from orig EXE.

For each unresolved reloc in the .obj files, read the corresponding 4-byte
slot in game/MK4.EXE, decode it (REL32 -> absolute, DIR32 -> as-is), and
record symbol_name -> address in config/extras_map.yaml.

This is a one-time discovery pass. Once extras_map.yaml is committed, the
build no longer needs to consult game/MK4.EXE for symbol resolution.

Usage: python3 tools/decomp/learn_addrs.py
"""
import os, struct, sys, yaml, re
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent))
from synthesize import parse_obj_full, build_global_symbol_map, ORIG_EXE, OBJ_DIR, parse_pe_sections, scan_source_aliases

ROOT = Path(__file__).resolve().parent.parent.parent
EXTRAS = ROOT / 'config' / 'extras_map.yaml'

def main():
    with open(ORIG_EXE,'rb') as f: orig = f.read()
    ib, pe_sections = parse_pe_sections(orig)
    text_sec = next(s for s in pe_sections if s['name'] == '.text')

    with open('config/symbols.yaml') as f: ydat = yaml.safe_load(f)
    name_to_entry = {e['name']: e for e in ydat['functions']}
    addr_to_name, name_to_addr = build_global_symbol_map()
    obj_aliases = scan_source_aliases()

    def resolve_yaml_name(obj_sym_name):
        n = obj_sym_name[1:] if obj_sym_name.startswith('_') else obj_sym_name
        if n in name_to_entry: return n
        n2 = re.sub(r'@\d+$', '', n)
        if n2 in name_to_entry: return n2
        if n in obj_aliases and obj_aliases[n] in name_to_entry: return obj_aliases[n]
        if n2 in obj_aliases and obj_aliases[n2] in name_to_entry: return obj_aliases[n2]
        return None

    if EXTRAS.exists():
        with open(EXTRAS) as f:
            extras = yaml.safe_load(f) or {}
    else:
        extras = {}

    learned_count = 0
    learned_names = set()
    for root, dirs, files in os.walk(OBJ_DIR):
        for fn in files:
            if not fn.endswith('.obj'): continue
            with open(os.path.join(root, fn),'rb') as f: obj = f.read()
            syms, sections = parse_obj_full(obj)
            sec_idx_to_va = {}
            for sym in syms:
                if sym is None: continue
                cl = resolve_yaml_name(sym['name'])
                if cl and sym['sec'] > 0:
                    sec_idx_to_va[sym['sec'] - 1] = name_to_entry[cl]['addr'] - sym['value']

            for sym in syms:
                if sym is None: continue
                cl = resolve_yaml_name(sym['name'])
                if cl is None: continue
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
                        ref_n = ref_sym['name']
                        ref_cl = ref_n[1:] if ref_n.startswith('_') else ref_n
                        ref_cl_nostd = re.sub(r'@\d+$', '', ref_cl)
                        ref_imp = '_' + ref_cl_nostd

                        # Skip resolutions where we trust the source: symbols.yaml entries
                        # and IAT slot map. These should never be overridden.
                        if ref_cl in name_to_entry:
                            continue
                        if ref_imp in name_to_addr and ref_imp.startswith('__imp__'):
                            continue
                        # Skip section-relative refs (local labels resolve via per-OBJ section map).
                        if ref_sym['sec'] > 0 and (ref_sym['sec']-1) in sec_idx_to_va:
                            continue
                        # NOTE: we DO override header /* 0xADDR */ comments and existing
                        # extras_map entries - those are derived from manual research and
                        # can be wrong (e.g. g_appFlags annotated as 0xf9f714, actually 0x7af914).
                        # Orig EXE is the ground truth.

                        # Compute target from orig bytes
                        addend = struct.unpack_from('<I', sec['content'], r['va'])[0]
                        file_off = (target_va - text_sec['vaddr']) + text_sec['raddr']
                        orig_slot = struct.unpack_from('<I', orig, file_off + off_in_fn)[0]
                        r_type = r['type']
                        if r_type == 6:  # DIR32
                            # orig_slot = ref_va + addend  =>  ref_va = orig_slot - addend
                            ref_va = (orig_slot - addend) & 0xffffffff
                        elif r_type == 20:  # REL32
                            # orig_slot = ref_va - (target_va + off + 4) + addend
                            # ref_va = orig_slot + (target_va + off + 4) - addend
                            ref_va = (orig_slot + target_va + off_in_fn + 4 - addend) & 0xffffffff
                        else:
                            continue

                        # Accept any value 0..PE_TOP - some "globals" in source are really
                        # small constants used as displacement bases (with reg*scale).
                        if not (0 <= ref_va < 0x1000000):
                            continue

                        if ref_cl in extras and extras[ref_cl] == ref_va:
                            continue  # already correctly recorded
                        if ref_cl in extras and extras[ref_cl] != ref_va:
                            print(f'  override {ref_cl}: {extras[ref_cl]:#x} -> {ref_va:#x}')
                        extras[ref_cl] = ref_va
                        learned_names.add(ref_cl)
                        learned_count += 1

    print(f'Learned {len(learned_names)} new symbol addresses ({learned_count} reloc occurrences)')
    with open(EXTRAS,'w') as f:
        yaml.dump(dict(sorted(extras.items())), f)
    print(f'Wrote {EXTRAS}')

if __name__ == '__main__':
    main()
