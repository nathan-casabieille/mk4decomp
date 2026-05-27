# Scenegraph subsystem

Per-subsystem deep dive for MK4's scene graph: node allocator,
transform stack, dispatch table, render walker. For the
asm-verified `RenderSceneNode` analysis see the corresponding
section in [architecture.md](architecture.md) ("Outer walker -
RenderSceneNode"). This doc covers the in-engine plumbing a
contributor needs to safely modify the subsystem without breaking
the byte match.


## Overview

MK4's scene graph is a **fixed-pool, linked-list node tree** with
three cooperating pieces:

1. **Allocator** (`AllocateNode`, `0x0041f290`) - hands out one of 63
   pre-allocated 0xE8-byte slots, splices it into a singly-linked
   list rooted at `g_nodeListTail`.
2. **Walker** (`RenderSceneNode`, `0x004ba720`) - recursive descent
   driven by a 16-entry function-pointer dispatch table.
3. **Transform stack** (`g_matrixStackA/B`, `g_xformChainTable`) -
   push/pop matrix chain managed by `NodeApplyMatrix` and
   `NodeApplyTransform_B_Swapped`.

There is no malloc/free per frame. Per-frame work is purely walking
the existing list and unlinking finished nodes.


## Node layout (0xE8 bytes = 232 bytes per slot)

The pool lives at `g_nodeSlotsArea` (`0x0053e368`), 64 slots ending
at `g_nodeSlotsHdr_end` (`0x00541e40`). Each slot has two regions:

```
+0x00 .. +0xD7   data area (216 bytes)
+0xD4            magic   0x12345678 (live-slot sanity tag)
+0xD8 .. +0xE7   header  (16 bytes)
```

The typed view is `struct ScenegraphNode` in
[include/engine/scenegraph.h](../../include/engine/scenegraph.h).
See "Typed access" section below for the lift pattern.

Header subfields, aliased as individual `extern` symbols:

| Field                | Offset | Symbol                       | Set by                  |
|----------------------|--------|------------------------------|-------------------------|
| `ptr_field`          | +0xD8  | `g_nodeSlotsHdr_ptrField`    | `AllocateNode` (= type) |
| `magic`              | +0xDC  | `g_nodeSlotsHdr_magic`       | `AllocateNode` (= 0x12345678) |
| `type_word`          | +0xDC  | `g_nodeSlotsHdr_typeWord`    | `AllocateNode` (zeroed) |
| `workType`           | +0xE0  | `g_nodeSlotsHdr_workType`    | `AllocateNode` (= `g_eventQueueWorkType`) |
| `next_link`          | +0xE4  | `g_nodeSlotsHdr_nextLink`    | `AllocateNode` (linked) |

Per-node data fields read by the walker + tick code:

| Offset | Meaning                                            |
|--------|----------------------------------------------------|
| +0x00  | linked-list/payload pointer (DWORD)                |
| +0x04  | `lea esi, [edx + 0x22]; mov [edx*4+4], esi` (self-ref scratch) |
| +0x08  | `g_pendingNodeType` at alloc time                  |
| +0x0C  | `g_eventQueueWorkType` at alloc time               |
| +0x10  | (cleared by alloc; later: see node-type docs)      |
| +0x14  | `g_eventQueueNotMask` at alloc time                |
| +0x18  | `g_eventQueueChild` at alloc time / chain next     |
| +0x1C  | `g_currentNodeFlags` at alloc time                 |
| +0x20  | **flag word** = `g_currentNodeFlags` (the type/mode bits read by the walker) |
| +0x24  | `g_eventQueueEnd` at alloc time                    |
| +0x28  | `g_eventQueueIdx` at alloc time / sub-descriptor for `NodeApplyMatrix` |
| +0x2C  | `g_fightGroupHead` at alloc time                   |
| +0x30  | player_id (1..4) - set by callers                  |
| +0x34  | state - set by callers                             |
| +0x3C  | first child ref                                    |
| +0x40  | second child ref                                   |
| +0x44  | third child ref                                    |
| +0x58  | y-position (signed, clamped to -0xffff)            |
| +0x74  | state-machine value (0x501 = "special state")     |
| +0xD4  | magic 0x12345678 (live tag)                        |
| +0xE4  | linked-list next pointer (header)                  |

`AllocateNode` zero-clears `+0x30` through `+0x80` and sets every
working-state global into a specific slot - so the 16 alloc-time
globals listed above are the **node's birth state**, captured at
allocation and never re-read by the allocator itself.

### The "packed_ptr" encoding

`g_currentNodeIdx` and `g_xformEntityIdx` are NOT array indices.
They are **node addresses pre-divided by 4**:

```
g_currentNodeIdx = node_address / 4
node_address     = g_currentNodeIdx * 4
node[+N]         = *(u32 *)(g_currentNodeIdx * 4 + N)
```

This is the legacy of the PSX/N64 origin codebase, where MIPS could
reach `[reg*4]` in one instruction. On x86 the engine pays no
penalty - MSVC SP3 turns it into `[edx*4 + disp32]` (one byte
shorter than the natural `[edx + disp32]` form).

Critically, this means the node POOL is **not** a typed array. Two
distinct nodes at addresses 0x53e368 and 0x53e450 have
`g_currentNodeIdx` values of 0x14f8da and 0x14f914 - so iterating
`for (idx = ...; idx < ...; idx += 0x3a) ...` won't work. The walker
follows the `+0xE4` linked-list pointer instead.


## Typed access - struct ScenegraphNode

The 232-byte slot is now exposed as a typed C struct in
[include/engine/scenegraph.h](../../include/engine/scenegraph.h).
The struct provides named fields for the offsets confirmed via
decompilation.

> **The pool is polymorphic.** These names are the meaning for the
> scenegraph / render / player node type. Generic task nodes reuse the
> same bytes for other purposes (e.g. `+0x5C` is `position_z` here but
> a countdown counter in `DualPickDecJmp_*`). Lifting a raw
> `[reg*4+0xNN]` access to `node->field` stays byte-identical, but only
> apply the *name* once you've confirmed the node type. See the
> "polymorphic" section of [node_struct.md](node_struct.md).

| Field           | Offset | Type | Semantic (when valid)                       |
|-----------------|--------|------|---------------------------------------------|
| `payload`       | +0x00  | u32  | Alloc-scan key (0 = slot free)              |
| `self_ref`      | +0x04  | u32  | lea-based self-pointer scratch              |
| `alloc_type`    | +0x08  | u32  | `g_pendingNodeType` at birth                |
| `alloc_work_type` | +0x0C | u32 | `g_eventQueueWorkType` at birth             |
| `not_mask`      | +0x14  | u32  | `g_eventQueueNotMask` at birth              |
| `child_chain`   | +0x18  | u32  | Chain pointer (packed_ptr), used by walks   |
| `alloc_flags`   | +0x1C  | u32  | `g_currentNodeFlags` at birth               |
| `flags`         | +0x20  | u32  | Type/mode flag word (read by walker)        |
| `queue_end`     | +0x24  | u32  | `g_eventQueueEnd` at birth                  |
| `queue_idx`     | +0x28  | u32  | `g_eventQueueIdx` at birth                  |
| `group_head`    | +0x2C  | u32  | `g_fightGroupHead` at birth                 |
| `player_id`     | +0x30  | u32  | 1..4 (player nodes only - see polymorphism) |
| `state_mask`    | +0x34  | u32  | Bit 0x1000 = "on screen", plus dirty bits   |
| `child_a/b/c`   | +0x3C/+0x40/+0x44 | u32 | Child packed_ptr refs (some node types) |
| `position_x`    | +0x54  | s32  | Signed x-coord (fixed-point)                |
| `position_y`    | +0x58  | s32  | Signed y-coord (> -0xffff_0000 = on-screen) |
| `position_z`    | +0x5C  | s32  | Signed z-coord (fixed-point)                |
| `fsm_state`     | +0x74  | u32  | FSM state value (0x501 = special / fatality)|
| `install_flag`  | +0x84  | u32  | 0/1 install state flag (set in install-self)|
| `magic`         | +0xD4  | u32  | = `NODE_LIVE_MAGIC` (0x12345678) when live  |
| `ptr_field`     | +0xD8  | u32  | Header: alloc-scan key mirror               |
| `type_word`     | +0xDC  | u32  | Header: type tag                            |
| `work_type`     | +0xE0  | u32  | Header: alloc-time `g_eventQueueWorkType`   |
| `next_link`     | +0xE4  | u32  | Header: linked-list next pointer            |

The remaining offsets (`_10`, `_38`, `_48[3]`, `_60[5]`, `_78[3]`,
`_88[19]`) are unnamed scratch / user-state slots whose meaning is
polymorphic per node type. (`_38`, for instance, is a node ref used as
the xform/distance anchor in some node types but a 16.16 scalar in
others - see [node_struct.md](node_struct.md) - so it is deliberately
left unnamed.) They are present as filler so the size matches 0xE8.

### Lift pattern

To convert raw pointer arithmetic to typed access:

```c
/* Before */
*(unsigned int *)(packed_ptr * 4 + 0x34) = v;
unsigned int s = *(unsigned int *)(packed_ptr * 4 + 0x34);

/* After (inline cast - always safe) */
((ScenegraphNode *)(packed_ptr * 4))->state_mask = v;
unsigned int s = ((ScenegraphNode *)(packed_ptr * 4))->state_mask;
```

MSVC SP3 produces byte-identical machine code for both forms
(verified across ~500 lifted accesses): the `(packed_ptr * 4) + field_offset`
calculation is the same, and the compiler emits `mov reg,
[reg*4 + disp32]` in both cases.

### Lift caveat - register allocation across function calls

A LOCAL pointer binding can break the byte match when there's a
function call between accesses:

```c
/* RISKY when there's a function call between accesses */
ScenegraphNode *n = (ScenegraphNode *)(packed_ptr * 4);
v = n->state_mask;
SomeFunc();
n->state_mask = v;    /* MSVC caches `n` in callee-saved register */
                      /* orig reloads packed_ptr from memory each time */
```

For these patterns, use inline casts at each access site so MSVC
sees a fresh global load each time. This was caught when lifting
`BitSavePushCallMergePop_0045dc60` regressed (92 bytes differ) then
matched again after switching to inline-cast.

**Rule of thumb**: bind `ScenegraphNode *n = ...` only when the
function body has no calls between field accesses on the same node.
Otherwise inline-cast every access.

### Lift caveat - SIB encoding vs pointer linearization

A second case where local binding can break the byte match: when the
orig uses an `[eax*4 + disp]` SIB addressing form, and the local
binding causes MSVC to linearize the address into a pre-computed
pointer.

```c
/* RISKY when the orig uses SIB encoding for the access */
ScenegraphNode *n = (ScenegraphNode *)(g_baseSel * 4);
v = n->fsm_state;
*(unsigned int *)((char *)n + 0x70) = v;
```

MSVC may emit `mov eax, [g_baseSel]; shl eax, 2; mov [eax + 0x70], ecx`
(2 instructions to compute the pointer, then a `[reg + disp]` store)
instead of the orig's `mov [eax*4 + 0x70], ecx` (1-instruction SIB
form). 14 byte difference observed in `ScaledMove74to70_0046eaa0`.

