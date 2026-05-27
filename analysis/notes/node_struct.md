# MK4.EXE - The node / task struct (the `*4` pool)

Almost every gameplay, scene and screen-FSM function in the engine
operates on records drawn from one shared **node pool**, addressed
through the engine's "packed pointer" convention. This is the single
most load-bearing data structure in the binary: a field-access tally
across the decompiled source finds `[reg*4 + 0x84]` alone referenced
**8110** times, and the next dozen offsets thousands more.

**The authoritative field table is the `ScenegraphNode` struct in
[scenegraph.md](scenegraph.md) / [include/engine/scenegraph.h](../../include/engine/scenegraph.h)**
(0xE8 = 232 bytes, with `position_x/y/z`, `player_id`, `state_mask`,
`fsm_state`, `flags`, `child_a/b/c`, the `magic`/header tail, etc.).
This note does **not** re-table those fields - it covers the
*cross-cutting* views of the same pool that scenegraph.md does not: the
**cooperative task-FSM** role, the **multi-view addressing** caveat,
the position **axis roles**, the polymorphic `+0x38` slot (left
unnamed `_38` in scenegraph.h), and the access-frequency ranking that
prioritises future RE.

## Packed-pointer addressing

A node is referenced by a **packed index** = `node_address / 4`
(see [scenegraph.md](scenegraph.md)). Globals like
`g_baseSel_00542060` (the current actor/player node),
`g_currentNodeIdx` (the transient walk/work cursor) and
`g_xformEntityIdx` hold these packed indices. Field access therefore
looks like:

```asm
mov  eax, [g_baseSel_00542060]   ; eax = packed idx
mov  edx, [eax*4 + 0x84]          ; edx = node->state   (idx*4 = node addr)
```

So `[reg*4 + 0xNN]` throughout the source is reading node field `0xNN`.

## Governing principle: the node pool is POLYMORPHIC

The single most important thing to know before trusting any field
name: **the node record is a polymorphic union - most slots mean
different things depending on the node's type.** scenegraph.h's named
fields (`position_x/y/z`, `fsm_state`, ...) are the meanings for the
**scenegraph / render / player** node type. Generic task nodes reuse
the very same bytes for unrelated purposes. Verified examples:

| Slot | scenegraph/render-node meaning | other observed use |
|------|--------------------------------|--------------------|
| +0x5c | `position_z` (16.16 coord) | a **countdown counter** in `DualPickDecJmp_*` (dec by 1, clamp at 0) |
| +0x38 | (unnamed) xform/distance anchor node ref | a **16.16 scalar** in `ChainStoreCmpJmp_*` (set to 0xffffb334, delta vs 0.1) |
| +0x48 | (unnamed `_48[3]`) | a **staged Y** copied to `position_y` by `ScaledMove48to58_*` |

So: **always confirm the node type / calling context before applying
a field name.** This is why scenegraph.h leaves most slots unnamed and
why a "lift `[reg*4+0xNN]` -> `node->field`" is only meaning-correct
inside a confirmed scenegraph/render-node context (it stays
byte-identical regardless, but the *name* can mislead). It is also why
the field-archaeology in this note stops at the universally-consistent
slots (state +0x84, the task-FSM cursor/continuation +0x04/+0x08) and
flags everything else as context-dependent.

## Caveat: multiple record views over the same `*4` pool

The packed-pointer convention is used for **more than one record
shape**, and the cursor that selects the view differs:

- `g_baseSel` / `g_currentNodeIdx` -> the **task / scene node** (the
  `ScenegraphNode` view: +0x84 task state, +0x54 position, +0x04
  cursor, +0x08 continuation).
- `g_xformEntityIdx` -> an **angle / transform-input record**. The
  `NodeApplyTransform_{A,B,C}` handlers read three 16.16 rotation
  angles from its `+0x00 / +0x04 / +0x08` and write a 3x3 matrix to the
  `g_currentNodeIdx` node (see [scenegraph.md](scenegraph.md)).

So the same byte offset can mean different things depending on which
cursor reached the record. The `ScenegraphNode` fields apply to the
**task/scene node** view; do not assume +0x04/+0x08 are the
cursor/continuation when the access goes through `g_xformEntityIdx`
(there they are rotation angles). When in doubt, check which global
indexed the `*4`.

## What this view adds over `ScenegraphNode`

scenegraph.md already names the render-struct fields. The cross-cutting
findings that belong here, not there:

