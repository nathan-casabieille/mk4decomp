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
extern void GuardedSeq_00433bd0(void);   /* 0x00433bd0 */
extern void ScaledIndirectJmp_00433bf0(void);   /* 0x00433bf0 */
extern void PackedSelectLoad6(void);   /* 0x00433c60 */
extern void CmpP1DualInitStore_00433d30(void);   /* 0x00433d30 */
extern void ScaledLoadTwoCallDualConst_0044ba30(void);   /* 0x0044ba30 */
extern void PendingMatch_0044baa0(void);   /* 0x0044baa0 */
extern void PoseCopyIdleCluster(void);   /* 0x004537a0 */
extern void BitmapBlitRunLength(void);   /* 0x004592f0 */
extern void ScaledLoadTwoCallDualConst_00467c30(void);   /* 0x00467c30 */
extern void GuardedTripleCallSetTail(void);   /* 0x00467ca0 */
extern void GuardedSeq_00473f50(void);   /* 0x00473f50 */
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
extern void GuardedSeq_00488be0(void);   /* 0x00488be0 */
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
void GuardedSeq_0041aad0(void) {
    BootStateInitLongChain();
    if (g_framePauseFlag) return;
    StackPopDispatchTagged();
}

/* @addr 0x004200b0 */
void GuardedSeq_004200b0(void) {
    ZeroTriple();
    if (g_framePauseFlag) return;
    PendingMatch_00401b70();
}

/* @addr 0x00428350 */
void GuardedSeq_00428350(void) {
    CopyJmp_00406ba0();
    if (g_framePauseFlag) return;
    MStackPushDualJmp();
}

/* @addr 0x00428480 */
void GuardedSeq_00428480(void) {
    CopyJmp_00406ba0();
    if (g_framePauseFlag) return;
    GuardedLoopWithCallback();
}

/* @addr 0x004297b0 */
void GuardedSeq_004297b0(void) {
    GuardedChainCmpDualBitXor();
    if (g_framePauseFlag) return;
    ScaledIncCmpJmp();
}

/* @addr 0x0042fb80 */
void GuardedSeq_0042fb80(void) {
    DualMulScaleStore();
    if (g_framePauseFlag) return;
    PhaseInstall2DInterpDispatch();
}

/* @addr 0x0042fba0 */
void GuardedSeq_0042fba0(void) {
    DualMulScaleStore();
    if (g_framePauseFlag) return;
    PhaseInstall2DInterpDispatch();
}

/* @addr 0x004335d0 */
void GuardedSeq_004335d0(void) {
    BitmapBlitRunLength();
    if (g_framePauseFlag) return;
    FiveTableInitChainBracketed();
}

/* @addr 0x00433bb0 */
void GuardedSeq_00433bb0(void) {
    PackedSelectLoad6();
    if (g_framePauseFlag) return;
    GuardedSeq_00433bd0();
}

/* @addr 0x00433bd0 */
void GuardedSeq_00433bd0(void) {
    CmpP1DualInitStore_00433d30();
    if (g_framePauseFlag) return;
    ScaledIndirectJmp_00433bf0();
}

/* @addr 0x00438630 */
void GuardedSeq_00438630(void) {
    ScaledZeroFour();
    if (g_framePauseFlag) return;
    StackPopDispatchTagged();
}

/* @addr 0x0044ba10 */
void GuardedSeq_0044ba10(void) {
    ScaledLoadTwoCallDualConst_0044ba30();
    if (g_framePauseFlag) return;
    GuardedSeq_00473f50();
}

/* @addr 0x0044ba80 */
void GuardedSeq_0044ba80(void) {
    PendingMatch_0044baa0();
    if (g_framePauseFlag) return;
    GuardedSeq_00473f50();
}

/* @addr 0x004515a0 */
void GuardedSeq_004515a0(void) {
    ChainDirtyBitWalker();
    if (g_framePauseFlag) return;
    DualScaledLoadStoreJmp();
}

/* @addr 0x00453780 */
void GuardedSeq_00453780(void) {
    MStackPushTwoEntryChainCall();
    if (g_framePauseFlag) return;
    PoseCopyIdleCluster();
}

/* @addr 0x004605b0 */
void GuardedSeq_004605b0(void) {
    MStackNegAwareMul10Pair();
    if (g_framePauseFlag) return;
    ChainTableWalkStore();
}

