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

/* @addr 0x00489d10 (380b game) - 2D squared-distance threshold + revert.
 *   Reads cached (x², y²) from [scaled+0x54]/[scaled+0x5c] via two
 *   Mul10Tail(x,x)+Mul10Tail(y,y) calls into g_eventQueueCurrent, stores
 *   into [g_eventQueueTotal*4] as the cur radius. Compares against
 *   g_rangeSqLimit; if greater-or-equal proceeds to the success path
 *   (advance position), else first stashes the un-advanced position
 *   into a save-slot keyed by g_pendingNodeType vs g_player1NodeIdx (either
 *   0x543560/8/4 or 0x543580/4/8) and continues.
 *
 *   Position advance: takes the cached (x,y)+(dx,dy) vector at
 *   [scaled+0x54]+[scaled+0x6c] etc., computes the new squared
 *   distance, compares against the cached radius. If exceeded, RESTORES
 *   the save-slot (revert advance) and conditionally clears velocity
 *   bytes at [scaled+0x6c]/+0x74 if bit 7 of [scaled+0x40] is clear.
 */
extern unsigned int g_dispatchTab64_00543554;
extern unsigned int g_dispatchVar32_00543558;
extern unsigned int g_installCountdownVar2_00543560;
extern unsigned int g_installCountdownVar_00543580;
extern unsigned int g_dispatchVar31_00543584;
extern unsigned int g_dispatchTab63_00543588;

__declspec(naked) void SqDistThresholdRevertAdvance_00489d10(void) {
    __asm {
        mov     eax, dword ptr [g_pendingNodeType]
        push    esi
        push    edi
        lea     esi, [eax*4]
        mov     eax, dword ptr [eax*4 + 0x54]
        mov     dword ptr [g_walkCallback], eax
        mov     ecx, dword ptr [esi + 0x5c]
        push    eax
        push    eax
        mov     dword ptr [g_eventQueueCurrent], ecx
        mov     dword ptr [g_acc_00542078], eax
        mov     dword ptr [g_eventQueueNotMask], ecx
        call    Mul10Tail
        add     esp, 8
        mov     dword ptr [g_walkCallback], eax
        mov     eax, dword ptr [g_eventQueueCurrent]
        push    eax
        push    eax
        call    Mul10Tail
        mov     ecx, dword ptr [g_walkCallback]
        mov     edx, dword ptr [g_eventQueueTotal]
        add     ecx, eax
        add     esp, 8
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [edx*4], ecx
        mov     eax, dword ptr [g_rangeSqLimit]
        mov     ecx, dword ptr [g_walkCallback]
        cmp     ecx, eax
        mov     dword ptr [g_eventQueueCurrent], eax
        jge     short L_sdt_advance
        mov     edx, dword ptr [g_pendingNodeType]
        mov     edi, dword ptr [g_player1NodeIdx]
        cmp     edx, edi
        mov     edx, dword ptr [esi + 0x54]
        jne     short L_sdt_stashAlt
        mov     dword ptr [g_installCountdownVar2_00543560], edx
        mov     edx, dword ptr [esi + 0x5c]
        mov     dword ptr [g_dispatchVar32_00543558], edx
        mov     dword ptr [g_dispatchTab64_00543554], ecx
        jmp     short L_sdt_cmpRadius
    L_sdt_stashAlt:
        mov     dword ptr [g_installCountdownVar_00543580], edx
        mov     edx, dword ptr [esi + 0x5c]
        mov     dword ptr [g_dispatchVar31_00543584], edx
        mov     dword ptr [g_dispatchTab63_00543588], ecx
    L_sdt_cmpRadius:
        cmp     ecx, eax
        jl      L_sdt_done
    L_sdt_advance:
        mov     eax, dword ptr [esi + 0x54]
        mov     dword ptr [g_eventQueueNotMask], eax
        mov     ecx, dword ptr [esi + 0x5c]
        mov     dword ptr [g_eventQueueCurrent], ecx
        mov     edx, dword ptr [esi + 0x6c]
        mov     dword ptr [g_eventQueueWorkType], edx
        mov     edi, dword ptr [esi + 0x74]
        add     eax, edx
        add     ecx, edi
        push    eax
        push    eax
        mov     dword ptr [g_acc_00542078], edi
        mov     dword ptr [g_eventQueueNotMask], eax
        mov     dword ptr [g_eventQueueCurrent], ecx
        call    Mul10Tail
        add     esp, 8
        mov     dword ptr [g_eventQueueNotMask], eax
        mov     eax, dword ptr [g_eventQueueCurrent]
        push    eax
        push    eax
        call    Mul10Tail
        mov     edx, dword ptr [g_eventQueueNotMask]
        mov     ecx, dword ptr [g_walkCallback]
        add     eax, edx
        add     esp, 8
        cmp     eax, ecx
        mov     dword ptr [g_eventQueueCurrent], eax
        jle     short L_sdt_done
        mov     eax, dword ptr [g_pendingNodeType]
        mov     ecx, dword ptr [g_player1NodeIdx]
        cmp     eax, ecx
        jne     short L_sdt_restoreAlt
        mov     ecx, dword ptr [g_installCountdownVar2_00543560]
        mov     dword ptr [esi + 0x54], ecx
        mov     edx, dword ptr [g_dispatchVar32_00543558]
        mov     dword ptr [esi + 0x5c], edx
        jmp     short L_sdt_checkBit
    L_sdt_restoreAlt:
        mov     eax, dword ptr [g_installCountdownVar_00543580]
        mov     dword ptr [esi + 0x54], eax
        mov     ecx, dword ptr [g_dispatchVar31_00543584]
        mov     dword ptr [esi + 0x5c], ecx
    L_sdt_checkBit:
        mov     eax, dword ptr [esi + 0x40]
        mov     dword ptr [g_eventQueueWorkType], eax
        and     eax, 0x80
        mov     dword ptr [g_xformScratch94], eax
        jne     short L_sdt_done
        xor     eax, eax
        mov     dword ptr [esi + 0x6c], eax
        mov     dword ptr [esi + 0x74], eax
    L_sdt_done:
        pop     edi
        pop     esi
        ret
    }
}
