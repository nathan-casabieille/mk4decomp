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
extern void WalkCbSubMul10_00431d50(void);
extern void Mul10Tail(unsigned int a, unsigned int b);
extern void BootMod6487eClampAndChainMul10(void);
extern void SpawnListBatchLoader_00477710(void);
extern void MStackPush2TableNot(void);
extern void GuardedChainCmpDualBitXor(void);
extern void ScaledLoadDecJmp_00429710(void);
extern void ScaledStoreCurDirtyClear_004296f0(void);
extern void MStackBitmaskIncMod_00492450(void);
extern void MStackBitmaskUpdate_00492510(void);
extern void Push1eCallTestDirtyLoop_004923b0(void);
extern void MStackLoopFieldInit_00492280(void);
extern void TaggedSceneDispatch(void);
extern void CallPauseDirty4StackPushFn_004839d0(void);
extern void CallPauseDirty1JmpDirty4StackPush_00483a80(void);
extern void Cmp2CallDirtyCall(void);
extern void QuadBlockArgInstallChain(void);
extern void InstallSelfChainSet84_80CallW_004363f0(void);
extern void Wrapper_00436490(void);
extern void MoveFsmCluster_004364a0(void);
extern void CallPauseTestByteJmpCalls(void);
extern void InstallSelfFullPath(void);
extern void InstallSelfCountdownChain_0047a950(void);
extern void CopyJmp_0048ef90(void);
extern void DualTestDirtyToggle_004282c0(void);
extern void TripleVecAccCallStore(void);
extern void Thunk_004bd5c0(void);
extern void AllocSlotPushTripleGlobals(void);
extern void MStackPop4Rewrite(void);
extern void Push70CallScaleArith(void);
extern void StreamChainStringInstall(void);
extern void MStackFrameCdeclDouble(void);
extern void ChainTableWalkStore_004917e0(void);
extern void Push16Call(void);
extern void DispatcherComplex260_00407030(void);
extern void ScaledLoadCmpStoreXfm_0048f2a0(void);
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

/* @addr 0x004ad5f0 (169b engine.install) - gamma/palette ramp computation (256 entries).
 *   if ([0x58c7e0] == 0): ret (no init).
 *   ebx = arg & 0x7f (clamped abs to 100).
 *   Zero-fill 10 dwords on stack ([esp+0xc..]); [esp+0xc] = 0x28 (cb); [esp+0x28] = ebx*5.
 *   if ([0x58c7b8] != 0): COM-style vtable call ([0x58c7b8])->vtable[0x10](self, &caps).
 *     Store result to [0x58c7dc].
 *   ebx clamp at 60. Loop 256 entries (ecx=0..0xff): byte = ((ebx*esi*0x51eb851f) sar 36) signed-fixup,
 *     clamp to 0xff, store at [ecx + 0x544158]. esi += ebx; ecx++.
 */
extern unsigned int g_palette;
extern unsigned int g_comptr_0058c7b8;
extern int g_renderer2_present_rc;
extern int g_renderer2_active;

__declspec(naked) void PaletteRampInit_004ad5f0(void) {
    __asm {
        mov     eax, dword ptr [g_renderer2_active]
        sub     esp, 0x28
        test    eax, eax
        _emit   0fh
        _emit   84h
        _emit   95h
        _emit   00h
        _emit   00h
        _emit   00h
        push    edi
        push    esi
        push    ebx
        mov     ebx, [esp + 0x38]
        mov     eax, ebx
        cdq
        xor     eax, edx
        sub     eax, edx
        cmp     eax, 0x64
        _emit   7eh
        _emit   05h
        mov     ebx, 0x64
        mov     ecx, 0x0a
        xor     eax, eax
        lea     edi, [esp + 0x0c]
        rep stosd
        lea     eax, [ebx + ebx*4]
        mov     dword ptr [esp + 0x0c], 0x28
        mov     [esp + 0x28], eax
        mov     eax, dword ptr [g_comptr_0058c7b8]
        test    eax, eax
        mov     dword ptr [esp + 0x10], 0x20
        _emit   74h
        _emit   10h
        mov     ecx, [eax]
        lea     edx, [esp + 0x0c]
        push    edx
        push    eax
        call    dword ptr [ecx + 0x10]
        mov     dword ptr [g_renderer2_present_rc], eax
        cmp     ebx, 0x3c
        _emit   7eh
        _emit   05h
        mov     ebx, 0x3c
        xor     ecx, ecx
        xor     esi, esi
        mov     eax, 0x51eb851f
        imul    esi
        sar     edx, 4
        mov     eax, edx
        shr     eax, 0x1f
        add     edx, eax
        cmp     edx, 0xff
        _emit   7ch
        _emit   05h
        mov     edx, 0xff
        mov     byte ptr [ecx + g_palette], dl
        inc     ecx
        add     esi, ebx
        cmp     ecx, 0x100
        _emit   7ch
        _emit   0d1h
        pop     ebx
        pop     esi
        pop     edi
        add     esp, 0x28
        ret
    }
}
