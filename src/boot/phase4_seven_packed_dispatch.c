/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown;
extern unsigned int g_xformScratch94;
extern unsigned int g_table_00535ddc;
extern unsigned int g_active_00537e88;
extern unsigned int g_active_0053a408;
extern unsigned int g_audioBankSel;

extern void StoreTwoCall(int, int);
extern void SetJmp_Thunk_LinkedListBitMaskSearch(void);
extern void Thunk_ChainNodeInit(void);
extern void ScaledZeroFour(void);
extern void WalkCbSubMul10(void);
extern void Mul10Tail(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10(void);
extern void SpawnListBatchLoader(void);
extern void MStackPush2TableNot(void);
extern void GuardedChainCmpDualBitXor(void);
extern void ScaledLoadDecJmp(void);
extern void ScaledStoreCurDirtyClear(void);
extern void MStackBitmaskIncMod(void);
extern void MStackBitmaskUpdate(void);
extern void Push1eCallTestDirtyLoop(void);
extern void MStackLoopFieldInit(void);
extern void TaggedSceneDispatch(void);
extern void CallPauseDirty4StackPushFn(void);
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void InstallSelfChainSet84_80CallW(void);
extern void Wrapper_PackedAdvanceCallTailJmp_004e46d0(void);
extern void MoveFsmCluster(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain(void);
extern void CopyJmp_SlotCmp3way_g_currentNodeIdx(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_LoadGeoAsset_Default(void);
extern void AllocSlotPushTripleGlobals(void);
extern void MStackPop4Rewrite(void);
extern void Push70CallScaleArith(void);
extern void StreamChainStringInstall(void);
extern void MStackFrameCdeclDouble(void);
extern void ChainTableWalkStore(void);
extern void Push16Call(void);
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm(void);
extern void StackPopDispatchTagged(void);
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_dualBitGate;
extern unsigned int g_eventArmReload;
extern unsigned int g_rangeBase;

extern void ScaledArrStore_ScaledChainJmp_004298c0(void);
extern void DualFieldAddSubStore(void);
extern void IterStepDualStore(int);
extern void ScaledXorStore_004900f0(void);
extern void ChainWalkInstall(void);
extern void FpuSqrtMul(void);
extern void PendingMatch_0042b930(void);
extern void MStackPush2RunCountdown(void);
extern void MStackBracket7_DispatchAndChain(void);
extern void MStackBracketed3StoreCall(void);
extern void ChainDirtyBitWalker(void);
extern void Wrapper_ScaledChainPushCall_004ef858(void);
extern void Wrapper_ScaledChainPushCall_004ef8b0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_IterLoad_0048fd30_004f12a0(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_StateDispatchYield_00438f50(void);
extern void SetJmp_StateDispatchYield_00438f60(void);
extern void GuardedDispatch_0042b6c0(void);
extern void MStackPushZeroCallPop_00407d00(void);
extern void DirtyToggleByGate(void);
extern void GameDispatchValidateState(void);
extern void CrouchAttackFsmCluster(void);
extern void MStackPushVec3Mul10(void);
extern void LiteralPushCallEntZero(void);
extern void LeaPlus22StoreSelf(void);
extern void IterLoad_00491050(void);
extern void GuardedDualConst2AndToggle(void);
extern void CallPauseScaledStorePushCall(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_00407400(void);
extern void PushSetCallPop(void);
extern unsigned int g_stateCountdown;
extern unsigned int g_installOwnerNode;
extern unsigned int g_cj_00542054;
extern unsigned int g_audioBoundNode;
extern unsigned int g_lastGatedValue;
extern unsigned int g_lastGatedTick;
extern unsigned int g_fightAxisNegX;
extern unsigned int g_fightAxisNegY;
extern unsigned int g_fightAxisPosX;
extern unsigned int g_fightAxisPosY;

extern unsigned int g_const_0049db40;
extern void AudioMixerStep(void);
extern void BootStateTriple(void);
extern void CallSetPause(void);
extern void SetJmp_BootStateTriple(void);
extern void StoreDoubleNegPauseSubStore(void);
extern void ZeroThreeFields_0040a8b0(void);

__declspec(naked) void Phase4SevenPackedDispatch(void)
{
    __asm {
        call    MStackPush2RunCountdown
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4sp7_A_ret
        call    MStackBracket7_DispatchAndChain
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4sp7_A_ret
        mov     dword ptr [g_walkCallback], 2
        call    BootStateTriple
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4sp7_A_ret
        push    0xC0
        push    offset g_const_0049db40
        mov     dword ptr [g_eventQueueNotMask], 0xC1
        call    StoreTwoCall
        mov     al, byte ptr [g_xformDirtyFlags]
        add     esp, 8
        test    al, 1
        jne     L_p4sp7_A_ret
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     edx, dword ptr [g_currentNodeIdx]
        lea     ecx, [eax*4]
        lea     eax, [edx*4]
        mov     edx, dword ptr [g_eventQueueTotal]
        mov     dword ptr [eax + 0x28], edx
        mov     edx, dword ptr [ecx + 0x3C]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 0x38], edx
        mov     edx, dword ptr [ecx + 0x40]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 0x3C], edx
        mov     ecx, dword ptr [ecx + 0x44]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x40], ecx
        jmp     ZeroThreeFields_0040a8b0
    L_p4sp7_A_ret:
        ret
        nop
        nop
        nop
    L_p4sp7_B:
        call    SetJmp_BootStateTriple
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4sp7_B_ret
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [ecx*4 + 0x20]
        or      al, 0x40
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x20], eax
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     ecx, dword ptr [eax*4]
        or      ecx, 0x0A
        mov     dword ptr [eax*4], ecx
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     dword ptr [eax*4 + 0x48], 0x3333
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, 0x2147
        mov     dword ptr [ecx*4 + 0x10], 0x0049D200
        mov     edx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x70], eax
        jmp     CallSetPause
    L_p4sp7_B_ret:
        ret
        nop
        nop
        nop
    L_p4sp7_C:
        mov     eax, dword ptr [g_gameMode]
        test    eax, eax
        jne     L_p4sp7_C_ret
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     ecx, dword ptr [eax*4 + 0x48]
        add     ecx, 0x62
        mov     dword ptr [eax*4 + 0x48], ecx
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     ecx, dword ptr [eax*4 + 0x48]
        mov     dword ptr [g_walkCallback], ecx
    L_p4sp7_C_ret:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
    L_p4sp7_D:
        mov     eax, dword ptr [g_gameMode]
        test    eax, eax
        jne     L_p4sp7_D_ret
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     ecx, dword ptr [eax*4 + 0x48]
        add     ecx, 0x83
        mov     dword ptr [eax*4 + 0x48], ecx
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     ecx, dword ptr [eax*4 + 0x48]
        mov     dword ptr [g_walkCallback], ecx
    L_p4sp7_D_ret:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
    L_p4sp7_E:
        mov     eax, dword ptr [g_gameMode]
        test    eax, eax
        jne     L_p4sp7_E_ret
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     ecx, dword ptr [eax*4 + 0x48]
        add     ecx, 0xA3
        mov     dword ptr [eax*4 + 0x48], ecx
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     ecx, dword ptr [eax*4 + 0x48]
        mov     dword ptr [g_walkCallback], ecx
    L_p4sp7_E_ret:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
    L_p4sp7_F:
        mov     eax, dword ptr [g_gameMode]
        test    eax, eax
        jne     L_p4sp7_F_ret
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     ecx, dword ptr [eax*4 + 0x48]
        add     ecx, 0x3D7
        mov     dword ptr [eax*4 + 0x48], ecx
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     ecx, dword ptr [eax*4 + 0x48]
        mov     dword ptr [g_walkCallback], ecx
    L_p4sp7_F_ret:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
    L_p4sp7_G:
        call    SetJmp_BootStateTriple
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4sp7_G_ret
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [ecx*4 + 0x20]
        or      eax, 0x4040
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x20], eax
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     ecx, dword ptr [eax*4]
        or      ecx, 0x0A
        mov     dword ptr [eax*4], ecx
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     dword ptr [eax*4 + 0x10], 0x0049D200
        mov     dword ptr [g_walkCallback], 0x8000
        call    AudioMixerStep
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4sp7_G_ret
        mov     ecx, dword ptr [g_walkCallback]
        mov     edx, dword ptr [g_xformEntityIdx]
        add     ecx, 0x5999
        mov     dword ptr [edx*4 + 0x48], ecx
        mov     dword ptr [g_walkCallback], 0x10000
        call    StoreDoubleNegPauseSubStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4sp7_G_ret
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, dword ptr [g_walkCallback]
        mov     dword ptr [ecx*4 + 0x28], eax
        mov     dword ptr [g_walkCallback], 0x10000
        call    StoreDoubleNegPauseSubStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4sp7_G_ret
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     edx, dword ptr [g_walkCallback]
        mov     dword ptr [eax*4 + 0x2C], edx
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, 0x11EB
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x70], eax
        jmp     CallSetPause
    L_p4sp7_G_ret:
        ret
    }
}
