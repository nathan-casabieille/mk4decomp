/**
 * Auto-split from misc_matchesM.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

typedef unsigned int (*DivLongFn)(int, int, __int64);
extern void func_004cb680(void);

void DivLongPushCall_004ab320(void) {
    int v = (int)g_walkCallback;
    if (v == 0) {
        g_walkCallback = (void (*)(void))v;
        return;
    }
    g_walkCallback = (void (*)(void))((DivLongFn)func_004cb680)(0, 1, (__int64)v);
}
