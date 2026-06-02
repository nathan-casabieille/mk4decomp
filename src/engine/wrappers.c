/**
 * 43 single-arg call-and-return wrappers.
 *
 * Each compiles to `push CONST; call Target; add esp, 4; ret`
 * (14 bytes). Likely auto-generated trampolines for static-init
 * constructors or per-table dispatch helpers.
 */

/* Externs for wrapper targets. */
extern void SaveCallRestore(unsigned int arg);   /* 0x004049d0 */
extern void OrListLoop(unsigned int arg);   /* 0x0041fcc0 */
extern void PackedAdvanceCallTailJmp(unsigned int arg);   /* 0x004392c0 */
extern void CmpDualPatchScaledRangeJmp(unsigned int arg);   /* 0x004399c0 */
extern void ArgSarStoreJmp(unsigned int arg);   /* 0x004594f0 */
extern void ScaledChainPushCall(unsigned int arg);   /* 0x00489ee0 */
extern void ScaledIndexCondCopy(unsigned int arg);   /* 0x0048e590 */
extern void IterLoad_g_scaledInit_00542044_then_MStackPush4IndirectCall(unsigned int arg);   /* 0x0048fd30 */
extern void Cascade5StageInit(unsigned int arg);   /* 0x00491520 */

/* The wrappers. */
/* @addr 0x0041fcf0 */
void Wrapper_OrListLoop_004de3f8(void) { OrListLoop(0x004de3f8u); }

/* @addr 0x0041fd00 */
void Wrapper_OrListLoop_004d8e80(void) { OrListLoop(0x004d8e80u); }

/* @addr 0x00433940 */
void Wrapper_PackedAdvanceCallTailJmp_004e44f0(void) { PackedAdvanceCallTailJmp(0x004e44f0u); }

/* @addr 0x00436490 */
void Wrapper_PackedAdvanceCallTailJmp_004e46d0(void) { PackedAdvanceCallTailJmp(0x004e46d0u); }

/* @addr 0x00436760 */
void Wrapper_PackedAdvanceCallTailJmp_004e4708(void) { PackedAdvanceCallTailJmp(0x004e4708u); }

/* @addr 0x00436770 */
void Wrapper_PackedAdvanceCallTailJmp_004e4718(void) { PackedAdvanceCallTailJmp(0x004e4718u); }

/* @addr 0x004377c0 */
void Wrapper_CmpDualPatchScaledRangeJmp_004e4810(void) { CmpDualPatchScaledRangeJmp(0x004e4810u); }

/* @addr 0x00438c40 */
void Wrapper_CmpDualPatchScaledRangeJmp_004e4850(void) { CmpDualPatchScaledRangeJmp(0x004e4850u); }

/* @addr 0x00438ed0 */
void Wrapper_CmpDualPatchScaledRangeJmp_004e4950(void) { CmpDualPatchScaledRangeJmp(0x004e4950u); }

/* @addr 0x00438ee0 */
void Wrapper_CmpDualPatchScaledRangeJmp_004e4990(void) { CmpDualPatchScaledRangeJmp(0x004e4990u); }

/* @addr 0x00439310 */
void Wrapper_ScaledIndexCondCopy(void) { ScaledIndexCondCopy(0x005422f0u); }

/* @addr 0x0043abf0 */
void Wrapper_PackedAdvanceCallTailJmp_004e4a58(void) { PackedAdvanceCallTailJmp(0x004e4a58u); }

/* @addr 0x0043ac00 */
void Wrapper_PackedAdvanceCallTailJmp_004e4a70(void) { PackedAdvanceCallTailJmp(0x004e4a70u); }

/* @addr 0x00471340 */
void Wrapper_ArgSarStoreJmp_004eba28(void) { ArgSarStoreJmp(0x004eba28u); }

/* @addr 0x0047d6d0 */
void Wrapper_ArgSarStoreJmp_004ed440(void) { ArgSarStoreJmp(0x004ed440u); }

/* @addr 0x0047ed80 */
void Wrapper_ArgSarStoreJmp_004ed660(void) { ArgSarStoreJmp(0x004ed660u); }

/* @addr 0x00481060 */
void Wrapper_IterLoad_0048fd30_004ed980(void) { IterLoad_g_scaledInit_00542044_then_MStackPush4IndirectCall(0x004ed980u); }

