/**
 * Auto-split from misc_matchesA.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004c6820 (18b): forwarding wrapper push 0+0+arg+call */
extern int __cdecl BootFatalAbortHandler(int, int, int);
int PushZ2ArgCall(int x) {
    return BootFatalAbortHandler(x, 0, 0);
}
