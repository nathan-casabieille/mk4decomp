/**
 * Auto-split from misc_matchesD.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0042c390 (31b)
 *   mov     eax, [g_baseSel]
 *   mov     [eax*4 + 0x74], 0x501
 *   mov     [g_walkCallback], 8
 *   jmp     T
 */
extern void ScaledLitLoadCall_ScaledChainCallPauseSetJmp_then_Wrapper_IterLoad_0048fd30_00481020(void);
void ScaledStore501Set8Jmp(void) {
    ((ScenegraphNode *)(g_baseSel * 4))->fsm_state = 0x501;
    g_walkCallback = (void (*)(void))8;
    ScaledLitLoadCall_ScaledChainCallPauseSetJmp_then_Wrapper_IterLoad_0048fd30_00481020();
}
