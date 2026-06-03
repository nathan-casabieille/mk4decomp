/**
 * Auto-split from misc_matchesN.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x00446120 (46b)
 *   mov     eax, [g_eventQueueIdx]
 *   mov     [g_fightGroupHead], eax
 *   mov     eax, [g_baseSel]
 *   mov     ecx, [eax*4 + 0x78]
 *   mov     [g_eventQueueEnd], ecx
 *   mov     edx, [eax*4 + 0x5c]
 *   mov     [g_currentNodeIdx], edx
 *   jmp     T
 */
extern void PushPopScaled1cDoubleCall(void);
void CopyScaledTriple_00446120(void) {
    unsigned int base;
    g_fightGroupHead = g_eventQueueIdx;
    base = g_baseSel;
    g_xformEntityIdx = *(unsigned int *)(base * 4 + 0x78);
    g_currentNodeIdx = *(unsigned int *)(base * 4 + 0x5c);
    PushPopScaled1cDoubleCall();
}

/* @addr 0x00446350 (46b): same shape with offsets 0x5c->disp, 0x78->disp swapped */
extern void PushPopScaled1cDoubleCall(void);
void CopyScaledTriple_00446350(void) {
    unsigned int base = g_baseSel;
    g_currentNodeIdx = *(unsigned int *)(base * 4 + 0x5c);
    g_xformEntityIdx = *(unsigned int *)(base * 4 + 0x78);
    g_fightGroupHead = g_eventQueueEnd;
    PushPopScaled1cDoubleCall();
}
