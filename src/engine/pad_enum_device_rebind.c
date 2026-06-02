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
extern void CopyJmp_0048ef90(void);
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

extern unsigned int g_renderer2_initVar;
extern u8 g_renderer2_buf3[];
extern u8 g_renderer2_buf2[];
extern u8 g_renderer2_buf1[];
extern unsigned int g_renderer2_state9;
extern unsigned int g_renderer2_var2;
extern int g_renderer2_present_rc;
extern int g_renderer2_active;
extern void R2_Init11(void);

__declspec(naked) void PadEnumDeviceRebind(void)
{
    __asm {
        mov      eax, dword ptr [g_renderer2_active]
        sub      esp, 0x6c
        test     eax, eax
        push     ebx
        push     ebp
        push     esi
        push     edi
        je       L_d9f8
        mov      ebx, dword ptr [esp + 0x80]
        cmp      bl, 0x10
        jae      L_d9f8
        mov      ebp, dword ptr [esp + 0x84]
        test     ebp, ebp
        je       L_d9f8
        push     ebx
        call     R2_Init11
        and      ebx, 0xff
        add      esp, 4
        shl      ebx, 2
        mov      esi, ebx
        mov      dword ptr [esp + 0x84], esi
        mov      eax, dword ptr [esi + g_renderer2_buf2]
        test     eax, eax
        je       L_d8c1
        mov      ecx, dword ptr [eax]
        push     eax
        call     dword ptr [ecx + 0x60]
        cmp      eax, 0x887601c2
        jne      L_d8c1
        mov      eax, dword ptr [esi + g_renderer2_buf2]
        push     eax
        mov      edx, dword ptr [eax]
        call     dword ptr [edx + 0x6c]
    L_d8c1:
        mov      edx, dword ptr [g_renderer2_state9]
        test     edx, edx
        je       L_d8e9
        mov      eax, dword ptr [edx]
        push     edx
        call     dword ptr [eax + 0x60]
        cmp      eax, 0x887601c2
        jne      L_d8e3
        mov      eax, dword ptr [g_renderer2_state9]
        push     eax
        mov      ecx, dword ptr [eax]
        call     dword ptr [ecx + 0x6c]
    L_d8e3:
        mov      edx, dword ptr [g_renderer2_state9]
    L_d8e9:
        mov      ecx, 0x1b
        xor      eax, eax
        lea      edi, [esp + 0x10]
        rep stosd
        test     edx, edx
        mov      dword ptr [esp + 0x10], 0x6c
        je       L_d91e
        mov      eax, dword ptr [edx]
        push     0
        lea      ecx, [esp + 0x14]
        push     0
        push     ecx
        push     0
        push     edx
        call     dword ptr [eax + 0x64]
        mov      edx, dword ptr [g_renderer2_state9]
        mov      dword ptr [g_renderer2_present_rc], eax
    L_d91e:
        mov      ebx, dword ptr [esp + 0x34]
        test     ebx, ebx
        je       L_d999
        mov      dword ptr [esp + 0x80], 0x100
    L_d931:
        mov      eax, dword ptr [g_renderer2_initVar]
        test     eax, eax
        je       L_d964
        mov      edx, ebx
        mov      ecx, ebp
        sub      edx, ebp
        mov      esi, 0x100
    L_d945:
        mov      ax, word ptr [ecx]
        add      ecx, 2
        mov      edi, eax
        and      eax, 0x3f
        and      edi, 0xffe0
        shl      edi, 1
        or       edi, eax
        dec      esi
        mov      word ptr [edx + ecx - 2], di
        jne      L_d945
        jmp      L_d96f
    L_d964:
        mov      ecx, 0x80
        mov      esi, ebp
        mov      edi, ebx
        rep movsd
    L_d96f:
        mov      ecx, dword ptr [esp + 0x20]
        mov      eax, dword ptr [esp + 0x80]
        add      ebp, 0x200
        add      ebx, ecx
        dec      eax
        mov      dword ptr [esp + 0x80], eax
        jne      L_d931
        mov      edx, dword ptr [g_renderer2_state9]
        mov      esi, dword ptr [esp + 0x84]
    L_d999:
        test     edx, edx
        je       L_d9ad
        mov      eax, dword ptr [edx]
        push     0
        push     edx
        call     dword ptr [eax + 0x80]
        mov      dword ptr [g_renderer2_present_rc], eax
    L_d9ad:
        mov      ecx, dword ptr [g_renderer2_var2]
        test     ecx, ecx
        je       L_d9cd
        mov      eax, dword ptr [esi + g_renderer2_buf3]
        test     eax, eax
        je       L_d9cd
        mov      edx, dword ptr [eax]
        push     ecx
        push     eax
        call     dword ptr [edx + 0x14]
        mov      dword ptr [g_renderer2_present_rc], eax
    L_d9cd:
        mov      eax, dword ptr [esi + g_renderer2_buf2]
        test     eax, eax
        je       L_d9f8
        mov      eax, dword ptr [esi + g_renderer2_buf3]
        test     eax, eax
        je       L_d9f8
        mov      eax, dword ptr [esi + g_renderer2_buf1]
        test     eax, eax
        je       L_d9f8
        mov      eax, 1
        pop      edi
        pop      esi
        pop      ebp
        pop      ebx
        add      esp, 0x6c
        ret
    L_d9f8:
        pop      edi
        pop      esi
        pop      ebp
        xor      eax, eax
        pop      ebx
        add      esp, 0x6c
        ret
    }
}
