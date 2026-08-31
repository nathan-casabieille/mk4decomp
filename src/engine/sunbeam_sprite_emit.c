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

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_dispatchSave725;
extern unsigned int g_sunbeamSpriteVar;
extern u32 g_inLoopStep;
extern unsigned int g_triStripRingB;
extern s32 g_vtxOut2_z;
extern s32 g_vtxOut_z;
extern s32 g_vtxTransX;
extern s32 g_vtxTransY;
extern s32 g_vtxTransZ;
extern s16 g_vtxScreenX;
extern s16 g_vtxScreenY;
extern unsigned int g_dispatchSave1501;
extern unsigned int g_dispatchSave1502;
extern unsigned int g_dispatchSave1503;
extern unsigned int g_dispatchSave1581;
#endif
#ifndef NON_MATCHING
extern void AdvanceTriStripRing(void);
#endif
#ifndef NON_MATCHING
extern void Helper_DrawCursor(void);
#endif
#ifndef NON_MATCHING
extern void ProjectVertex(void);
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
#define g_dispatchSave1501 (*(unsigned int *)MK4_VA(unsigned int, 0xab4398u))
#define g_dispatchSave1502 (*(unsigned int *)MK4_VA(unsigned int, 0xab439cu))
#define g_dispatchSave1503 (*(unsigned int *)MK4_VA(unsigned int, 0xab43a0u))
#define g_dispatchSave1581 (*(unsigned int *)MK4_VA(unsigned int, 0xab51fcu))
#define g_dispatchSave725 (*(unsigned int *)MK4_VA(unsigned int, 0x4f6398u))
#define g_dualBitGate (*(unsigned int *)MK4_VA(unsigned int, 0x53a7b0u))
#define g_eventArmReload (*(unsigned int *)MK4_VA(unsigned int, 0x53a770u))
#define g_fightAxisNegX (*(unsigned int *)MK4_VA(unsigned int, 0x535e70u))
#define g_fightAxisNegY (*(unsigned int *)MK4_VA(unsigned int, 0x535e74u))
#define g_fightAxisPosX (*(unsigned int *)MK4_VA(unsigned int, 0x535e78u))
#define g_fightAxisPosY (*(unsigned int *)MK4_VA(unsigned int, 0x535e7cu))
#define g_fightStateProgress (*(unsigned int *)MK4_VA(unsigned int, 0x535ddcu))
#define g_gameCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a718u))
#define g_inLoopStep (*(unsigned int *)MK4_VA(unsigned int, 0x7af92cu))
#define g_installOwnerNode (*(unsigned int *)MK4_VA(unsigned int, 0x535cf8u))
#define g_lastGatedTick (*(unsigned int *)MK4_VA(unsigned int, 0x54358cu))
#define g_lastGatedValue (*(unsigned int *)MK4_VA(unsigned int, 0x543598u))
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_sunbeamSpriteVar (*(unsigned int *)MK4_VA(unsigned int, 0x4f6580u))
#define g_tickW1 (*(unsigned int *)MK4_VA(unsigned int, 0x543550u))
#define g_triStripRingB (*(unsigned int *)MK4_VA(unsigned int, 0x7af984u))
#define g_vtxOut2_z (*(int *)MK4_VA(int, 0x7af988u))
#define g_vtxOut_z (*(int *)MK4_VA(int, 0x7af98cu))
#define g_vtxScreenX (*(unsigned int *)MK4_VA(unsigned int, 0x7af9bcu))
#define g_vtxScreenY (*(short *)MK4_VA(short, 0x7af9beu))
#define g_vtxTransX (*(int *)MK4_VA(int, 0x7af9a4u))
#define g_vtxTransY (*(int *)MK4_VA(int, 0x7af9a8u))
#define g_vtxTransZ (*(int *)MK4_VA(int, 0x7af9acu))
#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif


#ifdef NON_MATCHING
#include "portable/mem_model.h"

extern void AdvanceTriStripRing(s16 v0, s16 v1, s16 v2);
extern void ProjectVertex(void);
extern void Helper_DrawCursor(void *entry);

/* Portable twin, written from the disassembly. The sun sprite's four beams.
 *
 * The size at 0x004f6580 pulses: it steps by g_dispatchSave1581 each call and
 * the CLAMPS retarget the step - hitting the low bound (0x64) sets it to +0x10,
 * hitting the high bound (0x100) sets it to -8 - so the value bounces between
 * the two forever.
 *
 * The entity's corner table at 0x004f6398 (16 bytes per entry, ENTITY MINUS
 * ONE) provides four points; each is projected and its screen Y decremented.
 * Four thin quads then go out, every one with flag 0x20 set in the record's
 * 0x2f - Helper_DrawCursor skips vertex 1 on that flag, so only v0 and v2
 * matter - four 4-pixel-thick edges of the RECTANGLE the four corners
 * describe: TOP (P0 -> P1 with y+4), BOTTOM (P2 with y-4 -> P3), LEFT
 * (P0 -> P2 with x+4) and RIGHT (P1 -> P3 with x-4). It is a FRAME, not a
 * filled plate: this is the menu's selection highlight, and the row's text
 * has to stay readable inside it.
 *
 * The record is a stack local, as in the original; the submit copies it. The
 * fields the original leaves as stack garbage (v1 at +4, +0xe/+0xf,
 * +0x16..+0x19) are zeroed here - co-executing runs cannot share garbage. */
