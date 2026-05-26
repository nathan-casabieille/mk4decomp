# MK4.EXE - Event queue + scripted-event decoder

The engine drives scripted behaviour (fatalities, intros, special-move
scripts, stage hits, timed state changes) through a small **event
queue** plus a per-node **(opcode, arg) byte-stream decoder**. This is
the layer that the fight FSM ([combat_fsm.md](combat_fsm.md)) and the
scenegraph ([scenegraph.md](scenegraph.md)) feed work into each frame.

## Two layers

```
   LAYER 1 - the event queue (a 20-slot packed-ptr ring)

   DispatchEventQueue          0x0045c820
     g_xformEntityIdx = g_eventQueueActive       ; drain cursor = active read pos
     g_eventQueueTotal = (&g_eventQueueRing + 80) >> 2   ; pin ring end
     -> EventQueueDrainLoop                       ; tail call

   EventQueueDrainLoop         0x0045c840
     while (g_eventQueueHead != g_xformEntityIdx):
        node = g_evtRingTable[g_xformEntityIdx]
        g_eventQueueWorkType = 0x11               ; node kind = "event"
        g_pendingNodeType    = node
        AllocNode()                               ; materialize the event node
        if (g_framePauseFlag) break               ; pause aborts mid-drain
        g_evtRingSlot[g_xformEntityIdx] = 0        ; consume the slot
        if (++g_xformEntityIdx == g_eventQueueTotal)
            g_xformEntityIdx = (&g_eventQueueRing >> 2)   ; wrap
     DispatchEventQueue_Commit()                   ; active = pending

   DispatchEventQueue_Commit   0x0045c8d0
     g_eventQueueActive = g_eventQueuePending      ; publish the new tail


   LAYER 2 - the per-node (opcode, arg) decoder

   EventGateCluster (anchor)   0x0045e1e0
     g_eventQueueTotal = entity[+0x64]             ; load this entity's
     g_eventQueueEnd   = entity[+0x68]             ;   script cursor pair
     -> EventPacketDecoder                         ; tail jmp

   EventPacketDecoder          0x0045de60
     read (op, arg) words from the packed stream at g_currentNodeIdx
     op == 0xdd -> ConditionalAcc4or3              ; acc = scratch ? 3 : 4
     op == 0xaa -> ConditionalAcc3or4              ; acc = scratch ? 4 : 3
     other ops  -> collision / state-flag checks against
                   g_player1NodeIdx, g_fightGroupHead, g_fightTableC0
     dispatch a handler via Event_InvokeHandler / EventGateCluster subs

   Event_InvokeHandler         0x0045e100
     push 3 decoder-state words onto the matrix stack (cursor, queue
       total, walk callback)
     handler = g_eventHandlerTable_004e9ea8[g_eventQueueCurrent]
     call handler
     pop the 3 saved words back
     if (!dirty) -> IncJmp                          ; advance + re-decode

   IncJmp                      0x0045e1d0
     g_decodeCursor++                               ; (g_scaledInit_00542044)
     -> EventGateCluster                            ; re-enter the decoder
```

## Functions

| Address    | Name                              | Size (b) | Role |
|------------|-----------------------------------|---------:|------|
| 0x0045c820 | `DispatchEventQueue`              |      170 | Seeds the drain cursor from `g_eventQueueActive`, pins the ring end, tail-calls the drain loop. |
| 0x0045c840 | `EventQueueDrainLoop_0045c840`    |      138 | Walks the ring from the cursor to `g_eventQueueHead`, materializes each queued event node (`AllocNode`, node-kind 0x11), consumes the slot, wraps at the ring end. Aborts mid-walk if `g_framePauseFlag` is set. Commits at the end. |
| 0x0045c8d0 | `DispatchEventQueue_Commit`       |       11 | `g_eventQueueActive = g_eventQueuePending` - publishes the queue tail produced this frame. |
| 0x0045de60 | `EventPacketDecoder_0045de60`     |      582 | Decodes the per-node `(opcode, arg)` packed-pointer stream at `g_currentNodeIdx`. Recognizes opcodes `0xdd`/`0xaa` (accumulator presets) plus a set of collision / fighter-state-flag checks; dispatches matched opcodes to their handlers. |
| 0x0045e0b0 | `ConditionalAcc4or3_0045e0b0`     |       30 | `g_acc = 4; if (g_xformScratch2088) g_acc = 3;` - opcode `0xdd` helper. |
| 0x0045e0d0 | `ConditionalAcc3or4_0045e0d0`     |       30 | Mirror: default 3, override 4 - opcode `0xaa` helper. |
| 0x0045e100 | `Event_InvokeHandler_0045e100`    |      201 | Saves the 3 live decoder-state words on the matrix stack, indirect-calls the per-opcode handler from `g_eventHandlerTable_004e9ea8[g_eventQueueCurrent]`, restores them, and (unless the frame went dirty) tail-jumps to `IncJmp` to advance. (Was `MStackPush3IndirectCall_0045e100`.) |
| 0x0045e1d0 | `IncJmp_0045e1d0`                  |       11 | Increments the decode cursor (`g_scaledInit_00542044`) and re-enters `EventGateCluster`. The decoder's per-opcode 'advance and continue'. |
| 0x0045e1e0 | `EventGateCluster_0045e1e0`       |      942 | Packed cluster of event-driven sub-functions. Anchor: loads the current entity's script cursor pair from `entity[+0x64]/[+0x68]` into `g_eventQueueTotal/End` and jumps into `EventPacketDecoder`. Following sub-functions (NOP-separated) are `TripleEntryGate` + frame-pause + fight-tick gates that arm per-frame fighter state. (Was the misnamed `InputCheckCluster_0045e1e0`.) |

