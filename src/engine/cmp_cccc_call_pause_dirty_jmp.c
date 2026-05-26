/**
 * Auto-split from misc_matchesV.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
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
extern void func_0048ec10(void);
extern void DualCallPauseJmpDual_00439190(void);
extern void CallPauseTestByteJmpCalls_004390f0(void);
extern void GuardedDirtyDispatch_00438c50(void);
void CmpccccCallPauseDirtyJmp_004390b0(void) {
    unsigned int v = g_table_00535ddc;
    g_walkCallback = (void (*)(void))v;
    if ((int)v > 0xcccc) {
        DualCallPauseJmpDual_00439190();
        return;
    }
    func_0048ec10();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 1) != 0) {
        GuardedDirtyDispatch_00438c50();
        return;
    }
    CallPauseTestByteJmpCalls_004390f0();
}
