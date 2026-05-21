/**
 * Auto-split from misc_matchesR.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

void StrSearchCall_004c89b0(char *arg1, int arg2) {
    if (arg2 == 0) return;
    func_004ca0a0(arg1 + arg2, arg1, strlen(arg1) + 1);
}
