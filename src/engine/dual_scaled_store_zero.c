/**
 * Auto-split from misc_matchesK.c
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
#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#endif


/* @addr 0x00491080 (43b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     ecx, [g_eventQueueIdx]
 *   mov     [eax*4 + 0x24], ecx
 *   mov     edx, [g_fightGroupHead]
 *   xor     eax, eax
 *   mov     [g_walkCallback], eax
 *   mov     [edx*4 + 0x28], eax
 *   jmp     T
 */
extern void ScaledLoadOrSetJmp(void);
void DualScaledStoreZero(void) {
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_end = g_xformEntityIdx;
    g_walkCallback = (void (*)(void))0;
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_idx = 0;
    ScaledLoadOrSetJmp();
}
