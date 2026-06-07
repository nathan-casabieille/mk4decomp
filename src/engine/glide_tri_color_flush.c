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

extern unsigned int g_glideColorFlushByte;
extern f32 g_glideTable2[];
extern f32 g_glideTable1[];
extern f32 g_glideTable3[];
extern u32 g_glideD0;
extern int g_renderer1_active;
extern u8 g_glideE8;
extern int g_renderer1_busy;
extern int g_renderer1_surface;
extern unsigned int g_dispatchSave1632;
extern unsigned int g_dispatchSave1652;
extern unsigned int g_dispatchSave1653;

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void GlideTriColorFlush(byte param_1,byte param_2,undefined4 param_3,undefined4 param_4,uint param_5,
                 uint param_6,short param_7,undefined4 param_8,undefined4 param_9,uint param_10,
                 uint param_11,short param_12,undefined4 param_13,undefined4 param_14,uint param_15,
                 uint param_16,short param_17)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  if (g_renderer1_active == 0) {
    return;
  }
  if (g_renderer1_surface == 0) {
    return;
  }
  if (g_renderer1_busy != 0) {
    return;
  }
  if (0x10 < param_1) {
    param_1 = 0;
  }
  if (g_glideColorFlushByte != param_1) {
    (*g_dispatchSave1652)(0,(&g_glideCmdArgArr)[param_1],3,&g_glideD0);
    g_glideColorFlushByte = param_1;
  }
  bVar1 = g_glideE8;
  if (param_2 != g_glideE8) {
    bVar1 = param_2;
    if (param_2 == 0) {
      uVar5 = 4;
      uVar4 = 0;
      uVar3 = 4;
    }
    else if (param_2 == 0xff) {
      uVar5 = 4;
      uVar4 = 4;
      uVar3 = 4;
    }
    else {
      if ((g_glideE8 != 0) && (g_glideE8 != 0xff)) goto LAB_004b47ad;
      uVar5 = 0;
      uVar4 = 1;
      uVar3 = 5;
    }
    (*g_dispatchSave1632)(uVar3,uVar4,uVar5,0);
  }
