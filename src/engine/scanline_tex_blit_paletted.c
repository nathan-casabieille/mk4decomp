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
extern void SetJmp_0049cb90(void);
extern void Thunk_0049cbd0(void);
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
extern void Wrapper_00436490(void);
extern void MoveFsmCluster(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_004bd5c0(void);
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

extern void ScaledArrStore_004298c0(void);
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
extern void Wrapper_0048a350(void);
extern void Wrapper_0048a3a0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_0048ec20(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_00438f50(void);
extern void SetJmp_00438f60(void);
extern void GuardedDispatch_0042b6c0(void);
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
extern unsigned int g_dispatchSave1707_00b2d008;
extern unsigned int g_dispatchSave1708_00b2d00c;
extern unsigned int g_dispatchSave1340_00f4d028;
extern unsigned int g_dispatchSave1345_00f4d040;
extern unsigned int g_dispatchSave1346_00f4d044;
extern unsigned int g_dispatchSave1357_00f70f4c;
extern unsigned int g_dispatchSave1358_00f70f50;
extern s32 g_clipMinScratch;
extern unsigned int g_dispatchSave1367_00f70f7c;
extern unsigned int g_dispatchSave1371_00f70f88;
extern unsigned int g_dispatchSave1373_00f70f90;
extern unsigned int g_dispatchSave1374_00f70f98;
extern unsigned int g_dispatchSave1375_00f70f9a;
extern unsigned int g_dispatchSave1377_00f70fa0;
extern unsigned int g_dispatchSave1378_00f70fa8;
extern unsigned int g_dispatchSave1380_00f70fb0;
extern unsigned int g_dispatchSave1381_00f70fb8;
extern unsigned int g_dispatchSave1383_00f70fc0;
extern unsigned int g_dispatchSave1387_00f70fd8;
extern unsigned int g_dispatchSave1388_00f70fda;
extern unsigned int g_dispatchSave1400_00f85b34;
extern unsigned int g_dispatchSave1403_00f85b4c;
extern unsigned int g_viewportX;
extern unsigned int g_viewportY;
extern unsigned int g_dispatchSave1404_00f85b58;

__declspec(naked) void ScanlineTexBlitPaletted_004c0360(void)
{
    __asm {
        mov      eax, dword ptr [g_viewportX]
        push     ebx
        push     ebp
        push     esi
        test     eax, eax
        push     edi
        je       L_05d4
        mov      ecx, dword ptr [g_dispatchSave1378_00f70fa8]
        mov      eax, dword ptr [g_viewportW]
        cmp      ecx, eax
        jge      L_05d4
        mov      ebx, dword ptr [g_dispatchSave1381_00f70fb8]
        mov      eax, dword ptr [g_viewportH]
        cmp      ebx, eax
        jge      L_05d4
        mov      esi, dword ptr [g_dispatchSave1380_00f70fb0]
        test     esi, esi
        jl       L_05d4
        mov      edi, dword ptr [g_dispatchSave1383_00f70fc0]
        test     edi, edi
        jl       L_05d4
        sub      esi, ecx
        sub      edi, ebx
        cmp      esi, 1
        mov      dword ptr [g_dispatchSave1708_00b2d00c], esi
        mov      dword ptr [g_dispatchSave1707_00b2d008], edi
        jl       L_05d4
        cmp      edi, 1
        jl       L_05d4
        mov      eax, dword ptr [g_dispatchSave1374_00f70f98]
        mov      edx, dword ptr [g_dispatchSave1371_00f70f88]
        shl      eax, 0x10
        mov      dword ptr [g_dispatchSave1374_00f70f98], eax
        mov      eax, dword ptr [g_dispatchSave1373_00f70f90]
        shl      eax, 0x10
        shl      edx, 0x10
        mov      dword ptr [g_dispatchSave1373_00f70f90], eax
        sub      eax, edx
        mov      dword ptr [g_dispatchSave1371_00f70f88], edx
        mov      ebp, dword ptr [g_dispatchSave1377_00f70fa0]
        cdq
        idiv     esi
        mov      edx, dword ptr [g_dispatchSave1374_00f70f98]
        shl      ebp, 0x10
        mov      dword ptr [g_dispatchSave1377_00f70fa0], ebp
        mov      dword ptr [g_dispatchSave1357_00f70f4c], eax
        mov      eax, ebp
        sub      eax, edx
        cdq
        idiv     edi
        test     ecx, ecx
        mov      ebp, eax
        mov      dword ptr [g_dispatchSave1358_00f70f50], ebp
        jge      L_0456
        mov      eax, dword ptr [g_dispatchSave1357_00f70f4c]
        mov      edx, dword ptr [g_dispatchSave1371_00f70f88]
        imul     eax, ecx
        sub      edx, eax
        add      esi, ecx
        xor      ecx, ecx
        mov      dword ptr [g_dispatchSave1371_00f70f88], edx
        mov      dword ptr [g_dispatchSave1708_00b2d00c], esi
        mov      dword ptr [g_dispatchSave1378_00f70fa8], ecx
    L_0456:
        test     ebx, ebx
        jge      L_047b
        mov      edx, ebp
        mov      eax, dword ptr [g_dispatchSave1374_00f70f98]
        imul     edx, ebx
        sub      eax, edx
        add      edi, ebx
        xor      ebx, ebx
        mov      dword ptr [g_dispatchSave1374_00f70f98], eax
        mov      dword ptr [g_dispatchSave1707_00b2d008], edi
        mov      dword ptr [g_dispatchSave1381_00f70fb8], ebx
    L_047b:
        mov      eax, dword ptr [g_viewportW]
        mov      edx, dword ptr [g_dispatchSave1380_00f70fb0]
        cmp      edx, eax
        jl       L_0494
        sub      eax, ecx
        mov      esi, eax
        mov      dword ptr [g_dispatchSave1708_00b2d00c], esi
    L_0494:
        mov      eax, dword ptr [g_viewportH]
        mov      edx, dword ptr [g_dispatchSave1383_00f70fc0]
        cmp      edx, eax
        jl       L_04ad
        sub      eax, ebx
        mov      edi, eax
        mov      dword ptr [g_dispatchSave1707_00b2d008], edi
    L_04ad:
        mov      edx, dword ptr [g_viewportY]
        mov      eax, dword ptr [g_viewportX]
        imul     edx, ebx
        add      eax, edx
        mov      ebx, dword ptr [g_dispatchSave1340_00f4d028]
        lea      eax, [eax + ecx*2]
        mov      ecx, dword ptr [g_dispatchSave1367_00f70f7c]
        and      ecx, 0xff
        mov      dword ptr [g_dispatchSave1346_00f4d044], eax
        mov      eax, dword ptr [g_dispatchSave1403_00f85b4c]
        and      ecx, 0xfffffff0
        shl      ecx, 0xd
        and      eax, 0xf
        add      ecx, ebx
        shl      eax, 0x10
        test     edi, edi
        mov      dword ptr [g_dispatchSave1403_00f85b4c], eax
        jle      L_05d4
    L_04f7:
        mov      edx, dword ptr [g_dispatchSave1371_00f70f88]
        mov      ebx, dword ptr [g_dispatchSave1400_00f85b34]
        mov      dword ptr [g_dispatchSave1387_00f70fd8], edx
        xor      edx, edx
        mov      dh, byte ptr [g_dispatchSave1375_00f70f9a]
        mov      dword ptr [g_clipMinScratch], esi
        add      edx, eax
        test     esi, esi
        lea      edx, [ebx + edx*2]
        mov      dword ptr [g_dispatchSave1404_00f85b58], edx
        mov      edx, dword ptr [g_dispatchSave1346_00f4d044]
        mov      dword ptr [g_dispatchSave1345_00f4d040], edx
        jle      L_05a3
    L_0532:
        mov      edx, dword ptr [g_dispatchSave1404_00f85b58]
        xor      eax, eax
        mov      al, byte ptr [g_dispatchSave1388_00f70fda]
        mov      ax, word ptr [edx + eax*2]
        test     ax, ax
        je       L_0566
        mov      edx, dword ptr [g_dispatchSave1345_00f4d040]
        and      eax, 0xffff
        mov      ax, word ptr [ecx + eax*2]
        mov      word ptr [edx], ax
        mov      esi, dword ptr [g_dispatchSave1708_00b2d00c]
        mov      edi, dword ptr [g_dispatchSave1707_00b2d008]
    L_0566:
        mov      eax, dword ptr [g_clipMinScratch]
        mov      edx, dword ptr [g_dispatchSave1357_00f70f4c]
        mov      ebp, dword ptr [g_dispatchSave1387_00f70fd8]
        mov      ebx, dword ptr [g_dispatchSave1345_00f4d040]
        dec      eax
        add      ebp, edx
        add      ebx, 2
        mov      dword ptr [g_clipMinScratch], eax
        test     eax, eax
        mov      dword ptr [g_dispatchSave1387_00f70fd8], ebp
        mov      dword ptr [g_dispatchSave1345_00f4d040], ebx
        jg       L_0532
        mov      eax, dword ptr [g_dispatchSave1403_00f85b4c]
        mov      ebp, dword ptr [g_dispatchSave1358_00f70f50]
    L_05a3:
        mov      edx, dword ptr [g_dispatchSave1374_00f70f98]
        mov      ebx, dword ptr [g_dispatchSave1346_00f4d044]
        add      edx, ebp
        dec      edi
        mov      dword ptr [g_dispatchSave1374_00f70f98], edx
        mov      edx, dword ptr [g_viewportY]
        add      ebx, edx
        mov      dword ptr [g_dispatchSave1707_00b2d008], edi
        test     edi, edi
        mov      dword ptr [g_dispatchSave1346_00f4d044], ebx
        jg       L_04f7
    L_05d4:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    }
}
