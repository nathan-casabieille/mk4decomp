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
extern unsigned int g_dispatchSave531;
extern u32 g_inLoopStep;
extern unsigned int g_dispatchSave1626[];
extern s16 g_vtxIn2_x;
extern unsigned int g_triStripX0;
extern s16 g_vtxIn1_y;
extern s16 g_vtxIn1_z;
extern unsigned int g_triStripX1;
extern s16 g_vtxIn2_y;
extern s16 g_vtxIn2_z;
extern unsigned int g_triStripX2;
extern unsigned int g_triStripRingB;
extern s32 g_vtxOut2_z;
extern s32 g_vtxOut_z;
extern s32 g_vtxTransX;
extern s32 g_vtxTransY;
extern s32 g_vtxTransZ;
extern s32 g_vtxValid;
extern unsigned int g_triStripRingA;
extern s16 g_vtxScreenP2X;
extern s16 g_vtxScreenX;
extern unsigned int g_dispatchSave1501;
extern unsigned int g_dispatchSave1502;
extern unsigned int g_dispatchSave1503;
extern unsigned int g_dispatchSave1576;
#endif
#ifndef NON_MATCHING
extern void Helper_DrawCursor(void);
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
#define g_dispatchSave1576 (*(unsigned int *)MK4_VA(unsigned int, 0xab4e60u))
#define g_dispatchSave1626 ((unsigned int *)MK4_VA(unsigned int, 0x7af958u))
#define g_dispatchSave531 (*(unsigned int *)MK4_VA(unsigned int, 0x4f6238u))
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
#define g_triStripRingA (*(unsigned int *)MK4_VA(unsigned int, 0x7af9b4u))
#define g_triStripRingB (*(unsigned int *)MK4_VA(unsigned int, 0x7af984u))
#define g_triStripX0 (*(short *)MK4_VA(short, 0x7af95cu))
#define g_triStripX1 (*(short *)MK4_VA(short, 0x7af962u))
#define g_triStripX2 (*(short *)MK4_VA(short, 0x7af968u))
#define g_vtxIn1_y (*(short *)MK4_VA(short, 0x7af95eu))
#define g_vtxIn1_z (*(short *)MK4_VA(short, 0x7af960u))
#define g_vtxIn2_x (*(short *)MK4_VA(short, 0x7af95au))
#define g_vtxIn2_y (*(short *)MK4_VA(short, 0x7af964u))
#define g_vtxIn2_z (*(short *)MK4_VA(short, 0x7af966u))
#define g_vtxOut2_z (*(int *)MK4_VA(int, 0x7af988u))
#define g_vtxOut_z (*(int *)MK4_VA(int, 0x7af98cu))
#define g_vtxScreenP2X (*(unsigned int *)MK4_VA(unsigned int, 0x7af9b8u))
#define g_vtxScreenX (*(unsigned int *)MK4_VA(unsigned int, 0x7af9bcu))
#define g_vtxTransX (*(int *)MK4_VA(int, 0x7af9a4u))
#define g_vtxTransY (*(int *)MK4_VA(int, 0x7af9a8u))
#define g_vtxTransZ (*(int *)MK4_VA(int, 0x7af9acu))
#define g_vtxValid (*(int *)MK4_VA(int, 0x7af9b0u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif

extern void ProjectTwoVertices(void);

#ifdef NON_MATCHING
#include "portable/mem_model.h"

extern void ProjectTwoVertices(void);
extern void Helper_DrawCursor(void *entry);