/* @addr 0x00467c10 */
void GuardedSeq_00467c10(void) {
    ScaledLoadTwoCallDualConst_00467c30();
    if (g_framePauseFlag) return;
    GuardedSeq_00473f50();
}

/* @addr 0x00467c80 */
void GuardedSeq_00467c80(void) {
    GuardedTripleCallSetTail();
    if (g_framePauseFlag) return;
    GuardedSeq_00473f50();
}

/* @addr 0x00471670 */
void GuardedSeq_00471670(void) {
    MStackCall_00406740();
    if (g_framePauseFlag) return;
    CallSetPause();
}

/* @addr 0x00472820 */
void GuardedSeq_00472820(void) {
    DualPushCmp12Dispatch68();
    if (g_framePauseFlag) return;
    ByteWordTableTaggedDispatch();
}

/* @addr 0x00472840 */
void GuardedSeq_00472840(void) {
    DualPushCmp12Dispatch();
    if (g_framePauseFlag) return;
    ByteWordTableTaggedDispatch();
}

/* @addr 0x00473ef0 */
void GuardedSeq_00473ef0(void) {
    DualSetShiftCall();
    if (g_framePauseFlag) return;
    DoubleStackPushAndJmp7b();
}

/* @addr 0x00473f10 */
void GuardedSeq_00473f10(void) {
    DualSetShiftCall();
    if (g_framePauseFlag) return;
    DoubleStackPushAndJmp7d();
}

/* @addr 0x00473f30 */
void GuardedSeq_00473f30(void) {
    DualSetShiftCall();
    if (g_framePauseFlag) return;
    DoubleStackPushAndJmp();
}

/* @addr 0x00473f50 */
void GuardedSeq_00473f50(void) {
    DualSetShiftCall();
    if (g_framePauseFlag) return;
    DualPushSet7dCallPop();
}

/* @addr 0x00473f70 */
void GuardedSeq_00473f70(void) {
    DualSetShiftCall();
    if (g_framePauseFlag) return;
    MStackPush2CjMul10Triple();
}

/* @addr 0x00476de0 */
void GuardedSeq_00476de0(void) {
    DirtyDoubleDeref();
    if (g_framePauseFlag) return;
    ScaledOr4Jmp();
}

/* @addr 0x00476f10 */
void GuardedSeq_00476f10(void) {
    DirtyDoubleDeref();
    if (g_framePauseFlag) return;
    ChainSlotSetupInstallSelf();
}

/* @addr 0x00476fc0 */
void GuardedSeq_00476fc0(void) {
    DirtyDoubleDeref();
    if (g_framePauseFlag) return;
    ScaledAndFBJmp();
}

/* @addr 0x0047d980 */
void GuardedSeq_0047d980(void) {
    MStackPushSet0004();
    if (g_framePauseFlag) return;
    MoveSelectorCluster();
}

/* @addr 0x00485ca0 */
void GuardedSeq_00485ca0(void) {
    ScaledZeroFour();
    if (g_framePauseFlag) return;
    GuardedSeq_00488be0();
}

/* @addr 0x004871b0 */
void GuardedSeq_004871b0(void) {
    CmpJmpTwoBranch();
    if (g_framePauseFlag) return;
    Wrapper_ScaledChainPushCall_004ef8b0();
}

/* @addr 0x00488890 */
void GuardedSeq_00488890(void) {
    CjTableThresholdDispatch();
    if (g_framePauseFlag) return;
    RoundTextMenuEventCluster();
}

/* @addr 0x00488be0 */
void GuardedSeq_00488be0(void) {
    ScaledXorStore_004903b0();
    if (g_framePauseFlag) return;
    LiteralPushCallEntZero();
}

/* @addr 0x00490c60 */
void GuardedSeq_00490c60(void) {
    DualCallPauseDirtyJmp_00490c30();
    if (g_framePauseFlag) return;
    ScaledXorStore_004903b0();
}

/* @addr 0x00497450 */
void GuardedSeq_00497450(void) {
    MStackCall_00406740();
    if (g_framePauseFlag) return;
    CallSetPause();
}

/* @addr 0x0049a650 */
void GuardedSeq_0049a650(void) {
    MStackCall_00406740();
    if (g_framePauseFlag) return;
    CallSetPause();
}

/* @addr 0x0049c340 */
void GuardedSeq_0049c340(void) {
    MStackCall_00406740();
    if (g_framePauseFlag) return;
    CallSetPause();
}

