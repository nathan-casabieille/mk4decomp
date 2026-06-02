/**
 * 38 "guarded sequel" wrappers.
 *
 * Each compiles to:
 *   call PreFunc                  ; e8 + reloc
 *   mov eax, [g_framePauseFlag]   ; a1 6c 1e 54 00
 *   test eax, eax                  ; 85 c0
 *   jne short skip                 ; 75 05
 *   jmp PostFunc                   ; e9 + reloc  (tail-call)
 *   ret                            ; c3
 *
 * 20 bytes total. Generated as a per-tick chain helper that
 * runs PostFunc only if the frame pause flag is clear.
 */
#include "game/tick.h"   /* g_framePauseFlag */

/* Externs for guarded-sequel targets. */
extern void PendingMatch_00401b70(void);   /* 0x00401b70 */
extern void MStackPushTwoEntryChainCall(void);   /* 0x004058c0 */
extern void MStackCall_00406740(void);   /* 0x00406740 */
extern void CopyJmp_00406ba0(void);   /* 0x00406ba0 */
extern void ChainDirtyBitWalker(void);   /* 0x00408c10 */
extern void DirtyDoubleDeref(void);   /* 0x00408cb0 */
extern void BootStateInitLongChain(void);   /* 0x0041ab90 */
extern void StackPopDispatchTagged(void);   /* 0x0041f780 */
extern void CallSetPause(void);   /* 0x0041f830 */
extern void ZeroTriple(void);   /* 0x00421c20 */
extern void MStackPushDualJmp(void);   /* 0x00428370 */
extern void GuardedLoopWithCallback(void);   /* 0x004284a0 */
extern void ScaledIncCmpJmp(void);   /* 0x004297d0 */
extern void GuardedChainCmpDualBitXor(void);   /* 0x004299a0 */
extern void PhaseInstall2DInterpDispatch(void);   /* 0x0042f8a0 */
extern void DualMulScaleStore(void);   /* 0x0042ffa0 */
extern void GuardedSeq_CmpP1DualInitStore_then_ScaledIndirectJmp(void);   /* 0x00433bd0 */
extern void ScaledIndirectJmp_00433bf0(void);   /* 0x00433bf0 */
extern void PackedSelectLoad6(void);   /* 0x00433c60 */
extern void CmpP1DualInitStore_00433d30(void);   /* 0x00433d30 */
extern void ScaledLoadTwoCallDualConst_0044ba30(void);   /* 0x0044ba30 */
extern void PendingMatch_0044baa0(void);   /* 0x0044baa0 */
extern void PoseCopyIdleCluster(void);   /* 0x004537a0 */
extern void BitmapBlitRunLength(void);   /* 0x004592f0 */
extern void ScaledLoadTwoCallDualConst_00467c30(void);   /* 0x00467c30 */
extern void GuardedTripleCallSetTail(void);   /* 0x00467ca0 */
extern void GuardedSeq_DualSetShiftCall_then_DualPushSet7dCallPop(void);   /* 0x00473f50 */
extern void DualSetShiftCall(void);   /* 0x00473f90 */
extern void DoubleStackPushAndJmp(void);   /* 0x00474010 */
extern void DoubleStackPushAndJmp7d(void);   /* 0x00474050 */
extern void DoubleStackPushAndJmp7b(void);   /* 0x00474090 */
extern void MStackPush2CjMul10Triple(void);   /* 0x00474170 */
extern void DualPushSet7dCallPop(void);   /* 0x00474290 */
extern void DualPushCmp12Dispatch(void);   /* 0x00474d40 */
extern void DualPushCmp12Dispatch68(void);   /* 0x00474de0 */
extern void DualScaledLoadStoreJmp(void);   /* 0x00475790 */
extern void ScaledOr4Jmp(void);   /* 0x00476e00 */
extern void ChainSlotSetupInstallSelf(void);   /* 0x00476f30 */
extern void ScaledAndFBJmp(void);   /* 0x00476fe0 */
extern void FiveTableInitChainBracketed(void);   /* 0x004774f0 */
extern void MoveSelectorCluster(void);   /* 0x0047d9a0 */
extern void CmpJmpTwoBranch(void);   /* 0x004871d0 */
extern void RoundTextMenuEventCluster(void);   /* 0x004888b0 */
extern void GuardedSeq_ScaledXorStore_then_LiteralPushCallEntZero(void);   /* 0x00488be0 */
extern void LiteralPushCallEntZero(void);   /* 0x00488c00 */
extern void CjTableThresholdDispatch(void);   /* 0x00488f00 */
extern void ByteWordTableTaggedDispatch(void);   /* 0x0048a050 */
extern void Wrapper_ScaledChainPushCall_004ef8b0(void);   /* 0x0048a3a0 */
extern void MStackPushSet0004(void);   /* 0x00490230 */
extern void ScaledXorStore_004903b0(void);   /* 0x004903b0 */
extern void ScaledZeroFour(void);   /* 0x00490740 */
extern void DualCallPauseDirtyJmp_00490c30(void);   /* 0x00490c30 */
extern void MStackNegAwareMul10Pair(void);   /* 0x004910b0 */
extern void ChainTableWalkStore(void);   /* 0x004917e0 */

