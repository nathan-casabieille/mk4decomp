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

/* @addr 0x004b4450 (146b engine.geo) - decode 16-bit lookup table:
 *   _alloca(0x20000); if !g_renderer1_active: ret 0;
 *   if arg1 >= 0x10 or arg2 == NULL: ret 0;
 *   Reads 0x10000 words from arg2, rotates each (al<<1 | (al & 0x3f-bits)),
 *   stores into local stack buffer. Then calls IAT[007b0060](0, fn, 3, str_7affd0).
 */
extern u32 g_glideD0;
extern unsigned int g_iat_indirect_007b0060;
extern u32 g_glideE0;
extern int g_renderer1_active;
extern void Helper_ChkStk(void);

extern unsigned int g_arr_007afa28;

__declspec(naked) int DecodeTableAllocaCall(void) {
    __asm {
        mov     eax, 0x20000
        call    Helper_ChkStk
        mov     eax, dword ptr [g_renderer1_active]
        push    ebx
        push    esi
        push    edi
        test    eax, eax
        _emit   74h
        _emit   70h
        mov     edx, dword ptr [esp + 0x20010]
        cmp     dl, 0x10
        _emit   73h
        _emit   64h
        mov     ecx, dword ptr [esp + 0x20014]
        test    ecx, ecx
        _emit   74h
        _emit   59h
        lea     esi, [esp + 0x0c]
        mov     edi, 0x10000
        sub     esi, ecx
loop4b4450:
        mov     ax, word ptr [ecx]
        add     ecx, 2
        mov     bl, al
        and     al, 0xe0
        and     ebx, 0x3f
        shl     eax, 1
        or      ebx, eax
        dec     edi
        mov     word ptr [esi + ecx - 2], bx
        _emit   75h
        _emit   0e7h
        and     edx, 0xff
        push    offset g_glideD0
        push    3
        lea     eax, [esp + 0x14]
        mov     ecx, [edx*4 + g_arr_007afa28]
        mov     dword ptr [g_glideE0], eax
        push    ecx
        push    0
        call    dword ptr [g_iat_indirect_007b0060]
        mov     eax, 1
        pop     edi
        pop     esi
        pop     ebx
        add     esp, 0x20000
        ret
        pop     edi
        pop     esi
        xor     eax, eax
        pop     ebx
        add     esp, 0x20000
        ret
    }
}
