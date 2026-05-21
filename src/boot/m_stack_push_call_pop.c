/**
 * Auto-split from misc_matchesS.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0040a830 (54b)
 *   mov     eax, [g_matrixStackTop]
 *   mov     ecx, [g_eventQueueEnd]
 *   inc     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], ecx
 *   call    F
 *   mov     eax, [g_matrixStackTop]
 *   mov     edx, [eax*4 + 0]
 *   dec     eax
 *   mov     [g_eventQueueEnd], edx
 *   mov     [g_matrixStackTop], eax
 *   ret
 */
extern void func_0040a888(void);
void MStackPushCallPop_0040a830(void) {
    g_matrixStackTop++;
    *(unsigned int *)(g_matrixStackTop * 4) = g_eventQueueEnd;
    func_0040a888();
    g_eventQueueEnd = *(unsigned int *)(g_matrixStackTop * 4);
    g_matrixStackTop--;
}
