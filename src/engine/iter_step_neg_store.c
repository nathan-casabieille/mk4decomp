/**
 * Auto-split from misc_matchesK.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00490b10 (38b)
 *   mov     eax, [esp+4]
 *   sar     eax, 2
 *   mov     [g_eventQueueEnd], eax
 *   mov     ecx, [eax*4 + 0]
 *   inc     eax
 *   neg     ecx
 *   mov     [g_eventQueueEnd], eax
 *   mov     [g_walkCallback], ecx
 *   jmp     T
 */
extern void func_0049000a(void);
void IterStepNegStore_00490b10(int arg) {
    unsigned int packed = (unsigned int)(arg >> 2);
    int v;
    g_eventQueueEnd = packed;
    v = *(int *)(packed * 4);
    packed++;
    v = -v;
    g_eventQueueEnd = packed;
    g_walkCallback = (void (*)(void))v;
    func_0049000a();
}
