/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x00440990 (71b)
 *   call F1; if !pause: load g_scaledInit; copy [+0x24]→g_xformEntityIdx,
 *   [+0x28]→g_eventQueueIdx; eax = g_walkCallback;
 *   if eax == 2: jmp T (0x407030); else call F2; load pause; ret.
 */
extern void DirtyDoubleDeref_00408cb0(void);
extern void DispatcherComplex260_00407400(void);
extern void DispatcherComplex260_00407030(void);
int GuardedCallStoreSlotsCmp_00440990(void) {
    unsigned int s;
    DirtyDoubleDeref_00408cb0();
    if (g_framePauseFlag != 0) return g_framePauseFlag;
    s = g_scaledInit_00542044;
    g_xformEntityIdx = *(unsigned int *)(s * 4 + 0x24);
    g_eventQueueIdx = *(unsigned int *)(s * 4 + 0x28);
    if ((unsigned int)g_walkCallback != 2) {
        DispatcherComplex260_00407400();
        return g_framePauseFlag;
    }
    return ((int (*)(void))DispatcherComplex260_00407030)();
}
