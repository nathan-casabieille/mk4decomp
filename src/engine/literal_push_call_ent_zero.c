/**
 * Auto-split from misc_matchesJ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
#endif

/* @addr 0x00488c00 (37b)
 *   mov     eax, 0x00500d4c
 *   push    0x004ef1f8
 *   shr     eax, 2
 *   mov     [g_xformEntityIdx], eax
 *   mov     [g_walkCallback], 0
 *   call    F
 *   add     esp, 4
 *   ret
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern void *g_dispatchSave1314;
#endif
extern int Cascade5StageInit(void *);
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern int g_dispatchSave406;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dispatchSave1314 (*(unsigned int *)MK4_VA(unsigned int, 0x4ef1f8u))
#define g_dispatchSave406 (*(int *)MK4_VA(int, 0x500d4cu))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#endif

void LiteralPushCallEntZero(void) {
    g_xformEntityIdx = ((unsigned int)&g_dispatchSave406) >> 2;
    g_walkCallback = (void (*)(void))0;
    Cascade5StageInit(&g_dispatchSave1314);
}
