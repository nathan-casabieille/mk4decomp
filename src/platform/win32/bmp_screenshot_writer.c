/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern unsigned int g_state_0053a718;
extern unsigned int g_xformScratch94;
extern unsigned int g_table_00535ddc;
extern unsigned int g_active_00537e88;
extern unsigned int g_active_0053a408;
extern unsigned int g_audioBankSel_00537f94;

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
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit_0053a180;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_dualBitGate_0053a7b0;
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
extern unsigned int g_stateCountdown_0053a3c0;
extern unsigned int g_installOwnerNode_00535cf8;
extern unsigned int g_cj_00542054;
extern unsigned int g_audioBoundNode_005437f0;
extern unsigned int g_data_00543598;
extern unsigned int g_data_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

extern unsigned int g_data_004f47bc;
extern void Helper_FClose(void);
extern void Helper_FOpen(void);
extern void WrapThreeDispatch_004c5f80(void);

__declspec(naked) void BmpScreenshotWriter_004c4600(void)
{
    __asm {
        sub      esp, 0xc40
        push     ebx
        mov      ebx, dword ptr [esp + 0xc54]
        push     ebp
        push     esi
        mov      esi, dword ptr [esp + 0xc60]
        push     edi
        mov      eax, esi
        mov      word ptr [esp + 0x18], 0x4d42
        imul     eax, ebx
        mov      dword ptr [esp + 0x22], 0x36
        mov      dword ptr [esp + 0x28], 0x28
        lea      ecx, [eax + 0x12]
        lea      edx, [eax + eax*2]
        mov      eax, dword ptr [esp + 0xc54]
        mov      dword ptr [esp + 0x2c], ebx
        lea      ecx, [ecx + ecx*2]
        mov      dword ptr [esp + 0x30], esi
        mov      dword ptr [esp + 0x1a], ecx
        xor      ecx, ecx
        cmp      eax, ecx
        mov      word ptr [esp + 0x1e], cx
        mov      word ptr [esp + 0x20], cx
        mov      word ptr [esp + 0x34], 1
        mov      word ptr [esp + 0x36], 0x18
        mov      dword ptr [esp + 0x38], ecx
        mov      dword ptr [esp + 0x3c], edx
        mov      dword ptr [esp + 0x40], ecx
        mov      dword ptr [esp + 0x44], ecx
        mov      dword ptr [esp + 0x48], ecx
        mov      dword ptr [esp + 0x4c], ecx
        je       L_485e
        mov      ebp, dword ptr [esp + 0xc58]
        cmp      ebp, ecx
        je       L_485e
        mov      edi, dword ptr [esp + 0xc5c]
        cmp      edi, 1
        jl       L_485e
        cmp      ebx, 0x400
        jg       L_485e
        cmp      esi, 1
        jl       L_485e
        push     OFFSET g_data_004f47bc
        push     eax
        call     Helper_FOpen
        add      esp, 8
        mov      dword ptr [esp + 0x10], eax
        test     eax, eax
        je       L_485e
        push     eax
        push     1
        lea      eax, [esp + 0x20]
        push     0xe
        push     eax
        call     WrapThreeDispatch_004c5f80
        mov      ecx, dword ptr [esp + 0x20]
        add      esp, 0x10
        lea      edx, [esp + 0x28]
        push     ecx
        push     1
        push     0x28
        push     edx
        call     WrapThreeDispatch_004c5f80
        mov      eax, edi
        lea      ecx, [esi - 1]
        cdq
        sub      eax, edx
        add      esp, 0x10
        sar      eax, 1
        imul     ecx, eax
        test     esi, esi
        lea      edx, [ebp + ecx*2]
        mov      dword ptr [esp + 0xc5c], eax
        mov      dword ptr [esp + 0xc58], edx
        jle      L_4851
        mov      dword ptr [esp + 0x14], esi
    L_472b:
        mov      eax, dword ptr [esp + 0xc68]
        test     eax, eax
        je       short L_47a6
        test     ebx, ebx
        jle      L_4810
        mov      esi, dword ptr [esp + 0xc58]
        lea      ecx, [esp + 0x51]
        mov      ebp, ebx
    L_474b:
        mov      di, word ptr [esi]
        mov      eax, edi
        sar      eax, 0xb
        and      al, 0x1f
        mov      dl, al
        and      dl, 1
        neg      dl
        sbb      edx, edx
        and      edx, 7
        shl      al, 3
        or       dl, al
        mov      eax, edi
        sar      eax, 5
        and      al, 0x3f
        mov      byte ptr [ecx + 1], dl
        mov      dl, al
        and      dl, 1
        neg      dl
        sbb      edx, edx
        and      edx, 3
        shl      al, 2
        or       dl, al
        mov      al, byte ptr [esi]
        and      al, 0x1f
        mov      byte ptr [ecx], dl
        mov      dl, al
        and      dl, 1
        neg      dl
        sbb      edx, edx
        add      esi, 2
        and      edx, 7
        add      ecx, 3
        shl      al, 3
        or       dl, al
        dec      ebp
        mov      byte ptr [ecx - 4], dl
        jne      L_474b
        jmp      short L_4810
    L_47a6:
        test     ebx, ebx
        jle      short L_4810
        mov      esi, dword ptr [esp + 0xc58]
        lea      ecx, [esp + 0x51]
        mov      ebp, ebx
    L_47b7:
        mov      di, word ptr [esi]
        mov      eax, edi
        sar      eax, 0xa
        and      al, 0x1f
        mov      dl, al
        and      dl, 1
        neg      dl
        sbb      edx, edx
        and      edx, 7
        shl      al, 3
        or       dl, al
        mov      eax, edi
        sar      eax, 5
        and      al, 0x1f
        mov      byte ptr [ecx + 1], dl
        mov      dl, al
        and      dl, 1
        neg      dl
        sbb      edx, edx
        and      edx, 7
        shl      al, 3
        or       dl, al
        mov      al, byte ptr [esi]
        and      al, 0x1f
        mov      byte ptr [ecx], dl
        mov      dl, al
        and      dl, 1
        neg      dl
        sbb      edx, edx
        add      esi, 2
        and      edx, 7
        add      ecx, 3
        shl      al, 3
        or       dl, al
        dec      ebp
        mov      byte ptr [ecx - 4], dl
        jne      short L_47b7
    L_4810:
        mov      eax, dword ptr [esp + 0x10]
        lea      ecx, [ebx + ebx*2]
        push     eax
        push     1
        lea      edx, [esp + 0x58]
        push     ecx
        push     edx
        call     WrapThreeDispatch_004c5f80
        mov      eax, dword ptr [esp + 0xc6c]
        mov      ecx, dword ptr [esp + 0xc68]
        neg      eax
        add      esp, 0x10
        lea      edx, [ecx + eax*2]
        mov      eax, dword ptr [esp + 0x14]
        dec      eax
        mov      dword ptr [esp + 0xc58], edx
        mov      dword ptr [esp + 0x14], eax
        jne      L_472b
    L_4851:
        mov      eax, dword ptr [esp + 0x10]
        push     eax
        call     Helper_FClose
        add      esp, 4
    L_485e:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0xc40
        ret
    }
}