/* @addr 0x00484470 */
void Wrapper_ArgSarStoreJmp_004ee850(void) { ArgSarStoreJmp(0x004ee850u); }

/* @addr 0x00484d90 */
void Wrapper_ArgSarStoreJmp_004ee958(void) { ArgSarStoreJmp(0x004ee958u); }

/* @addr 0x00487140 */
void Wrapper_ArgSarStoreJmp_004eeeb0(void) { ArgSarStoreJmp(0x004eeeb0u); }

/* @addr 0x00488bd0 */
void Wrapper_Cascade5StageInit_004ef1e8(void) { Cascade5StageInit(0x004ef1e8u); }

/* @addr 0x00488c60 */
void Wrapper_Cascade5StageInit_004ef208(void) { Cascade5StageInit(0x004ef208u); }

/* @addr 0x0048a250 */
void Wrapper_ScaledChainPushCall_004ef980(void) { ScaledChainPushCall(0x004ef980u); }

/* @addr 0x0048a260 */
void Wrapper_ScaledChainPushCall_004ef828(void) { ScaledChainPushCall(0x004ef828u); }

/* @addr 0x0048a270 */
void Wrapper_ScaledChainPushCall_004ef948(void) { ScaledChainPushCall(0x004ef948u); }

/* @addr 0x0048a280 */
void Wrapper_ScaledChainPushCall_004ef810(void) { ScaledChainPushCall(0x004ef810u); }

/* @addr 0x0048a300 */
void Wrapper_ScaledChainPushCall_004ef898(void) { ScaledChainPushCall(0x004ef898u); }

/* @addr 0x0048a310 */
void Wrapper_ScaledChainPushCall_004ef910(void) { ScaledChainPushCall(0x004ef910u); }

/* @addr 0x0048a320 */
void Wrapper_ScaledChainPushCall_004ef900(void) { ScaledChainPushCall(0x004ef900u); }

/* @addr 0x0048a330 */
void Wrapper_ScaledChainPushCall_004ef878(void) { ScaledChainPushCall(0x004ef878u); }

/* @addr 0x0048a340 */
void Wrapper_ScaledChainPushCall_004ef8c8(void) { ScaledChainPushCall(0x004ef8c8u); }

/* @addr 0x0048a350 */
void Wrapper_ScaledChainPushCall_004ef858(void) { ScaledChainPushCall(0x004ef858u); }

/* @addr 0x0048a360 */
void Wrapper_ScaledChainPushCall_004ef868(void) { ScaledChainPushCall(0x004ef868u); }

/* @addr 0x0048a370 */
void Wrapper_ScaledChainPushCall_004ef920(void) { ScaledChainPushCall(0x004ef920u); }

/* @addr 0x0048a380 */
void Wrapper_ScaledChainPushCall_004ef8e0(void) { ScaledChainPushCall(0x004ef8e0u); }

/* @addr 0x0048a390 */
void Wrapper_ScaledChainPushCall_004ef8f0(void) { ScaledChainPushCall(0x004ef8f0u); }

/* @addr 0x0048a3a0 */
void Wrapper_ScaledChainPushCall_004ef8b0(void) { ScaledChainPushCall(0x004ef8b0u); }

/* @addr 0x0048a3b0 */
void Wrapper_ScaledChainPushCall_004ef888(void) { ScaledChainPushCall(0x004ef888u); }

/* @addr 0x0048a3c0 */
void Wrapper_ScaledChainPushCall_004ef838(void) { ScaledChainPushCall(0x004ef838u); }

/* @addr 0x0048ec20 */
void Wrapper_IterLoad_0048fd30_004f12a0(void) { IterLoad_g_scaledInit_00542044_then_MStackPush4IndirectCall(0x004f12a0u); }

/* @addr 0x0048fbc0 */
void Wrapper_IterLoad_0048fd30_004f12a8(void) { IterLoad_g_scaledInit_00542044_then_MStackPush4IndirectCall(0x004f12a8u); }

/* @addr 0x0048ff30 */
void Wrapper_IterLoad_0048fd30_004f12ac(void) { IterLoad_g_scaledInit_00542044_then_MStackPush4IndirectCall(0x004f12acu); }

/* @addr 0x0049eb10 */
void Wrapper_SaveCallRestore(void) { SaveCallRestore(0x00000266u); }

