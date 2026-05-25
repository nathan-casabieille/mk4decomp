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
extern unsigned int g_audioBankSel_00537f94;
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
extern unsigned int g_rangeSqLimit_0053a180;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_dualBitGate_0053a7b0;
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
extern unsigned int g_stateCountdown_0053a3c0;
extern unsigned int g_player1NodeIdx;
extern unsigned int g_installOwnerNode_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_audioBoundNode_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

extern unsigned int g_data_004ffd44;
extern unsigned int g_data_004ffd48;
extern unsigned int g_data_004ffd4c;
extern unsigned int g_data_00b2d008;
extern unsigned int g_data_00b2d00c;
extern unsigned int g_data_00f4d040;
extern unsigned int g_data_00f4d044;
extern unsigned int g_data_00f70f4c;
extern unsigned int g_data_00f70f50;
extern unsigned int g_data_00f70f70;
extern unsigned int g_data_00f70f88;
extern unsigned int g_data_00f70f90;
extern unsigned int g_data_00f70f98;
extern unsigned int g_data_00f70f9a;
extern unsigned int g_data_00f70fa0;
extern unsigned int g_data_00f70fa8;
extern unsigned int g_data_00f70fb0;
extern unsigned int g_data_00f70fb8;
extern unsigned int g_data_00f70fc0;
extern unsigned int g_data_00f70fd8;
extern unsigned int g_data_00f70fda;
extern unsigned int g_data_00f85b34;
extern unsigned int g_data_00f85b4c;
extern unsigned int g_data_00f85b50;
extern unsigned int g_data_00f85b54;
extern unsigned int g_data_00f85b58;