void SunbeamSpriteEmit(void)
{
    unsigned int var, tbl, u, w1;
    unsigned int packed;
    short px[4], py[4];
    unsigned short rec[14];
    int i;

    var = *MK4_VA(unsigned int, 0x4f6580u) + *MK4_VA(unsigned int, 0xab51fcu);
    *MK4_VA(unsigned int, 0x4f6580u) = var;
    if ((int)var < 0x64) {
        var = 0x64;
        *MK4_VA(unsigned int, 0xab51fcu) = 0x10;
        *MK4_VA(unsigned int, 0x4f6580u) = var;
    }
    if ((int)var > 0x100) {
        var = 0x100;
        *MK4_VA(unsigned int, 0x4f6580u) = 0x100;
        *MK4_VA(unsigned int, 0xab51fcu) = 0xfffffff8u;
    }

    if (g_inLoopStep != 0)
        return;

    g_vtxTransX = (int)g_dispatchSave1501 >> 16;
    g_vtxTransY = (int)g_dispatchSave1502 >> 16;
    g_vtxTransZ = (int)g_dispatchSave1503 >> 7;

    tbl = ((g_xformEntityIdx - 1u) << 4) + 0x4f6398u;
    for (i = 0; i < 4; i++) {
        AdvanceTriStripRing(*(short *)MK4_PTR(tbl),
                            *(short *)MK4_PTR(tbl + 2), 0);
        ProjectVertex();
        px[i] = *MK4_VA(short, 0x7af9bcu);
        py[i] = (short)(*MK4_VA(short, 0x7af9beu) - 1);
        tbl += 4;
    }

    if ((int)*MK4_VA(int, 0x7af984u) <= 0
        || (int)*MK4_VA(int, 0x7af988u) <= 0
        || (int)*MK4_VA(int, 0x7af98cu) <= 0)
        return;

    w1 = g_tickW1;
    if ((int)w1 < 0x10)
        u = 0;
    else
        u = (unsigned int)(((int)(w1 + ((w1 >> 31) & 7u)) >> 3) - 1);
    u = (unsigned int)(short)u;
    packed = (unsigned int)((int)(*MK4_VA(unsigned int, 0x4f6580u) * u) >> 8);
    packed = (((packed << 5) | packed) << 5) | packed;

    rec[9]  = 1;                                   /* +0x12: sort key        */
    ((unsigned char *)rec)[0x10] = 1;
    ((unsigned char *)rec)[0x11] = 0x64;
    ((unsigned char *)rec)[0xc]  = 1;
    ((unsigned char *)rec)[0xd]  = 0x64;
    rec[0xd] = 0x2f;                               /* +0x1a: flags, v1 skip  */
    rec[0xa] = (unsigned short)packed;             /* +0x14: colour          */
    rec[2] = 0; rec[3] = 0;                        /* v1 - garbage in orig   */
    rec[7] = 0; rec[0xb] = 0; rec[0xc] = 0;

    rec[0] = (unsigned short)px[0];
    rec[1] = (unsigned short)py[0];
    rec[4] = (unsigned short)px[1];
    rec[5] = (unsigned short)(py[1] + 4);
    Helper_DrawCursor(rec);

    rec[0] = (unsigned short)px[2];                /* BOTTOM: P2 -> P3       */
    rec[1] = (unsigned short)(py[2] - 4);
    rec[4] = (unsigned short)px[3];
    rec[5] = (unsigned short)py[3];
    Helper_DrawCursor(rec);

    rec[0] = (unsigned short)px[0];                /* LEFT:   P0 -> P2 + 4   */
    rec[1] = (unsigned short)py[0];
    rec[4] = (unsigned short)(px[2] + 4);
    rec[5] = (unsigned short)py[2];
    Helper_DrawCursor(rec);

    rec[0] = (unsigned short)px[1];                /* RIGHT:  P1 -> P3 - 4   */
    rec[1] = (unsigned short)py[1];
    rec[4] = (unsigned short)(px[3] - 4);
    rec[5] = (unsigned short)py[3];
    Helper_DrawCursor(rec);
}
#else
__declspec(naked) void SunbeamSpriteEmit(void)
{
    __asm {
        mov      eax, dword ptr [g_sunbeamSpriteVar]
        mov      edx, dword ptr [g_dispatchSave1581]
        sub      esp, 0x2c
        add      eax, edx
        mov      dword ptr [g_sunbeamSpriteVar], eax
        push     ebx
        mov      ebx, 0x64
        push     ebp
        push     esi
        cmp      eax, ebx
        push     edi
        jge      L_d2a3
        mov      eax, ebx
        mov      dword ptr [g_dispatchSave1581], 0x10
        mov      dword ptr [g_sunbeamSpriteVar], eax
    L_d2a3:
        cmp      eax, 0x100
        jle      L_d2be
        mov      dword ptr [g_sunbeamSpriteVar], 0x100
        mov      dword ptr [g_dispatchSave1581], 0xfffffff8
    L_d2be:
        mov      eax, dword ptr [g_inLoopStep]
        test     eax, eax
        jne      L_d48f
        mov      eax, dword ptr [g_xformEntityIdx]
        mov      ecx, dword ptr [g_dispatchSave1501]
        mov      edx, dword ptr [g_dispatchSave1502]
        lea      esi, [esp + 0x12]
        lea      edi, [eax - 1]
        mov      eax, dword ptr [g_dispatchSave1503]
        sar      ecx, 0x10
        sar      edx, 0x10
        sar      eax, 7
        shl      edi, 4
        mov      dword ptr [g_vtxTransX], ecx
        mov      dword ptr [g_vtxTransY], edx
        mov      dword ptr [g_vtxTransZ], eax
        add      edi, OFFSET g_dispatchSave725
        mov      ebp, 4
    L_d310:
        mov      cx, word ptr [edi + 2]
        mov      dx, word ptr [edi]
        push     0
        push     ecx
        push     edx
        call     AdvanceTriStripRing
        add      esp, 0xc
        call     ProjectVertex
        mov      ax, word ptr [g_vtxScreenX]
        mov      cx, word ptr [g_vtxScreenY]
        mov      word ptr [esi - 2], ax
        mov      word ptr [esi], cx
        dec      word ptr [esi]
        add      edi, 4
        add      esi, 4
        dec      ebp
        jne      L_d310
        mov      eax, dword ptr [g_triStripRingB]
        test     eax, eax
        jle      L_d48f
        mov      eax, dword ptr [g_vtxOut2_z]
        test     eax, eax
        jle      L_d48f
        mov      eax, dword ptr [g_vtxOut_z]
        test     eax, eax
        jle      L_d48f
        mov      eax, dword ptr [g_tickW1]
        cmp      eax, 0x10
        jl       L_d385
        cdq
        and      edx, 7
        add      eax, edx
        sar      eax, 3
        dec      eax
        jmp      L_d387
    L_d385:
        xor      eax, eax
    L_d387:
        movsx    edx, ax
        mov      eax, dword ptr [g_sunbeamSpriteVar]
        mov      ecx, 1
        imul     eax, edx
        sar      eax, 8
        mov      word ptr [esp + 0x32], cx
        mov      byte ptr [esp + 0x30], cl
        mov      byte ptr [esp + 0x2c], cl
        mov      ebp, dword ptr [esp + 0x16]
        mov      ecx, eax
        mov      si, word ptr [esp + 0x10]
        shl      ecx, 5
        mov      di, word ptr [esp + 0x12]
        or       ecx, eax
        shl      ecx, 5
        or       ecx, eax
        mov      byte ptr [esp + 0x31], bl
        mov      byte ptr [esp + 0x2d], bl
        mov      bx, word ptr [esp + 0x14]
        lea      eax, [esp + 0x20]
        lea      edx, [ebp + 4]
        push     eax
        mov      word ptr [esp + 0x3e], 0x2f
        mov      word ptr [esp + 0x38], cx
        mov      word ptr [esp + 0x24], si
        mov      word ptr [esp + 0x26], di
        mov      word ptr [esp + 0x2c], bx
        mov      word ptr [esp + 0x2e], dx
        call     Helper_DrawCursor
        mov      edx, dword ptr [esp + 0x1e]
        mov      cx, word ptr [esp + 0x1c]
        mov      ax, word ptr [esp + 0x20]
        add      edx, -4
        add      esp, 4
        mov      word ptr [esp + 0x22], dx
        mov      word ptr [esp + 0x20], cx
        mov      cx, word ptr [esp + 0x1e]
        lea      edx, [esp + 0x20]
        mov      word ptr [esp + 0x28], ax
        push     edx
        mov      word ptr [esp + 0x2e], cx
        call     Helper_DrawCursor
        mov      eax, dword ptr [esp + 0x1c]
        mov      cx, word ptr [esp + 0x1e]
        add      esp, 4
        lea      edx, [esp + 0x20]
        add      eax, 4
        mov      word ptr [esp + 0x20], si
        push     edx
        mov      word ptr [esp + 0x26], di
        mov      word ptr [esp + 0x2c], ax
        mov      word ptr [esp + 0x2e], cx
        call     Helper_DrawCursor
        mov      eax, dword ptr [esp + 0x20]
        mov      cx, word ptr [esp + 0x22]
        add      esp, 4
        lea      edx, [esp + 0x20]
        add      eax, -4
        mov      word ptr [esp + 0x20], bx
        push     edx
        mov      word ptr [esp + 0x26], bp
        mov      word ptr [esp + 0x2c], ax
        mov      word ptr [esp + 0x2e], cx
        call     Helper_DrawCursor
        add      esp, 4
    L_d48f:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x2c
        ret
    }
}
#endif