/* The wrappers - naked __asm to force the exact `call/test/jne/jmp/ret` sequence. */
/* @addr 0x0041aad0 */
void GuardedSeq_BootStateInitLongChain_then_StackPopDispatchTagged(void) {
    BootStateInitLongChain();
    if (g_framePauseFlag) return;
    StackPopDispatchTagged();
}

/* @addr 0x004200b0 */
void GuardedSeq_ZeroTriple_then_PendingMatch(void) {
    ZeroTriple();
    if (g_framePauseFlag) return;
    PendingMatch_00401b70();
}

/* @addr 0x00428350 */
void GuardedSeq_CopyJmp_then_MStackPushDualJmp(void) {
    CopyJmp_00406ba0();
    if (g_framePauseFlag) return;
    MStackPushDualJmp();
}

/* @addr 0x00428480 */
void GuardedSeq_CopyJmp_then_GuardedLoopWithCallback(void) {
    CopyJmp_00406ba0();
    if (g_framePauseFlag) return;
    GuardedLoopWithCallback();
}

/* @addr 0x004297b0 */
void GuardedSeq_GuardedChainCmpDualBitXor_then_ScaledIncCmpJmp(void) {
    GuardedChainCmpDualBitXor();
    if (g_framePauseFlag) return;
    ScaledIncCmpJmp();
}

/* @addr 0x0042fb80 */
void GuardedSeq_DualMulScaleStore_then_PhaseInstall2DInterpDispatch_0042fb80(void) {
    DualMulScaleStore();
    if (g_framePauseFlag) return;
    PhaseInstall2DInterpDispatch();
}

/* @addr 0x0042fba0 */
void GuardedSeq_DualMulScaleStore_then_PhaseInstall2DInterpDispatch_0042fba0(void) {
    DualMulScaleStore();
    if (g_framePauseFlag) return;
    PhaseInstall2DInterpDispatch();
}

/* @addr 0x004335d0 */
void GuardedSeq_BitmapBlitRunLength_then_FiveTableInitChainBracketed(void) {
    BitmapBlitRunLength();
    if (g_framePauseFlag) return;
    FiveTableInitChainBracketed();
}

/* @addr 0x00433bb0 */
void GuardedSeq_PackedSelectLoad6_then_GuardedSeq(void) {
    PackedSelectLoad6();
    if (g_framePauseFlag) return;
    GuardedSeq_CmpP1DualInitStore_then_ScaledIndirectJmp();
}

/* @addr 0x00433bd0 */
void GuardedSeq_CmpP1DualInitStore_then_ScaledIndirectJmp(void) {
    CmpP1DualInitStore_00433d30();
    if (g_framePauseFlag) return;
    ScaledIndirectJmp_00433bf0();
}

/* @addr 0x00438630 */
void GuardedSeq_ScaledZeroFour_then_StackPopDispatchTagged(void) {
    ScaledZeroFour();
    if (g_framePauseFlag) return;
    StackPopDispatchTagged();
}

/* @addr 0x0044ba10 */
void GuardedSeq_ScaledLoadTwoCallDualConst_then_GuardedSeq_0044ba10(void) {
    ScaledLoadTwoCallDualConst_0044ba30();
    if (g_framePauseFlag) return;
    GuardedSeq_DualSetShiftCall_then_DualPushSet7dCallPop();
}

/* @addr 0x0044ba80 */
void GuardedSeq_PendingMatch_then_GuardedSeq(void) {
    PendingMatch_0044baa0();
    if (g_framePauseFlag) return;
    GuardedSeq_DualSetShiftCall_then_DualPushSet7dCallPop();
}

/* @addr 0x004515a0 */
void GuardedSeq_ChainDirtyBitWalker_then_DualScaledLoadStoreJmp(void) {
    ChainDirtyBitWalker();
    if (g_framePauseFlag) return;
    DualScaledLoadStoreJmp();
}

/* @addr 0x00453780 */
void GuardedSeq_MStackPushTwoEntryChainCall_then_PoseCopyIdleCluster(void) {
    MStackPushTwoEntryChainCall();
    if (g_framePauseFlag) return;
    PoseCopyIdleCluster();
}

/* @addr 0x004605b0 */
void GuardedSeq_MStackNegAwareMul10Pair_then_ChainTableWalkStore(void) {
    MStackNegAwareMul10Pair();
    if (g_framePauseFlag) return;
    ChainTableWalkStore();
}

/* @addr 0x00467c10 */
void GuardedSeq_ScaledLoadTwoCallDualConst_then_GuardedSeq_00467c10(void) {
    ScaledLoadTwoCallDualConst_00467c30();
    if (g_framePauseFlag) return;
    GuardedSeq_DualSetShiftCall_then_DualPushSet7dCallPop();
}

/* @addr 0x00467c80 */
void GuardedSeq_GuardedTripleCallSetTail_then_GuardedSeq(void) {
    GuardedTripleCallSetTail();
    if (g_framePauseFlag) return;
    GuardedSeq_DualSetShiftCall_then_DualPushSet7dCallPop();
}