**Fix**: keep the packed_ptr (`idx = g_baseSel`) as a local u32 and
write the cast inline at each access site:

```c
unsigned int idx = g_baseSel_00542060;
unsigned int v = ((ScenegraphNode *)(idx * 4))->fsm_state;
*(unsigned int *)(idx * 4 + 0x70) = v;       /* matches SIB */
```

MSVC now treats `idx * 4 + disp` as a fresh expression at each site
and emits the SIB form.

### Slot polymorphism

The 232-byte slot is a **polymorphic view**. The same offset can
hold different semantic data depending on the node type:

- `+0x30`: `player_id` (1..4) for player nodes; `tag` (`0x25a`,
  `0x82-0x88`, etc.) for fight-group nodes.
- `+0x34`: `state_mask` bitfield in most contexts; `flags` bitfield
  with different bit semantics in fight-group nodes.
- `+0x40`: `child_b` packed_ptr in scenegraph children; `bits`
  bitfield (e.g. `& 0xdf` to clear bit 5) in fight-group nodes.

The header defines **two sister typedefs** over the same 232 bytes,
each with field names chosen for one node-type context:

| View              | Use when                                          |
|-------------------|---------------------------------------------------|
| `ScenegraphNode`  | Generic / player nodes (default)                  |
| `FightGroupNode`  | When `g_fightGroupHead` points to the node, OR    |
|                   | when the function writes a tag like `0x25a` to +0x30, OR |
|                   | when bit operations on `+0x40` indicate a flag word |

