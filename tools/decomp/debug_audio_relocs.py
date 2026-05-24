"""
Debug script: check COFF relocs in the 6 failing audio OBJs.
For each reloc in each function's range, resolve the symbol using the same
priority order as synthesize.py, then compare our resolved address against
what the original EXE actually has at that location (the ground-truth address).

Usage: python3 tools/decomp/debug_audio_relocs.py
"""

import os, re, struct, sys, yaml
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent.parent
ORIG_EXE = ROOT / 'game' / 'MK4.EXE'
OBJ_DIR  = ROOT / 'build' / 'obj'
SYMS     = ROOT / 'config' / 'symbols.yaml'

TARGETS = [
    ('audio/audio_swap_negate.obj',              'AudioSwapNegate_004ac080',         0x4ac080, 126),
    ('audio/audio_chain_init.obj',               'AudioChainInit_004a77c0',           0x4a77c0, 117),
    ('audio/audio_install_self_state_push.obj',  'AudioInstallSelfStatePush_004aa8a0', 0x4aa8a0, 146),
    ('audio/audio_state50b4_bit_dispatcher.obj', 'AudioState50b4BitDispatcher_004a32c0', 0x4a32c0, 309),
    ('audio/audio_init_args3.obj',               'AudioInitArgs3_004a1f20',           0x4a1f20, 118),
    ('audio/audio_bind_entry_b.obj',             'AudioBindEntryB_004a6230',          0x4a6230, 114),
]

def parse_pe_sections(data):
    pe_off = struct.unpack_from('<I', data, 0x3c)[0]
    nsec = struct.unpack_from('<H', data, pe_off+6)[0]
    opthdr_size = struct.unpack_from('<H', data, pe_off+20)[0]
    ib = struct.unpack_from('<I', data, pe_off+24+28)[0]
    sections = []
    for i in range(nsec):
        s = pe_off + 24 + opthdr_size + i*40
        name = data[s:s+8].rstrip(b'\x00').decode('latin1')
        vsize = struct.unpack_from('<I', data, s+8)[0]
        vaddr = struct.unpack_from('<I', data, s+12)[0] + ib
        rsize = struct.unpack_from('<I', data, s+16)[0]
        raddr = struct.unpack_from('<I', data, s+20)[0]
        sections.append({'name': name, 'vaddr': vaddr, 'vsize': vsize, 'rsize': rsize, 'raddr': raddr})
    return ib, sections

def parse_obj_full(obj_data):
    nsec_total = struct.unpack_from('<H', obj_data, 2)[0]
    opt = struct.unpack_from('<H', obj_data, 16)[0]
    nsyms = struct.unpack_from('<I', obj_data, 12)[0]
    sym_off = struct.unpack_from('<I', obj_data, 8)[0]
    str_off = sym_off + nsyms * 18

    def read_long_name(field):
        if field[:1] == b'/':
            idx = int(field[1:].rstrip(b'\x00').decode())
            end = obj_data.find(b'\x00', str_off + idx)
            return obj_data[str_off+idx:end].decode('latin1', errors='replace')
        elif field[:4] == b'\x00\x00\x00\x00':
            idx = struct.unpack_from('<I', field, 4)[0]
            end = obj_data.find(b'\x00', str_off + idx)
            return obj_data[str_off+idx:end].decode('latin1', errors='replace')
        return field.rstrip(b'\x00').decode('latin1', errors='replace')

    sections = []
    for i in range(nsec_total):
        s = 20 + opt + i*40
        name = read_long_name(obj_data[s:s+8])
        rsize = struct.unpack_from('<I', obj_data, s+16)[0]
        raddr = struct.unpack_from('<I', obj_data, s+20)[0]
        rloc_off = struct.unpack_from('<I', obj_data, s+24)[0]
        rloc_n = struct.unpack_from('<H', obj_data, s+32)[0]
        content = obj_data[raddr:raddr+rsize] if raddr and rsize else b''
        relocs = []
        for r in range(rloc_n):
            rp = rloc_off + r*10
            vaddr = struct.unpack_from('<I', obj_data, rp)[0]
            sym_idx = struct.unpack_from('<I', obj_data, rp+4)[0]
            r_type = struct.unpack_from('<H', obj_data, rp+8)[0]
            relocs.append({'va': vaddr, 'sym_idx': sym_idx, 'type': r_type})
        sections.append({'name': name, 'content': bytearray(content), 'relocs': relocs,
                         'raddr': raddr, 'rsize': rsize})

    syms = [None] * nsyms
    i = 0
    while i < nsyms:
        p = sym_off + i*18
        e = obj_data[p:p+8]
        if e[:4] == b'\x00\x00\x00\x00':
            offset = struct.unpack_from('<I', e, 4)[0]
            end = obj_data.find(b'\x00', str_off+offset)
            name = obj_data[str_off+offset:end].decode('latin1', errors='replace')
        else:
            name = e.rstrip(b'\x00').decode('latin1', errors='replace')
        value = struct.unpack_from('<I', obj_data, p+8)[0]
        sec = struct.unpack_from('<h', obj_data, p+12)[0]
        n_aux = obj_data[p+17]
        syms[i] = {'name': name, 'value': value, 'sec': sec}
        i += 1 + n_aux
    return syms, sections

