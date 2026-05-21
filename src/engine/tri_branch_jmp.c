/**
 * Auto-split from misc_matchesG.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00434530 (34b)
 *   mov     eax, [g_state_0053a51c]
 *   cmp     eax, 8
 *   mov     [g_walkCallback], eax
 *   jne     +5
 *   jmp     T1
 *   test    eax, eax
 *   jne     +5
 *   jmp     T2
 *   jmp     +0x0e
 */
extern unsigned int g_state_0053a51c;
extern void func_00434983(void);
extern void func_004348e1(void);
extern void func_0043454c(void);
void TriBranchJmp_00434530(void) {
    unsigned int v = g_state_0053a51c;
    g_walkCallback = (void (*)(void))v;
    if (v == 8) {
        func_00434983();
        return;
    }
    if (v == 0) {
        func_004348e1();
        return;
    }
    func_0043454c();
}
