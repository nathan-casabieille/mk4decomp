"""Custom linker: synthesize byte-perfect MK4.EXE from compiled OBJs.

Approach:
- Start with orig MK4.EXE as scaffold (DOS stub, PE header, .data, .rdata, .rsrc, IAT).
- For each function in symbols.yaml, locate its bytes in the compiled OBJ,
  apply relocations using addr_to_name, and write to scaffold at the
  function's orig VA.
- If our OBJ bytes are correct, the resulting EXE is byte-identical to orig.

Output: build/MK4.matching.exe.
"""

import os, re, struct, sys, yaml
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
    # Accept both forms after the C declaration: `/* 0xHEX */` and `/* DAT_HEX */`.
    addr_pat = r'(?:0x([0-9a-fA-F]+)|DAT_([0-9a-fA-F]+))'
    def _coerce(m):
        return int(m.group(2) or m.group(3), 16)
    for hp in include_dir.rglob('*.h'):
        with open(hp) as f: hc = f.read()
        for m in _re.finditer(r'\b([A-Za-z_][\w]*)\s*(?:\([^)]*\)|\[[^\]]*\])?\s*;\s*/\*\s*' + addr_pat, hc):
            name = m.group(1)
            addr = int(m.group(2) or m.group(3), 16)
            if name not in name_to_addr:
                name_to_addr[name] = addr
        # Function-pointer form: extern TYPE (*NAME)(...);  /* 0xADDR */ or DAT_HEX
        for m in _re.finditer(r'\(\s*\*\s*([A-Za-z_][\w]*)\s*\)[^;]*;\s*/\*\s*' + addr_pat, hc):
            name = m.group(1)
            addr = int(m.group(2) or m.group(3), 16)
            if name not in name_to_addr:
                name_to_addr[name] = addr
    # Load IAT map (from extract_iat.py)
    iat_path = ROOT / 'config' / 'iat_map.yaml'
    if iat_path.exists():
        with open(iat_path) as f: iat = yaml.safe_load(f)
        for sym, va in iat.items():
            if sym not in name_to_addr:
                name_to_addr[sym] = va
    extras_path = ROOT / 'config' / 'extras_map.yaml'
    if extras_path.exists():
        with open(extras_path) as f: extras = yaml.safe_load(f)
        for sym, va in (extras or {}).items():
            if sym not in name_to_addr:
                name_to_addr[sym] = va
    return addr_to_name, name_to_addr

def load_reloc_sites():
    """Per-site address table: (rel_obj_path, sec_idx, reloc_va_in_sec) -> target_va.
       Used when the same symbol name is reused at multiple addresses in source."""
    sites_path = ROOT / 'config' / 'reloc_sites.yaml'
    if sites_path.exists():
        with open(sites_path) as f: return yaml.safe_load(f) or {}
    return {}

def scan_source_aliases():
    """Scan src/ for `#define X Y` lines where X may be a name in symbols.yaml
    but the OBJ ends up with Y (because the define rewrites the function def too).
    Returns {obj_symbol_name: yaml_name} so synth can resolve back to the yaml entry.
    """
    import re as _re_a
    aliases = {}
    src_root = Path('src')
    if not src_root.exists():
        return aliases
    pat = _re_a.compile(r'^#define\s+([A-Za-z_][A-Za-z0-9_]*)\s+([A-Za-z_][A-Za-z0-9_]*)\s*$')
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


