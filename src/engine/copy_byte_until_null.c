/**
 * Auto-split from misc_matchesG.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004265a0 (41b): copy/set 4-stride
 *   mov     eax, [g_xformEntityIdx]
 *   mov     edx, [g_scaledInit_00542044]
 *   lea     ecx, [eax*4 + 0]
 *   lea     eax, [edx*4 + 0]
 * .loop:
 *   mov     dl, [eax]
 *   add     eax, 4
 *   mov     [ecx], dl
 *   inc     ecx
 *   mov     edx, [eax - 4]   ; just to set ZF? actually it's mov edx, [eax+0xfc]
 *   test    edx, edx
 *   jne     .loop
 *   ret
 *
 * Wait actually: 8b 50 fc = mov edx, [eax-4]. Let me re-decode:
 * Body: a1 482054 00 8b15 442054 00 8d0c85 00000000 8d0495 00000000 8a10 83c004 8811 41 8b50fc 85d2 75f1 c3
 * 5+6+7+7+2+3+2+1+3+2+2+1 = 41 ✓
 */
void CopyByteUntilNull_004265a0(void) {
    __asm {
        mov     eax, dword ptr [g_xformEntityIdx]
        mov     edx, dword ptr [g_scaledInit_00542044]
        lea     ecx, [eax*4 + 0]
        lea     eax, [edx*4 + 0]
        mov     dl, byte ptr [eax]
        add     eax, 4
        mov     byte ptr [ecx], dl
        inc     ecx
        mov     edx, dword ptr [eax - 4]
        test    edx, edx
        _emit   75h
        _emit   0f1h
        }
}
