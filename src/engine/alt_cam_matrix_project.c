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

/* @addr 0x004b9840 (367b engine.render) - alt-camera-matrix project pass.
 *   On arg [esp+8] non-zero (use-alt-matrix flag): snapshots current
 *   camera matrix at g_vtxMat..7af9a0 into local stack 0x10/0x14/
 *   0x18/0x1c (and high-bytes), loads alternate camera matrix from
 *   g_dispatchSave1554/5c/60/64/68 into g_vtxMat..7af9a0, then calls
 *   Mat3x3VecMul6Bit(arg, &local_vec) to project the vertex
 *   buffer at [esp+0x40] through it.
 *
 *   On arg == 0: loads 4 dwords from [arg] (mat row 0..2) and the
 *   reflected vec at [arg+8] into local stack, populates the alt
 *   camera fields, then calls Mat3x3VecMul6Bit again.
 *
 *   Always restores the original camera matrix afterward if used,
 *   writes 0x1e0 into g_screenH (screen pitch?), and clamps
 *   a derived value: takes local[0x14] (negated z), shl 9, idiv ecx,
 *   then computes `(eax * 15) << 13 >> 16 + 0xf0` and clamps to
 *   (0, 0x1e0) before storing into g_screenH as a u16.
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_screenH;
extern s16 g_vtxMat[];
extern unsigned int g_mat3x3_007af994;
extern unsigned int g_mat3x3_007af998;
extern unsigned int g_mat3x3_007af99c;
extern unsigned int g_mat3x3_007af9a0;
extern unsigned int g_vtxMatBase;
extern unsigned int g_dispatchSave1530;
extern unsigned int g_dispatchSave1531;
extern unsigned int g_dispatchSave1532;
extern unsigned int g_dispatchSave1533;
extern unsigned int g_dispatchSave1554;
extern unsigned int g_dispatchSave1555;
extern unsigned int g_dispatchSave1556;
extern unsigned int g_dispatchSave1557;
extern unsigned int g_dispatchSave1558;
extern unsigned int g_dispatchSave1569;
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
#define g_dispatchSave1530 (*(unsigned int *)MK4_VA(unsigned int, 0xab487cu))
#define g_dispatchSave1531 (*(unsigned int *)MK4_VA(unsigned int, 0xab4880u))
#define g_dispatchSave1532 (*(unsigned int *)MK4_VA(unsigned int, 0xab4884u))
#define g_dispatchSave1533 (*(unsigned int *)MK4_VA(unsigned int, 0xab4888u))
#define g_dispatchSave1554 (*(unsigned int *)MK4_VA(unsigned int, 0xab4d58u))
#define g_dispatchSave1555 (*(unsigned int *)MK4_VA(unsigned int, 0xab4d5cu))
#define g_dispatchSave1556 (*(unsigned int *)MK4_VA(unsigned int, 0xab4d60u))
#define g_dispatchSave1557 (*(unsigned int *)MK4_VA(unsigned int, 0xab4d64u))
#define g_dispatchSave1558 (*(unsigned int *)MK4_VA(unsigned int, 0xab4d68u))
#define g_dispatchSave1569 (*(unsigned int *)MK4_VA(unsigned int, 0xab4e24u))
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
#define g_mat3x3_007af990 (*(short *)MK4_VA(short, 0x7af990u))
#define g_mat3x3_007af994 (*(short *)MK4_VA(short, 0x7af994u))
#define g_mat3x3_007af998 (*(short *)MK4_VA(short, 0x7af998u))
#define g_mat3x3_007af99c (*(short *)MK4_VA(short, 0x7af99cu))
#define g_mat3x3_007af9a0 (*(short *)MK4_VA(short, 0x7af9a0u))
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_screenH (*(unsigned int *)MK4_VA(unsigned int, 0x4f623cu))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_vtxMat (*(short *)MK4_VA(short, 0x7af990u))
#define g_vtxMatBase (*(unsigned int *)MK4_VA(unsigned int, 0xab4878u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif

extern void Mat3x3VecMul6Bit(int *src, int *dst);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void AltCamMatrixProject(int *param_1, int param_2)
{
    /* The nine matrix entries are packed s16 at 0x7af990 +2. THIS function
       moves them a DWORD at a time - two entries per store - while the
       projection helpers read them one word at a time with movsx. So every
       access here is explicitly 32-bit THROUGH THE ADDRESS, independent of how
       gdef happens to type the global; the 16-bit view writes half the bytes
       (that was the mismatch at 0x7af990/994/998). 0x7af9a0 is the odd ninth
       entry and really is a word. */
    int vec[3];            /* the vec3 at [esp+0x10]; Mat3x3VecMul6Bit writes
                              three dwords through the pointer, so it must be
                              an array, not three separate locals. */
    unsigned int save990, save994, save998, save99c;
    unsigned short save9a0;
    int t;

    save994 = *(unsigned int *)&g_mat3x3_007af994;
    save998 = *(unsigned int *)&g_mat3x3_007af998;
    save99c = *(unsigned int *)&g_mat3x3_007af99c;
    save9a0 = *(unsigned short *)&g_mat3x3_007af9a0;
    save990 = *(unsigned int *)&g_mat3x3_007af990;

    if (param_2 != 0) {                       /* swap in the alt camera matrix */
        *(unsigned int *)&g_mat3x3_007af990 = g_dispatchSave1554;
        *(unsigned int *)&g_mat3x3_007af994 = g_dispatchSave1555;
        *(unsigned int *)&g_mat3x3_007af998 = g_dispatchSave1556;
        *(unsigned int *)&g_mat3x3_007af99c = g_dispatchSave1557;
        *(unsigned short *)&g_mat3x3_007af9a0 = (unsigned short)g_dispatchSave1558;
        Mat3x3VecMul6Bit(param_1, vec);
    } else {
        vec[0] = param_1[0];
        vec[2] = param_1[2];
    }

    *(unsigned int *)&g_mat3x3_007af990 = g_vtxMatBase;
    *(unsigned int *)&g_mat3x3_007af994 = g_dispatchSave1530;
    *(unsigned int *)&g_mat3x3_007af998 = g_dispatchSave1531;
    *(unsigned int *)&g_mat3x3_007af99c = g_dispatchSave1532;
    *(unsigned short *)&g_mat3x3_007af9a0 = (unsigned short)g_dispatchSave1533;
    vec[1] = -(int)g_dispatchSave1569;
    Mat3x3VecMul6Bit(vec, vec);

    if (param_2 != 0) {                       /* put the real matrix back */
        *(unsigned int *)&g_mat3x3_007af990 = save990;
        *(unsigned int *)&g_mat3x3_007af994 = save994;
        *(unsigned int *)&g_mat3x3_007af998 = save998;
        *(unsigned int *)&g_mat3x3_007af99c = save99c;
        *(unsigned short *)&g_mat3x3_007af9a0 = save9a0;
    }

    *(unsigned short *)&g_screenH = 0x1e0;    /* orig: mov word ptr, 0x1e0 */
    if (vec[2] > 0) {
        t = ((int)((unsigned)vec[1] << 9)) / vec[2];   /* shl 9 / cdq / idiv */
        t = (int)(((unsigned)t * 15u) << 13) >> 0x10;  /* lea,lea,shl 0xd,sar 0x10 */
        t = t + 0xf0;
        g_walkCallback = t;                   /* stored even when out of range */
        if (t > 0 && t < 0x1e0)
            *(unsigned short *)&g_screenH = (unsigned short)t;
    }
}
#else
__declspec(naked) void AltCamMatrixProject(void) {
    __asm {
        mov     eax, dword ptr [esp + 8]
        sub     esp, 0x2c
        test    eax, eax
        push    ebx
        push    ebp
        push    esi
        push    edi
        je      short L_acm_noAlt
        mov     eax, dword ptr [g_vtxMat]
        mov     ecx, dword ptr [g_dispatchSave1554]
        mov     ebx, dword ptr [g_mat3x3_007af998]
        mov     edi, dword ptr [g_mat3x3_007af99c]
        mov     edx, dword ptr [g_dispatchSave1555]
        mov     ebp, dword ptr [g_mat3x3_007af994]
        mov     si, word ptr [g_mat3x3_007af9a0]
        mov     dword ptr [esp + 0x1c], eax
        mov     eax, dword ptr [g_dispatchSave1556]
        mov     dword ptr [g_vtxMat], ecx
        mov     ecx, dword ptr [g_dispatchSave1557]
        mov     dword ptr [g_mat3x3_007af998], eax
        mov     dword ptr [g_mat3x3_007af99c], ecx
        mov     ecx, dword ptr [esp + 0x40]
        lea     eax, [esp + 0x10]
        mov     dword ptr [g_mat3x3_007af994], edx
        mov     dx, word ptr [g_dispatchSave1558]
        push    eax
        push    ecx
        mov     word ptr [g_mat3x3_007af9a0], dx
        call    Mat3x3VecMul6Bit
        add     esp, 8
        jmp     short L_acm_postCall
    L_acm_noAlt:
        mov     eax, dword ptr [esp + 0x40]
        mov     si, word ptr [esp + 0x2c]
        mov     edi, dword ptr [esp + 0x28]
        mov     ebx, dword ptr [esp + 0x24]
        mov     edx, dword ptr [eax]
        mov     eax, dword ptr [eax + 8]
        mov     ebp, dword ptr [esp + 0x20]
        mov     dword ptr [esp + 0x10], edx
        mov     dword ptr [esp + 0x18], eax
    L_acm_postCall:
        mov     ecx, dword ptr [g_dispatchSave1569]
        mov     edx, dword ptr [g_vtxMatBase]
        mov     eax, dword ptr [g_dispatchSave1530]
        mov     dword ptr [g_vtxMat], edx
        mov     edx, dword ptr [g_dispatchSave1532]
        mov     dword ptr [g_mat3x3_007af994], eax
        neg     ecx
        mov     ax, word ptr [g_dispatchSave1533]
        mov     dword ptr [esp + 0x14], ecx
        mov     ecx, dword ptr [g_dispatchSave1531]
        mov     dword ptr [g_mat3x3_007af99c], edx
        mov     dword ptr [g_mat3x3_007af998], ecx
        lea     ecx, [esp + 0x10]
        lea     edx, [esp + 0x10]
        push    ecx
        push    edx
        mov     word ptr [g_mat3x3_007af9a0], ax
        call    Mat3x3VecMul6Bit
        mov     eax, dword ptr [esp + 0x4c]
        add     esp, 8
        test    eax, eax
        je      short L_acm_skipRestore
        mov     eax, dword ptr [esp + 0x1c]
        mov     dword ptr [g_mat3x3_007af994], ebp
        mov     dword ptr [g_vtxMat], eax
        mov     dword ptr [g_mat3x3_007af998], ebx
        mov     dword ptr [g_mat3x3_007af99c], edi
        mov     word ptr [g_mat3x3_007af9a0], si
    L_acm_skipRestore:
        mov     ecx, dword ptr [esp + 0x18]
        mov     word ptr [g_screenH], 0x1e0
        test    ecx, ecx
        jle     short L_acm_done
        mov     eax, dword ptr [esp + 0x14]
        shl     eax, 9
        cdq
        idiv    ecx
        lea     eax, [eax + eax*2]
        lea     eax, [eax + eax*4]
        shl     eax, 0xd
        sar     eax, 0x10
        add     eax, 0xf0
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        jle     short L_acm_done
        cmp     eax, 0x1e0
        jge     short L_acm_done
        mov     word ptr [g_screenH], ax
    L_acm_done:
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 0x2c
        ret
    }
}
#endif
