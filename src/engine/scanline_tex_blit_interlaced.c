/**
 * Auto-split from misc_matchesQQ.c
 */
#include "portable/ghidra_types.h"
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
extern unsigned int g_dispatchSave1707;
extern unsigned int g_dispatchSave1708;
extern unsigned int g_dispatchSave1334;
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
extern unsigned int g_dispatchSave1395;
extern unsigned int g_dispatchSave1396;
extern unsigned int g_dispatchSave1400;
extern unsigned int g_dispatchSave1402;
extern unsigned int g_dispatchSave1403;
extern unsigned int g_viewportX;
extern unsigned int g_viewportY;
extern unsigned int g_dispatchSave1404;

#ifdef NON_MATCHING
/*
 * Portable C twin (path A). Faithful register-level transcription of the naked
 * branch below; verified by seeded co-exec (tools/decomp/verify_scanline.py),
 * not byte-match. Interlaced (checkerboard) variant of ScanlineTexBlit: per
 * scanline it writes every OTHER pixel (inner step esi+=2, texcoord step
 * gradX*2), choosing the starting parity from (rowIndex & 1) XOR
 * ((destAddr >> 1) & 1). g_dispatchSave1381 is the running row index. Texel 0 =
 * transparent. V/page and column bytes derived from 1374/1334 (layout-
 * independent; see ScanlineTexBlit).
 */
