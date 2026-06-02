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

/* @addr 0x0042ee40 (370b game) - boot-init: clears slot 0x52ab10, seeds
 *   bookkeeping globals, and zero-fills a counted region.
 *   Calls BootInitGuardedCallChain first. On no-error: reads the
 *   slot index from g_load_0052ab10 into g_currentNodeIdx, calls
 *   ZeroThreeFields_00404ed0 then writes (0, 0, 0xfffc0000) into
 *   [slot+0x54/+0x58/+0x5c]. Mirrors with g_particleEmitterNode slot getting
 *   (0, 0, 0x10000, 0). Then sets globals: 0x535de0=0, 0x541dd8=0,
 *   0x53a170=2, and 0x53a1ac=0xa (loop counter).
 *
 *   Inner loop: while 0x53a1ac >= 0, zeroes [0x542044*4] (advancing
 *   index each iteration) - counted zero-fill. After: stashes 0xa into
 *   0x52aabc.
 *
 *   Calls CopyGlobal; on no-error pushes 2 onto
 *   TableWalkBoundedCmp, sets byte 0x54371c=1, sets 0x54206c
 *   from g_dlNalt1, calls DownloadPlayerChar; on no-error sets
 *   0x542070=1 and 0x54206c from g_dlNalt2, calls DownloadPlayerChar
 *   again; on no-error sets 0x542044 = &g_installCountdownArr2_0050b214>>2 (packed_ptr),
 *   clears 0x54371c, calls LoadGeoAsset_Default; on no-error reloads
 *   &g_installCountdownArr2_0050b214>>2 and calls LoadGeoAsset_Default a second time.
 */
extern unsigned int g_installCountdownArr2_0050b214;
extern unsigned int g_phaseThunkVar2_0052aabc;
extern unsigned int g_load_0052ab10;
extern unsigned int g_phaseThunkVar4_00535de0;
extern unsigned int g_particleEmitterNode;
extern s32 g_dlNalt1;
extern s32 g_dlNalt2;
extern unsigned int g_dispatchSave96_0053a170;
extern unsigned int g_eventMusicVar;
extern unsigned int g_dispatchVar7_00541fbc;
extern u8 g_dlEnabledFlag;
extern void BootInitGuardedCallChain(void);
extern void CopyGlobal(void);
extern void DownloadPlayerChar(void);
extern void TableWalkBoundedCmp(void);
extern void ZeroThreeFields_00404ed0(void);

__declspec(naked) void BootInitClearSlotSeed(void) {
    __asm {
        push    ebx
        push    esi
        push    edi
        call    BootInitGuardedCallChain
        mov     eax, dword ptr [g_framePauseFlag]
        xor     ebx, ebx
        cmp     eax, ebx
        jne     L_bic_done
        mov     eax, dword ptr [g_load_0052ab10]
        mov     dword ptr [g_currentNodeIdx], eax
        lea     esi, [eax*4]
        call    ZeroThreeFields_00404ed0
        mov     dword ptr [esi + 0x54], ebx
        mov     dword ptr [esi + 0x58], ebx
        mov     dword ptr [esi + 0x5c], 0xfffc0000
        mov     eax, dword ptr [g_particleEmitterNode]
        mov     dword ptr [g_eventQueueEnd], eax
        shl     eax, 2
        mov     dword ptr [eax + 0x54], ebx
        mov     dword ptr [eax + 0x58], ebx
        mov     dword ptr [eax + 0x5c], 0x10000
        mov     dword ptr [eax + 0x34], ebx
        mov     eax, dword ptr [g_dispatchVar7_00541fbc]
        mov     dword ptr [g_phaseThunkVar4_00535de0], ebx
        mov     dword ptr [g_currentNodeIdx], eax
        mov     eax, 0xa
        mov     dword ptr [g_eventMusicVar], ebx
        mov     dword ptr [g_dispatchSave96_0053a170], 2
        mov     dword ptr [g_walkCallback], ebx
        mov     dword ptr [g_xformLoopCounter], eax
    L_bic_zeroLoop:
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [edx*4], ecx
        mov     edx, dword ptr [g_currentNodeIdx]
        mov     ecx, dword ptr [g_xformLoopCounter]
        inc     edx
        dec     ecx
        mov     dword ptr [g_currentNodeIdx], edx
        mov     dword ptr [g_xformLoopCounter], ecx
        jns     short L_bic_zeroLoop
        mov     dword ptr [g_phaseThunkVar2_0052aabc], eax
        mov     dword ptr [g_walkCallback], ebx
        call    CopyGlobal
        cmp     dword ptr [g_framePauseFlag], ebx
        jne     L_bic_done
        mov     esi, dword ptr [g_walkCallback]
        mov     edi, dword ptr [g_eventQueueCurrent]
        push    2
        call    TableWalkBoundedCmp
        mov     eax, dword ptr [g_dlNalt1]
        add     esp, 4
        mov     byte ptr [g_dlEnabledFlag], 1
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_eventQueueCurrent], ebx
        call    DownloadPlayerChar
        cmp     dword ptr [g_framePauseFlag], ebx
        jne     short L_bic_done
        mov     ecx, dword ptr [g_dlNalt2]
        mov     dword ptr [g_eventQueueCurrent], 1
        mov     dword ptr [g_walkCallback], ecx
        call    DownloadPlayerChar
        cmp     dword ptr [g_framePauseFlag], ebx
        jne     short L_bic_done
        mov     edx, offset g_installCountdownArr2_0050b214
        mov     byte ptr [g_dlEnabledFlag], bl
        shr     edx, 2
        mov     dword ptr [g_walkCallback], esi
        mov     dword ptr [g_eventQueueCurrent], edi
        mov     dword ptr [g_currentNodeIdx], edx
        call    LoadGeoAsset_Default
        cmp     dword ptr [g_framePauseFlag], ebx
        jne     short L_bic_done
        mov     eax, offset g_installCountdownArr2_0050b214
        shr     eax, 2
        mov     dword ptr [g_currentNodeIdx], eax
        call    LoadGeoAsset_Default
    L_bic_done:
        pop     edi
        pop     esi
        pop     ebx
        ret
    }
}
