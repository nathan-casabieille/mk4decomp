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
extern unsigned int g_dispatchSave1389;
extern unsigned int g_dispatchSave1393;
extern unsigned int g_dispatchSave1394;
extern unsigned int g_dispatchSave1400;
extern unsigned int g_dispatchSave1403;
extern unsigned int g_viewportX;
extern unsigned int g_viewportY;
extern unsigned int g_dispatchSave1404;

__declspec(naked) void TexturedTriRasterizeAlpha(void)
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
        je       L_1fcb
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
        jle      L_1fcb
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
        jge      L_1a4e
        shl      eax, 0xc
        cdq
        idiv     ecx
        shl      eax, 4
        jmp      L_1a57
    L_1a4e:
        shl      eax, 9
        cdq
        idiv     ecx
        shl      eax, 7
    L_1a57:
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
        jge      L_1a94
        shl      eax, 0xc
        cdq
        idiv     ecx
        shl      eax, 4
        jmp      L_1a9d
    L_1a94:
        shl      eax, 9
        cdq
        idiv     ecx
        shl      eax, 7
    L_1a9d:
        mov      ecx, dword ptr [g_dispatchSave1381]
        mov      dword ptr [g_dispatchSave1343], eax
        mov      eax, dword ptr [g_dispatchSave1382]
        xor      esi, esi
        xor      edx, edx
        cmp      eax, ecx
        mov      dword ptr [g_dispatchSave1359], edx
        mov      dword ptr [g_dispatchSave1365], ecx
        mov      dword ptr [g_dispatchSave1394], ecx
        jge      L_1ae0
        mov      dword ptr [g_dispatchSave1359], 1
        mov      edx, dword ptr [g_dispatchSave1359]
        mov      dword ptr [g_dispatchSave1365], eax
        mov      ecx, eax
        jmp      L_1ae5
    L_1ae0:
        mov      dword ptr [g_dispatchSave1394], eax
    L_1ae5:
        mov      eax, dword ptr [g_dispatchSave1383]
        cmp      eax, ecx
        jge      L_1b05
        mov      dword ptr [g_dispatchSave1359], 2
        mov      edx, dword ptr [g_dispatchSave1359]
        mov      dword ptr [g_dispatchSave1365], eax
        mov      ecx, eax
    L_1b05:
        cmp      eax, dword ptr [g_dispatchSave1394]
        jle      L_1b12
        mov      dword ptr [g_dispatchSave1394], eax
    L_1b12:
        cmp      ecx, esi
        jge      L_1b1e
        mov      dword ptr [g_dispatchSave1365], esi
        mov      ecx, esi
    L_1b1e:
        mov      eax, dword ptr [g_viewportH]
        mov      edi, dword ptr [g_dispatchSave1394]
        cmp      edi, eax
        jle      L_1b32
        mov      dword ptr [g_dispatchSave1394], eax
    L_1b32:
        mov      eax, dword ptr [g_dispatchSave1403]
        mov      ebx, dword ptr [g_dispatchSave1400]
        and      eax, 0xf
        mov      edi, dword ptr [g_viewportX]
        shl      eax, 0x11
        add      eax, ebx
        mov      dword ptr [g_dispatchSave1366], edx
        mov      dword ptr [g_dispatchSave1404], eax
        mov      eax, dword ptr [g_viewportY]
        imul     eax, ecx
        add      eax, edi
        mov      dword ptr [g_dispatchSave1385], esi
        mov      dword ptr [g_dispatchSave1346], eax
        mov      eax, dword ptr [g_dispatchSave1394]
        cmp      ecx, eax
        mov      dword ptr [g_dispatchSave1364], esi
        jge      L_1fcb
        mov      edi, dword ptr [g_dispatchSave1361]
        mov      ebx, dword ptr [g_dispatchSave1362]
        jmp      L_1b92
    L_1b8c:
        mov      ecx, dword ptr [g_dispatchSave1365]
    L_1b92:
        cmp      dword ptr [g_dispatchSave1364], ecx
        jg       L_1cb0
    L_1b9e:
        lea      esi, [edx - 1]
        test     esi, esi
        jge      L_1baa
        mov      esi, 2
    L_1baa:
        mov      ecx, dword ptr [esi*4 + g_dispatchSave1381]
        mov      eax, dword ptr [edx*4 + g_dispatchSave1381]
        mov      dword ptr [ebp - 4], ecx
        sub      ecx, eax
        mov      dword ptr [ebp - 8], eax
        je       L_1c1b
        mov      eax, dword ptr [esi*4 + g_dispatchSave1378]
        mov      edi, dword ptr [edx*4 + g_dispatchSave1378]
        sub      eax, edi
        mov      edi, dword ptr [g_dispatchSave1359]
        shl      eax, 0x10
        cdq
        idiv     ecx
        mov      ebx, dword ptr [edi*4 + g_dispatchSave1371]
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
        mov      edx, edi
        mov      dword ptr [g_dispatchSave1337], eax
    L_1c1b:
        mov      eax, dword ptr [edx*4 + g_dispatchSave1378]
        mov      edi, dword ptr [edx*4 + g_dispatchSave1371]
        mov      ebx, dword ptr [edx*4 + g_dispatchSave1374]
        mov      ecx, dword ptr [ebp - 8]
        shl      eax, 0x10
        mov      dword ptr [g_dispatchSave1363], eax
        mov      eax, dword ptr [g_dispatchSave1365]
        shl      edi, 0x10
        shl      ebx, 0x10
        sub      eax, ecx
        mov      dword ptr [g_dispatchSave1361], edi
        mov      dword ptr [g_dispatchSave1362], ebx
        mov      dword ptr [g_clipMaxScratch], eax
        je       L_1c92
        mov      ecx, eax
        mov      edx, dword ptr [g_dispatchSave1363]
        imul     ecx, dword ptr [g_dispatchSave1338]
        add      edx, ecx
        mov      dword ptr [g_dispatchSave1363], edx
        mov      edx, eax
        imul     edx, dword ptr [g_dispatchSave1336]
        imul     eax, dword ptr [g_dispatchSave1337]
        add      edi, edx
        add      ebx, eax
        mov      dword ptr [g_dispatchSave1361], edi
        mov      dword ptr [g_dispatchSave1362], ebx
    L_1c92:
        mov      eax, dword ptr [ebp - 4]
        mov      ecx, dword ptr [g_dispatchSave1365]
        cmp      eax, ecx
        mov      dword ptr [g_dispatchSave1359], esi
        mov      dword ptr [g_dispatchSave1364], eax
        mov      edx, esi
        jle      L_1b9e
    L_1cb0:
        cmp      dword ptr [g_dispatchSave1385], ecx
        jg       L_1d69
    L_1cbc:
        mov      eax, dword ptr [g_dispatchSave1366]
        inc      eax
        cmp      eax, 2
        mov      dword ptr [g_clipMinScratch], eax
        jle      L_1cd3
        xor      eax, eax
        mov      dword ptr [g_clipMinScratch], eax
    L_1cd3:
        mov      ecx, dword ptr [g_dispatchSave1366]
        mov      esi, dword ptr [eax*4 + g_dispatchSave1381]
        mov      dword ptr [ebp - 4], esi
        mov      ecx, dword ptr [ecx*4 + g_dispatchSave1381]
        sub      esi, ecx
        je       L_1d13
        mov      edx, dword ptr [g_dispatchSave1366]
        mov      eax, dword ptr [eax*4 + g_dispatchSave1378]
        sub      eax, dword ptr [edx*4 + g_dispatchSave1378]
        shl      eax, 0x10
        cdq
        idiv     esi
        mov      edx, dword ptr [g_dispatchSave1359]
        mov      dword ptr [g_dispatchSave1339], eax
    L_1d13:
        mov      eax, dword ptr [g_dispatchSave1366]
        mov      esi, dword ptr [eax*4 + g_dispatchSave1378]
        mov      eax, dword ptr [g_dispatchSave1365]
        shl      esi, 0x10
        sub      eax, ecx
        mov      dword ptr [g_dispatchSave1384], esi
        mov      dword ptr [g_clipMaxScratch], eax
        je       L_1d45
        imul     eax, dword ptr [g_dispatchSave1339]
        add      esi, eax
        mov      dword ptr [g_dispatchSave1384], esi
    L_1d45:
        mov      ecx, dword ptr [g_clipMinScratch]
        mov      eax, dword ptr [ebp - 4]
        mov      dword ptr [g_dispatchSave1366], ecx
        mov      ecx, dword ptr [g_dispatchSave1365]
        cmp      eax, ecx
        mov      dword ptr [g_dispatchSave1385], eax
        jle      L_1cbc
        jmp      L_1d6f
    L_1d69:
        mov      esi, dword ptr [g_dispatchSave1384]
    L_1d6f:
        mov      eax, dword ptr [g_dispatchSave1364]
        mov      ecx, dword ptr [g_dispatchSave1385]
        cmp      eax, ecx
        jl       L_1d80
        mov      eax, ecx
    L_1d80:
        mov      ecx, dword ptr [g_dispatchSave1365]
        mov      dword ptr [g_clipMinScratch], eax
        sub      eax, ecx
        mov      ecx, dword ptr [g_dispatchSave1394]
        mov      dword ptr [g_dispatchSave1393], eax
        mov      eax, dword ptr [g_clipMinScratch]
        cmp      eax, ecx
        mov      dword ptr [g_dispatchSave1365], eax
        jle      L_1db4
        sub      ecx, eax
        mov      eax, dword ptr [g_dispatchSave1393]
        add      eax, ecx
        mov      dword ptr [g_dispatchSave1393], eax
    L_1db4:
        mov      eax, dword ptr [g_dispatchSave1393]
        test     eax, eax
        jle      L_1fb8
    L_1dc1:
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
        jle      L_1f4d
        test     edx, edx
        jl       L_1f4d
        cmp      eax, dword ptr [g_viewportW]
        jge      L_1f4d
        add      ecx, eax
        mov      dword ptr [g_dispatchSave1387], edi
        test     eax, eax
        mov      dword ptr [g_dispatchSave1389], ebx
        mov      dword ptr [g_clipMaxScratch], ecx
        jge      L_1e43
        mov      edx, eax
        imul     eax, dword ptr [g_dispatchSave1343]
        imul     edx, dword ptr [g_dispatchSave1342]
        mov      esi, edi
        sub      esi, edx
        mov      edx, ebx
        sub      edx, eax
        mov      dword ptr [g_dispatchSave1387], esi
        mov      esi, dword ptr [g_dispatchSave1384]
        mov      dword ptr [g_dispatchSave1389], edx
        xor      eax, eax
    L_1e43:
        mov      edx, dword ptr [g_dispatchSave1346]
        lea      edx, [edx + eax*2]
        mov      dword ptr [g_dispatchSave1345], edx
        mov      edx, dword ptr [g_viewportW]
        cmp      ecx, edx
        jle      L_1e64
        mov      ecx, edx
        mov      dword ptr [g_clipMaxScratch], ecx
    L_1e64:
        sub      ecx, eax
        test     ecx, ecx
        mov      dword ptr [g_clipMinScratch], ecx
        jle      L_1f4d
        push     ebp
        mov      ebx, dword ptr [g_dispatchSave1389]
        shl      ebx, 0x10
        mov      ecx, dword ptr [g_dispatchSave1343]
        rol      ecx, 0x10
        mov      eax, dword ptr [g_dispatchSave1342]
        shr      eax, 8
        mov      ch, ah
        mov      edx, 0
        mov      eax, dword ptr [g_dispatchSave1389]
        shr      eax, 8
        mov      dh, ah
        mov      eax, dword ptr [g_dispatchSave1387]
        shr      eax, 8
        mov      dl, ah
        mov      edi, dword ptr [g_dispatchSave1345]
        mov      esi, dword ptr [g_dispatchSave1404]
        mov      ebp, dword ptr [g_dispatchSave1342]
        shl      ebp, 0x10
        mov      eax, dword ptr [g_clipMinScratch]
        mov      bp, ax
        mov      eax, dword ptr [g_dispatchSave1387]
        shl      eax, 0x10
        cmp      dword ptr [g_texturedTriVar], 0
        jne      L_1f0a
    L_1ed8:
        mov      ax, word ptr [esi + edx*2]
        mov      bx, word ptr [edi]
        test     ax, ax
        je       L_1ef9
        shr      ax, 1
        and      bx, 0x7bde
        shr      bx, 1
        and      ax, 0x3def
        add      ax, bx
        mov      word ptr [edi], ax
    L_1ef9:
        add      ebx, ecx
        adc      dh, cl
        add      eax, ebp
        adc      dl, ch
        add      edi, 2
        dec      bp
        jg       L_1ed8
        jmp      L_1f3a
    L_1f0a:
        mov      ax, word ptr [esi + edx*2]
        mov      bx, word ptr [edi]
        test     ax, ax
        je       L_1f2b
        shr      ax, 1
        and      bx, 0xf7de
        shr      bx, 1
        and      ax, 0x7bef
        add      ax, bx
        mov      word ptr [edi], ax
    L_1f2b:
        add      ebx, ecx
        adc      dh, cl
        add      eax, ebp
        adc      dl, ch
        add      edi, 2
        dec      bp
        jg       L_1f0a
    L_1f3a:
        pop      ebp
        mov      edi, dword ptr [g_dispatchSave1361]
        mov      ebx, dword ptr [g_dispatchSave1362]
        mov      esi, dword ptr [g_dispatchSave1384]
    L_1f4d:
        mov      ecx, dword ptr [g_viewportY]
        mov      edx, dword ptr [g_dispatchSave1346]
        mov      eax, dword ptr [g_dispatchSave1393]
        add      edx, ecx
        mov      ecx, dword ptr [g_dispatchSave1363]
        mov      dword ptr [g_dispatchSave1346], edx
        mov      edx, dword ptr [g_dispatchSave1338]
        dec      eax
        add      ecx, edx
        mov      edx, dword ptr [g_dispatchSave1339]
        mov      dword ptr [g_dispatchSave1363], ecx
        mov      ecx, dword ptr [g_dispatchSave1336]
        add      esi, edx
        mov      edx, dword ptr [g_dispatchSave1337]
        add      edi, ecx
        add      ebx, edx
        test     eax, eax
        mov      dword ptr [g_dispatchSave1393], eax
        mov      dword ptr [g_dispatchSave1384], esi
        mov      dword ptr [g_dispatchSave1361], edi
        mov      dword ptr [g_dispatchSave1362], ebx
        jg       L_1dc1
        mov      edx, dword ptr [g_dispatchSave1359]
    L_1fb8:
        mov      eax, dword ptr [g_dispatchSave1394]
        mov      ecx, dword ptr [g_dispatchSave1365]
        cmp      ecx, eax
        jl       L_1b8c
    L_1fcb:
        pop      edi
        pop      esi
        pop      ebx
        mov      esp, ebp
        pop      ebp
        ret
    }
}
