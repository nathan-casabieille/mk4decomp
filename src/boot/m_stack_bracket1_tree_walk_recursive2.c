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

extern void MStackBracket1_TreeWalkRecursive2(void);
extern void DirtyDoubleDeref(void);
extern void PushPopScaled1cDoubleCall(void);
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_installChainTailSlot;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_active_00537e88 (*(unsigned int *)MK4_VA(unsigned int, 0x537e88u))
#define g_active_0053a408 (*(unsigned int *)MK4_VA(unsigned int, 0x53a408u))
#define g_armedReloadA (*(unsigned int *)MK4_VA(unsigned int, 0x541fa4u))
#define g_armedReloadB (*(unsigned int *)MK4_VA(unsigned int, 0x541fa8u))
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
#define g_eventQueuePending (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_fightAxisNegX (*(unsigned int *)MK4_VA(unsigned int, 0x535e70u))
#define g_fightAxisNegY (*(unsigned int *)MK4_VA(unsigned int, 0x535e74u))
#define g_fightAxisPosX (*(unsigned int *)MK4_VA(unsigned int, 0x535e78u))
#define g_fightAxisPosY (*(unsigned int *)MK4_VA(unsigned int, 0x535e7cu))
#define g_fightStateProgress (*(unsigned int *)MK4_VA(unsigned int, 0x535ddcu))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_gameCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a718u))
#define g_installChainTailSlot (*(unsigned int *)MK4_VA(unsigned int, 0x53a3a8u))
#define g_installOwnerNode (*(unsigned int *)MK4_VA(unsigned int, 0x535cf8u))
#define g_lastGatedTick (*(unsigned int *)MK4_VA(unsigned int, 0x54358cu))
#define g_lastGatedValue (*(unsigned int *)MK4_VA(unsigned int, 0x543598u))
#define g_matrixStackTop (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformDirtyFlags (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif


#ifdef NON_MATCHING
extern void MStackBracket5_FieldClear_StateAdvance(void);
extern void MStackPush2ChainPrepend(void);
extern void MStackPushCallCallPop_func_00405e20(void);

/* @addr 0x00406dd0 (595b) - NATIVE twin; the matching build synthesizes it.
 *
 * The recursive tree builder. Saves the pending-type slot, allocates a
 * fresh node via the five-deep bracket, then copies the entity record into
 * it: +0xc/+0x10/+0x14 to +0x30/+0x34/+0x38, the entity word split as the
 * signed top 12 bits to +0x1c and the low 20 (tagged 0x8000000) to +0x20.
 * Entity advances 7 words to the first child; bit 3 of the packed word
 * skips descent, bit 4 stops the sibling loop after each prepend, and a
 * not-found from the child recursion routes through the 405e20 insert
 * before publishing null. Pause exits leak the bracket at every depth. */
void MStackBracket1_TreeWalkRecursive2(void)
{
    unsigned int w;

    g_matrixStackTop++;
    *MK4_NODE(unsigned int, g_matrixStackTop) = g_pendingNodeType;

    MStackBracket5_FieldClear_StateAdvance();
    if (g_framePauseFlag != 0) return;              /* bracket leaked */

    g_pendingNodeType = g_currentNodeIdx;
    if ((g_xformDirtyFlags & 4u) == 0) {
        MK4_NODE_AT(unsigned int, g_pendingNodeType, 0x24) = g_xformEntityIdx;
        w = MK4_NODE_AT(unsigned int, g_xformEntityIdx, 0xc);
        g_walkCallback = w;
        MK4_NODE_AT(unsigned int, g_pendingNodeType, 0x30) = w;
        w = MK4_NODE_AT(unsigned int, g_xformEntityIdx, 0x10);
        g_walkCallback = w;
        MK4_NODE_AT(unsigned int, g_pendingNodeType, 0x34) = w;
        w = MK4_NODE_AT(unsigned int, g_xformEntityIdx, 0x14);
        g_walkCallback = w;
        MK4_NODE_AT(unsigned int, g_pendingNodeType, 0x38) = w;
#ifdef TARGET_SDL
        /* MK4_TRACE_BIND=N: the bind-offset install - the asset record the
         * scene build reads (+0xc/+0x10/+0x14) and the node it writes them
         * into (+0x30/+0x34/+0x38). An all-zero source means the asset
         * carries no local translation for that node. */
        { extern void SDL_Log(const char *, ...); extern char *getenv(const char *);
          extern int atoi(const char *);
          static int nb, limb = -1;
          if (limb < 0) { char *e = getenv("MK4_TRACE_BIND"); limb = e ? atoi(e) : 0; }
          if (nb < limb) { nb++;
            SDL_Log("BIND node=%x src=%x v=[%d %d %d]",
                    g_pendingNodeType, g_xformEntityIdx,
                    MK4_NODE_AT(int, g_xformEntityIdx, 0xc),
                    MK4_NODE_AT(int, g_xformEntityIdx, 0x10),
                    MK4_NODE_AT(int, g_xformEntityIdx, 0x14)); } }
#endif

        g_matrixStackTop++;
        w = *MK4_NODE(unsigned int, g_xformEntityIdx);
        g_walkCallback = w;
        *MK4_NODE(unsigned int, g_matrixStackTop) = w;
        w = (unsigned int)((int)g_walkCallback >> 0x14);
        g_walkCallback = w;
        MK4_NODE_AT(unsigned int, g_pendingNodeType, 0x1c) = w;
        w = *MK4_NODE(unsigned int, g_matrixStackTop);
        g_matrixStackTop--;
        w = (w & 0xfffffu) | 0x8000000u;
        g_walkCallback = w;
        MK4_NODE_AT(unsigned int, g_pendingNodeType, 0x20) = w;
        g_xformScratch94 = w & 4u;                  /* dead, as original */
        g_xformEntityIdx += 7;
        w = MK4_NODE_AT(unsigned int, g_pendingNodeType, 0x20);
        g_walkCallback = w;
        g_xformScratch94 = w & 8u;
        if ((w & 8u) == 0) {
            MStackBracket1_TreeWalkRecursive2();
            if (g_framePauseFlag != 0) return;      /* bracket leaked */
            for (;;) {
                if ((g_xformDirtyFlags & 4u) == 0) {
                    g_matrixStackTop++;
                    *MK4_NODE(unsigned int, g_matrixStackTop) = g_xformEntityIdx;
                    g_xformEntityIdx = g_pendingNodeType;
                    MStackPush2ChainPrepend();
                    if (g_framePauseFlag != 0) return;
                    g_xformEntityIdx = *MK4_NODE(unsigned int, g_matrixStackTop);
                    g_matrixStackTop--;
                    w = MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x20);
                    g_walkCallback = w;
                    g_xformScratch94 = w & 0x10u;
                    if (w & 0x10u) break;
                    MStackBracket1_TreeWalkRecursive2();
                    if (g_framePauseFlag != 0) return;
                } else {
                    g_currentNodeIdx = g_pendingNodeType;
                    MStackPushCallCallPop_func_00405e20();
                    if (g_framePauseFlag != 0) return;
                    g_pendingNodeType = 0;
                    break;
                }
            }
        }
    }

    g_currentNodeIdx = g_pendingNodeType;
    g_xformDirtyFlags |= 4;
    if (g_currentNodeIdx != 0) g_xformDirtyFlags ^= 4;
    g_pendingNodeType = *MK4_NODE(unsigned int, g_matrixStackTop);
    g_matrixStackTop--;
}
#else
/* no matching-side C - the synthesizer provides 0x00406dd0. */
#endif

