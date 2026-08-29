/**
 * 2 "clamp two values to 0x10000" helpers (55 bytes each).
 *
 * Pattern:
 *   mov     eax, [g_X]
 *   cmp     eax, 0x00010000
 *   jle     .skipX
 *   mov     eax, 0x00010000
 *   mov     [g_X], eax
 * .skipX:
 *   mov     eax, [g_Y]
 *   cmp     eax, 0x00010000
 *   mov     [g_walkCallback], eax
 *   jle     .skipY
 *   mov     eax, 0x00010000
 *   mov     [g_walkCallback], eax
 *   mov     [g_Y], eax
 * .skipY:
 *   ret
 */
#include "engine/scenegraph.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_clamp_0053a6dc;
extern unsigned int g_clamp_0053a328;
extern unsigned int g_clamp_00537f2c;
extern unsigned int g_clamp_0053e348;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_clamp_00537f2c (*(unsigned int *)MK4_VA(unsigned int, 0x537f2cu))
#define g_clamp_0053a328 (*(unsigned int *)MK4_VA(unsigned int, 0x53a328u))
#define g_clamp_0053a6dc (*(unsigned int *)MK4_VA(unsigned int, 0x53a6dcu))
#define g_clamp_0053e348 (*(unsigned int *)MK4_VA(unsigned int, 0x53e348u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif


/* @addr 0x004226a0 */
void ClampTwoToMax_004226a0(void) {
    unsigned int v;
    v = g_clamp_0053a6dc;
    if ((int)v > 0x10000) {
        g_clamp_0053a6dc = 0x10000;
    }
    v = g_clamp_0053a328;
    g_walkCallback = v;
    if ((int)v > 0x10000) {
        g_walkCallback = 0x10000;
        g_clamp_0053a328 = 0x10000;
    }
}

/* @addr 0x004226e0 */
void ClampTwoToMax_004226e0(void) {
    unsigned int v;
    v = g_clamp_00537f2c;
    if ((int)v > 0x10000) {
        g_clamp_00537f2c = 0x10000;
    }
    v = g_clamp_0053e348;
    g_walkCallback = v;
    if ((int)v > 0x10000) {
        g_walkCallback = 0x10000;
        g_clamp_0053e348 = 0x10000;
    }
}
