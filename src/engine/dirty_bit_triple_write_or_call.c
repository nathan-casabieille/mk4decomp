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
extern void CopyJmp_0048ef90(void);
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
extern void Wrapper_ScaledChainPushCall_004ef858(void);
extern void Wrapper_ScaledChainPushCall_004ef8b0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_IterLoad_0048fd30_004f12a0(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_StateDispatchYield_00438f50(void);
extern void SetJmp_StateDispatchYield_00438f60(void);
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

/* @addr 0x004ba630 (140b engine.render) - dirty-bit gated triple-write or
 *   func call: if (g_xformDirtyFlags & 0x30): write ecx to 3 stack slots and
 *   call func_4b3a90(arr_main[g_pendingNodeType], esp). Else: write ecx to
 *   arr_main[g_pendingNodeType]+0,+8,+10 and zero +4,+0xc. Always set state |= 0x30.
 */
extern void Transform9Words(void);

extern unsigned int g_arr_ba630_disp_48;
extern unsigned int g_arr_ba630_main;

void DirtyBitTripleWriteOrCall(void) {
    __asm {
        mov     eax, dword ptr [g_xformEntityIdx]
        sub     esp, 0x0c
        mov     ecx, [eax*4 + g_arr_ba630_disp_48]
        mov     al, byte ptr [g_xformDirtyFlags]
        sar     ecx, 4
        test    al, 0x30
        _emit   75h
        _emit   3ah
        mov     edx, dword ptr [g_pendingNodeType]
        mov     [edx*4 + g_arr_ba630_main], ecx
        mov     [edx*4 + g_arr_ba630_main + 0x8], ecx
        mov     [edx*4 + g_arr_ba630_main + 0x10], ecx
        lea     eax, [edx*4 + g_arr_ba630_main]
        xor     edx, edx
        mov     dword ptr [eax + 4], edx
        mov     dword ptr [eax + 0x0c], edx
        mov     eax, dword ptr [g_xformDirtyFlags]
        or      al, 0x30
        mov     dword ptr [g_xformDirtyFlags], eax
        add     esp, 0x0c
        ret
        mov     dword ptr [esp + 8], ecx
        mov     dword ptr [esp + 4], ecx
        _emit   89h
        _emit   4ch
        _emit   24h
        _emit   00h
        mov     ecx, dword ptr [g_pendingNodeType]
        _emit   8dh
        _emit   44h
        _emit   24h
        _emit   00h
        lea     edx, [ecx*4 + g_arr_ba630_main]
        push    eax
        push    edx
        call    Transform9Words
        mov     eax, dword ptr [g_xformDirtyFlags]
        add     esp, 8
        or      al, 0x30
        mov     dword ptr [g_xformDirtyFlags], eax
        add     esp, 0x0c
        }
}