/* @addr 0x00471670 */
void GuardedSeq_MStackCall_then_CallSetPause_00471670(void) {
    MStackCall_00406740();
    if (g_framePauseFlag) return;
    CallSetPause();
}

/* @addr 0x00472820 */
void GuardedSeq_DualPushCmp12Dispatch68_then_ByteWordTableTaggedDispatch(void) {
    DualPushCmp12Dispatch68();
    if (g_framePauseFlag) return;
    ByteWordTableTaggedDispatch();
}

/* @addr 0x00472840 */
void GuardedSeq_DualPushCmp12Dispatch_then_ByteWordTableTaggedDispatch(void) {
    DualPushCmp12Dispatch();
    if (g_framePauseFlag) return;
    ByteWordTableTaggedDispatch();
}

/* @addr 0x00473ef0 */
void GuardedSeq_DualSetShiftCall_then_DoubleStackPushAndJmp7b(void) {
    DualSetShiftCall();
    if (g_framePauseFlag) return;
    DoubleStackPushAndJmp7b();
}

/* @addr 0x00473f10 */
void GuardedSeq_DualSetShiftCall_then_DoubleStackPushAndJmp7d(void) {
    DualSetShiftCall();
    if (g_framePauseFlag) return;
    DoubleStackPushAndJmp7d();
}

/* @addr 0x00473f30 */
void GuardedSeq_DualSetShiftCall_then_DoubleStackPushAndJmp(void) {
    DualSetShiftCall();
    if (g_framePauseFlag) return;
    DoubleStackPushAndJmp();
}

/* @addr 0x00473f50 */
void GuardedSeq_DualSetShiftCall_then_DualPushSet7dCallPop(void) {
    DualSetShiftCall();
    if (g_framePauseFlag) return;
    DualPushSet7dCallPop();
}

/* @addr 0x00473f70 */
void GuardedSeq_DualSetShiftCall_then_MStackPush2CjMul10Triple(void) {
    DualSetShiftCall();
    if (g_framePauseFlag) return;
    MStackPush2CjMul10Triple();
}

/* @addr 0x00476de0 */
void GuardedSeq_DirtyDoubleDeref_then_ScaledOr4Jmp(void) {
    DirtyDoubleDeref();
    if (g_framePauseFlag) return;
    ScaledOr4Jmp();
}

/* @addr 0x00476f10 */
void GuardedSeq_DirtyDoubleDeref_then_ChainSlotSetupInstallSelf(void) {
    DirtyDoubleDeref();
    if (g_framePauseFlag) return;
    ChainSlotSetupInstallSelf();
}

/* @addr 0x00476fc0 */
void GuardedSeq_DirtyDoubleDeref_then_ScaledAndFBJmp(void) {
    DirtyDoubleDeref();
    if (g_framePauseFlag) return;
    ScaledAndFBJmp();
}

/* @addr 0x0047d980 */
void GuardedSeq_MStackPushSet0004_then_MoveSelectorCluster(void) {
    MStackPushSet0004();
    if (g_framePauseFlag) return;
    MoveSelectorCluster();
}

/* @addr 0x00485ca0 */
void GuardedSeq_ScaledZeroFour_then_GuardedSeq(void) {
    ScaledZeroFour();
    if (g_framePauseFlag) return;
    GuardedSeq_ScaledXorStore_then_LiteralPushCallEntZero();
}

/* @addr 0x004871b0 */
void GuardedSeq_CmpJmpTwoBranch_then_Wrapper_ScaledChainPushCall(void) {
    CmpJmpTwoBranch();
    if (g_framePauseFlag) return;
    Wrapper_ScaledChainPushCall_004ef8b0();
}

/* @addr 0x00488890 */
void GuardedSeq_CjTableThresholdDispatch_then_RoundTextMenuEventCluster(void) {
    CjTableThresholdDispatch();
    if (g_framePauseFlag) return;
    RoundTextMenuEventCluster();
}

/* @addr 0x00488be0 */
void GuardedSeq_ScaledXorStore_then_LiteralPushCallEntZero(void) {
    ScaledXorStore_004903b0();
    if (g_framePauseFlag) return;
    LiteralPushCallEntZero();
}

/* @addr 0x00490c60 */
void GuardedSeq_DualCallPauseDirtyJmp_then_ScaledXorStore(void) {
    DualCallPauseDirtyJmp_00490c30();
    if (g_framePauseFlag) return;
    ScaledXorStore_004903b0();
}

/* @addr 0x00497450 */
void GuardedSeq_MStackCall_then_CallSetPause_00497450(void) {
    MStackCall_00406740();
    if (g_framePauseFlag) return;
    CallSetPause();
}

/* @addr 0x0049a650 */
void GuardedSeq_MStackCall_then_CallSetPause_0049a650(void) {
    MStackCall_00406740();
    if (g_framePauseFlag) return;
    CallSetPause();
}

/* @addr 0x0049c340 */
void GuardedSeq_MStackCall_then_CallSetPause_0049c340(void) {
    MStackCall_00406740();
    if (g_framePauseFlag) return;
    CallSetPause();
}

