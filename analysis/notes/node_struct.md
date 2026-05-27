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
| +0x54 / +0x58 / +0x5c | **position vector (X / Y / Z), 16.16 fixed-point** | `BulletVolleySpawner` lays a row of projectiles at `+0x54` = stepping X (`base + 0x120000`=+18.0 each) with `+0x58` = constant Y (`0xffb00000`=-80.0) - a spatial layout, i.e. positions not velocities. Gravity drifts the node via `add [n+0x58], 0x1999` (+0.1/frame). Read into coordinate math at 15-19 sites each (`add reg, [n+0x5x]`). Set as a group by spawn/physics/anim code. |
| +0x74 | pose / animation state | [combat_fsm.md](combat_fsm.md): writing `0x501` forces a fatal pose |
| +0x84 | **per-node FSM state** | read-and-clear dispatch (`eax = [n+0x84]; [n+0x84]=0; sub eax,0/dec eax/...`) in every task handler - `GameMode_EnterScene`, `EnduranceMode_Handler`, `ContinueScreenFsm`, the screen drawers. The most-accessed field in the binary. |

The task-handler idiom that ties +0x84 / +0x08 / +0x04 together:

```c
switch (node->state /* +0x84 */) {     // read-and-cleared each entry
case 0: ... break;                      // first entry: set up
case 1: node->resume = &&LABEL;         // +0x08 continuation
        node->state  = 2;               // advance; yield (g_framePauseFlag=1)
        ...
}
```

## Hot fields still TBD (ranked by access count)

These are referenced thousands of times but their meaning is not yet
pinned. Listed highest-traffic first - this is the recommended order
for future combat-FSM RE, since naming the busiest fields unlocks the
most call sites:

| Off  | Accesses | Notes / hypothesis (unconfirmed) |
|-----:|---------:|----------------------------------|
| +0x30 | 1652 | mostly register stores, no distinctive constants - generic scratch/state |
| +0x34 | 1556 | small signed 16.16 deltas written (`0xa3d`=+0.04, `0x20000`=+2.0, `0xfffff5c3`=-0.04) - likely a velocity / rate component (unconfirmed) |
| +0x70 | 1018 | small signed 16.16 deltas (`0xffffe148`=-0.12, `0xffffaaab`=-0.33) - likely a velocity / rate component (unconfirmed) |
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

- ~~Pin +0x54/+0x58/+0x5c~~ - DONE: position (X/Y/Z), 16.16. Next: find
  the per-frame `pos += vel` integration to pin the **velocity** vector
  (the small signed-delta fields +0x34 / +0x70 are the prime suspects).
- Confirm whether +0x34 / +0x70 are the velocity components by locating
  the frame update that adds them into +0x54/+0x58/+0x5c.
- Emit a real C `struct` once enough fields are pinned, so the
  combat-FSM bodies can be read against named members instead of raw
  offsets.
