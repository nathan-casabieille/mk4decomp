#!/usr/bin/env python3
"""Seeded co-exec for MainLoopStep's frame-core blockers.

`closure.py MainLoopStep` splits the native port's remaining work in two: a
d2..d5 band that IS the game frame, and a d7..d9 band of DDraw/DSound/registry
init the SDL backend replaces outright. This harness verifies the d2..d5 twins.

Most of them are guarded on a counter or a flag that is ZERO in the at-rest
image, so an unseeded run reports "VERIFIED (0 writes)" without having executed
the body at all - a false positive. Every entry below therefore seeds the
guard, plus at least one case that keeps the guard shut so the early-out is
covered too.

  build/venv/bin/python tools/decomp/verify_frame_core.py [NAME ...]
"""
import re
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import verify_twin as vt
import verify_coexec as vc

BASE = 0x00400000

# name -> [(label, seeds)], [(label, seeds, args)] or [(label, seeds, args, allow)]
#
# `allow` is a set of addresses permitted to hold DIFFERENT values at the end.
# There is exactly one legitimate reason for that: a global left holding the
# packed pointer to the scratch. The original's scratch is on its C stack and
# the twin's is the arena scratch stack, so when a path exits without popping,
# the two runs leave different-but-equivalent dangling pointers there. Any
# other difference, and any address written by only one side, is still a
# MISMATCH.
# A target key is a global name, or '@0xVA' to poke an absolute address.
#
# SCRATCH is a 64 KiB window near the top of the arena that nothing in the
# at-rest image uses, so fake nodes can be built there without disturbing
# real state.
SCRATCH = 0x00b90000

# Four 0x40-byte blocks laid end to end from g_memHeapStart. Header is
# {flags|size, owner slot, back link}; user pointer is header + 0xc.
def _blocks(free_mask=0, owner=0):
    d, prev = {}, 0x7b41a0
    for i in range(4):
        b = 0x7b41a0 + i * 0x40
        d['@0x%x' % b]       = 0x40 | (0x80000000 if free_mask >> i & 1 else 0)
        d['@0x%x' % (b + 4)] = owner if i == 1 else 0
        d['@0x%x' % (b + 8)] = prev
        prev = b
    return d

B1_USER = 0x7b41a0 + 0x40 + 0xc

TICKCFG = {'g_tickCurConfig': 0xb93000, '@0xb93000': 0, '@0xb93004': 0}

