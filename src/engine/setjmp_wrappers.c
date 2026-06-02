/**
 * 47 "set-global-and-tail-jmp" wrappers.
 *
 * Each compiles to:
 *   mov dword ptr [g_X], CONST     ; c7 05 + reloc + imm32  (10 bytes)
 *   jmp Target                      ; e9 + reloc            (5 bytes)
 *
 * 15 bytes total - per-state setup helpers in the menu/scene-
 * graph code.
 */
#include "engine/scenegraph.h"

/* New globals referenced by these wrappers. */
extern unsigned int g_acc_00542078;   /* 0x00542078 */
extern unsigned int g_setjmp;   /* 0x00ab5750 */

/* Externs for jump targets. */
extern void ZeroAndDirty4(void);   /* 0x00405430 */
extern void CallPauseScaledStoreAdd(void);   /* 0x004078f0 */
extern void BootStateTriple(void);   /* 0x00408d30 */
extern void EsiInstallDecCallChain_004294a0(void);   /* 0x004294a0 */
extern void EsiInstallBitCallChain_004295a0(void);   /* 0x004295a0 */
extern void ScaledArrStore_00429960(void);   /* 0x00429960 */
extern void Distance3DMul10Chain(void);   /* 0x0042d090 */
extern void AudioBridgeMStackChainCopy(void);   /* 0x00440730 */
extern void SetJmp_GuardedSeq_00473f10_00451ad0(void);   /* 0x00451ad0 */
extern void SetJmp_GuardedSeq_00473f10_00451b10(void);   /* 0x00451b10 */
extern void SetJmp_GuardedSeq_00473f10_00451b50(void);   /* 0x00451b50 */
extern void JuggleFsmCluster(void);   /* 0x00451b90 */
extern void CharSelectFsmCluster(void);   /* 0x004561f0 */
extern void SixSubdispatchSpan(void);   /* 0x0045ec10 */
extern void HitReactionDispatcher(void);   /* 0x0045f650 */
extern void AlarmCountdownInstall(void);   /* 0x004609e0 */
extern void StateDispatchYield(void);   /* 0x00471190 */
extern void GuardedSeq_00473f10(void);   /* 0x00473f10 */
extern void InstallSelfChainEsi(void);   /* 0x004753b0 */
extern void ScaledLitLoadCall_00481020(void);   /* 0x00481020 */
extern void InstallSelfTwoTailJmp(void);   /* 0x00483f30 */
extern void DualLoadDualStoreJmp(void);   /* 0x00485d70 */
extern void InstallSelfMStackIndirect(void);   /* 0x00487920 */
extern void Push16Call(void);   /* 0x00489f50 */
extern void Phase3InstallTableCheck(void);   /* 0x0048acd0 */
extern void MStackPush4IndirectCall(void);   /* 0x0048fd60 */
extern void Thunk_LinkedListBitMaskSearch(void);   /* 0x0049cba0 */
extern void IncCallVtablePushCall(void);   /* 0x004b0d80 */

/* The wrappers - naked __asm to lock the encoding. */
/* @addr 0x00405420 */
void SetJmp_ZeroAndDirty4(void) {
    g_walkCallback = (void (*)(void))0x0000f333;
    ZeroAndDirty4();
}

/* @addr 0x004078e0 */
void SetJmp_CallPauseScaledStoreAdd(void) {
    g_walkCallback = (void (*)(void))0x00000001;
    CallPauseScaledStoreAdd();
}

/* @addr 0x00408d20 */
void SetJmp_BootStateTriple(void) {
    g_walkCallback = (void (*)(void))0x00000001;
    BootStateTriple();
}

/* @addr 0x00428cf0 */
void SetJmp_EsiInstallDecCallChain_004294a0(void) {
    g_eventQueueChild = 0x00000003;
    EsiInstallDecCallChain_004294a0();
}

/* @addr 0x00429230 */
void SetJmp_EsiInstallBitCallChain_004295a0(void) {
    g_walkCallback = (void (*)(void))0x00000000;
    EsiInstallBitCallChain_004295a0();
}

/* @addr 0x00429950 */
void SetJmp_ScaledArrStore_00429960(void) {
    g_walkCallback = (void (*)(void))0x00000000;
    ScaledArrStore_00429960();
}

