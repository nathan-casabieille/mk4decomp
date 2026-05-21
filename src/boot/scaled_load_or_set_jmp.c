/**
 * Auto-split from misc_matchesD.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00406b20 (34b)
 *   mov     ecx, [g_fightGroupHead]
 *   mov     eax, [ecx*4 + 0x10]
 *   test    eax, eax
 *   mov     [g_walkCallback], eax
 *   jne     +0xb
 *   mov     [g_scaledInit_00542044], ecx
 *   jmp     +0xf
 *   ret
 */
extern void func_00406b3a(void);
void ScaledLoadOrSetJmp_00406b20(void) {
    unsigned int idx = g_fightGroupHead;
    unsigned int v = *(unsigned int *)(idx * 4 + 0x10);
    g_walkCallback = (void (*)(void))v;
    if (v) return;
    g_scaledInit_00542044 = idx;
    func_00406b3a();
}