/* Portable twin, written from the disassembly. Walks the billboard chain
 * hanging off the node's +0x2c and emits one queue entry per link.
 *
 * The entry is built ON THE STACK and handed to Helper_DrawCursor, which
 * COPIES its seven dwords into the queue and never keeps the pointer - so a
 * plain C local carries it and no arena scratch is needed. Fields +0xe/+0xf
 * and +0x16..+0x19 are never written, exactly as in the original, where the
 * queue receives whatever the frame left on the stack; they are zeroed here
 * instead, since two co-executing runs cannot share stack garbage.
 *
 * The flags word starts at 0x60 and collects three things: the low nibble is
 * XOR'd with the texture record's nibble (an xor against the CURRENT low
 * byte, transcribed as-is), bits 7..8 come from the two-bit table at
 * 0x004f6238 indexed by the link's own two bits, and bit 10 is the winding
 * from the projection.
 *
 * The billboard centre is the CHAIN node's +4/+8 scaled down by 128 and added
 * to the link's four s16 half-extents - and the staged nine words repeat the
 * pair: x appears at 0x7af95a and 0x7af95c, y at 0x7af95e and 0x7af960. */
void BillboardChainRender(void)
{
    unsigned int cur, blk, ent, base, src, idx16, tbl, u, w1;
    unsigned short rec[14];
    short cx0, ax0, dx0, di0;

    if (g_inLoopStep != 0)
        return;

    cur = MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x2c);
    g_vtxTransX = (int)g_dispatchSave1501 >> 16;
    g_vtxTransY = (int)g_dispatchSave1502 >> 16;
    g_vtxTransZ = (int)g_dispatchSave1503 >> 7;
    g_currentNodeIdx = cur;

    w1 = g_dispatchSave1576;
    if ((int)w1 < 0x10)
        u = 0;
    else
        u = (unsigned int)(((int)(w1 + ((w1 >> 31) & 7u)) >> 3) - 1);

    rec[0xd] = 0x60;                                   /* +0x1a: flags       */
    rec[0x9] = 0x40;                                   /* +0x12: sort key    */
    rec[0xa] = (unsigned short)((((u << 5) | u) << 5) | u);   /* +0x14 colour */
    rec[0x7] = 0; rec[0xb] = 0; rec[0xc] = 0;          /* never written by the
                                                          original - stack
                                                          garbage there      */

    while (cur != 0) {
        blk = MK4_NODE_AT(unsigned int, cur, 0xc);
        g_walkCallback = blk;
        if (blk != 0) {
            ent = MK4_NODE_AT(unsigned int, blk, 4);   /* a VA */
            g_xformEntityIdx = ent;
            idx16 = MK4_NODE_AT(unsigned int, blk, 0x18) << 4;
            base = *(unsigned int *)MK4_PTR(ent + 4);
            if (base != 0) {
                unsigned int a, c;

                src = idx16 + base + 0xc;
                tbl = *(unsigned int *)MK4_PTR(base + 4);

                a = *(unsigned char *)MK4_PTR(tbl
                        + (unsigned int)*(unsigned char *)MK4_PTR(src + 2) * 4u
                        + base + 0xa);
                rec[0xd] = (unsigned short)(rec[0xd]
                            ^ ((a ^ (rec[0xd] & 0xffu)) & 0xfu));

                c = *(unsigned char *)MK4_PTR(src + 1) & 3u;
                c = *(unsigned char *)MK4_VA(unsigned char, 0x004f6238u + c) & 3u;
                rec[0xd] = (unsigned short)((rec[0xd] & 0xfe7fu) | (c << 7));

                cx0 = (short)(*(short *)MK4_PTR(src + 8)
                              + (short)((int)MK4_NODE_AT(int, cur, 4) >> 7));
                ax0 = (short)(*(short *)MK4_PTR(src + 0xa)
                              + (short)((int)MK4_NODE_AT(int, cur, 8) >> 7));
                dx0 = (short)(*(short *)MK4_PTR(src + 4) + cx0);
                di0 = (short)(*(short *)MK4_PTR(src + 6) + ax0);

                *MK4_VA(short, 0x7af958u) = cx0;
                *MK4_VA(short, 0x7af95eu) = ax0;
                *MK4_VA(short, 0x7af964u) = 0;
                *MK4_VA(short, 0x7af95au) = dx0;
                *MK4_VA(short, 0x7af960u) = ax0;
                *MK4_VA(short, 0x7af966u) = 0;
                *MK4_VA(short, 0x7af95cu) = dx0;
                *MK4_VA(short, 0x7af962u) = di0;
                *MK4_VA(short, 0x7af968u) = 0;

                ProjectTwoVertices();

                ((unsigned char *)rec)[0xc] = *(unsigned char *)MK4_PTR(src + 0xc);
                ((unsigned char *)rec)[0xd] = *(unsigned char *)MK4_PTR(src + 0xd);
                ((unsigned char *)rec)[0x10] = (unsigned char)
                    (*(unsigned char *)MK4_PTR(src + 0xe)
                     + *(unsigned char *)MK4_PTR(src + 0xc));
                ((unsigned char *)rec)[0x11] = (unsigned char)
                    (*(unsigned char *)MK4_PTR(src + 0xf)
                     + *(unsigned char *)MK4_PTR(src + 0xd));

                ((unsigned int *)rec)[0] = *MK4_VA(unsigned int, 0x7af9b4u);
                ((unsigned int *)rec)[1] = *MK4_VA(unsigned int, 0x7af9b8u);
                ((unsigned int *)rec)[2] = *MK4_VA(unsigned int, 0x7af9bcu);
                rec[0xd] = (unsigned short)((rec[0xd] & 0xfbffu)
                            | ((*MK4_VA(unsigned char, 0x7af9b0u) & 1u) << 10));

                if ((int)*MK4_VA(int, 0x7af984u) > 0
                    && (int)*MK4_VA(int, 0x7af988u) > 0
                    && (int)*MK4_VA(int, 0x7af98cu) > 0)
                    Helper_DrawCursor(rec);

                cur = g_currentNodeIdx;
            }
        }
        cur = *MK4_NODE(unsigned int, cur);
        g_currentNodeIdx = cur;
    }
}
#else
__declspec(naked) void BillboardChainRender(void)
{
    __asm {
        mov      eax, dword ptr [g_inLoopStep]
        sub      esp, 0x20
        push     ebx
        xor      ebx, ebx
        cmp      eax, ebx
        jne      L_b24a
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_dispatchSave1501]
        mov      edx, dword ptr [g_dispatchSave1502]
        push     edi
        mov      edi, dword ptr [eax*4 + 0x2c]
        mov      eax, dword ptr [g_dispatchSave1503]
        sar      eax, 7
        mov      dword ptr [g_vtxTransZ], eax
        mov      eax, dword ptr [g_dispatchSave1576]
        sar      ecx, 0x10
        sar      edx, 0x10
        cmp      eax, 0x10
        push     esi
        mov      dword ptr [g_currentNodeIdx], edi
        mov      dword ptr [g_vtxTransX], ecx
        mov      dword ptr [g_vtxTransY], edx
        jl       L_b098
        cdq
        and      edx, 7
        add      eax, edx
        sar      eax, 3
        dec      eax
        jmp      L_b09a
    L_b098:
        xor      eax, eax
    L_b09a:
        mov      ecx, eax
        mov      word ptr [esp + 0x26], 0x60
        shl      ecx, 5
        or       ecx, eax
        mov      word ptr [esp + 0x1e], 0x40
        shl      ecx, 5
        or       ecx, eax
        mov      word ptr [esp + 0x20], cx
    L_b0b9:
        mov      eax, dword ptr [edi*4 + 0xc]
        cmp      eax, ebx
        mov      dword ptr [g_walkCallback], eax
        je       L_b233
        mov      edx, dword ptr [eax*4 + 4]
        mov      dword ptr [g_xformEntityIdx], edx
        mov      ecx, dword ptr [eax*4 + 0x18]
        mov      eax, dword ptr [edx + 4]
        cmp      eax, ebx
        je       L_b233
        shl      ecx, 4
        xor      edx, edx
        mov      dl, byte ptr [ecx + eax + 0xe]
        lea      esi, [ecx + eax + 0xc]
        mov      ecx, dword ptr [eax + 4]
        lea      edx, [ecx + edx*4]
        mov      cl, byte ptr [esp + 0x26]
        mov      al, byte ptr [edx + eax + 0xa]
        xor      al, cl
        and      eax, 0xf
        xor      word ptr [esp + 0x26], ax
        mov      cl, byte ptr [esi + 1]
        and      ecx, 3
        mov      dl, byte ptr [ecx + g_dispatchSave531]
        mov      ecx, dword ptr [esp + 0x26]
        and      dl, 3
        and      ecx, 0xfe7f
        movsx    ax, dl
        shl      eax, 7
        or       eax, ecx
        mov      word ptr [esp + 0x26], ax
        mov      eax, dword ptr [edi*4 + 4]
        mov      cx, word ptr [esi + 8]
        mov      edx, dword ptr [edi*4 + 8]
        mov      di, word ptr [esi + 6]
        sar      eax, 7
        add      cx, ax
        mov      ax, word ptr [esi + 0xa]
        sar      edx, 7
        add      ax, dx
        mov      dx, word ptr [esi + 4]
        add      dx, cx
        add      di, ax
        mov      word ptr [g_dispatchSave1626], cx
        mov      word ptr [g_vtxIn1_y], ax
        mov      word ptr [g_vtxIn2_y], bx
        mov      word ptr [g_vtxIn2_x], dx
        mov      word ptr [g_vtxIn1_z], ax
        mov      word ptr [g_vtxIn2_z], bx
        mov      word ptr [g_triStripX0], dx
        mov      word ptr [g_triStripX1], di
        mov      word ptr [g_triStripX2], bx
        call     ProjectTwoVertices
        mov      dl, byte ptr [esi + 0xc]
        mov      byte ptr [esp + 0x18], dl
        mov      al, byte ptr [esi + 0xd]
        mov      byte ptr [esp + 0x19], al
        mov      cl, byte ptr [esi + 0xe]
        add      cl, byte ptr [esi + 0xc]
        mov      byte ptr [esp + 0x1c], cl
        mov      dl, byte ptr [esi + 0xf]
        mov      al, byte ptr [esi + 0xd]
        mov      ecx, dword ptr [g_vtxScreenP2X]
        add      dl, al
        mov      eax, dword ptr [g_triStripRingA]
        mov      dword ptr [esp + 0x10], ecx
        mov      cl, byte ptr [g_vtxValid]
        mov      dword ptr [esp + 0xc], eax
        mov      eax, dword ptr [esp + 0x26]
        and      ecx, 1
        and      eax, 0xfbff
        shl      ecx, 0xa
        or       eax, ecx
        mov      byte ptr [esp + 0x1d], dl
        mov      edx, dword ptr [g_vtxScreenX]
        mov      word ptr [esp + 0x26], ax
        mov      eax, dword ptr [g_triStripRingB]
        mov      dword ptr [esp + 0x14], edx
        cmp      eax, ebx
        jle      L_b22d
        cmp      dword ptr [g_vtxOut2_z], ebx
        jle      L_b22d
        cmp      dword ptr [g_vtxOut_z], ebx
        jle      L_b22d
        lea      edx, [esp + 0xc]
        push     edx
        call     Helper_DrawCursor
        add      esp, 4
    L_b22d:
        mov      edi, dword ptr [g_currentNodeIdx]
    L_b233:
        mov      edi, dword ptr [edi*4]
        cmp      edi, ebx
        mov      dword ptr [g_currentNodeIdx], edi
        jne      L_b0b9
        pop      esi
        pop      edi
    L_b24a:
        pop      ebx
        add      esp, 0x20
        ret
    }
}
#endif
