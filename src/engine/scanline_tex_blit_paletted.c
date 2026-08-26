/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
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

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_viewportW;
extern unsigned int g_viewportH;
extern unsigned int g_dispatchSave1707;
extern unsigned int g_dispatchSave1708;
extern unsigned int g_dispatchSave1340;
extern unsigned int g_dispatchSave1345;
extern unsigned int g_dispatchSave1346;
extern unsigned int g_dispatchSave1357;
extern unsigned int g_dispatchSave1358;
extern s32 g_clipMinScratch;
extern unsigned int g_dispatchSave1367;
extern unsigned int g_dispatchSave1371;
extern unsigned int g_dispatchSave1373;
extern unsigned int g_dispatchSave1374;
#endif
extern unsigned int g_dispatchSave1375;
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_dispatchSave1377;
extern unsigned int g_dispatchSave1378;
extern unsigned int g_dispatchSave1380;
extern unsigned int g_dispatchSave1381;
extern unsigned int g_dispatchSave1383;
extern unsigned int g_dispatchSave1387;
#endif
extern unsigned int g_dispatchSave1388;
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_dispatchSave1400;
extern unsigned int g_dispatchSave1403;
extern unsigned int g_viewportX;
extern unsigned int g_viewportY;
extern unsigned int g_dispatchSave1404;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_clipMinScratch (*(unsigned int *)MK4_VA(unsigned int, 0xf70f70u))
#define g_dispatchSave1340 (*(unsigned int *)MK4_VA(unsigned int, 0xf4d028u))
#define g_dispatchSave1345 (*(unsigned int *)MK4_VA(unsigned int, 0xf4d040u))
#define g_dispatchSave1346 (*(unsigned int *)MK4_VA(unsigned int, 0xf4d044u))
#define g_dispatchSave1357 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f4cu))
#define g_dispatchSave1358 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f50u))
#define g_dispatchSave1367 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f7cu))
#define g_dispatchSave1371 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f88u))
#define g_dispatchSave1373 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f90u))
#define g_dispatchSave1374 (*(unsigned int *)MK4_VA(unsigned int, 0xf70f98u))
#define g_dispatchSave1377 (*(unsigned int *)MK4_VA(unsigned int, 0xf70fa0u))
#define g_dispatchSave1378 (*(unsigned int *)MK4_VA(unsigned int, 0xf70fa8u))
#define g_dispatchSave1380 (*(unsigned int *)MK4_VA(unsigned int, 0xf70fb0u))
#define g_dispatchSave1381 (*(unsigned int *)MK4_VA(unsigned int, 0xf70fb8u))
#define g_dispatchSave1383 (*(unsigned int *)MK4_VA(unsigned int, 0xf70fc0u))
#define g_dispatchSave1387 (*(unsigned int *)MK4_VA(unsigned int, 0xf70fd8u))
#define g_dispatchSave1400 (*(unsigned int *)MK4_VA(unsigned int, 0xf85b34u))
#define g_dispatchSave1403 (*(unsigned int *)MK4_VA(unsigned int, 0xf85b4cu))
#define g_dispatchSave1404 (*(unsigned int *)MK4_VA(unsigned int, 0xf85b58u))
#define g_dispatchSave1707 (*(unsigned int *)MK4_VA(unsigned int, 0xb2d008u))
#define g_dispatchSave1708 (*(unsigned int *)MK4_VA(unsigned int, 0xb2d00cu))
#define g_viewportH (*(unsigned int *)MK4_VA(unsigned int, 0x4ffd48u))
#define g_viewportW (*(unsigned int *)MK4_VA(unsigned int, 0x4ffd44u))
#define g_viewportX (*(unsigned int *)MK4_VA(unsigned int, 0xf85b50u))
#define g_viewportY (*(unsigned int *)MK4_VA(unsigned int, 0xf85b54u))
#endif


#ifdef NON_MATCHING
/*
 * Portable C twin (path A). Faithful register-level transcription of the naked
 * branch below; verified by seeded co-exec (tools/decomp/verify_scanline.py),
 * not byte-match. Paletted/CLUT variant of ScanlineTexBlit: the texture holds
 * 16bpp indices; each is looked up in a palette (base = ((1367 & 0xf0) << 13)
 * + 1340) to get the 16bpp output color. Index 0 = transparent. The texel
 * column index is (g_dispatchSave1387 >> 16) & 0xff and the texture page/row
 * byte is (g_dispatchSave1374 >> 16) & 0xff - in the original these are the
 * aliased bytes g_dispatchSave1388 (&1387+2) / g_dispatchSave1375 (&1374+2);
 * expressed via 1387/1374 here so the twin is layout-independent (correct in
 * both the verifier and the native build). Replaces an earlier unverified
 * Ghidra twin whose undefined2* globals did not co-exec.
 */
