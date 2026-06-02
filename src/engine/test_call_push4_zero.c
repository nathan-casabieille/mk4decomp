/**
 * Auto-split from misc_matchesA.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004bd590 (30b): same shape with different addr
 *   mov     eax, [g_dispatchSave266]
 *   test    eax, eax
 *   je      .skip
 *   push    4
 *   call    F
 *   add     esp, 4
 * .skip:
 *   mov     [g_dispatchSave266], 0
 *   ret
 */
extern unsigned int g_dispatchSave266;
extern void PackedListVisitor(int);
void TestCallPush4Zero(void) {
    if (g_dispatchSave266 != 0) {
        PackedListVisitor(4);
        g_dispatchSave266 = 0;
    }
}
