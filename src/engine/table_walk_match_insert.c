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
extern void DispatcherComplex260_MStackBracket1_TreeWalkRecursive2(void);
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

/* @addr 0x00459030 (296b game) - table-walk match scan with triple-cmp + insert.
 *   eax = 0x004e8860>>2; edx = 0x005380b0>>2; g_scaledInit=eax, g_xformEntityIdx=edx.
 *   Loop: ecx = [eax*4]; if zero ret. cmp with [edx*4]; if neq jump_advance.
 *     cmp with [edx*4+4]; if neq jump_advance. cmp with [edx*4+8]; if eq jump_insert.
 *     advance: eax+=3, reload, loop while ecx!=0.
 *   Insert: g_walkCallback=3; call StorePauseImulShr16; if pause ret.
 *     eax = g_walkCallback*3 + (0x004e8948>>2); scaledInit=eax; copy 3 entries to [g_xformEntityIdx*4 +0/4/8]; pop esi; ret.
 */
extern unsigned int g_dispatchSave956;
extern unsigned int g_dispatchSave957;
extern unsigned int g_stateChangeBase;
extern void StorePauseImulShr16(void);

__declspec(naked) void TableWalkMatchInsert(void) {
    __asm {
        mov     eax, offset g_dispatchSave956
        mov     edx, offset g_stateChangeBase
        shr     eax, 2
        shr     edx, 2
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [g_xformEntityIdx], edx
        mov     ecx, dword ptr [eax*4 + 0]
        push    esi
        test    ecx, ecx
        mov     dword ptr [g_walkCallback], ecx
        _emit   0fh
        _emit   84h
        _emit   0f5h
        _emit   00h
        _emit   00h
        _emit   00h
    loop_top:
        cmp     ecx, dword ptr [edx*4 + 0]
        _emit   75h
        _emit   30h
        mov     ecx, dword ptr [eax*4 + 4]
        mov     dword ptr [g_walkCallback], ecx
        mov     esi, dword ptr [edx*4 + 4]
        cmp     ecx, esi
        _emit   75h
        _emit   18h
        mov     ecx, dword ptr [eax*4 + 8]
        mov     dword ptr [g_walkCallback], ecx
        mov     esi, dword ptr [edx*4 + 8]
        cmp     ecx, esi
        _emit   74h
        _emit   1bh
        add     eax, 3
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     ecx, dword ptr [eax*4 + 0]
        test    ecx, ecx
        mov     dword ptr [g_walkCallback], ecx
        _emit   75h
        _emit   0aeh
        pop     esi
        ret
        mov     dword ptr [g_walkCallback], 3
        call    StorePauseImulShr16
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   85h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     eax, dword ptr [g_walkCallback]
        lea     ecx, [eax + eax*2]
        mov     eax, offset g_dispatchSave957
        shr     eax, 2
        add     eax, ecx
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     ecx, dword ptr [eax*4 + 0]
        inc     eax
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax*4 + 0], ecx
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     ecx, dword ptr [eax*4 + 0]
        inc     eax
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [edx*4 + 4], ecx
        mov     eax, dword ptr [g_scaledInit_00542044]
        mov     ecx, dword ptr [eax*4 + 0]
        inc     eax
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax*4 + 8], ecx
        pop     esi
        ret
    }
}
