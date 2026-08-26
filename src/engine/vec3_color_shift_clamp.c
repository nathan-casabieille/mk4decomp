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

/*
 * Vec3ColorShiftClamp - 256b RGB-channel sar+pack into a 16-bit color word triplet.
 *   For each of 3 channels (R, G, B), reads g_triStripRingB/988/98c, arithmetic-shift-right by cl
 *   (with negative clamp to 0, max clamp to 0x1f), computes (0xffff - channel) XOR with existing
 *   channel bits at word [esi + 0x14/0x16/0x18], packs the resulting 5-bit field into bits [0:5],
 *   [5:10] (shl 5), and [10:15] (shl 10) of the destination word.
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_triStripRingB;
extern s32 g_vtxOut2_z;
extern s32 g_vtxOut_z;
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
#define g_fightAxisNegX (*(unsigned int *)MK4_VA(unsigned int, 0x535e70u))
#define g_fightAxisNegY (*(unsigned int *)MK4_VA(unsigned int, 0x535e74u))
#define g_fightAxisPosX (*(unsigned int *)MK4_VA(unsigned int, 0x535e78u))
#define g_fightAxisPosY (*(unsigned int *)MK4_VA(unsigned int, 0x535e7cu))
#define g_fightStateProgress (*(unsigned int *)MK4_VA(unsigned int, 0x535ddcu))
#define g_gameCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a718u))
#define g_installOwnerNode (*(unsigned int *)MK4_VA(unsigned int, 0x535cf8u))
#define g_lastGatedTick (*(unsigned int *)MK4_VA(unsigned int, 0x54358cu))
#define g_lastGatedValue (*(unsigned int *)MK4_VA(unsigned int, 0x543598u))
#define g_min_007af984 (*(unsigned int *)MK4_VA(unsigned int, 0x7af984u))
#define g_min_007af988 (*(unsigned int *)MK4_VA(unsigned int, 0x7af988u))
#define g_min_007af98c (*(unsigned int *)MK4_VA(unsigned int, 0x7af98cu))
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_triStripRingB (*(unsigned int *)MK4_VA(unsigned int, 0x7af984u))
#define g_vtxOut2_z (*(int *)MK4_VA(int, 0x7af988u))
#define g_vtxOut_z (*(int *)MK4_VA(int, 0x7af98cu))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif


#ifdef NON_MATCHING
/* Portable twin (verified via verify_coexec). For each of three channels, read
 * the source dword, arithmetic-shift-right by (shift & 0x1f), clamp to
 * [0, 0x1f], take t5 = (0xffff - v) & 0x1f, and pack t5 into bits [0:5], [5:10]
 * and [10:15] of the destination 16-bit word, preserving its bit 15. The
 * source globals are read SIGNED (asm uses sar) - hence the (int) casts, which
 * matter under the verifier (it models globals as unsigned). */
void Vec3ColorShiftClamp(int dest_ptr, unsigned char shift)
{
    unsigned int s = shift & 0x1f;
#define PACK_CH(SRC, OFF) do {                                          \
        unsigned short *p = (unsigned short *)MK4_PTR(dest_ptr + (OFF));        \
        int v = (int)(SRC) >> s;          /* sar (signed) */            \
        unsigned int t5;                                                \
        if (v < 0)    v = 0;                                            \
        if (v > 0x1f) v = 0x1f;                                         \
        t5 = (0xffffu - (unsigned int)v) & 0x1f;                        \
        *p = (unsigned short)((*p & 0x8000) | t5 | (t5 << 5) | (t5 << 10)); \
    } while (0)
    PACK_CH(g_triStripRingB, 0x14);
    PACK_CH(g_vtxOut2_z,     0x16);
    PACK_CH(g_vtxOut_z,      0x18);
#undef PACK_CH
}
#else
__declspec(naked) void Vec3ColorShiftClamp(void)
{
    __asm
    {
        mov     ecx, dword ptr [esp + 8]
        push    ebx
        push    esi
        push    edi
        mov     edi, dword ptr [g_triStripRingB]
        sar     edi, cl
        test    edi, edi
        jge     short L_r_pos
        xor     edi, edi
    L_r_pos:
        cmp     edi, 0x1f
        jle     short L_r_lo
        mov     edi, 0x1f
    L_r_lo:
        mov     esi, dword ptr [esp + 0x10]
        mov     eax, 0xffff
        sub     eax, edi
        mov     dx, word ptr [esi + 0x14]
        xor     al, dl
        and     eax, 0x1f
        xor     eax, edx
        mov     edx, eax
        and     eax, 0x1f
        and     edx, 0xfc1f
        shl     eax, 5
        or      edx, eax
        mov     eax, edx
        and     edx, 0x3e0
        and     eax, 0x83ff
        shl     edx, 5
        or      eax, edx
        mov     word ptr [esi + 0x14], ax
        mov     edx, dword ptr [g_vtxOut2_z]
        sar     edx, cl
        test    edx, edx
        jge     short L_g_pos
        xor     edx, edx
    L_g_pos:
        cmp     edx, 0x1f
        jle     short L_g_lo
        mov     edx, 0x1f
    L_g_lo:
        mov     bx, word ptr [esi + 0x16]
        mov     eax, 0xffff
        sub     eax, edx
        xor     al, bl
        and     eax, 0x1f
        xor     eax, ebx
        mov     edx, eax
        and     eax, 0x1f
        and     edx, 0xfc1f
        shl     eax, 5
        or      edx, eax
        mov     eax, edx
        and     edx, 0x3e0
        and     eax, 0x83ff
        shl     edx, 5
        or      eax, edx
        mov     word ptr [esi + 0x16], ax
        mov     edx, dword ptr [g_vtxOut_z]
        sar     edx, cl
        test    edx, edx
        jge     short L_b_pos
        xor     edx, edx
    L_b_pos:
        cmp     edx, 0x1f
        jle     short L_b_lo
        mov     edx, 0x1f
    L_b_lo:
        mov     cx, word ptr [esi + 0x18]
        mov     eax, 0xffff
        sub     eax, edx
        pop     edi
        xor     al, cl
        and     eax, 0x1f
        xor     eax, ecx
        mov     ecx, eax
        and     eax, 0x1f
        and     ecx, 0xfc1f
        shl     eax, 5
        or      ecx, eax
        mov     edx, ecx
        and     ecx, 0x3e0
        and     edx, 0x83ff
        shl     ecx, 5
        or      edx, ecx
        mov     word ptr [esi + 0x18], dx
        pop     esi
        pop     ebx
        ret
    }
}
#endif
