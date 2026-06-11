/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;

/* @addr 0x00433c10 (74b)
 *   Dual scaled-init helper: stores 0x53a1a0>>2 into g_scaledInit
 *   and 0x53a518>>2 into g_xformEntityIdx; if g_fightGroupHead !=
 *   [0x538158], also overrides g_scaledInit with the second value.
 *   Then clears g_walkCallback and the indexed slot.
 */

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void DualScaledInitClear(void)

{
  int iVar1;
  
  (g_currentNodeIdx) = 0x14e868;
  g_eventQueuePending = 0x14e946;
  iVar1 = 0x14e868;
  if (g_cj_0054205c != g_player1NodeIdx) {
    (g_currentNodeIdx) = 0x14e946;
    iVar1 = 0x14e946;
  }
  g_walkCallback = 0;
  MK4_NODE_AT(undefined4, iVar1, 0) = 0;
  return;
}
#else
__declspec(naked) void DualScaledInitClear(void) {
    __asm {
        mov     edx, dword ptr [g_fightGroupHead]
        push    esi
        mov     esi, dword ptr [g_player1NodeIdx]
        mov     eax, 0x0053a1a0
        mov     ecx, 0x0053a518
        shr     eax, 2
        shr     ecx, 2
        cmp     edx, esi
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [g_xformEntityIdx], ecx
        _emit   74h
        _emit   07h
        mov     eax, ecx
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [g_walkCallback], 0
        mov     dword ptr [eax*4 + 0], 0
        pop     esi
        ret
    }
}
#endif