void ScanlineTexBlitInterlaced(void)
{
    unsigned int eax, ebx, ecx, edx, esi, edi;

    if (g_viewportX == 0) return;
    eax = g_dispatchSave1378;                           /* x0 */
    if ((int)eax >= (int)g_viewportW) return;
    ebx = g_dispatchSave1381;                           /* y0 */
    if ((int)ebx >= (int)g_viewportH) return;
    edi = g_dispatchSave1380;                           /* x1 */
    if ((int)edi < 0) return;
    ecx = g_dispatchSave1383;                           /* y1 */
    if ((int)ecx < 0) return;
    edi -= eax;                                         /* w */
    ecx -= ebx;                                         /* h */
    g_dispatchSave1708 = edi;
    g_dispatchSave1707 = ecx;
    if ((int)edi < 1) return;
    if ((int)ecx < 1) return;

    eax = g_dispatchSave1374 << 16;  g_dispatchSave1374 = eax;   /* u0fx */
    esi = g_dispatchSave1371 << 16;                             /* Pfx */
    edx = g_dispatchSave1377;                                   /* Q */
    eax = g_dispatchSave1373 << 16;  g_dispatchSave1373 = eax;   /* U1fx */
    eax = eax - esi;
    edx <<= 16;  g_dispatchSave1377 = edx;                       /* Qfx */
    g_dispatchSave1371 = esi;                                   /* Pfx */
    eax = (unsigned int)((int)eax / (int)edi);                  /* gradX (/w) */
    edx = g_dispatchSave1374;                                   /* u0fx */
    g_dispatchSave1357 = eax;                                   /* gradX */
    eax = g_dispatchSave1377;                                   /* Qfx */
    eax = eax - edx;
    eax = (unsigned int)((int)eax / (int)ecx);                  /* gradY (/h) */
    g_dispatchSave1358 = eax;                                   /* gradY */

    eax = g_dispatchSave1378;                                   /* x0 */
    if ((int)eax < 0) {                                         /* left clip */
        edx = g_dispatchSave1357;
        edi = edi + eax;
        edx = (unsigned int)((int)edx * (int)eax);
        esi = esi - edx;
        eax = 0;
        g_dispatchSave1371 = esi;
        g_dispatchSave1708 = edi;
        g_dispatchSave1378 = eax;
    }
    if ((int)ebx < 0) {                                         /* top clip */
        eax = g_dispatchSave1358;
        edx = g_dispatchSave1374;
        eax = (unsigned int)((int)eax * (int)ebx);
        edx = edx - eax;
        eax = g_dispatchSave1378;                              /* x0 (clamped) */
        ecx = ecx + ebx;
        ebx = 0;
        g_dispatchSave1374 = edx;
        g_dispatchSave1707 = ecx;
        g_dispatchSave1381 = ebx;
    }
    ecx = g_viewportW;
    edx = g_dispatchSave1380;
    if (!((int)edx < (int)ecx)) {                              /* right clip */
        ecx = ecx - eax;
        edi = ecx;
        g_dispatchSave1708 = edi;
    }
    ecx = g_viewportH;
    edx = g_dispatchSave1383;
    if (!((int)edx < (int)ecx)) {                              /* bottom clip */
        ecx = ecx - ebx;
        g_dispatchSave1707 = ecx;
    }
    edx = g_viewportY;                                         /* pitch */
    ecx = g_viewportX;                                         /* fb */
    edx = (unsigned int)((int)edx * (int)ebx);                /* pitch*y0 */
    ecx = ecx + edx;
    edx = g_dispatchSave1707;                                  /* h (row counter) */
    ecx = ecx + eax * 2;                                       /* dest top-left */
    eax = g_dispatchSave1403 & 0xf;
    g_dispatchSave1346 = ecx;
    eax <<= 16;                                                /* sub-texel << 16 */
    g_dispatchSave1403 = eax;
    if ((int)edx <= 0) return;

    eax = g_dispatchSave1403;                                  /* first row */
    for (;;) {
        /* L_12c5: interlace parity + per-row texcoord/dest base */
        edx = ((g_dispatchSave1374 >> 16) & 0xff) << 8;        /* texpage/row byte */
        ebx = ebx & 1;                                        /* row index parity */
        g_dispatchSave1387 = esi;                            /* Pfx */
        edx = edx + eax;                                     /* + sub<<16 */
        g_dispatchSave1396 = ecx;                            /* dest */
        g_dispatchSave1334 = esi;                            /* Pfx (start texcoord) */
        edx = g_dispatchSave1400 + edx * 2;                  /* tex row base */
        g_dispatchSave1404 = edx;
        ebx = ebx ^ ((ecx >> 1) & 1);                        /* XOR dest-column parity */
        edx = edi;                                           /* w */
        g_dispatchSave1402 = edx;
        if (ebx != 0) {                                      /* odd parity: start 1 pixel in */
            eax = g_dispatchSave1357;
            edx = edi - 1;                                   /* w - 1 */
            eax = eax + esi;                                 /* Pfx + gradX */
            g_dispatchSave1402 = edx;
            g_dispatchSave1334 = eax;
            eax = ecx + 2;                                   /* dest + 2 */
            g_dispatchSave1396 = eax;
        }
        /* L_1322 */
        eax = g_dispatchSave1357;                            /* gradX */
        ebx = g_dispatchSave1381;                            /* row index */
        eax = eax + eax;                                     /* gradX * 2 */
        ebx = ebx + 1;                                       /* row++ */
        edx = g_dispatchSave1402;                            /* adjusted width */
        g_dispatchSave1395 = eax;                            /* gradX*2 */
        g_dispatchSave1381 = ebx;
        if ((int)edx >= 1) {
            eax = g_dispatchSave1334 << 16;                  /* frac accumulator (=0) */
            edx = g_dispatchSave1404 >> 1;
            ecx = g_dispatchSave1334 >> 16;                  /* integer col */
            edx = (edx & 0xffffff00u) | (ecx & 0xff);        /* dl = cl */
            edi = g_dispatchSave1396;
            edi = edi + g_dispatchSave1402;
            edi = edi + g_dispatchSave1402;                  /* edi += 2*width */
            esi = g_dispatchSave1402;
            esi = (unsigned int)(-(int)esi);                 /* esi = -width */
            ecx = g_dispatchSave1395;                        /* gradX*2 */
            ecx = (ecx << 16) | (ecx >> 16);                 /* rol 16 */
            ecx = ecx & 0xffff00ffu;
            do {
                unsigned int texel = *(unsigned short *)MK4_PTR(edx * 2);
                eax = (eax & 0xffff0000u) | texel;
                if (texel != 0)
                    *(unsigned short *)MK4_PTR(edi + esi * 2) = (unsigned short)texel;
                {
                    unsigned int sum = eax + ecx;
                    unsigned int carry = (sum < eax) ? 1u : 0u;
                    unsigned int dl = (edx & 0xff) + (ecx & 0xff) + carry;
                    eax = sum;
                    edx = (edx & 0xffffff00u) | (dl & 0xff);
                }
                esi = esi + 2;                               /* interlace: every other pixel */
            } while ((int)esi < 0);
            ebx = g_dispatchSave1381;                        /* reload row index */
            edi = g_dispatchSave1708;                        /* reload w */
            esi = g_dispatchSave1371;                        /* reload Pfx */
            ecx = g_dispatchSave1346;                        /* reload dest */
        }
        /* L_13b2: row advance */
        edx = g_dispatchSave1358;                            /* gradY */
        eax = g_dispatchSave1707;                            /* rows */
        g_dispatchSave1374 = g_dispatchSave1374 + edx;       /* 1374 += gradY */
        edx = g_viewportY;
        eax = eax - 1;                                       /* rows-- */
        ecx = ecx + edx;                                     /* dest += pitch */
        g_dispatchSave1707 = eax;
        g_dispatchSave1346 = ecx;
        if (!((int)eax > 0)) break;
        eax = g_dispatchSave1403;
    }
}
#else
__declspec(naked) void ScanlineTexBlitInterlaced(void)
{
    __asm {
        mov      eax, dword ptr [g_viewportX]
        push     ebx
        push     esi
        push     edi
        test     eax, eax
        je       L_13df
        mov      eax, dword ptr [g_dispatchSave1378]
        mov      ecx, dword ptr [g_viewportW]
        cmp      eax, ecx
        jge      L_13df
        mov      ebx, dword ptr [g_dispatchSave1381]
        mov      ecx, dword ptr [g_viewportH]
        cmp      ebx, ecx
        jge      L_13df
        mov      edi, dword ptr [g_dispatchSave1380]
        test     edi, edi
        jl       L_13df
        mov      ecx, dword ptr [g_dispatchSave1383]
        test     ecx, ecx
        jl       L_13df
        sub      edi, eax
        sub      ecx, ebx
        cmp      edi, 1
        mov      dword ptr [g_dispatchSave1708], edi
        mov      dword ptr [g_dispatchSave1707], ecx
        jl       L_13df
        cmp      ecx, 1
        jl       L_13df
        mov      eax, dword ptr [g_dispatchSave1374]
        mov      esi, dword ptr [g_dispatchSave1371]
        mov      edx, dword ptr [g_dispatchSave1377]
        shl      eax, 0x10
        mov      dword ptr [g_dispatchSave1374], eax
        mov      eax, dword ptr [g_dispatchSave1373]
        shl      eax, 0x10
        shl      esi, 0x10
        mov      dword ptr [g_dispatchSave1373], eax
        sub      eax, esi
        shl      edx, 0x10
        mov      dword ptr [g_dispatchSave1377], edx
        mov      dword ptr [g_dispatchSave1371], esi
        cdq
        idiv     edi
        mov      edx, dword ptr [g_dispatchSave1374]
        mov      dword ptr [g_dispatchSave1357], eax
        mov      eax, dword ptr [g_dispatchSave1377]
        sub      eax, edx
        cdq
        idiv     ecx
        mov      dword ptr [g_dispatchSave1358], eax
        mov      eax, dword ptr [g_dispatchSave1378]
        test     eax, eax
        jge      L_1225
        mov      edx, dword ptr [g_dispatchSave1357]
        add      edi, eax
        imul     edx, eax
        sub      esi, edx
        xor      eax, eax
        mov      dword ptr [g_dispatchSave1371], esi
        mov      dword ptr [g_dispatchSave1708], edi
        mov      dword ptr [g_dispatchSave1378], eax
    L_1225:
        test     ebx, ebx
        jge      L_1254
        mov      eax, dword ptr [g_dispatchSave1358]
        mov      edx, dword ptr [g_dispatchSave1374]
        imul     eax, ebx
        sub      edx, eax
        mov      eax, dword ptr [g_dispatchSave1378]
        add      ecx, ebx
        xor      ebx, ebx
        mov      dword ptr [g_dispatchSave1374], edx
        mov      dword ptr [g_dispatchSave1707], ecx
        mov      dword ptr [g_dispatchSave1381], ebx
    L_1254:
        mov      ecx, dword ptr [g_viewportW]
        mov      edx, dword ptr [g_dispatchSave1380]
        cmp      edx, ecx
        jl       L_126e
        sub      ecx, eax
        mov      edi, ecx
        mov      dword ptr [g_dispatchSave1708], edi
    L_126e:
        mov      ecx, dword ptr [g_viewportH]
        mov      edx, dword ptr [g_dispatchSave1383]
        cmp      edx, ecx
        jl       L_1286
        sub      ecx, ebx
        mov      dword ptr [g_dispatchSave1707], ecx
    L_1286:
        mov      edx, dword ptr [g_viewportY]
        mov      ecx, dword ptr [g_viewportX]
        imul     edx, ebx
        add      ecx, edx
        mov      edx, dword ptr [g_dispatchSave1707]
        lea      ecx, [ecx + eax*2]
        mov      eax, dword ptr [g_dispatchSave1403]
        and      eax, 0xf
        mov      dword ptr [g_dispatchSave1346], ecx
        shl      eax, 0x10
        test     edx, edx
        mov      dword ptr [g_dispatchSave1403], eax
        jle      L_13df
        jmp      L_12c5
    L_12c0:
        mov      eax, dword ptr [g_dispatchSave1403]
    L_12c5:
        xor      edx, edx
        and      ebx, 1
        mov      dh, byte ptr [g_dispatchSave1375]
        mov      dword ptr [g_dispatchSave1387], esi
        add      edx, eax
        mov      eax, dword ptr [g_dispatchSave1400]
        mov      dword ptr [g_dispatchSave1396], ecx
        mov      dword ptr [g_dispatchSave1334], esi
        lea      edx, [eax + edx*2]
        mov      eax, ecx
        sar      eax, 1
        mov      dword ptr [g_dispatchSave1404], edx
        and      eax, 1
        mov      edx, edi
        xor      ebx, eax
        mov      dword ptr [g_dispatchSave1402], edx
        je       L_1322
        mov      eax, dword ptr [g_dispatchSave1357]
        lea      edx, [edi - 1]
        add      eax, esi
        mov      dword ptr [g_dispatchSave1402], edx
        mov      dword ptr [g_dispatchSave1334], eax
        lea      eax, [ecx + 2]
        mov      dword ptr [g_dispatchSave1396], eax
    L_1322:
        mov      eax, dword ptr [g_dispatchSave1357]
        mov      ebx, dword ptr [g_dispatchSave1381]
        add      eax, eax
        inc      ebx
        cmp      edx, 1
        mov      dword ptr [g_dispatchSave1395], eax
        mov      dword ptr [g_dispatchSave1381], ebx
        jl       L_13b2
        mov      eax, dword ptr [g_dispatchSave1334]
        shl      eax, 0x10
        mov      edx, dword ptr [g_dispatchSave1404]
        shr      edx, 1
        mov      ecx, dword ptr [g_dispatchSave1334]
        shr      ecx, 0x10
        mov      dl, cl
        mov      edi, dword ptr [g_dispatchSave1396]
        add      edi, dword ptr [g_dispatchSave1402]
        add      edi, dword ptr [g_dispatchSave1402]
        mov      esi, dword ptr [g_dispatchSave1402]
        neg      esi
        mov      ecx, dword ptr [g_dispatchSave1395]
        rol      ecx, 0x10
        mov      ch, 0
    L_1380:
        mov      ax, word ptr [edx*2]
        test     ax, ax
        je       L_1391
        mov      word ptr [edi + esi*2], ax
    L_1391:
        add      eax, ecx
        adc      dl, cl
        add      esi, 2
        jl       L_1380
        mov      ebx, dword ptr [g_dispatchSave1381]
        mov      edi, dword ptr [g_dispatchSave1708]
        mov      esi, dword ptr [g_dispatchSave1371]
        mov      ecx, dword ptr [g_dispatchSave1346]
    L_13b2:
        mov      edx, dword ptr [g_dispatchSave1358]
        mov      eax, dword ptr [g_dispatchSave1707]
        add      dword ptr [g_dispatchSave1374], edx
        mov      edx, dword ptr [g_viewportY]
        dec      eax
        add      ecx, edx
        test     eax, eax
        mov      dword ptr [g_dispatchSave1707], eax
        mov      dword ptr [g_dispatchSave1346], ecx
        jg       L_12c0
    L_13df:
        pop      edi
        pop      esi
        pop      ebx
        ret
    }
}
#endif
