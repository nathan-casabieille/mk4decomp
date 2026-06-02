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

/* @addr 0x004c5ad0 (151b boot/crt) - fseek-like wrapper (file flush + IO + errno).
 *   arg2 (whence) must be in {0,1,2}; else: set errno=EINVAL, return -1.
 *   FILE* esi = arg1; if (!(flags & 0x83)) errno fail.
 *   Mask bit 4 in flags; if (whence == 1): offset += saved_pos (call FileTellAdjusted_004c58e0).
 *   call FFlushImpl_004c69a0; reload flags.
 *   if (flag&0x80): flags &= ~3; jmp do-io.
 *   else: skip if flag & (1|8) or (ah & 4); set [esi+0x18] = 0x200.
 *   do-io: call IOWrapper_004c8dd0(offset, whence, [esi+0x10], 0); add esp,c.
 *   Return ((eax+1 != 0) ? 0 : -1) - 1 (encoded via neg/sbb/neg/dec).
 *   Fail: call CallAdd8; *eax = EINVAL (0x16); return -1.
 */
extern void Crt_errno_004c8ba0(void);
extern void FFlushImpl_004c69a0(void);
extern void FileTellAdjusted_004c58e0(void);
extern void IOWrapper_004c8dd0(void);

__declspec(naked) void FSeekImpl_004c5ad0(void) {
    __asm {
        push    esi
        mov     esi, [esp + 8]
        push    edi
        mov     eax, [esi + 0x0c]
        test    al, 0x83
        _emit   74h
        _emit   79h
        mov     edi, [esp + 0x14]
        test    edi, edi
        _emit   74h
        _emit   0ah
        cmp     edi, 1
        _emit   74h
        _emit   05h
        cmp     edi, 2
        _emit   75h
        _emit   67h
        and     al, 0xef
        cmp     edi, 1
        mov     [esi + 0x0c], eax
        _emit   75h
        _emit   15h
        push    esi
        call    FileTellAdjusted_004c58e0
        mov     ecx, [esp + 0x14]
        add     esp, 4
        add     ecx, eax
        xor     edi, edi
        mov     [esp + 0x10], ecx
        push    esi
        call    FFlushImpl_004c69a0
        mov     eax, [esi + 0x0c]
        add     esp, 4
        test    al, 0x80
        _emit   74h
        _emit   07h
        and     al, 0xfc
        mov     [esi + 0x0c], eax
        _emit   0ebh
        _emit   14h
        test    al, 1
        _emit   74h
        _emit   10h
        test    al, 8
        _emit   74h
        _emit   0ch
        test    ah, 4
        _emit   75h
        _emit   07h
        mov     dword ptr [esi + 0x18], 0x200
        mov     eax, [esp + 0x10]
        mov     ecx, [esi + 0x10]
        push    edi
        push    eax
        push    ecx
        call    IOWrapper_004c8dd0
        add     esp, 0x0c
        inc     eax
        neg     eax
        sbb     eax, eax
        neg     eax
        dec     eax
        pop     edi
        pop     esi
        ret
        call    Crt_errno_004c8ba0
        mov     dword ptr [eax], 0x16
        pop     edi
        or      eax, 0xffffffff
        pop     esi
        ret
    }
}
