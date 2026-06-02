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

/* @addr 0x004ab380 (191b audio) - linked-list builder for ESI=g_eventQueueTotal array.
 *   ebx = g_xformEntityIdx; esi = g_eventQueueTotal; edi = g_pendingNodeType.
 *   [esi+0] = 0; [esi+4] = ebx; [esi+8] = g_eventQueueEnd.
 *   if (g_eventQueueEnd == 0): return.
 *   [esi+0] = g_scaledInit; eax = ebx + g_scaledInit + 1; [eax*4] = esi.
 *   [0x53a1ac] = [esi+8]; if (<= 1) skip loop;
 *   [0x53a1ac] -= 2; eax = g_scaledInit + edi;
 *   loop: push ebp; ecx = g_scaledInit*4; [ecx + ebx*4 + 4] = esi; [ecx + ebx*4] = eax;
 *     ebp = [0x53a1ac]; edx = eax; ecx = eax*4; eax += edi; ebp--;
 *     [0x53a1ac] = ebp; if (ebp >= 0) loop;
 *   pop ebp.
 *   [ebx + edx] *= 0; [(ebx + edx + 1)*4] = esi.
 *   pop edi/esi/ebx.
 */
extern unsigned int g_matrixStack_arr;

__declspec(naked) void LinkedListBuilder_004ab380(void) {
    __asm {
        push    ebx
        mov     ebx, dword ptr [g_xformEntityIdx]
        push    esi
        mov     esi, dword ptr [g_eventQueueTotal]
        push    edi
        mov     edi, dword ptr [g_pendingNodeType]
        mov     dword ptr [esi*4 + g_matrixStack_arr], 0
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     [esi*4 + 4], eax
        mov     ecx, dword ptr [g_eventQueueEnd]
        mov     [esi*4 + 8], ecx
        mov     eax, dword ptr [g_eventQueueEnd]
        test    eax, eax
        _emit   74h
        _emit   79h
        mov     edx, dword ptr [g_scaledInit_00542044]
        mov     [esi*4 + g_matrixStack_arr], edx
        lea     eax, [ebx + edx + 1]
        mov     [eax*4 + g_matrixStack_arr], esi
        mov     eax, [esi*4 + 8]
        cmp     eax, 1
        mov     dword ptr [g_xformLoopCounter], eax
        _emit   7eh
        _emit   37h
        sub     eax, 2
        mov     dword ptr [g_xformLoopCounter], eax
        lea     eax, [edx + edi]
        _emit   78h
        _emit   2ah
        push    ebp
        lea     ecx, [edx*4 + g_matrixStack_arr]
        mov     [ecx + ebx*4 + 4], esi
        mov     [ecx + ebx*4], eax
        mov     ebp, dword ptr [g_xformLoopCounter]
        mov     edx, eax
        lea     ecx, [eax*4 + g_matrixStack_arr]
        add     eax, edi
        dec     ebp
        mov     dword ptr [g_xformLoopCounter], ebp
        _emit   79h
        _emit   0dfh
        pop     ebp
        lea     ecx, [ebx + edx]
        lea     edx, [ebx + edx + 1]
        mov     dword ptr [ecx*4 + g_matrixStack_arr], 0
        mov     [edx*4 + g_matrixStack_arr], esi
        pop     edi
        pop     esi
        pop     ebx
        ret
    }
}
