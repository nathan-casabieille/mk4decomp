/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel;
extern unsigned int g_chainAccumCur;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown;
extern unsigned int g_xformScratch94;
extern unsigned int g_fightStateProgress;
extern unsigned int g_active_00537e88;
extern unsigned int g_active_0053a408;
extern unsigned int g_audioBankSel;

extern void StoreTwoCall(int, int);
extern void SetJmp_Thunk_LinkedListBitMaskSearch(void);
extern void Thunk_ChainNodeInit(void);
extern void ScaledZeroFour(void);
extern void WalkCbSubMul10(void);
extern void Mul10Tail(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10(void);
extern void SpawnListBatchLoader(void);
extern void MStackPush2TableNot(void);
extern void GuardedChainCmpDualBitXor(void);
extern void ScaledLoadDecJmp(void);
extern void ScaledStoreCurDirtyClear(void);
extern void MStackBitmaskIncMod(void);
extern void MStackBitmaskUpdate(void);
extern void Push1eCallTestDirtyLoop(void);
extern void MStackLoopFieldInit(void);
extern void TaggedSceneDispatch(void);
extern void CallPauseDirty4StackPushFn(void);
extern void CallPauseDirty1JmpDirty4StackPush_GuardedDoubleIncCmpJmp(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void InstallSelfChainSet84_80CallW(void);
extern void Wrapper_PackedAdvanceCallTailJmp_004e46d0(void);
extern void MoveFsmCluster(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain(void);
extern void CopyJmp_SlotCmp3way_g_currentNodeIdx(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_LoadGeoAsset_Default(void);
extern void AllocSlotPushTripleGlobals(void);
extern void MStackPop4Rewrite(void);
extern void Push70CallScaleArith(void);
extern void StreamChainStringInstall(void);
extern void MStackFrameCdeclDouble(void);
extern void ChainTableWalkStore(void);
extern void Push16Call(void);
extern void DispatcherComplex260_MStackBracket1_TreeWalkRecursive2(void);
extern void ScaledLoadCmpStoreXfm(void);
extern void StackPopDispatchTagged(void);
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit;
extern unsigned int g_armedReloadA;
extern unsigned int g_armedReloadB;
extern unsigned int g_dualBitGate;
extern unsigned int g_eventArmReload;
extern unsigned int g_rangeBase;

extern void ScaledArrStore_ScaledChainJmp_004298c0(void);
extern void DualFieldAddSubStore(void);
extern void IterStepDualStore(int);
extern void ScaledXorStore_004900f0(void);
extern void ChainWalkInstall(void);
extern void FpuSqrtMul(void);
extern void PendingMatch_StoreTwoCall_0042b930(void);
extern void MStackPush2RunCountdown(void);
extern void MStackBracket7_DispatchAndChain(void);
extern void MStackBracketed3StoreCall(void);
extern void ChainDirtyBitWalker(void);
extern void Wrapper_ScaledChainPushCall_004ef858(void);
extern void Wrapper_ScaledChainPushCall_004ef8b0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_IterLoad_0048fd30_004f12a0(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_StateDispatchYield_00438f50(void);
extern void SetJmp_StateDispatchYield_00438f60(void);
extern void GuardedDispatch_InstallSelfDualEsi(void);
extern void MStackPushZeroCallPop_PendingMatch(void);
extern void DirtyToggleByGate(void);
extern void GameDispatchValidateState(void);
extern void CrouchAttackFsmCluster(void);
extern void MStackPushVec3Mul10(void);
extern void LiteralPushCallEntZero(void);
extern void LeaPlus22StoreSelf(void);
extern void IterLoad_g_scaledInit_00542048_then_DualScaledStoreZero(void);
extern void GuardedDualConst2AndToggle(void);
extern void CallPauseScaledStorePushCall(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_FramePauseScaledStore(void);
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
 * CharSelect_Team - 292b audio 8-iter table loop (extended from 0x004a76e0's 6-iter).
 *   For edi in 0..7: esi=(edi*9)*4; index=g_byteTab_004f3c20[esi]; chain=baseSel+index;
 *     g_currentNodeIdx=chain[ecx*4]; call MStackPush2ChainLLInsert.
 *   Switch on (edi-3): case 0 → use g_audioMixerKnob2 (3-way: push 0x4f43f4/0x4f43dc/0x4f43cc);
 *                       case 1 → use g_audioMixerKnob (3-way: push 0x4f4434/0x4f441c/0x4f440c).
 *   If case fired: push (0x00543450) and call PrintfStub; restore.
 *   Snapshot esi-table[+0x24] and esi-table[+0xc] (= 0x004f3c2c, 0x004f3c24); call GuardedSetupCallTailJmp;
 *   chain[+0x5c] = esi-table[+0x10]; esi-table[+0x8] = chain[+0x54]; movsx ecx = byte tab[+0];
 *   g_eventQueueCurrent = ecx; chain[ecx*4]=g_currentNodeIdx; chain[ecx*4+0x54] = esi-table[+0x8];
 *   chain[+0x58] = esi-table[+0xc]. inc edi; if < 8: loop.
 */
extern unsigned int g_byteTab_004f3c20;
extern unsigned int g_audioMixerKnob;
extern unsigned int g_audioMixerKnob2;
extern void GuardedSetupCallTailJmp(void);
extern void Helper_Sprintf(void);
extern void MStackPush2ChainLLInsert(void);

__declspec(naked) void CharSelect_Team(void)
{
    __asm
    {
        push    esi
        push    edi
        xor     edi, edi
    L_a7f_iter:
        mov     ecx, dword ptr [g_baseSel]
        lea     esi, [edi*8 + edi]
        shl     esi, 2
        movsx   eax, byte ptr [esi + g_byteTab_004f3c20]
        add     ecx, eax
        mov     edx, dword ptr [ecx*4]
        mov     dword ptr [g_currentNodeIdx], edx
        call    MStackPush2ChainLLInsert
        mov     eax, edi
        sub     eax, 3
        je      short L_a7f_case3
        dec     eax
        jne     short L_a7f_skipCase
        mov     eax, dword ptr [g_audioMixerKnob]
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
        mov     eax, dword ptr [g_audioMixerKnob2]
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
        call    GuardedSetupCallTailJmp
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [esi + 0x004f3c30]
        add     esp, 8
        mov     dword ptr [ecx*4 + 0x5c], eax
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     edx, dword ptr [eax*4 + 0x54]
        mov     dword ptr [esi + 0x004f3c28], edx
        mov     edx, dword ptr [g_baseSel]
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
