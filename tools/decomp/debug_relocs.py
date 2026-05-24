"""Debug reloc resolution for specific functions.

Reports which reloc symbols resolve to wrong addresses by comparing
synthesized bytes against original EXE bytes.
"""

import os, re, struct, sys, yaml
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from synthesize import parse_obj_full, build_global_symbol_map

ROOT = Path(__file__).resolve().parent.parent.parent
ORIG_EXE = ROOT / 'game' / 'MK4.EXE'
OBJ_DIR  = ROOT / 'build' / 'obj'
SYMS     = ROOT / 'config' / 'symbols.yaml'

# Functions to debug
TARGETS = {
    'TestCallPush4Zero_004bd590':          (0x4bd590,  30),
    'ScaledDualPropagateJmp_004287b0':     (0x4287b0, 109),
    'Scaled3StorePushCallJmp_00438220':    (0x438220,  118),
    'DualSetShiftCall_00473f90':           (0x473f90,  120),
    'MStackPushDirtyTail_0047faf0':        (0x47faf0,  119),
    'InstallSelfHelper2_0047e8a0':         (0x47e8a0,  104),
    'CrouchAttackFsmCluster_0046f7a0':     (0x46f7a0, 1088),
    'TournamentMenuFsmCluster_004960e0':   (0x4960e0, 1359),
    'Alarm3PhaseChainBody_0047e230':       (0x47e230,  211),
    'ChainWalkSelfRecursive_0045daf0':     (0x45daf0,  125),
    'ChainWalkCleanup_004bd4a0':           (0x4bd4a0,  110),
}

KNOWN_GLOBALS = {
    0x542044: 'g_scaledInit_00542044',
    0x542048: 'g_xformEntityIdx',
    0x54204c: 'g_pendingNodeType / g_data_0054204c',
    0x542054: 'g_eventQueueEnd',
    0x542058: 'g_eventQueueIdx',
    0x54205c: 'g_cj_0054205c / g_fightGroupHead',
    0x54206c: 'g_walkCallback',
    0x542070: 'g_data_00542070 / g_eventQueueCurrent',
    0x542074: 'g_eventQueueWorkType',
    0x542078: 'g_acc_00542078',
    0x542080: 'g_eventQueueChild',
}


def parse_pe_sections(data):
    pe_off = struct.unpack_from('<I', data, 0x3c)[0]
    opthdr_size = struct.unpack_from('<H', data, pe_off+20)[0]
    ib = struct.unpack_from('<I', data, pe_off+24+28)[0]
    nsec = struct.unpack_from('<H', data, pe_off+6)[0]
    sections = []
    for i in range(nsec):
        s = pe_off + 24 + opthdr_size + i*40
        name = data[s:s+8].rstrip(b'\x00').decode('latin1')
        vsize = struct.unpack_from('<I', data, s+8)[0]
        vaddr = struct.unpack_from('<I', data, s+12)[0] + ib
        rsize = struct.unpack_from('<I', data, s+16)[0]
        raddr = struct.unpack_from('<I', data, s+20)[0]
        sections.append({'name': name, 'vaddr': vaddr, 'vsize': vsize,
                         'rsize': rsize, 'raddr': raddr})
    return ib, sections


def load_reloc_sites():
    sites_path = ROOT / 'config' / 'reloc_sites.yaml'
    if sites_path.exists():
        with open(sites_path) as f: return yaml.safe_load(f) or {}
    return {}


def scan_source_aliases():
    aliases = {}
    src_root = ROOT / 'src'
    if not src_root.exists():
        return aliases
    pat = re.compile(r'^#define\s+([A-Za-z_][A-Za-z0-9_]*)\s+([A-Za-z_][A-Za-z0-9_]*)\s*$')
    for p in src_root.rglob('*.c'):
        try:
            for line in open(p):
                m = pat.match(line)
                if m:
                    lhs, rhs = m.group(1), m.group(2)
                    aliases[rhs] = lhs
        except Exception:
            pass
    return aliases


