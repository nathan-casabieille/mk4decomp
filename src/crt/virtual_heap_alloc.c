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

extern unsigned int g_data_00520130;
extern unsigned int g_data_00520134;
extern unsigned int g_data_00520140;
extern unsigned int g_data_00fa0ee4;
extern unsigned int g_iat_004d20b4;
extern unsigned int g_iat_004d2144;
extern unsigned int g_iat_004d214c;
extern unsigned int g_iat_004d2168;

__declspec(naked) void VirtualHeapAlloc_004c70d0(void)
{
    __asm {
        mov      eax, dword ptr [g_data_00520140]
        push     ebp
        push     esi
        cmp      eax, -1
        push     edi
        jne      short L_70e4
        mov      ebp, OFFSET g_data_00520130
        jmp      short L_7101
    L_70e4:
        mov      eax, dword ptr [g_data_00fa0ee4]
        push     0x2020
        push     0
        push     eax
        call     dword ptr [g_iat_004d20b4]
        mov      ebp, eax
        test     ebp, ebp
        je       L_722c
    L_7101:
        mov      edi, dword ptr [g_iat_004d2144]
        push     4
        push     0x2000
        push     0x400000
        push     0
        call     edi
        mov      esi, eax
        test     esi, esi
        je       L_7215
        push     4
        push     0x1000
        push     0x10000
        push     esi
        call     edi
        test     eax, eax
        je       L_7207
        cmp      ebp, OFFSET g_data_00520130
        jne      short L_7168
        mov      eax, dword ptr [g_data_00520130]
        test     eax, eax
        jne      short L_7153
        mov      dword ptr [g_data_00520130], OFFSET g_data_00520130
    L_7153:
        mov      eax, dword ptr [g_data_00520134]
        test     eax, eax
        jne      short L_7183
        mov      dword ptr [g_data_00520134], OFFSET g_data_00520130
        jmp      short L_7183
    L_7168:
        mov      dword ptr [ebp], OFFSET g_data_00520130
        mov      ecx, dword ptr [g_data_00520134]
        mov      dword ptr [ebp + 4], ecx
        mov      dword ptr [g_data_00520134], ebp
        mov      edx, dword ptr [ebp + 4]
        mov      dword ptr [edx], ebp
    L_7183:
        lea      eax, [esi + 0x400000]
        lea      ecx, [ebp + 0x18]
        lea      edx, [ebp + 0x98]
        mov      dword ptr [ebp + 0x14], eax
        mov      dword ptr [ebp + 0x10], esi
        mov      dword ptr [ebp + 8], ecx
        mov      dword ptr [ebp + 0xc], edx
        xor      eax, eax
        mov      edi, 0xf1
    L_71a5:
        xor      edx, edx
        cmp      eax, 0x10
        setge    dl
        dec      edx
        add      ecx, 8
        and      edx, edi
        dec      edx
        inc      eax
        mov      dword ptr [ecx - 8], edx
        mov      dword ptr [ecx - 4], edi
        cmp      eax, 0x400
        jl       short L_71a5
        mov      ecx, 0x4000
        xor      eax, eax
        mov      edi, esi
        rep stosd
        mov      eax, dword ptr [ebp + 0x10]
        add      eax, 0x10000
        cmp      esi, eax
        jae      short L_7201
        mov      ecx, 0xf0
        mov      al, 0xff
    L_71e0:
        lea      edx, [esi + 8]
        mov      dword ptr [esi + 4], ecx
        mov      dword ptr [esi], edx
        mov      byte ptr [esi + 0xf8], al
        mov      edx, dword ptr [ebp + 0x10]
        add      esi, 0x1000
        add      edx, 0x10000
        cmp      esi, edx
        jb       short L_71e0
    L_7201:
        mov      eax, ebp
        pop      edi
        pop      esi
        pop      ebp
        ret
    L_7207:
        push     0x8000
        push     0
        push     esi
        call     dword ptr [g_iat_004d2168]
    L_7215:
        cmp      ebp, OFFSET g_data_00520130
        je       short L_722c
        mov      eax, dword ptr [g_data_00fa0ee4]
        push     ebp
        push     0
        push     eax
        call     dword ptr [g_iat_004d214c]
    L_722c:
        pop      edi
        pop      esi
        xor      eax, eax
        pop      ebp
        ret
    }
}
