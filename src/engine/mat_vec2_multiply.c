/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
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

/* @addr 0x004b31e0 (301b engine.app) - 2x3-vector × 3x3-matrix Q12 multiply.
 *   Calls Word9Reorder(0x007af990, &local) to pull 9 words into local
 *   stack buf. Computes 6 Q12 dot products:
 *     out[0..2] = M_row0 . v0,  M_row0 . v1
 *     out[3..5] = M_row1 . v0,  M_row1 . v1
 *   (where v0 is words at +0x18, v1 at +0x1c). Matrix is in
 *   g_lightMat00..d4. Results stored to g_vtxLight0_x..ec.
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern s16 g_vtxMat[];
extern unsigned int g_lightMat00;
extern unsigned int g_lightMat01;
extern unsigned int g_lightMat02;
extern unsigned int g_dispatchSave1627;
extern unsigned int g_dispatchSave1628;
extern unsigned int g_dispatchSave1629;
extern s32 g_vtxLight0_x;
extern s32 g_vtxLight0_y;
extern s32 g_vtxLight0_z;
extern s32 g_vtxLight1_x;
extern s32 g_vtxLight1_z;
extern s32 g_vtxLight1_y;
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
#define g_dispatchSave1627 (*(unsigned int *)MK4_VA(unsigned int, 0x7af9ccu))
#define g_dispatchSave1628 (*(unsigned int *)MK4_VA(unsigned int, 0x7af9d0u))
#define g_dispatchSave1629 (*(unsigned int *)MK4_VA(unsigned int, 0x7af9d4u))
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
#define g_lightMat00 (*(unsigned int *)MK4_VA(unsigned int, 0x7af9c0u))
#define g_lightMat01 (*(unsigned int *)MK4_VA(unsigned int, 0x7af9c4u))
#define g_lightMat02 (*(unsigned int *)MK4_VA(unsigned int, 0x7af9c8u))
#define g_lightMat20 (*(unsigned int *)MK4_VA(unsigned int, 0x7af9d8u))
#define g_lightMat21 (*(unsigned int *)MK4_VA(unsigned int, 0x7af9dcu))
#define g_lightMat22 (*(unsigned int *)MK4_VA(unsigned int, 0x7af9e0u))
#define g_mat3x3_007af990 (*(short *)MK4_VA(short, 0x7af990u))
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_vtxLight0_x (*(int *)MK4_VA(int, 0x7af9d8u))
#define g_vtxLight0_y (*(int *)MK4_VA(int, 0x7af9dcu))
#define g_vtxLight0_z (*(int *)MK4_VA(int, 0x7af9e0u))
#define g_vtxLight1_x (*(int *)MK4_VA(int, 0x7af9e4u))
#define g_vtxLight1_y (*(int *)MK4_VA(int, 0x7af9ecu))
#define g_vtxLight1_z (*(int *)MK4_VA(int, 0x7af9e8u))
#define g_vtxMat (*(short *)MK4_VA(short, 0x7af990u))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif

extern void Word9Reorder(short *src, short *dst);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void MatVec2Multiply(void)
{
    /* Word9Reorder transposes a 3x3 s16 matrix through a POINTER, writing 18
       consecutive bytes. The Ghidra lift declared nine separate `short` locals
       and passed `&local_20`: nothing makes separate locals contiguous or
       ordered, so the callee scribbled over the frame - FETCH_UNMAPPED under
       co-exec. It has to be an array. */
    short t[9];
    unsigned acc;

    Word9Reorder((short *)&g_mat3x3_007af990, t);

    /* orig reads the temps with movsx and shifts with sar, so this is all
       SIGNED; the products accumulate through unsigned because three 32x16
       products can exceed INT_MAX and signed overflow is UB. */
    acc = (unsigned)((int)g_lightMat00 * (int)t[0])
        + (unsigned)((int)g_lightMat01 * (int)t[1])
        + (unsigned)((int)g_lightMat02 * (int)t[2]);
    g_lightMat20 = (int)acc >> 0xc;
    acc = (unsigned)((int)g_lightMat00 * (int)t[3])
        + (unsigned)((int)g_lightMat01 * (int)t[4])
        + (unsigned)((int)g_lightMat02 * (int)t[5]);
    g_lightMat21 = (int)acc >> 0xc;
    acc = (unsigned)((int)g_lightMat00 * (int)t[6])
        + (unsigned)((int)g_lightMat01 * (int)t[7])
        + (unsigned)((int)g_lightMat02 * (int)t[8]);
    g_lightMat22 = (int)acc >> 0xc;

    acc = (unsigned)((int)g_dispatchSave1627 * (int)t[0])
        + (unsigned)((int)g_dispatchSave1628 * (int)t[1])
        + (unsigned)((int)g_dispatchSave1629 * (int)t[2]);
    g_vtxLight1_x = (int)acc >> 0xc;
    acc = (unsigned)((int)g_dispatchSave1627 * (int)t[3])
        + (unsigned)((int)g_dispatchSave1628 * (int)t[4])
        + (unsigned)((int)g_dispatchSave1629 * (int)t[5]);
    g_vtxLight1_z = (int)acc >> 0xc;
    acc = (unsigned)((int)g_dispatchSave1627 * (int)t[6])
        + (unsigned)((int)g_dispatchSave1628 * (int)t[7])
        + (unsigned)((int)g_dispatchSave1629 * (int)t[8]);
    g_vtxLight1_y = (int)acc >> 0xc;
}
#else
__declspec(naked) void MatVec2Multiply(void) {
    __asm {
        sub     esp, 0x20
        _emit   8dh
        _emit   44h
        _emit   24h
        _emit   0h
        push    ebx
        push    ebp
        push    esi
        push    edi
        push    eax
        push    offset g_vtxMat
        call    Word9Reorder
        movsx   esi, word ptr [esp + 0x18]
        movsx   edx, word ptr [esp + 0x1a]
        mov     eax, dword ptr [g_lightMat00]
        mov     ecx, dword ptr [g_lightMat01]
        mov     ebx, eax
        mov     ebp, ecx
        imul    ebx, esi
        imul    ebp, edx
        movsx   edi, word ptr [esp + 0x1c]
        mov     edx, dword ptr [g_lightMat02]
        add     ebx, ebp
        mov     ebp, edx
        add     esp, 8
        imul    ebp, edi
        movsx   edi, word ptr [esp + 0x16]
        add     ebx, ebp
        mov     ebp, eax
        sar     ebx, 0x0c
        imul    ebp, edi
        mov     dword ptr [g_vtxLight0_x], ebx
        mov     edi, ecx
        movsx   ebx, word ptr [esp + 0x18]
        imul    edi, ebx
        add     ebp, edi
        mov     ebx, edx
        movsx   edi, word ptr [esp + 0x1a]
        imul    ebx, edi
        add     ebp, ebx
        movsx   ebx, word ptr [esp + 0x1c]
        sar     ebp, 0x0c
        imul    eax, ebx
        movsx   ebx, word ptr [esp + 0x1e]
        mov     dword ptr [g_vtxLight0_y], ebp
        imul    ecx, ebx
        movsx   ebp, word ptr [esp + 0x20]
        imul    edx, ebp
        add     eax, ecx
        mov     ecx, dword ptr [g_dispatchSave1628]
        add     eax, edx
        movsx   edx, word ptr [esp + 0x12]
        sar     eax, 0x0c
        mov     dword ptr [g_vtxLight0_z], eax
        mov     eax, dword ptr [g_dispatchSave1627]
        mov     ebx, eax
        imul    ebx, esi
        mov     esi, ecx
        imul    esi, edx
        mov     edx, dword ptr [g_dispatchSave1629]
        add     ebx, esi
        movsx   esi, word ptr [esp + 0x14]
        mov     ebp, edx
        imul    ebp, esi
        movsx   esi, word ptr [esp + 0x16]
        add     ebx, ebp
        mov     ebp, ecx
        sar     ebx, 0x0c
        mov     dword ptr [g_vtxLight1_x], ebx
        mov     ebx, eax
        imul    ebx, esi
        movsx   esi, word ptr [esp + 0x18]
        imul    ebp, esi
        mov     esi, edx
        add     ebx, ebp
        imul    esi, edi
        add     ebx, esi
        movsx   esi, word ptr [esp + 0x1c]
        imul    eax, esi
        movsx   esi, word ptr [esp + 0x1e]
        imul    ecx, esi
        sar     ebx, 0x0c
        mov     dword ptr [g_vtxLight1_z], ebx
        add     eax, ecx
        movsx   ecx, word ptr [esp + 0x20]
        imul    edx, ecx
        add     eax, edx
        pop     edi
        sar     eax, 0x0c
        pop     esi
        pop     ebp
        mov     dword ptr [g_vtxLight1_y], eax
        pop     ebx
        add     esp, 0x20
        ret
    }
}
#endif