| Off  | Finding | Note |
|-----:|---------|------|
| +0x04 | also the task **work cursor** | scenegraph.h calls it `self_ref` (scratch); the screen FSMs use it as a child-alloc bump pointer (`[esi+4]` read, write `node[cursor]`, inc, store). Same slot, task-layer reuse. |
| +0x08 | also the task **FSM continuation** | scenegraph.h calls it `alloc_type` (g_pendingNodeType at birth); the task layer overwrites it with `OFFSET <label>` (the resume point) once running. |
| +0x38 | **polymorphic user-state slot** | scenegraph.h keeps it unnamed (`_38`). In some node types it holds a node ref used as the xform / distance anchor (read as `[edx*4 + ...]` in `HitContactDispatcherCluster`); in others it is a plain 16.16 scalar (`ChainStoreCmpJmp_0049b850` sets it to `0xffffb334` and deltas it against a 0.1 threshold). So it is **not** a universal "parent" field - meaning depends on node type. (I briefly named it `parent`; reverted after finding the scalar usage.) |
| +0x54/+0x58/+0x5c | **axis roles** (refines scenegraph's position_x/y/z) | `HitContactDispatcherCluster` range-checks `dx*dx + dz*dz <= g_rangeSqLimit` using only X(+0x54) and Z(+0x5c) - the **horizontal floor plane** - while **gravity integrates on Y(+0x58)** (`add [n+0x58],0x1999`). So +0x58 is vertical/height, +0x54/+0x5c the ground plane. |
| +0x74 | move_state **value space** | scenegraph.h has `fsm_state` (0x501 sentinel). Written values cluster as `category<<8 | variant`: `0x404/0x406`, `0x501/0x502`, `0x1000/0x1002`, `0x4004`, `0x10b`, `0x112`. |
| +0x84 | task-FSM state is **multi-valued** | scenegraph.h calls it `install_flag` (0/1); the screen/mode FSMs dispatch it across 0/1/2/3 - it is the cooperative task-FSM dispatch state, not just a 0/1 flag (see pattern below). |

## Cooperative task-FSM pattern (how to read the combat code)

This is **the** idiom of the `game` cluster - hundreds of the naked
`MStack* / CallPause* / InstallSelf* / *Cluster / *Fsm` functions are
instances of it. Understanding it makes them readable even before
they are individually named.

A node is a **cooperative task**. Each frame the scheduler invokes the
node's current handler; the handler runs until it decides to "sleep
until next frame", at which point it registers a continuation and
yields. Canonical shape (verified in `HitFsmCluster_00437300`,
`ContinueScreenFsm`, `GameMode_EnterScene`, `EnduranceMode_Handler`,
the screen drawers):

```c
void Handler(void) {
    int st = node->state;   // +0x84, READ-AND-CLEARED (node->state = 0)
    if (st == 0) {                       // first/active entry: do the work
        ... ;
        node->resume      = &Handler + (1 << 24);  // +0x08: continuation,
                                                    //  state tag in top byte
        node->work_cursor = ... ;                   // +0x04 child bump ptr
        node->state       = 1;                      // +0x84: next phase
        g_framePauseFlag  = 1;                       // YIELD this frame
        return;
    }
    // st == 1: HitReactionStateCluster()/next phase, etc.
}
```

Key mechanics:
- **`node->state` (+0x84)** is read **and zeroed** on entry, then the
  switch runs - so a handler that wants to re-run a phase must re-set
  it. `sub eax,0 / dec eax / dec eax ...` is the compiled switch.
- **`node->resume` (+0x08)** stores the re-entry point. The constant
  added to `OFFSET label` (`+0x1000000` / `+0x2000000` / `+0x3000000`)
  packs a **phase tag in the top byte** of the continuation pointer.
- **`g_framePauseFlag`** is the cooperative **yield signal**: once a
  handler sets it, every caller up the chain checks
  `if (g_framePauseFlag) return;` and unwinds without advancing - so
  the whole call stack suspends until next frame. (This is why almost
  every combat function is peppered with that check after each call.)
- The `InstallSelf*` / `Push16Call` / `MStackPush*` helpers are the
  scheduler plumbing that registers/runs these continuations.

## Hot fields ranked by access count (reconciled with scenegraph.h)

Ranked highest-traffic first. Most rows are now named in
[scenegraph.h](../../include/engine/scenegraph.h) (allocator-birth
fields, the AuxVec3 triple, the child refs); the names below are the
**render/base-node view** and high counts likely fold in other-view
reuse (polymorphism). Rows flagged **genuinely TBD** have no name in
the header yet - those are the recommended next targets for combat-FSM
RE, since naming the busiest unlocks the most call sites:

| Off  | Accesses | Notes / hypothesis (unconfirmed) |
|-----:|---------:|----------------------------------|
| +0x30 | 1652 | **player_id** (1..4) on the player view, per [combat_fsm.md](combat_fsm.md)'s GameTick scan; generic register scratch on other node views. |
| +0x34 | 1556 | **state_mask** (OR'd with `0x1000` when on-screen) on the player view, per [combat_fsm.md](combat_fsm.md). (An earlier guess here of "velocity delta" from write-constants was wrong - the GameTick reading is authoritative.) |
| +0x70 | 1018 | **vertical velocity accumulator** in the ballistic / fight-group node view (see "Ballistic integration loop" below). Still polymorphic - the small signed 16.16 deltas (`0xffffe148`=-0.12, `0xffffaaab`=-0.33) seen elsewhere are not necessarily the same role. |
| +0x18 | 1012 | scenegraph.h `child_chain` - written at alloc from `g_eventQueueChild` (render-node view); high traffic likely includes other-view reuse. |
| +0x28 |  970 | scenegraph.h `queue_idx` - written at alloc from `g_eventQueueIdx`. |
| +0x64 |  910 | scenegraph.h `AuxVec3Node.aux_y` (secondary vec3 Y, +0x60/+0x64/+0x68); plain `_60[]` user state on the base view. |
| +0x6c |  834 | **TBD, strong lead** - horizontal facing/offset component (see "+0x6c facing lead" below). |
| +0x48 |  822 | first of scenegraph.h's `_48[3]`. `ScaledMove48to58_00490720` copies it directly into `position_y` (+0x58) - a staged/next-Y committed to the live Y position; combat_fsm.md notes +0x40/+0x48 read together in some walkers. (Polymorphic `_48` slot - meaning likely varies by node type, like +0x38.) |
| +0x68 |  795 | scenegraph.h `AuxVec3Node.aux_z` (secondary vec3 Z). |
| +0x38 |  757 | polymorphic user state (anchor ref vs 16.16 scalar) - see cross-cutting table above. |
| +0x14 |  552 | scenegraph.h `not_mask` - written at alloc from `g_eventQueueNotMask`. |
| +0x40 |  544 | scenegraph.h `child_b` (render view) / `FightGroupNode.bits` (fight-group view, shr+mask). |
| +0x24 |  503 | scenegraph.h `queue_end` - written at alloc from `g_eventQueueEnd`; read in RenderSceneNode. |
| +0x4c |  468 | **genuinely TBD** - tail of scenegraph.h's `_48[3]` region. |
| +0x1c |  423 | scenegraph.h `alloc_flags` - written at alloc from `g_currentNodeFlags`. |
| +0x10 |  419 | scenegraph.h `_10` - cleared by the allocator; live meaning **TBD**. |
| +0x44 |  414 | scenegraph.h `child_c` (third child reference). |

(Counts are from a grep of `[reg*4 + 0xNN]` across `src/`; they
under-count `reg+disp` accesses where the base is already the node
address, so treat them as relative weights, not exact totals.)

## Ballistic integration loop (+0x70 vertical velocity, fight-group view)

Two independent fight-group handlers (`phase1_chain_advance_call_scale`
and a `pending_match_variants` continuation, both keyed on
`g_fightGroupHead`) run the same per-frame loop that pins +0x70 as a
**vertical velocity** integrated against the Y position +0x58:

```c
node->vel_y += delta;             // +0x70 accumulate (g_dispatchSave621 / 0x106)
if (node->vel_y < 0) goto skip;   // js: nothing more while rising
node->position_y += 0x1999;       // +0x58 += ~0.1  (the gravity constant)
if (node->position_y <= 0) goto skip;   // still at/under the floor
... play landing sound (0x28A / 0x106) ...
if (g_xformDirtyFlags & 1)
    node->vel_y = fixmul(node->vel_y, RESTITUTION);  // +0x70 *= ~ -0.6 / -0.7
```

Evidence (16.16 fixed-point constants, `Mul10Tail_00404af0` =
fixed-point multiply):
- `0x1999` = +0.0999 -> the gravity increment on Y (+0x58), the same
  constant `HitContactDispatcherCluster` uses (see axis-roles row).
- `0xffff6667` = -0.60 and `0xffff4ccd` = -0.70 -> restitution / bounce
  damping multiplied into +0x70 on floor contact (negative => velocity
  reverses, magnitude < 1 => energy loss).
- `0xfd70` = +0.99 -> an air-drag factor multiplied into the
  **+0x78 / +0x7c / +0x80 triple** in the same loop, all three scaled by
  the identical 0.99 each frame. A uniformly drag-damped 3-vector that
  pairs with the +0x70 vertical term (the linear vs angular-velocity
  distinction is unconfirmed - the consuming position/rotation update is
  not in this loop).

This triple is a sharp polymorphism example: on the **player view**
(`g_baseSel`) the very same +0x7c and +0x80 slots are **counters** - a
`pending_match_variants` handler compares `node[+0x80]` against `0x6666`
and `node[+0x7c]` against `3`, then zeroes them - nothing to do with the
drag-damped fight-group vector. So +0x78/+0x7c/+0x80 are a motion vector
in the thrown-object view and unrelated counters in the player view; do
not name them globally.

So in this node type the motion model **is** a `pos += vel; vel +=
gravity` ballistic integrator with restitution - the one place a real
velocity field exists, contradicting nothing in the TODOs (which note
that *character* motion is pose/transform-driven; this is a thrown /
falling object, a different node type). Per the polymorphism rule the
+0x70 = velocity meaning is asserted only for this fight-group / thrown
node view, not universally.

## +0x6c facing lead (TBD, two converging clues)

+0x6c is unnamed in scenegraph.h but two independent contexts point at
a **horizontal facing / direction component** in the fighter-vs-fighter
math (not yet confident enough to name):

1. **Round start** (`round_start_cluster_variants` ~0x319): two nodes
   (`g_eventQueueEnd` and `g_eventQueueIdx`) get +0x6c set to
   `0x62e97` and `0xfff9d169` - **equal and opposite** (+/-405143,
   ~+/-6.18 in 16.16). A symmetric left/right placement of the two
   combatants. (A sister round-start branch zeroes both instead.)
2. **Per-player tick** (`helper_per_player_tick` ~0x277/0x323): +0x6c
   is read, and if zero falls back to +0x74 (`fsm_state`); the value is
   combined with the `g_fightAxisPosX/PosY/NegX/NegY` globals
   (`0x535e70..0x535e7c`) through an abs-sum + sign test that yields
   `0x10000` / `0xffff0000` (= +1.0 / -1.0 in 16.16) - a left/right
   **facing sign**. Consumed elsewhere via `add ecx, [n+0x6c]`
   accumulation (`pending_match_variants`) and a `dual_sub_from_field`
   subtract.

Hypothesis: a per-node horizontal facing / X-offset feeding the
inter-fighter direction computation. Left TBD pending a writer that
pins whether it is a position delta, a facing vector, or a knockback
direction.

## How to pin a field (method)

1. `grep -rn "\\*4 + 0xNN\\]" src/` to collect every read/write site.
2. Separate reads from writes; note the constants written and the
   helpers called nearby.
3. Cross-check against a function whose role is already known (a named
   `*_Handler` / `Screen_*`) to anchor the meaning in context.
4. Only name the field once the usage is unambiguous - per the project
   rule, an `+0xNN (TBD)` is better than a wrong field name.

## TODOs

- ~~Pin +0x54/+0x58/+0x5c~~ - DONE: position X/Y/Z, 16.16 (axes
  confirmed via the HitContactDispatcher floor-plane range check).
- ~~"velocity" at +0x34~~ - SETTLED: +0x34 is a **state_mask**, not a
  velocity (GameTick reading). *Character* motion is transform/pose-driven
  (`ik_chain_pose_update`, `pose_blend_driver`, `geo_transform_*`), not
  a simple `pos += vel`. But a real velocity field DOES exist for the
  thrown / ballistic node type at **+0x70** (vel_y), integrated against
  +0x58 with gravity `0x1999` and restitution multipliers - see the
  "Ballistic integration loop" section above.
- **Health field**: `HealthBarTickDriver` reads the first dword of the
  per-player block (`g_player1State`/`g_player2State`); damage reaches
  it via the node-pointer path inside the layered hit FSMs
  (`HitFsmCluster` -> `HitReactionStateCluster` -> ...), not a direct
  global decrement - trace that chain to pin true-health vs bar-value.
- Emit a real C `struct` once enough fields are pinned, so the
  combat-FSM bodies can be read against named members instead of raw
  offsets.
