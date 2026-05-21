/**
 * Auto-split from misc_matchesN.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00446120 (46b)
 *   mov     eax, [g_eventQueueIdx]
 *   mov     [g_fightGroupHead], eax
 *   mov     eax, [g_baseSel_00542060]
 *   mov     ecx, [eax*4 + 0x78]
 *   mov     [g_eventQueueEnd], ecx
 *   mov     edx, [eax*4 + 0x5c]
 *   mov     [g_scaledInit_00542044], edx
 *   jmp     T
 */
extern void func_00405e90(void);
void CopyScaledTriple_00446120(void) {
    unsigned int base;
    g_fightGroupHead = g_eventQueueIdx;
    base = g_baseSel_00542060;
    g_eventQueueEnd = *(unsigned int *)(base * 4 + 0x78);
    g_scaledInit_00542044 = *(unsigned int *)(base * 4 + 0x5c);
    func_00405e90();
}

/* @addr 0x00446350 (46b): same shape with offsets 0x5c->disp, 0x78->disp swapped */
extern void func_00405ce0(void);
void CopyScaledTriple_00446350(void) {
    unsigned int base = g_baseSel_00542060;
    g_scaledInit_00542044 = *(unsigned int *)(base * 4 + 0x5c);
    g_eventQueueIdx = *(unsigned int *)(base * 4 + 0x78);
    g_fightGroupHead = g_eventQueueEnd;
    func_00405ce0();
}