RET_STUB = 0x0041f2e0                    # AllocateNode's `ret`
DISPATCH = dict([('g_dispatchVar20', 0xb92000 // 4)] +
                [('@0x%x' % (0xb92000 + i * 4), RET_STUB) for i in range(4)])

HEAP = [
    ('@0x7b41a0', (5 << 24) | 0x20), ('@0x7b41a4', 0),
    ('@0x7b41c0', (5 << 24) | 0x20), ('@0x7b41c4', 0x7b4300),
    ('@0x7b4300', 0x7b4400),
    ('@0x7b41e0', (7 << 24) | 0x20), ('@0x7b41e4', 0),
    ('@0x7b4200', 0xc0000000 | (5 << 24) | 0x20), ('@0x7b4204', 0),
    ('@0x7b4220', 0xc0000000 | 0x300000), ('@0x7b4224', 0),
]
SEEDS = {
    'FpuSqrtMul': [
        ('guard shut (0)',      {'g_eventQueueWorkType': 0}),
        ('guard shut (neg)',    {'g_eventQueueWorkType': -4}),
        ('one',                 {'g_eventQueueWorkType': 1}),
        ('small',               {'g_eventQueueWorkType': 7}),
        ('fixed 1.0',           {'g_eventQueueWorkType': 0x10000}),
        ('large',               {'g_eventQueueWorkType': 0x3fffffff}),
        ('int max',             {'g_eventQueueWorkType': 0x7fffffff}),
    ],
    # FightFrameStep_Inner walks a chain of packed-pointer words. At rest every
    # one of them is zero, so the whole body is skipped and an unseeded run says
    # "0 writes". These lay a chain out in SCRATCH:
    #   NODE_A  the word behind g_cj_0054205c (its low 16 bits are the mask)
    #   CUR     the slot behind g_currentNodeIdx - XOR of the two picks the path
    #   CHAIN   g_dualC's word list, stepping 8 bytes, 0-terminated
    #   HEAD    g_eventQueueHead's node
    # NodeApplyTransform_B_Swapped hands a packed pointer to a 12-byte scratch
    # to its callee. The original's scratch is on the C stack and the twin's is
    # the arena scratch stack (MK4_ALLOCA), so the scratch bytes themselves are
    # NOT comparable - what these check is that every arena-visible effect
    # (the matrix-stack pushes and pops, g_walkCallback, the chain reads) is
    # identical, on both the normal and the frame-paused exit.
    'NodeApplyTransform_B_Swapped': [
        ('normal exit',  {'g_matrixStackTop': 0x2e4400, 'g_xformEntityIdx': 0x2e4000,
                          'g_pendingNodeType': 0x1234, 'g_framePauseFlag': 0,
                          '@0xb90000': 0x11111111, '@0xb90004': 0x22222222,
                          '@0xb90008': 0x33333333}),
        # the paused exit skips the two pops, so the scratch pointer is still
        # in g_xformEntityIdx / g_pendingNodeType when the function returns
        ('frame paused', {'g_matrixStackTop': 0x2e4400, 'g_xformEntityIdx': 0x2e4000,
                          'g_pendingNodeType': 0x1234, 'g_framePauseFlag': 1,
                          '@0xb90000': 0x11111111, '@0xb90004': 0x22222222,
                          '@0xb90008': 0x33333333},
                         None, {0x542048, 0x54204c}),
        ('zero chain',   {'g_matrixStackTop': 0x2e4400, 'g_xformEntityIdx': 0x2e4000,
                          'g_pendingNodeType': 0, 'g_framePauseFlag': 0,
                          '@0xb90000': 0, '@0xb90004': 0, '@0xb90008': 0}),
    ],
    # Dispatch index is 0/1/2/3 from two signed tests; the slot it lands on
    # holds a code VA. RET_STUB is AllocateNode's own `ret` byte, so the
    # dispatched call returns immediately in both runs.
    'GeoTransformDispatchAndApply': [
        ('index 0',       dict(DISPATCH, **{'g_primary_0052d74c': 0,
                                            'g_secondary_00538068': 0})),
        ('index 2 (primary)', dict(DISPATCH, **{'g_primary_0052d74c': 5,
                                            'g_secondary_00538068': 0})),
        ('index 1 (secondary)', dict(DISPATCH, **{'g_primary_0052d74c': 0,
                                            'g_secondary_00538068': 7})),
        ('index 3 (both)', dict(DISPATCH, **{'g_primary_0052d74c': 5,
                                            'g_secondary_00538068': 7})),
        ('secondary negative', dict(DISPATCH, **{'g_primary_0052d74c': 5,
                                            'g_secondary_00538068': -7})),
        ('primary negative', dict(DISPATCH, **{'g_primary_0052d74c': -5,
                                            'g_secondary_00538068': 0})),
    ],
    # TickAllEntities: g_tickInitFlag picks between the five-pass first frame
    # and the single main pass; g_framePauseFlag abandons the sequence after
    # any pass. TICKCFG points g_tickCurConfig at a scratch struct whose
    # bytes 4 and 5 pick the pass-3 mask and the pass-4 Inner/Alt branch.
    'TickAllEntities': [
        ('steady frame',      dict(TICKCFG, **{'g_tickInitFlag': 1, 'g_framePauseFlag': 0,
                                               'g_tickDecay': 5, 'g_tickW1': 0x40})),
        ('steady, decay 0',   dict(TICKCFG, **{'g_tickInitFlag': 1, 'g_framePauseFlag': 0,
                                               'g_tickDecay': 0, 'g_tickW1': 0x40})),
        ('W1 over the clamp', dict(TICKCFG, **{'g_tickInitFlag': 1, 'g_framePauseFlag': 0,
                                               'g_tickDecay': 5, 'g_tickW1': 0x4000})),
        ('byte flag set',     dict(TICKCFG, **{'g_tickInitFlag': 1, 'g_framePauseFlag': 0,
                                               'g_tickDecay': 5, 'g_tickW1': 0x40,
                                               '@0x543720': 1})),
        ('first frame',       dict(TICKCFG, **{'g_tickInitFlag': 0, 'g_framePauseFlag': 0,
                                               'g_tickDecay': 5, 'g_tickW1': 0x40})),
        ('first frame, alt',  dict(TICKCFG, **{'g_tickInitFlag': 0, 'g_framePauseFlag': 0,
                                               'g_tickDecay': 5, 'g_tickW1': 0x40,
                                               'g_tickFlagV': 1, 'g_tickFlagF': 7,
                                               '@0xb93004': 0x01010101})),
        ('paused up front',   dict(TICKCFG, **{'g_tickInitFlag': 0, 'g_framePauseFlag': 1,
                                               'g_tickDecay': 5, 'g_tickW1': 0x40})),
    ],
    'Mem_Free': [
        ('below the heap',      _blocks(),          (0x7b0000,)),
        ('above the heap',      _blocks(),          (0xac0000,)),
        ('plain free',          _blocks(),          (B1_USER,)),
        ('clears owner handle', _blocks(owner=0xb90000), (B1_USER,)),
        ('coalesce prev',       _blocks(free_mask=1), (B1_USER,)),
        ('coalesce next',       _blocks(free_mask=4), (B1_USER,)),
        ('coalesce both',       _blocks(free_mask=5), (B1_USER,)),
    ],
    'FightFrameStep_Inner': [
        ('xor zero: early out',  {'@0xb90000': 0x1234, '@0xb90010': 0x1234,
                                  '@0xb90020': 0x99,
                                  'g_cj_0054205c': 0x2e4000, 'g_currentNodeIdx': 0x2e4004,
                                  'g_eventQueuePending': 0x2e4008}),
        ('subset mask: dualC=dualD', {'@0xb90000': 0x00ff, '@0xb90010': 0x00f0,
                                  '@0xb90020': 0x0f0f,
                                  '@0xb90100': 0x0f, '@0xb90104': 0x5555, '@0xb90108': 0,
                                  'g_cj_0054205c': 0x2e4000, 'g_currentNodeIdx': 0x2e4004,
                                  'g_eventQueuePending': 0x2e4008,
                                  'g_dualC': 0xdead, 'g_dualD': 0x2e4040,
                                  'g_eventQueueHead': 0x2e4080}),
        ('disjoint mask: walk',  {'@0xb90000': 0x000f, '@0xb90010': 0x00ff,
                                  '@0xb90020': 0xffff,
                                  '@0xb90100': 0xf0, '@0xb90104': 0x5555, '@0xb90108': 0,
                                  'g_cj_0054205c': 0x2e4000, 'g_currentNodeIdx': 0x2e4004,
                                  'g_eventQueuePending': 0x2e4008,
                                  'g_dualC': 0x2e4040, 'g_dualD': 0xbeef,
                                  'g_eventQueueHead': 0x2e4080}),
        ('walk, 3-word chain',   {'@0xb90000': 0x000f, '@0xb90010': 0x00ff,
                                  '@0xb90020': 0xffff,
                                  '@0xb90100': 0xf0, '@0xb90104': 0x5555,
                                  '@0xb90108': 0x30, '@0xb9010c': 0x6666,
                                  '@0xb90110': 0,
                                  'g_cj_0054205c': 0x2e4000, 'g_currentNodeIdx': 0x2e4004,
                                  'g_eventQueuePending': 0x2e4008,
                                  'g_dualC': 0x2e4040, 'g_dualD': 0xbeef,
                                  'g_eventQueueHead': 0x2e4080}),
        ('head wraps at 0x14e942', {'@0xb90000': 0x000f, '@0xb90010': 0x00ff,
                                  '@0xb90020': 0xffff,
                                  '@0xb90100': 0xf0, '@0xb90104': 0x5555, '@0xb90108': 0,
                                  'g_cj_0054205c': 0x2e4000, 'g_currentNodeIdx': 0x2e4004,
                                  'g_eventQueuePending': 0x2e4008,
                                  'g_dualC': 0x2e4040, 'g_dualD': 0xbeef,
                                  'g_eventQueueHead': 0x14e941}),
    ],
    # AllocateNode picks the first slot whose ptr_field (node + 0xd8) is zero.
    # The at-rest image has slot 0 free, so seed occupied slots to move the
    # find, and fill all 64 to reach the exhausted path.
    'AllocateNode': [
        ('empty list, slot 0',  {'g_nodeListTail': 0}, (0x1234,)),
        ('slot 0 taken',        {'g_nodeListTail': 0,
                                 '@0x53e440': 0x99}, (0x1234,)),
        ('slots 0-2 taken',     {'g_nodeListTail': 0,
                                 '@0x53e440': 0x99, '@0x53e528': 0x99,
                                 '@0x53e610': 0x99}, (0x1234,)),
        ('splices onto a list', {'g_nodeListTail': 0xb90000,
                                 '@0xb900e4': 0}, (0x5678,)),
        ('walks a 2-deep list', {'g_nodeListTail': 0xb90000,
                                 '@0xb900e4': 0xb91000, '@0xb910e4': 0}, (0x5678,)),
        ('all 64 slots taken',  dict([('g_nodeListTail', 0)] +
                                     [('@0x%x' % (0x53e440 + i * 0xe8), 0x99)
                                      for i in range(64)]), (0x1234,)),
    ],
    'CountdownClampWalk': [
        # slot A at SCRATCH (index SCRATCH/4), slot B at SCRATCH+0x10.
        ('counter 5 -> 4',      {'g_xformEntityIdx': SCRATCH // 4,
                                 'g_currentNodeIdx': (SCRATCH + 0x10) // 4,
                                 '@0xb90000': 5, '@0xb90010': 0x1000}),
        ('counter 1 -> 0, ramp',{'g_xformEntityIdx': SCRATCH // 4,
                                 'g_currentNodeIdx': (SCRATCH + 0x10) // 4,
                                 '@0xb90000': 1, '@0xb90010': 0x1000}),
        ('counter 0 -> floor',  {'g_xformEntityIdx': SCRATCH // 4,
                                 'g_currentNodeIdx': (SCRATCH + 0x10) // 4,
                                 '@0xb90000': 0, '@0xb90010': 0x1000}),
        ('counter -3 -> floor', {'g_xformEntityIdx': SCRATCH // 4,
                                 'g_currentNodeIdx': (SCRATCH + 0x10) // 4,
                                 '@0xb90000': -3, '@0xb90010': 0x1000}),
        ('ramp hits the cap',   {'g_xformEntityIdx': SCRATCH // 4,
                                 'g_currentNodeIdx': (SCRATCH + 0x10) // 4,
                                 '@0xb90000': 0, '@0xb90010': 0xfff900}),
        ('ramp exactly at cap', {'g_xformEntityIdx': SCRATCH // 4,
                                 'g_currentNodeIdx': (SCRATCH + 0x10) // 4,
                                 '@0xb90000': 0, '@0xb90010': 0x10000 - 0xccc}),
    ],
    'NodeUnlink': [
        # Fake node at SCRATCH: +0xd8 prev, +0xe4 next.
        ('node IS the tail',    {'g_nodeListTail': SCRATCH,
                                 '@0xb900d8': 0x1111, '@0xb900e4': 0x2222},
                                (SCRATCH,)),
        ('found in slot 0',     {'g_nodeListTail': 0xdead0000,
                                 '@0x53e44c': SCRATCH,
                                 '@0xb900d8': 0x1111, '@0xb900e4': 0x2222},
                                (SCRATCH,)),
        ('found in slot 63',    {'g_nodeListTail': 0xdead0000,
                                 '@0x541d64': SCRATCH,
                                 '@0xb900d8': 0x1111, '@0xb900e4': 0x2222},
                                (SCRATCH,)),
        ('not found (bare ret)',{'g_nodeListTail': 0xdead0000,
                                 '@0xb900d8': 0x1111, '@0xb900e4': 0x2222},
                                (SCRATCH,)),
    ],
    # The at-rest heap is zeroed, so every entry's 24-bit stride is 0 and BOTH
    # sides spin until the instruction cap - an unseeded run "verifies" nothing.
    # HEAP lays out five 0x20-byte entries at g_memHeapStart with real strides:
    #   e0 tag 5, indirect slot null  -> frees the body at +0x0c
    #   e1 tag 5, indirect slot set   -> frees what the slot points at
    #   e2 tag 7                      -> tag mismatch when the arg is 5
    #   e3 tag 5 but 0xc0000000 set   -> skipped on the flag
    #   e4 flagged, stride 0x300000   -> lands past g_memHeapEnd, ending the walk
    'PackedListVisitor': [
        ('heap, match any',     dict(HEAP), (0xffffffff,)),
        ('heap, tag 5',         dict(HEAP), (5,)),
        ('heap, tag 7',         dict(HEAP), (7,)),
        ('heap, tag 0x3f miss', dict(HEAP), (0x3f,)),
    ],
    'Helper_TickFrame_Misc': [
        # The triplet table is fixed VAs, so the at-rest arena already walks all
        # 8 entries; these flip the source words so the AND-NOT has to produce
        # something other than what is already stored.
        ('at rest',             {}),
        ('sources all ones',    {'@0x543368': 0xffffffff, '@0x54336c': 0xffffffff,
                                 '@0x543370': 0xffffffff, '@0x54357c': 0xffffffff}),
        ('sources alternating', {'@0x543368': 0xaaaaaaaa, '@0x54336c': 0x55555555,
                                 '@0x543370': 0x0f0f0f0f, '@0x54357c': 0xf0f0f0f0}),
    ],
}


def seed(arena, gl_va, spec):
    for k, v in spec.items():
        va = int(k[1:], 16) if k.startswith('@') else gl_va[k]
        struct.pack_into('<I', arena, va - BASE, v & 0xffffffff)


def main():
    fn_va, gl_va = vt.load_maps()
    names = sys.argv[1:] or sorted(SEEDS)
    base = vc.ARENA.read_bytes()
    rc = 0
    for name in names:
        print(name)
        for case in SEEDS[name]:
            label, spec = case[0], case[1]
            args = case[2] if len(case) > 2 else None
            allow = case[3] if len(case) > 3 else set()
            arena = bytearray(base)
            seed(arena, gl_va, spec)
            res = vc.verify(name, fn_va, gl_va, fn_va, arena, argvals=args)
            if allow and res.startswith('MISMATCH'):
                m = re.match(r"MISMATCH orig_only=\[(.*?)\] twin_only=\[(.*?)\] "
                             r"vdiff=\[(.*?)\]", res)
                if m and not m.group(1) and not m.group(2):
                    diff = {int(a.strip().strip("'"), 16)
                            for a in m.group(3).split(',') if a.strip()}
                    if diff and diff <= allow:
                        res = 'VERIFIED (scratch ptr differs at %s - expected)' % (
                            ', '.join(hex(a) for a in sorted(diff)))
            print('  %-22s %s' % (label, res))
            if not res.startswith('VERIFIED'):
                rc = 1
    return rc


if __name__ == '__main__':
    sys.exit(main())
