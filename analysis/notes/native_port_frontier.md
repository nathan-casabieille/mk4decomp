# Native-port frontier roadmap (generated 2026-06-11)

MK4.native.full links 114 engine files + a weak stub frontier of 135 functions
+ 174 fixed-VA globals. To grow the native frame, convert these naked frontier
functions to verified twins (verify_coexec) in fan-in priority. Higher refs =
unblocks more of the closure when converted.

## Top frontier functions by fan-in

| refs | size | function | dedicated file |
|---|---|---|---|
| 28 | 674 | MStackBracket7_DispatchAndChain | src/engine/region_flush_chain.c |
| 28 | 226 | MStackPush2RunCountdown | (giant/none - needs split) |
| 27 | 148 | ChainDirtyBitWalker | (giant/none - needs split) |
| 27 | 160 | GuardedChainCmpDualBitXor | (giant/none - needs split) |
| 26 | 208 | MStackPush3CmpCall | (giant/none - needs split) |
| 26 | 197 | TaggedSceneDispatch | (giant/none - needs split) |
| 24 | 261 | BootMod6487eClampAndChainMul10 | (giant/none - needs split) |
| 24 | 306 | ChainTableWalkStore | (giant/none - needs split) |
| 24 | 97 | DirtyToggleByGate | (giant/none - needs split) |
| 24 | 11 | LoadGeoAsset_Default | src/engine/geo.c |
| 24 | 150 | MStackPushVec3Mul10 | (giant/none - needs split) |
| 12 | 296 | MStackPush2ChainPrepend | (giant/none - needs split) |
| 8 | 187 | StateDispatchYield | (giant/none - needs split) |
| 7 | 105 | DirtyDoubleDeref | (giant/none - needs split) |
| 7 | 226 | StateGateMStackOverlap | src/engine/install_self_with_body.c |
| 6 | 120 | DualSetShiftCall | src/engine/dual_set_shift_call.c |
| 6 | 243 | MStackPush2ChainInsert | src/boot/m_stack_push2_chain_insert.c |
| 6 | 224 | MStackPush4IndirectCall | src/engine/m_stack_push4_indirect_call.c |
| 5 | 205 | Cascade5StageInit | src/engine/cascade5_stage_init.c |
| 5 | 97 | CountdownClampWalk | (giant/none - needs split) |
| 5 | 688 | MStackChainInstallDispatch | src/engine/m_stack_chain_install_dispatch.c |
| 5 | 80 | PackedListVisitor | src/engine/packed_list_visitor.c |
| 4 | 930 | CharSelectFsmCluster | (giant/none - needs split) |
| 4 | 174 | EsiInstallChainCallIndirect | src/engine/esi_install_chain_call_indirect.c |
| 4 | 337 | FightFrameStep_Inner | src/engine/fight_frame_step.c |
| 4 | 3825 | FlushDrawQueue | src/engine/flush_draw_queue.c |
| 4 | 625 | HitReactionDispatcher | (giant/none - needs split) |
| 4 | 660 | PreFightInstallCluster | src/engine/node_walk_pose_update.c |
| 4 | 304 | PrefixThunkInstallSelf3State | (giant/none - needs split) |
| 4 | 399 | SelfInstallPhaseDispatch_StackPopDispatchTagged | src/boot/m_stack_push_triple_fields.c |
| 3 | 383 | AlarmCountdownInstall | src/engine/alarm_countdown_install.c |
| 3 | 324 | AudioBridgeMStackChainCopy | src/engine/audio_bridge_m_stack_chain_copy.c |
| 3 | 73 | AudioMixerStep | src/audio/audio_mixer_step.c |
| 3 | 219 | ByteWordTableTaggedDispatch | (giant/none - needs split) |
| 3 | 599 | CameraAimSplineDriver | (giant/none - needs split) |

## The 174 fixed-VA global stubs

These are the named-global memory-model decision: under MK4_NATIVE_FULL they are
4-byte weak placeholders (engine_autostubs.c), so the running native-full uses
zeroed state for them. Correct fix = route through the arena seam (real data at
real VAs) - the open decision in this file above. Until then native-full runs but
with hollow global state.

## Coupling note

The high-fan-in frontier is a tightly-coupled web (ChainDirtyBitWalker, the
MStack* dispatchers, file I/O via Helper_Sprintf/FSYS_*, Mem_Malloc/Mem_Free).
Converting one often pulls others, and many do file I/O (not co-exec-verifiable).
Recommended order: (1) the leaf compute/node-walk functions with dedicated files
and no I/O (verifiable), (2) Mem_Malloc/Mem_Free + FSYS_* as host-backed shims,
(3) the MStack dispatchers, (4) split the giant-dispatch-only symbols to pure-C.
