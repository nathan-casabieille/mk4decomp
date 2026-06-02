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
extern void SetJmp_0049cb90(void);
extern void Thunk_0049cbd0(void);
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
extern void Wrapper_00436490(void);
extern void MoveFsmCluster(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_004bd5c0(void);
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
extern void Wrapper_0048a350(void);
extern void Wrapper_0048a3a0(void);
extern void Helper_DownloadSetup(void);
extern void MStackPush3CmpCall(void);
extern void Wrapper_0048ec20(void);
extern void FiveCallScaledChainTailJmp(void);
extern void SetJmp_00438f50(void);
extern void SetJmp_00438f60(void);
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

/* @addr 0x004b31e0 (301b engine.app) - 2x3-vector × 3x3-matrix Q12 multiply.
 *   Calls Word9Reorder(0x007af990, &local) to pull 9 words into local
 *   stack buf. Computes 6 Q12 dot products:
 *     out[0..2] = M_row0 . v0,  M_row0 . v1
 *     out[3..5] = M_row1 . v0,  M_row1 . v1
 *   (where v0 is words at +0x18, v1 at +0x1c). Matrix is in
 *   g_arr_007af9c0..d4. Results stored to g_vtxLight0_x..ec.
 */
extern s16 g_vtxMat[];
extern unsigned int g_arr_007af9c0;
extern unsigned int g_arr_007af9c4;
extern unsigned int g_arr_007af9c8;
extern unsigned int g_dispatchSave1627_007af9cc;
extern unsigned int g_dispatchSave1628_007af9d0;
extern unsigned int g_dispatchSave1629_007af9d4;
extern s32 g_vtxLight0_x;
extern s32 g_vtxLight0_y;
extern s32 g_vtxLight0_z;
extern s32 g_vtxLight1_x;
extern s32 g_vtxLight1_z;
extern s32 g_vtxLight1_y;
extern void Word9Reorder(void);

__declspec(naked) void MatVec2Multiply(void) {
    __asm {
        sub     esp, 0x20
        _emit   8dh
        _emit   44h
        _emit   24h
        _emit   0h
        push    ebx
        push    ebp
        push    esi
        push    edi
        push    eax
        push    offset g_vtxMat
        call    Word9Reorder
        movsx   esi, word ptr [esp + 0x18]
        movsx   edx, word ptr [esp + 0x1a]
        mov     eax, dword ptr [g_arr_007af9c0]
        mov     ecx, dword ptr [g_arr_007af9c4]
        mov     ebx, eax
        mov     ebp, ecx
        imul    ebx, esi
        imul    ebp, edx
        movsx   edi, word ptr [esp + 0x1c]
        mov     edx, dword ptr [g_arr_007af9c8]
        add     ebx, ebp
        mov     ebp, edx
        add     esp, 8
        imul    ebp, edi
        movsx   edi, word ptr [esp + 0x16]
        add     ebx, ebp
        mov     ebp, eax
        sar     ebx, 0x0c
        imul    ebp, edi
        mov     dword ptr [g_vtxLight0_x], ebx
        mov     edi, ecx
        movsx   ebx, word ptr [esp + 0x18]
        imul    edi, ebx
        add     ebp, edi
        mov     ebx, edx
        movsx   edi, word ptr [esp + 0x1a]
        imul    ebx, edi
        add     ebp, ebx
        movsx   ebx, word ptr [esp + 0x1c]
        sar     ebp, 0x0c
        imul    eax, ebx
        movsx   ebx, word ptr [esp + 0x1e]
        mov     dword ptr [g_vtxLight0_y], ebp
        imul    ecx, ebx
        movsx   ebp, word ptr [esp + 0x20]
        imul    edx, ebp
        add     eax, ecx
        mov     ecx, dword ptr [g_dispatchSave1628_007af9d0]
        add     eax, edx
        movsx   edx, word ptr [esp + 0x12]
        sar     eax, 0x0c
        mov     dword ptr [g_vtxLight0_z], eax
        mov     eax, dword ptr [g_dispatchSave1627_007af9cc]
        mov     ebx, eax
        imul    ebx, esi
        mov     esi, ecx
        imul    esi, edx
        mov     edx, dword ptr [g_dispatchSave1629_007af9d4]
        add     ebx, esi
        movsx   esi, word ptr [esp + 0x14]
        mov     ebp, edx
        imul    ebp, esi
        movsx   esi, word ptr [esp + 0x16]
        add     ebx, ebp
        mov     ebp, ecx
        sar     ebx, 0x0c
        mov     dword ptr [g_vtxLight1_x], ebx
        mov     ebx, eax
        imul    ebx, esi
        movsx   esi, word ptr [esp + 0x18]
        imul    ebp, esi
        mov     esi, edx
        add     ebx, ebp
        imul    esi, edi
        add     ebx, esi
        movsx   esi, word ptr [esp + 0x1c]
        imul    eax, esi
        movsx   esi, word ptr [esp + 0x1e]
        imul    ecx, esi
        sar     ebx, 0x0c
        mov     dword ptr [g_vtxLight1_z], ebx
        add     eax, ecx
        movsx   ecx, word ptr [esp + 0x20]
        imul    edx, ecx
        add     eax, edx
        pop     edi
        sar     eax, 0x0c
        pop     esi
        pop     ebp
        mov     dword ptr [g_vtxLight1_y], eax
        pop     ebx
        add     esp, 0x20
        ret
    }
}