/* @addr 0x0042d070 */
void SetJmp_Distance3DMul10Chain_0042d070(void) {
    g_currentNodeFlags = 0x00010000;
    Distance3DMul10Chain();
}

/* @addr 0x0042d080 */
void SetJmp_Distance3DMul10Chain_0042d080(void) {
    g_currentNodeFlags = 0xffff0000;
    Distance3DMul10Chain();
}

/* @addr 0x00438f50 */
void SetJmp_StateDispatchYield_00438f50(void) {
    g_walkCallback = (void (*)(void))0x00000004;
    StateDispatchYield();
}

/* @addr 0x00438f60 */
void SetJmp_StateDispatchYield_00438f60(void) {
    g_walkCallback = (void (*)(void))0x00000005;
    StateDispatchYield();
}

/* @addr 0x00438f70 */
void SetJmp_StateDispatchYield_00438f70(void) {
    g_walkCallback = (void (*)(void))0x00000006;
    StateDispatchYield();
}

/* @addr 0x00439c30 */
void SetJmp_HitReactionDispatcher(void) {
    g_eventQueueNotMask = 0x00010029;
    HitReactionDispatcher();
}

/* @addr 0x00440710 */
void SetJmp_AudioBridgeMStackChainCopy_00440710(void) {
    g_walkCallback = (void (*)(void))0x000001f4;
    AudioBridgeMStackChainCopy();
}

/* @addr 0x00440720 */
void SetJmp_AudioBridgeMStackChainCopy_00440720(void) {
    g_walkCallback = (void (*)(void))0x0000002d;
    AudioBridgeMStackChainCopy();
}

/* @addr 0x00451aa0 */
void SetJmp_SetJmp_00451ad0_00451aa0(void) {
    g_walkCallback = (void (*)(void))0x00000005;
    SetJmp_GuardedSeq_00473f10_00451ad0();
}

/* @addr 0x00451ab0 */
void SetJmp_SetJmp_00451ad0_00451ab0(void) {
    g_walkCallback = (void (*)(void))0x00000002;
    SetJmp_GuardedSeq_00473f10_00451ad0();
}

/* @addr 0x00451ac0 */
void SetJmp_SetJmp_00451ad0_00451ac0(void) {
    g_walkCallback = (void (*)(void))0x00000003;
    SetJmp_GuardedSeq_00473f10_00451ad0();
}

/* @addr 0x00451ad0 */
void SetJmp_GuardedSeq_00473f10_00451ad0(void) {
    g_acc_00542078 = 0x00000006;
    GuardedSeq_00473f10();
}

/* @addr 0x00451ae0 */
void SetJmp_SetJmp_00451b10_00451ae0(void) {
    g_walkCallback = (void (*)(void))0x00000006;
    SetJmp_GuardedSeq_00473f10_00451b10();
}

/* @addr 0x00451af0 */
void SetJmp_SetJmp_00451b10_00451af0(void) {
    g_walkCallback = (void (*)(void))0x00000002;
    SetJmp_GuardedSeq_00473f10_00451b10();
}

/* @addr 0x00451b00 */
void SetJmp_SetJmp_00451b10_00451b00(void) {
    g_walkCallback = (void (*)(void))0x00000003;
    SetJmp_GuardedSeq_00473f10_00451b10();
}

/* @addr 0x00451b10 */
void SetJmp_GuardedSeq_00473f10_00451b10(void) {
    g_acc_00542078 = 0x00000005;
    GuardedSeq_00473f10();
}

/* @addr 0x00451b20 */
void SetJmp_SetJmp_00451b50_00451b20(void) {
    g_walkCallback = (void (*)(void))0x00000005;
    SetJmp_GuardedSeq_00473f10_00451b50();
}

/* @addr 0x00451b30 */
void SetJmp_SetJmp_00451b50_00451b30(void) {
    g_walkCallback = (void (*)(void))0x00000002;
    SetJmp_GuardedSeq_00473f10_00451b50();
}

/* @addr 0x00451b40 */
void SetJmp_SetJmp_00451b50_00451b40(void) {
    g_walkCallback = (void (*)(void))0x00000003;
    SetJmp_GuardedSeq_00473f10_00451b50();
}

/* @addr 0x00451b50 */
void SetJmp_GuardedSeq_00473f10_00451b50(void) {
    g_acc_00542078 = 0x0000000c;
    GuardedSeq_00473f10();
}

