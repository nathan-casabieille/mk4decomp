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

extern void Menu_FindNextSelectable(void);
extern void Menu_FindPrevSelectable(void);
extern void DrawMenu(void *menu_items, s32 selection);
extern void Menu_PollNavInput(void);
extern unsigned int g_gsmSub18Base_004f5090;
extern unsigned int g_dispatchSave516_004f5094;
extern unsigned char g_byte_00ab42d4;
extern unsigned int g_dispatchSave1473_00ab41a0;
extern unsigned int g_dispatchSave1494_00ab4364;

/*
 * Helper_GSM_Sub18 - 255b menu navigation dispatcher.
 *   al = g_byte_00ab42d4. If bit 0 not set: set it, push (0, &table); TableSearchAsc; store eax.
 *   Else: load saved g_dispatchSave1473_00ab41a0. Switch on g_dispatchSave1494_00ab4364 = 0/2/0x45/default.
 *     If 0 → set 0x00ab4364=2 + DrawMenu epilogue.
 *     If 2 → call Menu_PollNavInput(1); check bit 0x8000; bl&1: TableSearchDesc; check esi;
 *       bl&2: TableSearchAsc again; bl&0x10: load word from g_dispatchSave516_004f5094[eax*8] → g_dispatchSave1494_00ab4364;
 *       bl&0x20: g_dispatchSave1494_00ab4364=0x45.
 *     If 0x45 → set 0x00ab4364=0.
 *     Final epilogue: push (eax, &g_gsmSub18Base_004f5090); DrawMenu; pop ret.
 */
__declspec(naked) void Helper_GSM_Sub18(void)
{
    __asm
    {
        mov     al, byte ptr [g_byte_00ab42d4]
        push    ebx
        test    al, 1
        push    esi
        jne     short L_skipSet
        mov     bl, al
        push    offset g_gsmSub18Base_004f5090
        or      bl, 1
        push    0
        mov     byte ptr [g_byte_00ab42d4], bl
        call    Menu_FindNextSelectable
        add     esp, 8
        mov     dword ptr [g_dispatchSave1473_00ab41a0], eax
        jmp     short L_afterFirst
    L_skipSet:
        mov     eax, dword ptr [g_dispatchSave1473_00ab41a0]
    L_afterFirst:
        mov     ecx, dword ptr [g_dispatchSave1494_00ab4364]
        sub     ecx, 0
        je      L_case0
        sub     ecx, 2
        je      short L_case2
        sub     ecx, 0x43
        jne     L_drawMenu
        mov     dword ptr [g_dispatchSave1494_00ab4364], 0
        jmp     L_drawMenu
    L_case2:
        push    1
        call    Menu_PollNavInput
        mov     ebx, eax
        add     esp, 4
        mov     esi, ebx
        and     esi, 0x8000
        jne     short L_skipDesc
        test    bl, 1
        je      short L_skipDesc
        mov     eax, dword ptr [g_dispatchSave1473_00ab41a0]
        push    offset g_gsmSub18Base_004f5090
        push    eax
        call    Menu_FindPrevSelectable
        add     esp, 8
        mov     dword ptr [g_dispatchSave1473_00ab41a0], eax
        jmp     short L_checkBit2
    L_skipDesc:
        mov     eax, dword ptr [g_dispatchSave1473_00ab41a0]
    L_checkBit2:
        test    esi, esi
        jne     short L_drawMenu
        test    bl, 2
        je      short L_checkBit4
        push    offset g_gsmSub18Base_004f5090
        push    eax
        call    Menu_FindNextSelectable
        add     esp, 8
        mov     dword ptr [g_dispatchSave1473_00ab41a0], eax
    L_checkBit4:
        test    esi, esi
        jne     short L_drawMenu
        test    bl, 0x10
        je      short L_checkBit5
        movsx   ecx, word ptr [eax*8 + g_dispatchSave516_004f5094]
        mov     dword ptr [g_dispatchSave1494_00ab4364], ecx
    L_checkBit5:
        test    esi, esi
        jne     short L_drawMenu
        test    bl, 0x20
        je      short L_drawMenu
        mov     dword ptr [g_dispatchSave1494_00ab4364], 0x45
        jmp     short L_drawMenu
    L_case0:
        mov     dword ptr [g_dispatchSave1494_00ab4364], 2
    L_drawMenu:
        push    eax
        push    offset g_gsmSub18Base_004f5090
        call    DrawMenu
        mov     eax, dword ptr [g_dispatchSave1494_00ab4364]
        add     esp, 8
        pop     esi
        pop     ebx
        ret
    }
}
