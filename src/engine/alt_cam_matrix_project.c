/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
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
extern void CallPauseDirty1JmpDirty4StackPush_GuardedDoubleIncCmpJmp(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void InstallSelfChainSet84_80CallW(void);
extern void Wrapper_PackedAdvanceCallTailJmp_004e46d0(void);
extern void MoveFsmCluster(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain(void);
extern void CopyJmp_SlotCmp3way_g_currentNodeIdx(void);
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
extern void DispatcherComplex260_MStackBracket1_TreeWalkRecursive2(void);
extern void ScaledLoadCmpStoreXfm(void);
extern void StackPopDispatchTagged(void);
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit;
extern unsigned int g_zero_00541fa4;
extern unsigned int g_zero_00541fa8;
extern unsigned int g_dualBitGate;
extern unsigned int g_eventArmReload;
extern unsigned int g_rangeBase;

extern void ScaledArrStore_ScaledChainJmp_004298c0(void);
extern void DualFieldAddSubStore(void);
extern void IterStepDualStore(int);
extern void ScaledXorStore_004900f0(void);
extern void ChainWalkInstall(void);
extern void FpuSqrtMul(void);
extern void PendingMatch_StoreTwoCall_0042b930(void);
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
extern void GuardedDispatch_InstallSelfDualEsi(void);
extern void MStackPushZeroCallPop_PendingMatch(void);
extern void DirtyToggleByGate(void);
extern void GameDispatchValidateState(void);
extern void CrouchAttackFsmCluster(void);
extern void MStackPushVec3Mul10(void);
extern void LiteralPushCallEntZero(void);
extern void LeaPlus22StoreSelf(void);
extern void IterLoad_g_scaledInit_00542048_then_DualScaledStoreZero(void);
extern void GuardedDualConst2AndToggle(void);
extern void CallPauseScaledStorePushCall(void);
extern void LoadGeoAsset_Default(void);
extern void DispatcherComplex260_FramePauseScaledStore(void);
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

/* @addr 0x004b9840 (367b engine.render) - alt-camera-matrix project pass.
 *   On arg [esp+8] non-zero (use-alt-matrix flag): snapshots current
 *   camera matrix at g_vtxMat..7af9a0 into local stack 0x10/0x14/
 *   0x18/0x1c (and high-bytes), loads alternate camera matrix from
 *   g_dispatchSave1554/5c/60/64/68 into g_vtxMat..7af9a0, then calls
 *   Mat3x3VecMul6Bit(arg, &local_vec) to project the vertex
 *   buffer at [esp+0x40] through it.
 *
 *   On arg == 0: loads 4 dwords from [arg] (mat row 0..2) and the
 *   reflected vec at [arg+8] into local stack, populates the alt
 *   camera fields, then calls Mat3x3VecMul6Bit again.
 *
 *   Always restores the original camera matrix afterward if used,
 *   writes 0x1e0 into g_screenH (screen pitch?), and clamps
 *   a derived value: takes local[0x14] (negated z), shl 9, idiv ecx,
 *   then computes `(eax * 15) << 13 >> 16 + 0xf0` and clamps to
 *   (0, 0x1e0) before storing into g_screenH as a u16.
 */
extern unsigned int g_screenH;
extern s16 g_vtxMat[];
extern unsigned int g_mat3x3_007af994;
extern unsigned int g_mat3x3_007af998;
extern unsigned int g_mat3x3_007af99c;
extern unsigned int g_mat3x3_007af9a0;
extern unsigned int g_table_00ab4878;
extern unsigned int g_dispatchSave1530;
extern unsigned int g_dispatchSave1531;
extern unsigned int g_dispatchSave1532;
extern unsigned int g_dispatchSave1533;
extern unsigned int g_dispatchSave1554;
extern unsigned int g_dispatchSave1555;
extern unsigned int g_dispatchSave1556;
extern unsigned int g_dispatchSave1557;
extern unsigned int g_dispatchSave1558;
extern unsigned int g_dispatchSave1569;
extern void Mat3x3VecMul6Bit(void);

__declspec(naked) void AltCamMatrixProject(void) {
    __asm {
        mov     eax, dword ptr [esp + 8]
        sub     esp, 0x2c
        test    eax, eax
        push    ebx
        push    ebp
        push    esi
        push    edi
        je      short L_acm_noAlt
        mov     eax, dword ptr [g_vtxMat]
        mov     ecx, dword ptr [g_dispatchSave1554]
        mov     ebx, dword ptr [g_mat3x3_007af998]
        mov     edi, dword ptr [g_mat3x3_007af99c]
        mov     edx, dword ptr [g_dispatchSave1555]
        mov     ebp, dword ptr [g_mat3x3_007af994]
        mov     si, word ptr [g_mat3x3_007af9a0]
        mov     dword ptr [esp + 0x1c], eax
        mov     eax, dword ptr [g_dispatchSave1556]
        mov     dword ptr [g_vtxMat], ecx
        mov     ecx, dword ptr [g_dispatchSave1557]
        mov     dword ptr [g_mat3x3_007af998], eax
        mov     dword ptr [g_mat3x3_007af99c], ecx
        mov     ecx, dword ptr [esp + 0x40]
        lea     eax, [esp + 0x10]
        mov     dword ptr [g_mat3x3_007af994], edx
        mov     dx, word ptr [g_dispatchSave1558]
        push    eax
        push    ecx
        mov     word ptr [g_mat3x3_007af9a0], dx
        call    Mat3x3VecMul6Bit
        add     esp, 8
        jmp     short L_acm_postCall
    L_acm_noAlt:
        mov     eax, dword ptr [esp + 0x40]
        mov     si, word ptr [esp + 0x2c]
        mov     edi, dword ptr [esp + 0x28]
        mov     ebx, dword ptr [esp + 0x24]
        mov     edx, dword ptr [eax]
        mov     eax, dword ptr [eax + 8]
        mov     ebp, dword ptr [esp + 0x20]
        mov     dword ptr [esp + 0x10], edx
        mov     dword ptr [esp + 0x18], eax
    L_acm_postCall:
        mov     ecx, dword ptr [g_dispatchSave1569]
        mov     edx, dword ptr [g_table_00ab4878]
        mov     eax, dword ptr [g_dispatchSave1530]
        mov     dword ptr [g_vtxMat], edx
        mov     edx, dword ptr [g_dispatchSave1532]
        mov     dword ptr [g_mat3x3_007af994], eax
        neg     ecx
        mov     ax, word ptr [g_dispatchSave1533]
        mov     dword ptr [esp + 0x14], ecx
        mov     ecx, dword ptr [g_dispatchSave1531]
        mov     dword ptr [g_mat3x3_007af99c], edx
        mov     dword ptr [g_mat3x3_007af998], ecx
        lea     ecx, [esp + 0x10]
        lea     edx, [esp + 0x10]
        push    ecx
        push    edx
        mov     word ptr [g_mat3x3_007af9a0], ax
        call    Mat3x3VecMul6Bit
        mov     eax, dword ptr [esp + 0x4c]
        add     esp, 8
        test    eax, eax
        je      short L_acm_skipRestore
        mov     eax, dword ptr [esp + 0x1c]
        mov     dword ptr [g_mat3x3_007af994], ebp
        mov     dword ptr [g_vtxMat], eax
        mov     dword ptr [g_mat3x3_007af998], ebx
        mov     dword ptr [g_mat3x3_007af99c], edi
        mov     word ptr [g_mat3x3_007af9a0], si
    L_acm_skipRestore:
        mov     ecx, dword ptr [esp + 0x18]
        mov     word ptr [g_screenH], 0x1e0
        test    ecx, ecx
        jle     short L_acm_done
        mov     eax, dword ptr [esp + 0x14]
        shl     eax, 9
        cdq
        idiv    ecx
        lea     eax, [eax + eax*2]
        lea     eax, [eax + eax*4]
        shl     eax, 0xd
        sar     eax, 0x10
        add     eax, 0xf0
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        jle     short L_acm_done
        cmp     eax, 0x1e0
        jge     short L_acm_done
        mov     word ptr [g_screenH], ax
    L_acm_done:
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 0x2c
        ret
    }
}
