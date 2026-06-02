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

extern unsigned int g_dispatchSave105_00535d14;
extern void NodeUnlink_0041f710(void);

__declspec(naked) void BootScheduledNodeTimerWalk_0041f570(void)
{
    __asm
    {
        push    ebx
        push    esi
        mov     esi, dword ptr [g_nodeListTail]
        xor     ebx, ebx
        cmp     esi, ebx
        je      L_bsntw_done
        push    edi
        push    ebp
        or      ebp, 0xffffffff
    L_bsntw_loop:
        mov     eax, dword ptr [g_gameMode]
        cmp     eax, ebx
        je      short L_bsntw_proc
        cmp     eax, dword ptr [esi + 0xd8]
        je      short L_bsntw_proc
        cmp     dword ptr [esi + 0xe0], 0x11
        jne     L_bsntw_nextNode
    L_bsntw_proc:
        dec     word ptr [esi + 0xdc]
        cmp     word ptr [esi + 0xdc], bx
        jg      L_bsntw_checkDead
        mov     eax, esi
        sar     eax, 2
        mov     dword ptr [g_baseSel], eax
        mov     ecx, dword ptr [eax*4 + 0x14]
        mov     dword ptr [g_eventQueueNotMask], ecx
        mov     edx, dword ptr [eax*4 + 0x18]
        mov     dword ptr [g_eventQueueChild], edx
        mov     ecx, dword ptr [eax*4 + 0x24]
        mov     dword ptr [g_eventQueueEnd], ecx
        mov     edx, dword ptr [eax*4 + 0x28]
        mov     dword ptr [g_eventQueueIdx], edx
        mov     ecx, dword ptr [eax*4 + 8]
        mov     dword ptr [g_walkCallback], ecx
        mov     edx, dword ptr [eax*4 + 0x2c]
        mov     dword ptr [g_fightGroupHead], edx
        mov     ecx, dword ptr [eax*4 + 0x1c]
        mov     dword ptr [g_currentNodeFlags], ecx
        mov     edx, dword ptr [eax*4 + 0x20]
        mov     dword ptr [g_xformScratch2088], edx
        mov     eax, dword ptr [eax*4 + 8]
        mov     dword ptr [esi + 0xd8], eax
        mov     dword ptr [g_framePauseFlag], ebx
        mov     ecx, dword ptr [esi + 0xd8]
        mov     dword ptr [g_dispatchSave105_00535d14], ecx
        call    dword ptr [esi + 0xd8]
        mov     eax, dword ptr [esi + 0xd8]
        cmp     eax, ebp
        je      short L_bsntw_checkDead
        cmp     eax, ebx
        jbe     short L_bsntw_checkDead
        mov     edx, dword ptr [g_baseSel]
        mov     eax, dword ptr [edx*4 + 8]
        mov     dword ptr [esi + 0xd8], eax
        mov     ecx, dword ptr [g_baseSel]
        mov     edx, dword ptr [g_eventQueueNotMask]
        lea     eax, [ecx*4]
        mov     dword ptr [eax + 0x14], edx
        mov     ecx, dword ptr [g_eventQueueChild]
        mov     dword ptr [eax + 0x18], ecx
        mov     edx, dword ptr [g_currentNodeFlags]
        mov     dword ptr [eax + 0x1c], edx
        mov     ecx, dword ptr [g_xformScratch2088]
        mov     dword ptr [eax + 0x20], ecx
        mov     edx, dword ptr [g_pendingNodeType]
        mov     dword ptr [eax + 0x10], edx
        mov     ecx, dword ptr [g_eventQueueEnd]
        mov     dword ptr [eax + 0x24], ecx
        mov     edx, dword ptr [g_eventQueueIdx]
        mov     dword ptr [eax + 0x28], edx
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     dword ptr [eax + 0x2c], ecx
        mov     dx, word ptr [g_pendingNodeType]
        mov     word ptr [esi + 0xdc], dx
    L_bsntw_checkDead:
        cmp     dword ptr [esi + 0xd8], ebp
        jne     short L_bsntw_nextNode
        mov     edi, dword ptr [esi + 0xe4]
        push    esi
        call    NodeUnlink_0041f710
        add     esp, 4
        mov     esi, edi
        jmp     short L_bsntw_loopEnd
    L_bsntw_nextNode:
        mov     esi, dword ptr [esi + 0xe4]
    L_bsntw_loopEnd:
        cmp     esi, ebx
        jne     L_bsntw_loop
        pop     ebp
        pop     edi
    L_bsntw_done:
        mov     dword ptr [g_framePauseFlag], ebx
        pop     esi
        pop     ebx
        ret
    }
}
