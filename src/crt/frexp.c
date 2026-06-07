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

/* @addr 0x004cdee0 (259b crt) - _frexp-like double mantissa/exponent split.
 *   Arg: double x at [esp+4], int* exp at [esp+0x18].
 *   Compares x to 0.0 (g_crtMemMoveVar). If equal: *exp = 0, return 0.0.
 *   Else: extract exponent bits; if 0 (denormal/zero): denormal-renormalize
 *     loop, then compute fresh mantissa via PackDoubleFromInts; *exp = computed.
 *   Normal: pack 64-bit mantissa via PackDoubleFromInts, extract biased exp,
 *     store *exp = biased_exp - 0x3fe, return mantissa as double.
 */
extern unsigned int g_crtMemMoveVar;
extern void PackDoubleFromInts(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
float10 Frexp(uint param_1,uint param_2,int *param_3)

{
  ushort uVar1;
  double dVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  float10 fVar6;
  
  if ((double)CONCAT17((*(unsigned char *)((char *)&param_2 + 3)),CONCAT16((*(unsigned char *)((char *)&param_2 + 2)),CONCAT24((undefined2)param_2,param_1)))
      == g_crtMemMoveVar) {
    *param_3 = 0;
    return (float10)0.0;
  }
  if (((param_2 & 0x7ff00000) == 0) && (((param_2 & 0xfffff) != 0 || (param_1 != 0)))) {
    dVar2 = (double)CONCAT17((*(unsigned char *)((char *)&param_2 + 3)),
                             CONCAT16((*(unsigned char *)((char *)&param_2 + 2)),CONCAT24((undefined2)param_2,param_1)));
    iVar5 = -0x3fd;
    uVar4 = param_2;
    uVar3 = param_2;
    while ((uVar3 & 0x100000) == 0) {
      uVar3 = uVar4 << 1;
      (*(unsigned short *)((char *)&param_2 + 0)) = (undefined2)uVar3;
      (*(unsigned char *)((char *)&param_2 + 2)) = (undefined1)(uVar3 >> 0x10);
      (*(unsigned char *)((char *)&param_2 + 3)) = (byte)(uVar3 >> 0x18);
      uVar4 = uVar3;
      if ((param_1 & 0x80000000) != 0) {
        uVar4 = uVar3 | 1;
        (*(unsigned short *)((char *)&param_2 + 0)) = (undefined2)uVar4;
      }
      param_1 = param_1 << 1;
      iVar5 = iVar5 + -1;
    }
    uVar1 = CONCAT11((*(unsigned char *)((char *)&param_2 + 3)),(*(unsigned char *)((char *)&param_2 + 2))) & 0xffef;
    (*(unsigned char *)((char *)&param_2 + 2)) = (undefined1)uVar1;
    (*(unsigned char *)((char *)&param_2 + 3)) = (byte)(uVar1 >> 8);
    if (dVar2 < g_crtMemMoveVar) {
      (*(unsigned char *)((char *)&param_2 + 3)) = (*(unsigned char *)((char *)&param_2 + 3)) | 0x80;
    }
    fVar6 = (float10)PackDoubleFromInts(param_1,CONCAT13((*(unsigned char *)((char *)&param_2 + 3)),
                                                   CONCAT12((*(unsigned char *)((char *)&param_2 + 2)),(undefined2)param_2)),0);
    *param_3 = iVar5;
    return (float10)(double)fVar6;
  }
  fVar6 = (float10)PackDoubleFromInts(param_1,param_2,0);
  *param_3 = (short)((ushort)(param_2 >> 0x14) & 0x7ff) + -0x3fe;
  return (float10)(double)fVar6;
}
#else
__declspec(naked) void Frexp(void) {
    __asm {
        fld     qword ptr [esp + 4]
        fcomp   qword ptr [g_crtMemMoveVar]
        push    ebx
        push    esi
        push    edi
        fnstsw  ax
        test    ah, 0x40
        jz      short L_fx_nz
        mov     ecx, [esp + 0x18]
        mov     dword ptr [esp + 0x10], 0
        mov     dword ptr [esp + 0x14], 0
        xor     esi, esi
        fld     qword ptr [esp + 0x10]
        mov     [ecx], esi
        pop     edi
        pop     esi
        pop     ebx
        ret
    L_fx_nz:
        mov     esi, [esp + 0x16]
        mov     edx, [esp + 0x14]
        mov     ecx, [esp + 0x10]
        test    esi, 0x7ff0
        jne     L_fx_normal
        test    edx, 0xfffff
        jne     short L_fx_denorm
        test    ecx, ecx
        jz      L_fx_normal
    L_fx_denorm:
        fld     qword ptr [esp + 0x10]
        fcomp   qword ptr [g_crtMemMoveVar]
        mov     esi, -0x3fd
        fnstsw  ax
        test    ah, 1
        jz      short L_fx_dnoneg
        mov     edi, 1
        jmp     short L_fx_dnsetup
    L_fx_dnoneg:
        xor     edi, edi
    L_fx_dnsetup:
        mov     bl, byte ptr [esp + 0x16]
        mov     al, 0x10
        test    bl, al
        jne     short L_fx_dndone
    L_fx_dnloop:
        shl     edx, 1
        test    ecx, 0x80000000
        mov     [esp + 0x14], edx
        jz      short L_fx_dnsave
        or      edx, 1
        mov     [esp + 0x14], edx
    L_fx_dnsave:
        mov     bl, byte ptr [esp + 0x16]
        shl     ecx, 1
        dec     esi
        test    bl, al
        jz      short L_fx_dnloop
    L_fx_dndone:
        _emit   66h
        _emit   81h
        _emit   64h
        _emit   24h
        _emit   16h
        _emit   0efh
        _emit   0ffh
        test    edi, edi
        jz      short L_fx_dnPos
        or      byte ptr [esp + 0x17], 0x80
    L_fx_dnPos:
        mov     eax, dword ptr [esp + 0x14]
        push    0
        push    eax
        push    ecx
        call    PackDoubleFromInts
        mov     ecx, [esp + 0x24]
        add     esp, 0xc
        fstp    qword ptr [esp + 0x10]
        fld     qword ptr [esp + 0x10]
        mov     [ecx], esi
        pop     edi
        pop     esi
        pop     ebx
        ret
    L_fx_normal:
        push    0
        push    edx
        push    ecx
        call    PackDoubleFromInts
        mov     ecx, [esp + 0x24]
        add     esp, 0xc
        shr     esi, 4
        fstp    qword ptr [esp + 0x10]
        and     esi, 0x7ff
        pop     edi
        movsx   esi, si
        fld     qword ptr [esp + 0xc]
        sub     esi, 0x3fe
        mov     [ecx], esi
        pop     esi
        pop     ebx
        ret
    }
}
#endif
