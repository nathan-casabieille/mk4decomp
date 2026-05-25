/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_state_004d57ac;
extern unsigned int g_scaledInit_00542044;
extern packed_ptr g_xformEntityIdx;
extern u32 g_eventQueueEnd;
extern unsigned int g_baseSel_00542060;
extern u32 g_eventQueueWorkType;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern u32 g_framePauseFlag;
extern unsigned int g_state_0053a718;
extern unsigned int g_eventQueueTotal;
extern unsigned int g_eventQueueCurrent;
extern unsigned int g_currentNodeFlags;
extern unsigned int g_xformDirtyFlags;
extern unsigned int g_xformScratch2088;
extern unsigned int g_xformScratch94;
extern unsigned int g_table_00535ddc;
extern unsigned int g_active_00537e88;
extern unsigned int g_active_0053a408;
extern unsigned int g_state_00537f94;
extern unsigned int g_eventQueueChild;
extern u32 g_pendingNodeType;

extern void StoreTwoCall_0049cb40(int, int);
extern void SetJmp_0049cb90(void);
extern void Thunk_0049cbd0(void);
extern void ScaledZeroFour_00490740(void);
extern void WalkCbSubMul10_00431d50(void);
extern void Mul10Tail_00404af0(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10_00407510(void);
extern void SpawnListBatchLoader_00477710(void);
extern void MStackPush2TableNot_00426230(void);
extern void GuardedChainCmpDualBitXor_004299a0(void);
extern void ScaledLoadDecJmp_00429710(void);
extern void ScaledStoreCurDirtyClear_004296f0(void);
extern void MStackBitmaskIncMod_00492450(void);
extern void MStackBitmaskUpdate_00492510(void);
extern void Push1eCallTestDirtyLoop_004923b0(void);
extern void MStackLoopFieldInit_00492280(void);
extern void TaggedSceneDispatch_004be690(void);
extern void CallPauseDirty4StackPushFn_004839d0(void);
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall_004398b0(void);
extern void QuadBlockArgInstallChain_0043a950(void);
extern void InstallSelfChainSet84_80CallW_004363f0(void);
extern void Wrapper_00436490(void);
extern void MoveFsmCluster_004364a0(void);
extern void CallPauseTestByteJmpCalls_004390f0(void);
extern void InstallSelfFullPath_0047a840(void);
extern void InstallSelfCountdownChain_0047a950(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore_00476880(void);
extern void Thunk_004bd5c0(void);
extern void AllocSlotPushTripleGlobals_00427470(void);
extern void MStackPop4Rewrite_004274f0(void);
extern void Push70CallScaleArith_00457ad0(void);
extern void StreamChainStringInstall_00457900(void);
extern void MStackFrameCdeclDouble_004903f0(void);
extern void ChainTableWalkStore_004917e0(void);
extern void Push16Call_00489f50(void);
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm_0048f2a0(void);
extern void StackPopDispatchTagged_0041f780(void);
extern unsigned int g_eventQueueNotMask;
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit_0053a180;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_state_0053a7b0;
extern unsigned int g_data_0053a770;
extern unsigned int g_data_0053a46c;

extern void ScaledArrStore_004298c0(void);
extern void DualFieldAddSubStore_00470340(void);
extern void IterStepDualStore_00490b40(int);
extern void ScaledXorStore_004900f0(void);
extern void ChainWalkInstall_0049b7c0(void);
extern void FpuSqrtMul_004ab350(void);
extern void PendingMatch_0042b930(void);
extern void MStackPush2RunCountdown_004089e0(void);
extern void MStackBracket7_DispatchAndChain_004b8fa0(void);
extern void MStackBracketed3StoreCall_00475990(void);
extern void ChainDirtyBitWalker_00408c10(void);
extern void Wrapper_0048a350(void);
extern void Wrapper_0048a3a0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall_0048eec0(void);
extern void Wrapper_0048ec20(void);
extern void FiveCallScaledChainTailJmp_0045f8d0(void);
extern void SetJmp_00438f50(void);
extern void SetJmp_00438f60(void);
extern void GuardedDispatch_0042b6c0(void);
extern void MStackPushZeroCallPop_00407d00(void);
extern void DirtyToggleByGate_0048f350(void);
extern void GameDispatchValidateState_004339c0(void);
extern void CrouchAttackFsmCluster_0046f7a0(void);
extern void MStackPushVec3Mul10_004767e0(void);
extern void LiteralPushCallEntZero_00488c00(void);
extern void LeaPlus22StoreSelf_0048e4d0(void);
extern void IterLoad_00491050(void);
extern void GuardedDualConst2AndToggle_0048eba0(void);
extern void CallPauseScaledStorePushCall_0045fca0(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_00407400(void);
extern void PushSetCallPop_00406530(void);
extern unsigned int g_state_0053a3c0;
extern unsigned int g_player1NodeIdx;
extern unsigned int g_installOwnerNode_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_data_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

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
extern unsigned int g_x_004d2244;
extern unsigned int g_x_005438e8;
extern void Helper_AuxAudio_PostInit(void);

__declspec(naked) void AuxAudioDevCapsQuery_004ac3f0(void) {
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
        mov     ecx, dword ptr [g_x_005438e8]
        mov     edi, [esp + 0x28]
        mov     esi, dword ptr [g_x_004d2244]
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
        mov     eax, dword ptr [g_x_005438e8]
        lea     edx, [esp + 0x08]
        push    edx
        push    0x400
        push    0x080d
        push    eax
        mov     dword ptr [esp + 0x1c], 2
        call    esi
        mov     edx, dword ptr [g_x_005438e8]
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
