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
extern void BootMod6487eClampAndChainMul10_00407510(void);     /* 0x00407510 */
extern void MStackPush2ChainPrepend_00409970(void);     /* 0x00409970 */
extern void ZeroLargeBlock_0041f270(void);     /* 0x0041f270 */
extern void BootScheduledNodeTimerWalk_0041f570(void);     /* 0x0041f570 */
extern void StackPopDispatchTagged_0041f780(void);     /* 0x0041f780 */
extern void LoadShlDerefCallSkip_0041f810(void);     /* 0x0041f810 */
extern void ScaledNeg1SetPause_0041f840(void);     /* 0x0041f840 */
extern void NodeChainMaskMatch_0041f870(void);     /* 0x0041f870 */
extern void LinkedListBitMaskSearch_0041f8f0(void);     /* 0x0041f8f0 */
extern void ChainNodeInit_0041fa50(void);     /* 0x0041fa50 */
extern void StructArrayWalkCondCall_0041fc50(void);     /* 0x0041fc50 */
extern void ScaledLoadInstallOrCall_00433960(void);     /* 0x00433960 */
extern void GuardedSeq_00433bb0(void);     /* 0x00433bb0 */
extern void InstallSelfThreeStateDispatch_00436030(void);     /* 0x00436030 */
extern void ScaledAddrInit_004368f0(void);     /* 0x004368f0 */
extern void InstallSelfPacked0x2005_00437a90(void);     /* 0x00437a90 */
extern void InstallSelfChainSetB333_00437b60(void);     /* 0x00437b60 */
extern void InstallSelfChainSetB333v2_00437f00(void);     /* 0x00437f00 */
extern void Wrapper_00438ee0(void);     /* 0x00438ee0 */
extern void PrefixThunkInstallSelf3State_00438f80(void);     /* 0x00438f80 */
extern void SetJmp_00439c30(void);     /* 0x00439c30 */
extern void InstallSelfChainSet2011_00439ec0(void);     /* 0x00439ec0 */
extern void GuardedDoubleCallSetJmp_00460260(void);     /* 0x00460260 */
extern void Thunk_0049cbc0(void);     /* 0x0049cbc0 */
extern void Thunk_0049cbd0(void);     /* 0x0049cbd0 */
extern void AppInit_Misc2(void);     /* 0x004b5a80 */
extern void Helper_GeoLoadPre(void);     /* 0x004bd570 */
extern void LoadGeoAsset_Default(void);     /* 0x004bd5b0 */
extern void FlushDrawQueue(void);     /* 0x004bf460 */
extern void ExitGame(void);     /* 0x004c4870 */

/* The thunks. */
/* @addr 0x00405ac0 */
void Thunk_00405ac0(void) { MStackPush2ChainPrepend_00409970(); }

/* @addr 0x00427460 */
void Thunk_00427460(void) { BootMod6487eClampAndChainMul10_00407510(); }

/* @addr 0x004296e0 */
void Thunk_004296e0(void) { StackPopDispatchTagged_0041f780(); }

/* @addr 0x00433950 */
void Thunk_00433950(void) { ScaledLoadInstallOrCall_00433960(); }

/* @addr 0x004344a0 */
void Thunk_004344a0(void) { InstallSelfChainSetB333_00437b60(); }

/* @addr 0x00434c00 */
void Thunk_00434c00(void) { PrefixThunkInstallSelf3State_00438f80(); }

/* @addr 0x00434eb0 */
void Thunk_00434eb0(void) { InstallSelfThreeStateDispatch_00436030(); }

/* @addr 0x00435330 */
void Thunk_00435330(void) { InstallSelfPacked0x2005_00437a90(); }

/* @addr 0x00435de0 */
void Thunk_00435de0(void) { Wrapper_00438ee0(); }

/* @addr 0x004368d0 */
void Thunk_004368d0(void) { Wrapper_00438ee0(); }

/* @addr 0x004368e0 */
void Thunk_004368e0(void) { ScaledAddrInit_004368f0(); }

/* @addr 0x004399b0 */
void Thunk_004399b0(void) { GuardedSeq_00433bb0(); }

/* @addr 0x00439c20 */
void Thunk_00439c20(void) { SetJmp_00439c30(); }

/* @addr 0x00439e30 */
void Thunk_00439e30(void) { InstallSelfChainSet2011_00439ec0(); }

/* @addr 0x0043a540 */
void Thunk_0043a540(void) { InstallSelfChainSetB333v2_00437f00(); }

/* @addr 0x0045dae0 */
void Thunk_0045dae0(void) { Thunk_0049cbd0(); }

/* @addr 0x0045e0f0 */
void Thunk_0045e0f0(void) { Thunk_0049cbc0(); }

/* @addr 0x00460250 */
void Thunk_00460250(void) { GuardedDoubleCallSetJmp_00460260(); }

/* @addr 0x004647f0 */
void Thunk_004647f0(void) { StackPopDispatchTagged_0041f780(); }

/* @addr 0x0049cb70 */
void Thunk_0049cb70(void) { NodeChainMaskMatch_0041f870(); }

/* @addr 0x0049cb80 */
void Thunk_0049cb80(void) { LoadShlDerefCallSkip_0041f810(); }

/* @addr 0x0049cba0 */
void Thunk_0049cba0(void) { LinkedListBitMaskSearch_0041f8f0(); }

/* @addr 0x0049cbb0 */
void Thunk_0049cbb0(void) { Thunk_0049cbc0(); }

/* @addr 0x0049cbc0 */
void Thunk_0049cbc0(void) { ScaledNeg1SetPause_0041f840(); }

/* @addr 0x0049cbd0 */
void Thunk_0049cbd0(void) { ChainNodeInit_0041fa50(); }

/* @addr 0x0049cbe0 */
void Helper_TickFrame_PostFight(void) { BootScheduledNodeTimerWalk_0041f570(); }

/* @addr 0x0049cbf0 */
void Thunk_0049cbf0(void) { ZeroLargeBlock_0041f270(); }

/* @addr 0x0049cc00 */
void Thunk_0049cc00(void) { StructArrayWalkCondCall_0041fc50(); }

/* @addr 0x004b5ac0 */
void Thunk_004b5ac0(void) { AppInit_Misc2(); }

/* @addr 0x004bd5c0 */
void Thunk_004bd5c0(void) { LoadGeoAsset_Default(); }

/* @addr 0x004bd8d0 */
void Thunk_004bd8d0(void) { Helper_GeoLoadPre(); }

/* @addr 0x004bf320 */
void Thunk_004bf320(void) { FlushDrawQueue(); }

/* @addr 0x004c48b0 */
void Thunk_004c48b0(void) { ExitGame(); }
