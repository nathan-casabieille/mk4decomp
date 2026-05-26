/**
 * Auto-split from misc_matchesP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0048f8e0 (48b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     ecx, [eax*4 + 0x3c]
 *   mov     [g_scaledInit_00542044], ecx
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +0x0f
 *   mov     [g_scaledInit_00542044], 0x0048fa20
 *   jmp     T
 *   ret
 */
extern void Thunk_0049cbd0(void);
extern void MStackPush4IndirectCall_0048fd60(void);
void ScaledChainCallPauseSetJmp_0048f8e0(void) {
    g_scaledInit_00542044 = ((ScenegraphNode *)(g_baseSel_00542060 * 4))->child_a;
    Thunk_0049cbd0();
    if (g_framePauseFlag != 0) return;
    g_scaledInit_00542044 = 0x0048fa20;
    MStackPush4IndirectCall_0048fd60();
}
