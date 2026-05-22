/**
 * Auto-split from misc_matchesR.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_data_00f9f8c0;
extern unsigned int g_state_00f9fac8;
extern unsigned int g_state_00fa0dc4;
extern unsigned int g_state_00f9facc;
extern unsigned int g_state_00f9fad0;
extern unsigned int g_state_00f9fad4;
extern unsigned int g_state_00f9fad8;

void InitGlobalsAndZero_004c9800(void) {
    memset(&g_data_00f9f8c0, 0, 0x40 * 4 + 1);
    g_state_00f9fac8 = 0;
    g_state_00fa0dc4 = 0;
    g_state_00f9facc = 0;
    g_state_00f9fad0 = 0;
    g_state_00f9fad4 = 0;
    g_state_00f9fad8 = 0;
}
