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

extern unsigned int g_phase4SlotArr_00511fa4;
extern unsigned int g_load_0052ab10;
extern unsigned int g_particleEmitterNode;
extern unsigned int g_phase1ModelChain_0053e35c;
extern void AudioMixerStep(void);
extern void BootSetJmpStoreThenChainTriple(void);
extern void ChainWalkPushPop(void);
extern void MStackCall_004062f0(void);
extern void MStackCall_00406740(void);
extern void MStackPop8(void);
extern void MStackPush8(void);
extern void MStackPushDispatchBitGate(void);
extern void SetJmp_00405420(void);
extern void SetJmp_00408d20(void);
extern void StoreDoubleNegPauseSubStore(void);
extern void TableLookupCall_00489ff0(void);

__declspec(naked) void Phase4SlotInitPackedHelper(void)
{
    __asm {
        push    esi
        call    MStackPush8
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4sip_A_ret
        mov     eax, dword ptr [g_currentNodeIdx]
        mov     ecx, offset g_phase4SlotArr_00511fa4
        shr     ecx, 2
        mov     dword ptr [g_pendingNodeType], eax
        mov     dword ptr [g_xformEntityIdx], ecx
        call    MStackPushDispatchBitGate
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4sip_A_ret
        test    byte ptr [g_xformDirtyFlags], 4
        jne     L_p4sip_A_tailjmp
        mov     ecx, dword ptr [g_fightGroupHead]
        lea     eax, [ecx*4]
        mov     dword ptr [ecx*4 + 0x30], 0xA3
        mov     ecx, dword ptr [g_particleEmitterNode]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x3C], ecx
        mov     ecx, dword ptr [eax + 0x34]
        or      ch, 0x40
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x34], ecx
        mov     edx, dword ptr [g_pendingNodeType]
        mov     ecx, dword ptr [edx*4]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x54], ecx
        mov     ecx, dword ptr [g_pendingNodeType]
        inc     ecx
        mov     dword ptr [g_pendingNodeType], ecx
        mov     ecx, dword ptr [ecx*4]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x58], ecx
        mov     ecx, dword ptr [g_pendingNodeType]
        inc     ecx
        mov     dword ptr [g_pendingNodeType], ecx
        mov     ecx, dword ptr [ecx*4]
        mov     dword ptr [eax + 0x5C], ecx
        mov     edx, dword ptr [g_pendingNodeType]
        inc     edx
        mov     ecx, 0x13333
        mov     dword ptr [g_pendingNodeType], edx
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x60], ecx
        mov     eax, dword ptr [g_load_0052ab10]
        mov     dword ptr [g_eventQueueTotal], eax
        mov     edx, dword ptr [eax*4 + 0x64]
        neg     edx
        mov     dword ptr [g_walkCallback], edx
        call    BootMod6487eClampAndChainMul10
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4sip_A_ret
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [eax*4 + 0x64], ecx
        mov     dword ptr [g_walkCallback], 0x1999
        lea     esi, [eax*4]
        call    StoreDoubleNegPauseSubStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4sip_A_ret
        mov     edx, dword ptr [g_walkCallback]
        mov     dword ptr [esi + 0x6C], edx
        mov     dword ptr [g_walkCallback], 0x1999
        call    StoreDoubleNegPauseSubStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4sip_A_ret
        mov     eax, dword ptr [g_walkCallback]
        mov     dword ptr [esi + 0x74], eax
        mov     dword ptr [g_walkCallback], 0xCCC
        call    AudioMixerStep
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4sip_A_ret
        mov     ecx, dword ptr [g_walkCallback]
        add     ecx, 0xFFFFD99A
        mov     dword ptr [esi + 0x70], ecx
        mov     dword ptr [g_walkCallback], 0x9999
        call    StoreDoubleNegPauseSubStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4sip_A_ret
        mov     edx, dword ptr [g_walkCallback]
        mov     dword ptr [esi + 0x80], edx
        mov     dword ptr [g_walkCallback], 0xF5C
        call    StoreDoubleNegPauseSubStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4sip_A_ret
        mov     eax, dword ptr [g_walkCallback]
        mov     dword ptr [esi + 0x7C], eax
        mov     dword ptr [g_walkCallback], 0xF5C
        call    StoreDoubleNegPauseSubStore
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4sip_A_ret
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [esi + 0x78], ecx
        call    SetJmp_00408d20
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4sip_A_ret
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     eax, 0x00416280
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x10], eax
        call    MStackCall_004062f0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4sip_A_ret
    L_p4sip_A_tailjmp:
        call    MStackPop8
    L_p4sip_A_ret:
        pop     esi
        ret
    L_p4sip_B:
        mov     eax, dword ptr [g_gameMode]
        test    eax, eax
        jne     L_p4sip_B_ret
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_fightGroupHead]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], ecx
        call    ChainWalkPushPop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4sip_B_ret
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_walkCallback], 0x168
        mov     eax, dword ptr [ecx*4 + 0x70]
        add     eax, 0x168
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x70], eax
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [edx*4 + 0x58]
        sub     eax, 0xCCC
        mov     dword ptr [g_walkCallback], eax
        js      L_p4sip_B_pop1
        call    SetJmp_00405420
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4sip_B_ret
        test    byte ptr [g_xformDirtyFlags], 4
        je      L_p4sip_B_skip_paint
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, 0xFFFFE667
        mov     dword ptr [ecx*4 + 0x70], 0xFFFFF5C3
        mov     edx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x58], eax
        mov     eax, dword ptr [g_fightGroupHead]
        lea     ecx, [eax + 0x15]
        add     eax, 0x1B
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [g_xformEntityIdx], eax
        call    BootSetJmpStoreThenChainTriple
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4sip_B_ret
    L_p4sip_B_skip_paint:
        mov     eax, dword ptr [g_phase1ModelChain_0053e35c]
        and     eax, 1
        mov     dword ptr [g_eventQueueCurrent], eax
        add     eax, 0x13
        mov     dword ptr [g_walkCallback], eax
        call    TableLookupCall_00489ff0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4sip_B_ret
        call    MStackCall_00406740
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_p4sip_B_ret
        mov     dword ptr [g_currentNodeIdx], 0
    L_p4sip_B_pop1:
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_fightGroupHead], edx
        mov     dword ptr [g_matrixStackTop], eax
    L_p4sip_B_ret:
        ret
    }
}
