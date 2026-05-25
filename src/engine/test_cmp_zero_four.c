/**
 * Auto-split from misc_matchesE.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004238b0 (38b)
 *   mov     cl, byte ptr [g_byte_00542040]
 *   xor     eax, eax
 *   cmp     cl, al
 *   mov     [g_walkCallback], eax
 *   jne     +5
 *   mov     [0x0052ab40], eax
 *   mov     byte ptr [g_byte_00542040], al
 *   mov     [g_save_0053a7d8], eax
 *   mov     [g_walkStateIndex], eax
 *   ret
 */
extern unsigned char g_byte_00542040;
extern unsigned int g_or_0052ab40;
extern unsigned int g_save_0053a7d8;
void TestCmpZeroFour_004238b0(void) {
    g_walkCallback = (void (*)(void))0;
    if (g_byte_00542040 == 0) {
        g_or_0052ab40 = 0;
    }
    g_byte_00542040 = 0;
    g_save_0053a7d8 = 0;
    g_walkStateIndex = 0;
}
