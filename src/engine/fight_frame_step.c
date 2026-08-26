/**
 * Inner per-frame entity step.
 *
 * Walks the fight-scene sibling list off the current head pointer,
 * AND-merging child masks into the working state. Exits early via
 * the bare `ret` path if the head equals the previous one (XOR=0);
 * otherwise pushes esi/edi, walks the linked list of siblings (via
 * the [base*4 + 0] / [base*4 + 4] indirection), updating the queue
 * cursor and clamping it to the secondary range when it reaches the
 * primary end.
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_eventQueuePending;   /* 0x005420c8, packed node ptr */
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_cj_00542054 (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_cj_00542058 (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))
#define g_cj_0054205c (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_currentNodeFlags (*(unsigned int *)MK4_VA(unsigned int, 0x542084u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dualC (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_dualD (*(unsigned int *)MK4_VA(unsigned int, 0x542050u))
#define g_eventQueueChild (*(unsigned int *)MK4_VA(unsigned int, 0x542080u))
#define g_eventQueueCurrent (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_eventQueueHead (*(unsigned int *)MK4_VA(unsigned int, 0x53a2f0u))
#define g_eventQueueNotMask (*(unsigned int *)MK4_VA(unsigned int, 0x54207cu))
#define g_eventQueuePending (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_eventQueueWorkType (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif


/*
 * @addr 0x0045c6c0
 *

 * Naked + __asm: scaled-base addressing pattern (`[reg*4 + disp]`
 * with the table address kept as `addr >> 2` in the register) makes
 * the natural C form unrepresentable; the asymmetric epilogue
 * (early-out as bare `ret` versus `pop esi; mov; pop edi; ret`)
 * also requires a hand-rolled tail.
 */

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void FightFrameStep_Inner(void)

{
  uint uVar1;
  uint uVar2;
  
  g_walkCallback = MK4_NODE_AT(uint, g_cj_0054205c, 0) & 0xffff;
  g_eventQueueCurrent = *MK4_NODE(uint, (g_currentNodeIdx));
  g_eventQueueWorkType = MK4_NODE_AT(uint, g_eventQueuePending, 0);
  *MK4_NODE(uint, (g_currentNodeIdx)) = g_walkCallback;
  MK4_NODE_AT(uint, g_eventQueuePending, 0) = g_eventQueueCurrent;
  uVar1 = g_eventQueueCurrent ^ g_walkCallback;
  g_currentNodeFlags = g_eventQueueCurrent;
  if (uVar1 != 0) {
    g_eventQueueNotMask = ~g_walkCallback;
    if ((g_eventQueueNotMask & uVar1) == 0) {
      g_dualC = g_dualD;
      uVar2 = uVar1;
    }
    else {
      g_currentNodeFlags = g_eventQueueCurrent & g_eventQueueWorkType;
      uVar2 = g_eventQueueNotMask & uVar1 & g_currentNodeFlags;
    }
    g_walkCallback = MK4_NODE_AT(uint, g_dualC, 0);
    g_eventQueueCurrent = uVar1;
    g_cj_00542058 = g_eventQueueHead;
    g_eventQueuePending = g_dualC;
    g_eventQueueChild = uVar2;
    while (uVar1 = g_eventQueueCurrent, g_walkCallback != 0) {
      g_eventQueueCurrent = uVar2 & g_walkCallback;
      if (g_eventQueueCurrent != 0) {
        g_dualD = MK4_NODE_AT(int, g_eventQueuePending, 4);
        MK4_NODE_AT(int, g_eventQueueHead, 0) = g_dualD;
        g_cj_00542058 = g_cj_00542058 + 1;
        g_cj_00542054 = 0x14e942;
        if (g_cj_00542058 == 0x14e942) {
          g_cj_00542058 = 0x14e92e;
        }
        g_eventQueueHead = g_cj_00542058;
        uVar2 = g_eventQueueChild;
        if (g_eventQueueChild == g_walkCallback) {
          g_cj_00542054 = 0x14e942;
          return;
        }
      }
      g_eventQueuePending = g_eventQueuePending + 2;
      g_walkCallback = MK4_NODE_AT(uint, g_eventQueuePending, 0);
    }
  }
  g_eventQueueCurrent = uVar1;
  return;
}
#else
__declspec(naked) void FightFrameStep_Inner(void)
{
    __asm {
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     eax, dword ptr [eax*4]
        and     eax, 0xffff
        mov     dword ptr [g_walkCallback], eax
        mov     edx, dword ptr [ecx*4]
        mov     dword ptr [g_eventQueueCurrent], edx
        mov     edx, dword ptr [g_xformEntityIdx]
        mov     edx, dword ptr [edx*4]
        mov     dword ptr [g_eventQueueWorkType], edx
        mov     dword ptr [ecx*4], eax
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     eax, dword ptr [g_eventQueueCurrent]
        mov     dword ptr [ecx*4], eax
        mov     eax, dword ptr [g_eventQueueCurrent]
        mov     ecx, dword ptr [g_walkCallback]
        mov     edx, eax
        xor     eax, ecx
        mov     dword ptr [g_currentNodeFlags], edx
        mov     dword ptr [g_eventQueueCurrent], eax
        je      end
        not     ecx
        mov     dword ptr [g_eventQueueNotMask], ecx
        push    edi
        and     ecx, eax
        push    esi
        mov     esi, ecx
        jne     branch_a
        mov     edx, dword ptr [g_eventQueueTotal]
        mov     esi, eax
        mov     dword ptr [g_pendingNodeType], edx
        jmp     next
branch_a:
        and     edx, dword ptr [g_eventQueueWorkType]
        mov     dword ptr [g_currentNodeFlags], edx
        and     esi, edx
next:
        mov     ecx, dword ptr [g_eventQueueHead]
        mov     eax, dword ptr [g_pendingNodeType]
        mov     dword ptr [g_eventQueueChild], esi
        mov     dword ptr [g_eventQueueIdx], ecx
        mov     dword ptr [g_xformEntityIdx], eax
        mov     edx, dword ptr [eax*4]
        test    edx, edx
        mov     dword ptr [g_walkCallback], edx
        je      bail
loop_top:
        mov     edi, esi
        and     edi, edx
        mov     dword ptr [g_eventQueueCurrent], edi
        je      skip_inner
        mov     eax, dword ptr [eax*4 + 4]
        mov     dword ptr [g_eventQueueTotal], eax
        mov     dword ptr [ecx*4], eax
        mov     ecx, dword ptr [g_eventQueueIdx]
        mov     eax, 0x53a508
        inc     ecx
        shr     eax, 2
        cmp     ecx, eax
        mov     dword ptr [g_eventQueueIdx], ecx
        mov     dword ptr [g_eventQueueEnd], eax
        jne     skip_clamp
        mov     ecx, 0x53a4b8
        shr     ecx, 2
        mov     dword ptr [g_eventQueueIdx], ecx
skip_clamp:
        mov     esi, dword ptr [g_eventQueueChild]
        mov     eax, dword ptr [g_walkCallback]
        cmp     esi, eax
        je      bail
        mov     eax, dword ptr [g_xformEntityIdx]
skip_inner:
        add     eax, 2
        mov     dword ptr [g_xformEntityIdx], eax
        mov     edx, dword ptr [eax*4]
        test    edx, edx
        mov     dword ptr [g_walkCallback], edx
        jne     loop_top
bail:
        pop     esi
        mov     dword ptr [g_eventQueueHead], ecx
        pop     edi
end:
        ret
    }
}
#endif
