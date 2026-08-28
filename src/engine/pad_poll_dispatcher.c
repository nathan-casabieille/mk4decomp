/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel;
extern unsigned int g_chainAccumCur;
extern unsigned int g_cj_0054205c;
extern unsigned int g_gameCountdown;
extern unsigned int g_xformScratch94;
extern unsigned int g_fightStateProgress;
extern unsigned int g_active_00537e88;
extern unsigned int g_active_0053a408;
extern unsigned int g_audioBankSel;
#endif

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
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_cj_00542058;
extern unsigned int g_rangeSqLimit;
extern unsigned int g_armedReloadA;
extern unsigned int g_armedReloadB;
extern unsigned int g_dualBitGate;
extern unsigned int g_eventArmReload;
extern unsigned int g_rangeBase;
#endif

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
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
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
#endif

extern void Input_PollPlayerKeyboard(int player);
/* extern void Input_GetAsyncKey(int key); -- defined elsewhere with diff sig */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern u32 g_appInitFlag1;
extern unsigned int g_phaseThunkInst;
extern unsigned int g_renderer2_var5;
extern unsigned int g_dispatchSave537;
extern unsigned int g_dispatchSave536;
extern unsigned int g_dispatchSave630;
extern unsigned int g_dispatchSave629;
extern unsigned int g_dispatchSave535;
extern unsigned int g_dispatchSave534;
extern unsigned int g_dispatchSave628;
extern unsigned int g_dispatchSave627;
extern unsigned int g_renderer2_var7;
extern unsigned int g_renderer2_var6;
extern unsigned int g_dispatchSave518;
extern unsigned int g_dispatchSave517;
extern unsigned int g_dispatchSave533;
extern unsigned int g_dispatchSave532;
extern unsigned int g_dispatchSave626;
extern unsigned int g_dispatchSave625;
extern unsigned int g_dispatchSave27;
extern unsigned int g_dispatchSave26;
extern unsigned int g_dispatchSave25;
extern unsigned int g_dispatchVar39;
#endif

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern u32 g_demoModeFlag;
#endif
#ifdef NON_MATCHING
extern int Input_GetAsyncKey(int);
#else
extern void Input_GetAsyncKey(void);
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_active_00537e88 (*(unsigned int *)MK4_VA(unsigned int, 0x537e88u))
#define g_active_0053a408 (*(unsigned int *)MK4_VA(unsigned int, 0x53a408u))
#define g_appInitFlag1 (*(unsigned int *)MK4_VA(unsigned int, 0x7af920u))
#define g_armedReloadA (*(unsigned int *)MK4_VA(unsigned int, 0x541fa4u))
#define g_armedReloadB (*(unsigned int *)MK4_VA(unsigned int, 0x541fa8u))
#define g_audioBankSel (*(unsigned int *)MK4_VA(unsigned int, 0x537f94u))
#define g_audioBoundNode (*(unsigned int *)MK4_VA(unsigned int, 0x5437f0u))
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_chainAccumCur (*(unsigned int *)MK4_VA(unsigned int, 0x542078u))
#define g_cj_00542054 (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_cj_00542058 (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))
#define g_cj_0054205c (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_demoModeFlag (*(unsigned int *)MK4_VA(unsigned int, 0x4ffd7cu))
#define g_dispatchSave25 (*(unsigned int *)MK4_VA(unsigned int, 0x543370u))
#define g_dispatchSave26 (*(unsigned int *)MK4_VA(unsigned int, 0x54336cu))
#define g_dispatchSave27 (*(unsigned int *)MK4_VA(unsigned int, 0x543368u))
#define g_dispatchSave517 (*(unsigned int *)MK4_VA(unsigned int, 0x4f4df4u))
#define g_dispatchSave518 (*(unsigned int *)MK4_VA(unsigned int, 0x4f4df0u))
#define g_dispatchSave532 (*(unsigned int *)MK4_VA(unsigned int, 0x4f4dfcu))
#define g_dispatchSave533 (*(unsigned int *)MK4_VA(unsigned int, 0x4f4df8u))
#define g_dispatchSave534 (*(unsigned int *)MK4_VA(unsigned int, 0x4f4ddcu))
#define g_dispatchSave535 (*(unsigned int *)MK4_VA(unsigned int, 0x4f4dd8u))
#define g_dispatchSave536 (*(unsigned int *)MK4_VA(unsigned int, 0x4f4dccu))
#define g_dispatchSave537 (*(unsigned int *)MK4_VA(unsigned int, 0x4f4dc8u))
#define g_dispatchSave625 (*(unsigned int *)MK4_VA(unsigned int, 0x4f4e04u))
#define g_dispatchSave626 (*(unsigned int *)MK4_VA(unsigned int, 0x4f4e00u))
#define g_dispatchSave627 (*(unsigned int *)MK4_VA(unsigned int, 0x4f4de4u))
#define g_dispatchSave628 (*(unsigned int *)MK4_VA(unsigned int, 0x4f4de0u))
#define g_dispatchSave629 (*(unsigned int *)MK4_VA(unsigned int, 0x4f4dd4u))
#define g_dispatchSave630 (*(unsigned int *)MK4_VA(unsigned int, 0x4f4dd0u))
#define g_dispatchVar39 (*(unsigned int *)MK4_VA(unsigned int, 0x54357cu))
#define g_dualBitGate (*(unsigned int *)MK4_VA(unsigned int, 0x53a7b0u))
#define g_eventArmReload (*(unsigned int *)MK4_VA(unsigned int, 0x53a770u))
#define g_fightAxisNegX (*(unsigned int *)MK4_VA(unsigned int, 0x535e70u))
#define g_fightAxisNegY (*(unsigned int *)MK4_VA(unsigned int, 0x535e74u))
#define g_fightAxisPosX (*(unsigned int *)MK4_VA(unsigned int, 0x535e78u))
#define g_fightAxisPosY (*(unsigned int *)MK4_VA(unsigned int, 0x535e7cu))
#define g_fightStateProgress (*(unsigned int *)MK4_VA(unsigned int, 0x535ddcu))
#define g_fightTableC0 (*(unsigned int *)MK4_VA(unsigned int, 0x4d50a4u))
#define g_fightTableC1 (*(unsigned int *)MK4_VA(unsigned int, 0x4d50a8u))
#define g_fightTableC2 (*(unsigned int *)MK4_VA(unsigned int, 0x4d50b0u))
#define g_gameCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a718u))
#define g_gameStateResult (*(unsigned int *)MK4_VA(unsigned int, 0x7af918u))
#define g_installOwnerNode (*(unsigned int *)MK4_VA(unsigned int, 0x535cf8u))
#define g_lastGatedTick (*(unsigned int *)MK4_VA(unsigned int, 0x54358cu))
#define g_lastGatedValue (*(unsigned int *)MK4_VA(unsigned int, 0x543598u))
#define g_phaseThunkInst (*(unsigned int *)MK4_VA(unsigned int, 0x4d50acu))
#define g_rangeBase (*(unsigned int *)MK4_VA(unsigned int, 0x53a46cu))
#define g_rangeSqLimit (*(unsigned int *)MK4_VA(unsigned int, 0x53a180u))
#define g_renderer2_var5 (*(unsigned int *)MK4_VA(unsigned int, 0x4f4e98u))
#define g_renderer2_var6 (*(unsigned int *)MK4_VA(unsigned int, 0x4f4decu))
#define g_renderer2_var7 (*(unsigned int *)MK4_VA(unsigned int, 0x4f4de8u))
#define g_stateCountdown (*(unsigned int *)MK4_VA(unsigned int, 0x53a3c0u))
#define g_xformScratch94 (*(unsigned int *)MK4_VA(unsigned int, 0x542094u))
#endif

