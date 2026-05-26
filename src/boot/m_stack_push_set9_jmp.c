/**
 * Auto-split from misc_matchesD.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00413040 (39b)
 *   mov     eax, [g_matrixStackTop]
 *   mov     ecx, [g_fightGroupHead]
 *   inc     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], ecx
 *   mov     [g_walkCallback], 9
 *   jmp     T
 */
extern void Phase4StateInit4Helpers_004130c0(void);
void MStackPushSet9Jmp_00413040(void) {
    unsigned int top = g_matrixStackTop;
    unsigned int v = g_fightGroupHead;
    top++;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = v;
    g_walkCallback = (void (*)(void))9;
    Phase4StateInit4Helpers_004130c0();
}