/* @addr 0x00451b60 */
void SetJmp_JuggleFsmCluster_00451b60(void) {
    g_walkCallback = (void (*)(void))0x00000006;
    JuggleFsmCluster();
}

/* @addr 0x00451b70 */
void SetJmp_JuggleFsmCluster_00451b70(void) {
    g_walkCallback = (void (*)(void))0x00000002;
    JuggleFsmCluster();
}

/* @addr 0x00451b80 */
void SetJmp_JuggleFsmCluster_00451b80(void) {
    g_walkCallback = (void (*)(void))0x00000003;
    JuggleFsmCluster();
}

/* @addr 0x004561c0 */
void SetJmp_CharSelectFsmCluster_004561c0(void) {
    g_walkCallback = (void (*)(void))0x00000003;
    CharSelectFsmCluster();
}

/* @addr 0x004561d0 */
void SetJmp_CharSelectFsmCluster_004561d0(void) {
    g_walkCallback = (void (*)(void))0x00000009;
    CharSelectFsmCluster();
}

/* @addr 0x004561e0 */
void SetJmp_CharSelectFsmCluster_004561e0(void) {
    g_walkCallback = (void (*)(void))0x0000000a;
    CharSelectFsmCluster();
}

/* @addr 0x0045ebf0 */
void SetJmp_SixSubdispatchSpan_0045ebf0(void) {
    g_eventQueueCurrent = 0x00000002;
    SixSubdispatchSpan();
}

/* @addr 0x0045ec00 */
void SetJmp_SixSubdispatchSpan_0045ec00(void) {
    g_eventQueueCurrent = 0x00000001;
    SixSubdispatchSpan();
}

/* @addr 0x004609c0 */
void SetJmp_AlarmCountdownInstall_004609c0(void) {
    g_walkCallback = (void (*)(void))0x00000000;
    AlarmCountdownInstall();
}

/* @addr 0x004609d0 */
void SetJmp_AlarmCountdownInstall_004609d0(void) {
    g_walkCallback = (void (*)(void))0x00000001;
    AlarmCountdownInstall();
}

/* @addr 0x004753a0 */
void SetJmp_InstallSelfChainEsi(void) {
    g_eventQueueIdx = 0x00475570;
    InstallSelfChainEsi();
}

/* @addr 0x00483b40 */
void SetJmp_MStackPush4IndirectCall(void) {
    g_currentNodeIdx = 0x00494580;
    MStackPush4IndirectCall();
}

/* @addr 0x00483f20 */
void SetJmp_InstallSelfTwoTailJmp(void) {
    g_eventQueueNotMask = 0x0000000a;
    InstallSelfTwoTailJmp();
}

/* @addr 0x00485d60 */
void SetJmp_DualLoadDualStoreJmp(void) {
    g_acc_00542078 = 0x00010000;
    DualLoadDualStoreJmp();
}

/* @addr 0x00487910 */
void SetJmp_InstallSelfMStackIndirect(void) {
    g_eventQueueEnd = 0x00000000;
    InstallSelfMStackIndirect();
}

/* @addr 0x00489020 */
void SetJmp_ScaledLitLoadCall_00481020(void) {
    g_walkCallback = (void (*)(void))0x00000002;
    ScaledLitLoadCall_00481020();
}

/* @addr 0x0048acc0 */
void SetJmp_Phase3InstallTableCheck(void) {
    g_currentNodeFlags = 0x00010000;
    Phase3InstallTableCheck();
}

/* @addr 0x0049cb90 */
void SetJmp_Thunk_LinkedListBitMaskSearch(void) {
    g_eventQueueCurrent = 0xffffffff;
    Thunk_LinkedListBitMaskSearch();
}

/* @addr 0x004a1ac0 */
void SetJmp_Push16Call_004a1ac0(void) {
    g_eventQueueWorkType = 0x00000325;
    Push16Call();
}

/* @addr 0x004a1ad0 */
void SetJmp_Push16Call_004a1ad0(void) {
    g_eventQueueWorkType = 0x00000320;
    Push16Call();
}

/* @addr 0x004bea40 */
void Helper_TitleAudioCleanup(void) {
    g_setjmp = 0x00000000;
    IncCallVtablePushCall();
}