extern void Input_PollPlayerJoystick(void);

#ifdef NON_MATCHING
#include "portable/mem_model.h"

/* @addr 0x004b5650 (494b) - NATIVE twin; the matching build takes the
 * synthesizer's copy (the naked body lives in the QQ variants file).
 *
 * Thirteen unrolled button tests, one shape each: read this player's
 * virtual-key code from the key map, and if the key is down OR the mask
 * for that button into the target word. Three parallel tables, all
 * indexed the same way:
 *   key map  0x543ab8 + button*8  + player*4
 *   target   0x4f4dcc + button*16 + player*8   (a POINTER, i.e. a VA)
 *   mask     0x4f4dc8 + button*16 + player*8
 * The head is the Win32 alt-tab guard: while Alt is held the whole poll
 * is skipped, so a window switch does not land as a fistful of inputs.
 * It goes through the import slot, which the trampoline maps. */
void Input_PollPlayerKeyboard(int player)
{
    unsigned int b, tgt, mask;
    int vk;

    if (MK4_ALT_KEY_DOWN() & 0x8001)
        return;

    for (b = 0; b < 13; b++) {
        vk = *MK4_VA(int, 0x543ab8u + b * 8u + (unsigned)player * 4u);
        if (Input_GetAsyncKey(vk)) {
            tgt  = *MK4_VA(unsigned int,
                           0x4f4dccu + b * 0x10u + (unsigned)player * 8u);
            mask = *MK4_VA(unsigned int,
                           0x4f4dc8u + b * 0x10u + (unsigned)player * 8u);
            *MK4_VA(unsigned int, tgt) |= mask;
        }
    }
}
#else
/* no matching-side C here - the synthesizer provides 0x004b5650. */
#endif

