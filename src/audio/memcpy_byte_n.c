/**
 * Auto-split from misc_matches9.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004a5680 (28b)
 *   push    esi
 *   mov     esi, [esp+0x10]
 *   test    esi, esi
 *   jle     .ret
 *   mov     ecx, [esp+0x0c]
 *   mov     eax, [esp+8]
 * .loop:
 *   mov     dl, [ecx]
 *   mov     [eax], dl
 *   inc     eax
 *   inc     ecx
 *   dec     esi
 *   jne     .loop
 * .ret:
 *   pop     esi
 *   ret
 */
void MemcpyByteN(unsigned char *dst, unsigned char *src, int n) {
    if (n <= 0) return;
    do {
        *dst++ = *src++;
    } while (--n);
}
