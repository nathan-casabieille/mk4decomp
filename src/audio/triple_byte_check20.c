/**
 * Auto-split from misc_matchesM.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004a1c80 (45b)
 *   test    byte ptr [g_byte_004d50b8], 0x10
 *   je      +6
 *   mov     eax, 1
 *   ret
 *   mov     eax, [0x004d50b4]
 *   test    ah, 0x10
 *   je      +6
 *   mov     eax, 1
 *   ret
 *   movsx   eax, byte ptr [0x004d50c0]
 *   and     eax, 0x20
 *   shr     eax, 5
 *   ret
 */
extern unsigned int g_byte_004d50b4;
extern unsigned int g_byte_004d50b8;
extern unsigned int g_byte_004d50c0;

int TripleByteCheck20_004a1c80(void) {
    if (g_byte_004d50b8 & 0x10) return 1;
    if (g_byte_004d50b4 & 0x1000) return 1;
    __asm {
        movsx   eax, byte ptr [g_byte_004d50c0]
        and     eax, 0x20
        shr     eax, 5
        ret
    }
}

