/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_state_004d57ac;
extern unsigned int g_scaledInit_00542044;
extern packed_ptr g_xformEntityIdx;
extern u32 g_eventQueueEnd;
extern unsigned int g_baseSel_00542060;
extern u32 g_eventQueueWorkType;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern u32 g_framePauseFlag;
extern unsigned int g_state_0053a718;
extern unsigned int g_eventQueueTotal;
extern unsigned int g_eventQueueCurrent;
extern unsigned int g_currentNodeFlags;
extern unsigned int g_xformDirtyFlags;
extern unsigned int g_xformScratch2088;
extern unsigned int g_xformScratch94;
extern unsigned int g_table_00535ddc;
extern unsigned int g_active_00537e88;
extern unsigned int g_active_0053a408;
extern unsigned int g_state_00537f94;
extern unsigned int g_eventQueueChild;
extern u32 g_pendingNodeType;

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
extern unsigned int g_eventQueueNotMask;
extern unsigned int g_cj_00542058;
extern unsigned int g_data_0053a180;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_state_0053a7b0;
extern unsigned int g_data_0053a770;
extern unsigned int g_data_0053a46c;

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
extern unsigned int g_state_0053a3c0;
extern unsigned int g_player1NodeIdx;
extern unsigned int g_installOwnerNode_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_data_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

__declspec(naked) void BucketBlockAllocSplit_004c7670(void)
{
    __asm {
        mov      edx, dword ptr [esp + 0xc]
        push     ebx
        push     ebp
        push     esi
        push     edi
        mov      edi, dword ptr [esp + 0x14]
        mov      eax, dword ptr [edi + 4]
        mov      ecx, dword ptr [edi]
        cmp      eax, edx
        mov      dword ptr [esp + 0x14], ecx
        mov      esi, ecx
        lea      ebx, [edi + 0xf8]
        jb       short L_76cb
        lea      eax, [ecx + edx]
        mov      byte ptr [ecx], dl
        cmp      eax, ebx
        jae      short L_76aa
        mov      esi, dword ptr [edi]
        mov      eax, dword ptr [edi + 4]
        add      esi, edx
        sub      eax, edx
        mov      dword ptr [edi], esi
        mov      dword ptr [edi + 4], eax
        jmp      short L_76b6
    L_76aa:
        lea      edx, [edi + 8]
        mov      dword ptr [edi + 4], 0
        mov      dword ptr [edi], edx
    L_76b6:
        lea      eax, [edi + edi*2]
        lea      eax, [eax + eax*4]
        mov      edx, eax
        lea      eax, [ecx + 8]
        shl      eax, 4
        sub      eax, edx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    L_76cb:
        add      eax, ecx
        cmp      byte ptr [eax], 0
        je       short L_76d4
        mov      esi, eax
    L_76d4:
        lea      eax, [esi + edx]
        cmp      eax, ebx
        mov      ebx, dword ptr [esp + 0x18]
        jae      short L_7754
    L_76df:
        mov      al, byte ptr [esi]
        test     al, al
        jne      short L_7721
        cmp      byte ptr [esi + 1], 0
        lea      eax, [esi + 1]
        mov      ecx, 1
        jne      short L_76fa
    L_76f3:
        inc      eax
        inc      ecx
        cmp      byte ptr [eax], 0
        je       short L_76f3
    L_76fa:
        cmp      ecx, edx
        jae      short L_7737
        mov      ebp, dword ptr [esp + 0x14]
        cmp      esi, ebp
        jne      short L_770f
        mov      dword ptr [edi + 4], ecx
        mov      esi, eax
        mov      ecx, ebp
        jmp      short L_7728
    L_770f:
        sub      ebx, ecx
        cmp      ebx, edx
        jb       L_77db
        mov      ecx, dword ptr [esp + 0x14]
        mov      esi, eax
        jmp      short L_7728
    L_7721:
        and      eax, 0xff
        add      esi, eax
    L_7728:
        lea      ebp, [esi + edx]
        lea      eax, [edi + 0xf8]
        cmp      ebp, eax
        jb       short L_76df
        jmp      short L_7754
    L_7737:
        lea      eax, [esi + edx]
        lea      ebx, [edi + 0xf8]
        cmp      eax, ebx
        jae      short L_774d
        sub      ecx, edx
        mov      dword ptr [edi], eax
        mov      dword ptr [edi + 4], ecx
        jmp      short L_77c6
    L_774d:
        lea      ecx, [edi + 8]
        mov      dword ptr [edi], ecx
        jmp      short L_77bf
    L_7754:
        lea      ebp, [edi + 8]
        mov      esi, ebp
        cmp      esi, ecx
        jae      short L_77db
    L_775d:
        lea      ecx, [esi + edx]
        lea      eax, [edi + 0xf8]
        cmp      ecx, eax
        jae      short L_77db
        mov      al, byte ptr [esi]
        test     al, al
        jne      short L_7793
        cmp      byte ptr [esi + 1], 0
        lea      eax, [esi + 1]
        mov      ecx, 1
        jne      short L_7785
    L_777e:
        inc      eax
        inc      ecx
        cmp      byte ptr [eax], 0
        je       short L_777e
    L_7785:
        cmp      ecx, edx
        jae      short L_77a7
        sub      ebx, ecx
        cmp      ebx, edx
        jb       short L_77db
        mov      esi, eax
        jmp      short L_779a
    L_7793:
        and      eax, 0xff
        add      esi, eax
    L_779a:
        cmp      esi, dword ptr [esp + 0x14]
        jb       short L_775d
        xor      eax, eax
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    L_77a7:
        lea      eax, [esi + edx]
        lea      ebx, [edi + 0xf8]
        cmp      eax, ebx
        jae      short L_77bd
        sub      ecx, edx
        mov      dword ptr [edi], eax
        mov      dword ptr [edi + 4], ecx
        jmp      short L_77c6
    L_77bd:
        mov      dword ptr [edi], ebp
    L_77bf:
        mov      dword ptr [edi + 4], 0
    L_77c6:
        lea      eax, [edi + edi*2]
        mov      byte ptr [esi], dl
        lea      edx, [eax + eax*4]
        lea      eax, [esi + 8]
        shl      eax, 4
        sub      eax, edx
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    L_77db:
        pop      edi
        pop      esi
        pop      ebp
        xor      eax, eax
        pop      ebx
        ret
    }
}
