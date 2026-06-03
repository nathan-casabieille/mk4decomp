/**
 * Auto-split from misc_matchesG.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004398f0 (38b)
 *   mov     eax, [g_baseSel]
 *   mov     eax, [eax*4 + 0x74]
 *   cmp     eax, 0x200e
 *   mov     [g_eventQueueWorkType], eax
 *   je      .skip
 *   xor     eax, eax
 *   ret
 * .skip:
 *   call    F
 *   mov     eax, 1
 *   ret
 */
extern void Thunk_GuardedSeq(void);
int ScaledCmp200eCallBool(void) {
    unsigned int v = ((ScenegraphNode *)(g_baseSel * 4))->fsm_state;
    g_eventQueueNotMask = v;
    if (v != 0x200e) return 0;
    Thunk_GuardedSeq();
    return 1;
}