Lift syntax differs by view:

```c
/* Player node context */
((ScenegraphNode *)(g_player1NodeIdx * 4))->player_id == 1
((ScenegraphNode *)(p * 4))->state_mask |= 4

/* Fight-group node context */
((FightGroupNode *)(g_fightGroupHead * 4))->tag = 0x25a
((FightGroupNode *)(g_fightGroupHead * 4))->bits &= 0xFFFFFFDFu
```

Offsets that don't differ semantically across views (+0x74
`fsm_state`, header fields, +0x58 `position_y`) are only named in
`ScenegraphNode`. Access them via that view even in fight-group
contexts.

### Lifted-function inventory

As of this writing, 32 pure-C readers use typed access. By field:

- `player_id`: `game_tick.c` per-player overlay scan (4 player blocks).
- `state_mask`: `scaled_or_store`, `scaled_xor_store`, `scaled_or4_store`,
  `scaled_or_ah8_call_pause_jmp`, `scaled_and4_inv_dirty_clear`,
  `scaled_or4_dirty_clear`, `bit_save_push_call_merge_pop`,
  `state6_latch`, `six_tag_calls_tail_jmp`, `guarded_set_call_or_jmp`,
  `swap_or_pass_set`, `audio_swap_negate`, `cmp_dual_patch_call_jmp`,
  `dual_field_add_sub_store`, `guarded_chain_dispatch`,
  `m_stack_bracket3_sub_chain`, `small_helpers` (ClearBit2x34).
- `child_a/b/c`: `copy3_fields3c4044`, `slot_field_swap3c`,
  `chain2_axis_diff_store_tail_jmp`, `registry_push_bind_pop`,
  `scaled_chain_3c74_jmp`, `three_call_chain_copy`, `cmp_dual_patch_call_jmp`.
- `child_chain`: `scaled_chain_neg_store`, `dual_field_add_sub_store`.
- `fsm_state`: `scaled_store501_set8_jmp`, `const0x2005_store`,
  `const111_scaled_store_jmp`, `const_0303_init_jmp`,
  `push_pop_walk_set1006`, `chained_event3`, `scaled_chain_3c74_jmp`,
  `cmp_p1_scaled_load`.
- `position_y`: `game_tick.c` per-player blocks, `dual_field_add_sub_store`.


## Allocator - AllocateNode (0x0041f290)

`AllocateNode(type)` is a single naked function that does, in order:

1. **Walk to list tail**: starting at `g_nodeListTail`, follow `+0xE4`
   until null. This finds where to append the new node.
2. **Scan for free slot**: walk `g_nodeSlotsHdr_ptrField` in 0xE8 steps
   looking for `ptr_field == 0`. On exhaustion (after 64 slots),
   `g_xformDirtyFlags |= 5` and return NULL.
3. **Init header**: write `type` into `+0xD8`, zero `+0xDC` (low 16),
   copy `g_eventQueueWorkType` into `+0xE0`.
