/**
 * Compare-state vs 3 + jmp-or-push-call dispatcher.
 */
#include "engine/scenegraph.h"

/* @addr 0x004338e0 (34b)
 *   mov     eax, [g_stateCountdown]
 *   cmp     eax, 3
 *   mov     [g_walkCallback], eax
 *   jle     +5
 *   jmp     T1
 *   push    0x004e44c0
 *   call    F
 *   add     esp, 4
 *   ret
 */
extern unsigned int g_stateCountdown;
extern void CallPauseDirtyLit_00433910(void);
extern int PackedAdvanceCallTailJmp(void *);
extern void *g_dispatchSave1226_004e44c0;
void Cmp3JmpOrPushCall(void) {
    int v = (int)g_stateCountdown;
    g_walkCallback = (void (*)(void))v;
    if (v > 3) {
        CallPauseDirtyLit_00433910();
        return;
    }
    PackedAdvanceCallTailJmp(&g_dispatchSave1226_004e44c0);
}