def resolve_ref_va(ref_clean, name_to_entry, name_to_addr, ref_sym, sec_idx_to_va,
                   reloc_sites, site_key):
    site_va = reloc_sites.get(site_key)
    ref_clean_nostd = re.sub(r'@\d+$', '', ref_clean)
    ref_imp = '_' + ref_clean_nostd

    if site_va is not None:
        return site_va, 'reloc_sites'
    elif ref_clean in name_to_entry:
        return name_to_entry[ref_clean]['addr'], 'name_to_entry'
    elif ref_clean in name_to_addr:
        return name_to_addr[ref_clean], 'name_to_addr'
    elif ref_clean_nostd in name_to_addr:
        return name_to_addr[ref_clean_nostd], 'name_to_addr(nostd)'
    elif ref_imp in name_to_addr:
        return name_to_addr[ref_imp], 'name_to_addr(imp)'
    else:
        m_addr = re.search(r'_([0-9a-f]{8})$', ref_clean)
        if m_addr:
            return int(m_addr.group(1), 16), '_suffix'
        m_mid = re.search(r'_([0-9a-f]{8})_[a-z][a-z0-9]*$', ref_clean)
        if m_mid:
            return int(m_mid.group(1), 16), '_mid_suffix'
        m_short = re.search(r'_([0-9a-f]{6,7})$', ref_clean)
        if m_short:
            addr_str = m_short.group(1).rjust(8, '0')
            candidate = int(addr_str, 16)
            if 0x401000 <= candidate < 0xfa0ef4:
                return candidate, '_short_suffix'
        if ref_sym['sec'] > 0 and (ref_sym['sec'] - 1) in sec_idx_to_va:
            return sec_idx_to_va[ref_sym['sec'] - 1] + ref_sym['value'], 'sec_idx_to_va'
        return 0, 'UNRESOLVED'


