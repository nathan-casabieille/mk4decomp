import json, re, subprocess, os
from pathlib import Path

SDL='/opt/homebrew'
BASE_SRCS=['src/platform/sdl/main_sdl.c','src/platform/sdl/pal_sdl.c',
           'src/platform/sdl/host_win32.c','src/platform/sdl/engine_frame.c',
           'src/platform/sdl/engine_stubs.c','src/portable/arena.c','src/boot/main_loop.c','src/game/tick.c','src/engine/draw_scene.c']
# Giant dispatch/aggregate files: never auto-add (huge + naked asm).
GIANT=set(['src/engine/five_block_dispatch_variants.c','src/engine/prefix_thunk_install_self3_state.c',
           'src/engine/install_self_state_countdown.c','src/engine/install3_state_m_stack_counter_dispatch.c'])
idx=json.load(open('/tmp/symidx.json'))
CFLAGS=['-DNON_MATCHING','-DMK4_ARENA','-DTARGET_SDL','-DMK4_WIN32_SHIM','-Iinclude',
        '-I'+SDL+'/include','-O2','-w','-Wno-int-conversion','-Wno-incompatible-pointer-types',
        '-Wno-int-to-pointer-cast','-Wno-implicit-function-declaration']

def compiles(f):
    r=subprocess.run(['cc']+CFLAGS+['-c',f,'-o','/tmp/cc_test.o'],capture_output=True,text=True)
    return r.returncode==0

def link_undef(srcs):
    r=subprocess.run(['cc']+CFLAGS+srcs+['-L'+SDL+'/lib','-lSDL2','-o','/tmp/grow.out'],
                     capture_output=True,text=True)
    if r.returncode==0: return None
    return sorted(set(re.findall(r'"_([A-Za-z_]\w*)"', r.stderr)))

def pick_file(sym):
    cands=[c for c in idx.get(sym,[]) if c not in GIANT]
    if not cands: return None
    # prefer the most dedicated: fewest other symbols / smallest file
    cands.sort(key=lambda c: Path(c).stat().st_size)
    return cands[0]

# Seed from the CURRENT native-full list rather than a fixed base set, so this
# extends the build instead of restarting it.
CUR = Path('tools/decomp/native_full_srcs.txt')
srcs = list(BASE_SRCS)
if CUR.exists():
    srcs += [l.strip() for l in CUR.read_text().split('\n')
             if l.strip() and l.strip() not in srcs and Path(l.strip()).exists()]
srcs += [str(f) for f in sorted(Path('src/platform/sdl').glob('*.c'))
         if str(f) not in srcs]
if 'src/portable/arena.c' not in srcs: srcs.append('src/portable/arena.c')

def alias(f):
    """Arena-alias a file before adding it. A non-aliased TU would see
    different storage for the same globals than the rest of the build."""
    if 'alias_globals.py' in Path(f).read_text():
        return True
    bak = Path(f).read_text()
    subprocess.run(['build/venv/bin/python','tools/decomp/alias_globals.py',f],
                   capture_output=True, text=True)
    if compiles(f):
        return True
    Path(f).write_text(bak)      # keep it un-aliased rather than broken
    return compiles(f)

added=[]; stub_needed=set(); compile_fail=set()
for rnd in range(40):
    undef=link_undef(srcs)
    if undef is None:
        print('LINKED at round',rnd); break
    progress=False
    for sym in undef:
        if sym.startswith('g_') or sym.startswith('MK4_'): 
            stub_needed.add(sym); continue
        f=pick_file(sym)
        if not f: stub_needed.add(sym); continue
        if f in srcs: continue
        if not compiles(f): compile_fail.add(f); stub_needed.add(sym); continue
        alias(f)
        srcs.append(f); added.append(f); progress=True
    if not progress:
        print('no progress at round',rnd); break
print('added files:',len(added))
for a in added: print('  +',a)
print('stub-needed symbols:',len(stub_needed))
print('compile-fail files:',len(compile_fail))
open('/tmp/grow_srcs.txt','w').write('\n'.join(srcs))
open('/tmp/grow_stubs.txt','w').write('\n'.join(sorted(stub_needed)))