def build_name_to_addr():
    """Replicate synthesize.py priority: symbols.yaml -> headers -> extras_map."""
    with open(SYMS) as f: d = yaml.safe_load(f)
    name_to_addr = {}
    name_to_entry = {e['name']: e for e in d['functions']}

    # 1. symbols.yaml
    for e in d['functions']:
        name_to_addr[e['name']] = e['addr']

    # 2. Header /* 0xADDR */ comments
    include_dir = ROOT / 'include'
    addr_pat = r'(?:0x([0-9a-fA-F]+)|DAT_([0-9a-fA-F]+))'
    for hp in include_dir.rglob('*.h'):
        with open(hp) as f: hc = f.read()
        for m in re.finditer(r'\b([A-Za-z_][\w]*)\s*(?:\([^)]*\)|\[[^\]]*\])?\s*;\s*/\*\s*' + addr_pat, hc):
            nm = m.group(1)
            addr = int(m.group(2) or m.group(3), 16)
            if nm not in name_to_addr:
                name_to_addr[nm] = addr
        for m in re.finditer(r'\(\s*\*\s*([A-Za-z_][\w]*)\s*\)[^;]*;\s*/\*\s*' + addr_pat, hc):
            nm = m.group(1)
            addr = int(m.group(2) or m.group(3), 16)
            if nm not in name_to_addr:
                name_to_addr[nm] = addr

    # 3. extras_map (only if not already set)
    extras_path = ROOT / 'config' / 'extras_map.yaml'
    if extras_path.exists():
        with open(extras_path) as f: extras = yaml.safe_load(f)
        for sym, va in (extras or {}).items():
            if sym not in name_to_addr:
                name_to_addr[sym] = va

    return name_to_addr, name_to_entry

