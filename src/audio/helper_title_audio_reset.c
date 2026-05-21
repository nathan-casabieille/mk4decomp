/**
 * Auto-extracted during misc_matches reorganization.
 */
#include "engine/scenegraph.h"

/* @addr 0x004b5840 (11b)
 *   mov     [g_state_004f4e98], 1
 *   ret
 */
extern unsigned int g_state_004f4e98;
void Helper_TitleAudioReset(void) {
    g_state_004f4e98 = 1;
}