4. **Splice list**: if previous tail exists, set `prev->next_link = new_node`;
   otherwise set `g_nodeListTail = new_node`. Either way the new
   node's `next_link` is null.
5. **Stamp magic**: `+0xD4 = 0x12345678`.
6. **Capture birth state**: set `g_currentNodeIdx = new_node / 4`, then
   copy 9 working-state globals into the data area at +0x04 / +0x08 /
   +0x0C / +0x14 / +0x18 / +0x1C / +0x20 / +0x24 / +0x28 / +0x2C.
7. **Zero +0x30..+0x80**: 21 dwords, the "user state" area.
8. **Bookkeeping**: `g_nodeAllocCounter++`, `g_xformDirtyFlags &= ~5`.

The 9 captured globals are the **scene-walk context** the caller has
already set up. A caller normally:

```c
g_pendingNodeType = 0x02;             // node type
g_currentNodeFlags = ...;             // flag word (type/mode bits)
g_eventQueueWorkType = ...;
... (set the other globals)

node = AllocNode();                   // wraps AllocateNode(g_pendingNodeType)
```

Hence the `AllocNode` wrapper at `0x0049cb60` - 15 bytes of
`AllocateNode(g_pendingNodeType)`.


## Deallocator - NodeUnlink (0x0041f710)

Unlinks a node from the list and decrements `g_nodeAllocCounter`.
The naked body lives in `src/boot/node_unlink.c`. Two paths:

- **Tail case**: if `g_nodeListTail == node`, set
  `g_nodeListTail = node->next_link` and clear node->next/prev.
