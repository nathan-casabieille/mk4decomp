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

extern unsigned int g_dispatchSave618;
extern void AudioMixerStep(void);
extern void CmpDivJmp(void);
extern void CopyThreeFields(void);
extern void MStackCall_MStackPush2ChainPrepend_00406600(void);
extern void MStackPop8(void);
extern void MStackPush8(void);
extern void MStackPushNegMul10(void);
extern void PushSetXfmMaskCallPop(void);
extern void SetJmp_ZeroAndDirty4(void);
extern void SetJmp_BootStateTriple(void);
extern void ThreeChanPackClamp(void);

__declspec(naked) void Phase1ChainExtendedInitLoop2(void)
{
    __asm {
        push    ebx
        push    esi
        push    0x2010
        call    ThreeChanPackClamp
        mov     eax, dword ptr [g_fightGroupHead]
        add     esp, 4
        push    eax
        call    CopyThreeFields
        add     esp, 4
        call    SetJmp_ZeroAndDirty4
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p1cei2_ret
        mov     al, byte ptr [g_xformDirtyFlags]
        mov     ebx, 4
        test    al, bl
        je      L_p1cei2_ret
        call    MStackPush8
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p1cei2_ret
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     edx, offset g_dispatchSave618
        shr     edx, 2
        mov     dword ptr [g_eventQueueIdx], ecx
        mov     dword ptr [g_walkCallback], edx
        call    PushSetXfmMaskCallPop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p1cei2_ret
        test    byte ptr [g_xformDirtyFlags], bl
        jne     L_p1cei2_tailjmp
        mov     eax, dword ptr [g_fightGroupHead]
        mov     dword ptr [eax*4 + 0x30], 0x42
        mov     dword ptr [g_walkCallback], 0x60000
        call    AudioMixerStep
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p1cei2_ret
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     edx, dword ptr [g_walkCallback]
        mov     dword ptr [ecx*4 + 0x68], edx
        mov     eax, dword ptr [g_fightGroupHead]
        mov     dword ptr [eax*4 + 0x80], 0x1999
        mov     dword ptr [g_walkCallback], 0x41
        call    MStackPushNegMul10
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p1cei2_ret
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     edx, dword ptr [g_eventQueueIdx]
        shl     edx, 2
        lea     eax, [ecx*4]
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [eax + 0x6C], ecx
        mov     ecx, dword ptr [g_eventQueueCurrent]
        mov     dword ptr [eax + 0x74], ecx
        mov     ecx, dword ptr [g_walkCallback]
        lea     ecx, [ecx + ecx*2]
        lea     ecx, [ecx + ecx*4]
        shl     ecx, 3
        mov     dword ptr [g_walkCallback], ecx
        mov     esi, dword ptr [edx + 0x54]
        add     ecx, esi
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x54], ecx
        mov     ecx, dword ptr [g_eventQueueCurrent]
        lea     ecx, [ecx + ecx*2]
        lea     ecx, [ecx + ecx*4]
        shl     ecx, 3
        mov     dword ptr [g_eventQueueCurrent], ecx
        mov     esi, dword ptr [edx + 0x5C]
        add     ecx, esi
        mov     dword ptr [g_eventQueueCurrent], ecx
        mov     dword ptr [eax + 0x5C], ecx
        mov     edx, dword ptr [edx + 0x58]
        sub     edx, 0x3333
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [eax + 0x58], edx
        call    SetJmp_BootStateTriple
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p1cei2_ret
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     edx, dword ptr [eax*4]
        or      edx, 8
        mov     dword ptr [eax*4], edx
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     dword ptr [edx*4 + 0x48], 0xA666
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     dword ptr [eax*4 + 0x14], 0xFF
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, 0x004BA0E0
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x10], eax
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [eax*4 + 0x20]
        or      ch, 0x40
        mov     dword ptr [eax*4 + 0x20], ecx
        mov     dword ptr [g_walkCallback], 1
        call    CmpDivJmp
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p1cei2_ret
        test    byte ptr [g_xformDirtyFlags], bl
        jne     L_p1cei2_after_loop
        mov     dword ptr [g_eventQueueCurrent], 0
        mov     dword ptr [g_eventQueueWorkType], 0
        mov     esi, 0xFFFE8000
    L_p1cei2_loop_top:
        mov     edx, dword ptr [g_eventQueueIdx]
        mov     dword ptr [g_walkCallback], esi
        push    esi
        mov     eax, dword ptr [edx*4 + 0x6C]
        push    eax
        call    Mul10Tail
        mov     edx, dword ptr [g_eventQueueCurrent]
        mov     ecx, dword ptr [g_eventQueueIdx]
        add     edx, eax
        add     esp, 8
        mov     dword ptr [g_eventQueueCurrent], edx
        mov     dword ptr [g_walkCallback], esi
        mov     edx, dword ptr [ecx*4 + 0x74]
        push    esi
        push    edx
        call    Mul10Tail
        mov     ecx, dword ptr [g_eventQueueWorkType]
        mov     dword ptr [g_walkCallback], eax
        add     ecx, eax
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     dword ptr [g_eventQueueWorkType], ecx
        mov     ecx, dword ptr [g_eventQueueCurrent]
        mov     dword ptr [eax*4 + 4], ecx
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [g_eventQueueWorkType]
        add     esp, 8
        mov     dword ptr [edx*4 + 0x0C], eax
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     edx, dword ptr [g_xformDirtyFlags]
        mov     eax, dword ptr [ecx*4]
        or      edx, ebx
        test    eax, eax
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [g_xformDirtyFlags], edx
        je      L_p1cei2_after_loop
        mov     ecx, edx
        xor     ecx, ebx
        test    eax, eax
        mov     dword ptr [g_xformDirtyFlags], ecx
        jne     L_p1cei2_loop_top
    L_p1cei2_after_loop:
        mov     edx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_currentNodeIdx], edx
        call    MStackCall_MStackPush2ChainPrepend_00406600
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p1cei2_ret
    L_p1cei2_tailjmp:
        call    MStackPop8
    L_p1cei2_ret:
        pop     esi
        pop     ebx
        ret
    }
}
