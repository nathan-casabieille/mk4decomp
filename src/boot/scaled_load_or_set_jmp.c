/**
 * Auto-split from misc_matchesD.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x00406b20 (34b)
 *   mov     ecx, [g_fightGroupHead]
 *   mov     eax, [ecx*4 + 0x10]
 *   test    eax, eax
 *   mov     [g_walkCallback], eax
 *   jne     +0xb
 *   mov     [g_currentNodeIdx], ecx
 *   jmp     +0xf
 *   ret
 */
extern void MStackCall_MStackPush2ChainInsert_00406b50(void);
void ScaledLoadOrSetJmp(void) {
    unsigned int idx = g_fightGroupHead;
    unsigned int v = *(unsigned int *)(idx * 4 + 0x10);
    g_walkCallback = (void (*)(void))v;
    if (v) return;
    g_currentNodeIdx = idx;
    MStackCall_MStackPush2ChainInsert_00406b50();
}
