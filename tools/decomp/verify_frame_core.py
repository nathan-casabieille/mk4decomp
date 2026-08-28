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
}

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
                            types=TYPES.get(name))
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
