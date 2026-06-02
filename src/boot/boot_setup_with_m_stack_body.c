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

/* @addr 0x00418e00 (379b boot) - 2-entry packed boot setup + body.
 *   Entry 1 (offset 0, 194b): sets g_walkCallback = &g_dispatchSave562>>2,
 *     calls PushSetXfmMaskCallPop. On no-error AND bit 2 of
 *     g_xformDirtyFlags clear: writes [g_fightGroupHead*4+0x30]=0xa9,
 *     +0x3c=g_particleEmitterNode, +0x70=0xffffaaab, +0x80=0xffffb334. Calls
 *     SetJmp_BootStateTriple. On no-error writes the body label at
 *     [g_xformEntityIdx*4+0x10] and calls ScaledTripleCopy54.
 *     On no-error writes g_eventQueueNotMask → +0x58 and tail-jmps
 *     0x4062f0.
 *   14b NOP align pad.
 *   Entry 2 / body (offset 0xd0, 171b): mstack-pushes
 *     g_pendingNodeType/0054205c, calls ChainWalkPushPop.
 *     On no-error: g_pendingNodeType = g_load_0052ab10, computes
 *     [g_fightGroupHead*4+0x58] += 0x9fd70; if greater than the new
 *     0x54204c-derived value adds 0x3be3d7 instead. Then pops both
 *     mstack entries back.
 */
extern unsigned int g_dispatchSave562;
extern unsigned int g_load_0052ab10;
extern unsigned int g_particleEmitterNode;
extern unsigned int g_table_004d57b0;
extern void ChainWalkPushPop(void);
extern void MStackCall_004062f0(void);
extern void PushSetXfmMaskCallPop(void);
extern void ScaledTripleCopy54(void);
extern void SetJmp_BootStateTriple(void);

__declspec(naked) void BootSetupWithMStackBody(void) {
    __asm {
        mov     eax, offset g_dispatchSave562
        shr     eax, 2
        mov     dword ptr [g_walkCallback], eax
        call    PushSetXfmMaskCallPop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     L_bsm_e1End
        test    byte ptr [g_xformDirtyFlags], 4
        jne     L_bsm_e1End
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     dword ptr [ecx*4 + 0x30], 0xa9
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [g_particleEmitterNode]
        mov     dword ptr [edx*4 + 0x3c], eax
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, 0xffffb334
        mov     dword ptr [ecx*4 + 0x70], 0xffffaaab
        mov     edx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x80], eax
        call    SetJmp_BootStateTriple
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_bsm_e1End
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, offset L_bsm_body
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x10], eax
        call    ScaledTripleCopy54
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_bsm_e1End
        mov     edx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [g_eventQueueNotMask]
        mov     dword ptr [edx*4 + 0x58], eax
        jmp     MStackCall_004062f0
    L_bsm_e1End:
        ret
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
        nop
    L_bsm_body:
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_pendingNodeType]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + g_table_004d57b0], ecx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [g_fightGroupHead]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + g_table_004d57b0], edx
        call    ChainWalkPushPop
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_bsm_bodyEnd
        mov     ecx, dword ptr [g_load_0052ab10]
        mov     edx, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_pendingNodeType], ecx
        push    esi
        mov     eax, dword ptr [edx*4 + 0x58]
        add     eax, 0x9fd70
        mov     dword ptr [g_walkCallback], eax
        mov     esi, dword ptr [ecx*4 + 0x58]
        cmp     eax, esi
        jg      short L_bsm_skipAdd
        add     eax, 0x3be3d7
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [edx*4 + 0x58], eax
    L_bsm_skipAdd:
        mov     eax, dword ptr [g_matrixStackTop]
        pop     esi
        mov     ecx, dword ptr [eax*4 + g_table_004d57b0]
        dec     eax
        mov     dword ptr [g_fightGroupHead], ecx
        mov     dword ptr [g_matrixStackTop], eax
        mov     edx, dword ptr [eax*4 + g_table_004d57b0]
        dec     eax
        mov     dword ptr [g_pendingNodeType], edx
        mov     dword ptr [g_matrixStackTop], eax
    L_bsm_bodyEnd:
        ret
    }
}
