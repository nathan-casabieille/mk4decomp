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

extern unsigned int g_dispatchSave871;
extern unsigned int g_byte_00522bb4;
extern unsigned int g_dispatchSave111;
extern unsigned int g_dispatchSave110;
extern unsigned int g_crtTimeFmtPrefs;
extern unsigned int g_dispatchSave1446;
extern unsigned int g_dispatchSave1456;
extern unsigned int g_dispatchSave1457;
extern unsigned int g_dispatchSave1458;
extern unsigned int g_dispatchSave1461;
extern void CrtGetLocaleInfo(void);
extern void FreeImpl(void);
extern void LoadArgPushCall(void);
extern void StringStripSlotReplace(void);

__declspec(naked) void CrtTimeFmtPrefsCluster(void)
{
    __asm {
        /* === h1 (0x4cfe40): time-format string builder === */
        sub      esp, 8
        push     esi
        lea      eax, [esp + 8]
        push     edi
        mov      edi, dword ptr [esp + 0x14]
        push     eax
        push     0x23
        push     edi
        push     0
        mov      dword ptr [esp + 0x1c], 0
        mov      dword ptr [esp + 0x18], 0
        call     CrtGetLocaleInfo
        add      esp, 0x10
        lea      ecx, [esp + 8]
        mov      esi, eax
        push     ecx
        push     0x25
        push     edi
        push     0
        call     CrtGetLocaleInfo
        add      esp, 0x10
        lea      edx, [esp + 0x14]
        or       esi, eax
        push     edx
        push     0x1e
        push     edi
        push     1
        call     CrtGetLocaleInfo
        add      esp, 0x10
        or       esi, eax
        je       short L_fe9f
        mov      eax, esi
        pop      edi
        pop      esi
        add      esp, 8
        ret
    L_fe9f:
        push     0xd
        call     LoadArgPushCall
        mov      ecx, dword ptr [esp + 0x1c]
        add      esp, 4
        mov      dword ptr [ecx + 0xa8], eax
        mov      ecx, dword ptr [esp + 0xc]
        test     ecx, ecx
        je       short L_fecc
        mov      byte ptr [eax], 0x48
        mov      ecx, dword ptr [esp + 8]
        inc      eax
        test     ecx, ecx
        je       short L_fedc
        mov      byte ptr [eax], 0x48
        jmp      short L_fedb
    L_fecc:
        mov      byte ptr [eax], 0x68
        mov      ecx, dword ptr [esp + 8]
        inc      eax
        test     ecx, ecx
        je       short L_fedc
        mov      byte ptr [eax], 0x68
    L_fedb:
        inc      eax
    L_fedc:
        mov      edx, dword ptr [esp + 0x14]
        mov      cl, byte ptr [edx]
        test     cl, cl
        je       short L_fef1
    L_fee6:
        mov      byte ptr [eax], cl
        mov      cl, byte ptr [edx + 1]
        inc      eax
        inc      edx
        test     cl, cl
        jne      short L_fee6
    L_fef1:
        mov      byte ptr [eax], 0x6d
        mov      ecx, dword ptr [esp + 8]
        inc      eax
        test     ecx, ecx
        je       short L_ff01
        mov      byte ptr [eax], 0x6d
        inc      eax
    L_ff01:
        mov      edx, dword ptr [esp + 0x14]
        mov      cl, byte ptr [edx]
        test     cl, cl
        je       short L_ff16
    L_ff0b:
        mov      byte ptr [eax], cl
        mov      cl, byte ptr [edx + 1]
        inc      eax
        inc      edx
        test     cl, cl
        jne      short L_ff0b
    L_ff16:
        mov      byte ptr [eax], 0x73
        inc      eax
        mov      byte ptr [eax], 0x73
        mov      byte ptr [eax + 1], 0
        mov      edx, dword ptr [esp + 0x14]
        push     edx
        call     FreeImpl
        add      esp, 4
        xor      eax, eax
        pop      edi
        pop      esi
        add      esp, 8
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        /* === h2 (0x4cff60): prefs save/reload === */
        mov      eax, dword ptr [g_dispatchSave1446]
        push     ebx
        push     esi
        xor      ebx, ebx
        xor      esi, esi
        cmp      eax, ebx
        mov      si, word ptr [g_dispatchSave1461]
        push     edi
        je       L_0059
        push     OFFSET g_dispatchSave1456
        push     0xe
        push     esi
        push     1
        call     CrtGetLocaleInfo
        add      esp, 0x10
        mov      edi, eax
        push     OFFSET g_dispatchSave1457
        push     0xf
        push     esi
        push     1
        call     CrtGetLocaleInfo
        add      esp, 0x10
        or       edi, eax
        push     OFFSET g_dispatchSave1458
        push     0x10
        push     esi
        push     1
        call     CrtGetLocaleInfo
        add      esp, 0x10
        or       edi, eax
        mov      eax, dword ptr [g_dispatchSave1458]
        push     eax
        call     StringStripSlotReplace
        add      esp, 4
        cmp      edi, ebx
        je       short L_ffee
        mov      ecx, dword ptr [g_dispatchSave1456]
        push     ecx
        call     FreeImpl
        mov      edx, dword ptr [g_dispatchSave1457]
        add      esp, 4
        push     edx
        call     FreeImpl
        mov      eax, dword ptr [g_dispatchSave1458]
        add      esp, 4
        push     eax
        call     FreeImpl
        add      esp, 4
        mov      dword ptr [g_dispatchSave1456], ebx
        mov      dword ptr [g_dispatchSave1457], ebx
        mov      dword ptr [g_dispatchSave1458], ebx
        or       eax, 0xffffffff
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_ffee:
        mov      ecx, dword ptr [g_crtTimeFmtPrefs]
        mov      eax, dword ptr [ecx]
        cmp      eax, OFFSET g_dispatchSave110
        je       short L_002a
        push     eax
        call     FreeImpl
        mov      edx, dword ptr [g_crtTimeFmtPrefs]
        add      esp, 4
        mov      eax, dword ptr [edx + 4]
        push     eax
        call     FreeImpl
        mov      ecx, dword ptr [g_crtTimeFmtPrefs]
        add      esp, 4
        mov      edx, dword ptr [ecx + 8]
        push     edx
        call     FreeImpl
        add      esp, 4
    L_002a:
        mov      ecx, dword ptr [g_crtTimeFmtPrefs]
        mov      eax, dword ptr [g_dispatchSave1456]
        mov      dword ptr [ecx], eax
        mov      edx, dword ptr [g_crtTimeFmtPrefs]
        mov      eax, dword ptr [g_dispatchSave1457]
        mov      dword ptr [edx + 4], eax
        mov      ecx, dword ptr [g_crtTimeFmtPrefs]
        mov      edx, dword ptr [g_dispatchSave1458]
        mov      dword ptr [ecx + 8], edx
        jmp      L_0117
    L_0059:
        mov      eax, dword ptr [g_dispatchSave1456]
        push     eax
        call     FreeImpl
        mov      ecx, dword ptr [g_dispatchSave1457]
        add      esp, 4
        push     ecx
        call     FreeImpl
        mov      edx, dword ptr [g_dispatchSave1458]
        add      esp, 4
        push     edx
        call     FreeImpl
        add      esp, 4
        mov      dword ptr [g_dispatchSave1456], ebx
        mov      dword ptr [g_dispatchSave1457], ebx
        mov      dword ptr [g_dispatchSave1458], ebx
        push     2
        call     LoadArgPushCall
        mov      ecx, dword ptr [g_crtTimeFmtPrefs]
        add      esp, 4
        mov      dword ptr [ecx], eax
        mov      edx, dword ptr [g_crtTimeFmtPrefs]
        mov      eax, dword ptr [edx]
        cmp      eax, ebx
        jne      short L_00bc
        or       eax, 0xffffffff
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_00bc:
        mov      cx, word ptr [g_dispatchSave871]
        push     2
        mov      word ptr [eax], cx
        call     LoadArgPushCall
        mov      edx, dword ptr [g_crtTimeFmtPrefs]
        add      esp, 4
        mov      dword ptr [edx + 4], eax
        mov      eax, dword ptr [g_crtTimeFmtPrefs]
        mov      eax, dword ptr [eax + 4]
        cmp      eax, ebx
        jne      short L_00ec
        or       eax, 0xffffffff
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_00ec:
        push     2
        mov      byte ptr [eax], bl
        call     LoadArgPushCall
        mov      ecx, dword ptr [g_crtTimeFmtPrefs]
        add      esp, 4
        mov      dword ptr [ecx + 8], eax
        mov      edx, dword ptr [g_crtTimeFmtPrefs]
        mov      eax, dword ptr [edx + 8]
        cmp      eax, ebx
        jne      short L_0115
        or       eax, 0xffffffff
        pop      edi
        pop      esi
        pop      ebx
        ret
    L_0115:
        mov      byte ptr [eax], bl
    L_0117:
        mov      eax, dword ptr [g_crtTimeFmtPrefs]
        pop      edi
        pop      esi
        pop      ebx
        mov      ecx, dword ptr [eax]
        xor      eax, eax
        mov      dl, byte ptr [ecx]
        mov      dword ptr [g_dispatchSave111], 1
        mov      byte ptr [g_byte_00522bb4], dl
        ret
    }
}
