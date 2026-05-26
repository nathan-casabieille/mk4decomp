/**
 * Auto-split from misc_matches8.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0043d590 (5b) tail-jmp wrapper to CountdownStoreCallChain_0043d5a0
 * (resolved via the CountdownStoreCallChain_0043d5a0 alias in extras_map -> 0x43d5a0). */
void TailJmpTo_0043d5a0(void) {
    CountdownStoreCallChain_0043d5a0();
}
