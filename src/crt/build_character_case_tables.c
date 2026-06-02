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

extern unsigned int g_byte_00f9f8c1;
extern unsigned int g_dispatchSave1434;
extern unsigned int g_dispatchSave1435;
extern unsigned int g_dispatchSave1436;
extern unsigned int g_iat_GetCPInfo;
extern void CrtCodepageDispatcher(void);
extern void WcToMbDispatcher(void);

__declspec(naked) void BuildCharacterCaseTables(void)
{
    __asm {
        mov      ecx, dword ptr [g_dispatchSave1435]
        sub      esp, 0x514
        /* MASM emits 3-byte `8d 04 24` for lea eax,[esp]; orig uses
         * 4-byte disp8=0 form `8d 44 24 00`. */
        _emit    0x8d
        _emit    0x44
        _emit    0x24
        _emit    0x00
        push     ebx
        push     eax
        push     ecx
        call     dword ptr [g_iat_GetCPInfo]
        cmp      eax, 1
        jne      L_99b4
        push     edi
        push     esi
        xor      eax, eax
    L_9866:
        mov      byte ptr [esp + eax + 0x20], al
        inc      eax
        cmp      eax, 0x100
        jb       short L_9866
        mov      al, byte ptr [esp + 0x12]
        mov      byte ptr [esp + 0x20], 0x20
        test     al, al
        je       short L_98b4
        lea      edx, [esp + 0x13]
    L_9883:
        xor      ecx, ecx
        and      eax, 0xff
        mov      cl, byte ptr [edx]
        cmp      eax, ecx
        ja       short L_98aa
        sub      ecx, eax
        lea      edi, [esp + eax + 0x20]
        inc      ecx
        mov      eax, 0x20202020
        mov      esi, ecx
        shr      ecx, 2
        rep stosd
        mov      ecx, esi
        and      ecx, 3
        rep stosb
    L_98aa:
        mov      al, byte ptr [edx + 1]
        add      edx, 2
        test     al, al
        jne      short L_9883
    L_98b4:
        mov      edx, dword ptr [g_dispatchSave1436]
        mov      eax, dword ptr [g_dispatchSave1435]
        push     0
        push     edx
        lea      ecx, [esp + 0x328]
        push     eax
        push     ecx
        lea      edx, [esp + 0x30]
        push     0x100
        push     edx
        push     1
        call     WcToMbDispatcher
        mov      eax, dword ptr [g_dispatchSave1435]
        add      esp, 0x1c
        lea      ecx, [esp + 0x120]
        lea      edx, [esp + 0x20]
        push     0
        push     eax
        mov      eax, dword ptr [g_dispatchSave1436]
        push     0x100
        push     ecx
        push     0x100
        push     edx
        push     0x100
        push     eax
        call     CrtCodepageDispatcher
        mov      ecx, dword ptr [g_dispatchSave1435]
        add      esp, 0x20
        lea      edx, [esp + 0x220]
        lea      eax, [esp + 0x20]
        push     0
        push     ecx
        mov      ecx, dword ptr [g_dispatchSave1436]
        push     0x100
        push     edx
        push     0x100
        push     eax
        push     0x200
        push     ecx
        call     CrtCodepageDispatcher
        add      esp, 0x20
        xor      eax, eax
        lea      edx, [esp + 0x320]
        mov      bl, 0x10
    L_9950:
        mov      cx, word ptr [edx]
        test     cl, 1
        je       short L_9975
        mov      cl, byte ptr [eax + g_byte_00f9f8c1]
        or       cl, bl
        mov      byte ptr [eax + g_byte_00f9f8c1], cl
        mov      cl, byte ptr [esp + eax + 0x120]
        mov      byte ptr [eax + g_dispatchSave1434], cl
        jmp      short L_999f
    L_9975:
        test     cl, 2
        je       short L_9998
        mov      cl, byte ptr [eax + g_byte_00f9f8c1]
        or       cl, 0x20
        mov      byte ptr [eax + g_byte_00f9f8c1], cl
        mov      cl, byte ptr [esp + eax + 0x220]
        mov      byte ptr [eax + g_dispatchSave1434], cl
        jmp      short L_999f
    L_9998:
        mov      byte ptr [eax + g_dispatchSave1434], 0
    L_999f:
        inc      eax
        add      edx, 2
        cmp      eax, 0x100
        jb       short L_9950
        pop      esi
        pop      edi
        pop      ebx
        add      esp, 0x514
        ret
    L_99b4:
        xor      eax, eax
        mov      bl, 0x10
    L_99b8:
        cmp      eax, 0x41
        jb       short L_99dd
        cmp      eax, 0x5a
        ja       short L_99dd
        mov      dl, byte ptr [eax + g_byte_00f9f8c1]
        or       dl, bl
        mov      byte ptr [eax + g_byte_00f9f8c1], dl
        mov      dl, al
        add      dl, 0x20
        mov      byte ptr [eax + g_dispatchSave1434], dl
        jmp      short L_9a0a
    L_99dd:
        cmp      eax, 0x61
        jb       short L_9a03
        cmp      eax, 0x7a
        ja       short L_9a03
        mov      cl, byte ptr [eax + g_byte_00f9f8c1]
        or       cl, 0x20
        mov      byte ptr [eax + g_byte_00f9f8c1], cl
        mov      cl, al
        sub      cl, 0x20
        mov      byte ptr [eax + g_dispatchSave1434], cl
        jmp      short L_9a0a
    L_9a03:
        mov      byte ptr [eax + g_dispatchSave1434], 0
    L_9a0a:
        inc      eax
        cmp      eax, 0x100
        jb       short L_99b8
        pop      ebx
        add      esp, 0x514
        ret
    }
}
