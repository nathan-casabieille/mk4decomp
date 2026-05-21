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
extern unsigned int g_data_00542050;
extern unsigned int g_data_00542070;
extern unsigned int g_data_00542084;
extern unsigned int g_state_0054208c;
extern unsigned int g_state_00542088;
extern unsigned int g_state_00542094;
extern unsigned int g_state_00535ddc;
extern unsigned int g_state_00537e88;
extern unsigned int g_state_0053a408;
extern unsigned int g_state_00537f94;
extern unsigned int g_state_00542080;
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
extern unsigned int g_state_0054207c;
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

/* ------------------------------------------------------------------ */
/* Boss-room init cluster (640b game, 3 packed helpers)                */
/* Cross-references jump table inside sibling stub BossRoomBootstrap_004105c0.      */
/* ------------------------------------------------------------------ */
extern void ScaledChainOr8_00404e50(void);
extern void Copy3Fields3c4044_00404e90(void);
extern void PushSetXfmMaskCallPop_00407140(void);
extern void MStackPush2RunCountdown_004089e0(void);
extern void BossRoomBootstrap_004105c0(void);
extern void func_0041062b(void);
extern void func_00410725(void);
extern void func_0041076b(void);
extern void func_004107b4(void);
extern void MStackBracket7_DispatchAndChain_004b8fa0(void);
extern unsigned int g_data_004d57c8;
extern unsigned int g_data_004d5814;
extern unsigned int g_data_004d6990;
extern unsigned int g_data_004107b8;

__declspec(naked) void BossRoomInitCluster_00410340(void)
{
    __asm {
        /* === Helper 1 (0x410340): pack-hi16 into 004d5814[0] === */
    L_0340:
        mov      edx, dword ptr [g_data_0054206c]
        mov      eax, OFFSET g_data_004d5814
        shr      eax, 2
        mov      dword ptr [g_data_00542044], eax
        mov      ecx, dword ptr [eax*4]
        shl      edx, 0x10
        and      ecx, 0xffff
        mov      dword ptr [g_data_0054206c], edx
        or       ecx, edx
        mov      dword ptr [g_data_00542070], ecx
        mov      dword ptr [eax*4], ecx
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* === Helper 2 (0x410370): event-0 push trampoline === */
        push     0
        push     OFFSET L_0390
        call     StoreTwoCall_0049cb40
        add      esp, 8
        ret
        /* === Helper 3 (0x410390): main 5-case dispatcher === */
    L_0390:
        mov      eax, dword ptr [g_data_00542060]
        push     ebx
        push     esi
        push     edi
        lea      esi, [eax*4]
        mov      ebx, 4
        xor      edi, edi
        mov      eax, dword ptr [esi + 0x84]
        mov      dword ptr [esi + 0x84], edi
        cmp      eax, ebx
        ja       func_0041076b
        jmp      dword ptr [eax*4 + g_data_004107b8]
        mov      eax, dword ptr [g_data_00542054]
        dec      eax
        mov      dword ptr [g_data_00542054], eax
        jns      func_00410725
        call     MStackPush2RunCountdown_004089e0
        cmp      dword ptr [g_data_00541e6c], edi
        jne      func_004107b4
        call     MStackBracket7_DispatchAndChain_004b8fa0
        cmp      dword ptr [g_data_00541e6c], edi
        jne      func_004107b4
        mov      dword ptr [g_data_0054206c], 0xa
        call     ChainDirtyBitWalker_00408c10
        cmp      dword ptr [g_data_00541e6c], edi
        jne      func_004107b4
        test     byte ptr [g_data_0054208c], bl
        jne      L_04e1
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [g_data_00542048]
        mov      edx, dword ptr [g_data_0054205c]
        inc      eax
        mov      dword ptr [g_data_0054204c], ecx
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [eax*4], edx
        mov      eax, OFFSET g_data_004d6990
        shr      eax, 2
        mov      dword ptr [g_data_0054206c], eax
        call     PushSetXfmMaskCallPop_00407140
        cmp      dword ptr [g_data_00541e6c], edi
        jne      func_004107b4
        test     byte ptr [g_data_0054208c], bl
        jne      short L_04ae
        mov      ecx, dword ptr [g_data_0054205c]
        mov      eax, 0x9a
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 0x30], eax
        call     Copy3Fields3c4044_00404e90
        call     ScaledChainOr8_00404e50
        mov      edx, dword ptr [g_data_00542048]
        mov      eax, 0x14ccc
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [edx*4 + 0x48], eax
        call     MStackCall_004062f0
        cmp      dword ptr [g_data_00541e6c], edi
        jne      func_004107b4
    L_04ae:
        mov      eax, dword ptr [g_data_004d57ac]
        mov      ecx, dword ptr [eax*4]
        dec      eax
        mov      dword ptr [g_data_0054205c], ecx
        mov      dword ptr [g_data_004d57ac], eax
        mov      dword ptr [g_data_0054206c], 0x19
        call     TableLookupCall_00489ff0
        cmp      dword ptr [g_data_00541e6c], edi
        jne      func_004107b4
    L_04e1:
        mov      edx, dword ptr [g_data_0054205c]
        mov      ecx, 0xfd70
        mov      eax, dword ptr [edx*4 + 0x3c]
        mov      dword ptr [g_data_0054206c], ecx
        mov      dword ptr [g_data_00542054], eax
        mov      dword ptr [eax*4 + 0x3c], ecx
        mov      eax, dword ptr [g_data_00542054]
        mov      eax, dword ptr [eax*4 + 0x20]
        mov      dword ptr [eax*4 + 0x38], 0xffff0000
        mov      dword ptr [g_data_0054207c], 3
        jmp      BossRoomBootstrap_004105c0
        mov      eax, OFFSET g_data_004d57c8
        mov      dword ptr [g_data_0054206c], 0x707070
        shr      eax, 2
        mov      dword ptr [g_data_00542044], eax
        mov      dword ptr [eax*4], 0x707070
        mov      ecx, dword ptr [g_data_00542058]
        mov      edx, dword ptr [ecx*4]
        mov      dword ptr [g_data_0054206c], edx
        call     L_0340
        cmp      dword ptr [g_data_00541e6c], edi
        jne      func_004107b4
        mov      ecx, dword ptr [g_data_00542054]
        mov      eax, 0x10000
        mov      dword ptr [g_data_0054206c], eax
        mov      dword ptr [ecx*4 + 0x3c], eax
        mov      dword ptr [esi + 8], OFFSET L_0390
        mov      dword ptr [esi + 0x84], 3
        mov      dword ptr [g_data_0054204c], 2
        mov      dword ptr [g_data_00541e6c], 1
        pop      edi
        pop      esi
        pop      ebx
        ret
        mov      eax, dword ptr [g_data_0054207c]
        dec      eax
        cmp      eax, edi
        mov      dword ptr [g_data_0054207c], eax
        /* force short jle to in-sibling-stub target (orig: 7e 6b) */
        _emit    0x7e
        _emit    0x6b
    }
}
