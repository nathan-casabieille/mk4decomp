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

/* @addr 0x004c3be0 (286b engine.render) - twin of Snd3DSourceCleanup_004c3ad0 with extra flag-check.
 *   Same structure but adds `shl ecx,2; cmp [ecx+g_data_00f8fac8], 0; je;
 *   test [ecx+g_data_00f8fade], 1; je` before the vtbl calls (extra "in-use" filter).
 */
__declspec(naked) void Snd3DSourceCleanupFiltered_004c3be0(void) {
    __asm {
        mov     ax, word ptr [esp + 4]
        push    ebx
        push    ebp
        push    esi
        cmp     ax, 0x898
        push    edi
        jb      L_s3df_iter
        mov     al, byte ptr [esp + 0x18]
        cmp     al, 0x10
        jae     L_s3df_done
        movsx   esi, al
        shl     esi, 2
        mov     ax, word ptr [esi + g_data_00f9eb80]
        cmp     ax, 0xffff
        jz      L_s3df_done
        movsx   eax, ax
        xor     ebx, ebx
        lea     ecx, [eax*8]
        sub     ecx, eax
        shl     ecx, 2
        cmp     dword ptr [ecx + g_data_00f8fac8], ebx
        jz      L_s3df_done
        test    byte ptr [ecx + g_data_00f8fade], 1
        jz      L_s3df_done
        movsx   edx, word ptr [esi + g_data_00f9eb80 + 2]
        lea     ecx, [eax*8]
        sub     ecx, eax
        add     ecx, edx
        mov     eax, dword ptr [ecx*4 + g_data_00f8fac8]
        push    eax
        mov     ecx, [eax]
        call    dword ptr [ecx + 0x48]
        movsx   eax, word ptr [esi + g_data_00f9eb80]
        mov     edx, eax
        push    ebx
        shl     edx, 3
        sub     edx, eax
        movsx   eax, word ptr [esi + g_data_00f9eb80 + 2]
        add     edx, eax
        mov     eax, dword ptr [edx*4 + g_data_00f8fac8]
        push    eax
        mov     ecx, [eax]
        call    dword ptr [ecx + 0x34]
        movsx   eax, word ptr [esi + g_data_00f9eb80]
        mov     edx, eax
        shl     edx, 3
        sub     edx, eax
        movsx   eax, word ptr [esi + g_data_00f9eb80 + 2]
        mov     word ptr [esi + g_data_00f9eb80], 0xffff
        mov     byte ptr [eax + edx*4 + g_data_00f8fadf], bl
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
    L_s3df_iter:
        movsx   eax, ax
        mov     ebp, eax
        xor     ebx, ebx
        shl     ebp, 3
        sub     ebp, eax
        shl     ebp, 2
        mov     eax, dword ptr [ebp + g_data_00f8fac8]
        lea     edi, [ebp + g_data_00f8fac8]
        cmp     eax, ebx
        jz      short L_s3df_done
        test    byte ptr [ebp + g_data_00f8fade], 1
        jz      short L_s3df_done
        xor     esi, esi
    L_s3df_loop:
        mov     byte ptr [esi + ebp + g_data_00f8fadf], bl
        mov     eax, [edi]
        push    eax
        mov     ecx, [eax]
        call    dword ptr [ecx + 0x48]
        mov     eax, [edi]
        push    ebx
        push    eax
        mov     edx, [eax]
        call    dword ptr [edx + 0x34]
        inc     esi
        add     edi, 4
        cmp     esi, 4
        jl      short L_s3df_loop
    L_s3df_done:
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
    }
}
