/**
 * Auto-split from misc_matchesG.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004398f0 (38b)
 *   mov     eax, [g_baseSel_00542060]
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
extern void func_00439998(void);
int ScaledCmp200eCallBool_004398f0(void) {
    unsigned int v = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x74);
    g_eventQueueNotMask = v;
    if (v != 0x200e) return 0;
    func_00439998();
    return 1;
}
