/**
 * Auto-split from misc_matchesR.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_dispatchSave1433;
extern unsigned int g_dispatchSave1435;
extern unsigned int g_dispatchSave1467;
extern unsigned int g_dispatchSave1436;
extern unsigned int g_dispatchSave1437;
extern unsigned int g_dispatchSave1438;
extern unsigned int g_dispatchSave1439;

void InitGlobalsAndZero(void) {
    memset(&g_dispatchSave1433, 0, 0x40 * 4 + 1);
    g_dispatchSave1435 = 0;
    g_dispatchSave1467 = 0;
    g_dispatchSave1436 = 0;
    g_dispatchSave1437 = 0;
    g_dispatchSave1438 = 0;
    g_dispatchSave1439 = 0;
}