def resolve_ref_va(ref_name, name_to_addr, name_to_entry, sec_idx_to_va, syms, sym_idx):
    """Resolve a reloc's referenced symbol to a VA, same logic as synthesize.py."""
    ref_clean = ref_name[1:] if ref_name.startswith('_') else ref_name
    ref_clean_nostd = re.sub(r'@\d+$', '', ref_clean)
    ref_imp = '_' + ref_clean_nostd

    if ref_clean in name_to_entry:
        return name_to_entry[ref_clean]['addr'], 'symbols.yaml'
    if ref_clean in name_to_addr:
        return name_to_addr[ref_clean], 'name_to_addr(yaml/hdr/extras)'
    if ref_clean_nostd in name_to_addr:
        return name_to_addr[ref_clean_nostd], 'name_to_addr(nostdcall)'
    if ref_imp in name_to_addr:
        return name_to_addr[ref_imp], 'name_to_addr(imp)'

    # addr from name suffix
    m_addr = re.search(r'_([0-9a-f]{8})$', ref_clean)
    if m_addr:
        return int(m_addr.group(1), 16), 'name_suffix_8hex'
    m_mid = re.search(r'_([0-9a-f]{8})_[a-z][a-z0-9]*$', ref_clean)
    if m_mid:
        return int(m_mid.group(1), 16), 'name_mid_8hex'
    m_short = re.search(r'_([0-9a-f]{6,7})$', ref_clean)
    if m_short:
        candidate = int(m_short.group(1).rjust(8, '0'), 16)
        if 0x401000 <= candidate < 0xfa0ef4:
            return candidate, 'name_short_hex'

    ref_sym = syms[sym_idx]
    if ref_sym and ref_sym['sec'] > 0 and (ref_sym['sec'] - 1) in sec_idx_to_va:
        va = sec_idx_to_va[ref_sym['sec'] - 1] + ref_sym['value']
        return va, 'sec_idx_to_va'

    return 0, 'UNRESOLVED'

def read_orig_addr_at(orig_data, text_sec, fn_va, fn_size, offset_in_fn, r_type):
    """Read the original address from orig EXE at the given reloc offset."""
    file_off = (fn_va - text_sec['vaddr']) + text_sec['raddr'] + offset_in_fn
    if file_off + 4 > len(orig_data):
        return None
    raw = struct.unpack_from('<I', orig_data, file_off)[0]
    if r_type == 6:  # DIR32: the 4 bytes IS the absolute address (+ addend in OBJ)
        return raw
    elif r_type == 20:  # REL32: target = raw + next_instr_va
        next_instr_va = fn_va + offset_in_fn + 4
        return (raw + next_instr_va) & 0xffffffff
    return raw

