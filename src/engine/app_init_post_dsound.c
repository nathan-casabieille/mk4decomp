/**
 * Auto-extracted during misc_matches reorganization.
 */
#include "engine/scenegraph.h"

/* @addr 0x004b21b0 (8b)
 *   mov     byte ptr [g_byte_007af508], 0
 *   ret
 */
extern unsigned char g_byte_007af508;
void AppInit_PostDSound(void) {
    g_byte_007af508 = 0;
}

