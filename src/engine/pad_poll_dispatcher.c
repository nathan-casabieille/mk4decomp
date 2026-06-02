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

extern void Input_PollPlayerKeyboard(int player);
/* extern void Input_GetAsyncKey(int key); -- defined elsewhere with diff sig */
extern u32 g_appInitFlag1;
extern unsigned int g_phaseThunkInst_004d50ac;
extern unsigned int g_renderer2_var5_004f4e98;
extern unsigned int g_dispatchSave537_004f4dc8;
extern unsigned int g_dispatchSave536_004f4dcc;
extern unsigned int g_dispatchSave630_004f4dd0;
extern unsigned int g_dispatchSave629_004f4dd4;
extern unsigned int g_dispatchSave535_004f4dd8;
extern unsigned int g_dispatchSave534_004f4ddc;
extern unsigned int g_dispatchSave628_004f4de0;
extern unsigned int g_dispatchSave627_004f4de4;
extern unsigned int g_renderer2_var7_004f4de8;
extern unsigned int g_renderer2_var6_004f4dec;
extern unsigned int g_dispatchSave518_004f4df0;
extern unsigned int g_dispatchSave517_004f4df4;
extern unsigned int g_dispatchSave533_004f4df8;
extern unsigned int g_dispatchSave532_004f4dfc;
extern unsigned int g_dispatchSave626_004f4e00;
extern unsigned int g_dispatchSave625_004f4e04;
extern unsigned int g_dispatchSave27_00543368;
extern unsigned int g_dispatchSave26_0054336c;
extern unsigned int g_dispatchSave25_00543370;
extern unsigned int g_dispatchVar39_0054357c;

extern u32 g_demoModeFlag;
extern void Input_GetAsyncKey(void);
extern void Input_PollPlayerJoystick(void);

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
        mov     dword ptr [g_phaseThunkInst_004d50ac], esi
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
        mov     eax, dword ptr [g_renderer2_var5_004f4e98]
        add     esp, 4
        cmp     eax, esi
        je      L_idep_pause_gate2
        cmp     dword ptr [g_fightTableC2], esi
        jne     L_idep_clear_loop
        cmp     dword ptr [g_fightTableC0], esi
        jne     L_idep_clear_loop
        cmp     dword ptr [g_fightTableC1], esi
        jne     L_idep_clear_loop
        cmp     dword ptr [g_phaseThunkInst_004d50ac], esi
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
        mov     dword ptr [g_renderer2_var5_004f4e98], esi
    L_idep_clear_loop:
        mov     dword ptr [g_fightTableC2], esi
        mov     dword ptr [g_fightTableC0], esi
        mov     dword ptr [g_fightTableC1], esi
        mov     dword ptr [g_phaseThunkInst_004d50ac], esi
    L_idep_pause_gate2:
        cmp     dword ptr [g_appInitFlag1], esi
        je      L_idep_after_clear_masks
        mov     eax, dword ptr [g_renderer2_var6_004f4dec]
        mov     ecx, dword ptr [g_renderer2_var7_004f4de8]
        not     ecx
        mov     edx, dword ptr [eax]
        and     edx, ecx
        mov     dword ptr [eax], edx
        mov     eax, dword ptr [g_dispatchSave517_004f4df4]
        mov     edx, dword ptr [g_dispatchSave518_004f4df0]
        mov     ecx, dword ptr [eax]
        not     edx
        and     ecx, edx
        mov     dword ptr [eax], ecx
    L_idep_after_clear_masks:
        mov     ecx, dword ptr [g_dispatchSave536_004f4dcc]
        mov     eax, dword ptr [g_dispatchSave537_004f4dc8]
        test    dword ptr [ecx], eax
        je      L_idep_skip1
        mov     eax, dword ptr [g_dispatchSave534_004f4ddc]
        mov     edx, dword ptr [g_dispatchSave535_004f4dd8]
        not     edx
        and     dword ptr [eax], edx
    L_idep_skip1:
        mov     ecx, dword ptr [g_dispatchSave629_004f4dd4]
        mov     eax, dword ptr [g_dispatchSave630_004f4dd0]
        test    dword ptr [ecx], eax
        je      L_idep_skip2
        mov     eax, dword ptr [g_dispatchSave627_004f4de4]
        mov     edx, dword ptr [g_dispatchSave628_004f4de0]
        not     edx
        and     dword ptr [eax], edx
    L_idep_skip2:
        mov     ecx, dword ptr [g_renderer2_var6_004f4dec]
        mov     eax, dword ptr [g_renderer2_var7_004f4de8]
        test    dword ptr [ecx], eax
        je      L_idep_skip3
        mov     eax, dword ptr [g_dispatchSave532_004f4dfc]
        mov     edx, dword ptr [g_dispatchSave533_004f4df8]
        not     edx
        and     dword ptr [eax], edx
    L_idep_skip3:
        mov     ecx, dword ptr [g_dispatchSave517_004f4df4]
        mov     eax, dword ptr [g_dispatchSave518_004f4df0]
        test    dword ptr [ecx], eax
        je      L_idep_skip4
        mov     eax, dword ptr [g_dispatchSave625_004f4e04]
        mov     edx, dword ptr [g_dispatchSave626_004f4e00]
        not     edx
        and     dword ptr [eax], edx
    L_idep_skip4:
        mov     esi, dword ptr [g_phaseThunkInst_004d50ac]
        mov     eax, dword ptr [g_fightTableC2]
        mov     ecx, dword ptr [g_fightTableC0]
        mov     edx, dword ptr [g_fightTableC1]
        not     esi
        not     eax
        not     ecx
        not     edx
        mov     dword ptr [g_phaseThunkInst_004d50ac], esi
        mov     dword ptr [g_dispatchSave27_00543368], esi
        mov     dword ptr [g_fightTableC2], eax
        mov     dword ptr [g_fightTableC0], ecx
        mov     dword ptr [g_fightTableC1], edx
        mov     dword ptr [g_dispatchVar39_0054357c], eax
        mov     dword ptr [g_dispatchSave26_0054336c], ecx
        mov     dword ptr [g_dispatchSave25_00543370], edx
        pop     esi
        ret
    }
}
