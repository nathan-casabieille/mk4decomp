/**
 * Auto-split from misc_matchesA.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004c6820 (18b): forwarding wrapper push 0+0+arg+call */
extern int __cdecl BootFatalAbortHandler_004c6860(int, int, int);
int PushZ2ArgCall_004c6820(int x) {
    return BootFatalAbortHandler_004c6860(x, 0, 0);
}
