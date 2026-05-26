/**
 * Auto-split from misc_matchesM.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

typedef unsigned int (__stdcall *DivLongFn)(int, int, __int64);
extern void Alldiv_004c5690(void);

void DivLongPushCall_004ab320(void) {
    int v = (int)g_walkCallback;
    if (v == 0) {
        g_walkCallback = (void (*)(void))v;
        return;
    }
    g_walkCallback = (void (*)(void))((DivLongFn)Alldiv_004c5690)(0, 1, (__int64)v);
}
