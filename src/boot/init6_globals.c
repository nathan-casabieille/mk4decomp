/**
 * Auto-split from misc_matchesN.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
#endif

/* @addr 0x004051b0 (47b)
 *   xor     eax, eax
 *   mov     [0x0053a188], eax
 *   mov     [0x0053a498], eax
 *   mov     [0x0053a79c], eax
 *   mov     [0x00537f08], eax
 *   mov     [0x0053a380], eax
 *   mov     eax, 1
 *   mov     [g_walkCallback], eax
 *   mov     [0x00535d08], eax
 *   jmp     T
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_dispatchSave305;
extern unsigned int g_dispatchSave401;
extern unsigned int g_dispatchSave304;
extern unsigned int g_dispatchSave400;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dispatchSave304 (*(unsigned int *)MK4_VA(unsigned int, 0x53a380u))
#define g_dispatchSave305 (*(unsigned int *)MK4_VA(unsigned int, 0x53a188u))
#define g_dispatchSave400 (*(unsigned int *)MK4_VA(unsigned int, 0x535d08u))
#define g_dispatchSave401 (*(unsigned int *)MK4_VA(unsigned int, 0x537f08u))
#define g_gtFightTickCounter (*(unsigned int *)MK4_VA(unsigned int, 0x53a498u))
#define g_logicFrameCounter (*(unsigned int *)MK4_VA(unsigned int, 0x53a79cu))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif

extern void BootInitChainHeavy(void);
void Init6Globals(void) {
    g_dispatchSave305 = 0;
    g_gtFightTickCounter = 0;
    g_logicFrameCounter = 0;
    g_dispatchSave401 = 0;
    g_dispatchSave304 = 0;
    g_walkCallback = 1;
    g_dispatchSave400 = 1;
    BootInitChainHeavy();
}
