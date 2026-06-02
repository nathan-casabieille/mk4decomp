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
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
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
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm(void);
extern void StackPopDispatchTagged(void);
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_dualBitGate;
extern unsigned int g_eventArmReload;
extern unsigned int g_rangeBase;

extern void ScaledArrStore_ScaledChainJmp_004298c0(void);
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
extern void Wrapper_ScaledChainPushCall_004ef858(void);
extern void Wrapper_ScaledChainPushCall_004ef8b0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_IterLoad_0048fd30_004f12a0(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_StateDispatchYield_00438f50(void);
extern void SetJmp_StateDispatchYield_00438f60(void);
extern void GuardedDispatch_InstallSelfDualEsi(void);
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
 * Input_RebindKeyToAction - 176b menu helper: scans a 13-slot table
 *   pair starting at 0x00543ac0 (outer step 4, scans offsets -8..+0x58 step 8)
 *   and replaces any slot equal to arg2 with the saved [arg1] value, clearing
 *   the replacement value after use. Stores final value to [arg1] before
 *   returning. Early-out when arg2 == 0.
 */
__declspec(naked) void Input_RebindKeyToAction(void)
{
    __asm
    {
        mov     edx, dword ptr [esp + 8]
        push    esi
        mov     esi, dword ptr [esp + 8]
        test    edx, edx
        mov     ecx, dword ptr [esi]
        mov     dword ptr [esi], 0
        je      L_done
        mov     eax, 0x00543ac0
    L_loop:
        cmp     dword ptr [eax - 8], edx
        jne     short L_s0
        mov     dword ptr [eax - 8], ecx
        xor     ecx, ecx
    L_s0:
        cmp     dword ptr [eax], edx
        jne     short L_s1
        mov     dword ptr [eax], ecx
        xor     ecx, ecx
    L_s1:
        cmp     dword ptr [eax + 8], edx
        jne     short L_s2
        mov     dword ptr [eax + 8], ecx
        xor     ecx, ecx
    L_s2:
        cmp     dword ptr [eax + 0x10], edx
        jne     short L_s3
        mov     dword ptr [eax + 0x10], ecx
        xor     ecx, ecx
    L_s3:
        cmp     dword ptr [eax + 0x18], edx
        jne     short L_s4
        mov     dword ptr [eax + 0x18], ecx
        xor     ecx, ecx
    L_s4:
        cmp     dword ptr [eax + 0x20], edx
        jne     short L_s5
        mov     dword ptr [eax + 0x20], ecx
        xor     ecx, ecx
    L_s5:
        cmp     dword ptr [eax + 0x28], edx
        jne     short L_s6
        mov     dword ptr [eax + 0x28], ecx
        xor     ecx, ecx
    L_s6:
        cmp     dword ptr [eax + 0x30], edx
        jne     short L_s7
        mov     dword ptr [eax + 0x30], ecx
        xor     ecx, ecx
    L_s7:
        cmp     dword ptr [eax + 0x38], edx
        jne     short L_s8
        mov     dword ptr [eax + 0x38], ecx
        xor     ecx, ecx
    L_s8:
        cmp     dword ptr [eax + 0x40], edx
        jne     short L_s9
        mov     dword ptr [eax + 0x40], ecx
        xor     ecx, ecx
    L_s9:
        cmp     dword ptr [eax + 0x48], edx
        jne     short L_sa
        mov     dword ptr [eax + 0x48], ecx
        xor     ecx, ecx
    L_sa:
        cmp     dword ptr [eax + 0x50], edx
        jne     short L_sb
        mov     dword ptr [eax + 0x50], ecx
        xor     ecx, ecx
    L_sb:
        cmp     dword ptr [eax + 0x58], edx
        jne     short L_sc
        mov     dword ptr [eax + 0x58], ecx
        xor     ecx, ecx
    L_sc:
        add     eax, 4
        cmp     eax, 0x00543ac8
        jl      L_loop
        mov     dword ptr [esi], edx
    L_done:
        pop     esi
        ret
    }
}
