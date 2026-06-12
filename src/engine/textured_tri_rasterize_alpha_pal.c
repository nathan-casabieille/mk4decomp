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

extern unsigned int g_viewportW;
extern unsigned int g_viewportH;
extern unsigned int g_texturedTriVar;
extern unsigned int g_dispatchSave1336;
extern unsigned int g_dispatchSave1337;
extern unsigned int g_dispatchSave1338;
extern unsigned int g_dispatchSave1339;
extern unsigned int g_dispatchSave1342;
extern unsigned int g_dispatchSave1343;
extern unsigned int g_dispatchSave1345;
extern unsigned int g_dispatchSave1346;
extern unsigned int g_dispatchSave1359;
extern unsigned int g_dispatchSave1361;
extern unsigned int g_dispatchSave1362;
extern unsigned int g_dispatchSave1363;
extern unsigned int g_dispatchSave1364;
extern unsigned int g_dispatchSave1365;
extern s32 g_clipMinScratch;
extern unsigned int g_dispatchSave1366;
extern s32 g_clipMaxScratch;
extern unsigned int g_dispatchSave1370;
extern unsigned int g_dispatchSave1371;
extern unsigned int g_dispatchSave1372;
extern unsigned int g_dispatchSave1373;
extern unsigned int g_dispatchSave1374;
extern unsigned int g_dispatchSave1376;
extern unsigned int g_dispatchSave1377;
extern unsigned int g_dispatchSave1378;
extern unsigned int g_dispatchSave1379;
extern unsigned int g_dispatchSave1380;
extern unsigned int g_dispatchSave1381;
extern unsigned int g_dispatchSave1382;
extern unsigned int g_dispatchSave1383;
extern unsigned int g_dispatchSave1384;
extern unsigned int g_dispatchSave1385;
extern unsigned int g_dispatchSave1387;
extern unsigned int g_dispatchSave1388;
extern unsigned int g_dispatchSave1389;
extern unsigned int g_dispatchSave1393;
extern unsigned int g_dispatchSave1394;
extern unsigned int g_dispatchSave1400;
extern unsigned int g_dispatchSave1403;
extern unsigned int g_viewportX;
extern unsigned int g_viewportY;
extern unsigned int g_dispatchSave1404;

#ifdef NON_MATCHING
/*
 * Portable C twin (path A). Fresh full transcription (the reuse-outer recipe
 * mismatched because AlphaPal's register flow differs from TexturedTriRasterize).
 * Affine textured triangle with a two-mode SATURATING ADDITIVE blend
 * (g_texturedTriVar: 565 mask 0xf7de/0x10820, 555 mask 0x7bde/0x8420 - same math
 * as ScanlineTexBlitAdditive) over a paletted texel index (V_int<<8 | U_int) read
 * from word[1404 + idx*2]; simple full-add stepping (U+=1342, V+=1343). No stack
 * frame. Verified by tools/decomp/verify_tri.py.
 */
