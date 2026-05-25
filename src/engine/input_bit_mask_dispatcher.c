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
extern unsigned int g_state_00542094;
extern unsigned int g_state_00535ddc;
extern unsigned int g_state_00537e88;
extern unsigned int g_state_0053a408;
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
extern unsigned int g_data_0053a180;
extern unsigned int g_state_00541fa4;
extern unsigned int g_state_00541fa8;
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
extern unsigned int g_state_00538158;
extern unsigned int g_data_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_data_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_data_00535e70;
extern unsigned int g_data_00535e74;
extern unsigned int g_data_00535e78;
extern unsigned int g_data_00535e7c;

extern void AuxCapsBitFlagAggregate_004b5380(void);

__declspec(naked) void InputBitMaskDispatcher_004b5470(void)
{
    __asm {
        push    esi
        mov     esi, dword ptr [esp + 8]
        mov     eax, dword ptr [esi*4 + 0x00543B68]
        cmp     eax, -1
        je      L_ibmd_ret
        push    eax
        call    AuxCapsBitFlagAggregate_004b5380
        add     esp, 4
        test    eax, 0x40000000
        je      L_ibmd_skip1
        mov     ecx, dword ptr [esi*8 + 0x004F4DCC]
        mov     edx, dword ptr [esi*8 + 0x004F4DC8]
        or      dword ptr [ecx], edx
    L_ibmd_skip1:
        test    eax, 0x80000000
        je      L_ibmd_skip2
        mov     ecx, dword ptr [esi*8 + 0x004F4DDC]
        mov     edx, dword ptr [esi*8 + 0x004F4DD8]
        or      dword ptr [ecx], edx
    L_ibmd_skip2:
        test    eax, 0x10000000
        je      L_ibmd_skip3
        mov     ecx, dword ptr [esi*8 + 0x004F4DEC]
        mov     edx, dword ptr [esi*8 + 0x004F4DE8]
        or      dword ptr [ecx], edx
    L_ibmd_skip3:
        test    eax, 0x20000000
        je      L_ibmd_skip4
        mov     ecx, dword ptr [esi*8 + 0x004F4DFC]
        mov     edx, dword ptr [esi*8 + 0x004F4DF8]
        or      dword ptr [ecx], edx
    L_ibmd_skip4:
        mov     ecx, dword ptr [esi*4 + 0x00543B20]
        test    ecx, ecx
        je      L_ibmd_skip_b1
        dec     ecx
        mov     edx, 1
        shl     edx, cl
        test    edx, eax
        je      L_ibmd_skip_b1
        mov     ecx, dword ptr [esi*8 + 0x004F4E0C]
        mov     edx, dword ptr [esi*8 + 0x004F4E08]
        or      dword ptr [ecx], edx
    L_ibmd_skip_b1:
        mov     ecx, dword ptr [esi*4 + 0x00543B28]
        test    ecx, ecx
        je      L_ibmd_skip_b2
        dec     ecx
        mov     edx, 1
        shl     edx, cl
        test    edx, eax
        je      L_ibmd_skip_b2
        mov     ecx, dword ptr [esi*8 + 0x004F4E1C]
        mov     edx, dword ptr [esi*8 + 0x004F4E18]
        or      dword ptr [ecx], edx
    L_ibmd_skip_b2:
        mov     ecx, dword ptr [esi*4 + 0x00543B30]
        test    ecx, ecx
        je      L_ibmd_skip_b3
        dec     ecx
        mov     edx, 1
        shl     edx, cl
        test    edx, eax
        je      L_ibmd_skip_b3
        mov     ecx, dword ptr [esi*8 + 0x004F4E2C]
        mov     edx, dword ptr [esi*8 + 0x004F4E28]
        or      dword ptr [ecx], edx
    L_ibmd_skip_b3:
        mov     ecx, dword ptr [esi*4 + 0x00543B38]
        test    ecx, ecx
        je      L_ibmd_skip_b4
        dec     ecx
        mov     edx, 1
        shl     edx, cl
        test    edx, eax
        je      L_ibmd_skip_b4
        mov     ecx, dword ptr [esi*8 + 0x004F4E3C]
        mov     edx, dword ptr [esi*8 + 0x004F4E38]
        or      dword ptr [ecx], edx
    L_ibmd_skip_b4:
        mov     ecx, dword ptr [esi*4 + 0x00543B40]
        test    ecx, ecx
        je      L_ibmd_skip_b5
        dec     ecx
        mov     edx, 1
        shl     edx, cl
        test    edx, eax
        je      L_ibmd_skip_b5
        mov     ecx, dword ptr [esi*8 + 0x004F4E4C]
        mov     edx, dword ptr [esi*8 + 0x004F4E48]
        or      dword ptr [ecx], edx
    L_ibmd_skip_b5:
        mov     ecx, dword ptr [esi*4 + 0x00543B48]
        test    ecx, ecx
        je      L_ibmd_skip_b6
        dec     ecx
        mov     edx, 1
        shl     edx, cl
        test    edx, eax
        je      L_ibmd_skip_b6
        mov     ecx, dword ptr [esi*8 + 0x004F4E5C]
        mov     edx, dword ptr [esi*8 + 0x004F4E58]
        or      dword ptr [ecx], edx
    L_ibmd_skip_b6:
        mov     ecx, dword ptr [esi*4 + 0x00543B50]
        test    ecx, ecx
        je      L_ibmd_skip_b7
        dec     ecx
        mov     edx, 1
        shl     edx, cl
        test    edx, eax
        je      L_ibmd_skip_b7
        mov     ecx, dword ptr [esi*8 + 0x004F4E6C]
        mov     edx, dword ptr [esi*8 + 0x004F4E68]
        or      dword ptr [ecx], edx
    L_ibmd_skip_b7:
        mov     ecx, dword ptr [esi*4 + 0x00543B58]
        test    ecx, ecx
        je      L_ibmd_skip_b8
        dec     ecx
        mov     edx, 1
        shl     edx, cl
        test    edx, eax
        je      L_ibmd_skip_b8
        mov     ecx, dword ptr [esi*8 + 0x004F4E7C]
        mov     edx, dword ptr [esi*8 + 0x004F4E78]
        or      dword ptr [ecx], edx
    L_ibmd_skip_b8:
        mov     ecx, dword ptr [esi*4 + 0x00543B60]
        test    ecx, ecx
        je      L_ibmd_ret
        dec     ecx
        mov     edx, 1
        shl     edx, cl
        test    edx, eax
        je      L_ibmd_ret
        mov     eax, dword ptr [esi*8 + 0x004F4E8C]
        mov     ecx, dword ptr [esi*8 + 0x004F4E88]
        or      dword ptr [eax], ecx
    L_ibmd_ret:
        pop     esi
        ret
    }
}