- **Mid-list case**: scan the pool for the slot whose `+0xD8` field
  is `node`, copy `node->next_link` into that slot's `+0xD8` field
  (the previous node's payload pointer). This is a slow O(N) walk
  but the pool is only 64 entries.

Then `+0xD8` and `+0xE4` of the freed node are both zeroed, freeing
the slot for the next allocator scan.

The asymmetry (allocator finds free slots by `+0xD8 == 0`, NodeUnlink
walks finding the predecessor by `+0xD8 == target`) is why slot reuse
preserves the order: an unlinked slot keeps zeros in its header until
the next `AllocateNode` overwrites them.


## Per-frame walk - TickAllEntities (0x004b9e50)

Called from `GameLogicStep`. Has two distinct modes:

- **First frame** (`g_tickInitFlag == 0`): walks five fixed sub-trees,
  each with a different mask state, then fall through to the main
  pass.
- **Subsequent frames**: just the main sub-tree at `0x538070`.

Each "pass" sets up a packed_ptr for `g_currentNodeIdx`, points
`g_walkCallback` at the per-sibling callback, and calls
`Helper_TickInner` (or `Helper_TickAlt` if a sticky flag is set).
The callback is normally `Helper_FightSceneCallback`. After each
sub-tree, the walk aborts if `g_framePauseFlag != 0`.

Tail does `g_tickDecay = max(g_tickDecay - 1, 0)`.


## Sibling walker - Helper_TickInner (0x004ba130)

`Helper_TickInner` (in `src/engine/scenegraph.c`) walks the **sibling
chain** of `g_currentNodeIdx` by indexing into `g_siblingTable`:

```
ecx  = g_currentNodeIdx
eax  = g_siblingTable[ecx][+4]    ; first sibling
edi  = g_siblingTable[ecx][+8] + 2

loop:
  ecx = edi + eax
  g_currentNodeIdx = ecx           ; sibling[idx + 2]
  esi = g_siblingTable[ecx][0]
  g_currentNodeIdx = eax
  call g_walkCallback              ; ebx = callback addr
  if g_framePauseFlag != 0 -> exit
  if g_xformDirtyFlags & 1 -> post_walk
  eax = esi
  if eax != 0 -> loop
```

Two relevant globals:

| Symbol             | Address      | Role                                     |
|--------------------|--------------|------------------------------------------|
| `g_walkCallback`   | `0x0054206c` | Per-sibling callback function pointer    |
| `g_siblingTable[]` | (RELOC base) | Stride 4, indexed at +0, +4, +8          |
| `g_xformDirtyFlags`| `0x0054208c` | Bit 1 = abort walk early                 |

Exit path is `g_xformDirtyFlags |= 4`, then if `ebp != 0` and bit 0 of
the dirty flag is clear, `g_xformDirtyFlags ^= 4` (i.e. clear bit 2
that was just set). This is a two-state acknowledgment dance: the
callback can set bit 1 to abort the walk, and the walker tracks
whether the walk completed.


## Render walker - RenderSceneNode (0x004ba720)

Recursive descent through the node hierarchy. 1899 bytes, naked.
For full ASM-level analysis see [architecture.md](architecture.md);
the in-engine summary:

1. Load `node->flag_word` from `+0x20` into `g_currentNodeFlags`.
2. Test `g_currentNodeFlags & 0x2000` - bbox cull / Z-bucket clamp.
3. Test `g_framePauseFlag` - abort if set.
4. Read `node->child` at `+0x3C`; if zero, this is a leaf (calls
   `DrawMeshBlock` or one of the per-primitive submitters).
5. Otherwise dispatch via the **16-entry table**:
   ```
   idx = (flags >> 24) & 7;           // node type, 0..7
   if (flags & 0x100) idx += 8;       // mode bit
   g_nodeDispatchTable[idx]();        // apply local transform
   ```
6. Recurse into `+0x3C`, then `+0x40`, then `+0x44` (the three child
   slots).

The dispatch table at `g_nodeDispatchTable` (`0x004f7888`) is 16
function pointers, 9 distinct handlers:

| idx (type/mode) | Handler                          | Builder used      |
|-----------------|----------------------------------|-------------------|
| 0/0, 6/0, 7/0   | `NodeApplyTransform_A` (0xA3 b)  | `BuildRotMatrix_OrderA` |
| 1/0             | `NodeApplyTransform_C` (0xA3 b)  | `BuildRotMatrix_OrderC` |
| 2/0             | `NodeApplyTransform_B` (0xA3 b)  | `BuildRotMatrix_OrderB` |
| 3/0             | `NodeApplyTransform_C_Inverse` (0x9D b) | `BuildRotMatrix_OrderC` (no negation) |
| 4/0, 4/1        | `NodeApplyMatrix` (0xD6 b)       | (uses pre-built sub-matrix) |
| 5/0, 5/1        | `NodeApplyTransform_B_Swapped` (0xE0 b) | wraps `_B` with Y/Z swap |
| 0/1, 3/1, 6/1, 7/1 | `NodeApplyTransform_A_Direct` (0x62 b) | `BuildRotMatrix_OrderA` (BAM input) |
| 1/1             | `NodeApplyTransform_C_Direct` (0x62 b) | `BuildRotMatrix_OrderC` (BAM input) |
| 2/1             | `NodeApplyTransform_B_Direct` (0x62 b) | `BuildRotMatrix_OrderB` (BAM input) |

**Mode 0 vs mode 1**: in mode 0 (0xA3 bytes per handler) the
angle input is a 32-bit fixed-point value, scaled to a 16-bit BAM
via `(x >> 2) * 10430 >> 18`. In mode 1 (0x62 bytes per handler)
the input is already a 16-bit BAM, copied direct. This lets a node
choose between high-precision (radians) and compact (pre-converted
BAM) storage per joint.

The MSVC SP3 strength-reduction of `* 10430` is reproduced exactly
by writing the multiplication that way in source - see
[src/engine/scenegraph.c](../../src/engine/scenegraph.c) for the
pure-C body of `NodeApplyTransform_A/B/C` (already converted).


## Transform stack - NodeApplyMatrix (0x004be050)

The matrix stack is **two parallel arrays** plus a top counter:

| Symbol             | Role                                     |
|--------------------|------------------------------------------|
| `g_matrixStackTop` | Index (incremented before write, decremented after read) |
| `g_matrixStackA[]` | Stack of saved `g_currentNodeIdx` values |
| `g_matrixStackB[]` | Stack of saved `g_xformLoopCounter` values |
| `g_xformChainTable[]` | The actual matrix data, indexed by `g_xformEntityIdx*4` |

`NodeApplyMatrix` (still naked) implements a "push, loop 8 times,
pop" pattern:

```
push:  g_matrixStackA[++top] = g_currentNodeIdx
       g_matrixStackB[++top] = g_xformLoopCounter
       g_xformEntityIdx -= 0x0F
       g_xformLoopCounter = 8

loop8: for (i = 0; i < 8; i++) {
         next = g_xformChainTable[g_xformEntityIdx];
         g_walkCallback = next;
         g_xformChainTable[g_currentNodeIdx] = next;
         g_currentNodeIdx++;
         g_xformEntityIdx++;
       }

pop:   g_xformLoopCounter = g_matrixStackB[top--];
       g_currentNodeIdx   = g_matrixStackA[top--];
```

So `NodeApplyMatrix` copies 8 entries of `g_xformChainTable` to a
different slot in the same table - this is the **matrix multiply**
step in the recursive walk, accumulating the local transform on top
of the stacked parent transform.

`NodeApplyTransform_B_Swapped` (0x004be130) is similar but also
swaps Y/Z components of three chain entries, then tail-calls
`NodeApplyTransform_B`. If `g_framePauseFlag` is set after the inner
call, it skips the pop - leaving the stack 2-deep for the caller to
unwind on resume.


## Rotation matrices - the 4096-entry sine LUT

The three rotation-matrix builders (`BuildRotMatrix_OrderA/B/C`) at
`0x004b3800` / `0x004b3940` / `0x004b36c0` each take a 3-vector of
16-bit BAM angles and build a 3x3 matrix via:

```
sin(a) =  g_sinTable[a & 0xfff]
cos(a) = -g_sinTable[(a - 0x400) & 0xfff]
```

`g_sinTable` (`0x007b01a0`) is a 4096 x 4-byte fixed-point lookup
with `0x1000 = 2*pi`. The cosine offset trick (`sin(a - pi/2) = -cos(a)`)
lets both functions share one table.

### Angle-wrap period: `0x6487e` = one full revolution

The LUT is indexed in 12-bit BAM (`& 0xfff`, `0x1000` = 2*pi), but the
engine *stores and accumulates* rotation angles in a finer 16.16-style
unit whose full-circle period is **`0x6487e` (411262)**. Angles are
normalised into `[0, 0x6487e)` before use. Confirmed across a naming
family that all wrap by this constant:

- `TripleMod411262_00424740` - 3-unrolled mod-`0x6487e` over a node's
  three consecutive `+0x00 / +0x04 / +0x08` slots (the rotation-angle
  triple in the xform-record view), normalising each into one
  revolution.
- `ModuloMagic_0042afc0`, `m_stack_angle_wrap_dispatch`,
  `BootMod6487eClampAndChainMul10_00407510`, `triple_mod411262` - same
  `0x6487e` wrap.

The wrap is a reciprocal-magic modulo: `q = (x or (lower - x)) *
0xa2f99905 >> (32+18)` gives the revolution count, then `x -+= q *
0x6487e`. (`0xa2f99905 >> 50` is MSVC's magic reciprocal of the
period; the explicit `imul ..., 0x6487e` / `sub ..., 0x6487e` fixes the
period unambiguously.)

The stored unit is **16.16 radians** (full circle ~= `2*pi << 16`),
confirmed by the radians->BAM converter in the non-`Direct`
`NodeApplyTransform_A/B/C` handlers:

```c
bam12 = ((angle >> 2) * 10430) >> 18;   // = angle * 10430 / 2^20
```

`10430 / 2^20 = 0.0099468 = 1 / 100.53 = 4096 / (2*pi << 16)`, i.e. it
scales a 16.16-radian angle into the 4096-step (12-bit) BAM the sine
LUT indexes. The `Direct` variants
(`NodeApplyTransform_A/B/C_Direct`) skip this and copy `angles[]`
straight through - their inputs are **already** 12-bit BAM.

Note a real (tiny) engine inconsistency: the converter's implied
`2*pi << 16 = 411775`, but the wrap period is `0x6487e = 411262`. So a
full stored revolution converts to `((0x6487e >> 2) * 10430) >> 18 =
4091` BAM, not 4096 - the wrap path and the convert path use slightly
different `pi` approximations (~0.12% apart). Harmless at this scale,
but it means angle wrap and angle->LUT do not share one constant.

### OrderA matrix - decoded + verified

`BuildRotMatrix_OrderA` (`0x004b3800`) was transcribed cell-by-cell
from the asm and the result **verified orthonormal with det = +1**
over 200 random angle triples (a real rotation matrix). With
`cN = cos(aN)`, `sN = sin(aN)` for the three input angles, it stores
the row-major 3x3:

```
| -c2 c0 c1 + s2 s1    s2 c0 c1 + c2 s1   -s0 c1 |
| -c2 s0               s2 s0               c0    |
|  c2 c0 s1 + c1 s2   -s2 c0 s1 + c2 c1    s0 s1 |
```

(byte offsets: row0 = +0/+2/+4, row1 = +6/+8/+0xA, row2 = +0xC/+0xE/
+0x10; each product is `>> 12` normalised.)

**It is NOT a textbook Euler order.** Brute-forcing all 3-axis
sequences (incl. repeated-axis), per-axis sign conventions, angle-sign
flips and transpose (48+ conventions, validated to find a known
`Rz Ry Rx`) yields **no match** - the bare `cos(a0)` sits at the
off-diagonal (1,2) position, which standard XYZ/ZXZ/etc. never produce.
This is the engine's own axis convention (consistent with the explicit
Y/Z-swap variant `NodeApplyTransform_B_Swapped`), so a textbook label
like "XYZ" would be wrong. For porting, use the verified matrix above
directly rather than a Euler name.

