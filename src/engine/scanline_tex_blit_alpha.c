/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

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
extern unsigned int g_armedReloadA;
extern unsigned int g_armedReloadB;
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

extern unsigned int g_viewportW;
extern unsigned int g_viewportH;
extern unsigned int g_texturedTriVar;
extern unsigned int g_dispatchSave1707;
extern unsigned int g_dispatchSave1708;
extern unsigned int g_dispatchSave1346;
extern unsigned int g_dispatchSave1357;
extern unsigned int g_dispatchSave1358;
extern unsigned int g_dispatchSave1371;
extern unsigned int g_dispatchSave1373;
extern unsigned int g_dispatchSave1374;
extern unsigned int g_dispatchSave1375;
extern unsigned int g_dispatchSave1377;
extern unsigned int g_dispatchSave1378;
extern unsigned int g_dispatchSave1380;
extern unsigned int g_dispatchSave1381;
extern unsigned int g_dispatchSave1383;
extern unsigned int g_dispatchSave1387;
extern unsigned int g_dispatchSave1400;
extern unsigned int g_dispatchSave1403;
extern unsigned int g_viewportX;
extern unsigned int g_viewportY;
extern unsigned int g_dispatchSave1404;

#ifdef NON_MATCHING
/*
 * Portable C twin (path A). Faithful register-level transcription of the naked
 * branch below; verified by seeded co-exec (tools/decomp/verify_scanline.py),
 * not byte-match. Same clip/setup/16.16-stepping as ScanlineTexBlit; the inner
 * loop is a 50/50 alpha blend of src over dst with two modes (g_texturedTriVar):
 * mode!=0 = 565 (masks 0x7bef/0xf7de), mode==0 = 555 (masks 0x3def/0x7bde).
 * Texel 0 = transparent. V/page and column bytes derived from 1374/1387
 * (layout-independent; see ScanlineTexBlit).
 */
