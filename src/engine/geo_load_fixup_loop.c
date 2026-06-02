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

/*
 * @addr 0x004bd8e0 (127b engine.geo) - geometry-unload fixup loop, the
 * teardown counterpart of LoadGeoAsset_Textures: it frees the texture
 * slots a .geo asset claimed (g_texSlots[0x00ab4e00], g_table_004ab4e78,
 * g_texCount) before Mem_Free'ing the buffer.
 *
 *   mov ecx,[eax+4]; lea ecx,[ecx+eax+4]
 * is the same relative-offset-from-the-field-at-+4 fixup that geo_block
 * (include/engine/geo.h) and the texture-chunk reach in
 * LoadGeoAsset_Textures use - here it lands on the strip/texture index
 * word table. `mov dx,[eax+6]` then reads the node[0] header's u16 at
 * +6 (the same g_texCount index used by the loader).
 */
extern u16 g_texSlots[];
extern u32 g_curTexSlot;
extern unsigned int g_table_004ab4e78;
extern u32 g_texCount[];
extern void Helper_GeoLoadPost(void);
extern void Mem_Free_004b5b10(void);

__declspec(naked) void GeoLoadFixupLoop_004bd8e0(void) {
    __asm {
        push    esi
        push    edi
        mov     edi, dword ptr [g_scaledInit_00542044]
        xor     esi, esi
        mov     eax, dword ptr [edi*4 + 4]
        cmp     eax, esi
        je      done
        mov     ecx, dword ptr [eax + 4]
        lea     ecx, [ecx + eax + 4]
        xor     eax, eax
        mov     ax, word ptr [ecx]
        add     ecx, 4
        cmp     eax, esi
        jle     skipInner
        mov     edx, eax
innerLoop:
        movsx   eax, word ptr [ecx]
        cmp     eax, -1
        je      skipStore
        mov     word ptr [eax*2 + g_texSlots], si
skipStore:
        add     ecx, 4
        dec     edx
        jne     innerLoop
skipInner:
        mov     eax, dword ptr [edi*4 + 0]
        xor     edx, edx
        xor     ecx, ecx
        mov     dx, word ptr [eax + 6]
        mov     dword ptr [edx*4 + g_table_004ab4e78], esi
        mov     cx, word ptr [eax + 6]
        mov     dword ptr [ecx*4 + g_texCount], esi
        mov     edx, dword ptr [edi*4 + 4]
        push    edx
        call    Mem_Free_004b5b10
        add     esp, 4
        mov     dword ptr [g_curTexSlot], esi
        call    Helper_GeoLoadPost
done:
        pop     edi
        pop     esi
        ret
    }
}
