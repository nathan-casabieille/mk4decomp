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

extern void Helper_ECM_PostCleanup(void);
extern void ECM_Cleanup(void);
extern void EcmFrameDecode_004bec30(void);
/* extern void DoubleToInt64_004c57d0(void); -- defined elsewhere with diff sig */
extern unsigned int g_const_004d2998;
extern unsigned int g_const_004d29a0;
extern unsigned int g_const_004d29a8;
extern unsigned int g_const_004d29b0;
extern u32 g_ecmFrameIdx;
extern u32 g_ecmFrameTotal;
extern u8 g_ecmAudioSlots[];
extern unsigned int g_data_007aa224;
extern unsigned int g_data_007aa228;
extern unsigned int g_data_007aa234;
extern unsigned int g_data_007ab048;
extern void  * g_ecmFile;
extern u32 g_ecmFrameSizeDiv8;
extern unsigned int g_ecmDSBuffer;
extern u32 g_ecmRunFlag;
extern u32 g_ecmReserved;
extern HANDLE g_ecmThread;
extern u32 g_ecmVolumeFromFtol;
extern u32 g_ecmPlayState;

extern unsigned int g_iat_004d2074;
extern unsigned int g_iat_004d2084;
extern unsigned int g_iat_004d2240;
extern void DoubleToInt64_004c57d0(void);

