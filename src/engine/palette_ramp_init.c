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

/* @addr 0x004ad5f0 (169b engine.install) - gamma/palette ramp computation (256 entries).
 *   if ([0x58c7e0] == 0): ret (no init).
 *   ebx = arg & 0x7f (clamped abs to 100).
 *   Zero-fill 10 dwords on stack ([esp+0xc..]); [esp+0xc] = 0x28 (cb); [esp+0x28] = ebx*5.
 *   if ([0x58c7b8] != 0): COM-style vtable call ([0x58c7b8])->vtable[0x10](self, &caps).
 *     Store result to [0x58c7dc].
 *   ebx clamp at 60. Loop 256 entries (ecx=0..0xff): byte = ((ebx*esi*0x51eb851f) sar 36) signed-fixup,
 *     clamp to 0xff, store at [ecx + 0x544158]. esi += ebx; ecx++.
 */
extern unsigned int g_palette_00544158;
extern unsigned int g_x_0058c7b8;
extern unsigned int g_x_0058c7dc;
extern unsigned int g_x_0058c7e0;

__declspec(naked) void PaletteRampInit_004ad5f0(void) {
    __asm {
        mov     eax, dword ptr [g_x_0058c7e0]
        sub     esp, 0x28
        test    eax, eax
        _emit   0fh
        _emit   84h
        _emit   95h
        _emit   00h
        _emit   00h
        _emit   00h
        push    edi
        push    esi
        push    ebx
        mov     ebx, [esp + 0x38]
        mov     eax, ebx
        cdq
        xor     eax, edx
        sub     eax, edx
        cmp     eax, 0x64
        _emit   7eh
        _emit   05h
        mov     ebx, 0x64
        mov     ecx, 0x0a
        xor     eax, eax
        lea     edi, [esp + 0x0c]
        rep stosd
        lea     eax, [ebx + ebx*4]
        mov     dword ptr [esp + 0x0c], 0x28
        mov     [esp + 0x28], eax
        mov     eax, dword ptr [g_x_0058c7b8]
        test    eax, eax
        mov     dword ptr [esp + 0x10], 0x20
        _emit   74h
        _emit   10h
        mov     ecx, [eax]
        lea     edx, [esp + 0x0c]
        push    edx
        push    eax
        call    dword ptr [ecx + 0x10]
        mov     dword ptr [g_x_0058c7dc], eax
        cmp     ebx, 0x3c
        _emit   7eh
        _emit   05h
        mov     ebx, 0x3c
        xor     ecx, ecx
        xor     esi, esi
        mov     eax, 0x51eb851f
        imul    esi
        sar     edx, 4
        mov     eax, edx
        shr     eax, 0x1f
        add     edx, eax
        cmp     edx, 0xff
        _emit   7ch
        _emit   05h
        mov     edx, 0xff
        mov     byte ptr [ecx + g_palette_00544158], dl
        inc     ecx
        add     esi, ebx
        cmp     ecx, 0x100
        _emit   7ch
        _emit   0d1h
        pop     ebx
        pop     esi
        pop     edi
        add     esp, 0x28
        ret
    }
}
