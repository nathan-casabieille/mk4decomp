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

extern unsigned int g_data_004f6238;
extern u32 g_inLoopStep;
extern unsigned int g_data_007af958[];
extern s16 g_vtxIn2_x;
extern unsigned int g_triStripX0;
extern s16 g_vtxIn1_y;
extern s16 g_vtxIn1_z;
extern unsigned int g_triStripX1;
extern s16 g_vtxIn2_y;
extern s16 g_vtxIn2_z;
extern unsigned int g_triStripX2;
extern unsigned int g_triStripRingB;
extern s32 g_vtxOut2_z;
extern s32 g_vtxOut_z;
extern s32 g_vtxTransX;
extern s32 g_vtxTransY;
extern s32 g_vtxTransZ;
extern s32 g_vtxValid;
extern unsigned int g_triStripRingA;
extern s16 g_vtxScreenP2X;
extern s16 g_vtxScreenX;
extern unsigned int g_data_00ab4398;
extern unsigned int g_data_00ab439c;
extern unsigned int g_data_00ab43a0;
extern unsigned int g_data_00ab4e60;
extern void Helper_DrawCursor(void);
extern void ProjectTwoVertices(void);

__declspec(naked) void BillboardChainRender_004bb030(void)
{
    __asm {
        mov      eax, dword ptr [g_inLoopStep]
        sub      esp, 0x20
        push     ebx
        xor      ebx, ebx
        cmp      eax, ebx
        jne      L_b24a
        mov      eax, dword ptr [g_currentNodeIdx]
        mov      ecx, dword ptr [g_data_00ab4398]
        mov      edx, dword ptr [g_data_00ab439c]
        push     edi
        mov      edi, dword ptr [eax*4 + 0x2c]
        mov      eax, dword ptr [g_data_00ab43a0]
        sar      eax, 7
        mov      dword ptr [g_vtxTransZ], eax
        mov      eax, dword ptr [g_data_00ab4e60]
        sar      ecx, 0x10
        sar      edx, 0x10
        cmp      eax, 0x10
        push     esi
        mov      dword ptr [g_currentNodeIdx], edi
        mov      dword ptr [g_vtxTransX], ecx
        mov      dword ptr [g_vtxTransY], edx
        jl       L_b098
        cdq
        and      edx, 7
        add      eax, edx
        sar      eax, 3
        dec      eax
        jmp      L_b09a
    L_b098:
        xor      eax, eax
    L_b09a:
        mov      ecx, eax
        mov      word ptr [esp + 0x26], 0x60
        shl      ecx, 5
        or       ecx, eax
        mov      word ptr [esp + 0x1e], 0x40
        shl      ecx, 5
        or       ecx, eax
        mov      word ptr [esp + 0x20], cx
    L_b0b9:
        mov      eax, dword ptr [edi*4 + 0xc]
        cmp      eax, ebx
        mov      dword ptr [g_walkCallback], eax
        je       L_b233
        mov      edx, dword ptr [eax*4 + 4]
        mov      dword ptr [g_xformEntityIdx], edx
        mov      ecx, dword ptr [eax*4 + 0x18]
        mov      eax, dword ptr [edx + 4]
        cmp      eax, ebx
        je       L_b233
        shl      ecx, 4
        xor      edx, edx
        mov      dl, byte ptr [ecx + eax + 0xe]
        lea      esi, [ecx + eax + 0xc]
        mov      ecx, dword ptr [eax + 4]
        lea      edx, [ecx + edx*4]
        mov      cl, byte ptr [esp + 0x26]
        mov      al, byte ptr [edx + eax + 0xa]
        xor      al, cl
        and      eax, 0xf
        xor      word ptr [esp + 0x26], ax
        mov      cl, byte ptr [esi + 1]
        and      ecx, 3
        mov      dl, byte ptr [ecx + g_data_004f6238]
        mov      ecx, dword ptr [esp + 0x26]
        and      dl, 3
        and      ecx, 0xfe7f
        movsx    ax, dl
        shl      eax, 7
        or       eax, ecx
        mov      word ptr [esp + 0x26], ax
        mov      eax, dword ptr [edi*4 + 4]
        mov      cx, word ptr [esi + 8]
        mov      edx, dword ptr [edi*4 + 8]
        mov      di, word ptr [esi + 6]
        sar      eax, 7
        add      cx, ax
        mov      ax, word ptr [esi + 0xa]
        sar      edx, 7
        add      ax, dx
        mov      dx, word ptr [esi + 4]
        add      dx, cx
        add      di, ax
        mov      word ptr [g_data_007af958], cx
        mov      word ptr [g_vtxIn1_y], ax
        mov      word ptr [g_vtxIn2_y], bx
        mov      word ptr [g_vtxIn2_x], dx
        mov      word ptr [g_vtxIn1_z], ax
        mov      word ptr [g_vtxIn2_z], bx
        mov      word ptr [g_triStripX0], dx
        mov      word ptr [g_triStripX1], di
        mov      word ptr [g_triStripX2], bx
        call     ProjectTwoVertices
        mov      dl, byte ptr [esi + 0xc]
        mov      byte ptr [esp + 0x18], dl
        mov      al, byte ptr [esi + 0xd]
        mov      byte ptr [esp + 0x19], al
        mov      cl, byte ptr [esi + 0xe]
        add      cl, byte ptr [esi + 0xc]
        mov      byte ptr [esp + 0x1c], cl
        mov      dl, byte ptr [esi + 0xf]
        mov      al, byte ptr [esi + 0xd]
        mov      ecx, dword ptr [g_vtxScreenP2X]
        add      dl, al
        mov      eax, dword ptr [g_triStripRingA]
        mov      dword ptr [esp + 0x10], ecx
        mov      cl, byte ptr [g_vtxValid]
        mov      dword ptr [esp + 0xc], eax
        mov      eax, dword ptr [esp + 0x26]
        and      ecx, 1
        and      eax, 0xfbff
        shl      ecx, 0xa
        or       eax, ecx
        mov      byte ptr [esp + 0x1d], dl
        mov      edx, dword ptr [g_vtxScreenX]
        mov      word ptr [esp + 0x26], ax
        mov      eax, dword ptr [g_triStripRingB]
        mov      dword ptr [esp + 0x14], edx
        cmp      eax, ebx
        jle      L_b22d
        cmp      dword ptr [g_vtxOut2_z], ebx
        jle      L_b22d
        cmp      dword ptr [g_vtxOut_z], ebx
        jle      L_b22d
        lea      edx, [esp + 0xc]
        push     edx
        call     Helper_DrawCursor
        add      esp, 4
    L_b22d:
        mov      edi, dword ptr [g_currentNodeIdx]
    L_b233:
        mov      edi, dword ptr [edi*4]
        cmp      edi, ebx
        mov      dword ptr [g_currentNodeIdx], edi
        jne      L_b0b9
        pop      esi
        pop      edi
    L_b24a:
        pop      ebx
        add      esp, 0x20
        ret
    }
}
