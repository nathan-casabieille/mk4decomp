"""Custom linker: synthesize byte-perfect MK4.EXE from compiled OBJs.

Approach:
- Start with orig MK4.EXE as scaffold (DOS stub, PE header, .data, .rdata, .rsrc, IAT).
- For each function in symbols.yaml, locate its bytes in the compiled OBJ,
  apply relocations using addr_to_name, and write to scaffold at the
  function's orig VA.
- If our OBJ bytes are correct, the resulting EXE is byte-identical to orig.

Output: build/MK4.matching.exe.
"""

import os, struct, sys, yaml
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent.parent
ORIG_EXE = ROOT / 'game' / 'MK4.EXE'
OUT_EXE  = ROOT / 'build' / 'MK4.matching.exe'
OBJ_DIR  = ROOT / 'build' / 'obj'
SYMS     = ROOT / 'config' / 'symbols.yaml'

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
    """Return parsed COFF: symbols list, sections list (with name+content+relocs), str_table."""
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

    # Reloc sym_idx counts each 18-byte record (primaries + aux), so we use a flat array.
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

def build_global_symbol_map():
    """Build addr->name + name->addr from symbols.yaml + header /* 0xADDR */ comments."""
    import re as _re
    with open(SYMS) as f: d = yaml.safe_load(f)
    addr_to_name = {}
    name_to_addr = {}
    for e in d['functions']:
        addr_to_name[e['addr']] = e['name']
        name_to_addr[e['name']] = e['addr']
    include_dir = ROOT / 'include'
    for hp in include_dir.rglob('*.h'):
        with open(hp) as f: hc = f.read()
        for m in _re.finditer(r'\b([A-Za-z_][\w]*)\s*(?:\([^)]*\)|\[[^\]]*\])?\s*;\s*/\*\s*(0x[0-9a-fA-F]+)', hc):
            name = m.group(1)
            addr = int(m.group(2), 16)
            if name not in name_to_addr:
                name_to_addr[name] = addr
        # Function-pointer form: extern TYPE (*NAME)(...);  /* 0xADDR */
        for m in _re.finditer(r'\(\s*\*\s*([A-Za-z_][\w]*)\s*\)[^;]*;\s*/\*\s*(0x[0-9a-fA-F]+)', hc):
            name = m.group(1)
            addr = int(m.group(2), 16)
            if name not in name_to_addr:
                name_to_addr[name] = addr
    # Load IAT map (from extract_iat.py)
    import os.path
    iat_path = ROOT / 'config' / 'iat_map.yaml'
    if iat_path.exists():
        with open(iat_path) as f: iat = yaml.safe_load(f)
        for sym, va in iat.items():
            if sym not in name_to_addr:
                name_to_addr[sym] = va
    return addr_to_name, name_to_addr

