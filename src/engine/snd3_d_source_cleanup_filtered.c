/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
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

/* @addr 0x004c3be0 (286b engine.render) - twin of Snd3DSourceCleanup with extra flag-check.
 *   Same structure but adds `shl ecx,2; cmp [ecx+g_audioChannelTable], 0; je;
 *   test [ecx+g_flags_00f8fade], 1; je` before the vtbl calls (extra "in-use" filter).
 */
extern u8 g_audioChannelTable[];
extern unsigned int g_flags_00f8fade;
extern unsigned int g_flags_00f8fadf;
extern u16 g_audioChannelQueue[];

__declspec(naked) void Snd3DSourceCleanupFiltered(void) {
    __asm {
        mov     ax, word ptr [esp + 4]
        push    ebx
        push    ebp
        push    esi
        cmp     ax, 0x898
        push    edi
        jb      L_s3df_iter
        mov     al, byte ptr [esp + 0x18]
        cmp     al, 0x10
        jae     L_s3df_done
        movsx   esi, al
        shl     esi, 2
        mov     ax, word ptr [esi + g_audioChannelQueue]
        cmp     ax, 0xffff
        jz      L_s3df_done
        movsx   eax, ax
        xor     ebx, ebx
        lea     ecx, [eax*8]
        sub     ecx, eax
        shl     ecx, 2
        cmp     dword ptr [ecx + g_audioChannelTable], ebx
        jz      L_s3df_done
        test    byte ptr [ecx + g_flags_00f8fade], 1
        jz      L_s3df_done
        movsx   edx, word ptr [esi + g_audioChannelQueue + 2]
        lea     ecx, [eax*8]
        sub     ecx, eax
        add     ecx, edx
        mov     eax, dword ptr [ecx*4 + g_audioChannelTable]
        push    eax
        mov     ecx, [eax]
        call    dword ptr [ecx + 0x48]
        movsx   eax, word ptr [esi + g_audioChannelQueue]
        mov     edx, eax
        push    ebx
        shl     edx, 3
        sub     edx, eax
        movsx   eax, word ptr [esi + g_audioChannelQueue + 2]
        add     edx, eax
        mov     eax, dword ptr [edx*4 + g_audioChannelTable]
        push    eax
        mov     ecx, [eax]
        call    dword ptr [ecx + 0x34]
        movsx   eax, word ptr [esi + g_audioChannelQueue]
        mov     edx, eax
        shl     edx, 3
        sub     edx, eax
        movsx   eax, word ptr [esi + g_audioChannelQueue + 2]
        mov     word ptr [esi + g_audioChannelQueue], 0xffff
        mov     byte ptr [eax + edx*4 + g_flags_00f8fadf], bl
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
    L_s3df_iter:
        movsx   eax, ax
        mov     ebp, eax
        xor     ebx, ebx
        shl     ebp, 3
        sub     ebp, eax
        shl     ebp, 2
        mov     eax, dword ptr [ebp + g_audioChannelTable]
        lea     edi, [ebp + g_audioChannelTable]
        cmp     eax, ebx
        jz      short L_s3df_done
        test    byte ptr [ebp + g_flags_00f8fade], 1
        jz      short L_s3df_done
        xor     esi, esi
    L_s3df_loop:
        mov     byte ptr [esi + ebp + g_flags_00f8fadf], bl
        mov     eax, [edi]
        push    eax
        mov     ecx, [eax]
        call    dword ptr [ecx + 0x48]
        mov     eax, [edi]
        push    ebx
        push    eax
        mov     edx, [eax]
        call    dword ptr [edx + 0x34]
        inc     esi
        add     edi, 4
        cmp     esi, 4
        jl      short L_s3df_loop
    L_s3df_done:
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        ret
    }
}
