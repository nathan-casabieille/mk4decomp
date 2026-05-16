"""Audit symbols.yaml function names against their actual behavior.

Heuristic check: a function whose name claims it does X should be calling
other X-family functions and/or accessing X-family globals/IAT slots. When
the body shape contradicts the name, flag the entry for review.

Outputs a ranked list of suspects, worst first.

Usage: python3 tools/decomp/audit_names.py [--top N]
"""
import os, re, struct, sys, yaml
from collections import Counter, defaultdict
from pathlib import Path

with open('game/MK4.EXE','rb') as f:
    ORIG = f.read()

with open('config/symbols.yaml') as f:
    YDAT = yaml.safe_load(f)
ADDR_TO_NAME = {e['addr']: e['name'] for e in YDAT['functions']}


def fileoff(va):
    return va - 0x401000 + 0x400


# Behavior tags we extract from each function body
def analyze_body(addr, sz):
    fo = fileoff(addr)
    if fo + sz > len(ORIG):
        return {}
    data = ORIG[fo:fo+sz]
    calls = []
    dir32 = []
    iat = []
    has_fpu = False
    has_seh = False
    has_rep_movs = False
    has_switch = False
    i = 0
    while i < sz:
        op = data[i]
        if op == 0xe8 and i + 5 <= sz:
            rel = struct.unpack_from('<i', data, i+1)[0]
            calls.append(addr + i + 5 + rel)
            i += 5; continue
        if op == 0xff and i + 6 <= sz:
            if data[i+1] == 0x15:
                iat.append(struct.unpack_from('<I', data, i+2)[0])
                i += 6; continue
            if data[i+1] == 0x24 and data[i+2] == 0x85:
                has_switch = True
                i += 7; continue
        if op in (0xa1, 0xa3) and i + 5 <= sz:
            ptr = struct.unpack_from('<I', data, i+1)[0]
            if 0x400000 < ptr < 0xfa0ef4:
                dir32.append(ptr)
            i += 5; continue
        if op == 0xf3 and i + 2 <= sz and data[i+1] in (0xa4, 0xa5, 0xab):
            has_rep_movs = True
        if op == 0x64:
            has_seh = True
        if 0xd8 <= op <= 0xdf:
            has_fpu = True
        i += 1
    callee_names = [ADDR_TO_NAME.get(t, '') for t in calls]
    return {
        'calls': calls,
        'callee_names': callee_names,
        'dir32_globals': dir32,
        'iat_slots': iat,
        'has_fpu': has_fpu,
        'has_seh': has_seh,
        'has_rep_movs': has_rep_movs,
        'has_switch': has_switch,
    }


def behavior_tags(info):
    """Reduce body analysis to a tag set used to verify name claims."""
    tags = set()
    if info['has_fpu']: tags.add('fpu')
    if info['has_seh']: tags.add('seh')
    if info['has_rep_movs']: tags.add('rep-movs')
    if info['has_switch']: tags.add('switch')
    # CRT region: 0x4c0000 - 0x4d2000 contains the C runtime
    for t in info['calls']:
        if 0x4c0000 <= t < 0x4d2000:
            tags.add('crt-call')
    for g in info['dir32_globals']:
        if 0x4c0000 <= g < 0x4d2000 or 0xf9f000 <= g < 0xfa0ef4:
            tags.add('crt-global')
        if 0x542000 <= g < 0x543000:
            tags.add('game-state-global')
    # Look at callee name prefixes
    name_kinds = Counter()
    for n in info['callee_names']:
        if n.startswith('Crt'): name_kinds['Crt'] += 1
        elif n.startswith('Audio'): name_kinds['Audio'] += 1
        elif n.startswith('Render'): name_kinds['Render'] += 1
        elif n.startswith('MStack'): name_kinds['MStack'] += 1
        elif n.startswith('Boot'): name_kinds['Boot'] += 1
        elif n.startswith('DDraw'): name_kinds['DDraw'] += 1
        elif n.startswith('Helper_'): name_kinds['Helper'] += 1
        elif n.startswith('FpuFlag') or n.startswith('GetFpu'): name_kinds['Fpu'] += 1
    return tags, name_kinds


def name_kind(name):
    """Return the descriptive prefix of a function name, or None."""
    m = re.match(r'^(Crt|Audio|Render|MStack|Boot|DDraw|Scene|Game|Fpu|Io|Set|Get|Fopen|FRead|FWrite|FClose|Tm|Time|Locale|Mb[A-Z]|Wcs|Str|Mem|Float|Double|Int|Helper|Install|Push|Pop|Walk|Chain|Tick|Frame|Draw|Format|Parse|Init|Free|Alloc|Calloc|Malloc|Realloc|Open|Close|Lseek|Read|Write)', name)
    return m.group(1) if m else None


