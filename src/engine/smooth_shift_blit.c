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
extern void GuardedDispatch_InstallSelfDualEsi(void);
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

extern u32 g_gsmActiveFlag;
extern u32 g_titleStateE;
extern unsigned int g_dispatchSave1324;
extern unsigned int g_dispatchSave1325;
extern unsigned int g_dispatchSave1326;
extern void DrawScene(void);
extern void Loop16Init(void);
extern void Helper_TitleAudioReset(void);
extern void SceneRecordLookupRandInit(void);
extern void DSound_GetContext(void);
extern void ECM_OpenTrack(void);
extern void TestPushPushCall(void);
extern void Input_AnyConfirmPressed(void);
/* Renderer_GetMode declared in game/tick.h as int */
extern void AnimNodeKindDispatch(void);
extern void SmoothShiftBlit(void);
extern void JumpTable5Way(void);
extern void PresentFrame(void);
extern void PumpMessages(void);
extern void CallZero(void);

/* @addr 0x004be250 (354b engine.scenegraph) - cdecl wrapper that calls
 *   DrawScene + Loop16Init + Audio_TimerTeardown + SetState1, then if
 *   g_gsmActiveFlag == 0 returns 0; else looks up an entry via
 *   SceneRecordLookupRandInit keyed by [esp+0x24]. While that pointer is non-zero
 *   plays an ECM track and pumps the message loop: probe inputs via
 *   Input_AnyConfirmPressed, advance through TestPushPushCall
 *   transitions, and on key-1 input dispatch a 5-way JumpTable_004b41c0
 *   based action. On finish-condition (ebx != 0) restores state and
 *   returns either 0 or 0xa (bit-pattern via `neg/sbb/and 0xa`).
 */
extern void Audio_TimerTeardown(void);

__declspec(naked) void SceneFrameStepWithInputs(void) {
    __asm {
        sub     esp, 0x10
        push    ebx
        push    ebp
        push    esi
        xor     ebp, ebp
        push    edi
        mov     dword ptr [esp + 0x1c], ebp
        mov     dword ptr [esp + 0x18], ebp
        mov     dword ptr [esp + 0x14], ebp
        mov     dword ptr [esp + 0x10], ebp
        xor     ebx, ebx
        call    DrawScene
        call    Loop16Init
        call    Audio_TimerTeardown
        call    Helper_TitleAudioReset
        cmp     dword ptr [g_gsmActiveFlag], ebp
        je      short L_sfs_haveScene
        xor     eax, eax
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 0x10
        ret
    L_sfs_haveScene:
        mov     esi, dword ptr [esp + 0x24]
    L_sfs_lookupTop:
        push    esi
        call    SceneRecordLookupRandInit
        mov     edi, eax
        add     esp, 4
        cmp     edi, ebp
        je      L_sfs_zeroExit
    L_sfs_innerHead:
        cmp     dword ptr [g_titleStateE], ebp
        je      short L_sfs_zeroCtx
        call    DSound_GetContext
        jmp     short L_sfs_haveCtx
    L_sfs_zeroCtx:
        xor     eax, eax
    L_sfs_haveCtx:
        shl     esi, 4
        mov     ecx, dword ptr [esi + 0x4f78cc]
        push    ecx
        push    0x64
        push    eax
        push    edi
        call    ECM_OpenTrack
        add     esp, 0x10
        call    TestPushPushCall
        mov     edi, eax
        cmp     edi, ebp
        je      L_sfs_innerDone
    L_sfs_innerLoop:
        mov     edx, dword ptr [esp + 0x28]
        push    edx
        call    Input_AnyConfirmPressed
        mov     ebx, eax
        add     esp, 4
        cmp     ebx, ebp
        jne     short L_sfs_innerDone
        cmp     edi, dword ptr [esi + 0x4f78d0]
        jg      short L_sfs_innerDone
        call    Renderer_GetMode
        cmp     eax, 4
        jne     short L_sfs_notMode4
        cmp     dword ptr [g_mode4PauseGate], ebp
        je      short L_sfs_innerDone
    L_sfs_notMode4:
        cmp     edi, ebp
        jl      short L_sfs_skipCallChain
        lea     eax, [esp + 0x10]
        lea     ecx, [esp + 0x14]
        push    eax
        lea     edx, [esp + 0x1c]
        push    ecx
        lea     eax, [esp + 0x24]
        push    edx
        push    eax
        push    1
        call    AnimNodeKindDispatch
        add     esp, 0x14
        test    eax, eax
        je      short L_sfs_finishPresent
        mov     ecx, dword ptr [esp + 0x10]
        mov     edx, dword ptr [esp + 0x14]
        mov     eax, dword ptr [esp + 0x18]
        push    ecx
        mov     ecx, dword ptr [esp + 0x20]
        push    edx
        push    eax
        push    ecx
        call    SmoothShiftBlit
        add     esp, 0x10
        call    JumpTable5Way
        call    PresentFrame
    L_sfs_finishPresent:
        call    PumpMessages
    L_sfs_skipCallChain:
        call    TestPushPushCall
        mov     edi, eax
        cmp     edi, ebp
        jne     L_sfs_innerLoop
    L_sfs_innerDone:
        call    CallZero
        cmp     ebx, ebp
        jne     short L_sfs_finalReturn
        mov     esi, dword ptr [esi + 0x4f78d4]
        cmp     esi, -1
        je      short L_sfs_finalReturn
        push    esi
        call    SceneRecordLookupRandInit
        mov     edi, eax
        add     esp, 4
        cmp     edi, ebp
        jne     L_sfs_innerHead
    L_sfs_zeroExit:
        xor     eax, eax
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 0x10
        ret
    L_sfs_finalReturn:
        call    Helper_TitleAudioReset
        mov     eax, ebx
        pop     edi
        neg     eax
        sbb     eax, eax
        pop     esi
        pop     ebp
        and     eax, 0xa
        pop     ebx
        add     esp, 0x10
        ret
    }
}
