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

extern unsigned int g_data_00f9f8c1;
extern unsigned int g_data_00f9f9c8;
extern unsigned int g_data_00f9fac8;
extern unsigned int g_data_00f9facc;
extern unsigned int g_iat_004d2114;
extern void CrtCodepageDispatcher_004cd6f0(void);
extern void WcToMbDispatcher_004cdae0(void);

__declspec(naked) void BuildCharacterCaseTables_004c9840(void)
{
    __asm {
        mov      ecx, dword ptr [g_data_00f9fac8]
        sub      esp, 0x514
        /* MASM emits 3-byte `8d 04 24` for lea eax,[esp]; orig uses
         * 4-byte disp8=0 form `8d 44 24 00`. */
        _emit    0x8d
        _emit    0x44
        _emit    0x24
        _emit    0x00
        push     ebx
        push     eax
        push     ecx
        call     dword ptr [g_iat_004d2114]
        cmp      eax, 1
        jne      L_99b4
        push     edi
        push     esi
        xor      eax, eax
    L_9866:
        mov      byte ptr [esp + eax + 0x20], al
        inc      eax
        cmp      eax, 0x100
        jb       short L_9866
        mov      al, byte ptr [esp + 0x12]
        mov      byte ptr [esp + 0x20], 0x20
        test     al, al
        je       short L_98b4
        lea      edx, [esp + 0x13]
    L_9883:
        xor      ecx, ecx
        and      eax, 0xff
        mov      cl, byte ptr [edx]
        cmp      eax, ecx
        ja       short L_98aa
        sub      ecx, eax
        lea      edi, [esp + eax + 0x20]
        inc      ecx
        mov      eax, 0x20202020
        mov      esi, ecx
        shr      ecx, 2
        rep stosd
        mov      ecx, esi
        and      ecx, 3
        rep stosb
    L_98aa:
        mov      al, byte ptr [edx + 1]
        add      edx, 2
        test     al, al
        jne      short L_9883
    L_98b4:
        mov      edx, dword ptr [g_data_00f9facc]
        mov      eax, dword ptr [g_data_00f9fac8]
        push     0
        push     edx
        lea      ecx, [esp + 0x328]
        push     eax
        push     ecx
        lea      edx, [esp + 0x30]
        push     0x100
        push     edx
        push     1
        call     WcToMbDispatcher_004cdae0
        mov      eax, dword ptr [g_data_00f9fac8]
        add      esp, 0x1c
        lea      ecx, [esp + 0x120]
        lea      edx, [esp + 0x20]
        push     0
        push     eax
        mov      eax, dword ptr [g_data_00f9facc]
        push     0x100
        push     ecx
        push     0x100
        push     edx
        push     0x100
        push     eax
        call     CrtCodepageDispatcher_004cd6f0
        mov      ecx, dword ptr [g_data_00f9fac8]
        add      esp, 0x20
        lea      edx, [esp + 0x220]
        lea      eax, [esp + 0x20]
        push     0
        push     ecx
        mov      ecx, dword ptr [g_data_00f9facc]
        push     0x100
        push     edx
        push     0x100
        push     eax
        push     0x200
        push     ecx
        call     CrtCodepageDispatcher_004cd6f0
        add      esp, 0x20
        xor      eax, eax
        lea      edx, [esp + 0x320]
        mov      bl, 0x10
    L_9950:
        mov      cx, word ptr [edx]
        test     cl, 1
        je       short L_9975
        mov      cl, byte ptr [eax + g_data_00f9f8c1]
        or       cl, bl
        mov      byte ptr [eax + g_data_00f9f8c1], cl
        mov      cl, byte ptr [esp + eax + 0x120]
        mov      byte ptr [eax + g_data_00f9f9c8], cl
        jmp      short L_999f
    L_9975:
        test     cl, 2
        je       short L_9998
        mov      cl, byte ptr [eax + g_data_00f9f8c1]
        or       cl, 0x20
        mov      byte ptr [eax + g_data_00f9f8c1], cl
        mov      cl, byte ptr [esp + eax + 0x220]
        mov      byte ptr [eax + g_data_00f9f9c8], cl
        jmp      short L_999f
    L_9998:
        mov      byte ptr [eax + g_data_00f9f9c8], 0
    L_999f:
        inc      eax
        add      edx, 2
        cmp      eax, 0x100
        jb       short L_9950
        pop      esi
        pop      edi
        pop      ebx
        add      esp, 0x514
        ret
    L_99b4:
        xor      eax, eax
        mov      bl, 0x10
    L_99b8:
        cmp      eax, 0x41
        jb       short L_99dd
        cmp      eax, 0x5a
        ja       short L_99dd
        mov      dl, byte ptr [eax + g_data_00f9f8c1]
        or       dl, bl
        mov      byte ptr [eax + g_data_00f9f8c1], dl
        mov      dl, al
        add      dl, 0x20
        mov      byte ptr [eax + g_data_00f9f9c8], dl
        jmp      short L_9a0a
    L_99dd:
        cmp      eax, 0x61
        jb       short L_9a03
        cmp      eax, 0x7a
        ja       short L_9a03
        mov      cl, byte ptr [eax + g_data_00f9f8c1]
        or       cl, 0x20
        mov      byte ptr [eax + g_data_00f9f8c1], cl
        mov      cl, al
        sub      cl, 0x20
        mov      byte ptr [eax + g_data_00f9f9c8], cl
        jmp      short L_9a0a
    L_9a03:
        mov      byte ptr [eax + g_data_00f9f9c8], 0
    L_9a0a:
        inc      eax
        cmp      eax, 0x100
        jb       short L_99b8
        pop      ebx
        add      esp, 0x514
        ret
    }
}
