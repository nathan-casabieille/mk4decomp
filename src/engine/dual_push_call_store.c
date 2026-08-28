/**
 * Auto-split from misc_matchesS.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
#endif

/* @addr 0x004231b0 (53b)
 *   push    3
 *   push    0x004234f0
 *   call    F
 *   mov     eax, [g_currentNodeIdx]
 *   add     esp, 8
 *   mov     [0x00538040], eax
 *   push    4
 *   push    0x00423570
 *   call    F
 *   mov     ecx, [g_currentNodeIdx]
 *   add     esp, 8
 *   mov     [0x00538044], ecx
 *   ret
 */
extern int StoreTwoCall(void *p, int n);
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern void *g_dispatchSave1138;
extern void *g_dispatchSave1139;
extern unsigned int g_dispatchSave99;
extern unsigned int g_dispatchSave98;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dispatchSave1138 (*(unsigned int *)MK4_VA(unsigned int, 0x4234f0u))
#define g_dispatchSave1139 (*(unsigned int *)MK4_VA(unsigned int, 0x423570u))
#define g_dispatchSave98 (*(unsigned int *)MK4_VA(unsigned int, 0x538044u))
#define g_dispatchSave99 (*(unsigned int *)MK4_VA(unsigned int, 0x538040u))
#endif

void DualPushCallStore(void) {
    StoreTwoCall(&g_dispatchSave1138, 3);
    g_dispatchSave99 = g_currentNodeIdx;
    StoreTwoCall(&g_dispatchSave1139, 4);
    g_dispatchSave98 = g_currentNodeIdx;
}
