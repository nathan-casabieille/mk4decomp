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
extern void WalkCbSubMul10_00431d50(void);
extern void Mul10Tail(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10(void);
extern void SpawnListBatchLoader_00477710(void);
extern void MStackPush2TableNot(void);
extern void GuardedChainCmpDualBitXor(void);
extern void ScaledLoadDecJmp_00429710(void);
extern void ScaledStoreCurDirtyClear_004296f0(void);
extern void MStackBitmaskIncMod_00492450(void);
extern void MStackBitmaskUpdate_00492510(void);
extern void Push1eCallTestDirtyLoop_004923b0(void);
extern void MStackLoopFieldInit_00492280(void);
extern void TaggedSceneDispatch(void);
extern void CallPauseDirty4StackPushFn_004839d0(void);
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void InstallSelfChainSet84_80CallW_004363f0(void);
extern void Wrapper_00436490(void);
extern void MoveFsmCluster_004364a0(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain_0047a950(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_004bd5c0(void);
extern void AllocSlotPushTripleGlobals(void);
extern void MStackPop4Rewrite(void);
extern void Push70CallScaleArith(void);
extern void StreamChainStringInstall(void);
extern void MStackFrameCdeclDouble(void);
extern void ChainTableWalkStore_004917e0(void);
extern void Push16Call(void);
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm_0048f2a0(void);
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
extern unsigned int g_texturedTriVar_004ffd4c;
extern unsigned int g_dispatchSave1707_00b2d008;
extern unsigned int g_dispatchSave1708_00b2d00c;
extern unsigned int g_dispatchSave1345_00f4d040;
extern unsigned int g_dispatchSave1346_00f4d044;
extern unsigned int g_dispatchSave1357_00f70f4c;
extern unsigned int g_dispatchSave1358_00f70f50;
extern s32 g_clipMinScratch;
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

__declspec(naked) void ScanlineTexBlitAdditive_004c0e10(void)
{
    __asm {
        mov      eax, dword ptr [g_viewportX]
        push     ebx
        push     ebp
        push     esi
        test     eax, eax
        push     edi
        je       L_1129
        mov      ecx, dword ptr [g_dispatchSave1378_00f70fa8]
        mov      eax, dword ptr [g_viewportW]
        cmp      ecx, eax
        jge      L_1129
        mov      edi, dword ptr [g_dispatchSave1381_00f70fb8]
        mov      eax, dword ptr [g_viewportH]
        cmp      edi, eax
        jge      L_1129
        mov      ebp, dword ptr [g_dispatchSave1380_00f70fb0]
        test     ebp, ebp
        jl       L_1129
        mov      eax, dword ptr [g_dispatchSave1383_00f70fc0]
        test     eax, eax
        jl       L_1129
        sub      ebp, ecx
        sub      eax, edi
        cmp      ebp, 1
        mov      dword ptr [g_dispatchSave1708_00b2d00c], ebp
        mov      dword ptr [g_dispatchSave1707_00b2d008], eax
        jl       L_1129
        cmp      eax, 1
        jl       L_1129
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
        idiv     ebp
        shl      ebx, 0x10
        mov      dword ptr [g_dispatchSave1377_00f70fa0], ebx
        mov      esi, eax
        mov      eax, ebx
        mov      ebx, dword ptr [g_dispatchSave1374_00f70f98]
        mov      dword ptr [g_dispatchSave1357_00f70f4c], esi
        sub      eax, ebx
        cdq
        idiv     dword ptr [g_dispatchSave1707_00b2d008]
        test     ecx, ecx
        mov      dword ptr [g_dispatchSave1358_00f70f50], eax
        jge      L_0f05
        mov      edx, esi
        mov      ebx, dword ptr [g_dispatchSave1371_00f70f88]
        imul     edx, ecx
        sub      ebx, edx
        add      ebp, ecx
        xor      ecx, ecx
        mov      dword ptr [g_dispatchSave1371_00f70f88], ebx
        mov      dword ptr [g_dispatchSave1708_00b2d00c], ebp
        mov      dword ptr [g_dispatchSave1378_00f70fa8], ecx
    L_0f05:
        test     edi, edi
        jge      L_0f2e
        imul     eax, edi
        mov      edx, dword ptr [g_dispatchSave1374_00f70f98]
        sub      edx, eax
        mov      eax, dword ptr [g_dispatchSave1707_00b2d008]
        add      eax, edi
        xor      edi, edi
        mov      dword ptr [g_dispatchSave1374_00f70f98], edx
        mov      dword ptr [g_dispatchSave1707_00b2d008], eax
        mov      dword ptr [g_dispatchSave1381_00f70fb8], edi
    L_0f2e:
        mov      eax, dword ptr [g_viewportW]
        mov      edx, dword ptr [g_dispatchSave1380_00f70fb0]
        cmp      edx, eax
        jl       L_0f47
        sub      eax, ecx
        mov      ebp, eax
        mov      dword ptr [g_dispatchSave1708_00b2d00c], ebp
    L_0f47:
        mov      eax, dword ptr [g_viewportH]
        mov      edx, dword ptr [g_dispatchSave1383_00f70fc0]
        cmp      edx, eax
        jl       L_0f5d
        sub      eax, edi
        mov      dword ptr [g_dispatchSave1707_00b2d008], eax
    L_0f5d:
        mov      edx, dword ptr [g_viewportY]
        mov      eax, dword ptr [g_viewportX]
        imul     edx, edi
        add      eax, edx
        lea      edx, [eax + ecx*2]
        mov      eax, dword ptr [g_dispatchSave1403_00f85b4c]
        mov      ecx, dword ptr [g_dispatchSave1707_00b2d008]
        and      eax, 0xf
        shl      eax, 0x10
        test     ecx, ecx
        mov      dword ptr [g_dispatchSave1346_00f4d044], edx
        mov      dword ptr [g_dispatchSave1403_00f85b4c], eax
        jle      L_1129
        jmp      L_0f9b
    L_0f96:
        mov      eax, dword ptr [g_dispatchSave1403_00f85b4c]
    L_0f9b:
        mov      ecx, dword ptr [g_dispatchSave1371_00f70f88]
        mov      dword ptr [g_dispatchSave1345_00f4d040], edx
        mov      dword ptr [g_dispatchSave1387_00f70fd8], ecx
        xor      ecx, ecx
        mov      ch, byte ptr [g_dispatchSave1375_00f70f9a]
        mov      dword ptr [g_clipMinScratch], ebp
        add      ecx, eax
        mov      eax, dword ptr [g_dispatchSave1400_00f85b34]
        lea      ecx, [eax + ecx*2]
        mov      eax, dword ptr [g_texturedTriVar_004ffd4c]
        test     eax, eax
        mov      dword ptr [g_dispatchSave1404_00f85b58], ecx
        je       L_1071
        test     ebp, ebp
        jle      L_10ee
    L_0fe0:
        mov      edi, dword ptr [g_dispatchSave1404_00f85b58]
        xor      ecx, ecx
        mov      cl, byte ptr [g_dispatchSave1388_00f70fda]
        xor      eax, eax
        mov      ax, word ptr [edi + ecx*2]
        test     ax, ax
        je       L_1045
        mov      cx, word ptr [edx]
        and      eax, 0xf7de
        and      ecx, 0xf7de
        add      ecx, eax
        mov      eax, ecx
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
        mov      ebp, dword ptr [g_dispatchSave1708_00b2d00c]
        mov      esi, dword ptr [g_dispatchSave1357_00f70f4c]
        mov      edx, dword ptr [g_dispatchSave1345_00f4d040]
    L_1045:
        mov      eax, dword ptr [g_clipMinScratch]
        mov      ebx, dword ptr [g_dispatchSave1387_00f70fd8]
        dec      eax
        add      ebx, esi
        add      edx, 2
        mov      dword ptr [g_clipMinScratch], eax
        test     eax, eax
        mov      dword ptr [g_dispatchSave1387_00f70fd8], ebx
        mov      dword ptr [g_dispatchSave1345_00f4d040], edx
        jg       L_0fe0
        jmp      L_10ee
    L_1071:
        test     ebp, ebp
        jle      L_10ee
    L_1075:
        mov      edi, dword ptr [g_dispatchSave1404_00f85b58]
        xor      ecx, ecx
        mov      cl, byte ptr [g_dispatchSave1388_00f70fda]
        xor      eax, eax
        mov      ax, word ptr [edi + ecx*2]
        test     ax, ax
        je       L_10c8
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
        mov      ebp, dword ptr [g_dispatchSave1708_00b2d00c]
        mov      esi, dword ptr [g_dispatchSave1357_00f70f4c]
        mov      edx, dword ptr [g_dispatchSave1345_00f4d040]
    L_10c8:
        mov      eax, dword ptr [g_clipMinScratch]
        mov      ebx, dword ptr [g_dispatchSave1387_00f70fd8]
        dec      eax
        add      ebx, esi
        add      edx, 2
        mov      dword ptr [g_clipMinScratch], eax
        test     eax, eax
        mov      dword ptr [g_dispatchSave1387_00f70fd8], ebx
        mov      dword ptr [g_dispatchSave1345_00f4d040], edx
        jg       L_1075
    L_10ee:
        mov      edx, dword ptr [g_dispatchSave1358_00f70f50]
        mov      ebx, dword ptr [g_dispatchSave1374_00f70f98]
        mov      eax, dword ptr [g_dispatchSave1707_00b2d008]
        mov      edi, dword ptr [g_viewportY]
        add      ebx, edx
        mov      edx, dword ptr [g_dispatchSave1346_00f4d044]
        dec      eax
        add      edx, edi
        test     eax, eax
        mov      dword ptr [g_dispatchSave1707_00b2d008], eax
        mov      dword ptr [g_dispatchSave1374_00f70f98], ebx
        mov      dword ptr [g_dispatchSave1346_00f4d044], edx
        jg       L_0f96
    L_1129:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    }
}
