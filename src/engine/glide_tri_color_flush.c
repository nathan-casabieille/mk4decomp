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

extern unsigned int g_data_004f4b4c;
extern unsigned int g_data_007afa28;
extern unsigned int g_data_007afaa8;
extern unsigned int g_data_007aff50;
extern unsigned int g_data_007affd0;
extern unsigned int g_data_007affe4;
extern unsigned int g_data_007affe8;
extern unsigned int g_data_007afff0;
extern unsigned int g_data_007afff4;
extern unsigned int g_data_007b0004;
extern unsigned int g_data_007b0074;
extern unsigned int g_data_007b0078;

__declspec(naked) void GlideTriColorFlush_004b46f0(void)
{
    __asm {
        mov      eax, dword ptr [g_data_007affe4]
        sub      esp, 0xb4
        test     eax, eax
        je       L_4992
        mov      eax, dword ptr [g_data_007afff4]
        test     eax, eax
        je       L_4992
        mov      eax, dword ptr [g_data_007afff0]
        test     eax, eax
        jne      L_4992
        push     ebx
        mov      bl, byte ptr [esp + 0xbc]
        cmp      bl, 0x10
        jbe      L_4733
        xor      bl, bl
        mov      byte ptr [esp + 0xbc], bl
    L_4733:
        cmp      byte ptr [g_data_004f4b4c], bl
        je       L_4764
        mov      eax, dword ptr [esp + 0xbc]
        push     OFFSET g_data_007affd0
        and      eax, 0xff
        push     3
        mov      ecx, dword ptr [eax*4 + g_data_007afa28]
        push     ecx
        push     0
        call     dword ptr [g_data_007b0074]
        mov      byte ptr [g_data_004f4b4c], bl
    L_4764:
        mov      ebx, dword ptr [esp + 0xc0]
        mov      al, byte ptr [g_data_007affe8]
        cmp      bl, al
        je       L_47ad
        test     bl, bl
        jne      L_4782
        push     0
        push     4
        push     0
        push     4
        jmp      L_47a1
    L_4782:
        cmp      bl, 0xff
        jne      L_4791
        push     0
        push     4
        push     4
        push     4
        jmp      L_47a1
    L_4791:
        test     al, al
        je       L_4799
        cmp      al, 0xff
        jne      L_47a7
    L_4799:
        push     0
        push     0
        push     1
        push     5
    L_47a1:
        call     dword ptr [g_data_007b0004]
    L_47a7:
        mov      byte ptr [g_data_007affe8], bl
    L_47ad:
        mov      eax, dword ptr [esp + 0xc8]
        mov      edx, dword ptr [esp + 0xc4]
        mov      dword ptr [esp + 0x80], eax
        and      ebx, 0xff
        movsx    eax, word ptr [esp + 0xd4]
        fld      dword ptr [ebx*4 + g_data_007afaa8]
        fst      dword ptr [esp + 0x5c]
        fst      dword ptr [esp + 0x20]
        fstp     dword ptr [esp + 0x98]
        mov      ecx, eax
        mov      dword ptr [esp + 0x7c], edx
        sar      ecx, 0xa
        and      ecx, 0x1f
        mov      edx, eax
        sar      edx, 5
        fld      dword ptr [ecx*4 + g_data_007aff50]
        and      edx, 0x1f
        and      eax, 0x1f
        fstp     dword ptr [esp + 0x88]
        fld      dword ptr [edx*4 + g_data_007aff50]
        mov      ecx, dword ptr [esp + 0xd0]
        mov      edx, dword ptr [esp + 0xd8]
        fstp     dword ptr [esp + 0x8c]
        fld      dword ptr [eax*4 + g_data_007aff50]
        mov      eax, dword ptr [esp + 0xcc]
        and      ecx, 0xff
        fstp     dword ptr [esp + 0x90]
        and      eax, 0xff
        mov      dword ptr [esp + 4], edx
        mov      dword ptr [esp + 0x60], 0x3f800000
        mov      dword ptr [esp + 0x24], 0x3f800000
        fld      dword ptr [eax*4 + g_data_007afaa8]
        mov      eax, dword ptr [esp + 0xdc]
        mov      dword ptr [esp + 0x9c], 0x3f800000
        fstp     dword ptr [esp + 0xa0]
        fld      dword ptr [ecx*4 + g_data_007afaa8]
        mov      dword ptr [esp + 8], eax
        movsx    eax, word ptr [esp + 0xe8]
        fstp     dword ptr [esp + 0xa4]
        mov      ecx, eax
        mov      edx, eax
        sar      ecx, 0xa
        and      ecx, 0x1f
        and      eax, 0x1f
        sar      edx, 5
        fld      dword ptr [ecx*4 + g_data_007aff50]
        and      edx, 0x1f
        mov      ecx, dword ptr [esp + 0xe4]
        fstp     dword ptr [esp + 0x10]
        fld      dword ptr [edx*4 + g_data_007aff50]
        mov      edx, dword ptr [esp + 0xec]
        and      ecx, 0xff
        fstp     dword ptr [esp + 0x14]
        fld      dword ptr [eax*4 + g_data_007aff50]
        mov      eax, dword ptr [esp + 0xe0]
        mov      dword ptr [esp + 0x40], edx
        fstp     dword ptr [esp + 0x18]
        and      eax, 0xff
        fld      dword ptr [eax*4 + g_data_007afaa8]
        mov      eax, dword ptr [esp + 0xf0]
        fstp     dword ptr [esp + 0x28]
        fld      dword ptr [ecx*4 + g_data_007afaa8]
        mov      dword ptr [esp + 0x44], eax
        movsx    eax, word ptr [esp + 0xfc]
        fstp     dword ptr [esp + 0x2c]
        mov      ecx, eax
        mov      edx, eax
        sar      ecx, 0xa
        and      ecx, 0x1f
        and      eax, 0x1f
        sar      edx, 5
        fld      dword ptr [ecx*4 + g_data_007aff50]
        and      edx, 0x1f
        fstp     dword ptr [esp + 0x4c]
        fld      dword ptr [edx*4 + g_data_007aff50]
        fstp     dword ptr [esp + 0x50]
        fld      dword ptr [eax*4 + g_data_007aff50]
        mov      eax, dword ptr [esp + 0xf4]
        fstp     dword ptr [esp + 0x54]
        and      eax, 0xff
        fld      dword ptr [eax*4 + g_data_007afaa8]
        mov      ecx, dword ptr [esp + 0xf8]
        lea      edx, [esp + 0x40]
        fstp     dword ptr [esp + 0x64]
        and      ecx, 0xff
        lea      eax, [esp + 4]
        push     edx
        push     eax
        fld      dword ptr [ecx*4 + g_data_007afaa8]
        lea      ecx, [esp + 0x84]
        fstp     dword ptr [esp + 0x70]
        push     ecx
        call     dword ptr [g_data_007b0078]
        pop      ebx
    L_4992:
        add      esp, 0xb4
        ret
    }
}
