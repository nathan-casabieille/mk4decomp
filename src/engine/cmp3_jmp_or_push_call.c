/**
 * Compare-state vs 3 + jmp-or-push-call dispatcher.
 */
#include "engine/scenegraph.h"

/* @addr 0x004338e0 (34b)
 *   mov     eax, [g_stateCountdown_0053a3c0]
 *   cmp     eax, 3
 *   mov     [g_walkCallback], eax
 *   jle     +5
 *   jmp     T1
 *   push    0x004e44c0
 *   call    F
 *   add     esp, 4
 *   ret
 */
extern unsigned int g_stateCountdown_0053a3c0;
extern void func_00433901(void);
extern int func_004392a0(void *);
extern void *g_dispatchSave1226_004e44c0;
void Cmp3JmpOrPushCall_004338e0(void) {
    int v = (int)g_stateCountdown_0053a3c0;
    g_walkCallback = (void (*)(void))v;
    if (v > 3) {
        func_00433901();
        return;
    }
    func_004392a0(&g_dispatchSave1226_004e44c0);
}
