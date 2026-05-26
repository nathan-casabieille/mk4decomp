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

## Known opcodes

| Opcode | Handler | Effect |
|-------:|---------|--------|
| `0xdd` | `ConditionalAcc4or3_0045e0b0` | Set `g_acc` to 4, or 3 if `g_xformScratch2088` is set. |
| `0xaa` | `ConditionalAcc3or4_0045e0d0` | Set `g_acc` to 3, or 4 if `g_xformScratch2088` is set. |
| (others) | via `g_eventHandlerTable_004e9ea8` | Dispatched through `Event_InvokeHandler`; individual handler roles not yet mapped. |

## TODOs

- **Opcode catalog**. Only `0xdd`/`0xaa` are decoded above. The full
  set lives in `g_eventHandlerTable_004e9ea8` - dumping that table
  (entries are packed pointers, multiply by 4 to get the VA) would
  enumerate every scripted-event opcode and let each handler be named.
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
