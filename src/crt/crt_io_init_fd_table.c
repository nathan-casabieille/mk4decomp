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
extern unsigned int g_data_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_data_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

extern unsigned int g_data_00fa0de0;
extern unsigned int g_data_00fa0de4;
extern unsigned int g_data_00fa0ee0;
extern unsigned int g_iat_004d2120;
extern unsigned int g_iat_004d2128;
extern unsigned int g_iat_004d2138;
extern unsigned int g_iat_004d2148;
extern void CmpCallPushIATCall_004c6e60(void);
extern void LoadArgPushCall_004c54b0(void);

__declspec(naked) void CrtIoInitFdTable_004c8bc0(void)
{
    __asm {
        sub      esp, 0x48
        push     ebx
        push     ebp
        push     esi
        push     edi
        push     0x480
        call     LoadArgPushCall_004c54b0
        mov      esi, eax
        xor      edi, edi
        add      esp, 4
        cmp      esi, edi
        jne      short L_8be6
        push     0x1b
        call     CmpCallPushIATCall_004c6e60
        add      esp, 4
    L_8be6:
        lea      eax, [esi + 0x480]
        mov      dword ptr [g_data_00fa0de0], esi
        cmp      esi, eax
        mov      dword ptr [g_data_00fa0ee0], 0x20
        mov      bl, 0xa
        jae      short L_8c25
    L_8c02:
        mov      byte ptr [esi + 4], 0
        mov      dword ptr [esi], 0xffffffff
        mov      byte ptr [esi + 5], bl
        mov      dword ptr [esi + 8], edi
        mov      ecx, dword ptr [g_data_00fa0de0]
        add      esi, 0x24
        add      ecx, 0x480
        cmp      esi, ecx
        jb       short L_8c02
    L_8c25:
        lea      edx, [esp + 0x14]
        push     edx
        call     dword ptr [g_iat_004d2138]
        cmp      word ptr [esp + 0x46], di
        je       L_8d38
        mov      eax, dword ptr [esp + 0x48]
        cmp      eax, edi
        je       L_8d38
        mov      ecx, dword ptr [eax]
        lea      edi, [eax + 4]
        cmp      ecx, 0x800
        mov      dword ptr [esp + 0x10], ecx
        lea      ebp, [edi + ecx]
        jl       short L_8c63
        mov      dword ptr [esp + 0x10], 0x800
    L_8c63:
        mov      eax, dword ptr [esp + 0x10]
        mov      ecx, dword ptr [g_data_00fa0ee0]
        cmp      ecx, eax
        jge      short L_8ce1
        mov      esi, OFFSET g_data_00fa0de4
    L_8c76:
        push     0x480
        call     LoadArgPushCall_004c54b0
        xor      ecx, ecx
        add      esp, 4
        cmp      eax, ecx
        je       short L_8cd5
        mov      edx, dword ptr [g_data_00fa0ee0]
        mov      dword ptr [esi], eax
        add      edx, 0x20
        mov      dword ptr [g_data_00fa0ee0], edx
        lea      edx, [eax + 0x480]
        cmp      eax, edx
        jae      short L_8cc3
    L_8ca4:
        mov      byte ptr [eax + 4], 0
        mov      dword ptr [eax], 0xffffffff
        mov      byte ptr [eax + 5], bl
        mov      dword ptr [eax + 8], ecx
        mov      edx, dword ptr [esi]
        add      eax, 0x24
        add      edx, 0x480
        cmp      eax, edx
        jb       short L_8ca4
    L_8cc3:
        mov      eax, dword ptr [g_data_00fa0ee0]
        mov      edx, dword ptr [esp + 0x10]
        add      esi, 4
        cmp      eax, edx
        jl       short L_8c76
        jmp      short L_8ce3
    L_8cd5:
        mov      edx, dword ptr [g_data_00fa0ee0]
        mov      dword ptr [esp + 0x10], edx
        jmp      short L_8ce3
    L_8ce1:
        xor      ecx, ecx
    L_8ce3:
        mov      eax, dword ptr [esp + 0x10]
        xor      esi, esi
        cmp      eax, ecx
        jle      short L_8d38
    L_8ced:
        mov      ecx, dword ptr [ebp]
        cmp      ecx, -1
        je       short L_8d2b
        mov      al, byte ptr [edi]
        test     al, 1
        je       short L_8d2b
        test     al, 8
        jne      short L_8d0a
        push     ecx
        call     dword ptr [g_iat_004d2120]
        test     eax, eax
        je       short L_8d2b
    L_8d0a:
        mov      ecx, esi
        mov      eax, esi
        sar      ecx, 5
        and      eax, 0x1f
        lea      edx, [eax + eax*8]
        mov      eax, dword ptr [ecx*4 + g_data_00fa0de0]
        mov      ecx, dword ptr [ebp]
        lea      eax, [eax + edx*4]
        mov      dword ptr [eax], ecx
        mov      dl, byte ptr [edi]
        mov      byte ptr [eax + 4], dl
    L_8d2b:
        mov      eax, dword ptr [esp + 0x10]
        inc      esi
        inc      edi
        add      ebp, 4
        cmp      esi, eax
        jl       short L_8ced
    L_8d38:
        mov      ebx, dword ptr [g_iat_004d2148]
        xor      ebp, ebp
    L_8d40:
        mov      ecx, dword ptr [g_data_00fa0de0]
        lea      eax, [ebp + ebp*8]
        lea      esi, [ecx + eax*4]
        mov      eax, dword ptr [ecx + eax*4]
        cmp      eax, -1
        jne      short L_8da9
        test     ebp, ebp
        mov      byte ptr [esi + 4], 0x81
        jne      short L_8d64
        mov      eax, 0xfffffff6
        jmp      short L_8d6e
    L_8d64:
        mov      eax, ebp
        dec      eax
        neg      eax
        sbb      eax, eax
        add      eax, -0xb
    L_8d6e:
        push     eax
        call     ebx
        mov      edi, eax
        cmp      edi, -1
        je       short L_8da2
        push     edi
        call     dword ptr [g_iat_004d2120]
        test     eax, eax
        je       short L_8da2
        and      eax, 0xff
        mov      dword ptr [esi], edi
        cmp      eax, 2
        jne      short L_8d96
        mov      al, byte ptr [esi + 4]
        or       al, 0x40
        jmp      short L_8dae
    L_8d96:
        cmp      eax, 3
        jne      short L_8db1
        mov      al, byte ptr [esi + 4]
        or       al, 8
        jmp      short L_8dae
    L_8da2:
        mov      al, byte ptr [esi + 4]
        or       al, 0x40
        jmp      short L_8dae
    L_8da9:
        mov      al, byte ptr [esi + 4]
        or       al, 0x80
    L_8dae:
        mov      byte ptr [esi + 4], al
    L_8db1:
        inc      ebp
        cmp      ebp, 3
        jl       L_8d40
        mov      edx, dword ptr [g_data_00fa0ee0]
        push     edx
        call     dword ptr [g_iat_004d2128]
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x48
        ret
    }
}
