/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;

/* @addr 0x00440990 (71b)
 *   call F1; if !pause: load g_scaledInit; copy [+0x24]→g_xformEntityIdx,
 *   [+0x28]→g_eventQueueIdx; eax = g_walkCallback;
 *   if eax == 2: jmp T (0x407030); else call F2; load pause; ret.
 */
extern void DirtyDoubleDeref(void);
extern void DispatcherComplex260_FramePauseScaledStore(void);
extern void DispatcherComplex260_MStackBracket1_TreeWalkRecursive2(void);
int GuardedCallStoreSlotsCmp(void) {
    unsigned int s;
    DirtyDoubleDeref();
    if (g_framePauseFlag != 0) return g_framePauseFlag;
    s = g_currentNodeIdx;
    g_xformEntityIdx = ((ScenegraphNode *)(s * 4))->queue_end;
    g_eventQueueIdx = ((ScenegraphNode *)(s * 4))->queue_idx;
    if ((unsigned int)g_walkCallback != 2) {
        DispatcherComplex260_FramePauseScaledStore();
        return g_framePauseFlag;
    }
    return ((int (*)(void))DispatcherComplex260_MStackBracket1_TreeWalkRecursive2)();
}
