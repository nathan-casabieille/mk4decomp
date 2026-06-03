/**
 * Auto-split from misc_matches8.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x0043d590 (5b) tail-jmp wrapper to CountdownStoreCallChain
 * (resolved via the CountdownStoreCallChain alias in extras_map -> 0x43d5a0). */
void TailJmpTo_CountdownStoreCallChain(void) {
    CountdownStoreCallChain();
}
