/**
 * Auto-split from misc_matchesA.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004b1de0 (29b)
 *   mov     eax, [g_state_007af4e0]
 *   test    eax, eax
 *   je      .skip
 *   push    eax
 *   call    F
 *   add     esp, 4
 * .skip:
 *   mov     [g_state_007af4e0], 0
 *   ret
 */
extern unsigned int g_state_007af4e0;
extern void Helper_FClose(void *p);
void TestCallZero_004b1de0(void) {
    void *v = (void *)g_state_007af4e0;
    if (v != 0) {
        Helper_FClose(v);
    }
    g_state_007af4e0 = 0;
}
