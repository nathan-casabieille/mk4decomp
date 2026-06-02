/**
 * 33 single-instruction tail-call thunks (`jmp Target`).
 *
 * Each compiles to `e9 + rel32` (5 bytes). MSVC SP3 /O2 emits the
 * tail call as `jmp` for a void-returning function whose body is a
 * single call to another void-returning function - no frame setup,
 * no prologue/epilogue. Each is named `Thunk_VA` after its source
 * VA, jumping to the referenced target by name.
 */

/* Externs for thunk targets. */
extern void BootMod6487eClampAndChainMul10(void);     /* 0x00407510 */
extern void MStackPush2ChainPrepend(void);     /* 0x00409970 */
extern void ZeroLargeBlock(void);     /* 0x0041f270 */
extern void BootScheduledNodeTimerWalk(void);     /* 0x0041f570 */
extern void StackPopDispatchTagged(void);     /* 0x0041f780 */
extern void LoadShlDerefCallSkip(void);     /* 0x0041f810 */
extern void ScaledNeg1SetPause(void);     /* 0x0041f840 */
extern void NodeChainMaskMatch(void);     /* 0x0041f870 */
extern void LinkedListBitMaskSearch(void);     /* 0x0041f8f0 */
extern void ChainNodeInit(void);     /* 0x0041fa50 */
extern void StructArrayWalkCondCall(void);     /* 0x0041fc50 */
extern void ScaledLoadInstallOrCall_00433960(void);     /* 0x00433960 */
extern void GuardedSeq_00433bb0(void);     /* 0x00433bb0 */
extern void InstallSelfThreeStateDispatch(void);     /* 0x00436030 */
extern void ScaledAddrInit_004368f0(void);     /* 0x004368f0 */
extern void InstallSelfPacked0x2005(void);     /* 0x00437a90 */
extern void InstallSelfChainSetB333(void);     /* 0x00437b60 */
extern void InstallSelfChainSetB333v2(void);     /* 0x00437f00 */
extern void Wrapper_CmpDualPatchScaledRangeJmp_004e4990(void);     /* 0x00438ee0 */
extern void PrefixThunkInstallSelf3State(void);     /* 0x00438f80 */
extern void SetJmp_HitReactionDispatcher(void);     /* 0x00439c30 */
extern void InstallSelfChainSet2011(void);     /* 0x00439ec0 */
extern void GuardedDoubleCallSetJmp(void);     /* 0x00460260 */
extern void Thunk_ScaledNeg1SetPause(void);     /* 0x0049cbc0 */
extern void Thunk_ChainNodeInit(void);     /* 0x0049cbd0 */
extern void AppInit_Misc2(void);     /* 0x004b5a80 */
extern void Helper_GeoLoadPre(void);     /* 0x004bd570 */
extern void LoadGeoAsset_Default(void);     /* 0x004bd5b0 */
extern void FlushDrawQueue(void);     /* 0x004bf460 */
extern void ExitGame(void);     /* 0x004c4870 */

/* The thunks. */
/* @addr 0x00405ac0 */
void Thunk_MStackPush2ChainPrepend(void) { MStackPush2ChainPrepend(); }

/* @addr 0x00427460 */
void Thunk_BootMod6487eClampAndChainMul10(void) { BootMod6487eClampAndChainMul10(); }

/* @addr 0x004296e0 */
void Thunk_StackPopDispatchTagged_004296e0(void) { StackPopDispatchTagged(); }

/* @addr 0x00433950 */
void Thunk_ScaledLoadInstallOrCall_00433960(void) { ScaledLoadInstallOrCall_00433960(); }

/* @addr 0x004344a0 */
void Thunk_InstallSelfChainSetB333(void) { InstallSelfChainSetB333(); }

/* @addr 0x00434c00 */
void Thunk_PrefixThunkInstallSelf3State(void) { PrefixThunkInstallSelf3State(); }

/* @addr 0x00434eb0 */
void Thunk_InstallSelfThreeStateDispatch(void) { InstallSelfThreeStateDispatch(); }

/* @addr 0x00435330 */
void Thunk_InstallSelfPacked0x2005(void) { InstallSelfPacked0x2005(); }

/* @addr 0x00435de0 */
void Thunk_Wrapper_00438ee0_00435de0(void) { Wrapper_CmpDualPatchScaledRangeJmp_004e4990(); }

/* @addr 0x004368d0 */
void Thunk_Wrapper_00438ee0_004368d0(void) { Wrapper_CmpDualPatchScaledRangeJmp_004e4990(); }

/* @addr 0x004368e0 */
void Thunk_ScaledAddrInit_004368f0(void) { ScaledAddrInit_004368f0(); }

/* @addr 0x004399b0 */
void Thunk_GuardedSeq_00433bb0(void) { GuardedSeq_00433bb0(); }

/* @addr 0x00439c20 */
void Thunk_SetJmp_00439c30(void) { SetJmp_HitReactionDispatcher(); }

/* @addr 0x00439e30 */
void Thunk_InstallSelfChainSet2011(void) { InstallSelfChainSet2011(); }

/* @addr 0x0043a540 */
void Thunk_InstallSelfChainSetB333v2(void) { InstallSelfChainSetB333v2(); }

/* @addr 0x0045dae0 */
void Thunk_Thunk_0049cbd0(void) { Thunk_ChainNodeInit(); }

/* @addr 0x0045e0f0 */
void Thunk_Thunk_0049cbc0_0045e0f0(void) { Thunk_ScaledNeg1SetPause(); }

/* @addr 0x00460250 */
void Thunk_GuardedDoubleCallSetJmp(void) { GuardedDoubleCallSetJmp(); }

/* @addr 0x004647f0 */
void Thunk_StackPopDispatchTagged_004647f0(void) { StackPopDispatchTagged(); }

/* @addr 0x0049cb70 */
void Thunk_NodeChainMaskMatch(void) { NodeChainMaskMatch(); }

/* @addr 0x0049cb80 */
void Thunk_LoadShlDerefCallSkip(void) { LoadShlDerefCallSkip(); }

/* @addr 0x0049cba0 */
void Thunk_LinkedListBitMaskSearch(void) { LinkedListBitMaskSearch(); }

/* @addr 0x0049cbb0 */
void Thunk_Thunk_0049cbc0_0049cbb0(void) { Thunk_ScaledNeg1SetPause(); }

/* @addr 0x0049cbc0 */
void Thunk_ScaledNeg1SetPause(void) { ScaledNeg1SetPause(); }

/* @addr 0x0049cbd0 */
void Thunk_ChainNodeInit(void) { ChainNodeInit(); }

/* @addr 0x0049cbe0 */
void Helper_TickFrame_PostFight(void) { BootScheduledNodeTimerWalk(); }

/* @addr 0x0049cbf0 */
void Thunk_ZeroLargeBlock(void) { ZeroLargeBlock(); }

/* @addr 0x0049cc00 */
void Thunk_StructArrayWalkCondCall(void) { StructArrayWalkCondCall(); }

/* @addr 0x004b5ac0 */
void Thunk_AppInit_Misc2(void) { AppInit_Misc2(); }

/* @addr 0x004bd5c0 */
void Thunk_LoadGeoAsset_Default(void) { LoadGeoAsset_Default(); }

/* @addr 0x004bd8d0 */
void Thunk_Helper_GeoLoadPre(void) { Helper_GeoLoadPre(); }

/* @addr 0x004bf320 */
void Thunk_FlushDrawQueue(void) { FlushDrawQueue(); }

/* @addr 0x004c48b0 */
void Thunk_ExitGame(void) { ExitGame(); }