LAB_004b47ad:
  g_glideE8 = bVar1;
  uStack_38 = param_4;
  uVar2 = (uint)param_7;
  uStack_98 = (&g_glideTable1)[param_2];
  uStack_3c = param_3;
  uStack_30 = (&g_glideTable3)[(int)uVar2 >> 10 & 0x1f];
  uStack_2c = (&g_glideTable3)[(int)uVar2 >> 5 & 0x1f];
  uStack_28 = (&g_glideTable3)[uVar2 & 0x1f];
  uStack_b4 = param_8;
  uStack_58 = 0x3f800000;
  uStack_94 = 0x3f800000;
  uStack_18 = (&g_glideTable1)[param_5 & 0xff];
  uStack_1c = 0x3f800000;
  uStack_14 = (&g_glideTable1)[param_6 & 0xff];
  uStack_b0 = param_9;
  uVar2 = (uint)param_12;
  uStack_a8 = (&g_glideTable3)[(int)uVar2 >> 10 & 0x1f];
  uStack_a4 = (&g_glideTable3)[(int)uVar2 >> 5 & 0x1f];
  uStack_a0 = (&g_glideTable3)[uVar2 & 0x1f];
  uStack_78 = param_13;
  uStack_90 = (&g_glideTable1)[param_10 & 0xff];
  uStack_8c = (&g_glideTable1)[param_11 & 0xff];
  uStack_74 = param_14;
  uVar2 = (uint)param_17;
  uStack_6c = (&g_glideTable3)[(int)uVar2 >> 10 & 0x1f];
  uStack_68 = (&g_glideTable3)[(int)uVar2 >> 5 & 0x1f];
  uStack_64 = (&g_glideTable3)[uVar2 & 0x1f];
  uStack_54 = (&g_glideTable1)[param_15 & 0xff];
  uStack_50 = (&g_glideTable1)[param_16 & 0xff];
  uStack_5c = uStack_98;
  uStack_20 = uStack_98;
  (*g_dispatchSave1653)(&uStack_3c,&uStack_b4,&uStack_78);
  return;
}
#else
__declspec(naked) void GlideTriColorFlush(void)
{
    __asm {
        mov      eax, dword ptr [g_renderer1_active]
        sub      esp, 0xb4
        test     eax, eax
        je       L_4992
        mov      eax, dword ptr [g_renderer1_surface]
        test     eax, eax
        je       L_4992
        mov      eax, dword ptr [g_renderer1_busy]
        test     eax, eax
        jne      L_4992
        push     ebx
        mov      bl, byte ptr [esp + 0xbc]
        cmp      bl, 0x10
        jbe      L_4733
        xor      bl, bl
        mov      byte ptr [esp + 0xbc], bl
    L_4733:
        cmp      byte ptr [g_glideColorFlushByte], bl
        je       L_4764
        mov      eax, dword ptr [esp + 0xbc]
        push     OFFSET g_glideD0
        and      eax, 0xff
        push     3
        mov      ecx, dword ptr [eax*4 + g_glideTable2]
        push     ecx
        push     0
        call     dword ptr [g_dispatchSave1652]
        mov      byte ptr [g_glideColorFlushByte], bl
    L_4764:
        mov      ebx, dword ptr [esp + 0xc0]
        mov      al, byte ptr [g_glideE8]
        cmp      bl, al
        je       L_47ad
        test     bl, bl
        jne      L_4782
        push     0
        push     4
        push     0
        push     4
        jmp      L_47a1
    L_4782:
        cmp      bl, 0xff
        jne      L_4791
        push     0
        push     4
        push     4
        push     4
        jmp      L_47a1
    L_4791:
        test     al, al
        je       L_4799
        cmp      al, 0xff
        jne      L_47a7
    L_4799:
        push     0
        push     0
        push     1
        push     5
    L_47a1:
        call     dword ptr [g_dispatchSave1632]
    L_47a7:
        mov      byte ptr [g_glideE8], bl
    L_47ad:
        mov      eax, dword ptr [esp + 0xc8]
        mov      edx, dword ptr [esp + 0xc4]
        mov      dword ptr [esp + 0x80], eax
        and      ebx, 0xff
        movsx    eax, word ptr [esp + 0xd4]
        fld      dword ptr [ebx*4 + g_glideTable1]
        fst      dword ptr [esp + 0x5c]
        fst      dword ptr [esp + 0x20]
        fstp     dword ptr [esp + 0x98]
        mov      ecx, eax
        mov      dword ptr [esp + 0x7c], edx
        sar      ecx, 0xa
        and      ecx, 0x1f
        mov      edx, eax
        sar      edx, 5
        fld      dword ptr [ecx*4 + g_glideTable3]
        and      edx, 0x1f
        and      eax, 0x1f
        fstp     dword ptr [esp + 0x88]
        fld      dword ptr [edx*4 + g_glideTable3]
        mov      ecx, dword ptr [esp + 0xd0]
        mov      edx, dword ptr [esp + 0xd8]
        fstp     dword ptr [esp + 0x8c]
        fld      dword ptr [eax*4 + g_glideTable3]
        mov      eax, dword ptr [esp + 0xcc]
        and      ecx, 0xff
        fstp     dword ptr [esp + 0x90]
        and      eax, 0xff
        mov      dword ptr [esp + 4], edx
        mov      dword ptr [esp + 0x60], 0x3f800000
        mov      dword ptr [esp + 0x24], 0x3f800000
        fld      dword ptr [eax*4 + g_glideTable1]
        mov      eax, dword ptr [esp + 0xdc]
        mov      dword ptr [esp + 0x9c], 0x3f800000
        fstp     dword ptr [esp + 0xa0]
        fld      dword ptr [ecx*4 + g_glideTable1]
        mov      dword ptr [esp + 8], eax
        movsx    eax, word ptr [esp + 0xe8]
        fstp     dword ptr [esp + 0xa4]
        mov      ecx, eax
        mov      edx, eax
        sar      ecx, 0xa
        and      ecx, 0x1f
        and      eax, 0x1f
        sar      edx, 5
        fld      dword ptr [ecx*4 + g_glideTable3]
        and      edx, 0x1f
        mov      ecx, dword ptr [esp + 0xe4]
        fstp     dword ptr [esp + 0x10]
        fld      dword ptr [edx*4 + g_glideTable3]
        mov      edx, dword ptr [esp + 0xec]
        and      ecx, 0xff
        fstp     dword ptr [esp + 0x14]
        fld      dword ptr [eax*4 + g_glideTable3]
        mov      eax, dword ptr [esp + 0xe0]
        mov      dword ptr [esp + 0x40], edx
        fstp     dword ptr [esp + 0x18]
        and      eax, 0xff
        fld      dword ptr [eax*4 + g_glideTable1]
        mov      eax, dword ptr [esp + 0xf0]
        fstp     dword ptr [esp + 0x28]
        fld      dword ptr [ecx*4 + g_glideTable1]
        mov      dword ptr [esp + 0x44], eax
        movsx    eax, word ptr [esp + 0xfc]
        fstp     dword ptr [esp + 0x2c]
        mov      ecx, eax
        mov      edx, eax
        sar      ecx, 0xa
        and      ecx, 0x1f
        and      eax, 0x1f
        sar      edx, 5
        fld      dword ptr [ecx*4 + g_glideTable3]
        and      edx, 0x1f
        fstp     dword ptr [esp + 0x4c]
        fld      dword ptr [edx*4 + g_glideTable3]
        fstp     dword ptr [esp + 0x50]
        fld      dword ptr [eax*4 + g_glideTable3]
        mov      eax, dword ptr [esp + 0xf4]
        fstp     dword ptr [esp + 0x54]
        and      eax, 0xff
        fld      dword ptr [eax*4 + g_glideTable1]
        mov      ecx, dword ptr [esp + 0xf8]
        lea      edx, [esp + 0x40]
        fstp     dword ptr [esp + 0x64]
        and      ecx, 0xff
        lea      eax, [esp + 4]
        push     edx
        push     eax
        fld      dword ptr [ecx*4 + g_glideTable1]
        lea      ecx, [esp + 0x84]
        fstp     dword ptr [esp + 0x70]
        push     ecx
        call     dword ptr [g_dispatchSave1653]
        pop      ebx
    L_4992:
        add      esp, 0xb4
        ret
    }
}
#endif
