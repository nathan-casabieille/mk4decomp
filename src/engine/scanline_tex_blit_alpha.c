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
extern unsigned int g_texturedTriVar;
extern unsigned int g_dispatchSave1707_00b2d008;
extern unsigned int g_dispatchSave1708_00b2d00c;
extern unsigned int g_dispatchSave1346_00f4d044;
extern unsigned int g_dispatchSave1357_00f70f4c;
extern unsigned int g_dispatchSave1358_00f70f50;
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
extern unsigned int g_dispatchSave1400_00f85b34;
extern unsigned int g_dispatchSave1403_00f85b4c;
extern unsigned int g_viewportX;
extern unsigned int g_viewportY;
extern unsigned int g_dispatchSave1404_00f85b58;

__declspec(naked) void ScanlineTexBlitAlpha(void)
{
    __asm {
        mov      eax, dword ptr [g_viewportX]
        push     ebx
        push     esi
        push     edi
        test     eax, eax
        je       L_0e02
        mov      edi, dword ptr [g_dispatchSave1378_00f70fa8]
        mov      eax, dword ptr [g_viewportW]
        cmp      edi, eax
        jge      L_0e02
        mov      eax, dword ptr [g_dispatchSave1381_00f70fb8]
        mov      ecx, dword ptr [g_viewportH]
        cmp      eax, ecx
        jge      L_0e02
        mov      ecx, dword ptr [g_dispatchSave1380_00f70fb0]
        test     ecx, ecx
        jl       L_0e02
        mov      esi, dword ptr [g_dispatchSave1383_00f70fc0]
        test     esi, esi
        jl       L_0e02
        sub      ecx, edi
        sub      esi, eax
        cmp      ecx, 1
        mov      dword ptr [g_dispatchSave1708_00b2d00c], ecx
        mov      dword ptr [g_dispatchSave1707_00b2d008], esi
        jl       L_0e02
        cmp      esi, 1
        jl       L_0e02
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
        mov      ebx, dword ptr [g_dispatchSave1377_00f70fa0]
        cdq
        idiv     ecx
        mov      edx, dword ptr [g_dispatchSave1374_00f70f98]
        shl      ebx, 0x10
        mov      dword ptr [g_dispatchSave1377_00f70fa0], ebx
        mov      ebx, eax
        mov      eax, dword ptr [g_dispatchSave1377_00f70fa0]
        sub      eax, edx
        mov      dword ptr [g_dispatchSave1357_00f70f4c], ebx
        cdq
        idiv     esi
        test     edi, edi
        mov      dword ptr [g_dispatchSave1358_00f70f50], eax
        jge      L_0c63
        imul     ebx, edi
        mov      edx, dword ptr [g_dispatchSave1371_00f70f88]
        add      ecx, edi
        sub      edx, ebx
        xor      edi, edi
        mov      dword ptr [g_dispatchSave1371_00f70f88], edx
        mov      dword ptr [g_dispatchSave1708_00b2d00c], ecx
        mov      dword ptr [g_dispatchSave1378_00f70fa8], edi
    L_0c63:
        mov      ecx, dword ptr [g_dispatchSave1381_00f70fb8]
        test     ecx, ecx
        jge      L_0c96
        imul     eax, ecx
        mov      edx, dword ptr [g_dispatchSave1374_00f70f98]
        mov      dword ptr [g_dispatchSave1381_00f70fb8], 0
        sub      edx, eax
        add      esi, ecx
        mov      ecx, dword ptr [g_dispatchSave1381_00f70fb8]
        mov      dword ptr [g_dispatchSave1374_00f70f98], edx
        mov      dword ptr [g_dispatchSave1707_00b2d008], esi
    L_0c96:
        mov      eax, dword ptr [g_viewportW]
        mov      edx, dword ptr [g_dispatchSave1380_00f70fb0]
        cmp      edx, eax
        jl       L_0cac
        sub      eax, edi
        mov      dword ptr [g_dispatchSave1708_00b2d00c], eax
    L_0cac:
        mov      eax, dword ptr [g_viewportH]
        mov      edx, dword ptr [g_dispatchSave1383_00f70fc0]
        cmp      edx, eax
        jl       L_0cc5
        sub      eax, ecx
        mov      esi, eax
        mov      dword ptr [g_dispatchSave1707_00b2d008], esi
    L_0cc5:
        mov      edx, dword ptr [g_viewportY]
        mov      eax, dword ptr [g_viewportX]
        imul     edx, ecx
        add      eax, edx
        lea      eax, [eax + edi*2]
        mov      dword ptr [g_dispatchSave1346_00f4d044], eax
        mov      eax, dword ptr [g_dispatchSave1403_00f85b4c]
        and      eax, 0xf
        shl      eax, 0x10
        test     esi, esi
        mov      dword ptr [g_dispatchSave1403_00f85b4c], eax
        jle      L_0e02
        jmp      L_0cfc
    L_0cf7:
        mov      eax, dword ptr [g_dispatchSave1403_00f85b4c]
    L_0cfc:
        mov      ecx, dword ptr [g_dispatchSave1371_00f70f88]
        xor      edx, edx
        mov      dh, byte ptr [g_dispatchSave1375_00f70f9a]
        mov      dword ptr [g_dispatchSave1387_00f70fd8], ecx
        add      edx, eax
        mov      eax, dword ptr [g_dispatchSave1400_00f85b34]
        lea      ecx, [eax + edx*2]
        mov      dword ptr [g_dispatchSave1404_00f85b58], ecx
        mov      eax, dword ptr [g_dispatchSave1387_00f70fd8]
        shl      eax, 0x10
        mov      edx, dword ptr [g_dispatchSave1404_00f85b58]
        shr      edx, 1
        mov      ecx, dword ptr [g_dispatchSave1387_00f70fd8]
        shr      ecx, 0x10
        mov      dl, cl
        mov      edi, dword ptr [g_dispatchSave1346_00f4d044]
        add      edi, dword ptr [g_dispatchSave1708_00b2d00c]
        add      edi, dword ptr [g_dispatchSave1708_00b2d00c]
        mov      esi, dword ptr [g_dispatchSave1708_00b2d00c]
        neg      esi
        mov      ecx, dword ptr [g_dispatchSave1357_00f70f4c]
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
        mov      edx, dword ptr [g_dispatchSave1358_00f70f50]
        mov      esi, dword ptr [g_dispatchSave1374_00f70f98]
        mov      eax, dword ptr [g_dispatchSave1707_00b2d008]
        mov      ecx, dword ptr [g_viewportY]
        add      esi, edx
        mov      edx, dword ptr [g_dispatchSave1346_00f4d044]
        dec      eax
        add      edx, ecx
        test     eax, eax
        mov      dword ptr [g_dispatchSave1707_00b2d008], eax
        mov      dword ptr [g_dispatchSave1374_00f70f98], esi
        mov      dword ptr [g_dispatchSave1346_00f4d044], edx
        jg       L_0cf7
    L_0e02:
        pop      edi
        pop      esi
        pop      ebx
        ret
    }
}
