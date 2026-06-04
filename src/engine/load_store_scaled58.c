/**
 * Auto-split from misc_matches5.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel;

/* @addr 0x004314d0 (29b)
 *   mov     eax, [0x0052ab10]
 *   mov     ecx, 0xfffe8000
 *   mov     [g_fightGroupHead], eax
 *   mov     [g_walkCallback], ecx
 *   mov     [eax*4 + 0x58], ecx
 *   ret
 */
extern unsigned int g_eventQueueSeed;
void LoadStoreScaled58(void) {
    unsigned int idx = g_eventQueueSeed;
    g_fightGroupHead = idx;
    g_walkCallback   = (void(*)(void))0xfffe8000;
    ((ScenegraphNode *)(idx * 4))->position_y = (s32)0xfffe8000;
}
