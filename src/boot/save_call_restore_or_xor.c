/**
 * Auto-split from misc_matchesHH.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00404a00 (77b)
 *   save g_walkCallback into esi, write arg → walk; call F; pause-test → ret;
 *   load dirty | 4; mov ax,4; restore walk = esi;
 *   if (g_scaledInit != 0) dirty ^= 4 (clear it again); store dirty; ret.
 */
extern void MStackPush2LLWalkCompare_004069b0(void);
void SaveCallRestoreOrXor_00404a00(int arg) {
    void (*save)(void) = g_walkCallback;
    g_walkCallback = (void (*)(void))arg;
    MStackPush2LLWalkCompare_004069b0();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = save;
    g_xformDirtyFlags |= 4;
    if (g_scaledInit_00542044 != 0) {
        g_xformDirtyFlags = g_xformDirtyFlags ^ 4;
    }
}
