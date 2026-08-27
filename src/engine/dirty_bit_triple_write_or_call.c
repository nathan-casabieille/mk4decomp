/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
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
#endif

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
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit;
extern unsigned int g_armedReloadA;
extern unsigned int g_armedReloadB;
extern unsigned int g_dualBitGate;
extern unsigned int g_eventArmReload;
extern unsigned int g_rangeBase;
#endif

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
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
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
#endif

/* @addr 0x004ba630 (140b engine.render) - dirty-bit gated triple-write or
 *   func call: if (g_xformDirtyFlags & 0x30): write ecx to 3 stack slots and
 *   call func_4b3a90(arr_main[g_pendingNodeType], esp). Else: write ecx to
 *   arr_main[g_pendingNodeType]+0,+8,+10 and zero +4,+0xc. Always set state |= 0x30.
 */
#ifdef NON_MATCHING
extern void Transform9Words(short *dst, int *src);
#else
extern void Transform9Words(void);
#endif

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_arr_ba630_disp_48;
extern unsigned int g_arr_ba630_main;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_active_00537e88 (*(unsigned int *)MK4_VA(unsigned int, 0x537e88u))
#define g_active_0053a408 (*(unsigned int *)MK4_VA(unsigned int, 0x53a408u))
#define g_armedReloadA (*(unsigned int *)MK4_VA(unsigned int, 0x541fa4u))
#define g_armedReloadB (*(unsigned int *)MK4_VA(unsigned int, 0x541fa8u))
#define g_arr_ba630_disp_48 (*(unsigned int *)MK4_VA(unsigned int, 0x48u))
#define g_arr_ba630_main (*(unsigned int *)MK4_VA(unsigned int, 0x0u))
#define g_audioBankSel (*(unsigned int *)MK4_VA(unsigned int, 0x537f94u))
#define g_audioBoundNode (*(unsigned int *)MK4_VA(unsigned int, 0x5437f0u))
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_chainAccumCur (*(unsigned int *)MK4_VA(unsigned int, 0x542078u))
#define g_cj_00542054 (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_cj_00542058 (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))
#define g_cj_0054205c (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dualBitGate (*(unsigned int *)MK4_VA(unsigned int, 0x53a7b0u))
#define g_eventArmReload (*(unsigned int *)MK4_VA(unsigned int, 0x53a770u))
#define g_fightAxisNegX (*(unsigned int *)MK4_VA(unsigned int, 0x535e70u))
#define g_fightAxisNegY (*(unsigned int *)MK4_VA(unsigned int, 0x535e74u))
#define g_fightAxisPosX (*(unsigned int *)MK4_VA(unsigned int, 0x535e78u))
#define g_fightAxisPosY (*(unsigned int *)MK4_VA(unsigned int, 0x535e7cu))
#define g_fightStateProgress (*(unsigned int *)MK4_VA(unsigned int, 0x535ddcu))
#define g_gameCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a718u))
#define g_installOwnerNode (*(unsigned int *)MK4_VA(unsigned int, 0x535cf8u))
#define g_lastGatedTick (*(unsigned int *)MK4_VA(unsigned int, 0x54358cu))
#define g_lastGatedValue (*(unsigned int *)MK4_VA(unsigned int, 0x543598u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_xformDirtyFlags (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif


#ifdef NON_MATCHING
#include "portable/mem_model.h"

/* Portable twin. One scaled field of the transform entity is broadcast three
 * times. If the two dirty bits are already set the broadcast goes through
 * Transform9Words - which reads dwords and writes back s16 - otherwise it is
 * written straight into the pending node at a stride of eight, with the odd
 * words zeroed.
 *
 * Transform9Words dereferences its second argument directly, so a plain C
 * local carries it; it is never handed back as a packed pointer. */
void DirtyBitTripleWriteOrCall(void)
{
    int v = (int)MK4_NODE_AT(unsigned int, g_xformEntityIdx, 0x48) >> 4;

    if (g_xformDirtyFlags & 0x30) {
        int scratch[3];

        scratch[2] = v;
        scratch[1] = v;
        scratch[0] = v;
        Transform9Words(MK4_NODE(short, g_pendingNodeType), scratch);
    } else {
        unsigned int d = g_pendingNodeType;

        MK4_NODE_AT(unsigned int, d, 0)    = (unsigned int)v;
        MK4_NODE_AT(unsigned int, d, 8)    = (unsigned int)v;
        MK4_NODE_AT(unsigned int, d, 0x10) = (unsigned int)v;
        MK4_NODE_AT(unsigned int, d, 4)    = 0;
        MK4_NODE_AT(unsigned int, d, 0xc)  = 0;
    }
    g_xformDirtyFlags |= 0x30;
}
#else
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

#endif
