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
 * CharSelect_HelpPrompts - 278b audio: zero an 11-slot table at 0x00543408, then iterate
 *   11 times calling GuardedSetupCallTailJmp(ptr_i, val_i). After each call, chain[+0x54]=0x190000;
 *   chain[+0x5c]=0x18000; store g_currentNodeIdx to (g_table_00543404)[i].
 *   Stack-frame: sub esp, 0x58. Holds 11 const ptrs (0x004d24bc..0x004d2578) and 11 const vals
 *   (0xff9c0000..0x00930000 step 0x190000-ish).
 */
extern unsigned int g_table_00543404;
extern unsigned int g_table_00543408;
extern void GuardedSetupCallTailJmp(void);

__declspec(naked) void CharSelect_HelpPrompts(void)
{
    __asm
    {
        sub     esp, 0x58
        push    ebx
        push    esi
        push    edi
        mov     ecx, 0xb
        xor     eax, eax
        mov     edi, offset g_table_00543408
        rep     stosd
        mov     dword ptr [esp + 0x38], 0x004d24bc
        mov     dword ptr [esp + 0x3c], 0x004d24c0
        mov     dword ptr [esp + 0x40], 0x004d24d0
        mov     dword ptr [esp + 0x44], 0x004d24e8
        mov     dword ptr [esp + 0x48], 0x004d24f8
        mov     dword ptr [esp + 0x4c], 0x004d2510
        mov     dword ptr [esp + 0x50], 0x004d2528
        mov     dword ptr [esp + 0x54], 0x004d2538
        mov     dword ptr [esp + 0x58], 0x004d2548
        mov     dword ptr [esp + 0x5c], 0x004d2560
        mov     dword ptr [esp + 0x60], 0x004d2578
        mov     dword ptr [esp + 0x0c], 0xff9c0000
        mov     dword ptr [esp + 0x10], 0xffb20000
        mov     dword ptr [esp + 0x14], 0xffcb0000
        mov     dword ptr [esp + 0x18], 0xffe40000
        mov     dword ptr [esp + 0x1c], 0xfffd0000
        mov     dword ptr [esp + 0x20], 0x00160000
        mov     dword ptr [esp + 0x24], 0x002f0000
        mov     dword ptr [esp + 0x28], 0x00480000
        mov     dword ptr [esp + 0x2c], 0x00610000
        mov     dword ptr [esp + 0x30], 0x007a0000
        mov     dword ptr [esp + 0x34], 0x00930000
        xor     esi, esi
        mov     ebx, 0x190000
        mov     edi, 0x18000
    L_a5_iter:
        mov     eax, dword ptr [esp + esi + 0x0c]
        mov     ecx, dword ptr [esp + esi + 0x38]
        push    eax
        push    ecx
        call    GuardedSetupCallTailJmp
        mov     edx, dword ptr [g_currentNodeIdx]
        add     esi, 4
        add     esp, 8
        cmp     esi, 0x2c
        mov     dword ptr [edx*4 + 0x54], ebx
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     dword ptr [eax*4 + 0x5c], edi
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [esi + g_table_00543404], ecx
        jb      short L_a5_iter
        pop     edi
        pop     esi
        pop     ebx
        add     esp, 0x58
        ret
    }
}