### OrderC matrix - decoded + verified

`BuildRotMatrix_OrderC` (`0x004b36c0`, used by joint types 1 and 3)
transcribed the same way and **verified orthonormal, det = +1** over
300 random triples:

```
|  s2 s1               c2 s1              -c1    |
|  s2 c1 c0 - c2 s0    s2 s0 + c2 c1 c0    c0 s1 |
|  s2 c1 s0 + c2 c0   -c0 s2 + c2 c1 s0    s1 s0 |
```

It is a **genuinely different ordering** from OrderA, not just a
different store order: the bare-cos terms sit elsewhere (OrderC has
`-c1` at (0,2) and `c0 s1` at (1,2); OrderA has `-s0 c1` at (0,2) and
bare `c0` at (1,2)), and OrderC's row 0 is the simple `[s2 s1, c2 s1,
-c1]`. So A and C compose the three angles about a different axis
sequence (both in the engine's custom, non-textbook convention).

### OrderB matrix - decoded + verified

`BuildRotMatrix_OrderB` (`0x004b3940`, joint types 2/5) transcribed
cell-by-cell the same way and **verified orthonormal, det = +1** over
20000 random triples:

```
|  s1 s2             c0 c1 s2 + c2 s0    -s0 c1 s2 + c0 c2 |
| -s1 c2            -c0 c1 c2 + s0 s2     s0 c1 c2 + c0 s2 |
|  c1               -c0 s1                s1 s0           |
```

(byte offsets as in OrderA: row0 = +0/+2/+4, row1 = +6/+8/+0xA,
row2 = +0xC/+0xE/+0x10; products `>> 12` normalised.)

It is again the engine's **custom convention**, distinct from both A
and C: the bare `cos(a1)` sits at (2,0) and the simple `s1 s2`/`-s1 c2`
pair leads rows 0 and 1, while the bare `s1 s0` lands at (2,2). All
three builders (A/B/C) therefore compose the same three angles about
**different axis sequences**; none is a textbook Euler order, so port
each by its verified matrix above rather than a Euler name.

With this the full `BuildRotMatrix_OrderA/B/C` trio is decoded and
numerically verified.


## Sort-key LUT - BuildSortKeyLUT (0x004bf290)

Two-pass init called once from `Gfx_Init`:

1. `memset(g_paletteScratch, 0, 0x108000 * 4)` - clears 4 MB
   (`0x00b2d010..0x00f35010`).
2. `Helper_PaletteInit(0)` - palette/lighting init.
3. Fill `g_zSortKeyLUT[0..65535]` with
   `(s32)(i / (i * 31 / 65536 + 1))`. This remaps a linear z-bucket
   (0..65535) to a hyperbolic sort-key, giving more sort precision
   to near geometry.
4. Fill `g_div3Table[0..767]` with `i / 3`. Used to pick which of
   3 vertices in a primitive owns the sort key.

The pure-C body is in [src/engine/sort_lut.c](../../src/engine/sort_lut.c).
The static const decl order is **reversed** from the .rdata pool
order so MSVC SP3 emits the `fmul` operands in the right sequence.


## Globals reference

### Pool + linked list

| Symbol               | Address     | Role                                       |
|----------------------|-------------|--------------------------------------------|
| `g_nodeSlotsArea`    | `0x0053e368`| 64 * 0xE8-byte slot pool                   |
| `g_nodeSlotsHdr_ptrField` | `0x0053e440` | First slot's +0xD8 (alloc scan target) |
| `g_nodeSlotsHdr_end` | `0x00541e40`| End sentinel (exclusive)                   |
| `g_nodeListTail`     | `0x0052ab3c`| Tail of live linked list                   |
| `g_nodeAllocCounter` | `0x00541e64`| `g_nodeAllocCounter++` per alloc           |
| `g_pendingNodeType`  | `0x0054204c`| Type for next `AllocNode()` call           |

### Walk state

| Symbol               | Address     | Role                                       |
|----------------------|-------------|--------------------------------------------|
| `g_currentNodeIdx`   | `0x00542044`| Current node (packed_ptr = addr/4)         |
| `g_currentNodeFlags` | `0x00542084`| Flag word loaded from current node's +0x20 |
| `g_xformEntityIdx`   | `0x00542048`| Entity-table index (packed_ptr)            |
| `g_xformDirtyFlags`  | `0x0054208c`| Dirty bits OR'd by every `_Direct` handler |
| `g_xformScratch2088` | `0x00542088`| Sticky scratch slot                        |
| `g_walkCallback`     | `0x0054206c`| Per-sibling callback                       |
| `g_walkStateIndex`   | `0x0053a748`| Per-state index for SetState_XX helpers    |
| `g_framePauseFlag`   | (game/tick) | Set non-zero to abort all in-flight walks  |

### Transform stack

| Symbol               | Address     | Role                                       |
|----------------------|-------------|--------------------------------------------|
| `g_matrixStackTop`   | `0x004d57ac`| Stack index                                |
| `g_matrixStackA[]`   | (RELOC)     | Saved-nodeIdx stack                        |
| `g_matrixStackB[]`   | (RELOC)     | Saved-loopCounter stack                    |
| `g_xformLoopCounter` | `0x0053a1ac`| Inner-walk loop counter                    |
| `g_xformChainTable[]`| (RELOC)     | The matrix data (indexed via packed_ptr*4) |
| `g_xformTempAngles[3]`| `0x00ab5208`| 6-byte scratch for negated angles          |

### Event queue (driven alongside scene walk)

| Symbol               | Address     | Role                                       |
|----------------------|-------------|--------------------------------------------|
| `g_eventQueueHead`   | `0x0053a2f0`| Iteration cursor                           |
| `g_eventQueueEnd`    | `0x00542054`| Cached end of iteration                    |
| `g_eventQueueTotal`  | (varies)    | (set by `RenderSceneNode`)                 |
| `g_eventQueueWorkType`| `0x00542074`| Type tag captured at AllocateNode          |
| `g_eventQueueCurrent`| `0x00542070`| Active head value                          |
| `g_eventQueueChild`  | `0x00542080`| AND-merged child flags                     |
| `g_eventQueueIdx`    | `0x00542058`| Per-iter counter                           |
| `g_eventQueueNotMask`| `0x0054207c`| Negated mask                               |
| `g_fightGroupHead`   | `0x0054205c`| Per-fight-subtree head                     |

### Dispatch + render

| Symbol               | Address     | Role                                       |
|----------------------|-------------|--------------------------------------------|
| `g_nodeDispatchTable[16]` | `0x004f7888`| 16 fn ptrs (9 distinct handlers)      |
| `g_sinTable[4096]`   | `0x007b01a0`| BAM-indexed sine LUT (`0x1000 = 2*pi`)     |
| `g_zSortKeyLUT[65536]`| `0x00b0d008`| z-bucket -> sort-key remap (set by `BuildSortKeyLUT`) |
| `g_div3Table[768]`   | `0x00f70ff8`| `i / 3` for primitive vertex selection     |
| `g_paletteScratch[]` | `0x00b2d010`| 4 MB scratch (zero'd by `BuildSortKeyLUT`) |


## What's safe to change vs not

**Safe**:
- Renaming any of the globals above (apply consistently + `make matching`).
- Adding type info to the node descriptor (e.g. typedefing a `struct
  Node` in `include/engine/scenegraph.h`) **so long as field offsets
  and sizes match exactly** - 232-byte stride is hard-coded in
  `AllocateNode`, `NodeUnlink`, the walker's `+0xE4` chase, and in the
  16 dispatch handlers' `[packed_ptr * 4 + disp32]` references.
- Editing pure-C handlers (`NodeApplyTransform_A/B/C`, `_Direct`
  variants, `_C_Inverse`) - they are already converted; small style
  changes that preserve the strength-reduced `* 10430` lowering
  keep matching.
- Adding new sub-systems that allocate nodes via `AllocNode()`,
  provided they correctly prime `g_pendingNodeType` +
  `g_currentNodeFlags` before the call.

**Unsafe**:
- Changing the 232-byte stride, the `+0xD8` header offset, the
  `+0xE4` link offset, or the `+0xD4` magic. All four are
  byte-baked into the allocator + walker + dispatch handlers.
- Reordering slot fields. The 16 dispatch handlers reach into
  `node[+0x20]` (flag word), `+0x28` (sub-matrix for `NodeApplyMatrix`),
  `+0x3C/+0x40/+0x44` (children) directly via packed_ptr arithmetic.
- Reordering globals in the 0x00542044..0x0054208c range. They are
  loaded in specific byte-addressing patterns:
  `g_currentNodeIdx` (0x542044) -> `g_xformEntityIdx` (0x542048) ->
  `g_pendingNodeType` (0x54204c) etc. Changing offsets changes the
  imm32 in every `mov [g_X], reg` instruction site-wide.
- Changing the sine LUT base (`0x007b01a0`) or stride (4 bytes).
  Indexed via `[reg*4 + 0x007b01a0]` from inside the matrix builders.
- Changing the dispatch table base (`0x004f7888`) or entry order.
  `RenderSceneNode` does `[g_nodeDispatchTable + eax*4]` with the
  imm32 hardcoded.
- Modifying `BuildSortKeyLUT`'s static const order. MSVC SP3 emits
  `fmul` operands by .rdata pool order, which is reversed from C
  declaration order - the comment in `sort_lut.c` explains.


## What's still naked vs pure C

In `src/engine/scenegraph.c`:

- **Pure C** (already converted):
  `AllocNode` (the 15-byte wrapper),
  `NodeApplyTransform_A`, `_B`, `_C`, `_C_Inverse`,
  `_A_Direct`, `_B_Direct`, `_C_Direct`,
  `DispatchProbeOrTransformB_004bdc70`,
  `DispatchProbeOrTransformC_004bddc0`.

- **Hybrid C+__asm**:
  `NodeApplyMatrix` (push/loop/pop matrix-stack body, C-call wrapper).

- **Still naked**:
  `AllocateNode` - the 30-store reload-from-`g_currentNodeIdx`
  pattern cannot be coaxed from pure C; MSVC would CSE the load.
  `Helper_TickInner` - the long sibling walk needs `ebx` cached as
  the callback function pointer in a way pure C wouldn't preserve.
  `NodeApplyTransform_B_Swapped` - byte-exact `lea eax, [esp+0]`
  with disp8=0 forced via `_emit`.

In `src/engine/render_scene_node.c`:
- `RenderSceneNode` (1899 bytes naked) - recursive function pointer
  table dispatch + frustum cull + Z-bucket clamp. The function is
  too big and too register-allocator-sensitive to convert.

In `src/boot/`:
- `NodeUnlink_0041f710` - hybrid asm body (C wrapper +
  `__asm` block). The asm fits naturally; conversion is possible
  but adds 6+ instruction-byte diffs.


## Adding a new node type

If you wanted to add a new scene-graph node type without breaking
the byte match:

1. **Pick an unused type/mode pair**. The 16-entry dispatch table is
   FULL (types 0..7, both modes used somewhere). You cannot extend
   it. So a new node type has to **reuse** an existing handler via a
   creative flag-word assignment - or you can patch the dispatch
   table runtime (which would break the byte match of the data
   segment).
2. **Set up the alloc-time globals** before calling `AllocNode()`:
   `g_pendingNodeType`, `g_currentNodeFlags`, and the eight working
   `g_eventQueue*` globals.
3. **Add the type to the per-frame walk**. The default callbacks
   (`Helper_FightSceneCallback`, etc.) only fire on specific
   sub-trees - hook into `TickAllEntities` or attach via the
   `+0x3C/+0x40/+0x44` child fields of an existing node.

In practice MK4 is too constrained for runtime engine extension; the
scene graph was designed for a fixed set of game-object kinds. New
features ride on top of existing node types' user-state areas
(`+0x30..+0x80`).


## Where to start when modifying

- **Add a debug overlay**: walk the live list via `g_nodeListTail`
  and `+0xE4`; for each node print `+0x20` (flags) and `+0x30`
  (player_id). Doesn't need to touch any matching code.
- **Adjust draw order**: change the sort-key formula in
  `BuildSortKeyLUT`. Breaks byte match - flagged unsafe above.
- **Replace the sine LUT with float sin/cos**: hook
  `BuildRotMatrix_OrderA/B/C` callers. Breaks byte match.
- **Profile node lifetime**: tap `g_nodeAllocCounter` each frame.
  Pure observation, no risk.
