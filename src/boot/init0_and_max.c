/**
 * Auto-split from misc_matchesG.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00401370 (34b)
 *   push    edi
 *   mov     ecx, 0x0c
 *   xor     eax, eax
 *   mov     edi, 0x00523ae8
 *   rep     stosd
 *   mov     ecx, 0x0c
 *   mov     eax, 0x7fffffff
 *   mov     edi, 0x00523b28
 *   rep     stosd
 *   pop     edi
 *   ret
 */
void Init0AndMax_00401370(void) {
    __asm {
        mov     ecx, 0x0c
        xor     eax, eax
        mov     edi, 0x00523ae8
        rep     stosd
        mov     ecx, 0x0c
        mov     eax, 0x7fffffff
        mov     edi, 0x00523b28
        rep     stosd
        }
}
