/**
 * Scaled-array increment-compare 2-way dispatcher.
 */
#include "engine/scenegraph.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_currentNodeIdx;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_eventQueueCurrent (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_fightGroupHead (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#endif


/* @addr 0x004297d0 (45b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     ecx, [g_currentNodeIdx]
 *   mov     eax, [eax*4 + 0x28]
 *   inc     eax
 *   mov     [g_eventQueueCurrent], eax
 *   mov     edx, [ecx*4 + 4]
 *   cmp     eax, edx
 *   jge     +5
 *   jmp     T1
 *   jmp     T2
 */
extern void ScaledStoreCurDirtyClear(void);
extern void ScaledLoadDecJmp(void);
void ScaledIncCmpJmp(void) {
    unsigned int idx;
    unsigned int scaled;
    unsigned int v;
    int cmp_val;
    idx = g_fightGroupHead;
    scaled = g_currentNodeIdx;
    v = ((ScenegraphNode *)(idx * 4))->queue_idx + 1;
    g_eventQueueCurrent = v;
    cmp_val = *(int *)(scaled * 4 + 4);
    if ((int)v < cmp_val) {
        ScaledStoreCurDirtyClear();
        return;
    }
    ScaledLoadDecJmp();
}
