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

/*
 * AudioByteTable8Loop_004a7f50 - 292b audio 8-iter table loop (extended from 0x004a76e0's 6-iter).
 *   For edi in 0..7: esi=(edi*9)*4; index=g_byteTab_004f3c20[esi]; chain=baseSel+index;
 *     g_currentNodeIdx=chain[ecx*4]; call MStackPush2ChainLLInsert_00406790.
 *   Switch on (edi-3): case 0 → use g_audioMixerKnob2_00543440 (3-way: push 0x4f43f4/0x4f43dc/0x4f43cc);
 *                       case 1 → use g_audioMixerKnob_005433c4 (3-way: push 0x4f4434/0x4f441c/0x4f440c).
 *   If case fired: push (0x00543450) and call PrintfStub; restore.
 *   Snapshot esi-table[+0x24] and esi-table[+0xc] (= 0x004f3c2c, 0x004f3c24); call GuardedSetupCallTailJmp;
 *   chain[+0x5c] = esi-table[+0x10]; esi-table[+0x8] = chain[+0x54]; movsx ecx = byte tab[+0];
 *   g_eventQueueCurrent = ecx; chain[ecx*4]=g_currentNodeIdx; chain[ecx*4+0x54] = esi-table[+0x8];
 *   chain[+0x58] = esi-table[+0xc]. inc edi; if < 8: loop.
 */
extern unsigned int g_byteTab_004f3c20;
extern unsigned int g_audioMixerKnob_005433c4;
extern unsigned int g_audioMixerKnob2_00543440;
extern void GuardedSetupCallTailJmp_004a1fa0(void);
extern void Helper_Sprintf(void);
extern void MStackPush2ChainLLInsert_00406790(void);

__declspec(naked) void AudioByteTable8Loop_004a7f50(void)
{
    __asm
    {
        push    esi
        push    edi
        xor     edi, edi
    L_a7f_iter:
        mov     ecx, dword ptr [g_baseSel_00542060]
        lea     esi, [edi*8 + edi]
        shl     esi, 2
        movsx   eax, byte ptr [esi + g_byteTab_004f3c20]
        add     ecx, eax
        mov     edx, dword ptr [ecx*4]
        mov     dword ptr [g_currentNodeIdx], edx
        call    MStackPush2ChainLLInsert_00406790
        mov     eax, edi
        sub     eax, 3
        je      short L_a7f_case3
        dec     eax
        jne     short L_a7f_skipCase
        mov     eax, dword ptr [g_audioMixerKnob_005433c4]
        test    eax, eax
        jne     short L_a7f_c4_1
        push    0x004f4434
        jmp     short L_a7f_printf
    L_a7f_c4_1:
        cmp     eax, 1
        jne     short L_a7f_c4_2
        push    0x004f441c
        jmp     short L_a7f_printf
    L_a7f_c4_2:
        cmp     eax, 2
        jne     short L_a7f_skipCase
        push    0x004f440c
        jmp     short L_a7f_printf
    L_a7f_case3:
        mov     eax, dword ptr [g_audioMixerKnob2_00543440]
        test    eax, eax
        jne     short L_a7f_c3_1
        push    0x004f43f4
        jmp     short L_a7f_printf
    L_a7f_c3_1:
        cmp     eax, 1
        jne     short L_a7f_c3_2
        push    0x004f43dc
        jmp     short L_a7f_printf
    L_a7f_c3_2:
        cmp     eax, 2
        jne     short L_a7f_skipCase
        push    0x004f43cc
    L_a7f_printf:
        push    0x00543450
        call    Helper_Sprintf
        add     esp, 8
    L_a7f_skipCase:
        mov     eax, dword ptr [esi + 0x004f3c2c]
        mov     ecx, dword ptr [esi + 0x004f3c24]
        push    eax
        push    ecx
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_currentNodeIdx], ecx
        call    GuardedSetupCallTailJmp_004a1fa0
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [esi + 0x004f3c30]
        add     esp, 8
        mov     dword ptr [ecx*4 + 0x5c], eax
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     edx, dword ptr [eax*4 + 0x54]
        mov     dword ptr [esi + 0x004f3c28], edx
        mov     edx, dword ptr [g_baseSel_00542060]
        movsx   ecx, byte ptr [esi + g_byteTab_004f3c20]
        mov     dword ptr [g_eventQueueCurrent], ecx
        add     ecx, edx
        inc     edi
        mov     dword ptr [ecx*4], eax
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [esi + 0x004f3c28]
        cmp     edi, 8
        mov     dword ptr [ecx*4 + 0x54], eax
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     edx, dword ptr [esi + 0x004f3c2c]
        mov     dword ptr [eax*4 + 0x58], edx
        jb      L_a7f_iter
        pop     edi
        pop     esi
        ret
    }
}
