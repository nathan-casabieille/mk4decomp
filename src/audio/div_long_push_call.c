/**
 * Auto-split from misc_matchesM.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

typedef unsigned int (__stdcall *DivLongFn)(int, int, __int64);
extern void Alldiv(void);

void DivLongPushCall(void) {
    int v = (int)g_walkCallback;
    if (v == 0) {
        g_walkCallback = (void (*)(void))v;
        return;
    }
    g_walkCallback = (void (*)(void))((DivLongFn)Alldiv)(0, 1, (__int64)v);
}
