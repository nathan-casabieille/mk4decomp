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

extern void Menu_FindNextSelectable(void);
extern void Menu_FindPrevSelectable(void);
extern void DrawMenu(void *menu_items, s32 selection);
extern void Menu_PollNavInput(void);
extern unsigned int g_gsmSub18Base;
extern unsigned int g_dispatchSave516;
extern unsigned char g_byte_00ab42d4;
extern unsigned int g_dispatchSave1473;
extern unsigned int g_dispatchSave1494;

/*
 * Menu_HelpScreen - 255b menu navigation dispatcher.
 *   al = g_byte_00ab42d4. If bit 0 not set: set it, push (0, &table); TableSearchAsc; store eax.
 *   Else: load saved g_dispatchSave1473. Switch on g_dispatchSave1494 = 0/2/0x45/default.
 *     If 0 → set 0x00ab4364=2 + DrawMenu epilogue.
 *     If 2 → call Menu_PollNavInput(1); check bit 0x8000; bl&1: TableSearchDesc; check esi;
 *       bl&2: TableSearchAsc again; bl&0x10: load word from g_dispatchSave516[eax*8] → g_dispatchSave1494;
 *       bl&0x20: g_dispatchSave1494=0x45.
 *     If 0x45 → set 0x00ab4364=0.
 *     Final epilogue: push (eax, &g_gsmSub18Base); DrawMenu; pop ret.
 */
__declspec(naked) void Menu_HelpScreen(void)
{
    __asm
    {
        mov     al, byte ptr [g_byte_00ab42d4]
        push    ebx
        test    al, 1
        push    esi
        jne     short L_skipSet
        mov     bl, al
        push    offset g_gsmSub18Base
        or      bl, 1
        push    0
        mov     byte ptr [g_byte_00ab42d4], bl
        call    Menu_FindNextSelectable
        add     esp, 8
        mov     dword ptr [g_dispatchSave1473], eax
        jmp     short L_afterFirst
    L_skipSet:
        mov     eax, dword ptr [g_dispatchSave1473]
    L_afterFirst:
        mov     ecx, dword ptr [g_dispatchSave1494]
        sub     ecx, 0
        je      L_case0
        sub     ecx, 2
        je      short L_case2
        sub     ecx, 0x43
        jne     L_drawMenu
        mov     dword ptr [g_dispatchSave1494], 0
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
        mov     eax, dword ptr [g_dispatchSave1473]
        push    offset g_gsmSub18Base
        push    eax
        call    Menu_FindPrevSelectable
        add     esp, 8
        mov     dword ptr [g_dispatchSave1473], eax
        jmp     short L_checkBit2
    L_skipDesc:
        mov     eax, dword ptr [g_dispatchSave1473]
    L_checkBit2:
        test    esi, esi
        jne     short L_drawMenu
        test    bl, 2
        je      short L_checkBit4
        push    offset g_gsmSub18Base
        push    eax
        call    Menu_FindNextSelectable
        add     esp, 8
        mov     dword ptr [g_dispatchSave1473], eax
    L_checkBit4:
        test    esi, esi
        jne     short L_drawMenu
        test    bl, 0x10
        je      short L_checkBit5
        movsx   ecx, word ptr [eax*8 + g_dispatchSave516]
        mov     dword ptr [g_dispatchSave1494], ecx
    L_checkBit5:
        test    esi, esi
        jne     short L_drawMenu
        test    bl, 0x20
        je      short L_drawMenu
        mov     dword ptr [g_dispatchSave1494], 0x45
        jmp     short L_drawMenu
    L_case0:
        mov     dword ptr [g_dispatchSave1494], 2
    L_drawMenu:
        push    eax
        push    offset g_gsmSub18Base
        call    DrawMenu
        mov     eax, dword ptr [g_dispatchSave1494]
        add     esp, 8
        pop     esi
        pop     ebx
        ret
    }
}
