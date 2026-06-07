/**
 * Auto-split from misc_matchesQQ.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

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
extern unsigned int g_armedReloadA;
extern unsigned int g_armedReloadB;
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

extern unsigned int g_renderer2_initVar;
extern u8 g_renderer2_buf3[];
extern u8 g_renderer2_buf2[];
extern u8 g_renderer2_buf1[];
extern unsigned int g_renderer2_state9;
extern unsigned int g_renderer2_var2;
extern int g_renderer2_present_rc;
extern int g_renderer2_active;
extern void R2_Init11(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
undefined4 PadEnumDeviceRebind(uint param_1,ushort *param_2)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  ushort *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 auStack_6c [4];
  int iStack_5c;
  undefined4 *puStack_48;
  
  if (((g_renderer2_active != 0) && ((byte)param_1 < 0x10)) && (param_2 != (ushort *)0x0)) {
    R2_Init11(param_1);
    uVar5 = param_1 & 0xff;
    piVar2 = (int *)(&g_renderer2_buf2)[uVar5];
    if ((piVar2 != (int *)0x0) &&
       (iVar3 = (*(MK4ComMethod *)(*piVar2 + 0x60))(piVar2), iVar3 == -0x7789fe3e)) {
      (*(MK4ComMethod *)(*(int *)(&g_renderer2_buf2)[uVar5] + 0x6c))((int *)(&g_renderer2_buf2)[uVar5]);
    }
    if ((g_renderer2_state9 != (int *)0x0) &&
       (iVar3 = (*(MK4ComMethod *)(*g_renderer2_state9 + 0x60))(g_renderer2_state9), iVar3 == -0x7789fe3e)) {
      (*(MK4ComMethod *)(*g_renderer2_state9 + 0x6c))(g_renderer2_state9);
    }
    puVar6 = auStack_6c;
    for (iVar3 = 0x1b; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar6 = 0;
      puVar6 = puVar6 + 1;
    }
    auStack_6c[0] = 0x6c;
    if (g_renderer2_state9 != (int *)0x0) {
      g_comret_0058c7dc = (*(MK4ComMethod *)(*g_renderer2_state9 + 100))(g_renderer2_state9,0,auStack_6c,0,0);
    }
    if (puStack_48 != (undefined4 *)0x0) {
      param_1 = 0x100;
      do {
        if (g_renderer2_initVar == 0) {
          puVar4 = param_2;
          puVar6 = puStack_48;
          for (iVar3 = 0x80; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar6 = *(undefined4 *)puVar4;
            puVar4 = puVar4 + 2;
            puVar6 = puVar6 + 1;
          }
        }
        else {
          iVar3 = 0x100;
          puVar4 = param_2;
          do {
            uVar1 = *puVar4;
            puVar4 = puVar4 + 1;
            iVar3 = iVar3 + -1;
            *(ushort *)((int)puStack_48 + (-2 - (int)param_2) + (int)puVar4) =
                 (uVar1 & 0xffe0) << 1 | uVar1 & 0x3f;
          } while (iVar3 != 0);
        }
        param_2 = param_2 + 0x100;
        puStack_48 = (undefined4 *)((int)puStack_48 + iStack_5c);
        param_1 = param_1 + -1;
      } while (param_1 != 0);
    }
    if (g_renderer2_state9 != (int *)0x0) {
      g_comret_0058c7dc = (*(MK4ComMethod *)(*g_renderer2_state9 + 0x80))(g_renderer2_state9,0);
    }
    if ((g_renderer2_var2 != 0) && (piVar2 = (int *)(&g_renderer2_buf3)[uVar5], piVar2 != (int *)0x0)) {
      g_comret_0058c7dc = (*(MK4ComMethod *)(*piVar2 + 0x14))(piVar2,g_renderer2_var2);
    }
    if ((((&g_renderer2_buf2)[uVar5] != 0) && ((&g_renderer2_buf3)[uVar5] != 0)) &&
       ((&g_renderer2_buf1)[uVar5] != 0)) {
      return 1;
    }
  }
  return 0;
}
#else
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
#endif
