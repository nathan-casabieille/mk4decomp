/**
 * 2 "matrix-stack push + call + pause + pop + dirty test + jmp" (77b).
 *
 * Pattern:
 *   mov     eax, [g_matrixStackTop]
 *   mov     ecx, [g_walkCallback]
 *   inc     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], ecx
 *   call    Func
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, [g_matrixStackTop]
 *   mov     edx, [eax*4 + 0]
 *   dec     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     al, [g_xformDirtyFlags]
 *   test    al, 1
 *   mov     [g_walkCallback], edx
 *   je      .ret
 *   jmp     Tail
 * .ret:
 *   ret
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

extern void State208cBit0Flag(void);
extern void GuardedRangeCmpToggle(void);
extern void MStackCjChainSwapDualCall(void);

/* @addr 0x0042cc90 */

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void MStackPushCallPopDirtyJmp_State208cBit0Flag(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined *puVar3;
  
  g_matrixStackTop = g_matrixStackTop + 1;
  *(undefined4 *)((int)g_matrixStackTop * 4) = g_walkCallback;
  State208cBit0Flag();
  puVar3 = g_matrixStackTop;
  if (g_framePauseFlag == 0) {
    g_walkCallback = *(undefined4 *)((int)g_matrixStackTop * 4);
    puVar3 = g_matrixStackTop + -1;
    if (((byte)g_xformDirtyFlags & 1) != 0) {
      *(undefined4 *)((int)g_matrixStackTop * 4) = g_walkCallback;
      (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = MK4_NODE_AT(int, g_baseSel, 0x38);
      g_walkCallback = *(undefined4 *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x54);
      g_eventQueueCurrent = *(undefined4 *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x5c);
      g_eventQueueWorkType = MK4_NODE_AT(undefined4, g_cj_0054205c, 0x54);
      g_chainAccumCur = MK4_NODE_AT(undefined4, g_cj_0054205c, 0x5c);
      *(undefined4 *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x54) = g_eventQueueWorkType;
      *(undefined4 *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x5c) = g_chainAccumCur;
      MK4_NODE_AT(undefined4, g_cj_0054205c, 0x54) = g_walkCallback;
      MK4_NODE_AT(undefined4, g_cj_0054205c, 0x5c) = g_eventQueueCurrent;
      DualCallPauseDirtyJmp_00490c30();
      if (g_framePauseFlag == 0) {
        IterLoad_g_scaledInit_00542044_then_MStackPush4IndirectCall(&(*(unsigned int *)MK4_VA(unsigned int, 0x4e3698)));
        uVar2 = g_fightAxisPosY;
        uVar1 = g_fightAxisNegX;
        if (g_framePauseFlag == 0) {
          g_fightAxisNegX = g_fightAxisPosX;
          g_eventQueueCurrent = g_fightAxisPosY;
          g_eventQueueWorkType = uVar1;
          g_chainAccumCur = g_fightAxisNegY;
          g_fightAxisPosX = uVar1;
          g_fightAxisPosY = g_fightAxisNegY;
          g_fightAxisNegY = uVar2;
          g_walkCallback = *(undefined4 *)((int)g_matrixStackTop * 4);
          g_matrixStackTop = g_matrixStackTop + -1;
        }
      }
      return;
    }
  }
  g_matrixStackTop = puVar3;
  return;
}
#else
__declspec(naked) void MStackPushCallPopDirtyJmp_State208cBit0Flag(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_walkCallback]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], ecx
        call    State208cBit0Flag
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_mscpd_ret_a
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     al, byte ptr [g_xformDirtyFlags]
        test    al, 1
        mov     dword ptr [g_walkCallback], edx
        je      short L_mscpd_ret_a
        jmp     MStackCjChainSwapDualCall
L_mscpd_ret_a:
        ret
    }
}
#endif

/* @addr 0x0042cce0 */
#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void MStackPushCallPopDirtyJmp_GuardedRangeCmpToggle(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined *puVar3;
  
  g_matrixStackTop = g_matrixStackTop + 1;
  *(undefined4 *)((int)g_matrixStackTop * 4) = g_walkCallback;
  GuardedRangeCmpToggle();
  puVar3 = g_matrixStackTop;
  if (g_framePauseFlag == 0) {
    g_walkCallback = *(undefined4 *)((int)g_matrixStackTop * 4);
    puVar3 = g_matrixStackTop + -1;
    if (((byte)g_xformDirtyFlags & 1) != 0) {
      *(undefined4 *)((int)g_matrixStackTop * 4) = g_walkCallback;
      (*(unsigned int *)MK4_VA(unsigned int, 0x542044)) = MK4_NODE_AT(int, g_baseSel, 0x38);
      g_walkCallback = *(undefined4 *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x54);
      g_eventQueueCurrent = *(undefined4 *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x5c);
      g_eventQueueWorkType = MK4_NODE_AT(undefined4, g_cj_0054205c, 0x54);
      g_chainAccumCur = MK4_NODE_AT(undefined4, g_cj_0054205c, 0x5c);
      *(undefined4 *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x54) = g_eventQueueWorkType;
      *(undefined4 *)((*(unsigned int *)MK4_VA(unsigned int, 0x542044)) * 4 + 0x5c) = g_chainAccumCur;
      MK4_NODE_AT(undefined4, g_cj_0054205c, 0x54) = g_walkCallback;
      MK4_NODE_AT(undefined4, g_cj_0054205c, 0x5c) = g_eventQueueCurrent;
      DualCallPauseDirtyJmp_00490c30();
      if (g_framePauseFlag == 0) {
        IterLoad_g_scaledInit_00542044_then_MStackPush4IndirectCall(&(*(unsigned int *)MK4_VA(unsigned int, 0x4e3698)));
        uVar2 = g_fightAxisPosY;
        uVar1 = g_fightAxisNegX;
        if (g_framePauseFlag == 0) {
          g_fightAxisNegX = g_fightAxisPosX;
          g_eventQueueCurrent = g_fightAxisPosY;
          g_eventQueueWorkType = uVar1;
          g_chainAccumCur = g_fightAxisNegY;
          g_fightAxisPosX = uVar1;
          g_fightAxisPosY = g_fightAxisNegY;
          g_fightAxisNegY = uVar2;
          g_walkCallback = *(undefined4 *)((int)g_matrixStackTop * 4);
          g_matrixStackTop = g_matrixStackTop + -1;
        }
      }
      return;
    }
  }
  g_matrixStackTop = puVar3;
  return;
}
#else
__declspec(naked) void MStackPushCallPopDirtyJmp_GuardedRangeCmpToggle(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_walkCallback]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], ecx
        call    GuardedRangeCmpToggle
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     short L_mscpd_ret_b
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     al, byte ptr [g_xformDirtyFlags]
        test    al, 1
        mov     dword ptr [g_walkCallback], edx
        je      short L_mscpd_ret_b
        jmp     MStackCjChainSwapDualCall
L_mscpd_ret_b:
        ret
    }
}
#endif
