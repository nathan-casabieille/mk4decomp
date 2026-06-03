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

extern unsigned int g_dispatchSave1441;
extern unsigned int g_dispatchSave1443;
extern void CrtFileOpenImpl(void);

__declspec(naked) void FopenMode(void)
{
    __asm {
        mov      ecx, dword ptr [esp + 8]
        push     ebx
        push     ebp
        push     esi
        mov      al, byte ptr [ecx]
        xor      edx, edx
        xor      ebp, ebp
        push     edi
        mov      edi, dword ptr [g_dispatchSave1443]
        cmp      al, 0x61
        je       short L_92a5
        cmp      al, 0x72
        je       short L_929e
        cmp      al, 0x77
        je       short L_9297
        xor      eax, eax
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    L_9297:
        mov      eax, 0x301
        jmp      short L_92aa
    L_929e:
        xor      eax, eax
        or       edi, 1
        jmp      short L_92ad
    L_92a5:
        mov      eax, 0x109
    L_92aa:
        or       edi, 2
    L_92ad:
        inc      ecx
        mov      esi, 1
        mov      dword ptr [esp + 0x18], ecx
        mov      cl, byte ptr [ecx]
        test     cl, cl
        je       L_9371
    L_92c1:
        test     esi, esi
        je       L_9371
        movsx    ecx, cl
        add      ecx, -0x2b
        cmp      ecx, 0x49
        ja       short L_935c
        xor      ebx, ebx
        mov      bl, byte ptr [ecx + L_270_byidx]
        jmp      dword ptr [ebx*4 + L_270_jmptbl]
    L_92e7:
        test     al, 2
        jne      short L_935c
        and      al, 0xfe
        and      edi, 0xfffffffc
        or       al, 2
        or       edi, 0x80
        jmp      short L_935e
    L_92fa:
        test     ah, 0xc0
        jne      short L_935c
        or       ah, 0x80
        jmp      short L_935e
    L_9304:
        test     ah, 0xc0
        jne      short L_935c
        or       ah, 0x40
        jmp      short L_935e
    L_930e:
        test     edx, edx
        jne      short L_935c
        mov      edx, 1
        or       edi, 0x4000
        jmp      short L_935e
    L_931f:
        test     edx, edx
        jne      short L_935c
        mov      edx, 1
        and      edi, 0xffffbfff
        jmp      short L_935e
    L_9330:
        test     ebp, ebp
        jne      short L_935c
        mov      ebp, 1
        or       al, 0x20
        jmp      short L_935e
    L_933d:
        test     ebp, ebp
        jne      short L_935c
        mov      ebp, 1
        or       al, 0x10
        jmp      short L_935e
    L_934a:
        test     ah, 0x10
        jne      short L_935c
        or       ah, 0x10
        jmp      short L_935e
    L_9354:
        test     al, 0x40
        jne      short L_935c
        or       al, 0x40
        jmp      short L_935e
    L_935c:
        xor      esi, esi
    L_935e:
        mov      ecx, dword ptr [esp + 0x18]
        inc      ecx
        mov      dword ptr [esp + 0x18], ecx
        mov      cl, byte ptr [ecx]
        test     cl, cl
        jne      L_92c1
    L_9371:
        mov      ecx, dword ptr [esp + 0x1c]
        mov      edx, dword ptr [esp + 0x14]
        push     0x1a4
        push     ecx
        push     eax
        push     edx
        call     CrtFileOpenImpl
        mov      ecx, eax
        add      esp, 0x10
        test     ecx, ecx
        jge      short L_9396
        xor      eax, eax
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        ret
    L_9396:
        mov      eax, dword ptr [g_dispatchSave1441]
        inc      eax
        mov      dword ptr [g_dispatchSave1441], eax
        mov      eax, dword ptr [esp + 0x20]
        mov      dword ptr [eax + 0xc], edi
        pop      edi
        pop      esi
        pop      ebp
        mov      dword ptr [eax + 4], 0
        mov      dword ptr [eax], 0
        mov      dword ptr [eax + 8], 0
        mov      dword ptr [eax + 0x1c], 0
        mov      dword ptr [eax + 0x10], ecx
        pop      ebx
        ret
        nop
    L_270_jmptbl:
        _emit    0xe7
        _emit    0x92
        _emit    0x4c
        _emit    0x00
        _emit    0x54
        _emit    0x93
        _emit    0x4c
        _emit    0x00
        _emit    0x3d
        _emit    0x93
        _emit    0x4c
        _emit    0x00
        _emit    0x30
        _emit    0x93
        _emit    0x4c
        _emit    0x00
        _emit    0x4a
        _emit    0x93
        _emit    0x4c
        _emit    0x00
        _emit    0xfa
        _emit    0x92
        _emit    0x4c
        _emit    0x00
        _emit    0x0e
        _emit    0x93
        _emit    0x4c
        _emit    0x00
        _emit    0x1f
        _emit    0x93
        _emit    0x4c
        _emit    0x00
        _emit    0x04
        _emit    0x93
        _emit    0x4c
        _emit    0x00
        _emit    0x5c
        _emit    0x93
        _emit    0x4c
        _emit    0x00
    L_270_byidx:
        _emit    0x00
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x01
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x02
        _emit    0x03
        _emit    0x04
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x05
        _emit    0x06
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x07
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x09
        _emit    0x08
    }
}
