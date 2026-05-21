/**
 * Auto-split from misc_matchesA.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004bd5d0 (5b) tail-jmp wrapper. */
extern void LoadGeoAsset_Default(void);
void TailJmpRetNops_004bd5d0(void) {
    LoadGeoAsset_Default();
}
