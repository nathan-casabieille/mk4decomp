/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel;
extern unsigned int g_acc_00542078;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown;
extern unsigned int g_xformScratch94;
extern unsigned int g_table_00535ddc;
extern unsigned int g_active_00537e88;
extern unsigned int g_active_0053a408;
extern unsigned int g_audioBankSel;

extern void StoreTwoCall(int, int);
extern void SetJmp_Thunk_LinkedListBitMaskSearch(void);
extern void Thunk_ChainNodeInit(void);
extern void ScaledZeroFour(void);
extern void WalkCbSubMul10(void);
extern void Mul10Tail(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10(void);
extern void SpawnListBatchLoader(void);
extern void MStackPush2TableNot(void);
extern void GuardedChainCmpDualBitXor(void);
extern void ScaledLoadDecJmp(void);
extern void ScaledStoreCurDirtyClear(void);
extern void MStackBitmaskIncMod(void);
extern void MStackBitmaskUpdate(void);
extern void Push1eCallTestDirtyLoop(void);
extern void MStackLoopFieldInit(void);
extern void TaggedSceneDispatch(void);
extern void CallPauseDirty4StackPushFn(void);
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void InstallSelfChainSet84_80CallW(void);
extern void Wrapper_PackedAdvanceCallTailJmp_004e46d0(void);
extern void MoveFsmCluster(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_LoadGeoAsset_Default(void);
extern void AllocSlotPushTripleGlobals(void);
extern void MStackPop4Rewrite(void);
extern void Push70CallScaleArith(void);
extern void StreamChainStringInstall(void);
extern void MStackFrameCdeclDouble(void);
extern void ChainTableWalkStore(void);
extern void Push16Call(void);
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm(void);
extern void StackPopDispatchTagged(void);
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_dualBitGate;
extern unsigned int g_eventArmReload;
extern unsigned int g_rangeBase;

extern void ScaledArrStore_004298c0(void);
extern void DualFieldAddSubStore(void);
extern void IterStepDualStore(int);
extern void ScaledXorStore_004900f0(void);
extern void ChainWalkInstall(void);
extern void FpuSqrtMul(void);
extern void PendingMatch_0042b930(void);
extern void MStackPush2RunCountdown(void);
extern void MStackBracket7_DispatchAndChain(void);
extern void MStackBracketed3StoreCall(void);
extern void ChainDirtyBitWalker(void);
extern void Wrapper_ScaledChainPushCall_004ef858(void);
extern void Wrapper_ScaledChainPushCall_004ef8b0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_IterLoad_0048fd30_004f12a0(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_StateDispatchYield_00438f50(void);
extern void SetJmp_StateDispatchYield_00438f60(void);
extern void GuardedDispatch_0042b6c0(void);
extern void MStackPushZeroCallPop_00407d00(void);
extern void DirtyToggleByGate(void);
extern void GameDispatchValidateState(void);
extern void CrouchAttackFsmCluster(void);
extern void MStackPushVec3Mul10(void);
extern void LiteralPushCallEntZero(void);
extern void LeaPlus22StoreSelf(void);
extern void IterLoad_00491050(void);
extern void GuardedDualConst2AndToggle(void);
extern void CallPauseScaledStorePushCall(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_00407400(void);
extern void PushSetCallPop(void);
extern unsigned int g_stateCountdown;
extern unsigned int g_installOwnerNode;
extern unsigned int g_cj_00542054;
extern unsigned int g_audioBoundNode;
extern unsigned int g_lastGatedValue;
extern unsigned int g_lastGatedTick;
extern unsigned int g_fightAxisNegX;
extern unsigned int g_fightAxisNegY;
extern unsigned int g_fightAxisPosX;
extern unsigned int g_fightAxisPosY;

extern void MStackBootPush4Init(void);

extern s32 g_vtxValid;
extern s16 g_vtxMat[];
extern unsigned int g_dispatchSave1626[];
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
 *   (x,y,z) at g_dispatchSave1626/95e/964[ecx]; adds translation 0x7af9a4/a8/ac.
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
        movsx   edx, word ptr [ecx*2 + g_dispatchSave1626]
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
        movsx   eax, word ptr [ecx*2 + g_dispatchSave1626]
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
        movsx   edx, word ptr [ecx*2 + g_dispatchSave1626]
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
