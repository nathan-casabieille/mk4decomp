/**
 * Auto-split from misc_matches9.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004be610 (18b)
 *   call    F
 *   xor     eax, eax
 *   mov     [g_X1], eax
 *   mov     [g_X2], eax
 *   ret
 */
extern void Loop16Init(void);
extern unsigned int g_armedReloadB;
extern unsigned int g_armedReloadA;
void CallZero2(void) {
    Loop16Init();
    g_armedReloadB = 0;
    g_armedReloadA = 0;
}