void TexturedTriRasterizeAlphaPal(void)
{
    unsigned int eax, ebx, ecx, edx, esi, edi, ebp;
    unsigned int *X = (unsigned int *)&g_dispatchSave1378;
    unsigned int *Y = (unsigned int *)&g_dispatchSave1381;
    unsigned int *U = (unsigned int *)&g_dispatchSave1371;
    unsigned int *Vv = (unsigned int *)&g_dispatchSave1374;

    if (g_viewportX == 0) return;
    edi = Y[2]; ebp = Y[0]; ebx = Y[1]; edx = X[2]; eax = X[0]; ecx = X[1];
    edi -= ebp; ebx -= ebp; edx -= eax; ecx -= eax;
    edx = (unsigned int)((int)((unsigned int)edx * (unsigned int)ebx));
    ecx = (unsigned int)((int)((unsigned int)ecx * (unsigned int)edi));
    ecx = ecx - edx;
    g_clipMinScratch = ecx;
    if ((int)ecx <= 0) return;
    edx = U[2]; eax = U[0]; esi = U[1];
    edx -= eax; esi -= eax;
    edx = (unsigned int)((int)((unsigned int)edx * (unsigned int)ebx));
    esi = (unsigned int)((int)((unsigned int)esi * (unsigned int)edi));
    esi = esi - edx;
    { int n=(int)esi, ab=n<0?-n:n;
      if (ab>=0x80000) eax=(unsigned int)((int)(esi<<9)/(int)ecx)<<7;
      else eax=(unsigned int)((int)(esi<<12)/(int)ecx)<<4; }
    g_dispatchSave1342 = eax;
    edx = Vv[2]; esi = Vv[1]; eax = Vv[0];
    edx -= eax; esi -= eax;
    edx = (unsigned int)((int)((unsigned int)edx * (unsigned int)ebx));
    esi = (unsigned int)((int)((unsigned int)esi * (unsigned int)edi));
    esi = esi - edx;
    { int n=(int)esi, ab=n<0?-n:n;
      if (ab>=0x80000) eax=(unsigned int)((int)(esi<<9)/(int)ecx)<<7;
      else eax=(unsigned int)((int)(esi<<12)/(int)ecx)<<4; }
    g_dispatchSave1343 = eax;
    ecx = Y[1]; esi = 0; eax = 0; edx = ebp;
    g_dispatchSave1359 = eax; g_dispatchSave1365 = edx; g_dispatchSave1394 = ebp;
    if ((int)ecx < (int)ebp) {
        g_dispatchSave1359 = 1; eax = g_dispatchSave1359; g_dispatchSave1365 = ecx; edx = ecx;
    } else {
        g_dispatchSave1394 = ecx;
    }
    ecx = Y[2];
    if ((int)ecx < (int)edx) {
        g_dispatchSave1359 = 2; eax = g_dispatchSave1359; g_dispatchSave1365 = ecx; edx = ecx;
    }
    if ((int)ecx > (int)g_dispatchSave1394) g_dispatchSave1394 = ecx;
    if ((int)edx < (int)esi) { g_dispatchSave1365 = esi; edx = esi; }
    ecx = g_viewportH; edi = g_dispatchSave1394;
    if ((int)edi > (int)ecx) g_dispatchSave1394 = ecx;
    ecx = (g_dispatchSave1403 & 0xf) << 0x11;
    ecx = ecx + g_dispatchSave1400;
    edi = g_viewportX;
    g_dispatchSave1366 = eax;
    g_dispatchSave1404 = ecx;
    ecx = (unsigned int)((int)((unsigned int)g_viewportY * (unsigned int)edx));
    ecx = ecx + edi;
    g_dispatchSave1385 = esi;
    g_dispatchSave1346 = ecx;
    g_dispatchSave1364 = esi;
    if ((int)edx >= (int)g_dispatchSave1394) return;
    goto L_21ac;

L_21a1:
    edx = g_dispatchSave1365;
    eax = g_dispatchSave1359;
L_21ac:
    if ((int)esi > (int)edx) goto L_22c7;
L_21b6:
    eax = g_dispatchSave1359;
L_21bb:
    esi = eax - 1;
    if ((int)esi < 0) esi = 2;
    ebx = Y[esi]; edi = Y[eax];
    ecx = ebx - edi;
    if (ecx != 0) {
        edx = g_dispatchSave1359;
        eax = X[esi]; ebp = X[edx]; eax -= ebp;
        ebp = g_dispatchSave1359;
        eax = (unsigned int)((int)(eax << 16) / (int)ecx);
        edx = U[ebp];
        g_dispatchSave1338 = eax;
        eax = U[esi]; eax -= edx;
        eax = (unsigned int)((int)(eax << 16) / (int)ecx);
        edx = Vv[ebp];
        g_dispatchSave1336 = eax;
        eax = Vv[esi]; eax -= edx;
        eax = (unsigned int)((int)(eax << 16) / (int)ecx);
        edx = g_dispatchSave1365;
        g_dispatchSave1337 = eax;
        eax = ebp;
    }
/* L_2240 */
    ecx = X[eax]; ebp = U[eax]; eax = Vv[eax];
    eax = eax << 16;
    g_dispatchSave1362 = eax;
    eax = edx;
    ecx = ecx << 16; ebp = ebp << 16;
    eax = eax - edi;
    g_dispatchSave1363 = ecx;
    g_dispatchSave1361 = ebp;
    g_clipMaxScratch = eax;
    if (eax != 0) {
        edi = (unsigned int)((int)((unsigned int)eax * (unsigned int)g_dispatchSave1338));
        ecx = ecx + edi;
        g_dispatchSave1363 = ecx;
        ecx = (unsigned int)((int)((unsigned int)eax * (unsigned int)g_dispatchSave1336));
        eax = (unsigned int)((int)((unsigned int)eax * (unsigned int)g_dispatchSave1337));
        ebp = ebp + ecx;
        ecx = g_dispatchSave1362;
        ecx = ecx + eax;
        g_dispatchSave1361 = ebp;
        g_dispatchSave1362 = ecx;
    }
/* L_22b1 */
    g_dispatchSave1359 = esi;
    g_dispatchSave1364 = ebx;
    if ((int)ebx <= (int)edx) goto L_21b6;
    goto L_22cd;
L_22c7:
    ebp = g_dispatchSave1361;
L_22cd:
    if ((int)g_dispatchSave1385 > (int)edx) goto L_2364;
L_22d9:
    eax = g_dispatchSave1366;
    esi = eax + 1;
    if ((int)esi > 2) esi = 0;
    ebx = Y[esi]; edi = Y[eax];
    ecx = ebx - edi;
    if (ecx != 0) {
        edx = g_dispatchSave1366;
        eax = X[esi] - X[edx];
        eax = (unsigned int)((int)(eax << 16) / (int)ecx);
        edx = g_dispatchSave1365;
        g_dispatchSave1339 = eax;
        eax = g_dispatchSave1366;
    }
/* L_2326 */
    ecx = X[eax];
    eax = edx;
    ecx = ecx << 16;
    eax = eax - edi;
    g_dispatchSave1384 = ecx;
    g_clipMaxScratch = eax;
    if (eax != 0) {
        eax = (unsigned int)((int)((unsigned int)eax * (unsigned int)g_dispatchSave1339));
        ecx = ecx + eax;
        g_dispatchSave1384 = ecx;
    }
/* L_2350 */
    g_dispatchSave1366 = esi;
    g_dispatchSave1385 = ebx;
    if ((int)ebx <= (int)edx) goto L_22d9;
L_2364:
    eax = g_dispatchSave1385;
    esi = g_dispatchSave1364;
    if ((int)esi < (int)eax) eax = esi;
    ecx = g_dispatchSave1394;
    ebx = eax;
    ebx = ebx - edx;
    g_clipMinScratch = eax;
    g_dispatchSave1393 = ebx;
    g_dispatchSave1365 = eax;
    if ((int)eax > (int)ecx) {
        edx = ecx;
        edx = edx - eax;
        ebx = ebx + edx;
        g_dispatchSave1393 = ebx;
    }
/* L_239f */
    if ((int)ebx <= 0) goto L_2635;
L_23a7:
    ecx = g_dispatchSave1384;
    eax = g_dispatchSave1363;
    ecx = (unsigned int)((int)ecx >> 16);
    eax = (unsigned int)((int)eax >> 16);
    edi = ecx;
    g_dispatchSave1370 = ecx;
    edi = edi - eax;
    g_clipMinScratch = eax;
    g_clipMaxScratch = edi;
    if ((int)edi <= 0) goto L_25bf;
    if ((int)ecx < 0) goto L_25bf;
    ecx = g_viewportW;
    if ((int)eax >= (int)ecx) goto L_25bf;
    esi = g_dispatchSave1362;
    edi = edi + eax;
    g_dispatchSave1387 = ebp;
    g_dispatchSave1389 = esi;
    g_clipMaxScratch = edi;
    if ((int)eax < 0) {
        esi = (unsigned int)((int)((unsigned int)eax * (unsigned int)g_dispatchSave1342));
        eax = (unsigned int)((int)((unsigned int)eax * (unsigned int)g_dispatchSave1343));
        edx = ebp - esi;
        esi = g_dispatchSave1362;
        esi = esi - eax;
        g_dispatchSave1387 = edx;
        g_dispatchSave1389 = esi;
        eax = 0;
    }
/* L_2433 */
    edx = g_dispatchSave1346 + eax * 2;
    g_dispatchSave1345 = edx;
    if ((int)edi > (int)ecx) { edi = ecx; g_clipMaxScratch = edi; }
    edi = edi - eax;
    g_clipMinScratch = edi;
    if ((int)edi <= 0) goto L_25bf;
    {
        unsigned int uacc = g_dispatchSave1387;
        unsigned int vacc = g_dispatchSave1389;
        edx = g_dispatchSave1345;
        edi = g_clipMinScratch;
        if (g_texturedTriVar != 0) {           /* L_246b: 565 */
            for (;;) {
                ebx = g_dispatchSave1404;
                ecx = (((vacc & 0xff0000u) | (((uacc >> 16) & 0xff) << 8)) >> 8);
                {
                    unsigned int t = *(unsigned short *)(unsigned long)(ebx + ecx * 2);
                    if (t != 0) {
                        unsigned int d = *(unsigned short *)(unsigned long)edx;
                        unsigned int sum = (t & 0xf7deu) + (d & 0xf7deu);
                        unsigned int ov = sum & 0x10820u;
                        unsigned int s2 = (((ov & 0xffff00ffu) | ((ov >> 1) & 0x7f80u)) >> 5);
                        *(unsigned short *)(unsigned long)edx =
                            (unsigned short)(((ov - s2) | sum) & 0xf7deu);
                        edi = g_clipMinScratch;
                        vacc = g_dispatchSave1389;
                        edx = g_dispatchSave1345;
                    }
                }
                uacc = g_dispatchSave1387 + g_dispatchSave1342;
                vacc = vacc + g_dispatchSave1343;
                edx = edx + 2;
                edi = edi - 1;
                g_clipMinScratch = edi;
                g_dispatchSave1387 = uacc;
                g_dispatchSave1389 = vacc;
                g_dispatchSave1345 = edx;
                if (!((int)edi > 0)) break;
            }
        } else {                               /* L_251a: 555 */
            for (;;) {
                ebx = g_dispatchSave1404;
                ecx = (((vacc & 0xff0000u) | (((uacc >> 16) & 0xff) << 8)) >> 8);
                {
                    unsigned int t = *(unsigned short *)(unsigned long)(ebx + ecx * 2);
                    if (t != 0) {
                        unsigned int d = *(unsigned short *)(unsigned long)edx;
                        unsigned int sum = (t & 0x7bdeu) + (d & 0x7bdeu);
                        unsigned int ov = sum & 0x8420u;
                        unsigned int s2 = ov >> 5;
                        *(unsigned short *)(unsigned long)edx =
                            (unsigned short)(((ov - s2) | sum) & 0x7bdeu);
                        edi = g_clipMinScratch;
                        vacc = g_dispatchSave1389;
                        edx = g_dispatchSave1345;
                    }
                }
                uacc = g_dispatchSave1387 + g_dispatchSave1342;
                vacc = vacc + g_dispatchSave1343;
                edx = edx + 2;
                edi = edi - 1;
                g_clipMinScratch = edi;
                g_dispatchSave1387 = uacc;
                g_dispatchSave1389 = vacc;
                g_dispatchSave1345 = edx;
                if (!((int)edi > 0)) break;
            }
        }
    }
/* L_25b3 */
    ebx = g_dispatchSave1393;
    ebp = g_dispatchSave1361;
L_25bf:
    edx = g_dispatchSave1346 + g_viewportY;
    g_dispatchSave1346 = edx;
    esi = g_dispatchSave1384 + g_dispatchSave1339;
    ebp = g_dispatchSave1361 + g_dispatchSave1336;
    edi = g_dispatchSave1363 + g_dispatchSave1338;
    ecx = g_dispatchSave1362 + g_dispatchSave1337;
    ebx = g_dispatchSave1393 - 1;
    g_dispatchSave1393 = ebx;
    g_dispatchSave1363 = edi;
    g_dispatchSave1384 = esi;
    g_dispatchSave1361 = ebp;
    g_dispatchSave1362 = ecx;
    if ((int)ebx > 0) goto L_23a7;
    ecx = g_dispatchSave1394;
    esi = g_dispatchSave1364;
L_2635:
    if ((int)g_dispatchSave1365 < (int)ecx) goto L_21a1;
    return;
}
#else
__declspec(naked) void TexturedTriRasterizeAlphaPal(void)
{
    __asm {
        mov      eax, dword ptr [g_viewportX]
        push     ebx
        push     ebp
        push     esi
        test     eax, eax
        push     edi
        je       L_2641
        mov      edi, dword ptr [g_dispatchSave1383]
        mov      ebp, dword ptr [g_dispatchSave1381]
        mov      ebx, dword ptr [g_dispatchSave1382]
        mov      edx, dword ptr [g_dispatchSave1380]
        mov      eax, dword ptr [g_dispatchSave1378]
        mov      ecx, dword ptr [g_dispatchSave1379]
        sub      edi, ebp
        sub      ebx, ebp
        sub      edx, eax
        sub      ecx, eax
        imul     edx, ebx
        imul     ecx, edi
        sub      ecx, edx
        test     ecx, ecx
        mov      dword ptr [g_clipMinScratch], ecx
        jle      L_2641
        mov      edx, dword ptr [g_dispatchSave1373]
        mov      eax, dword ptr [g_dispatchSave1371]
        mov      esi, dword ptr [g_dispatchSave1372]
        sub      edx, eax
        sub      esi, eax
        imul     edx, ebx
        imul     esi, edi
        sub      esi, edx
        mov      eax, esi
        cdq
        xor      eax, edx
        sub      eax, edx
        cmp      eax, 0x80000
        mov      eax, esi
        jge      L_206a
        shl      eax, 0xc
        cdq
        idiv     ecx
        shl      eax, 4
        jmp      L_2073
    L_206a:
        shl      eax, 9
        cdq
        idiv     ecx
        shl      eax, 7
    L_2073:
        mov      edx, dword ptr [g_dispatchSave1377]
        mov      esi, dword ptr [g_dispatchSave1376]
        mov      dword ptr [g_dispatchSave1342], eax
        mov      eax, dword ptr [g_dispatchSave1374]
        sub      edx, eax
        sub      esi, eax
        imul     edx, ebx
        imul     esi, edi
        sub      esi, edx
        mov      eax, esi
        cdq
        xor      eax, edx
        sub      eax, edx
        cmp      eax, 0x80000
        mov      eax, esi
        jge      L_20b0
        shl      eax, 0xc
        cdq
        idiv     ecx
        shl      eax, 4
        jmp      L_20b9
    L_20b0:
        shl      eax, 9
        cdq
        idiv     ecx
        shl      eax, 7
    L_20b9:
        mov      ecx, dword ptr [g_dispatchSave1382]
        mov      dword ptr [g_dispatchSave1343], eax
        xor      esi, esi
        xor      eax, eax
        mov      edx, ebp
        cmp      ecx, ebp
        mov      dword ptr [g_dispatchSave1359], eax
        mov      dword ptr [g_dispatchSave1365], edx
        mov      dword ptr [g_dispatchSave1394], ebp
        jge      L_20f8
        mov      dword ptr [g_dispatchSave1359], 1
        mov      eax, dword ptr [g_dispatchSave1359]
        mov      dword ptr [g_dispatchSave1365], ecx
        mov      edx, ecx
        jmp      L_20fe
    L_20f8:
        mov      dword ptr [g_dispatchSave1394], ecx
    L_20fe:
        mov      ecx, dword ptr [g_dispatchSave1383]
        cmp      ecx, edx
        jge      L_211f
        mov      dword ptr [g_dispatchSave1359], 2
        mov      eax, dword ptr [g_dispatchSave1359]
        mov      dword ptr [g_dispatchSave1365], ecx
        mov      edx, ecx
    L_211f:
        cmp      ecx, dword ptr [g_dispatchSave1394]
        jle      L_212d
        mov      dword ptr [g_dispatchSave1394], ecx
    L_212d:
        cmp      edx, esi
        jge      L_2139
        mov      dword ptr [g_dispatchSave1365], esi
        mov      edx, esi
    L_2139:
        mov      ecx, dword ptr [g_viewportH]
        mov      edi, dword ptr [g_dispatchSave1394]
        cmp      edi, ecx
        jle      L_214f
        mov      dword ptr [g_dispatchSave1394], ecx
    L_214f:
        mov      ecx, dword ptr [g_dispatchSave1403]
        mov      ebx, dword ptr [g_dispatchSave1400]
        and      ecx, 0xf
        mov      edi, dword ptr [g_viewportX]
        shl      ecx, 0x11
        add      ecx, ebx
        mov      dword ptr [g_dispatchSave1366], eax
        mov      dword ptr [g_dispatchSave1404], ecx
        mov      ecx, dword ptr [g_viewportY]
        imul     ecx, edx
        add      ecx, edi
        mov      dword ptr [g_dispatchSave1385], esi
        mov      dword ptr [g_dispatchSave1346], ecx
        mov      ecx, dword ptr [g_dispatchSave1394]
        cmp      edx, ecx
        mov      dword ptr [g_dispatchSave1364], esi
        jge      L_2641
        jmp      L_21ac
    L_21a1:
        mov      edx, dword ptr [g_dispatchSave1365]
        mov      eax, dword ptr [g_dispatchSave1359]
    L_21ac:
        cmp      esi, edx
        jg       L_22c7
        jmp      L_21bb
    L_21b6:
        mov      eax, dword ptr [g_dispatchSave1359]
    L_21bb:
        lea      esi, [eax - 1]
        test     esi, esi
        jge      L_21c7
        mov      esi, 2
    L_21c7:
        mov      ebx, dword ptr [esi*4 + g_dispatchSave1381]
        mov      edi, dword ptr [eax*4 + g_dispatchSave1381]
        mov      ecx, ebx
        sub      ecx, edi
        je       L_2240
        mov      edx, dword ptr [g_dispatchSave1359]
        mov      eax, dword ptr [esi*4 + g_dispatchSave1378]
        mov      ebp, dword ptr [edx*4 + g_dispatchSave1378]
        sub      eax, ebp
        mov      ebp, dword ptr [g_dispatchSave1359]
        shl      eax, 0x10
        cdq
        idiv     ecx
        mov      edx, dword ptr [ebp*4 + g_dispatchSave1371]
        mov      dword ptr [g_dispatchSave1338], eax
        mov      eax, dword ptr [esi*4 + g_dispatchSave1371]
        sub      eax, edx
        shl      eax, 0x10
        cdq
        idiv     ecx
        mov      edx, dword ptr [ebp*4 + g_dispatchSave1374]
        mov      dword ptr [g_dispatchSave1336], eax
        mov      eax, dword ptr [esi*4 + g_dispatchSave1374]
        sub      eax, edx
        shl      eax, 0x10
        cdq
        idiv     ecx
        mov      edx, dword ptr [g_dispatchSave1365]
        mov      dword ptr [g_dispatchSave1337], eax
        mov      eax, ebp
    L_2240:
        mov      ecx, dword ptr [eax*4 + g_dispatchSave1378]
        mov      ebp, dword ptr [eax*4 + g_dispatchSave1371]
        mov      eax, dword ptr [eax*4 + g_dispatchSave1374]
        shl      eax, 0x10
        mov      dword ptr [g_dispatchSave1362], eax
        mov      eax, edx
        shl      ecx, 0x10
        shl      ebp, 0x10
        sub      eax, edi
        mov      dword ptr [g_dispatchSave1363], ecx
        mov      dword ptr [g_dispatchSave1361], ebp
        mov      dword ptr [g_clipMaxScratch], eax
        je       L_22b1
        mov      edi, eax
        imul     edi, dword ptr [g_dispatchSave1338]
        add      ecx, edi
        mov      dword ptr [g_dispatchSave1363], ecx
        mov      ecx, eax
        imul     ecx, dword ptr [g_dispatchSave1336]
        imul     eax, dword ptr [g_dispatchSave1337]
        add      ebp, ecx
        mov      ecx, dword ptr [g_dispatchSave1362]
        add      ecx, eax
        mov      dword ptr [g_dispatchSave1361], ebp
        mov      dword ptr [g_dispatchSave1362], ecx
    L_22b1:
        cmp      ebx, edx
        mov      dword ptr [g_dispatchSave1359], esi
        mov      dword ptr [g_dispatchSave1364], ebx
        jle      L_21b6
        jmp      L_22cd
    L_22c7:
        mov      ebp, dword ptr [g_dispatchSave1361]
    L_22cd:
        cmp      dword ptr [g_dispatchSave1385], edx
        jg       L_2364
    L_22d9:
        mov      eax, dword ptr [g_dispatchSave1366]
        lea      esi, [eax + 1]
        cmp      esi, 2
        jle      L_22e8
        xor      esi, esi
    L_22e8:
        mov      ebx, dword ptr [esi*4 + g_dispatchSave1381]
        mov      edi, dword ptr [eax*4 + g_dispatchSave1381]
        mov      ecx, ebx
        sub      ecx, edi
        je       L_2326
        mov      edx, dword ptr [g_dispatchSave1366]
        mov      eax, dword ptr [esi*4 + g_dispatchSave1378]
        sub      eax, dword ptr [edx*4 + g_dispatchSave1378]
        shl      eax, 0x10
        cdq
        idiv     ecx
        mov      edx, dword ptr [g_dispatchSave1365]
        mov      dword ptr [g_dispatchSave1339], eax
        mov      eax, dword ptr [g_dispatchSave1366]
    L_2326:
        mov      ecx, dword ptr [eax*4 + g_dispatchSave1378]
        mov      eax, edx
        shl      ecx, 0x10
        sub      eax, edi
        mov      dword ptr [g_dispatchSave1384], ecx
        mov      dword ptr [g_clipMaxScratch], eax
        je       L_2350
        imul     eax, dword ptr [g_dispatchSave1339]
        add      ecx, eax
        mov      dword ptr [g_dispatchSave1384], ecx
    L_2350:
        cmp      ebx, edx
        mov      dword ptr [g_dispatchSave1366], esi
        mov      dword ptr [g_dispatchSave1385], ebx
        jle      L_22d9
    L_2364:
        mov      eax, dword ptr [g_dispatchSave1385]
        mov      esi, dword ptr [g_dispatchSave1364]
        cmp      esi, eax
        jge      L_2375
        mov      eax, esi
    L_2375:
        mov      ecx, dword ptr [g_dispatchSave1394]
        mov      ebx, eax
        sub      ebx, edx
        cmp      eax, ecx
        mov      dword ptr [g_clipMinScratch], eax
        mov      dword ptr [g_dispatchSave1393], ebx
        mov      dword ptr [g_dispatchSave1365], eax
        jle      L_239f
        mov      edx, ecx
        sub      edx, eax
        add      ebx, edx
        mov      dword ptr [g_dispatchSave1393], ebx
    L_239f:
        test     ebx, ebx
        jle      L_2635
    L_23a7:
        mov      ecx, dword ptr [g_dispatchSave1384]
        mov      eax, dword ptr [g_dispatchSave1363]
        sar      ecx, 0x10
        sar      eax, 0x10
        mov      edi, ecx
        mov      dword ptr [g_dispatchSave1370], ecx
        sub      edi, eax
        mov      dword ptr [g_clipMinScratch], eax
        test     edi, edi
        mov      dword ptr [g_clipMaxScratch], edi
        jle      L_25bf
        test     ecx, ecx
        jl       L_25bf
        mov      ecx, dword ptr [g_viewportW]
        cmp      eax, ecx
        jge      L_25bf
        mov      esi, dword ptr [g_dispatchSave1362]
        add      edi, eax
        test     eax, eax
        mov      dword ptr [g_dispatchSave1387], ebp
        mov      dword ptr [g_dispatchSave1389], esi
        mov      dword ptr [g_clipMaxScratch], edi
        jge      L_2433
        mov      esi, eax
        imul     eax, dword ptr [g_dispatchSave1343]
        imul     esi, dword ptr [g_dispatchSave1342]
        mov      edx, ebp
        sub      edx, esi
        mov      esi, dword ptr [g_dispatchSave1362]
        sub      esi, eax
        mov      dword ptr [g_dispatchSave1387], edx
        mov      dword ptr [g_dispatchSave1389], esi
        xor      eax, eax
    L_2433:
        mov      edx, dword ptr [g_dispatchSave1346]
        cmp      edi, ecx
        lea      edx, [edx + eax*2]
        mov      dword ptr [g_dispatchSave1345], edx
        jle      L_244e
        mov      edi, ecx
        mov      dword ptr [g_clipMaxScratch], edi
    L_244e:
        sub      edi, eax
        test     edi, edi
        mov      dword ptr [g_clipMinScratch], edi
        jle      L_25bf
        mov      eax, dword ptr [g_texturedTriVar]
        test     eax, eax
        je       L_251a
    L_246b:
        mov      ebx, dword ptr [g_dispatchSave1404]
        xor      ecx, ecx
        mov      ch, byte ptr [g_dispatchSave1388]
        mov      eax, esi
        and      eax, 0xff0000
        or       ecx, eax
        xor      eax, eax
        sar      ecx, 8
        mov      ax, word ptr [ebx + ecx*2]
        test     ax, ax
        je       L_24dc
        mov      cx, word ptr [edx]
        and      eax, 0xf7de
        and      ecx, 0xf7de
        add      eax, ecx
        mov      ecx, eax
        and      eax, 0x10820
        mov      edi, eax
        mov      esi, eax
        shr      edi, 1
        and      esi, 0xffff00ff
        and      edi, 0x7f80
        or       esi, edi
        shr      esi, 5
        sub      eax, esi
        or       eax, ecx
        and      eax, 0xf7de
        mov      word ptr [edx], ax
        mov      edi, dword ptr [g_clipMinScratch]
        mov      esi, dword ptr [g_dispatchSave1389]
        mov      edx, dword ptr [g_dispatchSave1345]
    L_24dc:
        mov      eax, dword ptr [g_dispatchSave1342]
        mov      ebp, dword ptr [g_dispatchSave1387]
        mov      ebx, dword ptr [g_dispatchSave1343]
        dec      edi
        add      ebp, eax
        add      esi, ebx
        add      edx, 2
        mov      dword ptr [g_clipMinScratch], edi
        test     edi, edi
        mov      dword ptr [g_dispatchSave1387], ebp
        mov      dword ptr [g_dispatchSave1389], esi
        mov      dword ptr [g_dispatchSave1345], edx
        jg       L_246b
        jmp      L_25b3
    L_251a:
        mov      ebx, dword ptr [g_dispatchSave1404]
        xor      ecx, ecx
        mov      ch, byte ptr [g_dispatchSave1388]
        mov      eax, esi
        and      eax, 0xff0000
        or       ecx, eax
        xor      eax, eax
        sar      ecx, 8
        mov      ax, word ptr [ebx + ecx*2]
        test     ax, ax
        je       L_2579
        mov      cx, word ptr [edx]
        and      eax, 0x7bde
        and      ecx, 0x7bde
        add      ecx, eax
        mov      eax, ecx
        and      eax, 0x8420
        mov      esi, eax
        shr      esi, 5
        sub      eax, esi
        or       eax, ecx
        and      eax, 0x7bde
        mov      word ptr [edx], ax
        mov      edi, dword ptr [g_clipMinScratch]
        mov      esi, dword ptr [g_dispatchSave1389]
        mov      edx, dword ptr [g_dispatchSave1345]
    L_2579:
        mov      ecx, dword ptr [g_dispatchSave1342]
        mov      ebp, dword ptr [g_dispatchSave1387]
        mov      ebx, dword ptr [g_dispatchSave1343]
        dec      edi
        add      ebp, ecx
        add      esi, ebx
        add      edx, 2
        mov      dword ptr [g_clipMinScratch], edi
        test     edi, edi
        mov      dword ptr [g_dispatchSave1387], ebp
        mov      dword ptr [g_dispatchSave1389], esi
        mov      dword ptr [g_dispatchSave1345], edx
        jg       L_251a
    L_25b3:
        mov      ebx, dword ptr [g_dispatchSave1393]
        mov      ebp, dword ptr [g_dispatchSave1361]
    L_25bf:
        mov      edx, dword ptr [g_viewportY]
        mov      eax, dword ptr [g_dispatchSave1346]
        mov      ecx, dword ptr [g_dispatchSave1339]
        mov      esi, dword ptr [g_dispatchSave1384]
        mov      edi, dword ptr [g_dispatchSave1363]
        add      eax, edx
        mov      edx, dword ptr [g_dispatchSave1336]
        mov      dword ptr [g_dispatchSave1346], eax
        mov      eax, dword ptr [g_dispatchSave1338]
        add      esi, ecx
        mov      ecx, dword ptr [g_dispatchSave1362]
        add      ebp, edx
        mov      edx, dword ptr [g_dispatchSave1337]
        dec      ebx
        add      edi, eax
        add      ecx, edx
        test     ebx, ebx
        mov      dword ptr [g_dispatchSave1393], ebx
        mov      dword ptr [g_dispatchSave1363], edi
        mov      dword ptr [g_dispatchSave1384], esi
        mov      dword ptr [g_dispatchSave1361], ebp
        mov      dword ptr [g_dispatchSave1362], ecx
        jg       L_23a7
        mov      ecx, dword ptr [g_dispatchSave1394]
        mov      esi, dword ptr [g_dispatchSave1364]
    L_2635:
        cmp      dword ptr [g_dispatchSave1365], ecx
        jl       L_21a1
    L_2641:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    }
}
#endif
