/**
 * Auto-split from misc_matches6.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00490330 (28b): scaled and ah, 0xdf */
void ScaledAndAhdf_00490330(void) {
    unsigned int idx = g_fightGroupHead;
    unsigned int v = *(unsigned int *)(idx * 4 + 0x40) & 0xFFFFFFDFu;
    g_eventQueueCurrent = v;
    *(unsigned int *)(idx * 4 + 0x40) = v;
}

/* @addr 0x00490350 (28b): scaled and ah, 0xbf */
void ScaledAndAhbf_00490350(void) {
    unsigned int idx = g_fightGroupHead;
    unsigned int v = *(unsigned int *)(idx * 4 + 0x40) & 0xFFFFFFBFu;
    g_eventQueueCurrent = v;
    *(unsigned int *)(idx * 4 + 0x40) = v;
}

/* @addr 0x00490370 (28b): scaled and ah, 0xfb */
void ScaledAndAhfb_00490370(void) {
    unsigned int idx = g_fightGroupHead;
    unsigned int v = *(unsigned int *)(idx * 4 + 0x40) & 0xFFFFFFFBu;
    g_eventQueueCurrent = v;
    *(unsigned int *)(idx * 4 + 0x40) = v;
}

/* @addr 0x00490390 (28b): scaled and ah, 0xfe */
void ScaledAndAhfe_00490390(void) {
    unsigned int idx = g_fightGroupHead;
    unsigned int v = *(unsigned int *)(idx * 4 + 0x40) & 0xFFFFFFFEu;
    g_eventQueueCurrent = v;
    *(unsigned int *)(idx * 4 + 0x40) = v;
}

/* @addr 0x00490720 (30b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     ecx, [eax*4 + 0x48]
 *   mov     [g_walkCallback], ecx
 *   mov     [eax*4 + 0x58], ecx
 *   jmp     +2
 */
extern void ScaledZeroFour_00490740(void);
void ScaledMove48to58_00490720(void) {
    packed_ptr fg = g_fightGroupHead;
    unsigned int v = *(unsigned int *)(fg * 4 + 0x48);
    g_walkCallback = (void (*)(void))v;
    ((ScenegraphNode *)(fg * 4))->position_y = v;
    ScaledZeroFour_00490740();
}