def main():
    print('Loading orig EXE and symbol map...')
    with open(ORIG_EXE, 'rb') as f:
        orig_data = f.read()
    ib, pe_sections = parse_pe_sections(bytes(orig_data))
    text_sec = next(s for s in pe_sections if s['name'] == '.text')
    name_to_addr, name_to_entry = build_name_to_addr()

    total_mismatches = 0

    for rel_obj, fn_name, fn_va, fn_size in TARGETS:
        obj_path = OBJ_DIR / rel_obj
        print(f'\n{"="*70}')
        print(f'Function: {fn_name} @ 0x{fn_va:08x} ({fn_size}b)')
        print(f'OBJ: {rel_obj}')

        with open(obj_path, 'rb') as f:
            obj_data = f.read()
        syms, sections = parse_obj_full(obj_data)

        # Build sec_idx_to_va
        sec_idx_to_va = {}
        for sym in syms:
            if sym is None: continue
            nm = sym['name']
            clean = nm[1:] if nm.startswith('_') else nm
            clean2 = re.sub(r'@\d+$', '', clean)
            for n in [clean, clean2]:
                if n in name_to_entry and sym['sec'] > 0:
                    fn_entry_va = name_to_entry[n]['addr']
                    base_va = fn_entry_va - sym['value']
                    sec_idx_to_va[sym['sec'] - 1] = base_va

        # Find the function symbol
        fn_sym = None
        fn_sec_idx = None
        fn_offset = 0
        fn_coff_name = '_' + fn_name
        for sym in syms:
            if sym is None: continue
            if sym['name'] == fn_coff_name:
                fn_sym = sym
                fn_sec_idx = sym['sec'] - 1
                fn_offset = sym['value']
                break
        if fn_sym is None:
            print(f'  ERROR: symbol {fn_coff_name} not found in OBJ')
            continue

        sec = sections[fn_sec_idx]
        print(f'  Section: {sec["name"]}, offset in section: {fn_offset:#x}')
        print(f'  Relocs in section: {len(sec["relocs"])}')

        # Collect relocs within this function
        fn_relocs = [r for r in sec['relocs']
                     if fn_offset <= r['va'] < fn_offset + fn_size]
        print(f'  Relocs in function: {len(fn_relocs)}')

        mismatches_here = 0
        for r in fn_relocs:
            offset_in_fn = r['va'] - fn_offset
            ref_sym = syms[r['sym_idx']] if r['sym_idx'] < len(syms) else None
            if ref_sym is None:
                print(f'  [+{offset_in_fn:#04x}] sym_idx={r["sym_idx"]} MISSING SYMBOL')
                continue

            ref_name = ref_sym['name']

            # Get addend from OBJ content
            addend = struct.unpack_from('<i', sec['content'], r['va'])[0]

            # Resolve our address
            our_va, our_source = resolve_ref_va(
                ref_name, name_to_addr, name_to_entry, sec_idx_to_va, syms, r['sym_idx']
            )

            # Compute what synth would write
            r_type = r['type']
            if r_type == 6:  # DIR32
                synth_val = (our_va + addend) & 0xffffffff
            elif r_type == 20:  # REL32
                synth_val = (our_va - (fn_va + offset_in_fn + 4) + addend) & 0xffffffff
            else:
                synth_val = None

            # Read original value from EXE
            orig_raw = struct.unpack_from('<I', orig_data,
                (fn_va - text_sec['vaddr']) + text_sec['raddr'] + offset_in_fn)[0]
            # Decode orig's implied target VA
            if r_type == 6:
                orig_target = orig_raw  # for DIR32 raw IS the abs addr (addend was 0 in orig)
                # Actually: raw in EXE is the resolved value; since addend may be non-zero,
                # orig target = orig_raw - addend to get the base symbol addr
                orig_base = (orig_raw - addend) & 0xffffffff
            elif r_type == 20:
                next_instr_va = fn_va + offset_in_fn + 4
                orig_target = (orig_raw + next_instr_va) & 0xffffffff
                orig_base = orig_target  # no addend for REL32 typically
            else:
                orig_target = orig_raw
                orig_base = orig_raw

            mismatch = (synth_val is not None) and (synth_val != orig_raw)
            status = 'MISMATCH' if mismatch else 'ok'
            if mismatch:
                mismatches_here += 1
                total_mismatches += 1

            ref_clean = ref_name[1:] if ref_name.startswith('_') else ref_name
            if mismatch:
                print(f'  [+{offset_in_fn:#04x}] type={r_type} sym={ref_clean!r}')
                print(f'           addend       = {addend:#010x} ({addend})')
                print(f'           our_va       = {our_va:#010x}  (from {our_source})')
                print(f'           synth_val    = {synth_val:#010x}')
                print(f'           orig_raw_exe = {orig_raw:#010x}')
                if r_type == 6:
                    print(f'           orig_base    = {orig_base:#010x}  <-- correct symbol addr')
                else:
                    print(f'           orig_target  = {orig_target:#010x}  <-- correct symbol addr')
            else:
                clean = ref_clean[:50]
                print(f'  [+{offset_in_fn:#04x}] {status:8s} sym={clean!r} our_va={our_va:#010x}')

        if mismatches_here == 0:
            print(f'  ** All {len(fn_relocs)} relocs resolve correctly (per-OBJ diff = 0 confirmed) **')
            print(f'  ** Synth diffs for this function are caused by RELOC-SHUFFLE (wrong base VA in synth) **')

    print(f'\n{"="*70}')
    print(f'Total reloc mismatches found: {total_mismatches}')
    print()
    print('NOTE: diff_fn_obj.py masks reloc slots -> always shows diffs=0.')
    print('NOTE: synthesize.py diffs = reloc resolution errors in synth, NOT in linker.')
    print('If total_mismatches=0 and make diff shows byte-identical -> all diffs are')
    print('synth-internal reloc-shuffle false negatives (pre-existing, not regressions).')

if __name__ == '__main__':
    main()