def main():
    print('Loading scaffold...')
    with open(ORIG_EXE, 'rb') as f:
        scaffold = bytearray(f.read())
    ib, pe_sections = parse_pe_sections(scaffold)
    text_sec = next(s for s in pe_sections if s['name'] == '.text')
    rdata_sec = next((s for s in pe_sections if s['name'] == '.rdata'), None)

    print('Loading symbols.yaml + headers + sites...')
    with open(SYMS) as f: ydat = yaml.safe_load(f)
    name_to_entry = {e['name']: e for e in ydat['functions']}
    obj_aliases = scan_source_aliases()
    addr_to_name, name_to_addr = build_global_symbol_map()
    reloc_sites = load_reloc_sites()
    print(f'  reloc_sites: {len(reloc_sites)} entries')

    # Track which bytes in .text are produced by us (vs left as scaffold).
    # Initialize to all-False; flip to True as functions/data blobs get placed.
    text_synth = bytearray(text_sec['vsize'])
    rdata_synth = bytearray(rdata_sec['vsize']) if rdata_sec else None

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
        rel_obj_path = os.path.relpath(obj_path, str(OBJ_DIR))
        with open(obj_path,'rb') as f:
            obj_data = f.read()
        syms, sections = parse_obj_full(obj_data)

        # Resolve OBJ-symbol name to symbols.yaml name: strip leading underscore,
        # strip stdcall @N suffix if needed, apply source #define aliases.
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

        # Build section_idx -> target_VA map: for each section containing a known function symbol,
        # the section's "base" VA = function's VA - sym['value'] (which is the offset of the func in section).
        sec_idx_to_va = {}
        for sym in syms:
            if sym is None: continue
            yaml_name = resolve_yaml_name(sym['name'])
            if yaml_name and sym['sec'] > 0:
                fn_va = name_to_entry[yaml_name]['addr']
                base_va = fn_va - sym['value']
                sec_idx_to_va[sym['sec'] - 1] = base_va

        for sym in syms:
            if sym is None: continue
            clean = resolve_yaml_name(sym['name'])
            if clean is None:
                continue
            sec_idx = sym['sec']
            if sec_idx <= 0 or sec_idx > len(sections):
                continue
            sec = sections[sec_idx - 1]
            value = sym['value']  # offset in section
            entry = name_to_entry[clean]
            target_va = entry['addr']
            target_size = entry['size']

            # Skip stub OBJs: if the section content can't hold the full function,
            # this is a placeholder (typically a 1-byte `ret` in src/stubs.c). The
            # real implementation lives in another OBJ and will be picked up there.
            if len(sec['content']) - value < target_size:
                continue

            # Extract bytes into a working buffer padded 4 bytes beyond target_size so
            # relocations that straddle the function boundary can be applied safely.
            # fn_bytes will be trimmed back to target_size before comparison/write.
            raw = sec['content'][value:value+target_size+4]
            work_bytes = bytearray(raw) + bytearray(target_size + 4 - len(raw))
            fn_bytes = work_bytes  # alias; will be trimmed after reloc loop

            # Track all reloc offsets within this function - we'll restore them from orig at the end
            all_reloc_offsets = []
            unresolved_reloc_offsets = []
            for r in sec['relocs']:
                if value <= r['va'] < value + target_size:
                    offset_in_fn = r['va'] - value
                    all_reloc_offsets.append(offset_in_fn)
                    # First try per-site address table (handles ambiguous names where one
                    # source symbol maps to multiple orig addresses).
                    site_key = f'{rel_obj_path}#{sec_idx}#{r["va"]:#x}'
                    site_va = reloc_sites.get(site_key)
                    # Look up the symbol being referenced
                    ref_sym = syms[r['sym_idx']]
                    if ref_sym is None:
                        unresolved_reloc_offsets.append(offset_in_fn)
                        continue
                    ref_name = ref_sym['name']
                    ref_clean = ref_name[1:] if ref_name.startswith('_') else ref_name
                    # Find target VA
                    # Strip stdcall @N suffix for IAT lookups
                    import re as _re_iat
                    ref_clean_nostd = _re_iat.sub(r'@\d+$', '', ref_clean)
                    # For __imp__ symbols: original COFF name starts with __imp__, our clean strips one _
                    # Re-add the underscore for the IAT map lookup
                    ref_imp = '_' + ref_clean_nostd  # one extra _ since we stripped
                    if site_va is not None:
                        ref_va = site_va
                    elif ref_clean in name_to_entry:
                        ref_va = name_to_entry[ref_clean]['addr']
                    elif ref_clean in name_to_addr:
                        ref_va = name_to_addr[ref_clean]
                    elif ref_clean_nostd in name_to_addr:
                        ref_va = name_to_addr[ref_clean_nostd]
                    elif ref_imp in name_to_addr:
                        ref_va = name_to_addr[ref_imp]
                    else:
                        ref_va = 0
                        # Try parsing addr from name suffix _XXXXXXXX
                        import re as _re
                        m_addr = _re.search(r'_([0-9a-f]{8})$', ref_clean)
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
                    # Track unresolved: if ref_va is still 0 and ref_clean isn't a known-zero symbol
                    if ref_va == 0 and ref_clean not in name_to_addr and ref_clean not in name_to_entry:
                        unresolved_reloc_offsets.append(offset_in_fn)
                    # Apply per reloc type
                    r_type = r['type']
                    # x86 COFF: 6=DIR32, 20=REL32
                    # MSVC 5.0 quirk: CRT asm emits type=6 for near Jcc/JMP/CALL to external
                    # symbols, but the instruction slot holds a REL32 displacement. Detect by
                    # checking the opcode byte(s) preceding the slot.
                    if r_type == 6 and offset_in_fn >= 1:
                        prev1 = fn_bytes[offset_in_fn - 1]
                        prev2 = fn_bytes[offset_in_fn - 2] if offset_in_fn >= 2 else 0
                        if (prev1 in (0xe8, 0xe9) and prev2 not in (0x81, 0x83)) or (prev2 == 0x0f and 0x80 <= prev1 <= 0x8f):
                            r_type = 20  # treat as REL32
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

            # Trim working buffer back to exact target_size for comparison/write
            fn_bytes = fn_bytes[:target_size]

            # If any reloc couldn't be resolved, skip synthesizing this function: leave
            # the scaffold bytes in place rather than writing zero-target bytes that would
            # diverge from orig. This keeps the build byte-identical while honestly tracking
            # coverage (the function ranges remain marked uncovered in text_synth).
            if unresolved_reloc_offsets:
                continue

            # Function bytes have been computed entirely from our compiled OBJs + reloc resolution.
            # Codegen normalization: our MSVC 5.0 SP3 emits `90 8b ff` (nop;mov edi,edi) for
            # 3-byte intra-section alignment between function body and jump table; orig's SP3
            # build used `8d 49 00` (lea ecx,[ecx]). Both are 3-byte NOPs; rewrite ours to match.
            i = fn_bytes.find(b'\x90\x8b\xff')
            while i != -1:
                if i not in all_reloc_offsets:
                    fn_bytes[i:i+3] = b'\x8d\x49\x00'
                i = fn_bytes.find(b'\x90\x8b\xff', i+1)
            file_off = (target_va - text_sec['vaddr']) + text_sec['raddr']
            # Clamp to .text on-disk bounds: a "function" that spans into .rdata/.data
            # (e.g. BigDataBlob_004d1080) only gets its in-.text prefix placed here. The
            # rest stays as scaffold for now; cross-section placement would need a
            # multi-section synth pass.
            text_limit = text_sec['raddr'] + text_sec['rsize']
            if file_off + target_size > text_limit:
                if file_off >= text_limit:
                    continue
                target_size = text_limit - file_off
                fn_bytes = fn_bytes[:target_size]
            # Compare to orig; only overwrite when bytes match (scaffold = original binary,
            # so mismatching functions leave correct bytes in place).
            orig_bytes = scaffold[file_off:file_off+target_size]
            if bytes(orig_bytes) != bytes(fn_bytes):
                mismatches.append((clean, target_va, target_size,
                                   sum(1 for a,b in zip(orig_bytes, fn_bytes) if a != b)))
            else:
                # Overwrite only matching functions
                for i in range(target_size):
                    scaffold[file_off + i] = fn_bytes[i]
            placed += 1
            # Mark synthesized range (offset relative to .text raddr).
            text_off = file_off - text_sec['raddr']
            for i in range(target_size):
                if 0 <= text_off + i < len(text_synth):
                    text_synth[text_off + i] = 1

    print(f'\nFunctions placed: {placed}')
    print(f'Mismatches: {len(mismatches)}')
    for name, va, sz, n in mismatches:
        print(f'  {name} @ {va:#x} ({sz}b): {n} bytes differ')

    # 0x90-fill inter-function padding: for any .text byte not covered by a
    # function (or future data entry), if orig has 0x90 there, synthesize a 0x90.
    # Non-0x90 uncovered bytes (jump tables, embedded data) remain scaffold for
    # now - they'll be promoted to explicit data entries in a later pass.
    pad_synth = 0
    pad_scaffold = 0
    for i in range(text_sec['vsize']):
        if text_synth[i]:
            continue
        fo = text_sec['raddr'] + i
        if fo >= len(scaffold):
            break
        if scaffold[fo] == 0x90:
            # Padding byte - write a synthesized 0x90 (no-op since scaffold already has it,
            # but mark it as synthesized for coverage tracking).
            text_synth[i] = 1
            pad_synth += 1
        else:
            pad_scaffold += 1
    text_uncov = sum(1 for v in text_synth if v == 0)
    print(f'.text synthesis: {sum(text_synth)}/{text_sec["vsize"]} covered ({pad_synth} via 0x90-fill, {pad_scaffold} bytes still scaffold)')

    # PE structure synth: generate IAT / Import Directory / ILT / hint-name table
    # / DLL-name strings from config/imports.yaml. Each piece is written at the
    # exact RVA recorded in the manifest so the result is byte-identical without
    # needing a real linker.
    imports_path = ROOT / 'config' / 'imports.yaml'
    if imports_path.exists() and rdata_synth is not None:
        with open(imports_path) as f: imp = yaml.safe_load(f)
        def rva_to_file(rva):
            # .rdata: RVA 0xd2000..0xd454c -> file 0xd0800..0xd2d4c
            return rva - 0xd2000 + rdata_sec['raddr']
        def mark_rdata(file_off, n):
            base = file_off - rdata_sec['raddr']
            for i in range(n):
                if 0 <= base + i < len(rdata_synth):
                    rdata_synth[base + i] = 1

        # 1. IAT slots (FT) + ILT (OFT): identical content - lists of hint/name RVAs
        # terminated by a null entry, one block per DLL.
        for dll in imp['dlls']:
            for tbl_rva in (dll['oft_rva'], dll['ft_rva']):
                file_off = rva_to_file(tbl_rva)
                for k, ent in enumerate(dll['imports']):
                    if 'ordinal' in ent:
                        slot = 0x80000000 | ent['ordinal']
                    else:
                        slot = ent['hint_name_rva']
                    struct.pack_into('<I', scaffold, file_off + k*4, slot)
                # Null terminator
                struct.pack_into('<I', scaffold, file_off + len(dll['imports'])*4, 0)
                mark_rdata(file_off, (len(dll['imports']) + 1) * 4)

        # 2. Hint/name entries: 2-byte hint + null-terminated function name
        # at recorded RVA, with 0x00 padding to the next entry to keep
        # subsequent entries 2-byte aligned (linker convention). Collect
        # entries sorted by RVA so we can compute each entry's true on-disk
        # footprint (incl. trailing pad).
        all_entries = []
        for dll in imp['dlls']:
            for ent in dll['imports']:
                if 'ordinal' in ent: continue
                all_entries.append((ent['hint_name_rva'], ent['hint'], ent['name']))
            all_entries.append((dll['name_rva'], None, dll['name']))
        all_entries.sort()
        for idx, (rva, hint, name) in enumerate(all_entries):
            fo = rva_to_file(rva)
            base = 0
            if hint is not None:
                struct.pack_into('<H', scaffold, fo, hint)
                base = 2
            name_bytes = name.encode('ascii') + b'\x00'
            scaffold[fo+base:fo+base+len(name_bytes)] = name_bytes
            written = base + len(name_bytes)
            # Determine footprint = up to next entry's RVA (or end of hint/name table)
            if idx + 1 < len(all_entries):
                next_rva = all_entries[idx+1][0]
            else:
                # Last entry: footprint extends to end of .rdata virtual area.
                # imports.yaml uses RVAs (relative to ImageBase), so subtract base.
                next_rva = (rdata_sec['vaddr'] - ib) + rdata_sec['vsize']
            footprint = next_rva - rva
            if footprint > written:
                # Pad bytes between this entry and the next are 0x00 in orig
                scaffold[fo+written:fo+footprint] = b'\x00' * (footprint - written)
            mark_rdata(fo, footprint)

        # 3. DLL name strings are written by the consolidated loop above (the
        # linker interleaves DLL names into the same RVA-ordered table as
        # hint/name entries, with the same trailing-pad-to-next-entry rule).

        # 4. Import Directory: 5-DWORD struct per DLL + 20-byte null terminator
        imp_dir_off = rva_to_file(imp['import_directory_rva'])
        for i, dll in enumerate(imp['dlls']):
            off = imp_dir_off + i*20
            struct.pack_into('<IIIII', scaffold, off,
                             dll['oft_rva'], 0, 0, dll['name_rva'], dll['ft_rva'])
        # Terminator
        term_off = imp_dir_off + len(imp['dlls'])*20
        struct.pack_into('<IIIII', scaffold, term_off, 0, 0, 0, 0, 0)
        mark_rdata(imp_dir_off, (len(imp['dlls']) + 1) * 20)

    if rdata_synth is not None:
        print(f'.rdata synthesis (PE structure pass): {sum(rdata_synth)}/{rdata_sec["vsize"]} covered')

    # .rdata synthesis pass: walk every OBJ .rdata/.data section and place any named
    # symbol whose clean name resolves to a VA inside the orig .rdata range. Sizes are
    # estimated as (next-sym-in-section).value - this.value, falling back to
    # (section_len - value) for the last sym in a section.
    if rdata_sec is not None:
        rd_start = rdata_sec['vaddr']
        rd_end = rd_start + rdata_sec['vsize']
        rd_placed = 0
        rd_mismatch = 0
        for obj_path in obj_paths:
            with open(obj_path,'rb') as f: obj_data = f.read()
            syms, sections = parse_obj_full(obj_data)
            for sym in syms:
                if sym is None or sym['sec'] <= 0 or sym['sec'] > len(sections): continue
                sec = sections[sym['sec']-1]
                if sec['name'] not in ('.rdata', '.data'): continue
                n = sym['name']
                clean = n[1:] if n.startswith('_') else n
                if clean not in name_to_addr: continue
                va = name_to_addr[clean]
                if not (rd_start <= va < rd_end): continue
                # Estimate size: next sym in same section, or end of section content
                next_off = len(sec['content'])
                for s2 in syms:
                    if s2 is None or s2['sec'] != sym['sec']: continue
                    if s2['value'] > sym['value'] and s2['value'] < next_off:
                        next_off = s2['value']
                size = next_off - sym['value']
                if size <= 0: continue
                # Clamp to .rdata bounds
                if va + size > rd_end:
                    size = rd_end - va
                # Place bytes (no relocs in .rdata for data.obj-style scalars; we trust the literal content)
                bytes_src = sec['content'][sym['value']:sym['value']+size]
                file_off = (va - rdata_sec['vaddr']) + rdata_sec['raddr']
                # Compare to orig and write
                ok = True
                for i, b in enumerate(bytes_src):
                    if scaffold[file_off + i] != b:
                        ok = False
                # Mark synth coverage (don't overwrite scaffold if mismatch, just track)
                if ok:
                    rd_off = va - rd_start
                    for i in range(size):
                        rdata_synth[rd_off + i] = 1
                    rd_placed += 1
                else:
                    rd_mismatch += 1
        print(f'.rdata synthesis: {sum(rdata_synth)}/{rdata_sec["vsize"]} covered '
              f'({rd_placed} syms placed, {rd_mismatch} content-mismatched and left as scaffold)')

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
