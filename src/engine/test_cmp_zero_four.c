/**
 * Auto-split from misc_matchesE.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
#endif

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
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned char g_audioInitSeqByte;
extern unsigned int g_or;
extern unsigned int g_save_0053a7d8;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_audioInitSeqByte (*(unsigned char *)MK4_VA(unsigned char, 0x542040u))
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_or (*(unsigned int *)MK4_VA(unsigned int, 0x52ab40u))
#define g_save_0053a7d8 (*(unsigned int *)MK4_VA(unsigned int, 0x53a7d8u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_walkStateIndex (*(unsigned int *)MK4_VA(unsigned int, 0x53a748u))
#endif

void TestCmpZeroFour(void) {
    g_walkCallback = (void (*)(void))0;
    if (g_audioInitSeqByte == 0) {
        g_or = 0;
    }
    g_audioInitSeqByte = 0;
    g_save_0053a7d8 = 0;
    g_walkStateIndex = 0;
}