## Globals

| VA           | Name                                | Meaning |
|--------------|-------------------------------------|---------|
| `0x0053a4b8` | `g_eventQueueDrainBase_0053a4b8`    | Base of the 20-slot packed-pointer ring (0x0053a4b8..0x0053a508). |
| (state)      | `g_eventQueueHead`                  | Write cursor: where the next produced event lands. The drain loop stops when the read cursor catches up to it. |
| (state)      | `g_eventQueueActive`                | Read position used to seed the drain cursor each frame. |
| (state)      | `g_eventQueuePending`               | Tail produced during the current drain; promoted to Active by `DispatchEventQueue_Commit`. |
| (state)      | `g_xformEntityIdx`                  | The live drain cursor (doubles as the scenegraph entity index - the event queue piggy-backs on the transform walker's cursor slot). |
| (state)      | `g_eventQueueTotal`                 | Ring-end packed pointer (wrap target); also reused by the decoder as the per-entity script-cursor end. |
| (state)      | `g_eventQueueEnd`                   | Scratch copy of the head / per-entity cursor used during a step. |
| (state)      | `g_eventQueueCurrent`               | Current opcode / event ID - the index into `g_eventHandlerTable_004e9ea8`. |
| (state)      | `g_eventQueueWorkType`              | Node-kind tag written before `AllocNode` (0x11 = event node). |
| (state)      | `g_eventQueueChild`                 | Set to 0x1c20 by some opcode handlers (child node / channel id). |
| `0x004e9ea8` | `g_eventHandlerTable_004e9ea8`      | Function-pointer table indexed by `g_eventQueueCurrent`; entries are packed pointers (`base>>2 + cursor`). The per-opcode handler set. |
| `0x00542044` | `g_scaledInit_00542044`             | The decoder's packed read cursor into the `(op, arg)` stream. Incremented by `IncJmp`. |
| `0x00542078` | `g_acc_00542078`                    | Decoder accumulator preset by the `0xdd`/`0xaa` opcode helpers. |
| `0x00542060` | `g_baseSel_00542060`                | Selected entity base used by `EventGateCluster`'s anchor to fetch the per-entity script cursor. |

## The opcode dispatch table (g_eventHandlerTable_004e9ea8)

Extracted directly from `MK4.EXE` (.rdata, file offset 0xe7ca8). The
table is **113 dword slots** (opcodes `0x00`..`0x70`), indexed by
`g_eventQueueCurrent`. 84 slots are live, pointing at **71 distinct
handlers**; the remaining 29 slots are NULL (no-op opcodes). Handlers
span `0x45e210`..`0x48e0d0`, almost all inside the event-helper
cluster at `0x45exxx`.

Structural observations:
- **Opcode 0x00 is NULL** - opcode 0 = end/no-op (matches the decoder
  treating a zero op as stream terminator).
- **`0x48e0d0` is a shared catch-all**, reused by 8 opcodes
  (`0x56, 0x59, 0x5c, 0x5d, 0x60`..`0x65`). It sits 16 bytes before
  `SlotPhaseResetInstallChain_0048e0e0` and is almost certainly the
  default 'ignore this opcode' stub.
- **Opcode pairs 0x10 apart share a handler**: `0x37`/`0x47`,
  `0x38`/`0x48`, `0x3b`/`0x4b`, `0x3f`/`0x4f` each point at the same
  function. Suggests a per-player (or per-mode) opcode bank where the
  high nibble selects the actor and the low nibble selects the action.
- The named handlers below still carry shape-names (`SetJmp_`,
  `GuardedDispatch_`, ...) - the table tells us *which opcode maps to
  which handler*, but the per-handler in-game effect is still TODO.

| Opcode | Handler VA | Symbol |
|------:|-----------|--------|
| 0x01 | `0x0045f2d0` | (unnamed) |
| 0x02 | `0x0045f020` | (unnamed) |
| 0x03 | `0x0045efb0` | (unnamed) |
| 0x04 | `0x0045ede0` | `DualStreamSqDistThresh_0045ede0` |
| 0x05 | `0x0045f210` | (unnamed) |
| 0x06 | `0x0045edd0` | (unnamed) |
| 0x07 | `0x0045f120` | (unnamed) |
| 0x08 | `0x0045ed40` | (unnamed) |
| 0x09 | `0x0045ec70` | (unnamed) |
| 0x0a | `0x0045ec50` | (unnamed) |
| 0x0b | `0x0045ec00` | `SetJmp_0045ec00` |
| 0x0c | `0x0045f250` | (unnamed) |
| 0x0d | `0x0045ebe0` | (unnamed) |
| 0x0e | `0x0045ef10` | (unnamed) |
| 0x0f | `0x0045eb70` | (unnamed) |
| 0x10 | `0x0045eab0` | (unnamed) |
| 0x11 | `0x0045eb10` | (unnamed) |
| 0x12 | `0x0045ef80` | (unnamed) |
| 0x13 | `0x0045eba0` | (unnamed) |
| 0x14 | `0x0045ecc0` | (unnamed) |
| 0x15 | `0x0045eac0` | (unnamed) |
| 0x16 | `0x0045ea70` | (unnamed) |
| 0x17 | `0x0045f2c0` | (unnamed) |
| 0x18 | `0x0045ea30` | (unnamed) |
| 0x19 | `0x0045e9f0` | (unnamed) |
| 0x1a | `0x0045e600` | (unnamed) |
| 0x1b | `0x0045e5d0` | `TripleEntryGate_0045e5d0` |
| 0x1c | `0x0045e4c0` | (unnamed) |
| 0x1d | `0x0045e880` | (unnamed) |
| 0x1e | `0x0045e9b0` | (unnamed) |
| 0x1f | `0x0045e970` | (unnamed) |
| 0x20 | `0x0045f180` | (unnamed) |
| 0x21 | `0x0045e930` | (unnamed) |
| 0x22 | `0x0045e840` | (unnamed) |
| 0x23 | `0x0045e800` | (unnamed) |
| 0x24 | `0x0045e770` | (unnamed) |
| 0x25 | `0x0045e590` | `RangeCheckJmp_0045e590` |
| 0x26 | `0x0045e470` | (unnamed) |
| 0x27 | `0x0045e410` | (unnamed) |
| 0x29 | `0x0045e3c0` | (unnamed) |
| 0x2a | `0x0045e350` | (unnamed) |
| 0x2b | `0x0045e300` | (unnamed) |
| 0x2c | `0x0045e2b0` | (unnamed) |
| 0x2d | `0x0045e280` | (unnamed) |
| 0x2e | `0x0045e210` | (unnamed) |
| 0x2f | `0x0045e510` | (unnamed) |
| 0x31 | `0x0045e730` | (unnamed) |
| 0x32 | `0x0045e700` | (unnamed) |
| 0x33 | `0x0045e550` | (unnamed) |
| 0x35 | `0x00460a50` | (unnamed) |
| 0x37 | `0x00460c60` | `CallPauseCallTestStackPushJmp_00460c60` |
| 0x38 | `0x0045fcf0` | `CallPauseMStackPushSet0Jmp_0045fcf0` |
| 0x3b | `0x00460cd0` | `GuardedDispatch_00460cd0` |
| 0x3f | `0x00460ca0` | `GuardedDispatch_00460ca0` |
| 0x47 | `0x00460c60` | `CallPauseCallTestStackPushJmp_00460c60` |
| 0x48 | `0x0045fcf0` | `CallPauseMStackPushSet0Jmp_0045fcf0` |
| 0x4b | `0x00460cd0` | `GuardedDispatch_00460cd0` |
| 0x4f | `0x00460ca0` | `GuardedDispatch_00460ca0` |
| 0x56 | `0x0048e0d0` | (shared catch-all) |
| 0x57 | `0x004604f0` | (unnamed) |
| 0x58 | `0x00460510` | (unnamed) |
| 0x59 | `0x0048e0d0` | (shared catch-all) |
| 0x5a | `0x00460530` | (unnamed) |
| 0x5b | `0x00460550` | (unnamed) |
| 0x5c | `0x0048e0d0` | (shared catch-all) |
| 0x5d | `0x0048e0d0` | (shared catch-all) |
| 0x5e | `0x00460570` | (unnamed) |
| 0x5f | `0x00460590` | (unnamed) |
| 0x60 | `0x0048e0d0` | (shared catch-all) |
| 0x61 | `0x0048e0d0` | (shared catch-all) |
| 0x62 | `0x0048e0d0` | (shared catch-all) |
| 0x63 | `0x0048e0d0` | (shared catch-all) |
| 0x64 | `0x0048e0d0` | (shared catch-all) |
| 0x65 | `0x0048e0d0` | (shared catch-all) |
| 0x66 | `0x00460fa0` | `DualEntryStateGated_00460fa0` |
| 0x67 | `0x00461010` | (unnamed) |
| 0x68 | `0x00460260` | `GuardedDoubleCallSetJmp_00460260` |
| 0x69 | `0x00461090` | `SixEntryYieldThunks_00461090` |
| 0x6a | `0x00461020` | `PushFourCallPopBitJmp_00461020` |
| 0x6c | `0x00461120` | (unnamed) |
| 0x6d | `0x00461130` | (unnamed) |
| 0x6e | `0x00461190` | (unnamed) |
| 0x6f | `0x004611f0` | (unnamed) |
| 0x70 | `0x004611c0` | (unnamed) |

No-op opcodes (NULL slot, decoder ignores): `0x00, 0x28, 0x30, 0x34,
0x36, 0x39, 0x3a, 0x3c, 0x3d, 0x3e, 0x40, 0x41, 0x42, 0x43, 0x44,
0x45, 0x46, 0x49, 0x4a, 0x4c, 0x4d, 0x4e, 0x50, 0x51, 0x52, 0x53,
0x54, 0x55, 0x6b`.

### Accumulator-preset opcodes (decoded inline, not via the table)

| Opcode | Handler | Effect |
|-------:|---------|--------|
| `0xdd` | `ConditionalAcc4or3_0045e0b0` | Set `g_acc` to 4, or 3 if `g_xformScratch2088` is set. |
| `0xaa` | `ConditionalAcc3or4_0045e0d0` | Set `g_acc` to 3, or 4 if `g_xformScratch2088` is set. |

`0xdd` and `0xaa` are handled by an explicit compare in
`EventPacketDecoder` *before* the table lookup, so they sit outside
the `0x00`..`0x70` table range (they are sentinel/escape opcodes).

## TODOs

- ~~**Opcode catalog**~~ - DONE (raw mapping). The full
  `g_eventHandlerTable_004e9ea8` is now dumped above: 113 slots, 84
  live, 71 distinct handlers. What remains is **naming each handler**
  by reverse-engineering its body - they currently carry shape-names.
  Start with the 4 handler-sharing opcode pairs (0x37/0x47 etc) to
  confirm the per-player/per-mode bank theory, and with the
  shared catch-all at `0x48e0d0`.
- **`g_eventQueue*` exact slot semantics**. Head / Active / Pending /
  End / Current are reverse-engineered from access patterns; a runtime
  trace during a fatality (which is the densest event producer) would
  confirm the producer/consumer roles.
- **`EventGateCluster` sub-functions past the anchor**. The anchor is
  identified (event-decode entry); the NOP-separated tail
  sub-functions are `TripleEntryGate`-based fighter-state gates whose
  individual roles need separate analysis. The cluster is one 942-byte
  symbol - splitting it would need the packed-helpers workflow.
- **Relationship to `g_xformScratch2088`**. The `0xdd`/`0xaa` helpers
  branch on it; it appears to be a 'is this the active/attacking
  fighter' flag set elsewhere in the fight tick. Confirm.
- **`Helper_GSM_HandleEvent` (0x004b84d0)** in the menu state machine
  returns event IDs (0x18..0x1c, 0x45) that map to menu states - check
  whether it shares this opcode space or is a separate menu-only event
  channel (see [menu_state.md](menu_state.md)).
