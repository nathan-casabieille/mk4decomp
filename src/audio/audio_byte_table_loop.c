/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown;
extern unsigned int g_xformScratch94;
extern unsigned int g_table_00535ddc;
extern unsigned int g_active_00537e88;
extern unsigned int g_active_0053a408;
extern unsigned int g_audioBankSel;

extern void StoreTwoCall(int, int);
extern void SetJmp_0049cb90(void);
extern void Thunk_0049cbd0(void);
extern void ScaledZeroFour(void);
extern void WalkCbSubMul10_00431d50(void);
extern void Mul10Tail(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10(void);
extern void SpawnListBatchLoader_00477710(void);
extern void MStackPush2TableNot(void);
extern void GuardedChainCmpDualBitXor(void);
extern void ScaledLoadDecJmp_00429710(void);
extern void ScaledStoreCurDirtyClear_004296f0(void);
extern void MStackBitmaskIncMod_00492450(void);
extern void MStackBitmaskUpdate_00492510(void);
extern void Push1eCallTestDirtyLoop_004923b0(void);
extern void MStackLoopFieldInit_00492280(void);
extern void TaggedSceneDispatch(void);
extern void CallPauseDirty4StackPushFn_004839d0(void);
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void InstallSelfChainSet84_80CallW_004363f0(void);
extern void Wrapper_00436490(void);
extern void MoveFsmCluster_004364a0(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain_0047a950(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_004bd5c0(void);
extern void AllocSlotPushTripleGlobals(void);
extern void MStackPop4Rewrite(void);
extern void Push70CallScaleArith(void);
extern void StreamChainStringInstall(void);
extern void MStackFrameCdeclDouble(void);
extern void ChainTableWalkStore_004917e0(void);
extern void Push16Call(void);
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm_0048f2a0(void);
extern void StackPopDispatchTagged(void);
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_dualBitGate;
extern unsigned int g_eventArmReload;
extern unsigned int g_rangeBase;

extern void ScaledArrStore_004298c0(void);
extern void DualFieldAddSubStore(void);
extern void IterStepDualStore(int);
extern void ScaledXorStore_004900f0(void);
extern void ChainWalkInstall(void);
extern void FpuSqrtMul(void);
extern void PendingMatch_0042b930(void);
extern void MStackPush2RunCountdown(void);
extern void MStackBracket7_DispatchAndChain(void);
extern void MStackBracketed3StoreCall(void);
extern void ChainDirtyBitWalker(void);
extern void Wrapper_0048a350(void);
extern void Wrapper_0048a3a0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_0048ec20(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_00438f50(void);
extern void SetJmp_00438f60(void);
extern void GuardedDispatch_0042b6c0(void);
extern void MStackPushZeroCallPop_00407d00(void);
extern void DirtyToggleByGate(void);
extern void GameDispatchValidateState(void);
extern void CrouchAttackFsmCluster(void);
extern void MStackPushVec3Mul10(void);
extern void LiteralPushCallEntZero(void);
extern void LeaPlus22StoreSelf(void);
extern void IterLoad_00491050(void);
extern void GuardedDualConst2AndToggle(void);
extern void CallPauseScaledStorePushCall(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_00407400(void);
extern void PushSetCallPop(void);
extern unsigned int g_stateCountdown;
extern unsigned int g_installOwnerNode;
extern unsigned int g_cj_00542054;
extern unsigned int g_audioBoundNode;
extern unsigned int g_lastGatedValue;
extern unsigned int g_lastGatedTick;
extern unsigned int g_fightAxisNegX;
extern unsigned int g_fightAxisNegY;
extern unsigned int g_fightAxisPosX;
extern unsigned int g_fightAxisPosY;

/*
 * CharSelect_TeamSize - 221b audio iteration over a 6-element byte index table.
 *   Loop edi 0..5: esi = (g_baseSel + edi) * 4; index = byteTab[0x004f3b48 + esi];
 *     ecx = baseSel + index; edx = chain[ecx*4]; g_currentNodeIdx = edx; call MStackPush2ChainLLInsert_00406790.
 *     Switch on (edi-3): case 0 → push (data_004f3a30[edx*4], 0x004d2608) into Printf args;
 *     case 1 → push (data_004f3a30[eax*4 from g_audioByteTable_004f3af0], 0x004d2618); other → skip.
 *     If case fired: push (0x004f43c4, 0x00543450); call PrintfStub; restore.
 *     Snapshot tab[+0xc] & tab[+4]; call GuardedSetupCallTailJmp; chain[g_currentNodeIdx*4 + 0x5c] = tab[+0x10];
 *     tab[+8] = chain[+0x54]; ecx = movsx tab[+0]; g_eventQueueCurrent = ecx;
 *     chain[(baseSel + index)*4] = g_currentNodeIdx. inc edi; if <6: loop.
 */
extern unsigned int g_audioStateMachine2_004f3aec;
extern unsigned int g_audioByteTable_004f3af0;
extern void GuardedSetupCallTailJmp_004a1fa0(void);
extern void Helper_Sprintf(void);
extern void MStackPush2ChainLLInsert_00406790(void);

__declspec(naked) void CharSelect_TeamSize(void)
{
    __asm
    {
        push    esi
        push    edi
        xor     edi, edi
    L_iter:
        mov     ecx, dword ptr [g_baseSel]
        lea     esi, [edi*8 + edi]
        shl     esi, 2
        movsx   eax, byte ptr [esi + 0x004f3b48]
        add     ecx, eax
        mov     edx, dword ptr [ecx*4]
        mov     dword ptr [g_currentNodeIdx], edx
        call    MStackPush2ChainLLInsert_00406790
        mov     eax, edi
        sub     eax, 3
        je      short L_case3
        dec     eax
        jne     short L_skipCase
        mov     eax, dword ptr [g_audioByteTable_004f3af0]
        mov     ecx, dword ptr [eax*4 + 0x004f3a30]
        push    ecx
        push    0x004d2618
        jmp     short L_printf
    L_case3:
        mov     edx, dword ptr [g_audioStateMachine2_004f3aec]
        mov     eax, dword ptr [edx*4 + 0x004f3a30]
        push    eax
        push    0x004d2608
    L_printf:
        push    0x004f43c4
        push    0x00543450
        call    Helper_Sprintf
        add     esp, 0x10
    L_skipCase:
        mov     eax, dword ptr [esi + 0x004f3b54]
        mov     ecx, dword ptr [esi + 0x004f3b4c]
        push    eax
        push    ecx
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_currentNodeIdx], ecx
        call    GuardedSetupCallTailJmp_004a1fa0
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [esi + 0x004f3b58]
        add     esp, 8
        mov     dword ptr [edx*4 + 0x5c], ecx
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     edx, dword ptr [g_baseSel]
        mov     ecx, dword ptr [eax*4 + 0x54]
        mov     dword ptr [esi + 0x004f3b50], ecx
        movsx   ecx, byte ptr [esi + 0x004f3b48]
        mov     dword ptr [g_eventQueueCurrent], ecx
        add     ecx, edx
        inc     edi
        cmp     edi, 6
        mov     dword ptr [ecx*4], eax
        jb      L_iter
        pop     edi
        pop     esi
        ret
    }
}
