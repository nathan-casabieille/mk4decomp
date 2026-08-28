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

# Per-twin integer WIDTHS, opt-in for the reason narrow_globals() explains: the
# widths in config/global_widths.yaml are right, but retyping a global also
# changes C promotion in expressions written for the 32-bit spelling, so it is
# applied where it is needed and verified rather than everywhere.
#
# Helper_DrawMenuText needs it: g_dispatchSave1613..1616 are four CONSECUTIVE
# BYTES, so as `unsigned int` each store is 32 bits and wipes the next fields -
# 1615 and the low half of 1618 vanish, and the cursor quad goes out wrong.
TYPES = {
    'Helper_DrawMenuText': {
        'g_dispatchSave1609': 'unsigned short', 'g_dispatchSave1610': 'unsigned short',
        'g_dispatchSave1611': 'unsigned short', 'g_dispatchSave1612': 'unsigned short',
        'g_dispatchSave1613': 'unsigned char',  'g_dispatchSave1614': 'unsigned char',
        'g_dispatchSave1615': 'unsigned char',  'g_dispatchSave1616': 'unsigned char',
        'g_dispatchSave1617': 'unsigned short', 'g_dispatchSave1618': 'unsigned short',
        'g_dispatchSave1619': 'unsigned short',
    },
    # BboxProjectAndStash reads the working 3x3 as SIGNED WORDS - every one is
    # a `movsx eax, word ptr [...]`. As `unsigned int` each read pulls a dword
    # spanning two neighbouring elements, and the projection lands thousands of
    # units off. g_dispatchSave1626 is a word for the same reason.
    'BboxProjectAndStash': {
        'g_mat3x3_007af992': 'short', 'g_mat3x3_007af994': 'short',
        'g_mat3x3_007af998': 'short', 'g_mat3x3_007af99a': 'short',
        'g_mat3x3_007af99e': 'short', 'g_mat3x3_007af9a0': 'short',
        'g_dispatchSave1626': 'short',
    },
    # The six record words at 0x00ab48b8..c2. The twin's own width macros are
    # DROPPED by the extractor (it keeps only the function body), so without
    # this the harness types them as dwords - and every case still passes
    # except the one where a carry or a cross-word read touches the high half,
    # which here was the abs-diff snap reading its neighbour into the compare.
    'GamepadSeqRecord': {
        'g_dispatchSave1534': 'short', 'g_dispatchSave1535': 'short',
        'g_dispatchSave1536': 'short', 'g_dispatchSave1537': 'short',
        'g_dispatchSave1538': 'short', 'g_dispatchSave1539': 'short',
    },
    # Same signed-word matrix as BboxProjectAndStash - `movsx` reads in the
    # original, and the file's own width defines are dropped by the extractor.
    'Mat3x3VecMul': {
        'g_mat3x3_007af990': 'short', 'g_mat3x3_007af992': 'short',
        'g_mat3x3_007af994': 'short', 'g_mat3x3_007af996': 'short',
        'g_mat3x3_007af998': 'short', 'g_mat3x3_007af99a': 'short',
        'g_mat3x3_007af99c': 'short', 'g_mat3x3_007af99e': 'short',
        'g_mat3x3_007af9a0': 'short',
    },
}

# Twins whose ORIGINAL carries packed internal entry points (continuations
# behind the same symbol). Their blobs must not be based at the function's own
# VA or they cover those offsets - see verify_coexec.verify(offsite=).
OFFSITE = {'Screen_Loading', 'Screen_Loading_Tick_004a42e0',
           'ChainSplit_SizeFits_00425ba0',
           'ChainCall_SecondEntry_00405960',
           'PvsMergeDriver', 'PvsMerge_MatchEnd_00425f90',
           'PvsMerge_MatchNode_00425fd0', 'MStackBracket2_TreeWalkRecursive', 'BillboardSheetDualEmit'}

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

# `mov eax, 0x8000 ; ret 4` - a __stdcall GetAsyncKeyState that reports every
# key HELD (bit 15 set), so Menu_PollNavInput returns a full bit set and the
# menu twins actually take their navigation branches. Without it every key
# reads as up, the poll returns 0, and the interesting paths never run.
KEY_STUB_VA = 0x00b94000
KEY_DOWN = {'@0x%x' % KEY_STUB_VA: b'\xb8\x00\x80\x00\x00\xc2\x04\x00',
            'g_iat_GetAsyncKeyState': KEY_STUB_VA}

# A four-entry menu table at MENU_VA. Each entry is 8 bytes: [+0] non-zero
# means present, [+4] is a s16 that is 1 for a selectable row.
#   0 present+selectable, 1 present+selectable, 2 present+NOT selectable,
#   3 absent (end of table)
MENU_VA = 0x00b95000
MENU = {'@0x%x' % (MENU_VA + 0): 1, '@0x%x' % (MENU_VA + 4): 1,
        '@0x%x' % (MENU_VA + 8): 1, '@0x%x' % (MENU_VA + 12): 1,
        '@0x%x' % (MENU_VA + 16): 1, '@0x%x' % (MENU_VA + 20): 0,
        '@0x%x' % (MENU_VA + 24): 0, '@0x%x' % (MENU_VA + 28): 0}

# Menu_PollNavInput reaches the keyboard and the joysticks through Win32 IAT
# slots the verifier has no implementation for, so unseeded it just runs to the
# instruction cap. Overwriting the two readers' own entry bytes with
# `mov eax, IMM ; ret` makes them deterministic - and since the bytes are
# patched in the arena BOTH runs share, the comparison stays honest.
def _readers(key, joy):
    def imm_ret(v):
        return b'\xb8' + (v & 0xffffffff).to_bytes(4, 'little') + b'\xc3'
    return {'@0x4b5450': imm_ret(key),        # Input_GetAsyncKey
            '@0x4b5380': imm_ret(joy)}        # Input_PollJoystick

# A 3x3 matrix in a scratch node: four dwords plus a trailing halfword.
MAT = {'@0xb90000': 0x11112222, '@0xb90004': 0x33334444,
       '@0xb90008': 0x55556666, '@0xb9000c': 0x77778888,
       '@0xb90010': 0x9999}

