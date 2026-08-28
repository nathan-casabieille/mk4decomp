#!/usr/bin/env python3
"""Run a function's ORIGINAL bytes in the emulator and report what it writes.

Not a verification tool - a search tool. When a global is only ever written
through a COMPUTED index (no instruction anywhere names its address), the
static search that finds every other writer comes up empty, and the only way
left to find the writer is to run candidates and look at their write sets.

That is exactly the situation for the three scene-list heads the render walk
reads (0x53a1e0, 0x53a738, 0x541e50): disassembling every function finds
nothing but TickAllEntities READING them.

    probe_writes.py <fn> [<fn>...] [--watch 0x53a1e4,0x53a73c]

Seeds come from verify_frame_core's SEEDS when the function has an entry,
otherwise the arena is used as-is. A hit means that function, with that
state, stored to the watched address - it is a lead to read, not a proof.
"""
import sys
import pathlib

sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))

import verify_coexec as vc
import verify_twin as vt
import verify_frame_core as vfc


def main():
    args = [a for a in sys.argv[1:] if not a.startswith('--')]
    watch = []
    fight = '--fight' in sys.argv
    for a in sys.argv[1:]:
        if a.startswith('--watch'):
            watch = [int(x, 16) for x in a.split('=', 1)[1].split(',')]
    if '--all' in sys.argv:
        # Sweep every function in the map. Most return in a few hundred
        # instructions or take an early exit; the cap and the wall clock bound
        # the rest. A sweep is the point of the tool - the writer we are after
        # is by construction one that no static search can name.
        args = sorted(vt.load_maps()[0])
    if not args:
        print(__doc__)
        return 2

    fn_va, gl_va = vt.load_maps()
    base_arena = vc.ARENA.read_bytes()
    vc.ARG_BASE = vc.BASE + len(base_arena) - 0x40000
    for name in args:
        if name not in fn_va:
            print(f'{name}: no symbol')
            continue
        arena = bytearray(base_arena)
        spec = vfc.SEEDS.get(name)
        if spec:
            vfc.seed(arena, gl_va, spec[-1][1])
        elif fight:
            # A generic mid-fight state, so a candidate takes its real path
            # instead of the first early exit. Everything here is what the
            # engine itself leaves set once a match is running: a scheduled
            # node, both players, a stocked scene-node free chain, and the
            # pause/dirty flags clear.
            vfc.seed(arena, gl_va, {
                'g_framePauseFlag': 0, 'g_xformDirtyFlags': 0,
                'g_baseSel': 0x14f94e, 'g_currentNodeIdx': 0x13542c,
                'g_xformEntityIdx': 0x13542c, 'g_fightGroupHead': 0x13542c,
                'g_matrixStackTop': 0x14e05a, 'g_walkCallback': 0,
                'g_eventQueueCurrent': 0, 'g_pendingNodeType': 0,
                '@0x538158': 0x13542c, '@0x53815c': 0x13542c,
                '@0x537f48': 0, '@0x5380e0': 1, '@0x53a51c': 0,
                '@0x541e70': 0x14d7a2, '@0x541e74': 0x14d782,
                '@0x541e78': 0x14e9de,
                '@0x535e0c': 0x14d7a2, '@0x535e88': 0,
                '@0x535e9c': 0x7fc,
            })
        before = bytearray(vc.BASE) + bytes(arena)   # emulator image is 0-based
        uc, full = vc.uc_new(arena)
        try:
            after, terminated, _ = vc.run_at(uc, fn_va[name], full)
        except Exception as e:
            print(f'{name:38s} EMU-ERROR {type(e).__name__}: {str(e)[:60]}')
            continue
        n = min(len(after), len(before))
        diffs = [i for i in range(0, n, 4)
                 if after[i:i+4] != before[i:i+4]]
        del uc, after, before, arena
        hits = [d for d in diffs if any(w - 3 <= d <= w for w in watch)]
        note = 'ran out' if not terminated else 'returned'
        if hits:
            print(f'{name:38s} {note:8s} HIT {[hex(h) for h in hits]}')
        else:
            print(f'{name:38s} {note:8s} {len(diffs)} writes, no hit')
    return 0


if __name__ == '__main__':
    sys.exit(main())
