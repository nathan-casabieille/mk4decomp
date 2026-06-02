/**
 * Auto-split from misc_matchesR.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;

void StrSearchCall(char *arg1, int arg2) {
    if (arg2 == 0) return;
    CrtMemMove(arg1 + arg2, arg1, strlen(arg1) + 1);
}
