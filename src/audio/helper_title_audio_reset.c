/**
 * Auto-extracted during misc_matches reorganization.
 */
#include "engine/scenegraph.h"

/* @addr 0x004b5840 (11b)
 *   mov     [g_dispatchSave1323], 1
 *   ret
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_dispatchSave1323;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_dispatchSave1323 (*(unsigned int *)MK4_VA(unsigned int, 0x4f4e98u))
#endif

void Helper_TitleAudioReset(void) {
    g_dispatchSave1323 = 1;
}

