/**
 * Auto-extracted during misc_matches reorganization.
 */
#include "engine/scenegraph.h"

/* @addr 0x004b21b0 (8b)
 *   mov     byte ptr [g_callocInitFlag], 0
 *   ret
 */
extern unsigned char g_callocInitFlag;
void AppInit_PostDSound(void) {
    g_callocInitFlag = 0;
}