def analyze_fn(fn_name, target_va, target_size, orig_exe, text_sec,
               name_to_entry, name_to_addr, obj_aliases, reloc_sites, all_obj_paths):
    print(f'\n{"="*70}')
    print(f'FUNCTION: {fn_name}')
    print(f'  VA={target_va:#010x}  size={target_size}')

    file_off = (target_va - text_sec['vaddr']) + text_sec['raddr']
    orig_bytes = orig_exe[file_off:file_off+target_size]

    def resolve_yaml_name(obj_sym_name):
        n = obj_sym_name[1:] if obj_sym_name.startswith('_') else obj_sym_name
        if n in name_to_entry:
            return n
        n2 = re.sub(r'@\d+$', '', n)
        if n2 in name_to_entry:
            return n2
        if n in obj_aliases and obj_aliases[n] in name_to_entry:
            return obj_aliases[n]
        if n2 in obj_aliases and obj_aliases[n2] in name_to_entry:
            return obj_aliases[n2]
        return None

    candidates = []
    for obj_path in all_obj_paths:
        with open(obj_path, 'rb') as f:
            obj_data = f.read()
        syms, sections = parse_obj_full(obj_data)
        for sym in syms:
            if sym is None: continue
            clean = resolve_yaml_name(sym['name'])
            if clean != fn_name: continue
            sec_idx = sym['sec']
            if sec_idx <= 0 or sec_idx > len(sections): continue
            sec = sections[sec_idx - 1]
            value = sym['value']
            if len(sec['content']) - value < target_size: continue
            candidates.append((obj_path, syms, sections, sec_idx, value))

    if not candidates:
        print('  ** OBJ NOT FOUND for this function **')
        return

    for obj_path, syms, sections, sec_idx, value in candidates:
        rel_obj_path = os.path.relpath(obj_path, str(OBJ_DIR))
        print(f'  OBJ: {rel_obj_path}  (sec={sec_idx}, offset={value})')

        sec = sections[sec_idx - 1]

        sec_idx_to_va = {}
        for sym2 in syms:
            if sym2 is None: continue
            y2 = resolve_yaml_name(sym2['name'])
            if y2 and sym2['sec'] > 0:
                fn_va2 = name_to_entry[y2]['addr']
                base_va2 = fn_va2 - sym2['value']
                sec_idx_to_va[sym2['sec'] - 1] = base_va2

        raw = sec['content'][value:value+target_size+4]
        work_bytes = bytearray(raw) + bytearray(target_size + 4 - len(raw))
        fn_bytes = work_bytes

        all_reloc_offsets = []
        unresolved_offsets = []
        reloc_details = []

        for r in sec['relocs']:
            if not (value <= r['va'] < value + target_size):
                continue
            offset_in_fn = r['va'] - value
            all_reloc_offsets.append(offset_in_fn)

            ref_sym = syms[r['sym_idx']]
            if ref_sym is None:
                unresolved_offsets.append(offset_in_fn)
                continue

            ref_name = ref_sym['name']
            ref_clean = ref_name[1:] if ref_name.startswith('_') else ref_name

            site_key = f'{rel_obj_path}#{sec_idx}#{r["va"]:#x}'
            ref_va, source = resolve_ref_va(ref_clean, name_to_entry, name_to_addr,
                                            ref_sym, sec_idx_to_va, reloc_sites, site_key)

            if ref_va == 0 and ref_clean not in name_to_addr and ref_clean not in name_to_entry:
                unresolved_offsets.append(offset_in_fn)

            r_type = r['type']
            if r_type == 6 and offset_in_fn >= 1:
                prev1 = fn_bytes[offset_in_fn - 1]
                prev2 = fn_bytes[offset_in_fn - 2] if offset_in_fn >= 2 else 0
                if (prev1 in (0xe8, 0xe9) and prev2 not in (0x81, 0x83)) or \
                   (prev2 == 0x0f and 0x80 <= prev1 <= 0x8f):
                    r_type = 20

            existing = struct.unpack_from('<I', fn_bytes, offset_in_fn)[0]
            orig_slot = struct.unpack_from('<I', orig_bytes, offset_in_fn)[0] if offset_in_fn+4 <= target_size else None

            if r_type == 6:
                computed_slot = (ref_va + existing) & 0xffffffff if ref_va else existing
            elif r_type == 20:
                computed_slot = (ref_va - (target_va + offset_in_fn + 4) + existing) & 0xffffffff if ref_va else existing
            else:
                computed_slot = existing

            if r_type == 6 and ref_va:
                struct.pack_into('<I', fn_bytes, offset_in_fn, computed_slot)
            elif r_type == 20 and ref_va:
                struct.pack_into('<I', fn_bytes, offset_in_fn, computed_slot)

            reloc_details.append({
                'offset': offset_in_fn,
                'sym': ref_clean,
                'ref_va': ref_va,
                'source': source,
                'r_type_orig': r['type'],
                'r_type_used': r_type,
                'existing_slot': existing,
                'computed_slot': computed_slot,
                'orig_slot': orig_slot,
            })

        fn_bytes = fn_bytes[:target_size]

        # NOP canonicalization
        i = fn_bytes.find(b'\x90\x8b\xff')
        while i != -1:
            if i not in all_reloc_offsets:
                fn_bytes[i:i+3] = b'\x8d\x49\x00'
            i = fn_bytes.find(b'\x90\x8b\xff', i+1)

        n_diffs = sum(1 for a, b in zip(orig_bytes, fn_bytes) if a != b)
        print(f'  Diffs: {n_diffs} / {target_size} bytes')

        if n_diffs == 0:
            print('  >> canonical OBJ = 0 diffs (dispatch copy elsewhere)')
            continue

        diff_positions = [i for i, (a, b) in enumerate(zip(orig_bytes, fn_bytes)) if a != b]
        print(f'  Diff positions (fn-relative): {diff_positions[:30]}{"..." if len(diff_positions)>30 else ""}')

        # reloc coverage
        reloc_covered = set()
        for rd in reloc_details:
            reloc_covered.update(range(rd['offset'], rd['offset']+4))

        print()
        print('  RELOC TABLE (wrong entries marked):')
        header = f'  {"off":>5}  {"sym":<48} {"got_va":>10} {"orig_slot":>10} {"our_slot":>10}  {"src"}'
        print(header)
        print('  ' + '-'*(len(header)-2))

        any_wrong = False
        for rd in reloc_details:
            wrong = rd['orig_slot'] is not None and rd['orig_slot'] != rd['computed_slot']
            if wrong:
                any_wrong = True
            marker = ' <-- WRONG' if wrong else ''
            print(f'  {rd["offset"]:5d}  {rd["sym"]:<48} {rd["ref_va"]:#010x} '
                  f'{rd["orig_slot"] if rd["orig_slot"] is not None else "N/A":>10}  '
                  f'{rd["computed_slot"]:#010x}  {rd["source"]}{marker}')

        non_reloc_diffs = [p for p in diff_positions if p not in reloc_covered]
        if non_reloc_diffs:
            print()
            print('  NON-RELOC BYTE DIFFS (codegen mismatch):')
            for p in non_reloc_diffs[:40]:
                print(f'    fn+{p:#05x}: orig={orig_bytes[p]:#04x}  ours={fn_bytes[p]:#04x}')

        print()
        print('  WRONG RELOC DETAILS:')
        found_wrong = False
        for rd in reloc_details:
            if rd['orig_slot'] is None: continue
            if rd['orig_slot'] == rd['computed_slot']: continue
            found_wrong = True
            existing = rd['existing_slot']
            if rd['r_type_used'] == 20:
                expected_ref_va = rd['orig_slot'] + (target_va + rd['offset'] + 4) - existing
            elif rd['r_type_used'] == 6:
                expected_ref_va = (rd['orig_slot'] - existing) & 0xffffffff
            else:
                expected_ref_va = rd['orig_slot']
            known = KNOWN_GLOBALS.get(expected_ref_va, '')
            print(f'    fn+{rd["offset"]:4d}: sym="{rd["sym"]}"')
            print(f'           sym resolves to  {rd["ref_va"]:#010x}  (via {rd["source"]})')
            print(f'           orig expects      {expected_ref_va:#010x}  {known}')
        if not found_wrong:
            print('    (none - all diffs are codegen, not reloc)')

        if unresolved_offsets:
            print()
            print(f'  UNRESOLVED relocs at fn offsets: {unresolved_offsets}')


def main():
    print('Loading original EXE...')
    with open(ORIG_EXE, 'rb') as f:
        orig_exe = f.read()
    _ib, pe_sections = parse_pe_sections(orig_exe)
    text_sec = next(s for s in pe_sections if s['name'] == '.text')

    print('Loading symbol maps...')
    with open(SYMS) as f: ydat = yaml.safe_load(f)
    name_to_entry = {e['name']: e for e in ydat['functions']}
    obj_aliases = scan_source_aliases()
    addr_to_name, name_to_addr = build_global_symbol_map()
    reloc_sites = load_reloc_sites()

    print('Scanning OBJ files...')
    all_obj_paths = []
    for root, dirs, files in os.walk(OBJ_DIR):
        for fn in files:
            if fn.endswith('.obj'):
                all_obj_paths.append(os.path.join(root, fn))
    print(f'  Found {len(all_obj_paths)} OBJ files')

    for fn_name, (target_va, target_size) in TARGETS.items():
        analyze_fn(fn_name, target_va, target_size, orig_exe, text_sec,
                   name_to_entry, name_to_addr, obj_aliases, reloc_sites, all_obj_paths)

    print('\n\nDone.')


if __name__ == '__main__':
    main()