/* @addr 0x004a7030 (189b audio) - packed-ptr install + chain init + tail-jmp.
 *   g_xformEntityIdx = packed_ptr(0x50d418); call MStackBracket1_TreeWalkRecursive2; pause? -> end;
 *   (208c&4)? -> end;
 *   mstack-push g_scaledInit; [0x53a3a8] = g_scaledInit;
 *   chain[+0x40] = 0x6487; chain[+0x3c] = 0; chain[+0x44] = 0; chain[+0x30] = 0;
 *   g_walkCallback = 9; call DirtyDoubleDeref; pause? -> end;
 *   g_xformEntityIdx = g_scaledInit; mstack-pop into g_scaledInit; jmp PushPopScaled1cDoubleCall.
 */

extern unsigned int g_matrixStack_arr;

#ifdef NON_MATCHING
/* NATIVE twin of the naked driver below: points the walk at the static
 * record 0x50d418 (packed), runs the recursive tree builder, then stamps
 * the root node (+0x40 = 0x6487 countdown, three cleared fields), runs the
 * double-deref pass with callback 9 and tail-calls the scaled double-call.
 * The root index also lands in the install tail slot and rides the matrix
 * stack across the deref pass. */
void InstallChainInitTailJmp(void)
{
    g_xformEntityIdx = 0x0050d418u >> 2;
    MStackBracket1_TreeWalkRecursive2();
    if (g_framePauseFlag != 0) return;
    if (g_xformDirtyFlags & 4u) return;
    g_matrixStackTop++;
    g_installChainTailSlot = g_currentNodeIdx;
    *MK4_NODE(unsigned int, g_matrixStackTop) = g_currentNodeIdx;
    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x40) = 0x6487;
    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x3c) = 0;
    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x44) = 0;
    MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x30) = 0;
    g_walkCallback = 9;
    DirtyDoubleDeref();
    if (g_framePauseFlag != 0) return;
    g_xformEntityIdx = g_currentNodeIdx;
    g_currentNodeIdx = *MK4_NODE(unsigned int, g_matrixStackTop);
    g_matrixStackTop--;
    PushPopScaled1cDoubleCall();    /* tail-jmp in the original */
}
#else
__declspec(naked) void InstallChainInitTailJmp(void) {
    __asm {
        mov     eax, 0x0050d418
        shr     eax, 2
        mov     dword ptr [g_xformEntityIdx], eax
        call    MStackBracket1_TreeWalkRecursive2
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   9dh
        _emit   00h
        _emit   00h
        _emit   00h
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   0fh
        _emit   85h
        _emit   90h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     ecx, dword ptr [g_matrixStackTop]
        mov     eax, dword ptr [g_currentNodeIdx]
        inc     ecx
        mov     dword ptr [g_installChainTailSlot], eax
        mov     dword ptr [g_matrixStackTop], ecx
        mov     [ecx*4 + g_matrixStack_arr], eax
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     dword ptr [ecx*4 + 0x40], 0x00006487
        mov     dword ptr [ecx*4 + 0x3c], 0
        lea     eax, [ecx*4 + g_matrixStack_arr]
        mov     dword ptr [eax + 0x44], 0
        mov     dword ptr [eax + 0x30], 0
        mov     dword ptr [g_walkCallback], 9
        call    DirtyDoubleDeref
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   29h
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [g_matrixStackTop]
        mov     dword ptr [g_xformEntityIdx], edx
        mov     ecx, [eax*4 + g_matrixStack_arr]
        dec     eax
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [g_matrixStackTop], eax
        jmp     PushPopScaled1cDoubleCall
        ret
    }
}
#endif
