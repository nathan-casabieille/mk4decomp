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

/* @addr 0x004cd110 (161b crt) - _setmode-like (FD slot -> reserved 32-fd table; binary/text + std handle).
 *   fd (ecx) must be < [0xfa0ee0]; else errno = EBADF (9).
 *   table = [0xfa0de0 + (fd/32)*4]; slot_idx = (fd%32)*36; check [table][slot] != -1 else fail.
 *   If [0x520064] == 1: switch (fd) {
 *     case 0: SetStdHandle(STD_INPUT=-10, arg2); fall to default cleanup.
 *     case 1: SetStdHandle(STD_OUTPUT=-11, arg2); cleanup; ret.
 *     case 2: SetStdHandle(STD_ERROR=-12, arg2); cleanup; ret.
 *     default: cleanup. }
 *   Cleanup: *[table] [slot] = arg2; return 0.
 *   Fail: __errno() = 9; clear another errno-like ptr; return -1.
 */
extern unsigned int g_SetStdHandle_004d20d4;
extern unsigned int g_crtFdCloseSlot_00520064;
extern unsigned int g_dispatchSave1469_00fa0ee0;
extern void Crt_doserrno_004c8bb0(void);
extern void Crt_errno(void);

extern unsigned int g_arr_00fa0de0;

__declspec(naked) void SetFdMode_004cd110(void) {
    __asm {
        mov     ecx, [esp + 4]
        mov     eax, dword ptr [g_dispatchSave1469_00fa0ee0]
        push    ebx
        push    esi
        cmp     ecx, eax
        push    edi
        _emit   73h
        _emit   74h
        mov     eax, ecx
        sar     eax, 5
        lea     edi, [eax*4 + g_arr_00fa0de0]
        mov     eax, ecx
        and     eax, 0x1f
        mov     edx, [edi]
        lea     esi, [eax + eax*8]
        shl     esi, 2
        cmp     dword ptr [edx + esi], 0xffffffff
        _emit   75h
        _emit   55h
        mov     eax, dword ptr [g_crtFdCloseSlot_00520064]
        mov     ebx, [esp + 0x14]
        cmp     eax, 1
        _emit   75h
        _emit   3ch
        sub     ecx, 0
        _emit   74h
        _emit   2eh
        dec     ecx
        _emit   74h
        _emit   17h
        dec     ecx
        _emit   75h
        _emit   31h
        push    ebx
        push    0xfffffff4
        call    dword ptr [g_SetStdHandle_004d20d4]
        mov     eax, [edi]
        mov     [eax + esi], ebx
        xor     eax, eax
        pop     edi
        pop     esi
        pop     ebx
        ret
        push    ebx
        push    0xfffffff5
        call    dword ptr [g_SetStdHandle_004d20d4]
        mov     eax, [edi]
        mov     [eax + esi], ebx
        xor     eax, eax
        pop     edi
        pop     esi
        pop     ebx
        ret
        push    ebx
        push    0xfffffff6
        call    dword ptr [g_SetStdHandle_004d20d4]
        mov     eax, [edi]
        mov     [eax + esi], ebx
        xor     eax, eax
        pop     edi
        pop     esi
        pop     ebx
        ret
        call    Crt_errno
        mov     dword ptr [eax], 9
        call    Crt_doserrno_004c8bb0
        pop     edi
        mov     dword ptr [eax], 0
        pop     esi
        or      eax, 0xffffffff
        pop     ebx
        ret
    }
}
