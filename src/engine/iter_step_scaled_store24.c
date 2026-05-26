/**
 * Auto-split from misc_matchesN.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00428730 (48b)
 *   mov     eax, [esp+4]
 *   sar     eax, 2
 *   mov     [g_eventQueueTotal], eax
 *   mov     ecx, [eax*4 + 0]
 *   inc     eax
 *   mov     [g_eventQueueTotal], eax
 *   mov     eax, [g_fightGroupHead]
 *   mov     [g_scaledInit_00542044], ecx
 *   mov     [eax*4 + 0x24], ecx
 *   jmp     T
 */
extern void func_00429868(void);
void IterStepScaledStore24_00428730(int arg) {
    unsigned int packed = (unsigned int)(arg >> 2);
    unsigned int v;
    g_eventQueueTotal = packed;
    v = *(unsigned int *)(packed * 4);
    packed++;
    g_eventQueueTotal = packed;
    g_scaledInit_00542044 = v;
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_end = v;
    func_00429868();
}
