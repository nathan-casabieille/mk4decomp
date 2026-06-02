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

/* @addr 0x004cca50 (177b crt) - multi-precision left shift on a 4-u32 array.
 *   args: count (signed dword count, [esp+0x10] pre-push), ptr (u32* base, arg0).
 *   Step 1 (loop 3 iters): shift each u32 by abs(count)&31, propagating bits via ebx temp,
 *     storing back into the previous slot with edi/mask preserved low-bit pattern.
 *   Step 2 (loop 3 iters i=2..0): if i < (count>>5): word[i] = word[i - count>>5];
 *     else word[i] = 0.
 *   Result: u32 array shifted right by count, accounting for negative counts via sign trick.
 */
__declspec(naked) void BitShiftMultiPrecision(void) {
    __asm {
        sub     esp, 8
        mov     ecx, [esp + 0x10]
        push    ebx
        mov     eax, ecx
        push    ebp
        cdq
        and     edx, 0x1f
        push    esi
        add     eax, edx
        push    edi
        sar     eax, 5
        mov     [esp + 0x14], eax
        mov     eax, ecx
        cdq
        xor     eax, edx
        mov     esi, [esp + 0x1c]
        sub     eax, edx
        or      edi, -1
        and     eax, 0x1f
        mov     ebp, 0x20
        xor     eax, edx
        xor     ebx, ebx
        sub     eax, edx
        mov     dword ptr [esp + 0x20], 3
        mov     ecx, eax
        shl     edi, cl
        sub     ebp, eax
        not     edi
    L_shf_lp1:
        mov     edx, [esi]
        mov     ecx, edi
        and     ecx, edx
        add     esi, 4
        mov     [esp + 0x10], ecx
        mov     ecx, eax
        shr     edx, cl
        mov     ecx, ebp
        or      edx, ebx
        mov     ebx, [esp + 0x10]
        shl     ebx, cl
        mov     ecx, [esp + 0x20]
        mov     [esi - 4], edx
        dec     ecx
        mov     [esp + 0x20], ecx
        jne     short L_shf_lp1
        mov     ebx, [esp + 0x14]
        mov     esi, 2
        mov     ecx, 8
        lea     edi, [ebx*4 + 0]
    L_shf_lp2:
        cmp     esi, ebx
        jl      short L_shf_zero
        mov     edx, [esp + 0x1c]
        mov     eax, ecx
        sub     eax, edi
        mov     eax, [edx + eax]
        mov     [edx + ecx], eax
        jmp     short L_shf_next
    L_shf_zero:
        mov     edx, [esp + 0x1c]
        mov     dword ptr [edx + ecx], 0
    L_shf_next:
        dec     esi
        sub     ecx, 4
        jns     short L_shf_lp2
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 8
        ret
    }
}
