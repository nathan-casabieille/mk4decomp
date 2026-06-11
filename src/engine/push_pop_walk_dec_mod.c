/**
 * Auto-split from misc_matchesMM.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004923f0 (91b)
 *   inc g_matrixStackTop; push g_eventQueueCurrent; load walk;
 *   dec walk; if walk<0 jmp shift-amount path; else fall through.
 *   Computes shifted-mod via [g_eventMaskState + ecx*4] table.
 */
extern unsigned int g_eventQueueCurrent_mm;
extern unsigned int g_eventMaskState;

#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void PushPopWalkDecMod(void)

{
  g_matrixStackTop = g_matrixStackTop + 1;
  *MK4_NODE(undefined4, (int)g_matrixStackTop) = g_eventQueueCurrent;
  g_walkCallback = g_walkCallback - 1;
  if (-1 < (int)g_walkCallback) {
    g_walkCallback = g_eventMaskState >> ((char)g_walkCallback * '\x04' & 0x1fU) & 0xf;
  }
  g_eventQueueCurrent = *MK4_NODE(undefined4, (int)g_matrixStackTop);
  g_matrixStackTop = g_matrixStackTop + -1;
  return;
}
#else
__declspec(naked) void PushPopWalkDecMod(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_eventQueueCurrent_mm]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     eax, dword ptr [g_walkCallback]
        dec     eax
        mov     dword ptr [g_walkCallback], eax
        _emit   78h
        _emit   1dh
        mov     edx, eax
        mov     eax, dword ptr [g_eventMaskState]
        lea     ecx, [edx*4 + 0]
        shr     eax, cl
        and     eax, 0x0f
        mov     dword ptr [g_eventQueueCurrent_mm], eax
        mov     dword ptr [g_walkCallback], eax
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [eax*4 + 0]
        dec     eax
        mov     dword ptr [g_eventQueueCurrent_mm], ecx
        mov     dword ptr [g_matrixStackTop], eax
        ret
    }
}
#endif
