/**
 * Auto-split from misc_matchesI.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004708a0 (31b)
 *   mov     eax, [g_xformEntityIdx]
 *   mov     [eax*4 + 0x5c], 0xc
 *   mov     [g_walkCallback], 0x58
 *   jmp     T
 */
extern void func_0048a000(void);
void ScaledStoreCSet58Jmp_004708a0(void) {
    *(unsigned int *)(g_xformEntityIdx * 4 + 0x5c) = 0x0c;
    g_walkCallback = (void (*)(void))0x58;
    func_0048a000();
}
