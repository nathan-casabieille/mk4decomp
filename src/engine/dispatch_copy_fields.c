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

/* @addr 0x0043ec80 (227b game) - dispatch then 6-field copy.
 *   shr 0x004ec8f8 >> 2 -> g_xformEntityIdx; call DispatcherComplex260; if pause? ret.
 *   if bit2 of g_xformDirtyFlags set: copy g_cj_00542058 to g_dispatchCopyField_00537e9c, ret.
 *   else: scaledInit[+0x30] = 0x78; call MStackCall; if pause? ret.
 *   else: copy fields +0x54/+0x58/+0x5c (via g_walkCallback temp) and +0x64 from
 *   g_cj_00542058<<2 to g_scaledInit_00542044<<2; zero +0x60/+0x68; copy
 *   scaledInit to g_dispatchCopyField_00537e9c; merge low bit of [+0x34]; ret.
 */
extern unsigned int g_dispatchCopyField_00537e9c;
extern void MStackCall_00406340(void);

void DispatchCopyFields_0043ec80(void) {
    __asm {
        mov     eax, 0x004ec8f8
        shr     eax, 2
        mov     dword ptr [g_xformEntityIdx], eax
        call    DispatcherComplex260_00407030
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   0c3h
        _emit   00h
        _emit   00h
        _emit   00h
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   74h
        _emit   0dh
        mov     ecx, dword ptr [g_cj_00542058]
        mov     dword ptr [g_dispatchCopyField_00537e9c], ecx
        ret
        mov     edx, dword ptr [g_scaledInit_00542044]
        mov     eax, 0x78
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x30], eax
        call    MStackCall_00406340
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   84h
        _emit   00h
        _emit   00h
        _emit   00h
        mov     ecx, dword ptr [g_cj_00542058]
        mov     eax, dword ptr [g_scaledInit_00542044]
        shl     ecx, 2
        shl     eax, 2
        mov     edx, dword ptr [ecx + 0x54]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 0x54], edx
        mov     edx, dword ptr [ecx + 0x58]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 0x58], edx
        mov     edx, dword ptr [ecx + 0x5c]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 0x5c], edx
        mov     edx, dword ptr [ecx + 0x64]
        mov     dword ptr [eax + 0x64], edx
        mov     dword ptr [g_walkCallback], 0
        mov     dword ptr [eax + 0x60], 0
        mov     edx, dword ptr [g_walkCallback]
        mov     dword ptr [eax + 0x68], edx
        mov     edx, dword ptr [g_scaledInit_00542044]
        mov     dword ptr [g_dispatchCopyField_00537e9c], edx
        mov     edx, dword ptr [eax + 0x34]
        mov     dword ptr [g_walkCallback], edx
        mov     ecx, dword ptr [ecx + 0x34]
        and     ecx, 1
        _emit   83h
        _emit   0e2h
        _emit   0feh
        or      edx, ecx
        mov     dword ptr [g_eventQueueCurrent], ecx
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 0x34], edx
        }
}

