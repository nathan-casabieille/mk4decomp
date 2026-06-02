/**
 * Auto-split from misc_matchesV.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_acc_00542078;

/* @addr 0x004390b0 (56b)
 *   mov     eax, [g_table_00535ddc]
 *   cmp     eax, 0xcccc
 *   mov     [g_walkCallback], eax
 *   jle     +5
 *   jmp     +0xca
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   test    byte [g_xformDirtyFlags], 1
 *   je      +5
 *   jmp     T
 *   jmp     +9
 *   ret
 */
extern unsigned int g_table_00535ddc;
extern void Wrapper_0048ec20(void);
extern void DualCallPauseJmpDual(void);
extern void CallPauseTestByteJmpCalls(void);
extern void GuardedDirtyDispatch(void);
void CmpccccCallPauseDirtyJmp(void) {
    unsigned int v = g_table_00535ddc;
    g_walkCallback = (void (*)(void))v;
    if ((int)v > 0xcccc) {
        DualCallPauseJmpDual();
        return;
    }
    Wrapper_0048ec20();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 1) != 0) {
        GuardedDirtyDispatch();
        return;
    }
    CallPauseTestByteJmpCalls();
}
