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
extern unsigned int g_state_00542094;
extern unsigned int g_state_00535ddc;
extern unsigned int g_state_00537e88;
extern unsigned int g_state_0053a408;
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
extern unsigned int g_state_00541fa4;
extern unsigned int g_state_00541fa8;
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
extern unsigned int g_state_00538158;
extern unsigned int g_data_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_data_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_data_00535e70;
extern unsigned int g_data_00535e74;
extern unsigned int g_data_00535e78;
extern unsigned int g_data_00535e7c;

extern unsigned int g_data_004f6264;
extern unsigned int g_data_004f63e8;
extern unsigned int g_data_004f63ea;
extern unsigned int g_data_004f63ec;
extern unsigned int g_data_004f63ee;
extern unsigned int g_data_004f63f0;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_xformEntityIdx;
extern unsigned int g_data_007af958;
extern unsigned int g_data_007af95e;
extern unsigned int g_data_007af964;
extern unsigned int g_data_007af96c;
extern unsigned int g_data_007af978;
extern unsigned int g_data_007af984;
extern unsigned int g_data_007af992;
extern unsigned int g_data_007af994;
extern unsigned int g_data_007af998;
extern unsigned int g_data_007af99a;
extern unsigned int g_data_007af99e;
extern unsigned int g_data_007af9a0;
extern unsigned int g_data_007af9a4;
extern unsigned int g_data_007af9a8;
extern unsigned int g_data_007af9ac;
extern unsigned int g_data_00ab44f8;
extern unsigned int g_data_00ab44fa;
extern unsigned int g_data_00ab44fc;
extern unsigned int g_data_00ab44fe;
extern unsigned int g_data_00ab4500;
extern unsigned int g_data_00ab4502;
extern unsigned int g_data_00ab4e2c;
extern unsigned int g_data_00ab51f4;
extern unsigned int g_data_00ab51f8;

__declspec(naked) void BboxProjectAndStash_004bc5a0(void)
{
    __asm {
        mov      eax, dword ptr [g_xformEntityIdx]
        sub      esp, 0xc
        push     ebx
        push     ebp
        push     esi
        push     edi
        mov      edi, dword ptr [eax*4 + 0x1c]
        test     edi, edi
        mov      dword ptr [g_walkCallback], edi
        jle      L_c7d1
        cmp      edi, 0x10
        jg       L_c7d1
        shl      edi, 4
        mov      al, byte ptr [edi + g_data_004f63e8]
        test     al, al
        jne      L_c7d1
        mov      eax, dword ptr [g_data_00ab4e2c]
        cmp      eax, OFFSET g_data_004f6264
        jne      L_c5f6
        mov      eax, dword ptr [g_data_00ab51f8]
        test     eax, eax
        jne      L_c7d1
        jmp      L_c60b
    L_c5f6:
        mov      dword ptr [g_data_00ab51f8], 0
        mov      cl, byte ptr [eax]
        cmp      cl, 1
        jne      L_c7d1
    L_c60b:
        mov      cx, word ptr [edi + g_data_004f63ea]
        mov      dx, word ptr [edi + g_data_004f63ee]
        movsx    eax, word ptr [g_data_007af992]
        movsx    ebp, word ptr [g_data_007af994]
        movsx    ebx, cx
        movsx    ecx, dx
        mov      dword ptr [esp + 0x10], ebx
        mov      dword ptr [esp + 0x14], ecx
        imul     ebx, eax
        mov      eax, dword ptr [esp + 0x14]
        mov      word ptr [g_data_007af958], 0
        imul     eax, ebp
        movsx    ecx, word ptr [g_data_007af998]
        movsx    esi, word ptr [g_data_007af99a]
        add      ebx, eax
        mov      eax, dword ptr [g_data_007af9a4]
        sar      ebx, 0xc
        add      ebx, eax
        mov      ebp, esi
        movsx    eax, bx
        mov      dword ptr [g_currentNodeIdx], eax
        mov      eax, dword ptr [esp + 0x14]
        mov      ebx, ecx
        imul     ebp, eax
        imul     ebx, dword ptr [esp + 0x10]
        movsx    edx, word ptr [g_data_007af99e]
        add      ebx, ebp
        mov      ebp, dword ptr [g_data_007af9a8]
        sar      ebx, 0xc
        add      ebx, ebp
        mov      dword ptr [esp + 0x18], edx
        movsx    edx, word ptr [g_data_007af9a0]
        movsx    ebx, bx
        mov      dword ptr [g_xformEntityIdx], ebx
        mov      ebx, edx
        imul     ebx, eax
        mov      eax, dword ptr [esp + 0x18]
        mov      bp, word ptr [g_currentNodeIdx]
        imul     eax, dword ptr [esp + 0x10]
        add      ebx, eax
        mov      eax, dword ptr [g_data_007af9ac]
        sar      ebx, 0xc
        add      ebx, eax
        mov      eax, dword ptr [g_data_00ab51f4]
        movsx    ebx, bx
        lea      eax, [eax + eax*2]
        shl      eax, 1
        mov      word ptr [eax + g_data_00ab44f8], bp
        mov      bp, word ptr [g_xformEntityIdx]
        mov      word ptr [eax + g_data_00ab44fa], bp
        mov      word ptr [eax + g_data_00ab44fc], bx
        mov      bx, word ptr [edi + g_data_004f63ec]
        mov      di, word ptr [edi + g_data_004f63f0]
        mov      word ptr [g_data_007af95e], bx
        mov      word ptr [g_data_007af964], di
        movsx    ebx, bx
        mov      dword ptr [esp + 0x10], ebx
        mov      ebp, ebx
        movsx    ebx, word ptr [g_data_007af992]
        movsx    edi, di
        imul     ebp, ebx
        mov      dword ptr [esp + 0x14], edi
        mov      ebx, edi
        movsx    edi, word ptr [g_data_007af994]
        imul     ebx, edi
        mov      edi, dword ptr [g_data_007af9a4]
        add      ebp, ebx
        mov      ebx, dword ptr [esp + 0x14]
        sar      ebp, 0xc
        imul     esi, ebx
        add      ebp, edi
        mov      edi, dword ptr [esp + 0x10]
        imul     ecx, edi
        add      ecx, esi
        mov      esi, dword ptr [g_data_007af9a8]
        sar      ecx, 0xc
        add      ecx, esi
        movsx    ebp, bp
        movsx    esi, cx
        mov      dword ptr [g_data_007af96c], ebp
        mov      dword ptr [g_data_007af978], esi
        mov      ecx, dword ptr [esp + 0x18]
        imul     edx, ebx
        imul     ecx, edi
        add      edx, ecx
        mov      ecx, dword ptr [g_data_007af9ac]
        sar      edx, 0xc
        add      edx, ecx
        mov      dword ptr [g_currentNodeIdx], ebp
        movsx    ecx, dx
        mov      dx, word ptr [g_data_007af978]
        mov      dword ptr [g_data_007af984], ecx
        mov      dword ptr [g_eventQueueCurrent], ecx
        mov      cx, word ptr [g_data_007af96c]
        mov      word ptr [eax + g_data_00ab44fe], cx
        mov      cx, word ptr [g_data_007af984]
        mov      word ptr [eax + g_data_00ab4500], dx
        mov      word ptr [eax + g_data_00ab4502], cx
        mov      eax, dword ptr [g_data_00ab51f4]
        mov      dword ptr [g_xformEntityIdx], esi
        add      eax, 2
        mov      dword ptr [g_data_00ab51f4], eax
    L_c7d1:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0xc
        ret
    }
}
