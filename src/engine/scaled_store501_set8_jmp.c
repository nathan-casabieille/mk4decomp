/**
 * Auto-split from misc_matchesD.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0042c390 (31b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     [eax*4 + 0x74], 0x501
 *   mov     [g_walkCallback], 8
 *   jmp     T
 */
extern void ScaledLitLoadCall_00481020(void);
void ScaledStore501Set8Jmp_0042c390(void) {
    ((ScenegraphNode *)(g_baseSel_00542060 * 4))->fsm_state = 0x501;
    g_walkCallback = (void (*)(void))8;
    ScaledLitLoadCall_00481020();
}
