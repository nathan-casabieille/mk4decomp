/**
 * Auto-split from misc_matches5.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;

/* @addr 0x004314d0 (29b)
 *   mov     eax, [0x0052ab10]
 *   mov     ecx, 0xfffe8000
 *   mov     [g_fightGroupHead], eax
 *   mov     [g_walkCallback], ecx
 *   mov     [eax*4 + 0x58], ecx
 *   ret
 */
extern unsigned int g_load_0052ab10;
void LoadStoreScaled58_004314d0(void) {
    unsigned int idx = g_load_0052ab10;
    g_fightGroupHead = idx;
    g_walkCallback   = (void(*)(void))0xfffe8000;
    *(unsigned int *)(idx * 4 + 0x58) = 0xfffe8000;
}
