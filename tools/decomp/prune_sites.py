"""Prune redundant entries from config/reloc_sites.yaml.

An entry is redundant when removing it would still yield the same target_va
via synthesize.py's fallback chain (name_to_entry -> name_to_addr -> name
suffix -> section-relative). Keeps only the truly-ambiguous sites where the
source's symbol name maps to multiple distinct orig VAs at different
reference sites.

Run after learn_sites.py / after any change to extras_map / symbols.yaml /
header annotations to maintain a minimal reloc_sites.yaml.

Usage: python3 tools/decomp/prune_sites.py
"""
import os, sys, yaml, re
from pathlib import Path
sys.path.insert(0, str(Path(__file__).parent))
from synthesize import parse_obj_full, build_global_symbol_map, OBJ_DIR, scan_source_aliases


def main():
    with open('config/symbols.yaml') as f: ydat = yaml.safe_load(f)
    name_to_entry = {e['name']: e for e in ydat['functions']}
    addr_to_name, name_to_addr = build_global_symbol_map()
    obj_aliases = scan_source_aliases()
    with open('config/reloc_sites.yaml') as f: sites = yaml.safe_load(f) or {}

    def resolve_yaml_name(n_obj):
        n = n_obj[1:] if n_obj.startswith('_') else n_obj
        if n in name_to_entry: return n
        n2 = re.sub(r'@\d+$', '', n)
        if n2 in name_to_entry: return n2
        if n in obj_aliases and obj_aliases[n] in name_to_entry: return obj_aliases[n]
        if n2 in obj_aliases and obj_aliases[n2] in name_to_entry: return obj_aliases[n2]
        return None

    fallback_resolutions = {}
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
                entry = name_to_entry[cl]
                target_size = entry['size']
                for r in sec['relocs']:
                    if not (value <= r['va'] < value + target_size): continue
                    key = f'{rel_obj_path}#{sec_idx}#{r["va"]:#x}'
                    if r['sym_idx'] >= len(syms): continue
                    ref_sym = syms[r['sym_idx']]
                    if ref_sym is None: continue
                    ref_n = ref_sym['name']
                    ref_clean = ref_n[1:] if ref_n.startswith('_') else ref_n
                    ref_clean_nostd = re.sub(r'@\d+$', '', ref_clean)
                    ref_imp = '_' + ref_clean_nostd
                    if ref_clean in name_to_entry:
                        fb = name_to_entry[ref_clean]['addr']
                    elif ref_clean in name_to_addr:
                        fb = name_to_addr[ref_clean]
                    elif ref_clean_nostd in name_to_addr:
                        fb = name_to_addr[ref_clean_nostd]
                    elif ref_imp in name_to_addr:
                        fb = name_to_addr[ref_imp]
                    else:
                        fb = None
                        m_addr = re.search(r'_([0-9a-f]{8})$', ref_clean)
                        if m_addr: fb = int(m_addr.group(1), 16)
                        else:
                            m_mid = re.search(r'_([0-9a-f]{8})_[a-z][a-z0-9]*$', ref_clean)
                            if m_mid: fb = int(m_mid.group(1), 16)
                            else:
                                m_short = re.search(r'_([0-9a-f]{6,7})$', ref_clean)
                                if m_short:
                                    cand = int(m_short.group(1).rjust(8, '0'), 16)
                                    if 0x401000 <= cand < 0xfa0ef4: fb = cand
                                elif ref_sym['sec'] > 0 and (ref_sym['sec'] - 1) in sec_idx_to_va:
                                    fb = sec_idx_to_va[ref_sym['sec'] - 1] + ref_sym['value']
                    fallback_resolutions[key] = fb

    pruned = {key: site_va for key, site_va in sites.items()
              if not (fallback_resolutions.get(key) is not None
                      and fallback_resolutions.get(key) == site_va)}
    print(f'Total sites: {len(sites)}')
    print(f'Removed (redundant): {len(sites) - len(pruned)}')
    print(f'Kept (ambiguous): {len(pruned)}')
    with open('config/reloc_sites.yaml','w') as f:
        yaml.dump(dict(sorted(pruned.items())), f)


if __name__ == '__main__':
    main()
