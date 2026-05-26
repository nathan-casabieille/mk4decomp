/**
 * Auto-split from misc_matches9.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004be610 (18b)
 *   call    F
 *   xor     eax, eax
 *   mov     [g_X1], eax
 *   mov     [g_X2], eax
 *   ret
 */
extern void Loop16Init_004c4370(void);
extern unsigned int g_zero_00541fa8;
extern unsigned int g_zero_00541fa4;
void CallZero2_004be610(void) {
    Loop16Init_004c4370();
    g_zero_00541fa8 = 0;
    g_zero_00541fa4 = 0;
}
