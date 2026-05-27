# MK4.EXE - The node / task struct (the `*4` pool)

Almost every gameplay, scene and screen-FSM function in the engine
operates on records drawn from one shared **node pool**, addressed
through the engine's "packed pointer" convention. This is the single
most load-bearing data structure in the binary: a field-access tally
across the decompiled source finds `[reg*4 + 0x84]` alone referenced
**8110** times, and the next dozen offsets thousands more.

This note consolidates the node-field knowledge that was scattered
across [scenegraph.md](scenegraph.md) (render/transform view) and
[combat_fsm.md](combat_fsm.md) (fight view), adds the FSM-task fields
verified while mapping the menu/mode/screen handlers
([menu_state.md](menu_state.md), [fight_flow.md](fight_flow.md)), and
ranks every field by how often it is touched - which doubles as a
priority list for future combat-FSM reverse engineering.

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

## Caveat: multiple record views over the same `*4` pool

The packed-pointer convention is used for **more than one record
shape**, and the cursor that selects the view differs:

- `g_baseSel` / `g_currentNodeIdx` -> the **task / scene node** (the
  fields tabled below: +0x84 FSM state, +0x54 position, +0x04 cursor,
  +0x08 continuation).
- `g_xformEntityIdx` -> an **angle / transform-input record**. The
  `NodeApplyTransform_{A,B,C}` handlers read three 16.16 rotation
  angles from its `+0x00 / +0x04 / +0x08` and write a 3x3 matrix to the
  `g_currentNodeIdx` node (see [scenegraph.md](scenegraph.md)).

So the same byte offset can mean different things depending on which
cursor reached the record. The field table below is the **task/scene
node** view; do not assume +0x04/+0x08 are the cursor/continuation
when the access goes through `g_xformEntityIdx` (there they are
rotation angles). When in doubt, check which global indexed the `*4`.

## One pool, two roles

The same record serves simultaneously as:
- a **scenegraph render node** (transform/flags/children - the view in
  scenegraph.md), and
- a **task / FSM actor** (a co-operative per-frame state machine with
  its own re-entry continuation - the view used by every
  `*_Handler` / `*Screen` / `*Fsm` function).

The struct is at least **~0x88 bytes** (the highest field seen is
`+0x84`). scenegraph.md's earlier "at least 0x48 bytes" was a lower
bound from the render-only view.

## Established fields

| Off  | Field | Evidence |
|-----:|-------|----------|
| +0x04 | child-alloc / work cursor | screen FSMs read it, write `node[cursor]`, `inc`, store back (e.g. `ContinueScreenFsm`/`GameMode_EnterScene`) - a bump pointer used to append child nodes |
| +0x08 | FSM re-entry continuation | stores `OFFSET <label>` or a function pointer (e.g. `OFFSET AudioPreloadStreamingTrack`); the task resumes here next frame |
| +0x20 | flag word (node type/mode bits) | [scenegraph.md](scenegraph.md): `(flags>>24)&7` = type, bit 0x100 = mode; drives the 16-entry transform dispatch |
| +0x3c..+0x44 | up to 3 child-node refs | [scenegraph.md](scenegraph.md): recursive `RenderSceneNode` descent |
| +0x38 | linked / anchor node ref (packed index) | read then used as a node pointer: `mov edx,[n+0x38]; ... [edx*4 + 0x54]`. In `HitContactDispatcherCluster` it is the anchor the moving node's distance is measured against (owner / opponent / leash anchor - exact role TBD). Distinct from the +0x3c..+0x44 child refs. |
| +0x54 / +0x58 / +0x5c | **position: X (ground) / Y (vertical) / Z (depth), 16.16 fixed-point** | `BulletVolleySpawner` lays a row of projectiles at `+0x54` = stepping X (`+0x120000`=+18.0 each) with `+0x58` = constant Y (`0xffb00000`=-80.0) - a spatial layout. **Axis roles confirmed** by `HitContactDispatcherCluster`: it advances `+0x54`/`+0x5c`, then range-checks `dx*dx + dz*dz <= g_rangeSqLimit` using only X(+0x54) and Z(+0x5c) - the horizontal ground plane - while **gravity integrates on +0x58** (`add [n+0x58], 0x1999`). So +0x58 is the vertical axis, +0x54/+0x5c the floor plane. |
| +0x74 | pose / move_state (packed enum) | [combat_fsm.md](combat_fsm.md): `0x501` = the special "victory pose / fatality" sentinel. Written values cluster into categories with a low-byte variant - `0x404/0x406`, `0x501/0x502`, `0x1000/0x1002`, `0x4004`, `0x10b`, `0x112` - i.e. a packed move/animation-state code (`category << 8 | variant`). Distinct from the +0x84 task-FSM state. |
| +0x84 | **per-node task-FSM state** | read-and-clear dispatch (`eax = [n+0x84]; [n+0x84]=0; sub eax,0/dec eax/...`) in every task handler - `GameMode_EnterScene`, `EnduranceMode_Handler`, `ContinueScreenFsm`, the screen drawers. The most-accessed field in the binary. |

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

## Hot fields still TBD (ranked by access count)

These are referenced thousands of times but their meaning is not yet
pinned. Listed highest-traffic first - this is the recommended order
for future combat-FSM RE, since naming the busiest fields unlocks the
most call sites:

| Off  | Accesses | Notes / hypothesis (unconfirmed) |
|-----:|---------:|----------------------------------|
| +0x30 | 1652 | **player_id** (1..4) on the player view, per [combat_fsm.md](combat_fsm.md)'s GameTick scan; generic register scratch on other node views. |
| +0x34 | 1556 | **state_mask** (OR'd with `0x1000` when on-screen) on the player view, per [combat_fsm.md](combat_fsm.md). (An earlier guess here of "velocity delta" from write-constants was wrong - the GameTick reading is authoritative.) |
| +0x70 | 1018 | small signed 16.16 deltas (`0xffffe148`=-0.12, `0xffffaaab`=-0.33) - a rate/offset, role unconfirmed |
| +0x18 | 1012 | |
| +0x28 |  970 | |
| +0x64 |  910 | |
| +0x6c |  834 | |
| +0x48 |  822 | (combat_fsm.md notes +0x40/+0x48 are read together in some walkers) |
| +0x68 |  795 | |
| +0x38 |  757 | |
| +0x14 |  552 | |
| +0x40 |  544 | |
| +0x24 |  503 | [scenegraph.md] reads this in RenderSceneNode |
| +0x4c |  468 | |
| +0x1c |  423 | |
| +0x10 |  419 | [scenegraph.md] reads this (dword index 4) |
| +0x44 |  414 | child ref (see above) |

(Counts are from a grep of `[reg*4 + 0xNN]` across `src/`; they
under-count `reg+disp` accesses where the base is already the node
address, so treat them as relative weights, not exact totals.)

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
  velocity (GameTick reading). Node motion is transform/pose-driven
  (`ik_chain_pose_update`, `pose_blend_driver`, `geo_transform_*`), not
  a simple `pos += vel`, so there is no single velocity field to pin.
- **Health field**: `HealthBarTickDriver` reads the first dword of the
  per-player block (`g_player1State`/`g_player2State`); damage reaches
  it via the node-pointer path inside the layered hit FSMs
  (`HitFsmCluster` -> `HitReactionStateCluster` -> ...), not a direct
  global decrement - trace that chain to pin true-health vs bar-value.
- Emit a real C `struct` once enough fields are pinned, so the
  combat-FSM bodies can be read against named members instead of raw
  offsets.