def audit():
    suspects = []
    for e in YDAT['functions']:
        if e['size'] < 50: continue  # tiny stubs not worth auditing
        info = analyze_body(e['addr'], e['size'])
        if not info: continue
        tags, kinds = behavior_tags(info)
        name = e['name']
        kind = name_kind(name)
        if not kind: continue
        reasons = []
        # Rule 1: name says Crt* but body doesn't call any CRT functions
        # AND doesn't touch CRT globals AND has no IAT calls
        if kind == 'Crt':
            crt_calls = sum(1 for n in info['callee_names'] if n.startswith('Crt'))
            has_crt_signal = ('crt-call' in tags or 'crt-global' in tags or
                              info['iat_slots'] or crt_calls > 0)
            game_calls = sum(1 for n in info['callee_names']
                             if any(n.startswith(p) for p in ('Audio', 'MStack', 'Boot',
                                                              'Game', 'Render', 'Scene',
                                                              'Tick', 'Frame')))
            if not has_crt_signal and game_calls > 0:
                reasons.append(f'Crt* name but {game_calls} game/audio callees, no CRT signal')
        # Rule 2: name says Audio but no audio callees
        if kind == 'Audio':
            audio_calls = sum(1 for n in info['callee_names'] if n.startswith('Audio'))
            crt_calls = sum(1 for n in info['callee_names'] if n.startswith('Crt'))
            if audio_calls == 0 and crt_calls > 2:
                reasons.append(f'Audio* name but 0 audio callees, {crt_calls} CRT callees')
        # Rule 3: name says Render but no render context
        if kind == 'Render':
            render_calls = sum(1 for n in info['callee_names']
                               if n.startswith(('Render', 'Draw', 'Scene')))
            crt_calls = sum(1 for n in info['callee_names'] if n.startswith('Crt'))
            if render_calls == 0 and crt_calls > 2:
                reasons.append(f'Render* name but 0 render callees, {crt_calls} CRT callees')
        # Rule 4: name says Boot but no boot callees + lots of CRT
        if kind == 'Boot':
            boot_calls = sum(1 for n in info['callee_names'] if n.startswith('Boot'))
            crt_calls = sum(1 for n in info['callee_names'] if n.startswith('Crt'))
            if boot_calls == 0 and crt_calls > 3:
                reasons.append(f'Boot* name but 0 boot callees, {crt_calls} CRT callees')
        # Rule 5: name says Fpu* but no FPU ops + no Fpu callees
        if kind == 'Fpu':
            if not info['has_fpu']:
                fpu_callees = sum(1 for n in info['callee_names'] if 'Fpu' in n or 'fpu' in n.lower())
                if fpu_callees == 0:
                    reasons.append('Fpu* name but no FPU ops and 0 FPU callees')
        # Rule 6: name says Io/Stream/Lseek but body has lots of FPU
        if kind in ('Io', 'Lseek', 'Read', 'Write') and info['has_fpu']:
            reasons.append(f'{kind}* name but body uses FPU')
        # Rule 7: name implies file I/O but body does FPU-only work
        if kind in ('Open', 'Close', 'FRead', 'FWrite'):
            if info['has_fpu'] and not info['iat_slots']:
                reasons.append(f'{kind}* name but FPU+no IAT (not file I/O)')
        # Rule 8: Render* but no render globals + no render callees
        # already covered by rule 3, expand checking for Scene/Draw/Tick/Frame
        if kind in ('Scene', 'Draw', 'Tick', 'Frame'):
            render_calls = sum(1 for n in info['callee_names']
                               if n.startswith(('Render', 'Draw', 'Scene', 'Frame', 'Tick',
                                                'Helper_Render', 'Mat3x3', 'Camera', 'NodeApply')))
            crt_calls = sum(1 for n in info['callee_names'] if n.startswith('Crt'))
            if render_calls == 0 and crt_calls > 2:
                reasons.append(f'{kind}* name but 0 render/scene callees, {crt_calls} CRT callees')
        # Rule 9: Locale/Time but no IAT/CRT
        if kind in ('Locale', 'Tm', 'Time'):
            crt_or_iat = (sum(1 for n in info['callee_names'] if n.startswith('Crt')) +
                          len(info['iat_slots']))
            game_calls = sum(1 for n in info['callee_names']
                             if n.startswith(('Audio', 'MStack', 'Render', 'Scene', 'Game')))
            if crt_or_iat == 0 and game_calls > 0:
                reasons.append(f'{kind}* name but 0 CRT/IAT, {game_calls} game callees')
        # Rule 10: Helper_ that is huge or has many calls (true helpers are small)
        # Skip - too noisy
        # Rule 11: descriptive name calls 80% PendingMatch_ - probably itself a PendingMatch
        # in disguise
        pending_calls = sum(1 for n in info['callee_names'] if n.startswith('PendingMatch_'))
        if pending_calls >= 5 and len(info['calls']) > 0:
            ratio = pending_calls / max(len(info['calls']), 1)
            if ratio > 0.5 and kind not in ('Boot',):
                reasons.append(f'{pending_calls}/{len(info["calls"])} calls go to PendingMatch_ - likely undecoded itself')
        if reasons:
            suspects.append({
                'addr': e['addr'],
                'name': name,
                'size': e['size'],
                'reasons': reasons,
                'tags': sorted(tags),
                'kinds': dict(kinds),
                'top_callees': Counter(info['callee_names']).most_common(5),
            })
    return suspects


def main():
    suspects = audit()
    suspects.sort(key=lambda s: (-len(s['reasons']), -s['size']))
    top = int(sys.argv[2]) if len(sys.argv) > 2 and sys.argv[1] == '--top' else 30
    print(f'Found {len(suspects)} suspects. Showing top {top}:\n')
    for s in suspects[:top]:
        print(f'{s["addr"]:#x} {s["name"]} ({s["size"]}b)')
        for r in s['reasons']:
            print(f'  ! {r}')
        print(f'  tags: {", ".join(s["tags"])}')
        print(f'  kinds: {s["kinds"]}')
        print(f'  top callees: {s["top_callees"]}')
        print()


if __name__ == '__main__':
    main()