#ifndef NON_MATCHING /* twin: game_state_machine_maybe_rebuild.c */
__declspec(naked) void Input_TickPlayers(void)
{
    __asm {
        mov     eax, dword ptr [g_demoModeFlag]
        push    esi
        xor     esi, esi
        cmp     eax, esi
        mov     dword ptr [g_fightTableC2], esi
        mov     dword ptr [g_fightTableC0], esi
        mov     dword ptr [g_fightTableC1], esi
        mov     dword ptr [g_phaseThunkInst], esi
        je      L_idep_after_clear_masks
        cmp     dword ptr [g_gameStateResult], esi
        jne     L_idep_after_clear_masks
        push    esi
        call    Input_PollPlayerKeyboard
        add     esp, 4
        push    1
        call    Input_PollPlayerKeyboard
        add     esp, 4
        push    esi
        call    Input_PollPlayerJoystick
        add     esp, 4
        push    1
        call    Input_PollPlayerJoystick
        mov     eax, dword ptr [g_renderer2_var5]
        add     esp, 4
        cmp     eax, esi
        je      L_idep_pause_gate2
        cmp     dword ptr [g_fightTableC2], esi
        jne     L_idep_clear_loop
        cmp     dword ptr [g_fightTableC0], esi
        jne     L_idep_clear_loop
        cmp     dword ptr [g_fightTableC1], esi
        jne     L_idep_clear_loop
        cmp     dword ptr [g_phaseThunkInst], esi
        jne     L_idep_clear_loop
        push    0x1B
        call    Input_GetAsyncKey
        add     esp, 4
        test    eax, eax
        jne     L_idep_clear_loop
        push    0x20
        call    Input_GetAsyncKey
        add     esp, 4
        test    eax, eax
        jne     L_idep_clear_loop
        push    0x0D
        call    Input_GetAsyncKey
        add     esp, 4
        test    eax, eax
        jne     L_idep_clear_loop
        mov     dword ptr [g_renderer2_var5], esi
    L_idep_clear_loop:
        mov     dword ptr [g_fightTableC2], esi
        mov     dword ptr [g_fightTableC0], esi
        mov     dword ptr [g_fightTableC1], esi
        mov     dword ptr [g_phaseThunkInst], esi
    L_idep_pause_gate2:
        cmp     dword ptr [g_appInitFlag1], esi
        je      L_idep_after_clear_masks
        mov     eax, dword ptr [g_renderer2_var6]
        mov     ecx, dword ptr [g_renderer2_var7]
        not     ecx
        mov     edx, dword ptr [eax]
        and     edx, ecx
        mov     dword ptr [eax], edx
        mov     eax, dword ptr [g_dispatchSave517]
        mov     edx, dword ptr [g_dispatchSave518]
        mov     ecx, dword ptr [eax]
        not     edx
        and     ecx, edx
        mov     dword ptr [eax], ecx
    L_idep_after_clear_masks:
        mov     ecx, dword ptr [g_dispatchSave536]
        mov     eax, dword ptr [g_dispatchSave537]
        test    dword ptr [ecx], eax
        je      L_idep_skip1
        mov     eax, dword ptr [g_dispatchSave534]
        mov     edx, dword ptr [g_dispatchSave535]
        not     edx
        and     dword ptr [eax], edx
    L_idep_skip1:
        mov     ecx, dword ptr [g_dispatchSave629]
        mov     eax, dword ptr [g_dispatchSave630]
        test    dword ptr [ecx], eax
        je      L_idep_skip2
        mov     eax, dword ptr [g_dispatchSave627]
        mov     edx, dword ptr [g_dispatchSave628]
        not     edx
        and     dword ptr [eax], edx
    L_idep_skip2:
        mov     ecx, dword ptr [g_renderer2_var6]
        mov     eax, dword ptr [g_renderer2_var7]
        test    dword ptr [ecx], eax
        je      L_idep_skip3
        mov     eax, dword ptr [g_dispatchSave532]
        mov     edx, dword ptr [g_dispatchSave533]
        not     edx
        and     dword ptr [eax], edx
    L_idep_skip3:
        mov     ecx, dword ptr [g_dispatchSave517]
        mov     eax, dword ptr [g_dispatchSave518]
        test    dword ptr [ecx], eax
        je      L_idep_skip4
        mov     eax, dword ptr [g_dispatchSave625]
        mov     edx, dword ptr [g_dispatchSave626]
        not     edx
        and     dword ptr [eax], edx
    L_idep_skip4:
        mov     esi, dword ptr [g_phaseThunkInst]
        mov     eax, dword ptr [g_fightTableC2]
        mov     ecx, dword ptr [g_fightTableC0]
        mov     edx, dword ptr [g_fightTableC1]
        not     esi
        not     eax
        not     ecx
        not     edx
        mov     dword ptr [g_phaseThunkInst], esi
        mov     dword ptr [g_dispatchSave27], esi
        mov     dword ptr [g_fightTableC2], eax
        mov     dword ptr [g_fightTableC0], ecx
        mov     dword ptr [g_fightTableC1], edx
        mov     dword ptr [g_dispatchVar39], eax
        mov     dword ptr [g_dispatchSave26], ecx
        mov     dword ptr [g_dispatchSave25], edx
        pop     esi
        ret
    }
}
#endif
