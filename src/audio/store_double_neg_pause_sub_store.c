/**
 * Auto-split from misc_matchesBB.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004ab750 (62b)
 *   load walk; store g_state_00538130; double eax; if neg → neg eax;
 *   store walk; call F; pause-test → ret;
 *   load g_state_00538130 - walk → walk.
 */
extern unsigned int g_state_00538130;
extern void AudioMixerStep_004ab700(void);
void StoreDoubleNegPauseSubStore_004ab750(void) {
    int saved;
    int v;
    saved = (int)g_walkCallback;
    g_state_00538130 = (unsigned int)saved;
    v = saved + saved;
    g_walkCallback = (void (*)(void))v;
    if (v < 0) {
        v = -v;
        g_walkCallback = (void (*)(void))v;
    }
    AudioMixerStep_004ab700();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = (void (*)(void))((unsigned int)g_walkCallback - g_state_00538130);
}
