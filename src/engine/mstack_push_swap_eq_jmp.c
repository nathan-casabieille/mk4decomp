/**
 * 2 "matrix-stack push + swap + equality flag + tail-jmp" (70 bytes).
 *
 * Pattern:
 *   mov     eax, [g_matrixStackTop]
 *   mov     ecx, [g_eventQueueCurrent]
 *   inc     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], ecx                  ; push current
 *   mov     edx, [g_dlNalt1]
 *   mov     eax, [g_player1NodeIdx]
 *   mov     [g_eventQueueCurrent], edx        ; install nalt1
 *   mov     edx, [g_Y]                        ; per-helper
 *   xor     ecx, ecx
 *   cmp     eax, edx
 *   mov     [g_walkCallback], eax
 *   sete    cl
 *   mov     [g_eq_00542098], ecx
 *   jmp     Tail
 */
#include "engine/scenegraph.h"
#include "game/tick.h"
#include "game/statemachine.h"

extern unsigned int g_eq_00542098;

extern void StateSwitchMStackPop_00474f20(void);

/* @addr 0x00474e80 */
void MStackPushSwapEqJmp_00474e80(void) {
    unsigned int p;
    g_matrixStackTop++;
    *(unsigned int *)(g_matrixStackTop * 4) = g_eventQueueCurrent;
    g_eventQueueCurrent = g_dlNalt1;
    p = g_player1NodeIdx;
    g_walkCallback = (void (*)(void))p;
    g_eq_00542098 = (p == g_eventQueueEnd) ? 1 : 0;
    StateSwitchMStackPop_00474f20();
}

/* @addr 0x00474ed0 */
void MStackPushSwapEqJmp_00474ed0(void) {
    unsigned int p;
    g_matrixStackTop++;
    *(unsigned int *)(g_matrixStackTop * 4) = g_eventQueueCurrent;
    g_eventQueueCurrent = g_dlNalt1;
    p = g_player1NodeIdx;
    g_walkCallback = (void (*)(void))p;
    g_eq_00542098 = (p == g_eventQueueIdx) ? 1 : 0;
    StateSwitchMStackPop_00474f20();
}
