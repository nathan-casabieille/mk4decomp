/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown;
extern unsigned int g_xformScratch94;
extern unsigned int g_table_00535ddc;
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
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
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
extern void DispatcherComplex260_00407030(void);
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
extern void PendingMatch_0042b930(void);
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
extern void MStackPushZeroCallPop_00407d00(void);
extern void DirtyToggleByGate(void);
extern void GameDispatchValidateState(void);
extern void CrouchAttackFsmCluster(void);
extern void MStackPushVec3Mul10(void);
extern void LiteralPushCallEntZero(void);
extern void LeaPlus22StoreSelf(void);
extern void IterLoad_00491050(void);
extern void GuardedDualConst2AndToggle(void);
extern void CallPauseScaledStorePushCall(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_00407400(void);
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
extern unsigned int g_dispatchSave1335;
extern unsigned int g_dispatchSave1336;
extern unsigned int g_dispatchSave1337;
extern unsigned int g_dispatchSave1338;
extern unsigned int g_dispatchSave1339;
extern unsigned int g_dispatchSave1340;
extern unsigned int g_dispatchSave1341;
extern unsigned int g_dispatchSave1342;
extern unsigned int g_dispatchSave1343;
extern unsigned int g_dispatchSave1345;
extern unsigned int g_dispatchSave1346;
extern unsigned int g_dispatchSave1359;
extern unsigned int g_dispatchSave1360;
extern unsigned int g_dispatchSave1361;
extern unsigned int g_dispatchSave1362;
extern unsigned int g_dispatchSave1363;
extern unsigned int g_dispatchSave1364;
extern unsigned int g_dispatchSave1365;
extern s32 g_clipMinScratch;
extern unsigned int g_dispatchSave1366;
extern s32 g_clipMaxScratch;
extern unsigned int g_dispatchSave1367;
extern unsigned int g_dispatchSave1368;
extern unsigned int g_dispatchSave1369;
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
extern unsigned int g_dispatchSave1386;
extern unsigned int g_dispatchSave1387;
extern unsigned int g_dispatchSave1389;
extern unsigned int g_dispatchSave1390;
extern unsigned int g_dispatchSave1393;
extern unsigned int g_dispatchSave1394;
extern unsigned int g_dispatchSave1400;
extern unsigned int g_dispatchSave1403;
extern unsigned int g_viewportX;
extern unsigned int g_viewportY;
extern unsigned int g_dispatchSave1404;

__declspec(naked) void TexturedTriRasterizeShaded(void)
{
    __asm {
        push     ebp
        mov      ebp, esp
        sub      esp, 8
        mov      eax, dword ptr [g_viewportX]
        push     ebx
        push     esi
        push     edi
        test     eax, eax
        je       L_334f
        mov      edi, dword ptr [g_dispatchSave1383]
        mov      eax, dword ptr [g_dispatchSave1381]
        mov      ebx, dword ptr [g_dispatchSave1382]
        mov      edx, dword ptr [g_dispatchSave1380]
        mov      ecx, dword ptr [g_dispatchSave1379]
        sub      edi, eax
        sub      ebx, eax
        mov      eax, dword ptr [g_dispatchSave1378]
        sub      edx, eax
        sub      ecx, eax
        imul     edx, ebx
        imul     ecx, edi
        sub      ecx, edx
        test     ecx, ecx
        mov      dword ptr [g_clipMinScratch], ecx
        jle      L_334f
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
        jge      L_2d3e
        shl      eax, 0xc
        cdq
        idiv     ecx
        shl      eax, 4
        jmp      L_2d47
    L_2d3e:
        shl      eax, 9
        cdq
        idiv     ecx
        shl      eax, 7
    L_2d47:
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
        jge      L_2d84
        shl      eax, 0xc
        cdq
        idiv     ecx
        shl      eax, 4
        jmp      L_2d8d
    L_2d84:
        shl      eax, 9
        cdq
        idiv     ecx
        shl      eax, 7
    L_2d8d:
        mov      dword ptr [g_dispatchSave1343], eax
        mov      eax, dword ptr [g_dispatchSave1367]
        xor      edx, edx
        and      eax, 0xff
        mov      dl, byte ptr [g_dispatchSave1369]
        sub      edx, eax
        imul     edx, ebx
        xor      ebx, ebx
        mov      bl, byte ptr [g_dispatchSave1368]
        mov      esi, ebx
        sub      esi, eax
        imul     esi, edi
        sub      esi, edx
        mov      eax, esi
        cdq
        xor      eax, edx
        sub      eax, edx
        cmp      eax, 0x80000
        mov      eax, esi
        jge      L_2dd5
        shl      eax, 0xc
        cdq
        idiv     ecx
        shl      eax, 4
        jmp      L_2dde
    L_2dd5:
        shl      eax, 9
        cdq
        idiv     ecx
        shl      eax, 7
    L_2dde:
        mov      ecx, dword ptr [g_dispatchSave1382]
        mov      dword ptr [g_dispatchSave1341], eax
        mov      eax, dword ptr [g_dispatchSave1381]
        xor      edx, edx
        xor      edi, edi
        cmp      ecx, eax
        mov      dword ptr [g_dispatchSave1359], edi
        mov      dword ptr [g_dispatchSave1365], eax
        mov      dword ptr [g_dispatchSave1394], eax
        jge      L_2e1b
        mov      edi, 1
        mov      dword ptr [g_dispatchSave1365], ecx
        mov      dword ptr [g_dispatchSave1359], edi
        mov      eax, ecx
        jmp      L_2e21
    L_2e1b:
        mov      dword ptr [g_dispatchSave1394], ecx
    L_2e21:
        mov      ecx, dword ptr [g_dispatchSave1383]
        cmp      ecx, eax
        jge      L_2e3e
        mov      edi, 2
        mov      dword ptr [g_dispatchSave1365], ecx
        mov      dword ptr [g_dispatchSave1359], edi
        mov      eax, ecx
    L_2e3e:
        cmp      ecx, dword ptr [g_dispatchSave1394]
        jle      L_2e4c
        mov      dword ptr [g_dispatchSave1394], ecx
    L_2e4c:
        cmp      eax, edx
        jge      L_2e58
        mov      dword ptr [g_dispatchSave1365], edx
        mov      eax, edx
    L_2e58:
        mov      ecx, dword ptr [g_viewportH]
        mov      esi, dword ptr [g_dispatchSave1394]
        cmp      esi, ecx
        jle      L_2e6e
        mov      dword ptr [g_dispatchSave1394], ecx
    L_2e6e:
        mov      ecx, dword ptr [g_dispatchSave1403]
        mov      ebx, dword ptr [g_dispatchSave1400]
        and      ecx, 0xf
        mov      esi, dword ptr [g_viewportX]
        shl      ecx, 0x11
        add      ecx, ebx
        mov      dword ptr [g_dispatchSave1366], edi
        mov      dword ptr [g_dispatchSave1404], ecx
        mov      ecx, dword ptr [g_viewportY]
        imul     ecx, eax
        add      ecx, esi
        mov      dword ptr [g_dispatchSave1385], edx
        mov      dword ptr [g_dispatchSave1346], ecx
        mov      ecx, dword ptr [g_dispatchSave1394]
        cmp      eax, ecx
        mov      dword ptr [g_dispatchSave1364], edx
        jge      L_334f
        mov      ebx, dword ptr [g_dispatchSave1361]
        jmp      L_2ecc
    L_2ec7:
        mov      eax, dword ptr [g_dispatchSave1365]
    L_2ecc:
        cmp      dword ptr [g_dispatchSave1364], eax
        jg       L_3023
    L_2ed8:
        lea      esi, [edi - 1]
        test     esi, esi
        jge      L_2ee4
        mov      esi, 2
    L_2ee4:
        mov      ecx, dword ptr [esi*4 + g_dispatchSave1381]
        mov      eax, dword ptr [edi*4 + g_dispatchSave1381]
        mov      dword ptr [ebp - 4], ecx
        sub      ecx, eax
        mov      dword ptr [ebp - 8], eax
        je       L_2f6a
        mov      eax, dword ptr [esi*4 + g_dispatchSave1378]
        mov      ebx, dword ptr [edi*4 + g_dispatchSave1378]
        sub      eax, ebx
        mov      ebx, dword ptr [edi*4 + g_dispatchSave1371]
        shl      eax, 0x10
        cdq
        idiv     ecx
        mov      dword ptr [g_dispatchSave1338], eax
        mov      eax, dword ptr [esi*4 + g_dispatchSave1371]
        sub      eax, ebx
        mov      ebx, dword ptr [edi*4 + g_dispatchSave1374]
        shl      eax, 0x10
        cdq
        idiv     ecx
        mov      dword ptr [g_dispatchSave1336], eax
        mov      eax, dword ptr [esi*4 + g_dispatchSave1374]
        sub      eax, ebx
        shl      eax, 0x10
        cdq
        idiv     ecx
        xor      edx, edx
        mov      dl, byte ptr [edi + g_dispatchSave1367]
        mov      dword ptr [g_dispatchSave1337], eax
        xor      eax, eax
        mov      al, byte ptr [esi + g_dispatchSave1367]
        sub      eax, edx
        shl      eax, 0x10
        cdq
        idiv     ecx
        mov      dword ptr [g_dispatchSave1335], eax
    L_2f6a:
        mov      edx, dword ptr [edi*4 + g_dispatchSave1378]
        mov      ebx, dword ptr [edi*4 + g_dispatchSave1371]
        mov      ecx, dword ptr [edi*4 + g_dispatchSave1374]
        xor      eax, eax
        mov      al, byte ptr [edi + g_dispatchSave1367]
        mov      edi, dword ptr [ebp - 8]
        shl      eax, 0x10
        mov      dword ptr [g_dispatchSave1360], eax
        mov      eax, dword ptr [g_dispatchSave1365]
        shl      edx, 0x10
        shl      ebx, 0x10
        shl      ecx, 0x10
        sub      eax, edi
        mov      dword ptr [g_dispatchSave1363], edx
        mov      dword ptr [g_dispatchSave1361], ebx
        mov      dword ptr [g_dispatchSave1362], ecx
        mov      dword ptr [g_clipMaxScratch], eax
        je       L_3003
        mov      edi, eax
        imul     edi, dword ptr [g_dispatchSave1338]
        add      edx, edi
        mov      dword ptr [g_dispatchSave1363], edx
        mov      edx, eax
        imul     edx, dword ptr [g_dispatchSave1336]
        add      ebx, edx
        mov      edx, eax
        imul     edx, dword ptr [g_dispatchSave1337]
        imul     eax, dword ptr [g_dispatchSave1335]
        add      ecx, edx
        mov      dword ptr [g_dispatchSave1361], ebx
        mov      dword ptr [g_dispatchSave1362], ecx
        mov      ecx, dword ptr [g_dispatchSave1360]
        add      ecx, eax
        mov      dword ptr [g_dispatchSave1360], ecx
    L_3003:
        mov      eax, dword ptr [ebp - 4]
        mov      ecx, dword ptr [g_dispatchSave1365]
        cmp      eax, ecx
        mov      edi, esi
        mov      dword ptr [g_dispatchSave1364], eax
        jle      L_2ed8
        mov      dword ptr [g_dispatchSave1359], edi
        mov      eax, ecx
    L_3023:
        cmp      dword ptr [g_dispatchSave1385], eax
        jg       L_30ca
    L_302f:
        mov      edx, dword ptr [g_dispatchSave1366]
        lea      ecx, [edx + 1]
        cmp      ecx, 2
        jle      L_303f
        xor      ecx, ecx
    L_303f:
        mov      esi, dword ptr [ecx*4 + g_dispatchSave1381]
        mov      edx, dword ptr [edx*4 + g_dispatchSave1381]
        mov      dword ptr [ebp - 4], esi
        sub      esi, edx
        mov      dword ptr [ebp - 8], edx
        je       L_307e
        mov      edx, dword ptr [g_dispatchSave1366]
        mov      eax, dword ptr [ecx*4 + g_dispatchSave1378]
        sub      eax, dword ptr [edx*4 + g_dispatchSave1378]
        shl      eax, 0x10
        cdq
        idiv     esi
        mov      edx, dword ptr [ebp - 8]
        mov      dword ptr [g_dispatchSave1339], eax
        mov      eax, dword ptr [g_dispatchSave1365]
    L_307e:
        mov      esi, dword ptr [g_dispatchSave1366]
        mov      esi, dword ptr [esi*4 + g_dispatchSave1378]
        shl      esi, 0x10
        sub      eax, edx
        mov      dword ptr [g_dispatchSave1384], esi
        mov      dword ptr [g_clipMaxScratch], eax
        je       L_30ac
        imul     eax, dword ptr [g_dispatchSave1339]
        add      esi, eax
        mov      dword ptr [g_dispatchSave1384], esi
    L_30ac:
        mov      eax, dword ptr [g_dispatchSave1365]
        mov      dword ptr [g_dispatchSave1366], ecx
        mov      ecx, dword ptr [ebp - 4]
        cmp      ecx, eax
        mov      dword ptr [g_dispatchSave1385], ecx
        jle      L_302f
        jmp      L_30d0
    L_30ca:
        mov      esi, dword ptr [g_dispatchSave1384]
    L_30d0:
        mov      ecx, dword ptr [g_dispatchSave1364]
        mov      edx, dword ptr [g_dispatchSave1385]
        cmp      ecx, edx
        jge      L_30e2
        mov      edx, ecx
    L_30e2:
        mov      ecx, edx
        mov      dword ptr [g_clipMinScratch], edx
        sub      ecx, eax
        mov      eax, dword ptr [g_dispatchSave1394]
        cmp      edx, eax
        mov      dword ptr [g_dispatchSave1393], ecx
        mov      dword ptr [g_dispatchSave1365], edx
        jle      L_310b
        sub      eax, edx
        add      ecx, eax
        mov      dword ptr [g_dispatchSave1393], ecx
    L_310b:
        test     ecx, ecx
        jle      L_333c
    L_3113:
        mov      eax, dword ptr [g_dispatchSave1363]
        mov      edx, esi
        sar      edx, 0x10
        sar      eax, 0x10
        mov      ecx, edx
        mov      dword ptr [g_dispatchSave1370], edx
        sub      ecx, eax
        mov      dword ptr [g_clipMinScratch], eax
        test     ecx, ecx
        mov      dword ptr [g_clipMaxScratch], ecx
        jle      L_32bd
        test     edx, edx
        jl       L_32bd
        cmp      eax, dword ptr [g_viewportW]
        jge      L_32bd
        mov      edx, dword ptr [g_dispatchSave1362]
        add      ecx, eax
        mov      dword ptr [g_dispatchSave1389], edx
        mov      edx, dword ptr [g_dispatchSave1360]
        test     eax, eax
        mov      dword ptr [g_dispatchSave1387], ebx
        mov      dword ptr [g_dispatchSave1386], edx
        mov      dword ptr [g_clipMaxScratch], ecx
        jge      L_31c2
        mov      edx, eax
        mov      esi, ebx
        imul     edx, dword ptr [g_dispatchSave1342]
        sub      esi, edx
        mov      edx, eax
        imul     edx, dword ptr [g_dispatchSave1343]
        imul     eax, dword ptr [g_dispatchSave1341]
        mov      dword ptr [g_dispatchSave1387], esi
        mov      esi, dword ptr [g_dispatchSave1362]
        sub      esi, edx
        mov      edx, dword ptr [g_dispatchSave1360]
        sub      edx, eax
        mov      dword ptr [g_dispatchSave1389], esi
        mov      esi, dword ptr [g_dispatchSave1384]
        mov      dword ptr [g_dispatchSave1386], edx
        xor      eax, eax
    L_31c2:
        mov      edx, dword ptr [g_dispatchSave1346]
        lea      edx, [edx + eax*2]
        mov      dword ptr [g_dispatchSave1345], edx
        mov      edx, dword ptr [g_viewportW]
        cmp      ecx, edx
        jle      L_31e3
        mov      ecx, edx
        mov      dword ptr [g_clipMaxScratch], ecx
    L_31e3:
        sub      ecx, eax
        test     ecx, ecx
        mov      dword ptr [g_clipMinScratch], ecx
        jle      L_32bd
        push     ebp
        mov      ebx, dword ptr [g_dispatchSave1342]
        shl      ebx, 0x10
        mov      ecx, dword ptr [g_dispatchSave1387]
        shl      ecx, 0x10
        mov      eax, dword ptr [g_dispatchSave1343]
        shr      eax, 0x10
        mov      ch, al
        mov      eax, dword ptr [g_dispatchSave1342]
        shr      eax, 0x10
        mov      cl, al
        mov      edx, dword ptr [g_dispatchSave1404]
        shr      edx, 1
        mov      eax, dword ptr [g_dispatchSave1389]
        shr      eax, 0x10
        mov      dh, al
        mov      eax, dword ptr [g_dispatchSave1387]
        shr      eax, 0x10
        mov      dl, al
        mov      ebp, dword ptr [g_dispatchSave1343]
        shl      ebp, 0x10
        mov      edi, dword ptr [g_dispatchSave1345]
        mov      esi, dword ptr [g_dispatchSave1389]
        shl      esi, 0x10
        mov      eax, dword ptr [g_clipMinScratch]
        mov      si, ax
        mov      eax, dword ptr [g_dispatchSave1341]
        sar      eax, 4
        mov      dword ptr [g_dispatchSave1390], eax
        mov      eax, dword ptr [g_dispatchSave1386]
        shr      eax, 3
        add      eax, dword ptr [g_dispatchSave1340]
        shr      eax, 1
    L_3273:
        mov      bx, ax
        mov      ax, word ptr [edx*2]
        test     ax, ax
        je       L_328e
        mov      ax, word ptr [eax*2]
        mov      word ptr [edi], ax
    L_328e:
        mov      ax, bx
        mov      bx, 0
        add      esi, ebp
        adc      dh, ch
        add      ecx, ebx
        adc      dl, cl
        add      eax, dword ptr [g_dispatchSave1390]
        add      edi, 2
        dec      si
        jg       L_3273
        pop      ebp
        mov      edi, dword ptr [g_dispatchSave1359]
        mov      ebx, dword ptr [g_dispatchSave1361]
        mov      esi, dword ptr [g_dispatchSave1384]
    L_32bd:
        mov      ecx, dword ptr [g_viewportY]
        mov      edx, dword ptr [g_dispatchSave1346]
        add      edx, ecx
        mov      ecx, dword ptr [g_dispatchSave1363]
        mov      dword ptr [g_dispatchSave1346], edx
        mov      edx, dword ptr [g_dispatchSave1338]
        add      ecx, edx
        mov      edx, dword ptr [g_dispatchSave1339]
        mov      eax, dword ptr [g_dispatchSave1393]
        mov      dword ptr [g_dispatchSave1363], ecx
        mov      ecx, dword ptr [g_dispatchSave1336]
        add      esi, edx
        mov      edx, dword ptr [g_dispatchSave1362]
        add      ebx, ecx
        mov      ecx, dword ptr [g_dispatchSave1337]
        dec      eax
        add      edx, ecx
        mov      ecx, dword ptr [g_dispatchSave1360]
        mov      dword ptr [g_dispatchSave1362], edx
        mov      edx, dword ptr [g_dispatchSave1335]
        add      ecx, edx
        mov      dword ptr [g_dispatchSave1393], eax
        test     eax, eax
        mov      dword ptr [g_dispatchSave1384], esi
        mov      dword ptr [g_dispatchSave1361], ebx
        mov      dword ptr [g_dispatchSave1360], ecx
        jg       L_3113
    L_333c:
        mov      eax, dword ptr [g_dispatchSave1394]
        mov      ecx, dword ptr [g_dispatchSave1365]
        cmp      ecx, eax
        jl       L_2ec7
    L_334f:
        pop      edi
        pop      esi
        pop      ebx
        mov      esp, ebp
        pop      ebp
        ret
    }
}
