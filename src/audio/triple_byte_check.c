/**
 * Auto-split from misc_matchesM.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004a1c50 (38b)
 *   mov     cl, byte ptr [0x004d50b8]
 *   mov     eax, 1
 *   test    cl, al
 *   jne     +0x16
 *   test    byte ptr [0x004d50b4], 0x10
 *   jne     +0x0d
 *   movsx   eax, byte ptr [0x004d50c0]
 *   and     eax, 4
 *   shr     eax, 2
 *   ret
 */
extern unsigned char g_byte_004d50b8;
extern unsigned char g_byte_004d50b4;
extern char g_byte_004d50c0;
int TripleByteCheck_004a1c50(void) {
    int v = 1;
    if (g_byte_004d50b8 & v) return v;
    if (g_byte_004d50b4 & 0x10) return v;
    __asm {
        movsx   eax, byte ptr [g_byte_004d50c0]
        and     eax, 4
        shr     eax, 2
    }
    /* asm sets eax; falls into compiler-emitted ret */
}