__declspec(naked) void EcmStreamTickAdvance_004b0db0(void)
{
    __asm {
        mov      eax, dword ptr [g_ecmFile]
        sub      esp, 8
        push     ebx
        xor      ebx, ebx
        push     ebp
        push     esi
        cmp      eax, ebx
        push     edi
        je       L_1077
        mov      eax, dword ptr [g_ecmFrameSizeDiv8]
        mov      ecx, dword ptr [g_data_007aa234]
        cmp      eax, ecx
        jae      L_1077
        cmp      dword ptr [esp + 0x1c], ebx
        je       L_1077
        mov      ebp, dword ptr [esp + 0x20]
        cmp      ebp, ebx
        je       L_1077
        push     1
        call     Helper_ECM_PostCleanup
        mov      eax, dword ptr [g_ecmReserved]
        add      esp, 4
        cmp      eax, ebx
        je       L_0e4d
        mov      dword ptr [g_ecmReserved], ebx
        call     dword ptr [g_iat_004d2240]
        mov      ecx, dword ptr [g_ecmFrameSizeDiv8]
        mov      dword ptr [esp + 0x14], ebx
        mov      dword ptr [esp + 0x10], ecx
        mov      esi, eax
        fild     qword ptr [esp + 0x10]
        fmul     qword ptr [g_const_004d2998]
        fmul     qword ptr [g_const_004d29a0]
        fadd     qword ptr [g_const_004d29a8]
        call     DoubleToInt64_004c57d0
        sub      esi, eax
        mov      dword ptr [g_data_007ab048], ebx
        mov      dword ptr [g_data_007aa224], esi
        mov      dword ptr [g_data_007aa228], ebx
    L_0e4d:
        mov      eax, dword ptr [g_ecmFrameSizeDiv8]
        xor      edx, edx
        mov      ecx, 0xf
        div      ecx
        test     edx, edx
        jne      L_0e6f
        mov      eax, dword ptr [g_ecmThread]
        cmp      eax, ebx
        je       L_0e6f
        push     eax
        call     dword ptr [g_iat_004d2084]
    L_0e6f:
        mov      edx, dword ptr [g_ecmFrameTotal]
        mov      eax, dword ptr [g_ecmFrameIdx]
        mov      edi, dword ptr [g_iat_004d2074]
        cmp      edx, eax
        jle      L_0ee6
        mov      edx, dword ptr [g_ecmReserved]
        mov      eax, dword ptr [g_ecmDSBuffer]
        inc      edx
        cmp      eax, ebx
        mov      dword ptr [g_ecmReserved], edx
        je       L_0ea0
        mov      ecx, dword ptr [eax]
        push     eax
        call     dword ptr [ecx + 0x48]
    L_0ea0:
        mov      edx, dword ptr [g_ecmFrameTotal]
        mov      eax, dword ptr [g_ecmFrameIdx]
        xor      esi, esi
        cmp      edx, eax
        jle      L_0ecf
    L_0eb1:
        cmp      esi, 0xbb8
        jge      L_0eee
        push     0xa
        call     edi
        mov      eax, dword ptr [g_ecmFrameTotal]
        mov      ecx, dword ptr [g_ecmFrameIdx]
        add      esi, 0xa
        cmp      eax, ecx
        jg       L_0eb1
    L_0ecf:
        cmp      esi, 0xbb8
        jl       L_0ee6
        call     ECM_Cleanup
        xor      eax, eax
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 8
        ret
    L_0ee6:
        cmp      dword ptr [g_ecmPlayState], ebx
        je       L_0efd
    L_0eee:
        call     ECM_Cleanup
        xor      eax, eax
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 8
        ret
    L_0efd:
        mov      ecx, dword ptr [esp + 0x1c]
        mov      eax, dword ptr [g_ecmFrameSizeDiv8]
        push     ecx
        xor      edx, edx
        mov      ecx, 0xf
        push     ebp
        div      ecx
        mov      eax, dword ptr [g_ecmFrameTotal]
        push     edx
        cdq
        xor      eax, edx
        sub      eax, edx
        and      eax, 3
        xor      eax, edx
        sub      eax, edx
        imul     eax, eax, 0x5ab5c
        add      eax, OFFSET g_ecmAudioSlots
        push     eax
        call     EcmFrameDecode_004bec30
        add      esp, 0x10
        test     eax, eax
        jne      L_1077
        call     dword ptr [g_iat_004d2240]
        mov      edx, eax
        mov      eax, dword ptr [g_data_007ab048]
        sub      eax, edx
        dec      eax
        cmp      eax, ebx
        jle      L_0f56
        push     eax
        call     edi
    L_0f56:
        mov      eax, dword ptr [g_ecmDSBuffer]
        cmp      eax, ebx
        je       L_0fbf
        mov      ecx, dword ptr [eax]
        lea      edx, [esp + 0x1c]
        push     edx
        push     eax
        call     dword ptr [ecx + 0x24]
        test     byte ptr [esp + 0x1c], 1
        jne      L_0fbf
        mov      eax, dword ptr [g_ecmDSBuffer]
        mov      edx, dword ptr [g_ecmVolumeFromFtol]
        push     edx
        push     eax
        mov      ecx, dword ptr [eax]
        call     dword ptr [ecx + 0x3c]
        mov      ecx, dword ptr [g_ecmFrameSizeDiv8]
        xor      edx, edx
        mov      esi, dword ptr [g_ecmDSBuffer]
        lea      eax, [ecx + ecx*2]
        shl      eax, 4
        add      eax, ecx
        mov      ecx, 0x2b110
        mov      edi, dword ptr [esi]
        lea      eax, [eax + eax*2]
        lea      eax, [eax + eax*4]
        shl      eax, 2
        div      ecx
        push     edx
        push     esi
        call     dword ptr [edi + 0x34]
        mov      eax, dword ptr [g_ecmDSBuffer]
        push     1
        push     ebx
        push     ebx
        mov      edx, dword ptr [eax]
        push     eax
        call     dword ptr [edx + 0x30]
    L_0fbf:
        cmp      dword ptr [g_ecmRunFlag], ebx
        je       L_0fdd
        call     dword ptr [g_iat_004d2240]
        mov      edi, eax
        mov      dword ptr [g_ecmRunFlag], ebx
        mov      dword ptr [g_data_007aa224], edi
        jmp      L_0fe3
    L_0fdd:
        mov      edi, dword ptr [g_data_007aa224]
    L_0fe3:
        mov      esi, dword ptr [g_ecmFrameSizeDiv8]
        mov      dword ptr [esp + 0x14], ebx
        mov      dword ptr [esp + 0x10], esi
        fild     qword ptr [esp + 0x10]
        fmul     qword ptr [g_const_004d2998]
        fmul     qword ptr [g_const_004d29a0]
        fsubr    qword ptr [g_const_004d29b0]
        call     DoubleToInt64_004c57d0
        sub      edi, eax
        mov      eax, dword ptr [g_data_007aa228]
        cmp      eax, ebx
        mov      dword ptr [g_data_007ab048], edi
        jne      L_1048
        call     dword ptr [g_iat_004d2240]
        mov      ecx, dword ptr [g_data_007ab048]
        mov      esi, dword ptr [g_ecmFrameSizeDiv8]
        cmp      eax, ecx
        jb       L_1048
        cmp      esi, ebx
        je       L_1048
        mov      eax, dword ptr [g_data_007aa234]
        dec      eax
        cmp      esi, eax
        je       L_1048
        mov      ecx, 1
        jmp      L_104a
    L_1048:
        xor      ecx, ecx
    L_104a:
        inc      esi
        mov      eax, 0x88888889
        mul      esi
        shr      edx, 3
        cmp      ecx, ebx
        mov      dword ptr [g_data_007aa228], ecx
        mov      dword ptr [g_ecmFrameSizeDiv8], esi
        mov      dword ptr [g_ecmFrameTotal], edx
        je       L_106d
        neg      esi
    L_106d:
        mov      eax, esi
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 8
        ret
    L_1077:
        pop      edi
        pop      esi
        pop      ebp
        xor      eax, eax
        pop      ebx
        add      esp, 8
        ret
    }
}
