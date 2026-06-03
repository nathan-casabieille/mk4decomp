/**
 * Auto-split from misc_matchesHH.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x00424ba0 (65b)
 *   3-cell scaled-load test chain: deref [eax*4+0..8] in turn into walk;
 *   if any non-zero, jmp T1 else jmp T2.
 */
extern void IdentityMatrix(void);
extern void Mul10HeavyTransform(void);
void ScaledTestChainDispatch(void) {
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
                IdentityMatrix();
                return;
            }
        }
    }
    Mul10HeavyTransform();
}
