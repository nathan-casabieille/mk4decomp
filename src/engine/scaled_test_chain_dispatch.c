/**
 * Auto-split from misc_matchesHH.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern packed_ptr g_xformEntityIdx;
extern unsigned int g_state_004d57ac;
extern packed_ptr g_fightGroupHead;
extern u32 g_eventQueueWorkType;
extern u32 g_pendingNodeType;

/* @addr 0x00424ba0 (65b)
 *   3-cell scaled-load test chain: deref [eax*4+0..8] in turn into walk;
 *   if any non-zero, jmp T1 else jmp T2.
 */
extern void IdentityMatrix_00424b70(void);
extern void Mul10HeavyTransform_00424bf0(void);
void ScaledTestChainDispatch_00424ba0(void) {
    unsigned int *p = (unsigned int *)(g_xformEntityIdx * 4);
    unsigned int v = p[0];
    g_walkCallback = (void (*)(void))v;
    if (v == 0) {
        v = p[1];
        g_walkCallback = (void (*)(void))v;
        if (v == 0) {
            v = p[2];
            g_walkCallback = (void (*)(void))v;
            if (v == 0) {
                IdentityMatrix_00424b70();
                return;
            }
        }
    }
    Mul10HeavyTransform_00424bf0();
}
