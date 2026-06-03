/**
 * Auto-split from misc_matchesE.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004238b0 (38b)
 *   mov     cl, byte ptr [g_audioInitSeqByte]
 *   xor     eax, eax
 *   cmp     cl, al
 *   mov     [g_walkCallback], eax
 *   jne     +5
 *   mov     [0x0052ab40], eax
 *   mov     byte ptr [g_audioInitSeqByte], al
 *   mov     [g_save_0053a7d8], eax
 *   mov     [g_walkStateIndex], eax
 *   ret
 */
extern unsigned char g_audioInitSeqByte;
extern unsigned int g_or;
extern unsigned int g_save_0053a7d8;
void TestCmpZeroFour(void) {
    g_walkCallback = (void (*)(void))0;
    if (g_audioInitSeqByte == 0) {
        g_or = 0;
    }
    g_audioInitSeqByte = 0;
    g_save_0053a7d8 = 0;
    g_walkStateIndex = 0;
}
