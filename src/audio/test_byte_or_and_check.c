/**
 * Auto-split from misc_matchesL.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004a1ae0 (32b)
 *   test    byte ptr [0x004d50b8], 0x22
 *   je      .skip
 *   mov     eax, 1
 *   ret
 * .skip:
 *   mov     eax, [0x004d50b4]
 *   and     eax, 0x4040
 *   neg     eax
 *   sbb     eax, eax
 *   neg     eax
 *   ret
 */
extern unsigned char g_byte_004d50b8[1];
extern unsigned int g_state_004d50b4;
int TestByteOrAndCheck_004a1ae0(void) {
    int v;
    if ((g_byte_004d50b8[0] & 0x22) != 0) return 1;
    v = g_state_004d50b4 & 0x4040;
    return v != 0;
}
