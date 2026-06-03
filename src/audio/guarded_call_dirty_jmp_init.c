/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;

/* @addr 0x004a19c0 (74b)
 *   walk = g_eventQueueEnd; if non-zero: push 0x25b, call F1;
 *   if (dirty & 4): jmp T1; else
 *   ecx = g_scaledInit; walk = 0x50000; [ecx*4+0x6c] = 0x50000;
 *   jmp T2.  If walk was 0: jmp T3.
 */
extern void PushCallTestByte4Jmp(void);
extern void SaveCallRestoreOrXor(int);
extern void InstallSelfPauseGate(void);
void GuardedCallDirtyJmpInit(void) {
    unsigned int v = g_eventQueueEnd;
    g_walkCallback = (void (*)(void))v;
    if (v == 0) {
        PushCallTestByte4Jmp();
        return;
    }
    SaveCallRestoreOrXor(0x25b);
    if ((g_xformDirtyFlags & 4) != 0) {
        func_0041f780_pp();
        return;
    }
    g_walkCallback = (void (*)(void))0x00050000;
    *(unsigned int *)(g_currentNodeIdx * 4 + 0x6c) = 0x00050000;
    InstallSelfPauseGate();
}
