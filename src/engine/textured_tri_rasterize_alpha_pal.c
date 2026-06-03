/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel;
extern unsigned int g_acc_00542078;
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
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
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
