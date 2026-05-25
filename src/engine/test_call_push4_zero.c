/**
 * Auto-split from misc_matchesA.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004bd590 (30b): same shape with different addr
 *   mov     eax, [g_dispatchSave266_0052ab00]
 *   test    eax, eax
 *   je      .skip
 *   push    4
 *   call    F
 *   add     esp, 4
 * .skip:
 *   mov     [g_dispatchSave266_0052ab00], 0
 *   ret
 */
extern unsigned int g_dispatchSave266_0052ab00;
extern void func_004b5c80(int);
void TestCallPush4Zero_004bd590(void) {
    if (g_dispatchSave266_0052ab00 != 0) {
        func_004b5c80(4);
        g_dispatchSave266_0052ab00 = 0;
    }
}