void ScanlineTexBlitAlpha(void)
{
    unsigned int eax, ebx, ecx, edx, esi, edi;

    if (g_viewportX == 0) return;
    edi = g_dispatchSave1378;                           /* x0 */
    if ((int)edi >= (int)g_viewportW) return;
    eax = g_dispatchSave1381;                           /* y0 */
    if ((int)eax >= (int)g_viewportH) return;
    ecx = g_dispatchSave1380;                           /* x1 */
    if ((int)ecx < 0) return;
    esi = g_dispatchSave1383;                           /* y1 */
    if ((int)esi < 0) return;
    ecx -= edi;                                         /* w */
    esi -= eax;                                         /* h */
    g_dispatchSave1708 = ecx;
    g_dispatchSave1707 = esi;
    if ((int)ecx < 1) return;
    if ((int)esi < 1) return;

    eax = g_dispatchSave1374 << 16;  g_dispatchSave1374 = eax;
    edx = g_dispatchSave1371 << 16;
    eax = g_dispatchSave1373 << 16;  g_dispatchSave1373 = eax;
    eax = eax - edx;
    g_dispatchSave1371 = edx;
    ebx = g_dispatchSave1377;
    eax = (unsigned int)((int)eax / (int)ecx);          /* gradX */
    edx = g_dispatchSave1374;
    ebx <<= 16;
    g_dispatchSave1377 = ebx;
    ebx = eax;
    eax = g_dispatchSave1377;
    eax = eax - edx;
    g_dispatchSave1357 = ebx;                           /* gradX */
    eax = (unsigned int)((int)eax / (int)esi);          /* gradY */
    g_dispatchSave1358 = eax;                           /* gradY */

    if ((int)edi < 0) {                                 /* left clip */
        ebx = (unsigned int)((int)ebx * (int)edi);
        edx = g_dispatchSave1371;
        ecx = ecx + edi;
        edx = edx - ebx;
        edi = 0;
        g_dispatchSave1371 = edx;
        g_dispatchSave1708 = ecx;
        g_dispatchSave1378 = edi;
    }
    ecx = g_dispatchSave1381;
    if ((int)ecx < 0) {                                 /* top clip */
        eax = (unsigned int)((int)eax * (int)ecx);
        edx = g_dispatchSave1374;
        g_dispatchSave1381 = 0;
        edx = edx - eax;
        esi = esi + ecx;
        ecx = g_dispatchSave1381;
        g_dispatchSave1374 = edx;
        g_dispatchSave1707 = esi;
    }
    eax = g_viewportW;
    edx = g_dispatchSave1380;
    if (!((int)edx < (int)eax)) {                       /* right clip */
        eax = eax - edi;
        g_dispatchSave1708 = eax;
    }
    eax = g_viewportH;
    edx = g_dispatchSave1383;
    if (!((int)edx < (int)eax)) {                       /* bottom clip */
        eax = eax - ecx;
        esi = eax;
        g_dispatchSave1707 = esi;
    }
    edx = g_viewportY;
    eax = g_viewportX;
    edx = (unsigned int)((int)edx * (int)ecx);
    eax = eax + edx;
    eax = eax + edi * 2;
    g_dispatchSave1346 = eax;
    eax = g_dispatchSave1403 & 0xf;
    eax <<= 16;
    g_dispatchSave1403 = eax;
    if ((int)esi <= 0) return;

    eax = g_dispatchSave1403;
    for (;;) {
        ecx = g_dispatchSave1371;
        edx = ((g_dispatchSave1374 >> 16) & 0xff) << 8;  /* texpage/row byte */
        g_dispatchSave1387 = ecx;
        edx = edx + eax;
        eax = g_dispatchSave1400;
        ecx = eax + edx * 2;
        g_dispatchSave1404 = ecx;
        eax = g_dispatchSave1387 << 16;                  /* frac accumulator (=0) */
        edx = g_dispatchSave1404 >> 1;
        ecx = g_dispatchSave1387 >> 16;
        edx = (edx & 0xffffff00u) | (ecx & 0xff);
        edi = g_dispatchSave1346;
        edi = edi + g_dispatchSave1708;
        edi = edi + g_dispatchSave1708;                  /* row end */
        esi = g_dispatchSave1708;
        esi = (unsigned int)(-(int)esi);                 /* esi = -w */
        ecx = g_dispatchSave1357;
        ecx = (ecx << 16) | (ecx >> 16);                 /* rol 16 */
        ecx = ecx & 0xffff00ffu;
        if (g_texturedTriVar != 0) {                     /* mode != 0: 565 */
            do {
                unsigned int texel = *(unsigned short *)(unsigned long)(edx * 2);
                unsigned int dst = *(unsigned short *)(unsigned long)(edi + esi * 2);
                eax = (eax & 0xffff0000u) | texel;
                if (texel != 0) {
                    unsigned int px = (((texel >> 1) & 0x7bef) + ((dst & 0xf7de) >> 1)) & 0xffff;
                    *(unsigned short *)(unsigned long)(edi + esi * 2) = (unsigned short)px;
                }
                {
                    unsigned int sum = eax + ecx;
                    unsigned int carry = (sum < eax) ? 1u : 0u;
                    unsigned int dl = (edx & 0xff) + (ecx & 0xff) + carry;
                    eax = sum;
                    edx = (edx & 0xffffff00u) | (dl & 0xff);
                }
                esi = esi + 1;
            } while ((int)esi < 0);
        } else {                                         /* mode == 0: 555 */
            do {
                unsigned int texel = *(unsigned short *)(unsigned long)(edx * 2);
                unsigned int dst = *(unsigned short *)(unsigned long)(edi + esi * 2);
                eax = (eax & 0xffff0000u) | texel;
                if (texel != 0) {
                    unsigned int px = (((texel >> 1) & 0x3def) + ((dst & 0x7bde) >> 1)) & 0xffff;
                    *(unsigned short *)(unsigned long)(edi + esi * 2) = (unsigned short)px;
                }
                {
                    unsigned int sum = eax + ecx;
                    unsigned int carry = (sum < eax) ? 1u : 0u;
                    unsigned int dl = (edx & 0xff) + (ecx & 0xff) + carry;
                    eax = sum;
                    edx = (edx & 0xffffff00u) | (dl & 0xff);
                }
                esi = esi + 1;
            } while ((int)esi < 0);
        }
        edx = g_dispatchSave1358;
        esi = g_dispatchSave1374;
        eax = g_dispatchSave1707;
        ecx = g_viewportY;
        esi = esi + edx;                                 /* 1374 += gradY */
        edx = g_dispatchSave1346;
        eax = eax - 1;                                   /* rows-- */
        edx = edx + ecx;                                 /* dest += pitch */
        g_dispatchSave1707 = eax;
        g_dispatchSave1374 = esi;
        g_dispatchSave1346 = edx;
        if (!((int)eax > 0)) break;
        eax = g_dispatchSave1403;
    }
}
#else
__declspec(naked) void ScanlineTexBlitAlpha(void)
{
    __asm {
        mov      eax, dword ptr [g_viewportX]
        push     ebx
        push     esi
        push     edi
        test     eax, eax
        je       L_0e02
        mov      edi, dword ptr [g_dispatchSave1378]
        mov      eax, dword ptr [g_viewportW]
        cmp      edi, eax
        jge      L_0e02
        mov      eax, dword ptr [g_dispatchSave1381]
        mov      ecx, dword ptr [g_viewportH]
        cmp      eax, ecx
        jge      L_0e02
        mov      ecx, dword ptr [g_dispatchSave1380]
        test     ecx, ecx
        jl       L_0e02
        mov      esi, dword ptr [g_dispatchSave1383]
        test     esi, esi
        jl       L_0e02
        sub      ecx, edi
        sub      esi, eax
        cmp      ecx, 1
        mov      dword ptr [g_dispatchSave1708], ecx
        mov      dword ptr [g_dispatchSave1707], esi
        jl       L_0e02
        cmp      esi, 1
        jl       L_0e02
        mov      eax, dword ptr [g_dispatchSave1374]
        mov      edx, dword ptr [g_dispatchSave1371]
        shl      eax, 0x10
        mov      dword ptr [g_dispatchSave1374], eax
        mov      eax, dword ptr [g_dispatchSave1373]
        shl      eax, 0x10
        shl      edx, 0x10
        mov      dword ptr [g_dispatchSave1373], eax
        sub      eax, edx
        mov      dword ptr [g_dispatchSave1371], edx
        mov      ebx, dword ptr [g_dispatchSave1377]
        cdq
        idiv     ecx
        mov      edx, dword ptr [g_dispatchSave1374]
        shl      ebx, 0x10
        mov      dword ptr [g_dispatchSave1377], ebx
        mov      ebx, eax
        mov      eax, dword ptr [g_dispatchSave1377]
        sub      eax, edx
        mov      dword ptr [g_dispatchSave1357], ebx
        cdq
        idiv     esi
        test     edi, edi
        mov      dword ptr [g_dispatchSave1358], eax
        jge      L_0c63
        imul     ebx, edi
        mov      edx, dword ptr [g_dispatchSave1371]
        add      ecx, edi
        sub      edx, ebx
        xor      edi, edi
        mov      dword ptr [g_dispatchSave1371], edx
        mov      dword ptr [g_dispatchSave1708], ecx
        mov      dword ptr [g_dispatchSave1378], edi
    L_0c63:
        mov      ecx, dword ptr [g_dispatchSave1381]
        test     ecx, ecx
        jge      L_0c96
        imul     eax, ecx
        mov      edx, dword ptr [g_dispatchSave1374]
        mov      dword ptr [g_dispatchSave1381], 0
        sub      edx, eax
        add      esi, ecx
        mov      ecx, dword ptr [g_dispatchSave1381]
        mov      dword ptr [g_dispatchSave1374], edx
        mov      dword ptr [g_dispatchSave1707], esi
    L_0c96:
        mov      eax, dword ptr [g_viewportW]
        mov      edx, dword ptr [g_dispatchSave1380]
        cmp      edx, eax
        jl       L_0cac
        sub      eax, edi
        mov      dword ptr [g_dispatchSave1708], eax
    L_0cac:
        mov      eax, dword ptr [g_viewportH]
        mov      edx, dword ptr [g_dispatchSave1383]
        cmp      edx, eax
        jl       L_0cc5
        sub      eax, ecx
        mov      esi, eax
        mov      dword ptr [g_dispatchSave1707], esi
    L_0cc5:
        mov      edx, dword ptr [g_viewportY]
        mov      eax, dword ptr [g_viewportX]
        imul     edx, ecx
        add      eax, edx
        lea      eax, [eax + edi*2]
        mov      dword ptr [g_dispatchSave1346], eax
        mov      eax, dword ptr [g_dispatchSave1403]
        and      eax, 0xf
        shl      eax, 0x10
        test     esi, esi
        mov      dword ptr [g_dispatchSave1403], eax
        jle      L_0e02
        jmp      L_0cfc
    L_0cf7:
        mov      eax, dword ptr [g_dispatchSave1403]
    L_0cfc:
        mov      ecx, dword ptr [g_dispatchSave1371]
        xor      edx, edx
        mov      dh, byte ptr [g_dispatchSave1375]
        mov      dword ptr [g_dispatchSave1387], ecx
        add      edx, eax
        mov      eax, dword ptr [g_dispatchSave1400]
        lea      ecx, [eax + edx*2]
        mov      dword ptr [g_dispatchSave1404], ecx
        mov      eax, dword ptr [g_dispatchSave1387]
        shl      eax, 0x10
        mov      edx, dword ptr [g_dispatchSave1404]
        shr      edx, 1
        mov      ecx, dword ptr [g_dispatchSave1387]
        shr      ecx, 0x10
        mov      dl, cl
        mov      edi, dword ptr [g_dispatchSave1346]
        add      edi, dword ptr [g_dispatchSave1708]
        add      edi, dword ptr [g_dispatchSave1708]
        mov      esi, dword ptr [g_dispatchSave1708]
        neg      esi
        mov      ecx, dword ptr [g_dispatchSave1357]
        rol      ecx, 0x10
        mov      ch, 0
        cmp      dword ptr [g_texturedTriVar], 0
        jne      L_0d99
    L_0d69:
        mov      ax, word ptr [edx*2]
        mov      bx, word ptr [edi + esi*2]
        test     ax, ax
        je       L_0d90
        shr      ax, 1
        and      bx, 0x7bde
        shr      bx, 1
        and      ax, 0x3def
        add      ax, bx
        mov      word ptr [edi + esi*2], ax
    L_0d90:
        add      eax, ecx
        adc      dl, cl
        inc      esi
        jl       L_0d69
        jmp      L_0dc7
    L_0d99:
        mov      ax, word ptr [edx*2]
        mov      bx, word ptr [edi + esi*2]
        test     ax, ax
        je       L_0dc0
        shr      ax, 1
        and      bx, 0xf7de
        shr      bx, 1
        and      ax, 0x7bef
        add      ax, bx
        mov      word ptr [edi + esi*2], ax
    L_0dc0:
        add      eax, ecx
        adc      dl, cl
        inc      esi
        jl       L_0d99
    L_0dc7:
        mov      edx, dword ptr [g_dispatchSave1358]
        mov      esi, dword ptr [g_dispatchSave1374]
        mov      eax, dword ptr [g_dispatchSave1707]
        mov      ecx, dword ptr [g_viewportY]
        add      esi, edx
        mov      edx, dword ptr [g_dispatchSave1346]
        dec      eax
        add      edx, ecx
        test     eax, eax
        mov      dword ptr [g_dispatchSave1707], eax
        mov      dword ptr [g_dispatchSave1374], esi
        mov      dword ptr [g_dispatchSave1346], edx
        jg       L_0cf7
    L_0e02:
        pop      edi
        pop      esi
        pop      ebx
        ret
    }
}
#endif
