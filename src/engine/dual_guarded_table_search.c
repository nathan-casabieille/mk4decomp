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

/* @addr 0x004708c0 (186b game) - dual-guarded packed-table search by chain[+0x34].
 *   call MStackPush3CmpCall. if (!(g_xformDirtyFlags & 1)): return 0.
 *   eax = [0x535ddc]; g_walkCallback = eax; if (eax > 0x10000): return 0.
 *   call CmpP1GTSetup_00470980; g_scaledInit = packed_ptr(0x4ebe90);
 *   ecx = chain[scaledInit]; scaledInit++;
 *   loop: g_eventQueueWorkType = ecx; if (ecx < 0) break;
 *     esi = g_xformEntityIdx; if (chain[esi+0x34] == ecx) goto found.
 *     ecx = chain[scaledInit++]; g_eventQueueWorkType = ecx; scaledInit++ again;
 *     ecx = chain[scaledInit]; if (ecx >= 0) goto loop.
 *   break: return 0.
 *   found: g_walkCallback = chain[scaledInit++]; call SnapshotDispatchMStack;
 *     call ScaledZeroFour; return 1.
 */
extern unsigned int g_table_00535ddc;
extern void CmpP1GTSetup_00470980(void);
extern void SnapshotDispatchMStack_00491350(void);

extern unsigned int g_matrixStack_arr;

__declspec(naked) void DualGuardedTableSearch_004708c0(void) {
    __asm {
        push    esi
        call    MStackPush3CmpCall
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   75h
        _emit   04h
        xor     eax, eax
        pop     esi
        ret
        mov     eax, dword ptr [g_table_00535ddc]
        cmp     eax, 0x00010000
        mov     dword ptr [g_walkCallback], eax
        _emit   7eh
        _emit   04h
        xor     eax, eax
        pop     esi
        ret
        call    CmpP1GTSetup_00470980
        mov     eax, 0x004ebe90
        shr     eax, 2
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     ecx, [eax*4 + g_matrixStack_arr]
        inc     eax
        test    ecx, ecx
        mov     dword ptr [g_eventQueueWorkType], ecx
        mov     dword ptr [g_scaledInit_00542044], eax
        _emit   7ch
        _emit   41h
        mov     esi, dword ptr [g_xformEntityIdx]
        mov     edx, [esi*4 + 0x34]
        cmp     edx, ecx
        mov     dword ptr [g_eventQueueCurrent], edx
        _emit   74h
        _emit   2eh
        mov     ecx, [eax*4 + g_matrixStack_arr]
        inc     eax
        mov     dword ptr [g_eventQueueWorkType], ecx
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     ecx, [eax*4 + g_matrixStack_arr]
        inc     eax
        test    ecx, ecx
        mov     dword ptr [g_eventQueueWorkType], ecx
        mov     dword ptr [g_scaledInit_00542044], eax
        _emit   7dh
        _emit   0c5h
        xor     eax, eax
        pop     esi
        ret
        mov     edx, [eax*4 + g_matrixStack_arr]
        inc     eax
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [g_scaledInit_00542044], eax
        call    SnapshotDispatchMStack_00491350
        call    ScaledZeroFour
        mov     eax, 1
        pop     esi
        ret
    }
}