__declspec(naked) void ScanlineTexBlitAdditive_004c0e10(void)
{
    __asm {
        mov      eax, dword ptr [g_data_00f85b50]
        push     ebx
        push     ebp
        push     esi
        test     eax, eax
        push     edi
        je       L_1129
        mov      ecx, dword ptr [g_data_00f70fa8]
        mov      eax, dword ptr [g_data_004ffd44]
        cmp      ecx, eax
        jge      L_1129
        mov      edi, dword ptr [g_data_00f70fb8]
        mov      eax, dword ptr [g_data_004ffd48]
        cmp      edi, eax
        jge      L_1129
        mov      ebp, dword ptr [g_data_00f70fb0]
        test     ebp, ebp
        jl       L_1129
        mov      eax, dword ptr [g_data_00f70fc0]
        test     eax, eax
        jl       L_1129
        sub      ebp, ecx
        sub      eax, edi
        cmp      ebp, 1
        mov      dword ptr [g_data_00b2d00c], ebp
        mov      dword ptr [g_data_00b2d008], eax
        jl       L_1129
        cmp      eax, 1
        jl       L_1129
        mov      eax, dword ptr [g_data_00f70f98]
        mov      edx, dword ptr [g_data_00f70f88]
        shl      eax, 0x10
        mov      dword ptr [g_data_00f70f98], eax
        mov      eax, dword ptr [g_data_00f70f90]
        shl      eax, 0x10
        shl      edx, 0x10
        mov      dword ptr [g_data_00f70f90], eax
        sub      eax, edx
        mov      dword ptr [g_data_00f70f88], edx
        mov      ebx, dword ptr [g_data_00f70fa0]
        cdq
        idiv     ebp
        shl      ebx, 0x10
        mov      dword ptr [g_data_00f70fa0], ebx
        mov      esi, eax
        mov      eax, ebx
        mov      ebx, dword ptr [g_data_00f70f98]
        mov      dword ptr [g_data_00f70f4c], esi
        sub      eax, ebx
        cdq
        idiv     dword ptr [g_data_00b2d008]
        test     ecx, ecx
        mov      dword ptr [g_data_00f70f50], eax
        jge      L_0f05
        mov      edx, esi
        mov      ebx, dword ptr [g_data_00f70f88]
        imul     edx, ecx
        sub      ebx, edx
        add      ebp, ecx
        xor      ecx, ecx
        mov      dword ptr [g_data_00f70f88], ebx
        mov      dword ptr [g_data_00b2d00c], ebp
        mov      dword ptr [g_data_00f70fa8], ecx
    L_0f05:
        test     edi, edi
        jge      L_0f2e
        imul     eax, edi
        mov      edx, dword ptr [g_data_00f70f98]
        sub      edx, eax
        mov      eax, dword ptr [g_data_00b2d008]
        add      eax, edi
        xor      edi, edi
        mov      dword ptr [g_data_00f70f98], edx
        mov      dword ptr [g_data_00b2d008], eax
        mov      dword ptr [g_data_00f70fb8], edi
    L_0f2e:
        mov      eax, dword ptr [g_data_004ffd44]
        mov      edx, dword ptr [g_data_00f70fb0]
        cmp      edx, eax
        jl       L_0f47
        sub      eax, ecx
        mov      ebp, eax
        mov      dword ptr [g_data_00b2d00c], ebp
    L_0f47:
        mov      eax, dword ptr [g_data_004ffd48]
        mov      edx, dword ptr [g_data_00f70fc0]
        cmp      edx, eax
        jl       L_0f5d
        sub      eax, edi
        mov      dword ptr [g_data_00b2d008], eax
    L_0f5d:
        mov      edx, dword ptr [g_data_00f85b54]
        mov      eax, dword ptr [g_data_00f85b50]
        imul     edx, edi
        add      eax, edx
        lea      edx, [eax + ecx*2]
        mov      eax, dword ptr [g_data_00f85b4c]
        mov      ecx, dword ptr [g_data_00b2d008]
        and      eax, 0xf
        shl      eax, 0x10
        test     ecx, ecx
        mov      dword ptr [g_data_00f4d044], edx
        mov      dword ptr [g_data_00f85b4c], eax
        jle      L_1129
        jmp      L_0f9b
    L_0f96:
        mov      eax, dword ptr [g_data_00f85b4c]
    L_0f9b:
        mov      ecx, dword ptr [g_data_00f70f88]
        mov      dword ptr [g_data_00f4d040], edx
        mov      dword ptr [g_data_00f70fd8], ecx
        xor      ecx, ecx
        mov      ch, byte ptr [g_data_00f70f9a]
        mov      dword ptr [g_data_00f70f70], ebp
        add      ecx, eax
        mov      eax, dword ptr [g_data_00f85b34]
        lea      ecx, [eax + ecx*2]
        mov      eax, dword ptr [g_data_004ffd4c]
        test     eax, eax
        mov      dword ptr [g_data_00f85b58], ecx
        je       L_1071
        test     ebp, ebp
        jle      L_10ee
    L_0fe0:
        mov      edi, dword ptr [g_data_00f85b58]
        xor      ecx, ecx
        mov      cl, byte ptr [g_data_00f70fda]
        xor      eax, eax
        mov      ax, word ptr [edi + ecx*2]
        test     ax, ax
        je       L_1045
        mov      cx, word ptr [edx]
        and      eax, 0xf7de
        and      ecx, 0xf7de
        add      ecx, eax
        mov      eax, ecx
        and      eax, 0x10820
        mov      edi, eax
        mov      esi, eax
        shr      edi, 1
        and      esi, 0xffff00ff
        and      edi, 0x7f80
        or       esi, edi
        shr      esi, 5
        sub      eax, esi
        or       eax, ecx
        and      eax, 0xf7de
        mov      word ptr [edx], ax
        mov      ebp, dword ptr [g_data_00b2d00c]
        mov      esi, dword ptr [g_data_00f70f4c]
        mov      edx, dword ptr [g_data_00f4d040]
    L_1045:
        mov      eax, dword ptr [g_data_00f70f70]
        mov      ebx, dword ptr [g_data_00f70fd8]
        dec      eax
        add      ebx, esi
        add      edx, 2
        mov      dword ptr [g_data_00f70f70], eax
        test     eax, eax
        mov      dword ptr [g_data_00f70fd8], ebx
        mov      dword ptr [g_data_00f4d040], edx
        jg       L_0fe0
        jmp      L_10ee
    L_1071:
        test     ebp, ebp
        jle      L_10ee
    L_1075:
        mov      edi, dword ptr [g_data_00f85b58]
        xor      ecx, ecx
        mov      cl, byte ptr [g_data_00f70fda]
        xor      eax, eax
        mov      ax, word ptr [edi + ecx*2]
        test     ax, ax
        je       L_10c8
        mov      cx, word ptr [edx]
        and      eax, 0x7bde
        and      ecx, 0x7bde
        add      ecx, eax
        mov      eax, ecx
        and      eax, 0x8420
        mov      esi, eax
        shr      esi, 5
        sub      eax, esi
        or       eax, ecx
        and      eax, 0x7bde
        mov      word ptr [edx], ax
        mov      ebp, dword ptr [g_data_00b2d00c]
        mov      esi, dword ptr [g_data_00f70f4c]
        mov      edx, dword ptr [g_data_00f4d040]
    L_10c8:
        mov      eax, dword ptr [g_data_00f70f70]
        mov      ebx, dword ptr [g_data_00f70fd8]
        dec      eax
        add      ebx, esi
        add      edx, 2
        mov      dword ptr [g_data_00f70f70], eax
        test     eax, eax
        mov      dword ptr [g_data_00f70fd8], ebx
        mov      dword ptr [g_data_00f4d040], edx
        jg       L_1075
    L_10ee:
        mov      edx, dword ptr [g_data_00f70f50]
        mov      ebx, dword ptr [g_data_00f70f98]
        mov      eax, dword ptr [g_data_00b2d008]
        mov      edi, dword ptr [g_data_00f85b54]
        add      ebx, edx
        mov      edx, dword ptr [g_data_00f4d044]
        dec      eax
        add      edx, edi
        test     eax, eax
        mov      dword ptr [g_data_00b2d008], eax
        mov      dword ptr [g_data_00f70f98], ebx
        mov      dword ptr [g_data_00f4d044], edx
        jg       L_0f96
    L_1129:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    }
}
