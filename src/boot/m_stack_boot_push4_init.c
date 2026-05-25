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

extern void MStackBootPush4Init_00408350(void);

extern s32 g_vtxValid;
extern s16 g_vtxMat[];
extern unsigned int g_data_007af958[];
extern unsigned int g_mat3x3_007af992;
extern s16 g_vtxIn1_y;
extern s16 g_vtxIn2_y;
extern unsigned int g_mat3x3_007af994;
extern s32 g_vtxTransX;
extern s32 g_vtxOut1_x;
extern unsigned int g_mat3x3_007af996;
extern unsigned int g_mat3x3_007af998;
extern unsigned int g_mat3x3_007af99a;
extern s32 g_vtxTransY;
extern s32 g_vtxOut1_y;
extern unsigned int g_mat3x3_007af99c;
extern unsigned int g_mat3x3_007af99e;
extern unsigned int g_mat3x3_007af9a0;
extern s32 g_vtxTransZ;
extern unsigned int g_triStripRingB;
extern unsigned int g_triStripRingA;
extern s16 g_vtxScreenP1Y;

/* @addr 0x004b2d20 (338b engine.app) - 3D vertex transform + perspective project.
 *   Reads vertex idx ecx; applies 3x3 matrix at g_vtxMat..0x7af9a0 to
 *   (x,y,z) at g_data_007af958/95e/964[ecx]; adds translation 0x7af9a4/a8/ac.
 *   Stores transformed XYZ at [0x7af96c/78/84][ecx*4].
 *   Perspective divide: if Z > 1, scale = 0x02000000/Z; project X via
 *   scale*0x19999a (offset 0x140 = 320 center); Y via scale * 15 * 8192/65536
 *   (offset 0xf0 = 240 center). Stores screen XY (word) at 0x7af9b4/b6.
 */
__declspec(naked) void Helper_EmitLine(void) {
    __asm {
        mov     ecx, [esp + 4]
        mov     dword ptr [g_vtxValid], 1
        movsx   eax, word ptr [g_vtxMat]
        movsx   edx, word ptr [ecx*2 + g_data_007af958]
        imul    eax, edx
        movsx   edx, word ptr [g_mat3x3_007af992]
        push    esi
        movsx   esi, word ptr [ecx*2 + g_vtxIn1_y]
        imul    edx, esi
        movsx   esi, word ptr [ecx*2 + g_vtxIn2_y]
        add     eax, edx
        movsx   edx, word ptr [g_mat3x3_007af994]
        imul    edx, esi
        add     eax, edx
        mov     edx, dword ptr [g_vtxTransX]
        sar     eax, 0x0c
        add     eax, edx
        movsx   eax, ax
        mov     dword ptr [ecx*4 + g_vtxOut1_x], eax
        movsx   edx, word ptr [g_mat3x3_007af996]
        movsx   eax, word ptr [ecx*2 + g_data_007af958]
        movsx   esi, word ptr [ecx*2 + g_vtxIn1_y]
        imul    edx, eax
        movsx   eax, word ptr [g_mat3x3_007af998]
        imul    eax, esi
        movsx   esi, word ptr [ecx*2 + g_vtxIn2_y]
        add     edx, eax
        movsx   eax, word ptr [g_mat3x3_007af99a]
        imul    eax, esi
        add     edx, eax
        mov     eax, dword ptr [g_vtxTransY]
        sar     edx, 0x0c
        add     edx, eax
        movsx   edx, dx
        mov     dword ptr [ecx*4 + g_vtxOut1_y], edx
        movsx   eax, word ptr [g_mat3x3_007af99c]
        movsx   edx, word ptr [ecx*2 + g_data_007af958]
        movsx   esi, word ptr [ecx*2 + g_vtxIn1_y]
        imul    eax, edx
        movsx   edx, word ptr [g_mat3x3_007af99e]
        imul    edx, esi
        movsx   esi, word ptr [ecx*2 + g_vtxIn2_y]
        add     eax, edx
        movsx   edx, word ptr [g_mat3x3_007af9a0]
        imul    edx, esi
        mov     esi, dword ptr [g_vtxTransZ]
        add     eax, edx
        sar     eax, 0x0c
        add     eax, esi
        movsx   esi, ax
        cmp     esi, 1
        mov     dword ptr [ecx*4 + g_triStripRingB], esi
        mov     eax, 0x02000000
        jle     short L_vp3_skipDiv
        cdq
        idiv    esi
    L_vp3_skipDiv:
        mov     edx, eax
        pop     esi
        imul    edx, dword ptr [ecx*4 + g_vtxOut1_x]
        sar     edx, 0x10
        imul    edx, 0x0001999a
        sar     edx, 0x10
        add     edx, 0x140
        mov     word ptr [ecx*4 + g_triStripRingA], dx
        imul    eax, dword ptr [ecx*4 + g_vtxOut1_y]
        sar     eax, 0x10
        lea     eax, [eax + eax*2]
        lea     eax, [eax + eax*4]
        shl     eax, 0x0d
        sar     eax, 0x10
        add     eax, 0xf0
        mov     word ptr [ecx*4 + g_vtxScreenP1Y], ax
        ret
    }
}
