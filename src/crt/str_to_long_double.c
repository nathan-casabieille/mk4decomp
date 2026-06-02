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

/* @addr 0x004ce2f0 (241b crt) - decimal-string → 96-bit fixed-point parser.
 *   Builds a 12-byte accumulator at *FILE (esi): clears 12 bytes, then for each
 *   digit byte from str (ebx), shifts left by ~3.32 bits (call Shl96By1 four times
 *   to ×16, then add digit/×10 via TimeValAdd3) - actually the loop does shl×1,
 *   shl×1, add (shl×3 = ×8), shl×1, add (×10 emulation).
 *   After processing 'count' chars, normalizes the high word and writes the
 *   16-bit exponent at [esi+0xa]. exp = 0x404e (starting) decremented by 0x10
 *   each rough normalize step.
 */
extern void Shl96By1(void);
extern void TimeValAdd3(void);

__declspec(naked) void StrToLongDouble(void) {
    __asm {
        mov     eax, [esp + 8]
        sub     esp, 0xc
        push    ebx
        push    ebp
        push    esi
        mov     esi, [esp + 0x24]
        xor     ebp, ebp
        push    edi
        cmp     eax, ebp
        mov     edi, 0x404e
        mov     [esi], ebp
        mov     [esi + 4], ebp
        mov     [esi + 8], ebp
        jbe     short L_stld_norm
        mov     ebx, [esp + 0x20]
        mov     [esp + 0x28], eax
    L_stld_digit:
        mov     eax, esi
        push    esi
        mov     ecx, [eax]
        mov     [esp + 0x14], ecx
        mov     edx, [eax + 4]
        mov     [esp + 0x18], edx
        mov     eax, [eax + 8]
        mov     [esp + 0x1c], eax
        call    Shl96By1
        add     esp, 4
        push    esi
        call    Shl96By1
        add     esp, 4
        lea     ecx, [esp + 0x10]
        push    ecx
        push    esi
        call    TimeValAdd3
        add     esp, 8
        push    esi
        call    Shl96By1
        movsx   edx, byte ptr [ebx]
        add     esp, 4
        lea     eax, [esp + 0x10]
        mov     [esp + 0x10], edx
        mov     [esp + 0x14], ebp
        push    eax
        push    esi
        mov     [esp + 0x20], ebp
        call    TimeValAdd3
        mov     eax, [esp + 0x30]
        add     esp, 8
        inc     ebx
        dec     eax
        mov     [esp + 0x28], eax
        jne     short L_stld_digit
    L_stld_norm:
        cmp     [esi + 8], ebp
        jne     short L_stld_topBit
    L_stld_norm16:
        mov     eax, [esi + 4]
        add     edi, 0xfff0
        mov     ecx, eax
        shr     ecx, 16
        mov     [esi + 8], ecx
        mov     ecx, [esi]
        mov     edx, ecx
        shr     edx, 16
        shl     eax, 16
        or      edx, eax
        mov     eax, [esi + 8]
        shl     ecx, 16
        cmp     eax, ebp
        mov     [esi + 4], edx
        mov     [esi], ecx
        jz      short L_stld_norm16
    L_stld_topBit:
        mov     eax, [esi + 8]
        mov     ebx, 0x8000
        test    eax, ebx
        jne     short L_stld_storeExp
    L_stld_normBit:
        push    esi
        call    Shl96By1
        mov     eax, [esi + 8]
        add     esp, 4
        add     edi, 0xffff
        test    eax, ebx
        jz      short L_stld_normBit
    L_stld_storeExp:
        mov     word ptr [esi + 0xa], di
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 0xc
        ret
    }
}
