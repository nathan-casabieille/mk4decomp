/**
 * Auto-split from misc_matches7.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004a42b0 (25b)
 *   mov     eax, [g_X]
 *   test    eax, eax
 *   je      .ret
 *   mov     [g_X], 0
 *   jmp     T
 *   ret
 */
extern unsigned int g_state_00543824;
extern void func_0048a1ad(void);
void TestZeroJmp_004a42b0(void) {
    if (!g_state_00543824) return;
    g_state_00543824 = 0;
    func_0048a1ad();
}
