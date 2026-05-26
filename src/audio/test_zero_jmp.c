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
extern unsigned int g_dispatchSave_00543824;
extern void DualBitGateInitCall_0048a1c0(void);
void TestZeroJmp_004a42b0(void) {
    if (!g_dispatchSave_00543824) return;
    g_dispatchSave_00543824 = 0;
    DualBitGateInitCall_0048a1c0();
}
