/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown_0053a718;
extern unsigned int g_xformScratch94;
extern unsigned int g_table_00535ddc;
extern unsigned int g_active_00537e88;
extern unsigned int g_active_0053a408;
extern unsigned int g_audioBankSel_00537f94;

extern void StoreTwoCall_0049cb40(int, int);
extern void SetJmp_0049cb90(void);
extern void Thunk_0049cbd0(void);
extern void ScaledZeroFour_00490740(void);
extern void WalkCbSubMul10_00431d50(void);
extern void Mul10Tail_00404af0(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10_00407510(void);
extern void SpawnListBatchLoader_00477710(void);
extern void MStackPush2TableNot_00426230(void);
extern void GuardedChainCmpDualBitXor_004299a0(void);
extern void ScaledLoadDecJmp_00429710(void);
extern void ScaledStoreCurDirtyClear_004296f0(void);
extern void MStackBitmaskIncMod_00492450(void);
extern void MStackBitmaskUpdate_00492510(void);
extern void Push1eCallTestDirtyLoop_004923b0(void);
extern void MStackLoopFieldInit_00492280(void);
extern void TaggedSceneDispatch_004be690(void);
extern void CallPauseDirty4StackPushFn_004839d0(void);
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall_004398b0(void);
extern void QuadBlockArgInstallChain_0043a950(void);
extern void InstallSelfChainSet84_80CallW_004363f0(void);
extern void Wrapper_00436490(void);
extern void MoveFsmCluster_004364a0(void);
extern void CallPauseTestByteJmpCalls_004390f0(void);
extern void InstallSelfFullPath_0047a840(void);
extern void InstallSelfCountdownChain_0047a950(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore_00476880(void);
extern void Thunk_004bd5c0(void);
extern void AllocSlotPushTripleGlobals_00427470(void);
extern void MStackPop4Rewrite_004274f0(void);
extern void Push70CallScaleArith_00457ad0(void);
extern void StreamChainStringInstall_00457900(void);
extern void MStackFrameCdeclDouble_004903f0(void);
extern void ChainTableWalkStore_004917e0(void);
extern void Push16Call_00489f50(void);
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm_0048f2a0(void);
extern void StackPopDispatchTagged_0041f780(void);
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit_0053a180;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_dualBitGate_0053a7b0;
extern unsigned int g_eventArmReload_0053a770;
extern unsigned int g_rangeBase_0053a46c;

extern void ScaledArrStore_004298c0(void);
extern void DualFieldAddSubStore_00470340(void);
extern void IterStepDualStore_00490b40(int);
extern void ScaledXorStore_004900f0(void);
extern void ChainWalkInstall_0049b7c0(void);
extern void FpuSqrtMul_004ab350(void);
extern void PendingMatch_0042b930(void);
extern void MStackPush2RunCountdown_004089e0(void);
extern void MStackBracket7_DispatchAndChain_004b8fa0(void);
extern void MStackBracketed3StoreCall_00475990(void);
extern void ChainDirtyBitWalker_00408c10(void);
extern void Wrapper_0048a350(void);
extern void Wrapper_0048a3a0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall_0048eec0(void);
extern void Wrapper_0048ec20(void);
extern void FiveCallScaledChainTailJmp_0045f8d0(void);
extern void SetJmp_00438f50(void);
extern void SetJmp_00438f60(void);
extern void GuardedDispatch_0042b6c0(void);
extern void MStackPushZeroCallPop_00407d00(void);
extern void DirtyToggleByGate_0048f350(void);
extern void GameDispatchValidateState_004339c0(void);
extern void CrouchAttackFsmCluster_0046f7a0(void);
extern void MStackPushVec3Mul10_004767e0(void);
extern void LiteralPushCallEntZero_00488c00(void);
extern void LeaPlus22StoreSelf_0048e4d0(void);
extern void IterLoad_00491050(void);
extern void GuardedDualConst2AndToggle_0048eba0(void);
extern void CallPauseScaledStorePushCall_0045fca0(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_00407400(void);
extern void PushSetCallPop_00406530(void);
extern unsigned int g_stateCountdown_0053a3c0;
extern unsigned int g_installOwnerNode_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_audioBoundNode_005437f0;
extern unsigned int g_lastGatedValue_00543598;
extern unsigned int g_lastGatedTick_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

extern void CrtInitPerThreadData_004c9df0(void);
extern void ArraySearch_004cba90(void);
extern unsigned int g_crtSehFpuDispatch_005228f8;
extern unsigned int g_crtSehFpuDispatch2_005228fc;
extern unsigned int g_iat_004d20f8;

__declspec(naked) void SehFpuExceptionDispatch_004cb880(void)
{
    __asm {
        push     ecx
        push     ebx
        push     ebp
        push     esi
        push     edi
        call     CrtInitPerThreadData_004c9df0
        mov      ecx, dword ptr [esp + 0x18]
        mov      esi, eax
        mov      eax, dword ptr [esi + 0x50]
        push     eax
        push     ecx
        call     ArraySearch_004cba90
        xor      edi, edi
        add      esp, 8
        cmp      eax, edi
        je       L_ba7c
        mov      edx, dword ptr [eax + 8]
        cmp      edx, edi
        mov      dword ptr [esp + 0x18], edx
        je       L_ba7c
        cmp      edx, 5
        jne      short L_b8c9
        mov      dword ptr [eax + 8], edi
        mov      eax, 1
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        pop      ecx
        ret
    L_b8c9:
        cmp      edx, 1
        jne      short L_b8d7
        or       eax, 0xffffffff
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        pop      ecx
        ret
    L_b8d7:
        mov      ecx, dword ptr [esi + 0x54]
        mov      dword ptr [esp + 0x10], ecx
        mov      ecx, dword ptr [esp + 0x1c]
        mov      dword ptr [esi + 0x54], ecx
        mov      ecx, dword ptr [eax + 4]
        cmp      ecx, 8
        jne      L_ba63
        mov      ecx, dword ptr [g_crtSehFpuDispatch_005228f8]
        mov      ebx, dword ptr [g_crtSehFpuDispatch2_005228fc]
        add      ebx, ecx
        cmp      ecx, ebx
        jge      short L_b92a
        lea      edx, [ecx + ecx*2]
        shl      edx, 2
    L_b909:
        mov      ebx, dword ptr [esi + 0x50]
        inc      ecx
        mov      dword ptr [ebx + edx + 8], edi
        mov      ebx, dword ptr [g_crtSehFpuDispatch_005228f8]
        mov      ebp, dword ptr [g_crtSehFpuDispatch2_005228fc]
        add      edx, 0xc
        add      ebp, ebx
        cmp      ecx, ebp
        jl       short L_b909
        mov      edx, dword ptr [esp + 0x18]
    L_b92a:
        mov      eax, dword ptr [eax]
        mov      edi, dword ptr [esi + 0x58]
        cmp      eax, 0xc000008e
        jne      short L_b95b
        mov      dword ptr [esi + 0x58], 0x83
        mov      eax, dword ptr [esi + 0x58]
        push     eax
        push     8
        call     edx
        mov      ecx, dword ptr [esp + 0x18]
        add      esp, 8
        mov      dword ptr [esi + 0x58], edi
        mov      dword ptr [esi + 0x54], ecx
        or       eax, 0xffffffff
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        pop      ecx
        ret
    L_b95b:
        cmp      eax, 0xc0000090
        jne      short L_b987
        mov      dword ptr [esi + 0x58], 0x81
        mov      eax, dword ptr [esi + 0x58]
        push     eax
        push     8
        call     edx
        mov      ecx, dword ptr [esp + 0x18]
        add      esp, 8
        mov      dword ptr [esi + 0x58], edi
        mov      dword ptr [esi + 0x54], ecx
        or       eax, 0xffffffff
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        pop      ecx
        ret
    L_b987:
        cmp      eax, 0xc0000091
        jne      short L_b9b3
        mov      dword ptr [esi + 0x58], 0x84
        mov      eax, dword ptr [esi + 0x58]
        push     eax
        push     8
        call     edx
        mov      ecx, dword ptr [esp + 0x18]
        add      esp, 8
        mov      dword ptr [esi + 0x58], edi
        mov      dword ptr [esi + 0x54], ecx
        or       eax, 0xffffffff
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        pop      ecx
        ret
    L_b9b3:
        cmp      eax, 0xc0000093
        jne      short L_b9df
        mov      dword ptr [esi + 0x58], 0x85
        mov      eax, dword ptr [esi + 0x58]
        push     eax
        push     8
        call     edx
        mov      ecx, dword ptr [esp + 0x18]
        add      esp, 8
        mov      dword ptr [esi + 0x58], edi
        mov      dword ptr [esi + 0x54], ecx
        or       eax, 0xffffffff
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        pop      ecx
        ret
    L_b9df:
        cmp      eax, 0xc000008d
        jne      short L_ba0b
        mov      dword ptr [esi + 0x58], 0x82
        mov      eax, dword ptr [esi + 0x58]
        push     eax
        push     8
        call     edx
        mov      ecx, dword ptr [esp + 0x18]
        add      esp, 8
        mov      dword ptr [esi + 0x58], edi
        mov      dword ptr [esi + 0x54], ecx
        or       eax, 0xffffffff
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        pop      ecx
        ret
    L_ba0b:
        cmp      eax, 0xc000008f
        jne      short L_ba37
        mov      dword ptr [esi + 0x58], 0x86
        mov      eax, dword ptr [esi + 0x58]
        push     eax
        push     8
        call     edx
        mov      ecx, dword ptr [esp + 0x18]
        add      esp, 8
        mov      dword ptr [esi + 0x58], edi
        mov      dword ptr [esi + 0x54], ecx
        or       eax, 0xffffffff
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        pop      ecx
        ret
    L_ba37:
        cmp      eax, 0xc0000092
        jne      short L_ba45
        mov      dword ptr [esi + 0x58], 0x8a
    L_ba45:
        mov      eax, dword ptr [esi + 0x58]
        push     eax
        push     8
        call     edx
        mov      ecx, dword ptr [esp + 0x18]
        add      esp, 8
        mov      dword ptr [esi + 0x58], edi
        mov      dword ptr [esi + 0x54], ecx
        or       eax, 0xffffffff
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        pop      ecx
        ret
    L_ba63:
        push     ecx
        mov      dword ptr [eax + 8], edi
        call     edx
        mov      ecx, dword ptr [esp + 0x14]
        add      esp, 4
        mov      dword ptr [esi + 0x54], ecx
        or       eax, 0xffffffff
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        pop      ecx
        ret
    L_ba7c:
        mov      edx, dword ptr [esp + 0x1c]
        push     edx
        call     dword ptr [g_iat_004d20f8]
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        pop      ecx
        ret
    }
}
