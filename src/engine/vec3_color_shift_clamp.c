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
extern unsigned int g_data_00542050;
extern unsigned int g_data_00542070;
extern unsigned int g_data_00542084;
extern unsigned int g_state_0054208c;
extern unsigned int g_state_00542088;
extern unsigned int g_state_00542094;
extern unsigned int g_state_00535ddc;
extern unsigned int g_state_00537e88;
extern unsigned int g_state_0053a408;
extern unsigned int g_state_00537f94;
extern unsigned int g_state_00542080;
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
extern unsigned int g_state_0054207c;
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

/*
 * Vec3ColorShiftClamp_004b3490 - 256b RGB-channel sar+pack into a 16-bit color word triplet.
 *   For each of 3 channels (R, G, B), reads g_x_007af984/988/98c, arithmetic-shift-right by cl
 *   (with negative clamp to 0, max clamp to 0x1f), computes (0xffff - channel) XOR with existing
 *   channel bits at word [esi + 0x14/0x16/0x18], packs the resulting 5-bit field into bits [0:5],
 *   [5:10] (shl 5), and [10:15] (shl 10) of the destination word.
 */
__declspec(naked) void Vec3ColorShiftClamp_004b3490(void)
{
    __asm
    {
        mov     ecx, dword ptr [esp + 8]
        push    ebx
        push    esi
        push    edi
        mov     edi, dword ptr [g_x_007af984]
        sar     edi, cl
        test    edi, edi
        jge     short L_r_pos
        xor     edi, edi
    L_r_pos:
        cmp     edi, 0x1f
        jle     short L_r_lo
        mov     edi, 0x1f
    L_r_lo:
        mov     esi, dword ptr [esp + 0x10]
        mov     eax, 0xffff
        sub     eax, edi
        mov     dx, word ptr [esi + 0x14]
        xor     al, dl
        and     eax, 0x1f
        xor     eax, edx
        mov     edx, eax
        and     eax, 0x1f
        and     edx, 0xfc1f
        shl     eax, 5
        or      edx, eax
        mov     eax, edx
        and     edx, 0x3e0
        and     eax, 0x83ff
        shl     edx, 5
        or      eax, edx
        mov     word ptr [esi + 0x14], ax
        mov     edx, dword ptr [g_x_007af988]
        sar     edx, cl
        test    edx, edx
        jge     short L_g_pos
        xor     edx, edx
    L_g_pos:
        cmp     edx, 0x1f
        jle     short L_g_lo
        mov     edx, 0x1f
    L_g_lo:
        mov     bx, word ptr [esi + 0x16]
        mov     eax, 0xffff
        sub     eax, edx
        xor     al, bl
        and     eax, 0x1f
        xor     eax, ebx
        mov     edx, eax
        and     eax, 0x1f
        and     edx, 0xfc1f
        shl     eax, 5
        or      edx, eax
        mov     eax, edx
        and     edx, 0x3e0
        and     eax, 0x83ff
        shl     edx, 5
        or      eax, edx
        mov     word ptr [esi + 0x16], ax
        mov     edx, dword ptr [g_x_007af98c]
        sar     edx, cl
        test    edx, edx
        jge     short L_b_pos
        xor     edx, edx
    L_b_pos:
        cmp     edx, 0x1f
        jle     short L_b_lo
        mov     edx, 0x1f
    L_b_lo:
        mov     cx, word ptr [esi + 0x18]
        mov     eax, 0xffff
        sub     eax, edx
        pop     edi
        xor     al, cl
        and     eax, 0x1f
        xor     eax, ecx
        mov     ecx, eax
        and     eax, 0x1f
        and     ecx, 0xfc1f
        shl     eax, 5
        or      ecx, eax
        mov     edx, ecx
        and     ecx, 0x3e0
        and     edx, 0x83ff
        shl     ecx, 5
        or      edx, ecx
        mov     word ptr [esi + 0x18], dx
        pop     esi
        pop     ebx
        ret
    }
}
