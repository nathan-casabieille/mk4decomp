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

extern void Input_PollJoystick(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void Input_PollPlayerJoystick(int param_1)

{
  uint uVar1;
  
  if ((&g_joySelP0)[param_1] != -1) {
    uVar1 = Input_PollJoystick((&g_joySelP0)[param_1]);
    if ((uVar1 & 0x40000000) != 0) {
      *(uint *)(&g_dispatchSave536)[param_1 * 2] =
           *(uint *)(&g_dispatchSave536)[param_1 * 2] | (&g_dispatchSave537)[param_1 * 2];
    }
    if ((uVar1 & 0x80000000) != 0) {
      *(uint *)(&g_dispatchSave534)[param_1 * 2] =
           *(uint *)(&g_dispatchSave534)[param_1 * 2] | (&g_dispatchSave535)[param_1 * 2];
    }
    if ((uVar1 & 0x10000000) != 0) {
      *(uint *)(&g_renderer2_var6)[param_1 * 2] =
           *(uint *)(&g_renderer2_var6)[param_1 * 2] | (&g_renderer2_var7)[param_1 * 2];
    }
    if ((uVar1 & 0x20000000) != 0) {
      *(uint *)(&g_dispatchSave532)[param_1 * 2] =
           *(uint *)(&g_dispatchSave532)[param_1 * 2] | (&g_dispatchSave533)[param_1 * 2];
    }
    if ((*MK4_NODE(int, &g_btnBind0 + param_1) != 0) &&
       ((uVar1 & 1 << ((char)*MK4_NODE(int, &g_btnBind0 + param_1) - 1U & 0x1f)) != 0)) {
      *(uint *)(&g_dispatchSave1111)[param_1 * 2] =
           *(uint *)(&g_dispatchSave1111)[param_1 * 2] | *(uint *)(&g_dispatchSave1110 + param_1 * 8);
    }
    if ((*MK4_NODE(int, &g_btnBind1 + param_1) != 0) &&
       ((uVar1 & 1 << ((char)*MK4_NODE(int, &g_btnBind1 + param_1) - 1U & 0x1f)) != 0)) {
      *(uint *)(&g_dispatchSave1113)[param_1 * 2] =
           *(uint *)(&g_dispatchSave1113)[param_1 * 2] | *(uint *)(&g_dispatchSave1112 + param_1 * 8);
    }
    if ((*MK4_NODE(int, &g_btnBind2 + param_1) != 0) &&
       ((uVar1 & 1 << ((char)*MK4_NODE(int, &g_btnBind2 + param_1) - 1U & 0x1f)) != 0)) {
      *(uint *)(&g_dispatchSave1115)[param_1 * 2] =
           *(uint *)(&g_dispatchSave1115)[param_1 * 2] | *(uint *)(&g_dispatchSave1114 + param_1 * 8);
    }
    if ((*MK4_NODE(int, &g_btnBind3 + param_1) != 0) &&
       ((uVar1 & 1 << ((char)*MK4_NODE(int, &g_btnBind3 + param_1) - 1U & 0x1f)) != 0)) {
      *(uint *)(&g_dispatchSave1117)[param_1 * 2] =
           *(uint *)(&g_dispatchSave1117)[param_1 * 2] | *(uint *)(&g_dispatchSave1116 + param_1 * 8);
    }
    if ((*MK4_NODE(int, &g_btnBind4 + param_1) != 0) &&
       ((uVar1 & 1 << ((char)*MK4_NODE(int, &g_btnBind4 + param_1) - 1U & 0x1f)) != 0)) {
      *(uint *)(&g_dispatchSave1119)[param_1 * 2] =
           *(uint *)(&g_dispatchSave1119)[param_1 * 2] | *(uint *)(&g_dispatchSave1118 + param_1 * 8);
    }
    if ((*MK4_NODE(int, &g_btnBind5 + param_1) != 0) &&
       ((uVar1 & 1 << ((char)*MK4_NODE(int, &g_btnBind5 + param_1) - 1U & 0x1f)) != 0)) {
      *(uint *)(&g_dispatchSave1121)[param_1 * 2] =
           *(uint *)(&g_dispatchSave1121)[param_1 * 2] | *(uint *)(&g_dispatchSave1120 + param_1 * 8);
    }
    if ((*MK4_NODE(int, &g_btnBind6 + param_1) != 0) &&
       ((uVar1 & 1 << ((char)*MK4_NODE(int, &g_btnBind6 + param_1) - 1U & 0x1f)) != 0)) {
      *(uint *)(&g_dispatchSave1123)[param_1 * 2] =
           *(uint *)(&g_dispatchSave1123)[param_1 * 2] | *(uint *)(&g_dispatchSave1122 + param_1 * 8);
    }
    if ((*MK4_NODE(int, &g_btnBind7 + param_1) != 0) &&
       ((uVar1 & 1 << ((char)*MK4_NODE(int, &g_btnBind7 + param_1) - 1U & 0x1f)) != 0)) {
      *(uint *)(&g_dispatchSave1125)[param_1 * 2] =
           *(uint *)(&g_dispatchSave1125)[param_1 * 2] | *(uint *)(&g_dispatchSave1124 + param_1 * 8);
    }
    if ((*MK4_NODE(int, &g_btnBind8 + param_1) != 0) &&
       ((uVar1 & 1 << ((char)*MK4_NODE(int, &g_btnBind8 + param_1) - 1U & 0x1f)) != 0)) {
      *(uint *)(&g_dispatchSave1127)[param_1 * 2] =
           *(uint *)(&g_dispatchSave1127)[param_1 * 2] | *(uint *)(&g_dispatchSave1126 + param_1 * 8);
    }
  }
  return;
}
#else
__declspec(naked) void Input_PollPlayerJoystick(void)
{
    __asm {
        push    esi
        mov     esi, dword ptr [esp + 8]
        mov     eax, dword ptr [esi*4 + 0x00543B68]
        cmp     eax, -1
        je      L_ibmd_ret
        push    eax
        call    Input_PollJoystick
        add     esp, 4
        test    eax, 0x40000000
        je      L_ibmd_skip1
        mov     ecx, dword ptr [esi*8 + 0x004F4DCC]
        mov     edx, dword ptr [esi*8 + 0x004F4DC8]
        or      dword ptr [ecx], edx
    L_ibmd_skip1:
        test    eax, 0x80000000
        je      L_ibmd_skip2
        mov     ecx, dword ptr [esi*8 + 0x004F4DDC]
        mov     edx, dword ptr [esi*8 + 0x004F4DD8]
        or      dword ptr [ecx], edx
    L_ibmd_skip2:
        test    eax, 0x10000000
        je      L_ibmd_skip3
        mov     ecx, dword ptr [esi*8 + 0x004F4DEC]
        mov     edx, dword ptr [esi*8 + 0x004F4DE8]
        or      dword ptr [ecx], edx
    L_ibmd_skip3:
        test    eax, 0x20000000
        je      L_ibmd_skip4
        mov     ecx, dword ptr [esi*8 + 0x004F4DFC]
        mov     edx, dword ptr [esi*8 + 0x004F4DF8]
        or      dword ptr [ecx], edx
    L_ibmd_skip4:
        mov     ecx, dword ptr [esi*4 + 0x00543B20]
        test    ecx, ecx
        je      L_ibmd_skip_b1
        dec     ecx
        mov     edx, 1
        shl     edx, cl
        test    edx, eax
        je      L_ibmd_skip_b1
        mov     ecx, dword ptr [esi*8 + 0x004F4E0C]
        mov     edx, dword ptr [esi*8 + 0x004F4E08]
        or      dword ptr [ecx], edx
    L_ibmd_skip_b1:
        mov     ecx, dword ptr [esi*4 + 0x00543B28]
        test    ecx, ecx
        je      L_ibmd_skip_b2
        dec     ecx
        mov     edx, 1
        shl     edx, cl
        test    edx, eax
        je      L_ibmd_skip_b2
        mov     ecx, dword ptr [esi*8 + 0x004F4E1C]
        mov     edx, dword ptr [esi*8 + 0x004F4E18]
        or      dword ptr [ecx], edx
    L_ibmd_skip_b2:
        mov     ecx, dword ptr [esi*4 + 0x00543B30]
        test    ecx, ecx
        je      L_ibmd_skip_b3
        dec     ecx
        mov     edx, 1
        shl     edx, cl
        test    edx, eax
        je      L_ibmd_skip_b3
        mov     ecx, dword ptr [esi*8 + 0x004F4E2C]
        mov     edx, dword ptr [esi*8 + 0x004F4E28]
        or      dword ptr [ecx], edx
    L_ibmd_skip_b3:
        mov     ecx, dword ptr [esi*4 + 0x00543B38]
        test    ecx, ecx
        je      L_ibmd_skip_b4
        dec     ecx
        mov     edx, 1
        shl     edx, cl
        test    edx, eax
        je      L_ibmd_skip_b4
        mov     ecx, dword ptr [esi*8 + 0x004F4E3C]
        mov     edx, dword ptr [esi*8 + 0x004F4E38]
        or      dword ptr [ecx], edx
    L_ibmd_skip_b4:
        mov     ecx, dword ptr [esi*4 + 0x00543B40]
        test    ecx, ecx
        je      L_ibmd_skip_b5
        dec     ecx
        mov     edx, 1
        shl     edx, cl
        test    edx, eax
        je      L_ibmd_skip_b5
        mov     ecx, dword ptr [esi*8 + 0x004F4E4C]
        mov     edx, dword ptr [esi*8 + 0x004F4E48]
        or      dword ptr [ecx], edx
    L_ibmd_skip_b5:
        mov     ecx, dword ptr [esi*4 + 0x00543B48]
        test    ecx, ecx
        je      L_ibmd_skip_b6
        dec     ecx
        mov     edx, 1
        shl     edx, cl
        test    edx, eax
        je      L_ibmd_skip_b6
        mov     ecx, dword ptr [esi*8 + 0x004F4E5C]
        mov     edx, dword ptr [esi*8 + 0x004F4E58]
        or      dword ptr [ecx], edx
    L_ibmd_skip_b6:
        mov     ecx, dword ptr [esi*4 + 0x00543B50]
        test    ecx, ecx
        je      L_ibmd_skip_b7
        dec     ecx
        mov     edx, 1
        shl     edx, cl
        test    edx, eax
        je      L_ibmd_skip_b7
        mov     ecx, dword ptr [esi*8 + 0x004F4E6C]
        mov     edx, dword ptr [esi*8 + 0x004F4E68]
        or      dword ptr [ecx], edx
    L_ibmd_skip_b7:
        mov     ecx, dword ptr [esi*4 + 0x00543B58]
        test    ecx, ecx
        je      L_ibmd_skip_b8
        dec     ecx
        mov     edx, 1
        shl     edx, cl
        test    edx, eax
        je      L_ibmd_skip_b8
        mov     ecx, dword ptr [esi*8 + 0x004F4E7C]
        mov     edx, dword ptr [esi*8 + 0x004F4E78]
        or      dword ptr [ecx], edx
    L_ibmd_skip_b8:
        mov     ecx, dword ptr [esi*4 + 0x00543B60]
        test    ecx, ecx
        je      L_ibmd_ret
        dec     ecx
        mov     edx, 1
        shl     edx, cl
        test    edx, eax
        je      L_ibmd_ret
        mov     eax, dword ptr [esi*8 + 0x004F4E8C]
        mov     ecx, dword ptr [esi*8 + 0x004F4E88]
        or      dword ptr [eax], ecx
    L_ibmd_ret:
        pop     esi
        ret
    }
}
#endif
