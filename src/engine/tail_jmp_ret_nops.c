/**
 * Auto-split from misc_matchesA.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004bd5d0 (5b) tail-jmp wrapper. */
extern void LoadGeoAsset_Default(void);
void TailJmpRetNops(void) {
    LoadGeoAsset_Default();
}