RET_STUB = 0x0041f2e0                    # AllocateNode's `ret`
DISPATCH = dict([('g_dispatchVar20', 0xb92000 // 4)] +
                [('@0x%x' % (0xb92000 + i * 4), RET_STUB) for i in range(4)])


# The engine's real 3x3, at 0x007af990 - what the projection helpers read.
MAT3 = {'@0x7af990': 0x00100010, '@0x7af994': 0xfff00010,
        '@0x7af998': 0x0010fff0, '@0x7af99c': 0x00100010,
        '@0x7af9a0': 0x0010}

# The vtable at 0x004f7868 the dispatch indexes: 32 slots, every one a `ret`.
VTBL = dict([('@0x%x' % (0x4f7868 + i * 4), RET_STUB) for i in range(32)])


# The texture page base lives in a 32-bit slot at 0x00f85b34; point it at a
# scratch region so an upload writes somewhere both runs share.
TEXPAGE = {'@0xf85b34': 0x00ba0000, 'g_texturedTriVar': 0}


# Three blocks from g_memHeapStart to g_memHeapEnd: free 0x40, used 0x40, then
# one free block running to the end of the heap. Mem_Malloc walks to HEAP_HI,
# so the sizes have to tile the whole region or the walk runs off.
def _heap3():
    LO, HI = 0x7b41a0, 0xab4194
    d = {}
    d['@0x%x' % LO]         = 0x80000040
    d['@0x%x' % (LO + 4)]   = 0
    d['@0x%x' % (LO + 8)]   = LO
    d['@0x%x' % (LO + 0x40)]     = 0x00000040
    d['@0x%x' % (LO + 0x44)]     = 0
    d['@0x%x' % (LO + 0x48)]     = LO
    d['@0x%x' % (LO + 0x80)]     = 0x80000000 | (HI - (LO + 0x80))
    d['@0x%x' % (LO + 0x84)]     = 0
    d['@0x%x' % (LO + 0x88)]     = LO + 0x40
    d['@0xb90200'] = 0
    return d


# A sixteen-entry FILESYS directory at 0x007ab0e0: {key, offset, size}, keys
# ascending by 0x100. `want` picks which key the lookup is given, seeded as the
# already-hashed value at the path FSYS_fopen will be handed - the hash runs on
# a path that normalizes to the same string in both runs either way.
def _fsysdir(want=8):
    # Helper_FSeek / Helper_FRead are MSVC CRT stdio; executed as original
    # bytes they try to do real I/O and run to the instruction cap. Patch their
    # entry points to `mov eax, IMM ; ret` - cdecl, so the caller cleans up -
    # in the arena BOTH runs share, which keeps the comparison honest.
    def imm_ret(v):
        return b'\xb8' + (v & 0xffffffff).to_bytes(4, 'little') + b'\xc3'
    d = {'@0x7af4e4': 16, '@0x7af4e0': 1, '@0x4f4a50': 0,
         '@0x4c5a90': imm_ret(0),      # Helper_FSeek
         '@0x4c5b70': imm_ret(4),      # Helper_FRead -> 4 items
         '@0x4c5580': imm_ret(0)}      # Helper_Sprintf
    # The path FSYS_fopen is handed normalizes to "C:\\A", whose FSYS_HashName
    # is 0x415c3a47. `want` says which SLOT carries it, so the same lookup can
    # be driven to the first, middle and last entry - the interesting thing is
    # the bisection's path, not the key.
    KEY = 0x415c3a47
    for i in range(16):
        b = 0x7ab0e0 + i * 12
        d['@0x%x' % b]       = (KEY - (want - i) * 0x10) & 0xffffffff
        d['@0x%x' % (b + 4)] = 0x1000 + i * 0x800     # archive offset
        d['@0x%x' % (b + 8)] = 0x400                  # entry size
        d['@0x%x' % (0x7ae0e0 + i * 4)] = 0
    # "C:\A" - short, so the hash is cheap and deterministic
    d['@0xb91000'] = 0x415c3a43
    d['@0xb91004'] = 0
    d['@0xb92000'] = 0
    return d


# A .geo texture block for LoadGeoAsset_Textures. The node is at packed index
# 0x2e4000 (VA 0xb90000): +0 is the name table, +4 the cached block. The
# loaded file lands at 0xb95000 - its +4 is the offset to the texture chunk,
# then a count and two entries of {w, h, words, data...}.
def _geoblk():
    def imm_ret(v):
        return b'\xb8' + (v & 0xffffffff).to_bytes(4, 'little') + b'\xc3'
    d = {
        'g_currentNodeIdx': 0x2e4000,
        '@0xb90000': 0xb90100,          # name table
        '@0xb90004': 0,                 # not loaded yet
        '@0xb90100': 0xb90800,          # entry[0].name
        '@0xb90106': 0x00000002,        # entry[0] +6: the slot key (u16 = 2)
        '@0xb90800': 0x004f4f46,        # "FOO"
        '@0xb95004': 0x10,              # offset from +4 to the chunk
        '@0xb95014': 0x00000002,        # count = 2
        '@0xb95018': 0x00040004,        # tex0: w=4 h=4
        '@0xb9501c': 0x00000004,        # tex0: words
        '@0xb95020': 0x001f001f,
        '@0xb95024': 0x001f001f,
        '@0xb95028': 0x00020002,        # tex1: w=2 h=2
        '@0xb9502c': 0x00000002,        # tex1: words
        '@0xb95030': 0x7c1f7c1f,
        '@0xab4e74': 0,                 # slot cursor
        '@0xf85b34': 0x00ba0000,        # texture page base
        'g_texturedTriVar': 0,
        'g_texXorKey': 0,
        # FSYS_fsize -> 0x100, FSYS_fload -> nothing, Mem_Malloc -> 0xb95000
        '@0x4b2120': imm_ret(0x100),
        '@0x4b2160': b'\xc3',
        '@0x4b5bc0': (b'\x8b\x4c\x24\x04'          # mov ecx, [esp+4]
                      b'\xb8\x00\x50\xb9\x00'      # mov eax, 0xb95000
                      b'\x89\x01'                    # mov [ecx], eax
                      b'\xc3'),                       # ret
        '@0x4c5580': imm_ret(0),        # Helper_Sprintf
        '@0x4bd570': b'\xc3',           # Helper_GeoLoadPre
        '@0x4bd6d0': b'\xc3',           # Helper_GeoLoadPost
    }
    for i in range(16):
        d.setdefault('@0x%x' % (0xab4e00 + i * 2), 0)
    return d


# VibrationFrameUpdate's FPU state: the running scale at 0x004f6570, its signed
# increment at 0x004f6578, and the two bounds at 0x004d2a00 / 0x004d2a10 - all
# doubles, seeded as their exact bit patterns.
def _vib(k=1.0, step=0.01):
    import struct

    def halves(x):
        return struct.unpack('<II', struct.pack('<d', x))

    d = {'g_cj_0054205c': 0x180000, 'g_dualC': 0x2e4040,
         'g_xformDirtyFlags': 0, 'g_walkCallback': 0x40,
         '@0x4f6510': 0x40, '@0x4f6514': 0x40, '@0x4f6518': 0x40,
         '@0x4f651c': 0x40, '@0x4f6520': 0x40}
    for va, x in ((0x4f6570, k), (0x4f6578, step),
                  (0x4d2a00, 0.9), (0x4d2a10, 1.1)):
        lo, hi = halves(x)
        d['@0x%x' % va] = lo
        d['@0x%x' % (va + 4)] = hi
    # the 3x3 Transform9Words scales, at the pending node
    for i in range(5):
        d['@0x%x' % (0xb90100 + i * 4)] = 0x00100010
    return d


# VertexQuadBuilder's input: g_xformEntityIdx is a RAW VA (0xb90100), its +4 is
# the block base, and entry `index` sits at base + index*0x10 + 0xc with the
# vertex count as the u16 at +2. Two vertices, each 8 source bytes.
def _vqb():
    # _heap3, not _blocks: Mem_Malloc walks from g_memHeapStart all the way to
    # g_memHeapEnd, so the seeded blocks have to tile the WHOLE region or the
    # allocation fails and the function takes its error path - which shows up
    # as a suspiciously empty "VERIFIED (0 writes)".
    d = dict(_heap3())
    d.update({
        'g_xformEntityIdx': 0xb90100,
        'g_currentNodeIdx': 0x2e4000,
        'g_fightGroupHead': 0x00080000,     # (>> 16) & 8 -> 8
        'g_dispatchSave1572': 1,
        'g_pendingNodeType': 0,
        '@0xb90048': 0,                      # the node's cache slot
        '@0xb90104': 0xb90200,               # block base
        # entry 0 is at base + 0*0x10 + 0xc = 0xb9020c
        '@0xb9020e': 2,                      # entry +2: vertex count
        '@0xb90218': 0x20,                   # entry +0xc: offset to the stream
        '@0xb90204': 0x40,                   # base +4: offset to the shade table
        # the source stream at entry + 0xc + 0x20 = 0xb90238, two 8-byte records
        '@0xb90238': 0x11110001, '@0xb9023c': 0x33332222,
        '@0xb90240': 0x44440002, '@0xb90244': 0x66665555,
        # the shade table
        '@0xb90248': 0x0f0f0f0f, '@0xb9024c': 0x0f0f0f0f,
        '@0x4bd510': b'\xc3',               # LeaScaledCall: cdecl, plain ret
    })
    return d


# BboxProjectAndStash reads a bbox out of the table at 0x004f63e8 (0x10-byte
# entries, indexed by g_walkCallback), projects it through the 3x3 at
# 0x007af990, and stashes the result into the packed s16 triples at 0x00ab44f8.
def _bbox():
    d = {
        # the index is LOADED from the node's +0x1c, not read from a global -
        # seeding g_walkCallback does nothing, the function overwrites it
        '@0xb9001c': 1,
        'g_tickCurConfig': 0xb96000,
        '@0xb96000': 1,                       # *g_tickCurConfig == 1
        'g_dispatchSave1580': 0,
        'g_tickX2': 0,
        'g_dispatchSave1559': 0,
        'g_vtxTransX': 0x10, 'g_vtxTransY': 0x20, 'g_vtxTransZ': 0x30,
        'g_pointPosX': 0x400, 'g_pointPosY': 0x500, 'g_pointPosZ': 0x600,
        'g_eventQueuePending': 0x2e4000,
        '@0xb90000': 0x40, '@0xb90004': 0x50, '@0xb90008': 0x60,
        # the bbox entry for index 1: base + 0x10
        '@0x4f63f8': 0,                       # the byte gate, clear
        '@0x4f63fa': 0x00200010,              # +2 / +4 of the entry
        '@0x4f63fe': 0x00400030,
        # the working 3x3
        '@0x7af990': 0x00100010, '@0x7af994': 0xfff00010,
        '@0x7af998': 0x0010fff0, '@0x7af99c': 0x00100010,
        '@0x7af9a0': 0x0010,
    }
    return d


# MovesPanelEmit: g_eventQueueTotal's node holds the panel index at +0x18, and
# the panel must be one of the four sentinel records - 0x004ed000 here, so the
# vertex fields are the dwords at 0x4ed004/0c/14/1c.
def _panel():
    return {
        # the PANEL is one of the four sentinel records - g_eventQueueTotal*4
        # must be 0x4ed000 - and its +0x18 names the NODE the vertices and the
        # colour test read.
        'g_eventQueueTotal': 0x4ed000 // 4,
        '@0x4ed018': 0x2e4000,
        'g_inLoopStep': 0,
        'g_tickW1': 0x20,
        '@0xab4e20': 0x1234,                  # g_tickCurMask (word)
        '@0xb90000': 0xa000,                  # picks the 0x0a colour
        '@0xb90004': 0x11002200, '@0xb9000c': 0x33004400,
        '@0xb90014': 0x55006600, '@0xb9001c': 0x77008800,
        # the working 3x3 + translate, for ProjectTwoVertices
        '@0x7af990': 0x00100010, '@0x7af994': 0xfff00010,
        '@0x7af998': 0x0010fff0, '@0x7af99c': 0x00100010,
        '@0x7af9a0': 0x0010,
        'g_vtxTransX': 0, 'g_vtxTransY': 0, 'g_vtxTransZ': 0x280,
        '@0x4bcc70': b'\xc3',                 # GamepadSeqRecord
        '@0x4bd270': b'\xc3',                 # SunbeamSpriteEmit
        '@0x4c3360': b'\xc3',                 # Helper_DrawCursor
    }


# BillboardChainRender: the node's +0x2c heads a chain (one link at 0x2e4040);
# the link's +0xc names a block whose +4 is the entity VA, and the entity's +4
# is the mesh base carrying the texture records.
def _bbc():
    return {
        'g_currentNodeIdx': 0x2e4000,
        'g_inLoopStep': 0,
        '@0xb9002c': 0x2e4040,               # chain head
        '@0xb90100': 0,                       # link: next = end
        '@0xb9010c': 0x2e4080,               # link +0xc: block
        '@0xb90104': 0x11,                    # link +4: centre x (>>7)
        '@0xb90108': 0x22,                    # link +8: centre y
        '@0xb90204': 0xb93000,               # block +4: entity VA
        '@0xb90218': 1,                       # block +0x18: record index
        '@0xb93004': 0xb94000,               # entity +4: mesh base
        '@0xb94004': 0x30,                    # base +4: texture table offset
        # record 1 at base + 0x10 + 0xc = 0xb9401c
        '@0xb9401c': 0x02020104, '@0xb94020': 0x00300020,
        '@0xb94024': 0x00500040, '@0xb94028': 0x0a0a0505,
        # the two-bit table the flags sample
        '@0x4f6238': 0x03020100,
        # texture table entry: tbl + texrec*4 + base + 0xa
        '@0xb94042': 0x0f0f0f0f,
        # projection inputs
        '@0xab4398': 0x00100000, '@0xab439c': 0x00200000,
        '@0xab43a0': 0x00014000,              # g_dispatchSave1503 (z)
        '@0xab4e60': 0x20,                    # g_dispatchSave1576
        '@0x7af990': 0x00100010, '@0x7af994': 0xfff00010,
        '@0x7af998': 0x0010fff0, '@0x7af99c': 0x00100010,
        '@0x7af9a0': 0x0010,
        'g_drawQueueSize': 0,
    }


# CameraSetupAndCullFan: g_currentNodeIdx's +0x15 block is the camera position,
# g_xformEntityIdx's +0x15 block the target, and the entity's +0x3c the raw
# FOV. The wt 3x3 snapshot at 0x00ab4d58 feeds the rotation.
def _cam():
    return {
        'g_currentNodeIdx': 0x2e4000,
        'g_xformEntityIdx': 0x2e4040,
        'g_pendingNodeType': 0x99,
        'g_tickX3': 0x40, 'g_tickW1': 0x20,
        '@0xb9013c': 0x8000,                 # entity +0x3c: fov -> 0x80
        # camera block: node +0x15 packed = VA 0xb90000 + 0x54
        '@0xb90054': 0x00100000, '@0xb90058': 0x00200000, '@0xb9005c': 0x00300000,
        # target block: entity +0x15 = VA 0xb90100 + 0x54
        '@0xb90154': 0x00400000, '@0xb90158': 0x00600000, '@0xb9015c': 0x00900000,
        # the wt 3x3 snapshot (dwords + word)
        '@0xab4d58': 0x00100010, '@0xab4d5c': 0xfff00010,
        '@0xab4d60': 0x0010fff0, '@0xab4d64': 0x00100010,
        '@0xab4d68': 0x0010,
        'g_pointPosX': 0x00500000, 'g_pointPosY': 0x00700000,
        'g_pointPosZ': 0x00200000,
        'g_pointColorR': 0x9000, 'g_pointColorG': 0x7000, 'g_pointColorB': 0xc000,
        'g_fightGroupHead': 0, 'g_tickFlagZ': 0,
        'g_dispatchSave1574': 0xffffffff,
        '@0x4b9840': b'\xc3',                # AltCamMatrixProject stub
    }


# SunbeamSpriteEmit: entity 2's corner table entry lives at 0x004f6398 + 16
# (ENTITY MINUS ONE, 16 bytes per entry) - four s16 pairs.
def _beam():
    return {
        'g_xformEntityIdx': 2,
        'g_inLoopStep': 0,
        'g_tickW1': 0x20,
        '@0x4f6580': 0x80, '@0xab51fc': 8,
        '@0x4f63a8': 0x00200010, '@0x4f63ac': 0xffe00040,
        '@0x4f63b0': 0x00300050, '@0x4f63b4': 0x00100060,
        '@0xab4398': 0x00100000, '@0xab439c': 0x00200000,
        '@0xab43a0': 0x00014000,
        '@0x7af990': 0x00100010, '@0x7af994': 0xfff00010,
        '@0x7af998': 0x0010fff0, '@0x7af99c': 0x00100010,
        '@0x7af9a0': 0x0010,
        'g_drawQueueSize': 0,
    }


# GamepadSeqRecord: the six record words seeded distinct, and the renderer
# mode picked per case (Renderer_GetMode runs live and reads 0x004f4b3c).
def _gsr(mode):
    return {
        '@0x4f4b3c': mode,
        '@0xab48b8': 100, '@0xab48ba': 200, '@0xab48bc': 300,
        '@0xab48be': 400, '@0xab48c0': 500, '@0xab48c2': 600,
    }


# MStackBracket5_LinkedListUnlink: the node lives at g_currentNodeIdx + xe
# (0x2e4000 + 0x40); its +4 names prev, +8 the back link, +0 the forward link,
# both RELATIVE (neighbour = link + xe).
def _unlink(back, fwd):
    d = {
        'g_currentNodeIdx': 0x2e4000, 'g_xformEntityIdx': 0x40,
        'g_matrixStackTop': 0x2e5000,
        'g_chainInsertSlot': 0x11, 'g_eventQueueCurrent': 0x22,
        'g_pendingNodeType': 0x33, 'g_eventQueueTotal': 0x44,
        'g_eventQueueEnd': 0x55,
        '@0xb90100': fwd,                    # node[0]: forward link
        '@0xb90104': 0x2e4200,               # node[+4]: prev
        '@0xb90108': back,                   # node[+8]: back link
        '@0xb9080c': 7,                      # prev[+0xc]: element count
    }
    if back:
        d['@0x%x' % ((back + 0x40) * 4)] = 0x9999
    if fwd:
        d['@0x%x' % ((fwd + 0x40) * 4 + 0x20)] = 0x8888
    return d


# PvsMergeDriver: the node being freed sits at cur (idx 0x2e4044, so cur-4 =
# 0x2e4040 is what the unlink sees), its list fields seeded as a sole element;
# the PVS head at 0x00541e74 names a one-node sibling walk for Helper_TickAlt
# (head node at 0x2e6000, its f0 -> the region node 0x2e4100, stride 0).
def _pvs():
    return {
        'g_currentNodeIdx': 0x2e4044, 'g_xformEntityIdx': 0x99,
        'g_pendingNodeType': 0x88, 'g_matrixStackTop': 0x2e5000,
        'g_framePauseFlag': 0, 'g_xformDirtyFlags': 0,
        'g_vertexInitFlag': 0x2e6000,
        # the freed node (at cur - 4 + xe(0) = 0x2e4040): sole element
        '@0xb90100': 0, '@0xb90104': 0x2e4200, '@0xb90108': 0,
        '@0xb9010c': 0x10,                    # its count
        '@0xb9080c': 5,                       # prev's element count
        # the walk: head node f0 -> region node, stride f8 = 0
        '@0xb98000': 0x2e4100, '@0xb98008': 0,
        # the region node the walk visits: count so END = 0x2e4100+0x18+4
        '@0xb9040c': 0x18,
        '@0xb90400': 0, '@0xb90404': 0x2e4200, '@0xb90408': 0,
    }


# MStackBracket2_TreeWalkRecursive: a parent node at 0x2e4000 whose +0x14 is
# clear (no unlink for itself); children hang off node[0] and remove
# THEMSELVES via the offset-4 unlink, whose prev field points back at the
# parent's head slot. The boot list head and the DirtyPushCallPop state head
# are small scratch nodes.
def _tree():
    return {
        'g_currentNodeIdx': 0x2e4000, 'g_xformEntityIdx': 0x11,
        'g_pendingNodeType': 0x22, 'g_matrixStackTop': 0x2e5000,
        'g_xformDirtyFlags': 0, 'g_framePauseFlag': 0,
        'g_fightGroupHead': 0,
        'g_bootChainSlot2': 0x2e4800, 'g_bootChainState4': 0x2e4900,
        # parent: no children, +0x14/+0x18/+0x1c/+0x28/+0x2c all clear
        '@0xb90000': 0, '@0xb90014': 0, '@0xb90018': 0, '@0xb9001c': 0,
        '@0xb90028': 0, '@0xb9002c': 0,
        # child at 0x2e4040 (used by the one-child case): +0x14 = parent, so
        # its unlink patches parent[0]; leaf otherwise
        '@0xb90100': 0, '@0xb90128': 0, '@0xb9012c': 0, '@0xb9011c': 0,
        # boot list head fields the insert reads
        '@0xb92000': 0, '@0xb92004': 0, '@0xb92008': 0, '@0xb9200c': 0,
        '@0xb92400': 0, '@0xb92404': 0, '@0xb92408': 0,
        '@0x4bd510': b'\xc3',               # LeaScaledCall
    }


# BillboardSheetDualEmit: the sheet record at VA 0xb90210 (u8 fields at +1/+2,
# extents at +4/+6, corner at +8/+a, colours at +c..f); the entity VA in
# g_xformEntityIdx leads to the mesh base and its texture table; one chain
# node hangs off the current node's +0x2c; the 3x3 at 0x2e4100*4 = 0xb90400.
def _sheet():
    return {
        'g_inLoopStep': 0,
        'g_currentNodeIdx': 0x2e4000,
        'g_xformEntityIdx': 0xb93000,
        'g_currentNodeFlags': 0,
        'g_fightGroupHead': 0,
        'g_dispatchSave1576': 0x20,
        'g_dispatchSave1559': 1,
        '@0xab4e20': 0,                      # g_tickCurMask: 0 -> MaxOfThree
        '@0xab4398': 0x00100000, '@0xab439c': 0x00200000,
        '@0xab43a0': 0x00014000,
        # sheet record
        '@0xb90210': 0x00020100, '@0xb90214': 0x00300020,
        '@0xb90218': 0x00500040, '@0xb9021c': 0x30201008,
        # entity -> mesh base -> texture table
        '@0xb93004': 0xb94000, '@0xb94004': 0x30,
        '@0xb94040': 0x0f0f0f0f, '@0xb94044': 0x0f0f0f0f,
        '@0x4f6238': 0x03020100,
        # the working 3x3 for the projections
        '@0x7af990': 0x00100010, '@0x7af994': 0xfff00010,
        '@0x7af998': 0x0010fff0, '@0x7af99c': 0x00100010,
        '@0x7af9a0': 0x0010,
        # chain: node +0x2c -> one member, whose own next is 0
        '@0xb9002c': 0x2e4200, '@0xb90800': 0,
        '@0xb90804': 0x00001000, '@0xb90808': 0x00002000,
        '@0xb9080c': 0x00003000,
        # the rotation 3x3 at mat*4
        '@0xb90400': 0x00001000, '@0xb90404': 0x00000000,
        '@0xb90408': 0x10000000, '@0xb9040c': 0x00000010,
        '@0xb90410': 0x1000,
        'g_drawQueueSize': 0,
    }


# Helper_TickReinit: two vec3 rows in the camera table, the wt snapshot and
# its alternate both seeded, the BAM angles non-zero, the seed node's +0x58
# carrying `half` in bits 8..23.
def _reinit():
    return {
        'g_inLoopStep': 0, 'g_tickX2': 2,
        'g_eventQueueSeed': 0x2e4000,
        '@0xb90058': 0x00340000,             # half = 0x34
        '@0xab44f8': 0x00200100, '@0xab44fc': 0x01400030,
        '@0xab4500': 0x00600180, '@0xab4504': 0x00000050,
        # wt snapshot at 0xab4d58 and the alternate at 0xab4878
        '@0xab4d58': 0x00100010, '@0xab4d5c': 0xfff00010,
        '@0xab4d60': 0x0010fff0, '@0xab4d64': 0x00100010,
        '@0xab4d68': 0x0010,
        '@0xab4878': 0x00100010, '@0xab487c': 0xfff00010,
        '@0xab4880': 0x0010fff0, '@0xab4884': 0x00100010,
        '@0xab4888': 0x0010,
        '@0xab47f8': 0x0800,                 # camRotXBam
        '@0xab47fc': 0xf800,                 # camRotZBam (negative word)
        'g_drawQueueSize': 0,
    }


# TaggedSceneDispatch: every callee stubbed - the reset trio and iterator to
# plain rets, TableSearch to "miss" (eax=0), the two audio calls to
# ret-with-value so the s8 store is observable.
def _tsd():
    def imm_ret(v):
        return b'\xb8' + (v & 0xffffffff).to_bytes(4, 'little') + b'\xc3'
    return {
        'g_texXorKey': 0,
        '@0x4be610': b'\xc3',                # CallZero2
        '@0x4be630': b'\xc3',                # SixDoublePushCall
        '@0x4be590': b'\xc3',                # TwinRecordIter
        '@0x4be760': imm_ret(0),             # TableSearch: miss
        '@0x4ac650': b'\xc3',                # Audio_TimerSet
        '@0x4c3960': imm_ret(0xa5),          # Audio_PlaySoundId -> s8 0xa5
        '@0x4f7d84': 0x1234,                 # table entry for hit=3
    }


# AudioVolumeRescale: DualAddSar left live - seed whatever it reads to a
# stable pair so both runs see the same comparison base.
def _avr():
    return {'g_xformDirtyFlags': 0, 'g_framePauseFlag': 0,
            'g_bootInitSaveSlot': 0, '@0x53814c': 0}


# BootDispatchSlotInit: the dispatcher and the three walk callees stubbed -
# default all `and ~4 / ret`-shaped success (clear bit 2), overridden per case
# with `or 4` (not-found) or a pause store. The node and its +0x18 list are
# scratch.
def _bdsi():
    clear4 = b'\x83\x25' + (0x54208c).to_bytes(4, 'little') + b'\xfb\xc3'
    return {
        'g_matrixStackTop': 0x2e5000, 'g_xformEntityIdx': 0x11,
        'g_pendingNodeType': 0x22, 'g_walkCallback': 0x2e4100,
        'g_framePauseFlag': 0, 'g_xformDirtyFlags': 0,
        'g_currentNodeIdx': 0x2e4000, 'g_fightGroupHead': 0,
        '@0xb90018': 0x2e4040, '@0xb90020': 0,
        '@0x407400': clear4,             # DispatcherComplex260
        '@0x408600': clear4,             # MStackBracket4_ListInsertZeroFill
        '@0x4088b0': clear4,             # MStackPush3LinkedListWalk
        '@0x408d30': clear4,             # BootStateTriple
        '@0x406790': b'\xc3',            # MStackPush2ChainLLInsert
        '@0x409260': b'\xc3',            # ScaledStoreThree
    }


# BootPhaseGateBracketedInit: the chain-step callee stubbed to success (clear
# bit 2) and leaving cur at a scratch node the fills can write.
def _bpg():
    clear4 = (b'\x83\x25' + (0x54208c).to_bytes(4, 'little') + b'\xfb'
              b'\xc7\x05' + (0x542044).to_bytes(4, 'little')
              + (0x2e4000).to_bytes(4, 'little') + b'\xc3')
    return {
        'g_matrixStackTop': 0x2e5000, 'g_xformLoopCounter': 0x77,
        'g_bootChainPair0': 0x2e4800, 'g_framePauseFlag': 0,
        'g_xformDirtyFlags': 0, 'g_baseSel': 0x99,
        '@0x4ab510': clear4,
    }

# FramePauseScaledStore: the field-clear advance stubbed to success; the
# entity's first word carries the value the split decomposes.
def _b5():
    # bracket5: five saved globals with recognizable values; the chain step's
    # own seeds (slot2 -> head 0x2e4040 whose +4 link is 0, i.e. its own
    # successor); the walk stubbed to a plain ret.
    return {
        'g_xformLoopCounter': 0x111, 'g_xformEntityIdx': 0x222,
        'g_pendingNodeType': 0x333, 'g_eventQueueTotal': 0x444,
        'g_eventQueueEnd': 0x555, 'g_matrixStackTop': 0x2e5000,
        'g_framePauseFlag': 0, 'g_xformDirtyFlags': 0,
        'g_bootChainSlot2': 0x2e4000,
        '@0xb90000': 0x2e4040, '@0xb90004': 0, '@0xb90100': 0x777,
        '@0x409740': b'\xc3',
    }

# bracket1 (the recursive tree builder): entity record at 0x2e4000 whose
# first child record overlaps at +7 words. The alloc (bracket5) is stubbed
# with a COUNTING stub - each call decrements the word at 0xb98000 and fails
# (bit 2 set, null node) when it reaches zero, else succeeds handing out
# node 0x2e4100. Prepend and the 405e20 insert are plain-ret stubs.
_B5CNT = (b'\xff\x0d\x00\x80\xb9\x00'                      # dec dword [0xb98000]
          b'\x74\x12'                                        # jz FAIL
          b'\x83\x25\x8c\x20\x54\x00\xfb'                  # and dirty, ~4
          b'\xc7\x05\x44\x20\x54\x00\x00\x41\x2e\x00'     # cur = 0x2e4100
          b'\xc3'
          b'\x83\x0d\x8c\x20\x54\x00\x04'                  # FAIL: or dirty, 4
          b'\xc7\x05\x44\x20\x54\x00\x00\x00\x00\x00'     # cur = 0
          b'\xc3')

def _b1(alloc_budget, w0, childw0):
    return {
        'g_pendingNodeType': 0x333, 'g_xformEntityIdx': 0x2e4000,
        'g_matrixStackTop': 0x2e5000, 'g_framePauseFlag': 0,
        'g_xformDirtyFlags': 0, 'g_xformScratch94': 0, 'g_walkCallback': 0,
        'g_currentNodeIdx': 0x11111,
        '@0xb98000': alloc_budget,
        '@0xb90000': w0, '@0xb9000c': 0x11, '@0xb90010': 0x22,
        '@0xb90014': 0x33, '@0xb9001c': childw0,
        '@0x405630': _B5CNT,
        '@0x409970': b'\xc3', '@0x405e20': b'\xc3',
    }

def _b4():
    # bracket4 full-path defaults: node 0x2e4000 with no prior list, +0x18
    # record at 0x2e4200; set1c reports 3 elements; the insert hands out
    # block 0x2e4100 (its four words pre-dirtied to prove the zero-fill).
    return {
        'g_xformLoopCounter': 0x111, 'g_currentNodeIdx': 0x2e4000,
        'g_xformEntityIdx': 0x222, 'g_pendingNodeType': 0x333,
        'g_matrixStackTop': 0x2e5000, 'g_framePauseFlag': 0,
        'g_xformDirtyFlags': 0, 'g_walkCallback': 0,
        'g_eventQueueCurrent_mm': 0x99,
        '@0xb9001c': 0, '@0xb90018': 0x2e4200,
        '@0xb90400': 0xdead, '@0xb90404': 0xdead,
        '@0xb90408': 0xdead, '@0xb9040c': 0xdead,
        '@0x4084b0': b'\xc7\x05\x70\x20\x54\x00\x03\x00\x00\x00\xc3',
        '@0x425db0': b'\xc3',
        '@0x425be0': b'\x83\x25\x8c\x20\x54\x00\xfb'
                     b'\xc7\x05\x44\x20\x54\x00\x00\x41\x2e\x00\xc3',
        '@0x408580': b'\xc3',
    }

# the match loader and the loading-screen tick: every callee stubbed at its
# VA. RET1/RET0 for the input gate; DCOK hands out node 0x2e4100 with the
# dirty bit cleared; QREC records QuadCallPhase2's four args at 0xb98000.
_RET   = b'\xc3'
_RET1  = b'\xb8\x01\x00\x00\x00\xc3'
_RET0  = b'\x31\xc0\xc3'
_PAUSE = b'\xc7\x05\x6c\x1e\x54\x00\x01\x00\x00\x00\xc3'
_DCOK  = (b'\x83\x25\x8c\x20\x54\x00\xfb'
          b'\xc7\x05\x44\x20\x54\x00\x00\x41\x2e\x00\xc3')
_QREC  = (b'\x8b\x44\x24\x04\xa3\x00\x80\xb9\x00'
          b'\x8b\x44\x24\x08\xa3\x04\x80\xb9\x00'
          b'\x8b\x44\x24\x0c\xa3\x08\x80\xb9\x00'
          b'\x8b\x44\x24\x10\xa3\x0c\x80\xb9\x00\xc3')

def _lgsm(st):
    # node 0x2e4000 is the scheduled node; +0x84 at 0xb90210, +8 at 0xb90020.
    return {
        'g_baseSel': 0x2e4000, '@0xb90084': st, 'g_framePauseFlag': 0,
        'g_pendingNodeType': 0, 'g_xformDirtyFlags': 0, 'g_walkCallback': 0,
        'g_currentNodeIdx': 0x11111, 'g_xformEntityIdx': 0,
        'g_tickW1': 0, 'g_tickFlagF': 0, 'g_tickInitFlag': 0,
        'g_dlNalt1': 2, 'g_dlNalt2': 3,
        'g_dualB_00538038': 0x2e6000, 'g_dualB_0053803c': 0x2e7000,
        'g_cj_00542054': 0x2e6000, 'g_cj_00542058': 0x777, 'g_cj_0054205c': 0x888,
        'g_eventQueueCurrent': 0, 'g_audioStateDisp50b4': 0, 'g_gameMode': 0x11,
        '@0x4d52c0': 0xb90000, '@0x4d52c4': 0,
        '@0x4f33c0': 0xb94000, '@0x4f33c4': 0,
        '@0x4bd890': _RET, '@0x4bd5b0': _RET, '@0x4a1bf0': _RET0,
        '@0x4a1ad0': _RET, '@0x464800': _RET, '@0x406790': _RET,
        '@0x407400': _DCOK, '@0x4064b0': _RET, '@0x41f780': _RET,
    }

def _slt(st):
    return {
        'g_baseSel': 0x2e4000, '@0xb90084': st, '@0xb90004': 0x2e4800,
        'g_framePauseFlag': 0, 'g_pendingNodeType': 0, 'g_walkCallback': 0,
        'g_currentNodeIdx': 0x11111, 'g_gameMode': 0x11,
        'g_gsmOut1': 0, 'g_gsmOut2': 0, 'g_gsmOut3': 0, 'g_gsmOut4': 0,
        'g_gsmActiveFlag': 0, 'g_logicStepFlag': 0, 'g_audioStreamState': 0,
        'g_audioStateMask50c0': 0, 'g_active_0053a408': 0, 'g_active_00537e88': 0,
        'g_audioInitScaled': 0, 'g_counter_0053a51c': 0x40,
        'g_dualB_00538038': 0x2e6000, 'g_dualB_0053803c': 0x2e7000,
        'g_dlNalt1': 2, 'g_dlNalt2': 3,
        '@0x54380c': 0, '@0x54389c': 0, '@0x543824': 0,
        '@0xb98000': 0, '@0xb98004': 0, '@0xb98008': 0, '@0xb9800c': 0,
        '@0xb98010': 0x11223344, '@0xb9c010': 0x55667788,
        '@0x4b6340': _RET, '@0x4be610': _RET, '@0x4a1ac0': _RET,
        '@0x4ac1f0': _RET, '@0x4265d0': _RET, '@0x4aa940': _RET,
        '@0x4a1fa0': _RET, '@0x4a4260': _RET, '@0x41f830': _RET,
        '@0x4a41a0': _RET, '@0x4aa8a0': _RET, '@0x4be800': _QREC,
        '@0x48a130': _RET, '@0x4a42b0': _RET, '@0x4a38d0': _RET,
        '@0x4a42d0': b'\xc7\x05\x24\x38\x54\x00\x01\x00\x00\x00\xc3',
    }

def _ipk():
    # 13 buttons x 2 players. Only button 0 is given a real key (0x41) and a
    # real target/mask pair; the rest point at a scratch word so a mis-index
    # shows up as a write to the wrong place. The GetAsyncKey stub reports
    # key 0x41 down.
    d = {
        '@0x4d21c0': 0xb99000,
        '@0xb99000': b'\x31\xc0\xc2\x04\x00',          # alt: return 0
        '@0xb99010': (b'\x8b\x44\x24\x04'                # mov eax,[esp+4]
                      b'\x3d\x41\x00\x00\x00'            # cmp eax, 0x41
                      b'\x74\x04\x31\xc0\xc3'            # jne -> 0
                      b'\xb8\x01\x00\x00\x00\xc3'),     # else 1
        '@0x4b5450': b'\xe9' + ((0xb99010 - (0x4b5450 + 5)) & 0xffffffff
                                 ).to_bytes(4, 'little'),
        '@0xb9a000': 0, '@0xb9a004': 0,
    }
    for b in range(13):
        for pl in range(2):
            d['@%x' % (0x543ab8 + b * 8 + pl * 4)] = 0 if b else (0x41 if pl == 0 else 0)
            d['@%x' % (0x4f4dcc + b * 0x10 + pl * 8)] = 0xb9a000 if b else 0xb9a000
            d['@%x' % (0x4f4dc8 + b * 0x10 + pl * 8)] = 0 if b else (0x40 if pl == 0 else 0x80)
    return d


def _itp():
    return {
        'g_demoModeFlag': 1, '@0x7af918': 0, '@0x7af920': 0, '@0x4f4e98': 0,
        '@0x4d50a4': 0x1111, '@0x4d50a8': 0x2222,
        '@0x4d50ac': 0x3333, '@0x4d50b0': 0x4444,
        '@0x543368': 0, '@0x54336c': 0, '@0x543370': 0, '@0x54357c': 0,
        '@0x4f4dcc': 0xb9a000, '@0x4f4dc8': 0x40,
        '@0x4f4ddc': 0xb9a004, '@0x4f4dd8': 0x40,
        '@0x4f4dd4': 0xb9a008, '@0x4f4dd0': 0x40,
        '@0x4f4de4': 0xb9a00c, '@0x4f4de0': 0x40,
        '@0x4f4dec': 0xb9a010, '@0x4f4de8': 0x40,
        '@0x4f4dfc': 0xb9a014, '@0x4f4df8': 0x40,
        '@0x4f4df4': 0xb9a018, '@0x4f4df0': 0x40,
        '@0x4f4e04': 0xb9a01c, '@0x4f4e00': 0x40,
        '@0xb9a000': 0xff, '@0xb9a004': 0xff, '@0xb9a008': 0xff,
        '@0xb9a00c': 0xff, '@0xb9a010': 0xff, '@0xb9a014': 0xff,
        '@0xb9a018': 0xff, '@0xb9a01c': 0xff,
        '@0x4b5650': b'\xc3', '@0x4b5470': b'\xc3', '@0x4b5450': b'\x31\xc0\xc3',
    }


def _vsi():
    return {
        'g_eventQueueTotal': 0x2e4000, 'g_xformEntityIdx': 3,
        'g_pendingNodeType': 0x40, 'g_currentNodeIdx': 0x2e5000,
        'g_eventQueueEnd': 3, 'g_xformDirtyFlags': 0,
        'g_xformLoopCounter': 0,
    }


def _b2i():
    # the walk stub reports "found" (dirty bit 2 clear) and hands back node
    # 0x2e4000, whose +0xc size leaves a splittable remainder.
    return {
        'g_matrixStackTop': 0x2e5000, 'g_xformEntityIdx': 0x111,
        'g_eventQueueCurrent': 0x222, 'g_walkCallback': 0x40,
        'g_vertexInitFlag': 0x2e6000, 'g_vertexInitVar': 0x2e7000,
        'g_currentNodeIdx': 0, 'g_xformDirtyFlags': 0, 'g_framePauseFlag': 0,
        '@0xb9000c': 0x100, '@0xb90004': 0,
        '@0x4bae90': b'\x83\x25\x8c\x20\x54\x00\xfb'
                     b'\xc7\x05\x44\x20\x54\x00\x00\x40\x2e\x00\xc3',
        '@0x409aa0': b'\xc3', '@0x409870': b'\xc3',
    }


def _mim():
    RET = b'\xc3'
    d = {
        'g_baseSel': 0x2e4000, '@0xb90084': 1, '@0xb90004': 0x2e4900,
        'g_framePauseFlag': 0, 'g_xformDirtyFlags': 0, 'g_walkCallback': 0,
        'g_currentNodeIdx': 0x1234, 'g_eventQueueCurrent': 0,
        'g_xformScratch94': 0, 'g_dlNalt1': 0, 'g_dlNalt2': 1,
        'g_iatPtr_00542058': 0,
        '@0x53a7d8': 3, '@0x53a51c': 0, '@0x52ab40': 0, '@0x535dac': 0,
        '@0x53a178': 0, '@0x53a250': 0, '@0x54371c': 0, '@0x543438': 0,
        '@0x52aac4': 0, '@0x538038': 0, '@0x53803c': 0, '@0x541df8': 0,
    }
    for va in (0x429ac0, 0x4223e0, 0x423870, 0x421c20, 0x464350, 0x431260,
               0x422e20, 0x422ef0, 0x422fc0, 0x4230b0, 0x4236a0, 0x4232e0,
               0x49cb40, 0x4231b0, 0x48a190, 0x48a1c0, 0x422ce0, 0x4613b0,
               0x461b70, 0x4776b0, 0x41f780, 0x4647f0):
        d['@%x' % va] = RET
    return d


def _dlp():
    return {
        'g_dlNalt1': 3, 'g_dlNalt2': 5, 'g_fightGroupHead': 0x2e4000,
        'g_framePauseFlag': 0, 'g_walkCallback': 0, 'g_eventQueueCurrent': 0,
        'g_lit16_00542074': 0,
        '@0x53a510': 0x11, '@0x52aafc': 0x22, '@0x537f78': 0x33,
        '@0x541de0': 0x44, '@0x538158': 0, '@0x53815c': 0,
        '@0xb90034': 0x8000000a,
        '@0x48bcf0': b'\xc3', '@0x4231f0': b'\xc3',
    }


def _dpc():
    return {
        '@0x54371c': 1, '@0x542004': 0, '@0x541ec4': 1, '@0x541ec8': 1,
        '@0x53a178': 4, '@0x53a250': 6, 'g_dlNalt1': 3, 'g_dlNalt2': 5,
        '@0x53a510': 0, '@0x52aafc': 1, '@0x541e34': 9, '@0x541e38': 9,
        'g_eventQueueCurrent': 0, 'g_currentNodeIdx': 0x2e4000,
        'g_matrixStackTop': 0x2e5000, 'g_framePauseFlag': 0,
        '@0x541ed4': 0, '@0x541ed8': 0, '@0x541edc': 0, '@0x541ee0': 0,
        '@0xb9000c': 0x2e4400, '@0xb90010': 0x2e4800,
        '@0xb91004': 0x2e4c00, '@0xb92004': 0x2e5c00,
        '@0x4d5718': 0x03020100, '@0x4d571c': 0x07060504,
        '@0x4d5720': 0x0b0a0908, '@0x4d5724': 0x0f0e0d0c,
        '@0x48bfe0': b'\xc3', '@0x48bc40': b'\xc3', '@0x4bd6e0': b'\xc3',
    }


def _fpss():
    clear4 = b'\x83\x25' + (0x54208c).to_bytes(4, 'little') + b'\xfb\xc3'
    return {
        'g_currentNodeIdx': 0x2e4000, 'g_xformEntityIdx': 0x2e4040,
        'g_matrixStackTop': 0x2e5000, 'g_framePauseFlag': 0,
        'g_xformDirtyFlags': 0,
        '@0xb90100': 0x12345678,
        '@0x405630': clear4,
    }

# The DC260 driver: both callees live-stubbed with success defaults.
def _dc260():
    clear4 = (b'\x83\x25' + (0x54208c).to_bytes(4, 'little') + b'\xfb'
              b'\xc7\x05' + (0x542044).to_bytes(4, 'little')
              + (0x2e4100).to_bytes(4, 'little') + b'\xc3')
    return {
        'g_matrixStackTop': 0x2e5000, 'g_pendingNodeType': 0x2e4000,
        'g_eventQueuePending': 0x55, 'g_framePauseFlag': 0,
        'g_xformDirtyFlags': 0,
        '@0x4060c0': clear4,                  # BootPhaseGateBracketedInit
        '@0x406c10': b'\x83\x25' + (0x54208c).to_bytes(4, 'little') + b'\xfb\xc3',
        '@0x406790': b'\xc3',                 # MStackPush2ChainLLInsert
    }

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
    # GameStateMachine: g_gameState picks the block, and for state 0 the `cmd`
    # argument picks the new state through the second jump table. The menu and
    # mode blocks call into helpers that co-execute as original bytes.
    'GameStateMachine': [
        ('state 0, cmd 1',    {'g_gameState': 0}, (1,)),
        ('state 0, cmd 2, flag clear', {'g_gameState': 0, 'g_gsmFlag': 0}, (2,)),
        ('state 0, cmd 2, flag set',   {'g_gameState': 0, 'g_gsmFlag': 1}, (2,)),
        ('state 0, cmd 8',    {'g_gameState': 0}, (8,)),
        ('state 0, cmd 0',    {'g_gameState': 0}, (0,)),
        ('state 0, cmd 9',    {'g_gameState': 0}, (9,)),
        ('state 0, cmd -1',   {'g_gameState': 0}, (0xffffffff,)),
        ('state 1 (default)', {'g_gameState': 1}, (0,)),
        ('state 13 (default)',{'g_gameState': 13}, (0,)),
        ('state out of range',{'g_gameState': 0x40}, (0,)),
        ('state 0x1c config', {'g_gameState': 0x1c}, (0,)),
    ],
    # Menu_HelpScreen's two co-executable paths run the REAL DrawMenu end to
    # end - 1281 and 1279 matching writes - which is what makes them worth
    # having. Its g_dispatchSave1494 == 2 branch is NOT co-executable: it goes
    # through Menu_PollNavInput into GetAsyncKeyState via an IAT slot the
    # verifier has no implementation for, and past the instruction cap the run
    # simply walks off into zeroed pages. Seeding a `mov eax, 0x8000 ; ret 4`
    # stub over the slot gets further but not out. The one defect that branch
    # carried - Ghidra striding the 8-byte menu table on a uint pointer, i.e.
    # by 32 - is settled directly by the original's own encoding,
    # `movsx ecx, word ptr [eax*8 + 0x4f5094]`.
    'Menu_HelpScreen': [
        ('first entry',        {'g_menuHelpScreenFlags': 0}),
        ('exit state 0x45',    {'g_menuHelpScreenFlags': 1, 'g_dispatchSave1494': 0x45}),
    ],
    'Menu_FindNextSelectable': [
        ('from -1',            dict(MENU), (-1, MENU_VA)),
        ('from 0',             dict(MENU), (0, MENU_VA)),
        ('from 1',             dict(MENU), (1, MENU_VA)),
        ('from 2 (walks off)', dict(MENU), (2, MENU_VA)),
        ('cur below -1',       dict(MENU), (-9, MENU_VA)),
    ],
    'Menu_FindPrevSelectable': [
        ('from 3',             dict(MENU), (3, MENU_VA)),
        ('from 2',             dict(MENU), (2, MENU_VA)),
        ('from 1',             dict(MENU), (1, MENU_VA)),
        ('from 0 (mask path)', dict(MENU), (0, MENU_VA)),
        ('negative cur',       dict(MENU), (-4, MENU_VA)),
    ],
    'AppInit_Misc2': [
        ('at rest',            {}),
        ('dirty heap head',    {'@0x7b41a0': 0xdeadbeef, '@0x7b41a8': 0}),
    ],
    'Menu_PollNavInput': [
        ('nothing pressed',   dict(_readers(0, 0), **{'g_dispatchSave1491': 0}), (0,)),
        ('every key down',    dict(_readers(1, 0), **{'g_dispatchSave1491': 0}), (0,)),
        ('every key, held',   dict(_readers(1, 0), **{'g_dispatchSave1491': 3}), (0,)),
        ('joystick dpad',     dict(_readers(0, 0xf0000000), **{'g_dispatchSave1491': 0}), (0,)),
        ('joy buttons, arg 0',dict(_readers(0, 0x00000fff), **{'g_dispatchSave1491': 0}), (0,)),
        ('joy buttons, arg 1',dict(_readers(0, 0x00000fff), **{'g_dispatchSave1491': 0}), (1,)),
    ],
    # DrawMenu needs a REAL menu table or it returns immediately; 0x004f5090 is
    # the help screen's, so these run the whole renderer - measure, centre,
    # slide, draw every label, place the cursor quad.
    'DrawMenu': [
        ('fresh open',        {'g_menuPrev': 0, 'g_menuCurrent': 0,
                               'g_menuCounter': 0}, (0x4f5090, 0)),
        ('same menu again',   {'g_menuPrev': 0x4f5090, 'g_menuCurrent': 0,
                               'g_menuCounter': 40}, (0x4f5090, 0)),
        ('no selection',      {'g_menuPrev': 0x4f5090, 'g_menuCurrent': 0,
                               'g_menuCounter': 40}, (0x4f5090, -1)),
        ('selection 2',       {'g_menuPrev': 0x4f5090, 'g_menuCurrent': 0,
                               'g_menuCounter': 40}, (0x4f5090, 2)),
        ('sliding out',       {'g_menuPrev': 0x4f5090, 'g_menuCurrent': 0x4f5090,
                               'g_menuCounter': 50}, (0x4f5090, 0)),
        ('counter at the cap',{'g_menuPrev': 0x4f5090, 'g_menuCurrent': 0x4f5090,
                               'g_menuCounter': 0x60}, (0x4f5090, 0)),
        ('null menu',         {'g_menuPrev': 0, 'g_menuCurrent': 0}, (0, 0)),
    ],
    # Helper_DrawMenuText walks the string a glyph at a time and submits a quad
    # per character, so it needs a real one; TEXT_VA carries it.
    'Helper_DrawMenuText': [
        ('empty string',   {'@0xb97000': b'\0'},        (100, 80, 0xb97000, 0, 0x7fff)),
        ('one glyph',      {'@0xb97000': b'A\0'},       (100, 80, 0xb97000, 0, 0x7fff)),
        ('a word',         {'@0xb97000': b'OPTIONS\0'}, (100, 80, 0xb97000, 0, 0x7fff)),
        ('highlighted',    {'@0xb97000': b'OPTIONS\0'}, (100, 80, 0xb97000, 1, 0x7fff)),
        ('wraps the page', {'@0xb97000': b'ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ\0'},
                                                        (0, 0, 0xb97000, 0, 0x100)),
    ],
    # Two out-pointers, so they need real addresses; 0xb98000 is scratch.
    'Helper_GetMenuExtents': [
        ('renderer mode 1', {'g_clampedRendererMode': 1}, (0xb98000, 0xb98010)),
        ('renderer mode 3', {'g_clampedRendererMode': 3}, (0xb98000, 0xb98010)),
        ('renderer mode 5', {'g_clampedRendererMode': 5}, (0xb98000, 0xb98010)),
        ('unknown mode 9',  {'g_clampedRendererMode': 9}, (0xb98000, 0xb98010)),
        ('null out params', {'g_clampedRendererMode': 1}, (0, 0)),
    ],
    'Helper_DrawMenu_PostRender': [
        ('centred box',   {}, (200, 150, 240, 120)),
        ('at the origin', {}, (0, 0, 640, 480)),
        ('negative x',    {}, (-40, 20, 300, 100)),
        ('degenerate',    {}, (100, 100, 0, 0)),
    ],
    # The command switch only runs on state 2, and only acts when the select
    # bit is set - so the key reader is stubbed to "held" and the selected
    # row's s16 command word (0x4f4fd4 for selection 0) is seeded per case.
    'Menu_InsertCDDialog': [
        ('fresh open',    {'g_dispatchSave1488': 0, 'g_dispatchSave1500': 0}),
        ('closing',       {'g_dispatchSave1488': 1, 'g_dispatchSave1500': 0x45}),
        ('cmd 0x11 retry', dict(_readers(1, 0), **{'g_dispatchSave1488': 1,
                               'g_dispatchSave1500': 2, 'g_dispatchSave1481': 0,
                               'g_dispatchSave1491': 0, '@0x4f4fd4': b'\x11\x00'})),
        ('cmd 0x12 close', dict(_readers(1, 0), **{'g_dispatchSave1488': 1,
                               'g_dispatchSave1500': 2, 'g_dispatchSave1481': 0,
                               'g_dispatchSave1491': 0, '@0x4f4fd4': b'\x12\x00'})),
        ('cmd 0x13 quit',  dict(_readers(1, 0), **{'g_dispatchSave1488': 1,
                               'g_dispatchSave1500': 2, 'g_dispatchSave1481': 0,
                               'g_dispatchSave1491': 0, '@0x4f4fd4': b'\x13\x00'})),
        ('cmd 0, no keys', dict(_readers(0, 0), **{'g_dispatchSave1488': 1,
                               'g_dispatchSave1500': 2, 'g_dispatchSave1481': 0,
                               'g_dispatchSave1491': 0, '@0x4f4fd4': b'\x00\x00'})),
    ],
    # RenderSceneGraphIterate walks ONE node: NODE at SCRATCH (index 0x2e4000).
    # +0x18 is the child chain (zero ends the walk), +0x34 the flag word,
    # +0x60/64/68 the transform that decides identity vs dispatch, +0x2c the
    # matrix source and +0x3c the distance node.
    'RenderSceneGraphIterate': [
        ('no child: early out', {'g_currentNodeIdx': 0x2e4000, '@0xb90018': 0}),
        ('flags bit 2: cleanup', {'g_currentNodeIdx': 0x2e4000, '@0xb90018': 0x2e4100,
                                  '@0xb90034': 4, '@0xb90100': 0}),
        ('identity, bit 0 clear', {'g_currentNodeIdx': 0x2e4000, '@0xb90018': 0x2e4040,
                                   '@0xb90034': 0, '@0xb90060': 0, '@0xb90064': 0,
                                   '@0xb90068': 0, '@0xb9002c': 0, '@0xb9003c': 0,
                                   'g_dispatchSave1573': 0, '@0xb90118': 0, '@0xb90134': 0}),
        ('identity, bit 0 set',  {'g_currentNodeIdx': 0x2e4000, '@0xb90018': 0x2e4040,
                                  '@0xb90034': 1, '@0xb90060': 0, '@0xb90064': 0,
                                  '@0xb90068': 0, '@0xb9002c': 0, '@0xb9003c': 0,
                                  'g_dispatchSave1573': 0, '@0xb90118': 0, '@0xb90134': 0}),
        ('alt bases (bit 1)',    {'g_currentNodeIdx': 0x2e4000, '@0xb90018': 0x2e4040,
                                  '@0xb90034': 2, '@0xb90060': 0, '@0xb90064': 0,
                                  '@0xb90068': 0, '@0xb9002c': 0, '@0xb9003c': 0,
                                  'g_dispatchSave1573': 0, '@0xb90118': 0, '@0xb90134': 0}),
        ('distance node set',    {'g_currentNodeIdx': 0x2e4000, '@0xb90018': 0x2e4040,
                                  '@0xb90034': 0, '@0xb90060': 0, '@0xb90064': 0,
                                  '@0xb90068': 0, '@0xb9002c': 0,
                                  '@0xb9003c': 0x2e4400, '@0xb9103c': 0x4000,
                                  'g_dispatchSave1573': 0, '@0xb90118': 0, '@0xb90134': 0}),
    ],
    # RenderSceneNode is gated on g_dispatchSave1573, which is 0 at rest, so
    # every case sets it. NODE is at SCRATCH: +0x20 flags, +0x3c/40/44 the
    # transform (all zero picks the identity path), +0 the child chain (zero
    # stops the recursion), +0x24/28/48 the sub-object, timer and cache slots.
    'RenderSceneNode': [
        ('gate clear: early out', {'g_dispatchSave1573': 0}),
        # the translation words are seeded non-zero, else the vtxTrans stores
        # write zero over zero and the case "passes" having proved nothing
        ('identity, no child',    {'g_dispatchSave1573': 1, 'g_currentNodeIdx': 0x2e4000,
                                   '@0xb90020': 0, '@0xb9003c': 0, '@0xb90040': 0,
                                   '@0xb90044': 0, '@0xb90000': 0, '@0xb90024': 0,
                                   '@0xb90028': 0, '@0xb90048': 0,
                                   'g_dispatchSave1501': 0x12340, 'g_dispatchSave1502': 0x5678,
                                   'g_dispatchSave1503': 0x9abc,
                                   'g_eventQueuePending': 0x2e4100, 'g_cj_0054205c': 0}),
        ('identity, shifted 0x11', {'g_dispatchSave1573': 1, 'g_currentNodeIdx': 0x2e4000,
                                   '@0xb90020': 0, '@0xb9003c': 0, '@0xb90040': 0,
                                   '@0xb90044': 0, '@0xb90000': 0, '@0xb90024': 0,
                                   '@0xb90028': 0, '@0xb90048': 0,
                                   'g_dispatchSave1501': 0x12340, 'g_dispatchSave1502': 0x5678,
                                   'g_dispatchSave1503': 0x9abc,
                                   'g_eventQueuePending': 0x2e4100, 'g_cj_0054205c': 0x60}),
        ('non-identity: dispatch', {'g_dispatchSave1573': 1, 'g_currentNodeIdx': 0x2e4000,
                                   '@0xb90020': 0, '@0xb9003c': 0x100, '@0xb90040': 0,
                                   '@0xb90044': 0, '@0xb90000': 0, '@0xb90024': 0,
                                   '@0xb90028': 0, '@0xb90048': 0,
                                   'g_dispatchSave1501': 0x12340,
                                   'g_eventQueuePending': 0x2e4100, 'g_cj_0054205c': 0}),
        ('culled (flag 0x4)',     {'g_dispatchSave1573': 1, 'g_currentNodeIdx': 0x2e4000,
                                   '@0xb90020': 4, '@0xb9003c': 0, '@0xb90040': 0,
                                   '@0xb90044': 0, '@0xb90000': 0,
                                   'g_eventQueuePending': 0x2e4100, 'g_cj_0054205c': 0}),
        ('already z-clamped',     {'g_dispatchSave1573': 1, 'g_currentNodeIdx': 0x2e4000,
                                   '@0xb90020': 0x2000, '@0xb90000': 0,
                                   'g_eq': 0, 'g_eventQueuePending': 0x2e4100,
                                   'g_cj_0054205c': 0}),
        ('matrix build (0x200)',  {'g_dispatchSave1573': 1, 'g_currentNodeIdx': 0x2e4000,
                                   '@0xb90020': 0x200, '@0xb9003c': 0, '@0xb90040': 0,
                                   '@0xb90044': 0, '@0xb90000': 0, '@0xb90024': 0,
                                   '@0xb90028': 0, '@0xb90048': 0,
                                   'g_eventQueuePending': 0x2e4100, 'g_cj_0054205c': 0}),
    ],
    # Both copy a 3x3 out of a node; MAT seeds that node so the copy is visible.
    'DirtyTestScaledCopy': [
        ('dirty bit clear', {'g_xformDirtyFlags': 0}),
        ('dirty bit set',   dict(MAT, **{'g_xformDirtyFlags': 0x10,
                                         'g_pendingNodeType': 0x2e4000})),
        ('dirty, other bits kept', dict(MAT, **{'g_xformDirtyFlags': 0xff,
                                         'g_pendingNodeType': 0x2e4000})),
    ],
    # The 3x3 the projection helpers read, at its real address.
    # Signs everywhere: a Q12 product with all-positive operands reads the
    # same whether the shift is arithmetic or logical.
    'MatrixTransform3x3Q12': [
        ('mixed signs', {'@0x7af990': 0x10000800, '@0x7af994': 0xf8000000,
                         '@0x7af998': 0x00001000, '@0x7af99c': 0x0800f800,
                         '@0x7af9a0': 0x1000,
                         '@0xb90000': 0x2000f000, '@0xb90004': 0x00001000,
                         '@0xb90008': 0xe0002000, '@0xb9000c': 0x10000000,
                         '@0xb90010': 0xf000},
                        (0xb90000, 0xb90100)),
        # Destination overlapping the source: the original builds all nine
        # elements in a stack scratch before copying any of them out.
        ('in place', {'@0x7af990': 0x10000800, '@0x7af994': 0xf8000000,
                      '@0x7af998': 0x00001000, '@0x7af99c': 0x0800f800,
                      '@0x7af9a0': 0x1000,
                      '@0xb90000': 0x2000f000, '@0xb90004': 0x00001000,
                      '@0xb90008': 0xe0002000, '@0xb9000c': 0x10000000,
                      '@0xb90010': 0xf000},
                     (0xb90000, 0xb90000)),
    ],
    'ArgSarAddDerefJmp': [
        ('zero base',   {'g_tickFlagF': 0, '@0xb90000': RET_STUB}, (0xb90000,)),
        ('offset base', {'g_tickFlagF': 0x40, '@0xb90100': RET_STUB}, (0xb90000,)),
    ],
    # The fallback path scales g_tickFlagF, not g_phaseIdx - eax is never
    # reloaded on it. Two different flag values pin that.
    'DispatchScaledLEA': [
        ('flag 2 uses the phase', {'g_tickFlagF': 2, 'g_phaseIdx': 3,
                                   'g_tickCurConfig': 0x4f6240,
                                   'g_dispatchSave1571': 0}),
        ('flag 5 scales itself',  {'g_tickFlagF': 5, 'g_phaseIdx': 3,
                                   'g_tickCurConfig': 0x4f62a8,
                                   'g_dispatchSave1571': 0x4f62a8}),
    ],
    'Helper_PreTick': [
        ('pause after the transform', {'g_framePauseFlag': 1,
                                       'g_eventQueueSeed': 0x2e4000,
                                       'g_tickFlagF': 2, 'g_phaseIdx': 0}),
        ('full publish', {'g_framePauseFlag': 0,
                          'g_eventQueueSeed': 0x2e4000,
                          'g_tickFlagF': 2, 'g_phaseIdx': 0,
                          # nine packed s16, mixed signs: the shl 4 widening is
                          # signed, so all-positive seeds prove nothing.
                          '@0xab4878': 0xf0000100, '@0xab487c': 0x0200f100,
                          '@0xab4880': 0xf2000300, '@0xab4884': 0x0400f300,
                          '@0xab4888': 0x8000f400}),
    ],
    # RLE stream at 0xb90000: literal, run-of-4, run with a zero colour (the
    # XOR must be skipped), then a literal that ends the row.
    # Both branches: g_texturedTriVar selects a straight row copy or the
    # channel-expanding one, and only the second rewrites the pixels.
    # A three-block heap: free / used / free-to-the-end. The split path and the
    # exact-fit path take different branches through the back-link fixups.
    # A two-texture .geo block in scratch, with the loader's own callees
    # stubbed: the file layer and the allocator are verified separately, and
    # executed for real here they would run to the instruction cap.
    'LoadGeoAsset_Textures': [
        ('already loaded is a no-op', dict(_geoblk(), **{'@0xb90004': 0x12345678}), (0,)),
        ('two textures', _geoblk(), (0,)),
        # every slot occupied: the search gives up, the record keeps its 0xffff
        ('no free slot', dict(_geoblk(), **{
            '@0x%x' % (0xab4e00 + i * 2): 0xffffffff for i in range(0, 16, 2)}), (0,)),
    ],
    # The callees are real code here - GuardedChainPushSetCallPop and the two
    # walkers - so the cases stay shallow: the null-node early out, the paused
    # exit that SKIPS the mstack pops, and a node with both child chains empty.
    # Mode 2 is the oscillator; anything else skips to the broadcast. The
    # bounds live at 0x004d2a00 / 0x004d2a10 as doubles.
    # Mem_Malloc runs for real against the seeded heap; LeaScaledCall is
    # stubbed to a ret. The entry table hangs off g_xformEntityIdx, which is a
    # RAW VA in this function rather than a packed index.
    # The guards are narrow: g_walkCallback in 1..0x10, the byte at
    # 0x004f63e8 + idx*0x10 must be zero, and g_tickCurConfig decides which of
    # two entry conditions applies. Without all three the body never runs and
    # the emitter harness reports a WEAK pass.
    # GamepadSeqRecord (750B, unconverted), SunbeamSpriteEmit and
    # Helper_DrawCursor are stubbed to `ret` in the shared arena - the record
    # stores all land BEFORE those calls, so they stay observable.
    # One chain link with a full texture record; Helper_DrawCursor is left
    # LIVE - it copies the entry into the queue, so the queue slot is the
    # observable output. The mins-negative case proves the skip.
    # The camera setup. Mat3x3VecMul6Bit / Vec3NormalizeScaleStore /
    # Color15BitPacker / PackColor run LIVE as original bytes - all four are
    # small pure-arithmetic leaves. AltCamMatrixProject is stubbed.
    # The three FPU/colour leaves the camera calls, verified on their own.
    'Vec3NormalizeScaleStore': [
        ('normalizes into row 1', {}, (1, 300, -400, 0)),
        ('zero vector passes raw', {'@0x7af9c0': 0x11, '@0x7af9d8': 0x22,
                                    '@0x7af9c4': 0x33, '@0x7af9dc': 0x44,
                                    '@0x7af9c8': 0x55, '@0x7af9e0': 0x66}, (0, 0, 0, 0)),
        # a component that overflows s16 after scaling wraps, as the original's
        # `movsx esi, ax` does
        ('row 0', {}, (0, 3, 4, 12)),
    ],
    'Color15BitPacker': [
        ('packs and clamps', {'@0x7af9f0': 0x8013}, (300, -5, 0x7f)),
        ('keeps bit 15 and low bits', {'@0x7af9f0': 0x0000}, (0x10, 0x20, 0x30)),
    ],
    'PackColor': [
        ('lane 0', {}, (0, 300, -5, 0x7f)),
        ('lane 1', {}, (1, 0x10, 0x20, 0x30)),
    ],
    # The projection leaves run LIVE; Helper_DrawCursor too - four submits
    # land in the queue. The two clamp cases prove the step retargeting.
    # A nudger: three renderer-mode branches x two `which` branches, each
    # bumping the six record words by per-panel deltas. The 0x4ed020 panel has
    # the only conditional - an abs-diff snap - driven both ways.
    # MStackBracket5_LinkedListUnlink (485B, unconverted) is stubbed to a ret
    # at its VA in the shared arena; the bracket writes are the observables.
    # A relative-linked list: node at base+xe, neighbours reached as
    # link + xe. Four link shapes: middle, head (no back-link), tail (no
    # forward link), and sole element.
    # The full merge driver, every callee LIVE: the unlink, Helper_TickAlt
    # walking a one-node sibling list, and the packed continuations at
    # 0x425f90/0x425fd0 running as original bytes in both runs.
    # The recursive teardown. Every callee LIVE: the unlink is what removes
    # each child from the parent's list, so the loop drains for real; the
    # insert lands each node in the boot list. LeaScaledCall is stubbed.
    # The sheet emitter, all projection leaves and the submit LIVE. arg1 is
    # the sheet VA (the caller passes a host pointer; identity under co-exec),
    # arg2 the packed 3x3 index.
    'BillboardSheetDualEmit': [
        ('loop-step gate', {'g_inLoopStep': 1}, (0xb90210, 0x2e4100)),
        ('sheet and one chain node', _sheet(), (0xb90210, 0x2e4100)),
        ('flag 0x40: chain only', dict(_sheet(), **{
            'g_currentNodeFlags': 0x40}), (0xb90210, 0x2e4100)),
        ('raw offsets under 0x4000', dict(_sheet(), **{
            'g_currentNodeFlags': 0x4000}), (0xb90210, 0x2e4100)),
        ('degenerate pair collapses', dict(_sheet(), **{
            '@0xb90214': 0, '@0xb90216': 0}), (0xb90210, 0x2e4100)),
    ],
    # The ground-strip emitter: one vec3 pair, all callees LIVE. `half` comes
    # from bits 8..23 of the seed's +0x58; the pair from the camera table.
    'Helper_TickReinit': [
        ('loop-step gate', {'g_inLoopStep': 1, 'g_tickX2': 2}),
        ('no rows', {'g_inLoopStep': 0, 'g_tickX2': 0}),
        ('one strip pair', _reinit()),
        # negative camera angles drive the sideways correction the other way
        ('negative rotation', dict(_reinit(), **{'@0xab47f8': 0xf000,
                                                 '@0xab47fc': 0x0800})),
    ],
    # LinkedListInsert's reversed sibling: prepend to an empty and a
    # non-empty relative list.
    # Branch selection on the tag's LOW WORD; the six callees are stubbed at
    # their VAs (ret / ret-with-value), so the writes are the dispatcher's own.
    # AllocateNode runs LIVE against the slot table; the arg is a code VA.
    # The 411262-unit angle wrap: in range untouched (no store), negative by
    # one and by many periods, and high by one and by many.
    # The four callees are stubbed at their VAs - each with a chosen effect on
    # the dirty bit, so all four routes through the driver are taken.
    # The gate init: MStackPushChainStepIndex stubbed both ways. The success
    # path zero-fills 21 + 15 words of the fresh node pair and stamps three
    # 0x10000 fields.
    # The bracketed list walk: elements after the count word at node +0x1c;
    # positive elements get a ScaledTestPauseStore pass (stub per case).
    'MStackPush3LinkedListWalk': [
        ('walks two, skips a hole', {'g_currentNodeIdx': 0x2e4000,
            'g_xformEntityIdx': 0x222, 'g_pendingNodeType': 0x333,
            'g_matrixStackTop': 0x2e5000, 'g_framePauseFlag': 0,
            'g_xformDirtyFlags': 4, 'g_walkCallback': 0,
            'g_eventQueueCurrent_mm': 0,
            '@0xb9001c': 0x2e4100, '@0xb90400': 3,
            '@0xb90404': 0x2e4800, '@0xb90408': 0, '@0xb9040c': 0x2e4900,
            '@0x408860': b'\xc3'}),
        ('count zero still takes the first', {'g_currentNodeIdx': 0x2e4000,
            'g_xformEntityIdx': 0x222, 'g_pendingNodeType': 0x333,
            'g_matrixStackTop': 0x2e5000, 'g_framePauseFlag': 0,
            'g_xformDirtyFlags': 4, 'g_walkCallback': 0,
            'g_eventQueueCurrent_mm': 0,
            '@0xb9001c': 0x2e4100, '@0xb90400': 0, '@0xb90404': 0x2e4800,
            '@0x408860': b'\xc3'}),
        ('pass aborts the walk', {'g_currentNodeIdx': 0x2e4000,
            'g_xformEntityIdx': 0x222, 'g_pendingNodeType': 0x333,
            'g_matrixStackTop': 0x2e5000, 'g_framePauseFlag': 0,
            'g_xformDirtyFlags': 0, 'g_walkCallback': 0,
            'g_eventQueueCurrent_mm': 0,
            '@0xb9001c': 0x2e4100, '@0xb90400': 2,
            '@0xb90404': 0x2e4800, '@0xb90408': 0x2e4900,
            '@0x408860': b'\x83\x0d\x8c\x20\x54\x00\x04\xc3'}),
        ('pause inside the pass: leak 3', {'g_currentNodeIdx': 0x2e4000,
            'g_xformEntityIdx': 0x222, 'g_pendingNodeType': 0x333,
            'g_matrixStackTop': 0x2e5000, 'g_framePauseFlag': 0,
            'g_xformDirtyFlags': 0, 'g_walkCallback': 0,
            'g_eventQueueCurrent_mm': 0,
            '@0xb9001c': 0x2e4100, '@0xb90400': 1, '@0xb90404': 0x2e4800,
            '@0x408860': b'\xc7\x05\x6c\x1e\x54\x00\x01\x00\x00\x00\xc3'}),
    ],
    # The list installer: set1c stub reports the element count; the insert
    # stub hands out block 0x2e4100 (or not-found); cleanup is a plain ret.
    'MStackBracket4_ListInsertZeroFill': [
        ('no elements: straight pops', dict(_b4(), **{
            '@0x4084b0': b'\xc3'})),
        ('pvs gate taken, then straight pops', dict(_b4(), **{
            '@0xb9001c': 0x2e4300, '@0x4084b0': b'\xc3'})),
        ('pause inside the set1c pass: leak 4', dict(_b4(), **{
            '@0x4084b0': b'\xc7\x05\x6c\x1e\x54\x00\x01\x00\x00\x00\xc3'})),
        ('insert, fill and cleanup', _b4()),
        ('insert says not-found: abort', dict(_b4(), **{
            '@0x425be0': b'\x83\x0d\x8c\x20\x54\x00\x04\xc3'})),
        ('pause inside the insert: leak 5', dict(_b4(), **{
            '@0x425be0': b'\xc7\x05\x6c\x1e\x54\x00\x01\x00\x00\x00\xc3'})),
    ],
    # The geo-group walk: entries of the 0xab4e78 table are packed node
    # indices; entry word +4 selects the group. GeoLoadFixupLoop stubbed.
    # The two button pollers: any of five state bits reports 1, else the
    # fall-through bit. Both read only the two DirectSound state bytes.
    # The keyboard poller. The import slot 0x4d21c0 is pointed at a scratch
    # stub (returns 0 = Alt not held, or 0x8001 = held); Input_GetAsyncKey is
    # stubbed to report one chosen key down. Key map, target and mask tables
    # are seeded for both players so the indexing is what is under test.
    # The per-frame input tick: clears the four pad words, runs the two
    # keyboard and two joystick polls (stubbed here - each sets one bit in
    # a pad word so the clear/invert sequence is observable), then the
    # edge-mask passes over four (pointer, mask) pairs and the final
    # inversion + copy-out.
    'Input_TickPlayers': [
        ('demo gate closed: only the clear', dict(_itp(), **{
            'g_demoModeFlag': 0})),
        ('gameStateResult set: polls skipped', dict(_itp(), **{
            '@0x7af918': 1})),
        ('full pass, nothing pressed', _itp()),
        ('a pad bit set by the poll stub', dict(_itp(), **{
            '@0x4b5650': b'\x83\x0d\xa4\x50\x4d\x00\x01\xc3'})),
        ('escape check clears 1323', dict(_itp(), **{
            '@0x4f4e98': 1})),
    ],
    'Input_PollPlayerKeyboard': [
        ('alt held: whole poll skipped', dict(_ipk(), **{
            '@0xb99000': b'\xb8\x01\x80\x00\x00\xc2\x04\x00'}), (0,)),
        ('player 0, button 0 down', _ipk(), (0,)),
        ('player 1 uses the other half of each pair', dict(_ipk(), **{
            '@0x543abc': 0x41}), (1,)),
        ('no key down: no mask set', dict(_ipk(), **{
            '@0xb99010': b'\x31\xc0\xc3'}), (0,)),
    ],
    # The config reset: a clear, 26 key-binding copies from the defaults
    # table, the stamped volumes and button assignments, then the joystick
    # scan. Seeded with two sticks present at slots 3 and 9.
    'ResetConfigToDefaults': [
        ('no joysticks present', {'@0x4f46a0': 0x57, '@0x4f46a4': 0x26,
            '@0x4f46a8': 0x5a, '@0x4f46ac': 0x28, '@0x4f4700': 0x11,
            '@0x4f4704': 0x22, '@0x543ab8': 0, '@0x543b68': 0x1234,
            '@0x543b6c': 0x5678}),
        ('two sticks: 3 and 9', {'@0x4f46a0': 0x57, '@0x4f46a4': 0x26,
            '@0x4f46a8': 0x5a, '@0x4f46ac': 0x28, '@0x4f4700': 0x11,
            '@0x4f4704': 0x22, '@0x543ab8': 0, '@0x543b68': 0x1234,
            '@0x543b6c': 0x5678, '@0x7b018b': 1, '@0x7b0191': 1}),
        ('one stick only', {'@0x4f46a0': 0x57, '@0x4f46a4': 0x26,
            '@0x4f46a8': 0x5a, '@0x4f46ac': 0x28, '@0x543b68': 0x1234,
            '@0x543b6c': 0x5678, '@0x7b018e': 1}),
    ],
    # The node's +0x28 queue-entry cache: set means "already queued" (clear
    # dirty bit 2 and out), clear runs the burst init and stamps the entity.
    # The vertex-slot chain: header words, then count-1 links threaded at a
    # pending-type stride, each carrying the record and a back-pointer.
    'VertexSlotInitFlagWalk': [
        ('count zero: header only', dict(_vsi(), **{'g_eventQueueEnd': 0})),
        ('count one: no links', dict(_vsi(), **{'g_eventQueueEnd': 1})),
        ('count two: one link', dict(_vsi(), **{'g_eventQueueEnd': 2})),
        ('count five: four links', dict(_vsi(), **{'g_eventQueueEnd': 5})),
    ],
    'ChainSplit_SizeFits_00425ba0': [
        ('block is big enough', {'g_currentNodeIdx': 0x2e4000, '@0xb9000c': 0x20,
            'g_eventQueueCurrent': 0x40, 'g_xformDirtyFlags': 0xff,
            'g_walkCallback': 0}),
        ('block too small', {'g_currentNodeIdx': 0x2e4000, '@0xb9000c': 0x80,
            'g_eventQueueCurrent': 0x40, 'g_xformDirtyFlags': 0,
            'g_walkCallback': 0}),
    ],
    # The block allocator with a split: the walk finds a free block, it is
    # unlinked and re-inserted, and a leftover of 8+ words becomes a second
    # block back on the free chain.
    'MStackBracket2InitChainSplitInsert': [
        ('walk finds nothing', dict(_b2i(), **{
            '@0x4bae90': b'\x83\x0d\x8c\x20\x54\x00\x04\xc3'})),
        ('exact fit: no split', dict(_b2i(), **{'@0xb9000c': 0x44})),
        ('leftover splits off', _b2i()),
        ('pause inside the walk', dict(_b2i(), **{
            '@0x4bae90': b'\xc7\x05\x6c\x1e\x54\x00\x01\x00\x00\x00\xc3'})),
        ('pause inside the re-insert', dict(_b2i(), **{
            '@0x409870': b'\xc7\x05\x6c\x1e\x54\x00\x01\x00\x00\x00\xc3'})),
        ('request under the minimum is clamped', dict(_b2i(), **{
            'g_walkCallback': 1})),
    ],
    'ChainCall_SecondEntry_00405960': [
        ('no children: stamps and returns', {'g_currentNodeIdx': 0x2e4000,
            '@0xb90000': 0, 'g_walkCallback': 0, 'g_eventQueueCurrent': 0x99,
            'g_framePauseFlag': 0, '@0x405880': b'\xc3', '@0x4bae90': b'\xc3'}),
        ('walks the child list', {'g_currentNodeIdx': 0x2e4000,
            '@0xb90000': 0x2e4800, 'g_walkCallback': 0,
            'g_eventQueueCurrent': 0, 'g_framePauseFlag': 0,
            '@0x405880': b'\xc3', '@0x4bae90': b'\xc3'}),
        ('pause inside the stamp', {'g_currentNodeIdx': 0x2e4000,
            '@0xb90000': 0x2e4800, 'g_walkCallback': 0,
            'g_eventQueueCurrent': 0, 'g_framePauseFlag': 0,
            '@0x405880': b'\xc7\x05\x6c\x1e\x54\x00\x01\x00\x00\x00\xc3'}),
    ],
    'MStackPushTwoEntryChainCall': [
        ('no child: bracket in and out', {'g_currentNodeIdx': 0x2e4000,
            '@0xb90018': 0, 'g_matrixStackTop': 0x2e5000, 'g_walkCallback': 0,
            'g_framePauseFlag': 0, '@0x405880': b'\xc3', '@0x4bae90': b'\xc3'}),
        ('child with no list', {'g_currentNodeIdx': 0x2e4000,
            '@0xb90018': 0x2e4800, '@0xb92000': 0, 'g_matrixStackTop': 0x2e5000,
            'g_walkCallback': 0, 'g_eventQueueCurrent': 0x99,
            'g_framePauseFlag': 0, '@0x405880': b'\xc3', '@0x4bae90': b'\xc3'}),
        ('child with a list: walks it', {'g_currentNodeIdx': 0x2e4000,
            '@0xb90018': 0x2e4800, '@0xb92000': 0x2e4900,
            'g_matrixStackTop': 0x2e5000, 'g_walkCallback': 0,
            'g_eventQueueCurrent': 0, 'g_framePauseFlag': 0,
            '@0x405880': b'\xc3', '@0x4bae90': b'\xc3'}),
        ('pause in the stamp leaks the bracket', {'g_currentNodeIdx': 0x2e4000,
            '@0xb90018': 0x2e4800, 'g_matrixStackTop': 0x2e5000,
            'g_walkCallback': 0, 'g_framePauseFlag': 0,
            '@0x405880': b'\xc7\x05\x6c\x1e\x54\x00\x01\x00\x00\x00\xc3'}),
    ],
    'ScaledMaskOrStore': [
        ('replaces the type nibble', {'g_currentNodeIdx': 0x2e4000,
            '@0xb90020': 0x0a123456, 'g_walkCallback': 0x9000000,
            'g_eventQueueCurrent': 0}),
        ('zero walk clears it', {'g_currentNodeIdx': 0x2e4000,
            '@0xb90020': 0xffffffff, 'g_walkCallback': 0,
            'g_eventQueueCurrent': 0}),
    ],
    # Linear search of the 16-entry sound-id table; a hit returns index+2.
    # The 170-record iterator: two loops over the per-character table,
    # each entry converted (id < 101 -> +2000, else /5) and handed to the
    # slot teardown. Loop 1 skips index 60.
    'TwinRecordIter': [
        ('both loops run', {'@0xb98000': 0,
            '@0x4c37e0': b'\xc3',
            '@0x4c3ad0': (b'\x8b\x44\x24\x04'
                          b'\x01\x05\x00\x80\xb9\x00'
                          b'\xc3')}),
    ],
    # Match init. Every callee is stubbed at its VA with a plain ret (or a
    # pause) so what is checked is the ORDER, the guards and the three
    # scheduled handlers - the sequence that turns a loaded pair of
    # characters into a live fight.
    'MatchInitMonsterChain': [
        ('state 0: re-arms and yields', dict(_mim(), **{'@0xb90084': 0})),
        ('full init', _mim()),
        ('dirty-1 branches taken', dict(_mim(), **{'g_xformDirtyFlags': 1})),
        ('mode bit 8: extra zero-triple', dict(_mim(), **{'@0x52ab40': 0x100})),
        ('mode bit 9 skips the arena-4 pair', dict(_mim(), **{'@0x52ab40': 0x200})),
        ('arena 4 takes the dual-bit gate', dict(_mim(), **{'@0x53a51c': 4})),
        ('arena 1 record iterator', dict(_mim(), **{'@0x53a51c': 1})),
        ('character 15 skips the iterators', dict(_mim(), **{'g_dlNalt1': 0xf})),
        ('pause inside the round reset', dict(_mim(), **{
            '@0x4223e0': b'\xc7\x05\x6c\x1e\x54\x00\x01\x00\x00\x00\xc3'})),
        ('pause inside the player spawn', dict(_mim(), **{
            '@0x422e20': b'\xc7\x05\x6c\x1e\x54\x00\x01\x00\x00\x00\xc3'})),
    ],
    # The two player spawns. The download and dual-push passes are stubbed;
    # the group they leave in g_fightGroupHead is what gets dressed, so the
    # field values and the player-node globals are what is checked.
    'DownloadDualPush': [
        ('spawns player 1', _dlp()),
        ('pause inside the download', dict(_dlp(), **{
            '@0x48bcf0': b'\xc7\x05\x6c\x1e\x54\x00\x01\x00\x00\x00\xc3'})),
        ('pause inside the dual push', dict(_dlp(), **{
            '@0x4231f0': b'\xc7\x05\x6c\x1e\x54\x00\x01\x00\x00\x00\xc3'})),
    ],
    'DownloadCharSetup': [
        ('spawns player 2', _dlp()),
        ('pause inside the download', dict(_dlp(), **{
            '@0x48bcf0': b'\xc7\x05\x6c\x1e\x54\x00\x01\x00\x00\x00\xc3'})),
    ],
    # One fighter's download. The costume-clash correction is the head; the
    # slot then selects which character index, which flag and which variant
    # byte apply. The debug print, setup and texture load are stubbed.
    'DownloadPlayerChar': [
        ('downloads disabled: nothing', dict(_dpc(), **{'@0x54371c': 0})),
        ('slot 0, no clash', _dpc()),
        ('slot 0, same character: costume nudged', dict(_dpc(), **{
            'g_dlNalt2': 3})),
        ('slot 1', dict(_dpc(), **{'g_eventQueueCurrent': 1})),
        ('slot 2', dict(_dpc(), **{'g_eventQueueCurrent': 2})),
        ('slot 3', dict(_dpc(), **{'g_eventQueueCurrent': 3})),
        ('flag set: the other chain', dict(_dpc(), **{'@0x53a510': 1})),
        ('mode 1 clash on the far pair', dict(_dpc(), **{
            '@0x542004': 1, '@0x53a178': 7, '@0x53a250': 7})),
        ('pause inside the setup', dict(_dpc(), **{
            '@0x48bc40': b'\xc7\x05\x6c\x1e\x54\x00\x01\x00\x00\x00\xc3'})),
    ],
    'TableSearch': [
        ('id 100 or more: refused', {'@0x4f7d40': 0}, (100,)),
        ('first slot hit', {'@0x4f7d40': 7, '@0x4f7d44': 9}, (7,)),
        ('third slot hit', {'@0x4f7d40': 1, '@0x4f7d44': 2, '@0x4f7d48': 3},
         (3,)),
        ('miss', {'@0x4f7d40': 1, '@0x4f7d44': 2}, (55,)),
    ],
    'ScaledTestPauseStore': [
        ('already queued', {'g_currentNodeIdx': 0x2e4000, '@0xb90028': 0x77,
            'g_xformDirtyFlags': 0xff, 'g_walkCallback': 0,
            '@0x405450': b'\xc3'}),
        ('stamps the entity', {'g_currentNodeIdx': 0x2e4000, '@0xb90028': 0,
            'g_xformDirtyFlags': 0xff, 'g_walkCallback': 0,
            'g_xformEntityIdx': 0x2e4444, 'g_framePauseFlag': 0,
            '@0x405450': b'\xc3'}),
        ('pause inside the burst init', {'g_currentNodeIdx': 0x2e4000,
            '@0xb90028': 0, 'g_xformDirtyFlags': 0xff, 'g_walkCallback': 0,
            'g_xformEntityIdx': 0x2e4444, 'g_framePauseFlag': 0,
            '@0x405450': b'\xc7\x05\x6c\x1e\x54\x00\x01\x00\x00\x00\xc3'}),
    ],
    # Raises the element counter to the node's +0x1c, then re-installs
    # itself as the walk callback over the node's word 0.
    'ScaledLoadCallSet1c': [
        ('counter already higher, no children', {'g_currentNodeIdx': 0x2e4000,
            'g_eventQueueCurrent': 9, '@0xb9001c': 3, '@0xb90000': 0,
            'g_xformDirtyFlags': 0xff, 'g_walkCallback': 0,
            '@0x4bae90': b'\xc3'}),
        ('counter raised, children walked', {'g_currentNodeIdx': 0x2e4000,
            'g_eventQueueCurrent': 1, '@0xb9001c': 7, '@0xb90000': 0x2e4800,
            'g_xformDirtyFlags': 0xff, 'g_walkCallback': 0,
            'g_framePauseFlag': 0, '@0x4bae90': b'\xc3'}),
        ('pause inside the alt tick', {'g_currentNodeIdx': 0x2e4000,
            'g_eventQueueCurrent': 1, '@0xb9001c': 7, '@0xb90000': 0x2e4800,
            'g_xformDirtyFlags': 0xff, 'g_walkCallback': 0,
            'g_framePauseFlag': 0,
            '@0x4bae90': b'\xc7\x05\x6c\x1e\x54\x00\x01\x00\x00\x00\xc3'}),
    ],
    'InputPollFlagBits': [
        ('nothing down', {'@0x4d50b8': 0, '@0x4d50b4': 0}),
        ('pad bit 1', {'@0x4d50b8': 2, '@0x4d50b4': 0}),
        ('state bit 6', {'@0x4d50b8': 0, '@0x4d50b4': 0x40}),
        ('pad bit 0', {'@0x4d50b8': 1, '@0x4d50b4': 0}),
        ('state bit 4', {'@0x4d50b8': 0, '@0x4d50b4': 0x10}),
        ('state bit 5', {'@0x4d50b8': 0, '@0x4d50b4': 0x20}),
        ('fall-through pad bit 2', {'@0x4d50b8': 4, '@0x4d50b4': 0}),
        ('fall-through, high bit set', {'@0x4d50b8': 0x84, '@0x4d50b4': 0}),
    ],
    'InputPollFlagBitsHalf': [
        ('nothing down', {'@0x4d50b8': 0, '@0x4d50b4': 0}),
        ('pad bit 5', {'@0x4d50b8': 0x20, '@0x4d50b4': 0}),
        ('dword bit 14', {'@0x4d50b8': 0, '@0x4d50b4': 0x4000}),
        ('pad bit 4', {'@0x4d50b8': 0x10, '@0x4d50b4': 0}),
        ('dword bit 12', {'@0x4d50b8': 0, '@0x4d50b4': 0x1000}),
        ('dword bit 13', {'@0x4d50b8': 0, '@0x4d50b4': 0x2000}),
        ('fall-through pad bit 6', {'@0x4d50b8': 0x40, '@0x4d50b4': 0}),
        ('fall-through, high bit set', {'@0x4d50b8': 0x80, '@0x4d50b4': 0}),
    ],
    'TableWalkBoundedCmp': [
        ('one entry matches the group', {'@0xab4e78': 0x2e4000, '@0xab5030': 0x5a5a,
            '@0xb90000': 0xb94000, '@0xb94004': 8, 'g_currentNodeIdx': 0x1234,
            'g_walkCallback': 0,
            '@0x4bd8e0': b'\xc7\x05\x6c\x20\x54\x00\x99\x00\x00\x00\xc3'}, (8,)),
        ('entry group differs: no fixup', {'@0xab4e78': 0x2e4000, '@0xab5030': 0x5a5a,
            '@0xb90000': 0xb94000, '@0xb94004': 3, 'g_currentNodeIdx': 0x1234,
            'g_walkCallback': 0,
            '@0x4bd8e0': b'\xc7\x05\x6c\x20\x54\x00\x99\x00\x00\x00\xc3'}, (8,)),
    ],
    # The unload: texture-id list at rec + [rec+4] + 4, ids every 4 bytes.
    'GeoLoadFixupLoop': [
        ('no record: nothing', {'g_currentNodeIdx': 0x2e4000, '@0xb90004': 0}),
        ('clears two ids, one hole', {'g_currentNodeIdx': 0x2e4000,
            '@0xb90004': 0xb94000, '@0xb94004': 0x40, '@0xb94048': 3,
            '@0xb9404c': 5, '@0xb94050': 0xffffffff, '@0xb94054': 7,
            '@0xb90000': 0xb95000, '@0xb95004': 0x00090000,
            '@0xab4e0a': 0x1111, '@0xab4e0e': 0x2222,
            'g_curTexSlot': 0x99,
            '@0x4b5b10': b'\xc3', '@0x4bd6d0': b'\xc3'}),
    ],
    'MStackPushComplexCallPop_MStackPush2ChainPrepend_004064b0': [
        ('marks the node and prepends', {'g_matrixStackTop': 0x2e5000,
            'g_xformEntityIdx': 0x123, 'g_currentNodeIdx': 0x2e4000,
            '@0xb90008': 0x11, 'g_tickFrameNodeB': 0x456,
            'g_framePauseFlag': 0, 'g_walkCallback': 0,
            '@0x409970': b'\xc3'}),
        ('pause inside the prepend', {'g_matrixStackTop': 0x2e5000,
            'g_xformEntityIdx': 0x123, 'g_currentNodeIdx': 0x2e4000,
            '@0xb90008': 0x11, 'g_tickFrameNodeB': 0x456,
            'g_framePauseFlag': 0, 'g_walkCallback': 0,
            '@0x409970': b'\xc7\x05\x6c\x1e\x54\x00\x01\x00\x00\x00\xc3'}),
    ],
    'MStackPushComplexCallPop_MStackPush2ChainPrepend_00406430': [
        ('marks the node and prepends', {'g_matrixStackTop': 0x2e5000,
            'g_xformEntityIdx': 0x123, 'g_currentNodeIdx': 0x2e4000,
            '@0xb90008': 0x11, 'g_tickFrameNodeA': 0x456,
            'g_framePauseFlag': 0, 'g_walkCallback': 0,
            '@0x409970': b'\xc3'}),
    ],
    'AudioInitSequence': [
        ('publishes the selections and un-parks', {
            '@0x542040': 0, 'g_walkCallback': 0, 'g_framePauseFlag': 0,
            '@0x541ecc': 0x11, '@0x541ed0': 0x22, '@0x53a790': 0x33,
            '@0x537ea0': 0x44, '@0x537edc': 0x55, '@0x53a1cc': 0x66,
            '@0x53a51c': 0x77, '@0x543800': 0x4a42e0, '@0x52aac4': 9,
            'g_nodeListTail': 0, 'g_eventQueueWorkType': 0,
            '@0x4ac1f0': b'\xc3', '@0x4265d0': b'\xc3',
            '@0x429e30': b'\xc3', '@0x4238b0': b'\xc3',
            '@0x49cb40': b'\xc3'}),
        ('pause in the accumulate pass', {
            '@0x542040': 0, 'g_walkCallback': 0, 'g_framePauseFlag': 0,
            '@0x541ecc': 0x11, '@0x541ed0': 0x22, '@0x53a790': 0x33,
            '@0x537ea0': 0x44, '@0x537edc': 0x55, '@0x53a1cc': 0x66,
            '@0x53a51c': 0x77, '@0x543800': 0x4a42e0,
            '@0x4ac1f0': b'\xc3', '@0x4265d0': b'\xc3',
            '@0x429e30': b'\xc7\x05\x6c\x1e\x54\x00\x01\x00\x00\x00\xc3'}),
    ],
    'Loop1cBitMask': [
        ('clears bit 2 across the stride', {'@0xf8fade': 0xff, '@0xf8fafa': 0xff,
                                            '@0xf9eb62': 0xff}),
    ],
    'LoadGeoAssetsStateMachine': [
        ('state 0 arms the fade', _lgsm(0)),
        ('state 1 mid-fade re-arms', dict(_lgsm(1), **{'g_tickW1': 0x28})),
        ('state 1 loads and sets up the group', dict(_lgsm(1), **{'g_tickW1': 0x14})),
        ('state 2 fade-in re-arms', _lgsm(2)),
        ('state 2 completes to 3', dict(_lgsm(2), **{'g_tickW1': 0xf0})),
        ('state 3 input skip arms 4', dict(_lgsm(3), **{'@0x4a1bf0': _RET1})),
        ('state 3 audio busy: swap and re-group', dict(_lgsm(3), **{
            'g_audioStateDisp50b4': 4})),
        ('state 3 idle re-arms', _lgsm(3)),
        ('state 4 finalize and link', dict(_lgsm(4), **{'g_tickW1': 0x14})),
        ('state 5 hands back to the screen', dict(_lgsm(5), **{'g_tickW1': 0xf0})),
        ('pause inside a geo load', dict(_lgsm(1), **{
            'g_tickW1': 0x14, '@0x4bd5b0': _PAUSE})),
    ],
    'Screen_Loading': [
        ('arms and chains to zero-call', {'@0x543824': 0, '@0x4be610': _RET}),
    ],
    'Screen_Loading_Tick_004a42e0': [
        ('wait: nothing pending', _slt(0)),
        ('wait: signal the FSM', dict(_slt(1), **{'g_logicStepFlag': 1})),
        ('wait: stream counters still busy', dict(_slt(0), **{
            'g_audioStateMask50c0': 4, 'g_active_0053a408': 7})),
        ('world re-init band', dict(_slt(0), **{
            'g_gsmOut3': 1, 'g_gsmActiveFlag': 1})),
        ('audio re-init band', dict(_slt(0), **{'g_gsmOut2': 1})),
        ('hand the screen to the loader', dict(_slt(0), **{'g_gsmOut1': 1})),
        ('ready: queue the state-3 resume', dict(_slt(2), **{'@0x54389c': 1})),
        ('state 2 not ready re-arms 1', _slt(2)),
        ('the load band', dict(_slt(3), **{
            '@0xb98010': 0x11223344, '@0xb9c010': 0x55667788,
            '@0xb98034': 4, '@0xb9c034': 5, 'g_gsmActiveFlag': 1})),
        ('the load band, hidden char alt args', dict(_slt(3), **{
            '@0xb98034': 6, '@0xb9c034': 5})),
    ],
    'MStackBracket1_TreeWalkRecursive2': [
        ('pause inside the alloc: leak 1', dict(_b1(9, 0x12345, 0x18), **{
            '@0x405630': b'\xc7\x05\x6c\x1e\x54\x00\x01\x00\x00\x00\xc3'})),
        ('alloc says not-found: publish null', _b1(1, 0x12345, 0x18)),
        ('leaf entity: copy and split only', _b1(9, 0x12348, 0x18)),
        ('one child, sibling stop bit', _b1(9, 0x12345, 0x18)),
        ('child alloc fails: the insert path', _b1(2, 0x12345, 0x5)),
    ],
    'InstallChainInitTailJmp': [
        ('walk paused', {'g_framePauseFlag': 0, 'g_xformDirtyFlags': 0,
            'g_matrixStackTop': 0x2e5000, 'g_installChainTailSlot': 0,
            '@0x406dd0': b'\xc7\x05\x6c\x1e\x54\x00\x01\x00\x00\x00\xc3'}),
        ('walk says not-found', {'g_framePauseFlag': 0, 'g_xformDirtyFlags': 0,
            'g_matrixStackTop': 0x2e5000, 'g_installChainTailSlot': 0,
            '@0x406dd0': b'\x83\x0d\x8c\x20\x54\x00\x04\xc3'}),
        ('stamps the root and chains on', {'g_framePauseFlag': 0,
            'g_xformDirtyFlags': 0, 'g_matrixStackTop': 0x2e5000,
            'g_installChainTailSlot': 0, 'g_walkCallback': 0,
            '@0x406dd0': b'\x83\x25\x8c\x20\x54\x00\xfb'
                         b'\xc7\x05\x44\x20\x54\x00\x00\x41\x2e\x00\xc3',
            '@0x408cb0': b'\xc3', '@0x408510': b'\xc3'}),
        ('pause inside the deref pass', {'g_framePauseFlag': 0,
            'g_xformDirtyFlags': 0, 'g_matrixStackTop': 0x2e5000,
            'g_installChainTailSlot': 0, 'g_walkCallback': 0,
            '@0x406dd0': b'\x83\x25\x8c\x20\x54\x00\xfb'
                         b'\xc7\x05\x44\x20\x54\x00\x00\x41\x2e\x00\xc3',
            '@0x408cb0': b'\xc7\x05\x6c\x1e\x54\x00\x01\x00\x00\x00\xc3'}),
    ],
    # The five-deep bracket around the chain step and the vertex-slot walk.
    # Chain-step and walk stubbed per case; the full path runs the chain step
    # LIVE with its own seeds (head at 0x2e4040, self-successor).
    'MStackBracket5_FieldClear_StateAdvance': [
        ('pause inside the chain step: leak 5', dict(_b5(), **{
            '@0x4ab510': b'\xc7\x05\x6c\x1e\x54\x00\x01\x00\x00\x00\xc3'})),
        ('chain says not-found: pop through', dict(_b5(), **{
            '@0x4ab510': b'\x83\x0d\x8c\x20\x54\x00\x04\xc3'})),
        ('pause inside the walk: leak 6', dict(_b5(), **{
            '@0x409740': b'\xc7\x05\x6c\x1e\x54\x00\x01\x00\x00\x00\xc3'})),
        ('full path: clear, stamp, walk, restore', _b5()),
    ],
    # The chain-step is a leaf: pop the head off the free chain under the
    # bit-2 toggle. Successor = field(+4) + head; head slot inherits the
    # successor's forward link; the successor's two words are zeroed.
    'MStackPushChainStepIndex': [
        ('empty chain: not-found toggle', {'g_currentNodeIdx': 0x2e4000,
            '@0xb90000': 0, 'g_xformDirtyFlags': 0,
            'g_matrixStackTop': 0x2e5000}),
        ('pops the head', {'g_currentNodeIdx': 0x2e4000, '@0xb90000': 0x10,
            '@0xb90004': 0x2e4030, 'g_xformDirtyFlags': 0,
            'g_xformEntityIdx': 0x55aa, 'g_matrixStackTop': 0x2e5000,
            '@0xb90100': 0x777}),
    ],
    'BootPhaseGateBracketedInit': [
        ('step not-found', dict(_bpg(), **{
            '@0x4ab510': b'\x83\x0d\x8c\x20\x54\x00\x04\xc3'})),
        ('fills the fresh pair', _bpg()),
    ],
    'FramePauseScaledStore': [
        ('advance not-found', dict(_fpss(), **{
            '@0x405630': b'\x83\x0d\x8c\x20\x54\x00\x04\xc3'})),
        # the split: top 12 bits signed into +0x1c, low 20 | 0x8000000 into +0x20
        ('splits a negative word', dict(_fpss(), **{'@0xb90100': 0xfff23456})),
        ('splits a positive word', _fpss()),
    ],
    'DispatcherComplex260_FramePauseScaledStore': [
        ('gate not-found: straight out', dict(_dc260(), **{
            '@0x4060c0': b'\x83\x0d\x8c\x20\x54\x00\x04\xc3'})),
        ('full path', _dc260()),
        ('inner not-found: insert', dict(_dc260(), **{
            '@0x406c10': b'\x83\x0d\x8c\x20\x54\x00\x04\xc3'})),
    ],
    'ScaledStoreThree_00409260': [
        ('stores the triple', {'g_xformEntityIdx': 0x2e4000, 'g_walkCallback': 0x77,
                               '@0xb90004': 1, '@0xb90008': 2, '@0xb9000c': 3}),
    ],
    'BootDispatchSlotInit': [
        ('paused inside the dispatcher', dict(_bdsi(), **{
            '@0x407400': b'\xc7\x05\x6c\x1e\x54\x00\x01\x00\x00\x00\xc3'})),
        ('dispatcher says not-found: insert path', dict(_bdsi(), **{
            '@0x407400': b'\x83\x0d\x8c\x20\x54\x00\x04\xc3'})),
        ('full success path', _bdsi()),
        ('walk fails after the fill', dict(_bdsi(), **{
            '@0x4088b0': b'\x83\x0d\x8c\x20\x54\x00\x04\xc3'})),
    ],
    'BootMod6487eClampAndChainMul10': [
        ('in range: no store', {'g_walkCallback': 0x1234}),
        ('negative one period', {'g_walkCallback': 0xffffff00}),
        ('negative many periods', {'g_walkCallback': 0xffc00000}),
        ('high one period', {'g_walkCallback': 0x70000}),
        ('high many periods', {'g_walkCallback': 0x500000}),
        ('exactly the period', {'g_walkCallback': 0x6487e}),
    ],
    'StoreTwoCall': [
        ('parks and allocates', {'g_nodeListTail': 0,
            '@0x53e440': 0, 'g_eventQueueWorkType': 0}, (0x48caa0, 0x71)),
    ],
    'BootStateTriple': [
        ('null first link', {'g_fightGroupHead': 0x2e4000, '@0xb9001c': 0,
                             'g_xformDirtyFlags': 0}),
        ('full chase', {'g_fightGroupHead': 0x2e4000, '@0xb9001c': 0x2e4040,
                        'g_walkCallback': 4, 'g_xformDirtyFlags': 0,
                        '@0xb90110': 0x2e4080, '@0xb90228': 0x99}),
        ('negative second hop', {'g_fightGroupHead': 0x2e4000,
                        '@0xb9001c': 0x2e4040, 'g_walkCallback': 4,
                        'g_xformDirtyFlags': 0, '@0xb90110': 0x80000001}),
    ],
    'PushSetCallCleanup': [
        ('no park, no children', {'g_currentNodeIdx': 0x2e4000,
            '@0xb9001c': 0, '@0xb90000': 0, 'g_xformDirtyFlags': 1}),
        ('parks and walks', {'g_currentNodeIdx': 0x2e4000,
            '@0xb9001c': 2, '@0xb90000': 0x2e4040, 'g_xformEntityIdx': 0x2e5000,
            'g_xformDirtyFlags': 1, 'g_framePauseFlag': 0,
            '@0xb90100': 0, '@0xb90108': 0,
            '@0x4bae90': b'\xc3'}),
    ],
    # DualAddSar runs LIVE; the rescale is *125*8 >> 16 = 1000/65536.
    'AudioVolumeRescale': [
        ('below: found', dict(_avr(), **{'g_walkCallback': 0x100})),
        ('above: cleared and zeroed', dict(_avr(), **{'g_walkCallback': 0xf000})),
    ],
    'TaggedSceneDispatch': [
        ('gated by the xor key', dict(_tsd(), **{'g_texXorKey': 1}), (5,)),
        ('tag -1: the reset trio', _tsd(), (0xffffffff,)),
        ('tag -2: iterator only', _tsd(), (0xfffffffe,)),
        ('small tag: iterate and play +2000', _tsd(), (5,)),
        ('mid tag: no iterate, magic divide', _tsd(), (0x3e8,)),
        ('range tag: iterate then divide', _tsd(), (0x1580,)),
        ('table hit: timer set', dict(_tsd(), **{
            '@0x4be760': b'\xb8\x03\x00\x00\x00\xc3'}), (0x3e8,)),
    ],
    'MStackPush2ChainPrepend': [
        ('empty list', {'g_matrixStackTop': 0x2e5000, 'g_chainInsertSlot': 0x11,
                        'g_pendingNodeType': 0x22, 'g_currentNodeIdx': 0x2e4040,
                        'g_xformEntityIdx': 0x2e4000,
                        '@0xb90000': 0, '@0xb90004': 0, '@0xb90008': 0x10,
                        '@0xb9000c': 0}),
        ('non-empty list', {'g_matrixStackTop': 0x2e5000, 'g_chainInsertSlot': 0x11,
                        'g_pendingNodeType': 0x22, 'g_currentNodeIdx': 0x2e4040,
                        'g_xformEntityIdx': 0x2e4000,
                        '@0xb90000': 0x2e4080, '@0xb90004': 0x2e4080,
                        '@0xb90008': 0x10, '@0xb9000c': 3}),
    ],
    'Mat3x3VecMul': [
        # negative matrix elements: an unsigned read pulls the neighbour
        ('mixed signs', {'@0x7af990': 0x0800f000, '@0x7af994': 0xf8000000,
                         '@0x7af998': 0x00001000, '@0x7af99c': 0x0800f800,
                         '@0x7af9a0': 0x1000,
                         '@0xb90000': 0x100, '@0xb90004': 0xffffff00,
                         '@0xb90008': 0x80}, (0xb90000, 0xb90100)),
    ],
    'Init16BitFields': [
        ('resets the BAM trio', {'@0xab47f8': 0x12345678, '@0xab47fc': 0x9abc}),
    ],
    'LinkedListSwapHead': [
        ('no chain', {'g_currentNodeIdx': 0x2e4000, '@0xb9002c': 0,
                      'g_walkCallback': 9}),
        ('splices a two-node chain', {'g_currentNodeIdx': 0x2e4000,
             '@0xb9002c': 0x2e4040, 'g_xformEntityIdx': 0x77,
             'g_matrixStackTop': 0x2e5000, 'g_bootLongChainState': 0x2e4900,
             '@0xb90100': 0x2e4080, '@0xb90200': 0}),
    ],
    'MStackBracket2_TreeWalkRecursive': [
        ('null node', {'g_currentNodeIdx': 0, 'g_xformEntityIdx': 0x11,
                       'g_pendingNodeType': 0x22, 'g_matrixStackTop': 0x2e5000,
                       'g_xformDirtyFlags': 0}),
        ('leaf node', dict(_tree(), **{})),
        ('parent with one child', dict(_tree(), **{
            '@0xb90000': 0x2e4040,
            '@0xb90114': 0x2e4000, '@0xb90110': 0, '@0xb90118': 0})),
        ('slot clear and stash', dict(_tree(), **{
            '@0xb9001c': 5, 'g_fightGroupHead': 0x2e4400,
            '@0xb9101c': 0x2e4800, '@0xb90028': 0x2e4600,
            '@0xb91800': 0, '@0xb91804': 0, '@0xb91808': 0})),
    ],
    'PvsMergeDriver': [
        ('paused at entry', dict(_pvs(), **{'g_framePauseFlag': 1})),
        ('walks found nothing: no merges', dict(_pvs(), **{'@0xb98000': 0})),
        # region1 ends exactly at the freed node and region2 sits exactly
        # past the merged region - both walks match, both merges run, and the
        # head is rewired twice.
        ('both merges run', dict(_pvs(), **{
            '@0xb98000': 0x2e4000,
            '@0xb90000': 0x2e4054, '@0xb90004': 0x2e6000,
            '@0xb90008': 0, '@0xb9000c': 0x3c,
            '@0xb90150': 0, '@0xb90154': 0x2e6000,
            '@0xb90158': 0, '@0xb9015c': 0x20,
            '@0xb9800c': 3})),
    ],
    'PvsMerge_MatchEnd_00425f90': [
        ('match', {'g_currentNodeIdx': 0x100, '@0x40c': 0x20,
                   'g_pendingNodeType': 0x124, 'g_xformDirtyFlags': 1}),
        ('no match', {'g_currentNodeIdx': 0x100, '@0x40c': 0x20,
                      'g_pendingNodeType': 0x999, 'g_xformDirtyFlags': 1}),
    ],
    'PvsMerge_MatchNode_00425fd0': [
        ('match', {'g_currentNodeIdx': 0x124, 'g_pendingNodeType': 0x124,
                   'g_xformDirtyFlags': 1}),
        ('no match', {'g_currentNodeIdx': 0x100, 'g_pendingNodeType': 0x124,
                      'g_xformDirtyFlags': 1}),
    ],
    'MStackBracket5_LinkedListUnlink': [
        ('middle of the list', _unlink(back=0x100, fwd=0x180)),
        ('first element',      _unlink(back=0,     fwd=0x180)),
        ('last element',       _unlink(back=0x100, fwd=0)),
        ('sole element',       _unlink(back=0,     fwd=0)),
    ],
    'MStackPushZeroCallPop': [
        ('brackets and pops', {'g_matrixStackTop': 0x2e5000, 'g_xformEntityIdx': 0x77,
                               'g_framePauseFlag': 0, '@0x409aa0': b'\xc3'}),
        ('paused: pop skipped', {'g_matrixStackTop': 0x2e5000, 'g_xformEntityIdx': 0x77,
                                 'g_framePauseFlag': 1, '@0x409aa0': b'\xc3'}),
    ],
    'GuardedChainPushSetCallPop': [
        ('no child', {'g_currentNodeIdx': 0x2e4000, '@0xb90010': 0,
                      'g_walkCallback': 5}),
        ('walks the child', {'g_currentNodeIdx': 0x2e4000, '@0xb90010': 0x2e4040,
                             'g_matrixStackTop': 0x2e5000, 'g_xformEntityIdx': 0x77,
                             'g_framePauseFlag': 0, '@0x409aa0': b'\xc3'}),
        ('paused: pop skipped', {'g_currentNodeIdx': 0x2e4000, '@0xb90010': 0x2e4040,
                                 'g_matrixStackTop': 0x2e5000, 'g_xformEntityIdx': 0x77,
                                 'g_framePauseFlag': 1, '@0x409aa0': b'\xc3'}),
    ],
    'GamepadSeqRecord': [
        ('sw, panel 40',  dict(_gsr(0), **{}), (0x4ed040, 0)),
        ('sw, panel 00',  dict(_gsr(0), **{}), (0x4ed000, 0)),
        ('sw, panel 20, which 1', dict(_gsr(0), **{}), (0x4ed020, 1)),
        ('hw, panel 40',  dict(_gsr(2), **{}), (0x4ed040, 0)),
        ('hw, panel 60, which 1', dict(_gsr(1), **{}), (0x4ed060, 1)),
        ('hw, panel 20: snaps',   dict(_gsr(2), **{'@0xab48b8': 500,
                                                   '@0xab48c0': 500}), (0x4ed020, 0)),
        ('hw, panel 20: far apart', dict(_gsr(2), **{}), (0x4ed020, 0)),
        ('not a panel', _gsr(0), (0xb90000, 0)),
    ],
    'SunbeamSpriteEmit': [
        ('pulses up from the low bound', dict(_beam(), **{
            '@0x4f6580': 0x50, '@0xab51fc': 4})),
        ('bounces at the high bound', dict(_beam(), **{
            '@0x4f6580': 0xfc, '@0xab51fc': 0x10})),
        ('loop-step gate', dict(_beam(), **{'g_inLoopStep': 1})),
        ('emits four beams', _beam()),
        ('mins negative: none', dict(_beam(), **{'g_vtxTransZ': 0,
            '@0xab43a0': 0xfffff000})),
    ],
    'CameraSetupAndCullFan': [
        ('camera at the target', _cam()),
        # distinct positions: both FPU blocks run, angles land in the BAM words
        ('full setup', dict(_cam(), **{'@0xb90054': 0x00900000,
                                       '@0xb90058': 0x00300000,
                                       '@0xb9005c': 0x00500000})),
        # point light exactly on the camera: len2 == 0 skips the second half
        ('light on the camera', dict(_cam(), **{'g_pointPosX': 0x100000,
                                                'g_pointPosY': 0x200000,
                                                'g_pointPosZ': 0x300000})),
        ('fov clamped low', dict(_cam(), **{'@0xb9013c': 0x1000})),
        ('cutscene counter', dict(_cam(), **{'g_fightGroupHead': 0x180000,
                                             'g_tickFlagZ': 1})),
    ],
    'BillboardChainRender': [
        ('loop step gate', {'g_inLoopStep': 1}),
        ('empty chain', dict(_bbc(), **{'@0xb9002c': 0})),
        ('link without a block', dict(_bbc(), **{'@0xb9010c': 0})),
        ('emits one entry', _bbc()),
        ('mins negative: entry skipped', dict(_bbc(), **{'g_vtxTransZ': 0,
            '@0xab43a0': 0xfffff000})),
    ],
    'MovesPanelEmit': [
        ('small node goes to the sunbeam', dict(_panel(), **{'@0x4ed018': 3})),
        ('not a panel record', dict(_panel(), **{'g_eventQueueTotal': 0x2e4100,
                                                 '@0xb90418': 0x2e4000})),
        ('both edges', _panel()),
        # middle vertex flipped: the second edge's winding bit changes
        ('winding flip', dict(_panel(), **{'@0xb9001c': 0xe000f00f})),
    ],
    'BboxProjectAndStash': [
        ('index out of range', dict(_bbox(), **{'@0xb9001c': 0x11})),
        ('byte gate set',      dict(_bbox(), **{'@0x4f63f8': 0x01})),
        ('config is the sentinel, already done', dict(_bbox(), **{
            'g_tickCurConfig': 0x4f6264, 'g_dispatchSave1580': 1})),
        ('config is the sentinel, first time', dict(_bbox(), **{
            'g_tickCurConfig': 0x4f6264, 'g_dispatchSave1580': 0})),
        ('projects and stashes', _bbox()),
        # a negative bbox corner: the projection shifts are arithmetic
        ('negative corner', dict(_bbox(), **{'@0x4f63ea': 0xfe00fd00})),
    ],
    'VertexQuadBuilder': [
        ('zero vertex count', dict(_vqb(), **{'@0xb9020e': 0,
                                              'g_pendingNodeType': 0x1234,
                                              '@0xb90048': 0x5678}), (0, 0)),
        ('fresh allocation',  _vqb(), (0, 0)),
        ('reuse rejected: wrong flags', dict(_vqb(), **{
            '@0xb90048': 0xb90400, '@0xb90400': 0, '@0xb90404': 0x1000}), (0, 1)),
        ('reuse accepted',    dict(_vqb(), **{
            '@0xb90048': 0xb90400, '@0xb90400': 8, '@0xb90404': 0x1000}), (0, 1)),
    ],
    'VibrationFrameUpdate': [
        ('gate clear', {'g_cj_0054205c': 0}, (0x2e4000,)),
        ('mode 5: broadcast only', dict(_vib(), **{'@0xb9001c': 5}), (0x2e4000,)),
        ('mode 2: steps the scale', dict(_vib(), **{'@0xb9001c': 2}), (0x2e4000,)),
        # the -0x14 sentinel means mode 2
        ('sentinel is mode 2', dict(_vib(), **{'@0xb9001c': 0xffffffec}), (0x2e4000,)),
        # scale already above the top: the increment must flip sign
        ('above the upper bound', dict(_vib(k=1.5), **{'@0xb9001c': 2}), (0x2e4000,)),
        ('below the lower bound', dict(_vib(k=0.5), **{'@0xb9001c': 2}), (0x2e4000,)),
    ],
    'LinkedListInsert': [
        ('prepend to an empty head', {
            'g_matrixStackTop': 0x2e5000, 'g_chainInsertSlot': 0x77,
            'g_pendingNodeType': 0x88, 'g_currentNodeIdx': 0x2e4040,
            'g_xformEntityIdx': 0x2e4000,
            '@0xb90000': 0, '@0xb90004': 0, '@0xb90008': 0}),
        # head[+4] is an OFFSET added to the node index, not a pointer
        ('non-zero link offset', {
            'g_matrixStackTop': 0x2e5000, 'g_chainInsertSlot': 0x77,
            'g_pendingNodeType': 0x88, 'g_currentNodeIdx': 0x2e4040,
            'g_xformEntityIdx': 0x2e4000,
            '@0xb90000': 0x2e4080, '@0xb90004': 0x10, '@0xb90008': 3}),
    ],
    'DirtyPushCallPop': [
        ('null node', {'g_currentNodeIdx': 0, 'g_xformDirtyFlags': 0}),
        ('inserts', {'g_xformDirtyFlags': 0, 'g_xformEntityIdx': 0x99,
                     'g_matrixStackTop': 0x2e5000,
                     'g_bootChainState4': 0x2e4000,
                     'g_currentNodeIdx': 0x2e4040, 'g_framePauseFlag': 0,
                     '@0xb90000': 0, '@0xb90004': 0, '@0xb90008': 0}),
    ],
    'MStackPush2ChainLLInsert': [
        ('null node', {'g_currentNodeIdx': 0, 'g_xformDirtyFlags': 0xff}),
        ('paused before the walk', {'g_currentNodeIdx': 0x2e4000,
                                    'g_framePauseFlag': 1,
                                    'g_xformDirtyFlags': 0,
                                    'g_matrixStackTop': 0x2e5000,
                                    'g_xformEntityIdx': 0x11,
                                    'g_fightGroupHead': 0x22}),
        ('no children', {'g_currentNodeIdx': 0x2e4000,
                         'g_framePauseFlag': 0,
                         'g_xformDirtyFlags': 0,
                         'g_matrixStackTop': 0x2e5000,
                         'g_xformEntityIdx': 0x11,
                         'g_fightGroupHead': 0x2e4000,
                         'g_bootChainPair0': 0,
                         '@0xb9001c': 0, '@0xb90018': 0}),
    ],
    'FSYS_HashName': [
        ('mixed case and length', {'@0xb90000': 0x415c3a43, '@0xb90004': 0x2e4f4f46,
                                   '@0xb90008': 0x004f4547}, (0xb90000,)),
    ],
    'FSYS_NormalizePath': [
        ('null argument',  {'@0xb90000': 0}, (0,)),
        ('empty string',   {'@0xb90000': 0}, (0xb90000,)),
        # "c:\foo.geo" - lowercase, and a valid DOS absolute so no error path
        ('uppercases', {'@0xb90000': 0x665c3a63, '@0xb90004': 0x672e6f6f,
                        '@0xb90008': 0x00006f65}, (0xb90000,)),
    ],
    # The directory is 12-byte entries with the key first, ascending. Sixteen
    # of them, so the hand-rolled bisection takes several steps.
    # Helper_FOpen and Helper_FRead are stubbed to succeed, so the run reaches
    # the directory walk and the O(n^2) sort check rather than an error exit.
    'AppInit_PreInstall': [
        ('reads the directory', dict(_fsysdir(8),
            **{'@0x4c5db0': b'\xb8\x01\x00\x00\x00\xc3',   # Helper_FOpen -> 1
               '@0x4c5b70': b'\xb8\x01\x00\x00\x00\xc3'})),  # Helper_FRead -> 1
    ],
    'FSYS_fopen': [
        ('key in the middle', _fsysdir(8),  (0xb91000, 0)),
        ('key first',         _fsysdir(0),  (0xb91000, 0)),
        ('key last',          _fsysdir(15), (0xb91000, 0)),
    ],
    'FSYS_fseek': [
        ('out of range handle', _fsysdir(), (0x401, 0, 0)),
        ('absolute',           _fsysdir(), (3, 0x40, 0)),
        ('relative',           _fsysdir(), (3, 0x40, 1)),
        ('from the end',       _fsysdir(), (3, 0, 2)),
        ('clamped to the end', _fsysdir(), (3, 0xffff, 0)),
    ],
    'FSYS_fread': [
        ('out of range handle', _fsysdir(), (0xb92000, 1, 4, 0x401)),
        ('fits',                _fsysdir(), (0xb92000, 4, 4, 3)),
        ('clamped by the entry end', _fsysdir(), (0xb92000, 4, 0x1000, 3)),
        # size 0 must divide by one rather than fault
        ('zero element size',   _fsysdir(), (0xb92000, 0, 4, 3)),
    ],
    'Mem_Malloc': [
        ('split the last fit', _heap3(), (0xb90200, 0x20, 5)),
        # sized so `need` lands exactly on the last block: no split, and the
        # back-link fixups are skipped entirely
        ('exact fit',          _heap3(), (0xb90200, 0x2fff65, 5)),
        ('first free block is skipped', _heap3(), (0xb90200, 0x30, 0x3f)),
    ],
    'Helper_TexUpload': [
        ('plain row copy', dict(TEXPAGE, **{
            '@0xf4d050': 0x7c1f001f, '@0xf4d054': 0x03e0ffff,
            '@0xf4d250': 0x12345678, '@0xf4d254': 0x9abcdef0}),
         (3, 2, 1, 4, 2)),
        ('channel expand', dict(TEXPAGE, **{
            'g_texturedTriVar': 1,
            '@0xf4d050': 0x7c1f001f, '@0xf4d054': 0x03e0ffff,
            '@0xf4d250': 0x12345678, '@0xf4d254': 0x9abcdef0}),
         (3, 2, 1, 4, 2)),
        ('zero height writes nothing', dict(TEXPAGE, **{
            '@0xf4d050': 0x7c1f001f}), (3, 0, 0, 4, 0)),
    ],
    'Tex_DecodeRLE16': [
        ('literals and runs', dict(TEXPAGE, **{
            'g_texXorKey': 0x1234,
            '@0xb90000': 0x8004001f,       # lit 0x001f, then code 0x8004...
            '@0xb90004': 0x03800002,
            '@0xb90008': 0x7c1f8000,
            '@0xb9000c': 0x00000002}),
         (3, 8, 2, 0xb90000)),
        # a negative slot must clamp to 14, not index backwards
        ('negative slot clamps', dict(TEXPAGE, **{
            'g_texXorKey': 0,
            '@0xb90000': 0x001f001f, '@0xb90004': 0x001f001f,
            '@0xb90008': 0x001f001f, '@0xb9000c': 0x001f001f}),
         (0xffffffff, 4, 1, 0xb90000)),
    ],
    'ChainStreamMatMulVecAdd': [
        ('project and accumulate', {'g_eventQueueTotal': 0x2e4040,
                                    'g_xformEntityIdx': 0x2e4000,
                                    'g_pendingNodeType': 0x2e4080,
                                    'g_currentNodeIdx': 0x2e40c0,
                                    '@0xb90000': 0x00100010, '@0xb90004': 0xfff00010,
                                    '@0xb90008': 0x0010fff0, '@0xb9000c': 0x00100010,
                                    '@0xb90010': 0x0010,
                                    '@0xb90100': 11, '@0xb90104': 22, '@0xb90108': 0x2e4100,
                                    '@0xb90200': 0x40, '@0xb90204': 0xffffffc0,
                                    '@0xb90208': 0x80,
                                    '@0xb90300': 5, '@0xb90304': 6, '@0xb90308': 7,
                                    '@0xb90400': 3, '@0xb90404': 4, '@0xb90408': 5}),
    ],
    # Each case ends the walk a different way: the null link, the yield to
    # Helper_TickAlt, and a two-node hop that reaches the null link.
    'ChainWalkCleanup': [
        ('null link, no handle', {'g_currentNodeIdx': 0x2e4000,
                                  '@0xb90000': 0, '@0xb90048': 0}),
        ('handle released first', {'g_currentNodeIdx': 0x2e4000,
                                  '@0xb90000': 0, '@0xb90048': 0xb90100,
                                  '@0xb900f4': 0x3f123456, '@0xb900f8': 0}),
        ('yields on a non-1 field', {'g_currentNodeIdx': 0x2e4000,
                                  '@0xb90000': 0x2e4040, '@0xb90048': 0,
                                  '@0xb9000c': 7}),
        ('hops one node then stops', {'g_currentNodeIdx': 0x2e4000,
                                  '@0xb90000': 0x2e4040, '@0xb90048': 0,
                                  '@0xb9000c': 1,
                                  '@0xb90100': 0, '@0xb90148': 0}),
    ],
    'ScaledNegThreeWords': [
        ('mixed signs', {'g_currentNodeIdx': 0x2e4000, 'g_xformDirtyFlags': 1,
                         '@0xb90000': 0xfe000100, '@0xb90004': 0x8000}),
    ],
    'CleanupCallTwice': [
        ('null slot',  {'@0xb90200': 0}, (0xb90200,)),
        ('cleans up',  {'@0xb90200': 0xb90100,
                        '@0xb900f4': 0x3f123456,      # header at user - 0xc
                        '@0xb900f8': 0},              # owner slot at user - 8
                       (0xb90200,)),
    ],
    'Transform9Words': [
        ('all positive', {'@0x7af990': 0x02000100, '@0x7af994': 0x04000300,
                          '@0x7af998': 0x06000500, '@0x7af99c': 0x08000700,
                          '@0x7af9a0': 0x0900,
                          '@0xb90100': 0x1000, '@0xb90104': 0x2000,
                          '@0xb90108': 0x0800},
                         (0x7af990, 0xb90100)),
        # A Q12 scale is signed on both sides; all-positive seeds cannot tell
        # `sar esi, 0xc` from a logical shift.
        ('negative words', {'@0x7af990': 0xff00fe00, '@0x7af994': 0x0400fd00,
                            '@0x7af998': 0xfc000500, '@0x7af99c': 0x0800fb00,
                            '@0x7af9a0': 0xfa00,
                            '@0xb90100': 0x1000, '@0xb90104': 0xffffe000,
                            '@0xb90108': 0x0800},
                           (0x7af990, 0xb90100)),
    ],
    'TransformAccumulate': [
        ('accumulate', dict(MAT3, **{'g_eventQueueTotal': 0x2e4040,
                                     'g_pendingNodeType': 0x2e4080,
                                     'g_currentNodeIdx': 0x2e40c0,
                                     '@0xb90100': 11, '@0xb90104': 22, '@0xb90108': 33,
                                     '@0xb90200': 0x40, '@0xb90204': 0xffffffc0,
                                     '@0xb90208': 0x80,
                                     '@0xb90300': 5, '@0xb90304': 6, '@0xb90308': 7})),
    ],
    'DirtyBitTripleWriteOrCall': [
        ('straight write', {'g_xformDirtyFlags': 0, 'g_xformEntityIdx': 0x2e4000,
                            'g_pendingNodeType': 0x2e4040, '@0xb90048': 0x800}),
        # sar 4, not shr - a negative field is what separates them.
        ('straight write, negative', {'g_xformDirtyFlags': 1,
                            'g_xformEntityIdx': 0x2e4000,
                            'g_pendingNodeType': 0x2e4040, '@0xb90048': 0xfffff800}),
        ('through Transform9Words', dict(MAT3,
                           **{'g_xformDirtyFlags': 0x10, 'g_xformEntityIdx': 0x2e4000,
                              'g_pendingNodeType': 0x1ebe64, '@0xb90048': 0x8000})),
    ],
    'VtableDispatchSetDirty': [
        ('low bank, no pause', dict(VTBL, **{'g_currentNodeFlags': 0x03000000,
                                             'g_fightGroupHead': 0}), (7,)),
        # bit 8 selects the second bank of eight at +0x10
        ('high bank', dict(VTBL, **{'g_currentNodeFlags': 0x0300f100,
                                    'g_fightGroupHead': 0}), (7,)),
        ('paused after the call', dict(VTBL, **{'g_currentNodeFlags': 0x03000000,
                                    'g_framePauseFlag': 1, 'g_fightGroupHead': 0}), (7,)),
        ('odd flags take the extra call', dict(VTBL,
                                   **{'g_currentNodeFlags': 0x03000000,
                                      'g_fightGroupHead': 1}), (7,)),
    ],
    'WtSnapshotPushCall': [
        ('snapshot', dict(MAT, **{'g_xformEntityIdx': 0x2e4000,
                                  'g_pendingNodeType': 0x2e4040,
                                  'g_currentNodeIdx': 0x2e4080})),
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
        if isinstance(v, (bytes, bytearray)):      # raw stub code / byte run
            arena[va - BASE:va - BASE + len(v)] = v
        else:
            struct.pack_into('<I', arena, va - BASE, v & 0xffffffff)


def main():
    fn_va, gl_va = vt.load_maps()
    # Packed internal entry points with no symbols.yaml entry, registered in
    # config/codeptr_extras.yaml for the native trampoline; the harness needs
    # their VAs here to verify their C directly. Offsite, like their parent.
    fn_va['Screen_Loading_Tick_004a42e0'] = 0x4a42e0
    fn_va['ChainSplit_SizeFits_00425ba0'] = 0x425ba0
    fn_va['ChainCall_SecondEntry_00405960'] = 0x405960
    fn_va['PvsMerge_MatchEnd_00425f90'] = 0x425f90
    fn_va['PvsMerge_MatchNode_00425fd0'] = 0x425fd0
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
            res = vc.verify(name, fn_va, gl_va, fn_va, arena, argvals=args,
                            types=TYPES.get(name), offsite=name in OFFSITE)
            if allow and res.startswith('MISMATCH'):
                m = re.match(r"MISMATCH orig_only=\[(.*?)\] twin_only=\[(.*?)\] "
                             r"vdiff=\[(.*?)\]", res)
                if m and not m.group(1) and not m.group(2):
                    # vdiff entries carry values now ('0xADDR: orig=X twin=Y');
                    # only the address before the colon is the key.
                    diff = {int(a.strip().strip("'").split(':')[0], 16)
                            for a in m.group(3).split(',')
                            if a.strip() and a.strip().strip("'")[0] == '0'}
                    if diff and diff <= allow:
                        res = 'VERIFIED (scratch ptr differs at %s - expected)' % (
                            ', '.join(hex(a) for a in sorted(diff)))
            print('  %-22s %s' % (label, res))
            if not res.startswith('VERIFIED'):
                rc = 1
    return rc


if __name__ == '__main__':
    sys.exit(main())