void ScanlineTexBlitPaletted(void)
{
    unsigned int eax, ebx, ecx, edx, esi, edi, ebp;

    if (g_viewportX == 0) return;
    ecx = g_dispatchSave1378;                  /* x0 */
    if ((int)ecx >= (int)g_viewportW) return;
    ebx = g_dispatchSave1381;                  /* y0 */
    if ((int)ebx >= (int)g_viewportH) return;
    esi = g_dispatchSave1380;                  /* x1 */
    if ((int)esi < 0) return;
    edi = g_dispatchSave1383;                  /* y1 */
    if ((int)edi < 0) return;
    esi -= ecx;                                /* w */
    edi -= ebx;                                /* h */
    g_dispatchSave1708 = esi;
    g_dispatchSave1707 = edi;
    if ((int)esi < 1) return;
    if ((int)edi < 1) return;

    eax = g_dispatchSave1374 << 16;  g_dispatchSave1374 = eax;   /* u0fx (V) */
    edx = g_dispatchSave1371 << 16;                             /* Pfx */
    eax = g_dispatchSave1373 << 16;  g_dispatchSave1373 = eax;   /* U1fx */
    eax = eax - edx;
    g_dispatchSave1371 = edx;
    ebp = g_dispatchSave1377;                                   /* Q */
    eax = (unsigned int)((int)eax / (int)esi);                  /* gradX = (U1fx-Pfx)/w */
    edx = g_dispatchSave1374;                                   /* u0fx */
    ebp <<= 16;  g_dispatchSave1377 = ebp;                       /* Qfx */
    g_dispatchSave1357 = eax;                                   /* gradX */
    eax = ebp;
    eax = eax - edx;
    eax = (unsigned int)((int)eax / (int)edi);                  /* gradY = (Qfx-u0fx)/h */
    ebp = eax;
    g_dispatchSave1358 = ebp;                                   /* gradY */

    if ((int)ecx < 0) {                                         /* left clip */
        eax = g_dispatchSave1357;
        edx = g_dispatchSave1371;
        eax = (unsigned int)((int)eax * (int)ecx);
        edx = edx - eax;
        esi = esi + ecx;
        ecx = 0;
        g_dispatchSave1371 = edx;
        g_dispatchSave1708 = esi;
        g_dispatchSave1378 = ecx;
    }
    if ((int)ebx < 0) {                                         /* top clip */
        edx = ebp;
        eax = g_dispatchSave1374;
        edx = (unsigned int)((int)edx * (int)ebx);
        eax = eax - edx;
        edi = edi + ebx;
        ebx = 0;
        g_dispatchSave1374 = eax;
        g_dispatchSave1707 = edi;
        g_dispatchSave1381 = ebx;
    }
    eax = g_viewportW;
    edx = g_dispatchSave1380;
    if (!((int)edx < (int)eax)) {                              /* right clip */
        eax = eax - ecx;
        esi = eax;
        g_dispatchSave1708 = esi;
    }
    eax = g_viewportH;
    edx = g_dispatchSave1383;
    if (!((int)edx < (int)eax)) {                              /* bottom clip */
        eax = eax - ebx;
        edi = eax;
        g_dispatchSave1707 = edi;
    }
    edx = g_viewportY;                                         /* pitch */
    eax = g_viewportX;                                         /* fb base */
    edx = (unsigned int)((int)edx * (int)ebx);                /* pitch*y0 */
    eax = eax + edx;
    ebx = g_dispatchSave1340;                                  /* palette base lo */
    eax = eax + ecx * 2;                                       /* + x0*2 */
    ecx = g_dispatchSave1367 & 0xff;
    g_dispatchSave1346 = eax;                                  /* dest top-left */
    eax = g_dispatchSave1403;
    ecx = (ecx & 0xfffffff0u) << 13;
    eax = eax & 0xf;
    ecx = ecx + ebx;                                           /* palette base */
    eax <<= 16;                                                /* sub-texel << 16 */
    g_dispatchSave1403 = eax;
    if ((int)edi <= 0) return;

    for (;;) {                                                 /* row loop; ecx=palette base */
        edx = g_dispatchSave1371;
        ebx = g_dispatchSave1400;                              /* tex base */
        g_dispatchSave1387 = edx;
        edx = ((g_dispatchSave1374 >> 16) & 0xff) << 8;        /* texpage/row byte (1374-derived) */
        g_clipMinScratch = esi;                                /* column counter = w */
        edx = edx + eax;                                       /* + sub<<16 */
        edx = ebx + edx * 2;                                   /* texture row base */
        g_dispatchSave1404 = edx;
        edx = g_dispatchSave1346;
        g_dispatchSave1345 = edx;                              /* current dest ptr */
        if ((int)esi > 0) {
            do {
                edx = g_dispatchSave1404;
                eax = (g_dispatchSave1387 >> 16) & 0xff;       /* texel column index */
                {
                    unsigned short t = *(unsigned short *)MK4_PTR(edx + eax * 2);
                    eax = (eax & 0xffff0000u) | t;             /* mov ax, [edx+eax*2] */
                }
                if ((eax & 0xffff) != 0) {                     /* index 0 = transparent */
                    edx = g_dispatchSave1345;
                    eax = eax & 0xffff;
                    {
                        unsigned short c = *(unsigned short *)MK4_PTR(ecx + eax * 2);
                        *(unsigned short *)MK4_PTR(edx) = c; /* CLUT lookup -> pixel */
                    }
                    esi = g_dispatchSave1708;                  /* reload esi=w */
                    edi = g_dispatchSave1707;                  /* reload edi=h */
                }
                eax = g_clipMinScratch;
                edx = g_dispatchSave1357;                      /* gradX */
                ebp = g_dispatchSave1387;
                ebx = g_dispatchSave1345;
                eax = eax - 1;
                ebp = ebp + edx;                               /* texcoord += gradX */
                ebx = ebx + 2;                                 /* dest += 2 */
                g_clipMinScratch = eax;
                g_dispatchSave1387 = ebp;
                g_dispatchSave1345 = ebx;
            } while ((int)eax > 0);
            eax = g_dispatchSave1403;                          /* restore eax = sub<<16 */
            ebp = g_dispatchSave1358;                          /* restore ebp = gradY */
        }
        edx = g_dispatchSave1374;
        ebx = g_dispatchSave1346;
        edx = edx + ebp;                                       /* 1374 += gradY (V advance) */
        edi = edi - 1;                                         /* rows-- */
        g_dispatchSave1374 = edx;
        edx = g_viewportY;
        ebx = ebx + edx;                                       /* dest += pitch */
        g_dispatchSave1707 = edi;
        g_dispatchSave1346 = ebx;
        if (!((int)edi > 0)) break;
    }
}
#else
__declspec(naked) void ScanlineTexBlitPaletted(void)
{
    __asm {
        mov      eax, dword ptr [g_viewportX]
        push     ebx
        push     ebp
        push     esi
        test     eax, eax
        push     edi
        je       L_05d4
        mov      ecx, dword ptr [g_dispatchSave1378]
        mov      eax, dword ptr [g_viewportW]
        cmp      ecx, eax
        jge      L_05d4
        mov      ebx, dword ptr [g_dispatchSave1381]
        mov      eax, dword ptr [g_viewportH]
        cmp      ebx, eax
        jge      L_05d4
        mov      esi, dword ptr [g_dispatchSave1380]
        test     esi, esi
        jl       L_05d4
        mov      edi, dword ptr [g_dispatchSave1383]
        test     edi, edi
        jl       L_05d4
        sub      esi, ecx
        sub      edi, ebx
        cmp      esi, 1
        mov      dword ptr [g_dispatchSave1708], esi
        mov      dword ptr [g_dispatchSave1707], edi
        jl       L_05d4
        cmp      edi, 1
        jl       L_05d4
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
        mov      ebp, dword ptr [g_dispatchSave1377]
        cdq
        idiv     esi
        mov      edx, dword ptr [g_dispatchSave1374]
        shl      ebp, 0x10
        mov      dword ptr [g_dispatchSave1377], ebp
        mov      dword ptr [g_dispatchSave1357], eax
        mov      eax, ebp
        sub      eax, edx
        cdq
        idiv     edi
        test     ecx, ecx
        mov      ebp, eax
        mov      dword ptr [g_dispatchSave1358], ebp
        jge      L_0456
        mov      eax, dword ptr [g_dispatchSave1357]
        mov      edx, dword ptr [g_dispatchSave1371]
        imul     eax, ecx
        sub      edx, eax
        add      esi, ecx
        xor      ecx, ecx
        mov      dword ptr [g_dispatchSave1371], edx
        mov      dword ptr [g_dispatchSave1708], esi
        mov      dword ptr [g_dispatchSave1378], ecx
    L_0456:
        test     ebx, ebx
        jge      L_047b
        mov      edx, ebp
        mov      eax, dword ptr [g_dispatchSave1374]
        imul     edx, ebx
        sub      eax, edx
        add      edi, ebx
        xor      ebx, ebx
        mov      dword ptr [g_dispatchSave1374], eax
        mov      dword ptr [g_dispatchSave1707], edi
        mov      dword ptr [g_dispatchSave1381], ebx
    L_047b:
        mov      eax, dword ptr [g_viewportW]
        mov      edx, dword ptr [g_dispatchSave1380]
        cmp      edx, eax
        jl       L_0494
        sub      eax, ecx
        mov      esi, eax
        mov      dword ptr [g_dispatchSave1708], esi
    L_0494:
        mov      eax, dword ptr [g_viewportH]
        mov      edx, dword ptr [g_dispatchSave1383]
        cmp      edx, eax
        jl       L_04ad
        sub      eax, ebx
        mov      edi, eax
        mov      dword ptr [g_dispatchSave1707], edi
    L_04ad:
        mov      edx, dword ptr [g_viewportY]
        mov      eax, dword ptr [g_viewportX]
        imul     edx, ebx
        add      eax, edx
        mov      ebx, dword ptr [g_dispatchSave1340]
        lea      eax, [eax + ecx*2]
        mov      ecx, dword ptr [g_dispatchSave1367]
        and      ecx, 0xff
        mov      dword ptr [g_dispatchSave1346], eax
        mov      eax, dword ptr [g_dispatchSave1403]
        and      ecx, 0xfffffff0
        shl      ecx, 0xd
        and      eax, 0xf
        add      ecx, ebx
        shl      eax, 0x10
        test     edi, edi
        mov      dword ptr [g_dispatchSave1403], eax
        jle      L_05d4
    L_04f7:
        mov      edx, dword ptr [g_dispatchSave1371]
        mov      ebx, dword ptr [g_dispatchSave1400]
        mov      dword ptr [g_dispatchSave1387], edx
        xor      edx, edx
        mov      dh, byte ptr [g_dispatchSave1375]
        mov      dword ptr [g_clipMinScratch], esi
        add      edx, eax
        test     esi, esi
        lea      edx, [ebx + edx*2]
        mov      dword ptr [g_dispatchSave1404], edx
        mov      edx, dword ptr [g_dispatchSave1346]
        mov      dword ptr [g_dispatchSave1345], edx
        jle      L_05a3
    L_0532:
        mov      edx, dword ptr [g_dispatchSave1404]
        xor      eax, eax
        mov      al, byte ptr [g_dispatchSave1388]
        mov      ax, word ptr [edx + eax*2]
        test     ax, ax
        je       L_0566
        mov      edx, dword ptr [g_dispatchSave1345]
        and      eax, 0xffff
        mov      ax, word ptr [ecx + eax*2]
        mov      word ptr [edx], ax
        mov      esi, dword ptr [g_dispatchSave1708]
        mov      edi, dword ptr [g_dispatchSave1707]
    L_0566:
        mov      eax, dword ptr [g_clipMinScratch]
        mov      edx, dword ptr [g_dispatchSave1357]
        mov      ebp, dword ptr [g_dispatchSave1387]
        mov      ebx, dword ptr [g_dispatchSave1345]
        dec      eax
        add      ebp, edx
        add      ebx, 2
        mov      dword ptr [g_clipMinScratch], eax
        test     eax, eax
        mov      dword ptr [g_dispatchSave1387], ebp
        mov      dword ptr [g_dispatchSave1345], ebx
        jg       L_0532
        mov      eax, dword ptr [g_dispatchSave1403]
        mov      ebp, dword ptr [g_dispatchSave1358]
    L_05a3:
        mov      edx, dword ptr [g_dispatchSave1374]
        mov      ebx, dword ptr [g_dispatchSave1346]
        add      edx, ebp
        dec      edi
        mov      dword ptr [g_dispatchSave1374], edx
        mov      edx, dword ptr [g_viewportY]
        add      ebx, edx
        mov      dword ptr [g_dispatchSave1707], edi
        test     edi, edi
        mov      dword ptr [g_dispatchSave1346], ebx
        jg       L_04f7
    L_05d4:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    }
}
#endif
