/**
 * Auto-split from misc_matchesI.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00473450 (44b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     eax, [eax*4 + 0x18]
 *   test    eax, eax
 *   mov     [g_walkCallback], eax
 *   jne     +0x0d
 *   mov     eax, [g_xformDirtyFlags]
 *   and     al, 0xfe
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 *   mov     [g_scaledInit_00542044], eax
 *   jmp     +4
 */
extern void func_00473461(void);
void ScaledLoadDirtyOrSetJmp_00473450(void) {
    unsigned int v = *(unsigned int *)(g_fightGroupHead * 4 + 0x18);
    g_walkCallback = (void (*)(void))v;
    if (v == 0) {
        g_xformDirtyFlags = g_xformDirtyFlags & 0xfffffffeu;
        return;
    }
    g_scaledInit_00542044 = v;
    func_00473461();
}
