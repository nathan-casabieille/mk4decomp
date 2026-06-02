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

/* @addr 0x004ac3f0 (189b audio) - aux audio devcaps query (auxGetDevCapsA via [0x4d2244]).
 *   Frame: sub esp, 0x1c; push esi, edi.
 *   call Helper_AuxAudio_PostInit; if (rv == 0) fail.
 *   ecx = [0x5438e8] (device id); edi = arg[0]; esi = [0x4d2244] (function ptr).
 *   Build mciSendCommandA-style packet on stack (cmd 0x814 = MCI_GETDEVCAPS, flags 0x4001, edi).
 *   esi(ecx, 0x814, 0x110, &caps); if (rv != 0) fail; check caps.devType == 0x440; else fail.
 *   Second call: cmd 0x80d (MCI_INFO), flags 2, no edi store; esi(eax, 0x80d, 0x400, &stack8).
 *   Third call: cmd 0x814 again with flags 1, edi.
 *   On success: return ((caps[+0x18] & 0xff) * 0x3c) | (caps[+0x18] >> 8 & 0xff).
 *     (eax | edx where edx = result*0x3c (= eax * 5 * 4 * 3? Actually lea+shl gives *60))
 *   Wait: eax_low *= 3; eax *= 5 ((eax + eax*4)); shl 2 → *60 total. So eax_low * 60 + (caps >> 8 & 0xff).
 */
extern unsigned int g_iat_mciSendCommandA;
extern u32 g_audioPreState;
extern void Helper_AuxAudio_PostInit(void);

__declspec(naked) void AuxAudioDevCapsQuery(void) {
    __asm {
        sub     esp, 0x1c
        push    esi
        push    edi
        call    Helper_AuxAudio_PostInit
        test    eax, eax
        _emit   0fh
        _emit   84h
        _emit   0a3h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     ecx, dword ptr [g_audioPreState]
        mov     edi, [esp + 0x28]
        mov     esi, dword ptr [g_iat_mciSendCommandA]
        lea     eax, [esp + 0x14]
        push    eax
        push    0x110
        push    0x0814
        push    ecx
        mov     dword ptr [esp + 0x2c], 0x00004001
        mov     [esp + 0x30], edi
        call    esi
        test    eax, eax
        _emit   75h
        _emit   71h
        cmp     dword ptr [esp + 0x18], 0x00000440
        _emit   75h
        _emit   67h
        mov     eax, dword ptr [g_audioPreState]
        lea     edx, [esp + 0x08]
        push    edx
        push    0x400
        push    0x080d
        push    eax
        mov     dword ptr [esp + 0x1c], 2
        call    esi
        mov     edx, dword ptr [g_audioPreState]
        lea     ecx, [esp + 0x14]
        push    ecx
        push    0x110
        push    0x0814
        push    edx
        mov     dword ptr [esp + 0x2c], 1
        mov     [esp + 0x30], edi
        call    esi
        test    eax, eax
        _emit   75h
        _emit   20h
        mov     eax, [esp + 0x18]
        xor     ecx, ecx
        mov     cl, ah
        and     eax, 0xff
        lea     eax, [eax + eax*2]
        lea     edx, [eax + eax*4]
        shl     edx, 2
        add     ecx, edx
        mov     eax, ecx
        pop     edi
        pop     esi
        add     esp, 0x1c
        ret
        pop     edi
        xor     eax, eax
        pop     esi
        add     esp, 0x1c
        ret
    }
}
