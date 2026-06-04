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

/* @addr 0x004c8ed0 (239b crt) - CRT _filbuf: fill stream buffer on read.
 *   FILE* arg (esi); reads flags from [esi+0xc]. If !0x83 → error tail.
 *   If 0x40 (error) → error tail. If 0x02 → mark EOF (or 0x20), ret -1.
 *   Otherwise: ensure buffer allocated (StreamAllocInit) or reset to [esi+8].
 *   Read via IOWrapper(buf=[esi+0x10], size=[esi+8], fd=[esi+0x18]) → eax.
 *   If 0 or -1: set EOF/error flag, ret -1.
 *   Otherwise: check device flags via fd lookup table (g_crtHandleTable or default 0x5222e0):
 *     if 0x82 device flags set, OR 0x2000 into flags.
 *   If buf-size == 0x200 and flag-bit 8 set and flag-bit 0x400 clear: bump size to 0x1000.
 *   Decrement count, return first byte.
 */
extern unsigned int g_crtFilbufBase;
extern unsigned int g_crtHandleTable;
extern void IOWrapper_CritSecLazyEnter_004c8fc0(void);
extern void StreamAllocInit(void);

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
uint Filbuf(undefined4 *param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined *puVar4;
  
  uVar2 = param_1[3];
  if (((uVar2 & 0x83) != 0) && ((uVar2 & 0x40) == 0)) {
    if ((uVar2 & 2) != 0) {
      param_1[3] = uVar2 | 0x20;
      return 0xffffffff;
    }
    param_1[3] = uVar2 | 1;
    if ((uVar2 & 0x10c) == 0) {
      StreamAllocInit(param_1);
    }
    else {
      *param_1 = param_1[2];
    }
    iVar3 = IOWrapper_CritSecLazyEnter_004c8fc0(param_1[4],param_1[2],param_1[6]);
    param_1[1] = iVar3;
    if ((iVar3 != 0) && (iVar3 != -1)) {
      if ((param_1[3] & 0x82) == 0) {
        uVar2 = param_1[4];
        if (uVar2 == 0xffffffff) {
          puVar4 = &g_crtFilbufBase;
        }
        else {
          puVar4 = (undefined *)((&g_crtHandleTable)[(int)uVar2 >> 5] + (uVar2 & 0x1f) * 0x24);
        }
        if ((puVar4[4] & 0x82) == 0x82) {
          param_1[3] = param_1[3] | 0x2000;
        }
      }
      if (((param_1[6] == 0x200) && ((param_1[3] & 8) != 0)) && ((param_1[3] & 0x400) == 0)) {
        param_1[6] = 0x1000;
      }
      param_1[1] = iVar3 + -1;
      bVar1 = *(byte *)*param_1;
      *param_1 = (byte *)*param_1 + 1;
      return (uint)bVar1;
    }
    param_1[1] = 0;
    param_1[3] = param_1[3] | (-(uint)(iVar3 != 0) & 0x10) + 0x10;
  }
  return 0xffffffff;
}
#else
__declspec(naked) void Filbuf(void) {
    __asm {
        push    esi
        mov     esi, [esp + 8]
        push    edi
        mov     eax, [esi + 0xc]
        test    al, 0x83
        jz      L_fb_err
        test    al, 0x40
        jne     L_fb_err
        test    al, 2
        jz      short L_fb_setRead
        or      al, 0x20
        mov     [esi + 0xc], eax
        or      eax, -1
        pop     edi
        pop     esi
        ret
    L_fb_setRead:
        or      al, 1
        test    eax, 0x10c
        mov     [esi + 0xc], eax
        jne     short L_fb_haveBuf
        push    esi
        call    StreamAllocInit
        add     esp, 4
        jmp     short L_fb_doRead
    L_fb_haveBuf:
        mov     eax, [esi + 8]
        mov     [esi], eax
    L_fb_doRead:
        mov     ecx, [esi + 0x18]
        mov     edx, [esi + 8]
        mov     eax, [esi + 0x10]
        push    ecx
        push    edx
        push    eax
        call    IOWrapper_CritSecLazyEnter_004c8fc0
        add     esp, 0xc
        mov     [esi + 4], eax
        test    eax, eax
        jz      short L_fb_eof
        cmp     eax, -1
        jz      short L_fb_eof
        mov     edx, [esi + 0xc]
        test    dl, 0x82
        jne     short L_fb_sizeCk
        mov     ecx, [esi + 0x10]
        cmp     ecx, -1
        jz      short L_fb_useDefault
        mov     edi, ecx
        sar     edi, 5
        and     ecx, 0x1f
        mov     edi, dword ptr [edi*4 + g_crtHandleTable]
        lea     ecx, [ecx + ecx*8]
        lea     ecx, [edi + ecx*4]
        jmp     short L_fb_checkFlags
    L_fb_useDefault:
        mov     ecx, offset g_crtFilbufBase
    L_fb_checkFlags:
        mov     cl, byte ptr [ecx + 4]
        and     cl, 0x82
        cmp     cl, 0x82
        jne     short L_fb_sizeCk
        or      dh, 0x20
        mov     [esi + 0xc], edx
    L_fb_sizeCk:
        cmp     dword ptr [esi + 0x18], 0x200
        jne     short L_fb_advance
        mov     ecx, [esi + 0xc]
        test    cl, 8
        jz      short L_fb_advance
        test    ch, 4
        jne     short L_fb_advance
        mov     dword ptr [esi + 0x18], 0x1000
    L_fb_advance:
        dec     eax
        xor     edx, edx
        mov     [esi + 4], eax
        mov     eax, [esi]
        mov     dl, [eax]
        inc     eax
        mov     [esi], eax
        mov     eax, edx
        pop     edi
        pop     esi
        ret
    L_fb_eof:
        mov     ecx, [esi + 0xc]
        mov     dword ptr [esi + 4], 0
        neg     eax
        sbb     eax, eax
        and     eax, 0x10
        add     eax, 0x10
        or      ecx, eax
        mov     [esi + 0xc], ecx
    L_fb_err:
        pop     edi
        or      eax, -1
        pop     esi
        ret
    }
}
#endif