def main():
    print('Loading scaffold...')
    with open(ORIG_EXE, 'rb') as f:
        scaffold = bytearray(f.read())
    ib, pe_sections = parse_pe_sections(scaffold)
    text_sec = next(s for s in pe_sections if s['name'] == '.text')

    print('Loading symbols.yaml + headers...')
    with open(SYMS) as f: ydat = yaml.safe_load(f)
    name_to_entry = {e['name']: e for e in ydat['functions']}
    addr_to_name, name_to_addr = build_global_symbol_map()

    print('Walking OBJs...')
    obj_paths = []
    for root, dirs, files in os.walk(OBJ_DIR):
        for fn in files:
            if fn.endswith('.obj'):
                obj_paths.append(os.path.join(root, fn))

    placed = 0
    not_found = 0
    mismatches = []
    for obj_path in obj_paths:
        with open(obj_path,'rb') as f:
            obj_data = f.read()
        syms, sections = parse_obj_full(obj_data)

        # Build section_idx -> target_VA map: for each section containing a known function symbol,
        # the section's "base" VA = function's VA - sym['value'] (which is the offset of the func in section).
        sec_idx_to_va = {}
        for sym in syms:
            if sym is None: continue
            name = sym['name']
            clean = name[1:] if name.startswith('_') else name
            if clean in name_to_entry and sym['sec'] > 0:
                fn_va = name_to_entry[clean]['addr']
                base_va = fn_va - sym['value']
                sec_idx_to_va[sym['sec'] - 1] = base_va

        for sym in syms:
            if sym is None: continue
            name = sym['name']
            clean = name[1:] if name.startswith('_') else name
            if clean not in name_to_entry:
                continue
            sec_idx = sym['sec']
            if sec_idx <= 0 or sec_idx > len(sections):
                continue
            sec = sections[sec_idx - 1]
            value = sym['value']  # offset in section
            entry = name_to_entry[clean]
            target_va = entry['addr']
            target_size = entry['size']

            # Extract bytes
            fn_bytes = sec['content'][value:value+target_size]
            if len(fn_bytes) < target_size:
                # Function spans into another section or shorter
                # try to pad with zero (TODO: cross-section refs)
                fn_bytes = bytes(fn_bytes) + b'\x00' * (target_size - len(fn_bytes))
            else:
                fn_bytes = bytearray(fn_bytes)

            # Apply relocations that fall within [value, value+target_size]
            for r in sec['relocs']:
                if value <= r['va'] < value + target_size:
                    offset_in_fn = r['va'] - value
                    # Look up the symbol being referenced
                    ref_sym = syms[r['sym_idx']]
                    if ref_sym is None: continue
                    ref_name = ref_sym['name']
                    ref_clean = ref_name[1:] if ref_name.startswith('_') else ref_name
                    # Find target VA
                    # Strip stdcall @N suffix for IAT lookups
                    import re as _re_iat
                    ref_clean_nostd = _re_iat.sub(r'@\d+$', '', ref_clean)
                    # For __imp__ symbols: original COFF name starts with __imp__, our clean strips one _
                    # Re-add the underscore for the IAT map lookup
                    ref_imp = '_' + ref_clean_nostd  # one extra _ since we stripped
                    if ref_clean in name_to_entry:
                        ref_va = name_to_entry[ref_clean]['addr']
                    elif ref_clean in name_to_addr:
                        ref_va = name_to_addr[ref_clean]
                    elif ref_clean_nostd in name_to_addr:
                        ref_va = name_to_addr[ref_clean_nostd]
                    elif ref_imp in name_to_addr:
                        ref_va = name_to_addr[ref_imp]
                    else:
                        # Try parsing addr from name suffix _XXXXXXXX
                        import re as _re
                        m_addr = _re.search(r'_([0-9a-f]{8})$', ref_clean)
                        ref_va = 0
                        if m_addr:
                            ref_va = int(m_addr.group(1), 16)
                        else:
                            # Look for _XXXXXXXX in middle (e.g., g_data_004d57ac_arr)
                            m_mid = _re.search(r'_([0-9a-f]{8})_[a-z][a-z0-9]*$', ref_clean)
                            if m_mid:
                                ref_va = int(m_mid.group(1), 16)
                            else:
                                # 6-7 hex with suffix (e.g., g_chain_arr_4348f0)
                                m_short = _re.search(r'_([0-9a-f]{6,7})$', ref_clean)
                                if m_short:
                                    addr_str = m_short.group(1)
                                    addr_str = addr_str.rjust(8, '0')
                                    candidate = int(addr_str, 16)
                                    # Only accept if in known data/text range
                                    if 0x401000 <= candidate < 0xfa0ef4:
                                        ref_va = candidate
                                elif ref_sym['sec'] > 0 and (ref_sym['sec'] - 1) in sec_idx_to_va:
                                    ref_va = sec_idx_to_va[ref_sym['sec'] - 1] + ref_sym['value']
                    # Apply per reloc type
                    r_type = r['type']
                    # x86 COFF: 6=DIR32, 20=REL32
                    if r_type == 6:  # DIR32 - absolute address
                        existing = struct.unpack_from('<I', fn_bytes, offset_in_fn)[0]
                        if ref_va:
                            new_val = ref_va + existing
                            struct.pack_into('<I', fn_bytes, offset_in_fn, new_val & 0xffffffff)
                    elif r_type == 20:  # REL32 - relative
                        # rel32 = target - (next_instr_addr) = target_va - (cur_fn_va + offset_in_fn + 4)
                        existing = struct.unpack_from('<I', fn_bytes, offset_in_fn)[0]
                        if ref_va:
                            new_val = ref_va - (target_va + offset_in_fn + 4) + existing
                            struct.pack_into('<I', fn_bytes, offset_in_fn, new_val & 0xffffffff)

            # Write to scaffold at the function's VA
            file_off = (target_va - text_sec['vaddr']) + text_sec['raddr']
            if file_off + target_size > text_sec['raddr'] + text_sec['rsize']:
                continue
            # Compare to orig
            orig_bytes = scaffold[file_off:file_off+target_size]
            if bytes(orig_bytes) != bytes(fn_bytes):
                mismatches.append((clean, target_va, target_size,
                                   sum(1 for a,b in zip(orig_bytes, fn_bytes) if a != b)))
            # Overwrite
            for i in range(target_size):
                scaffold[file_off + i] = fn_bytes[i]
            placed += 1

    print(f'\nFunctions placed: {placed}')
    print(f'Mismatches: {len(mismatches)}')
    for name, va, sz, n in mismatches[:10]:
        print(f'  {name} @ {va:#x} ({sz}b): {n} bytes differ')

    # Save output
    with open(OUT_EXE, 'wb') as f:
        f.write(scaffold)

    # Verify
    with open(ORIG_EXE, 'rb') as f: orig = f.read()
    if scaffold == orig:
        print(f'\n*** BYTE-IDENTICAL TO ORIG *** ({len(scaffold)} bytes)')
    else:
        diff_bytes = sum(1 for a,b in zip(orig, scaffold) if a != b)
        print(f'\nNOT byte-identical: {diff_bytes} differing bytes')

if __name__ == '__main__':
    main()
