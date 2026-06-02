/**
 * Auto-split from misc_matchesQ.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004c45c0 (5b) tail-jmp wrapper to CallThreeSumLea
 * (resolved via the CallThreeSumLea alias in extras_map -> 0x4c45d0). */
void TailJmpTo_CallThreeSumLea(void) {
    CallThreeSumLea();
}
