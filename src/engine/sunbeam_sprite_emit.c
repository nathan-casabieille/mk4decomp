/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown_0053a718;
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
extern unsigned int g_eventArmReload_0053a770;
extern unsigned int g_rangeBase_0053a46c;

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
extern unsigned int g_lastGatedValue_00543598;
extern unsigned int g_lastGatedTick_0054358c;
extern unsigned int g_fightAxisNegX_00535e70;
extern unsigned int g_fightAxisNegY_00535e74;
extern unsigned int g_fightAxisPosX_00535e78;
extern unsigned int g_fightAxisPosY_00535e7c;

extern unsigned int g_dispatchSave725_004f6398;
extern unsigned int g_sunbeamSpriteVar_004f6580;
extern u32 g_inLoopStep;
extern unsigned int g_triStripRingB;
extern s32 g_vtxOut2_z;
extern s32 g_vtxOut_z;
extern s32 g_vtxTransX;
extern s32 g_vtxTransY;
extern s32 g_vtxTransZ;
extern s16 g_vtxScreenX;
extern s16 g_vtxScreenY;
extern unsigned int g_dispatchSave1501_00ab4398;
extern unsigned int g_dispatchSave1502_00ab439c;
extern unsigned int g_dispatchSave1503_00ab43a0;
extern unsigned int g_dispatchSave1581_00ab51fc;
extern void AdvanceTriStripRing(void);
extern void Helper_DrawCursor(void);
extern void ProjectVertex(void);

__declspec(naked) void SunbeamSpriteEmit_004bd270(void)
{
    __asm {
        mov      eax, dword ptr [g_sunbeamSpriteVar_004f6580]
        mov      edx, dword ptr [g_dispatchSave1581_00ab51fc]
        sub      esp, 0x2c
        add      eax, edx
        mov      dword ptr [g_sunbeamSpriteVar_004f6580], eax
        push     ebx
        mov      ebx, 0x64
        push     ebp
        push     esi
        cmp      eax, ebx
        push     edi
        jge      L_d2a3
        mov      eax, ebx
        mov      dword ptr [g_dispatchSave1581_00ab51fc], 0x10
        mov      dword ptr [g_sunbeamSpriteVar_004f6580], eax
    L_d2a3:
        cmp      eax, 0x100
        jle      L_d2be
        mov      dword ptr [g_sunbeamSpriteVar_004f6580], 0x100
        mov      dword ptr [g_dispatchSave1581_00ab51fc], 0xfffffff8
    L_d2be:
        mov      eax, dword ptr [g_inLoopStep]
        test     eax, eax
        jne      L_d48f
        mov      eax, dword ptr [g_xformEntityIdx]
        mov      ecx, dword ptr [g_dispatchSave1501_00ab4398]
        mov      edx, dword ptr [g_dispatchSave1502_00ab439c]
        lea      esi, [esp + 0x12]
        lea      edi, [eax - 1]
        mov      eax, dword ptr [g_dispatchSave1503_00ab43a0]
        sar      ecx, 0x10
        sar      edx, 0x10
        sar      eax, 7
        shl      edi, 4
        mov      dword ptr [g_vtxTransX], ecx
        mov      dword ptr [g_vtxTransY], edx
        mov      dword ptr [g_vtxTransZ], eax
        add      edi, OFFSET g_dispatchSave725_004f6398
        mov      ebp, 4
    L_d310:
        mov      cx, word ptr [edi + 2]
        mov      dx, word ptr [edi]
        push     0
        push     ecx
        push     edx
        call     AdvanceTriStripRing
        add      esp, 0xc
        call     ProjectVertex
        mov      ax, word ptr [g_vtxScreenX]
        mov      cx, word ptr [g_vtxScreenY]
        mov      word ptr [esi - 2], ax
        mov      word ptr [esi], cx
        dec      word ptr [esi]
        add      edi, 4
        add      esi, 4
        dec      ebp
        jne      L_d310
        mov      eax, dword ptr [g_triStripRingB]
        test     eax, eax
        jle      L_d48f
        mov      eax, dword ptr [g_vtxOut2_z]
        test     eax, eax
        jle      L_d48f
        mov      eax, dword ptr [g_vtxOut_z]
        test     eax, eax
        jle      L_d48f
        mov      eax, dword ptr [g_tickW1]
        cmp      eax, 0x10
        jl       L_d385
        cdq
        and      edx, 7
        add      eax, edx
        sar      eax, 3
        dec      eax
        jmp      L_d387
    L_d385:
        xor      eax, eax
    L_d387:
        movsx    edx, ax
        mov      eax, dword ptr [g_sunbeamSpriteVar_004f6580]
        mov      ecx, 1
        imul     eax, edx
        sar      eax, 8
        mov      word ptr [esp + 0x32], cx
        mov      byte ptr [esp + 0x30], cl
        mov      byte ptr [esp + 0x2c], cl
        mov      ebp, dword ptr [esp + 0x16]
        mov      ecx, eax
        mov      si, word ptr [esp + 0x10]
        shl      ecx, 5
        mov      di, word ptr [esp + 0x12]
        or       ecx, eax
        shl      ecx, 5
        or       ecx, eax
        mov      byte ptr [esp + 0x31], bl
        mov      byte ptr [esp + 0x2d], bl
        mov      bx, word ptr [esp + 0x14]
        lea      eax, [esp + 0x20]
        lea      edx, [ebp + 4]
        push     eax
        mov      word ptr [esp + 0x3e], 0x2f
        mov      word ptr [esp + 0x38], cx
        mov      word ptr [esp + 0x24], si
        mov      word ptr [esp + 0x26], di
        mov      word ptr [esp + 0x2c], bx
        mov      word ptr [esp + 0x2e], dx
        call     Helper_DrawCursor
        mov      edx, dword ptr [esp + 0x1e]
        mov      cx, word ptr [esp + 0x1c]
        mov      ax, word ptr [esp + 0x20]
        add      edx, -4
        add      esp, 4
        mov      word ptr [esp + 0x22], dx
        mov      word ptr [esp + 0x20], cx
        mov      cx, word ptr [esp + 0x1e]
        lea      edx, [esp + 0x20]
        mov      word ptr [esp + 0x28], ax
        push     edx
        mov      word ptr [esp + 0x2e], cx
        call     Helper_DrawCursor
        mov      eax, dword ptr [esp + 0x1c]
        mov      cx, word ptr [esp + 0x1e]
        add      esp, 4
        lea      edx, [esp + 0x20]
        add      eax, 4
        mov      word ptr [esp + 0x20], si
        push     edx
        mov      word ptr [esp + 0x26], di
        mov      word ptr [esp + 0x2c], ax
        mov      word ptr [esp + 0x2e], cx
        call     Helper_DrawCursor
        mov      eax, dword ptr [esp + 0x20]
        mov      cx, word ptr [esp + 0x22]
        add      esp, 4
        lea      edx, [esp + 0x20]
        add      eax, -4
        mov      word ptr [esp + 0x20], bx
        push     edx
        mov      word ptr [esp + 0x26], bp
        mov      word ptr [esp + 0x2c], ax
        mov      word ptr [esp + 0x2e], cx
        call     Helper_DrawCursor
        add      esp, 4
    L_d48f:
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x2c
        ret
    }
}
