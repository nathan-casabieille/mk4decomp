/**
 * Auto-split from misc_matchesI.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x00476e00 (32b)
 *   mov     ecx, [g_currentNodeIdx]
 *   mov     eax, [ecx*4 + 0x20]
 *   or      al, 4
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x20], eax
 *   jmp     T
 */
extern void CondInstallDispatch_00476e20(void);
void ScaledOr4Jmp(void) {
    unsigned int scaled = g_currentNodeIdx;
    unsigned int v = ((ScenegraphNode *)(scaled * 4))->flags | 4;
    g_walkCallback = (void (*)(void))v;
    ((ScenegraphNode *)(scaled * 4))->flags = v;
    CondInstallDispatch_00476e20();
}

/* @addr 0x00476fe0 (32b): same shape, and al, 0xfb */
extern void CondInstallDispatch_00477000(void);
void ScaledAndFBJmp(void) {
    unsigned int scaled = g_currentNodeIdx;
    unsigned int v = ((ScenegraphNode *)(scaled * 4))->flags & 0xfffffffbu;
    g_walkCallback = (void (*)(void))v;
    ((ScenegraphNode *)(scaled * 4))->flags = v;
    CondInstallDispatch_00477000();
}
