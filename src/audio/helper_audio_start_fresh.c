/**
 * Auto-extracted during misc_matches reorganization.
 */
#include "engine/scenegraph.h"

/* @addr 0x004c4360 (13b)
 *   call    F
 *   mov     byte ptr [g_audioMute], 1
 *   ret
 */
extern void Helper_TitleAudioStop(void);
extern unsigned char g_audioMute;
void Helper_AudioStartFresh(void) {
    Helper_TitleAudioStop();
    g_audioMute = 1;
}

