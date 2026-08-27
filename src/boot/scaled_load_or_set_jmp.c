/**
 * Auto-split from misc_matchesD.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_fightGroupHead (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif


/* @addr 0x00406b20 (34b)
 *   mov     ecx, [g_fightGroupHead]
 *   mov     eax, [ecx*4 + 0x10]
 *   test    eax, eax
 *   mov     [g_walkCallback], eax
 *   jne     +0xb
 *   mov     [g_currentNodeIdx], ecx
 *   jmp     +0xf
 *   ret
 */
extern void MStackCall_MStackPush2ChainInsert_00406b50(void);
void ScaledLoadOrSetJmp(void) {
    unsigned int idx = g_fightGroupHead;
    unsigned int v = *(unsigned int *)MK4_PTR((idx * 4 + 0x10));
    g_walkCallback = (void (*)(void))v;
    if (v) return;
    g_currentNodeIdx = idx;
    MStackCall_MStackPush2ChainInsert_00406b50();
}
