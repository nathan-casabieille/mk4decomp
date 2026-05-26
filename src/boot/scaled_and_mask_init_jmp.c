/**
 * Auto-split from misc_matchesT.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00405a00 (59b)
 *   mov     eax, [g_scaledInit_00542044]
 *   mov     edx, [eax*4 + 0x20]
 *   and     dl, 0x7f
 *   mov     [eax*4 + 0x20], edx
 *   mov     eax, [g_scaledInit_00542044]
 *   mov     [g_walkCallback], 0x00405a00
 *   mov     eax, [eax*4 + 0]
 *   test    eax, eax
 *   mov     [g_eventQueueCurrent], eax
 *   je      +5
 *   jmp     +0xb5456
 *   ret
 */
extern void func_004bae62(void);
extern void ScaledAndMaskInitJmp_00405a00(void);
void ScaledAndMaskInitJmp_00405a00(void) {
    unsigned int v;
    ((ScenegraphNode *)(g_scaledInit_00542044 * 4))->flags &= 0xffffff7fu;
    g_walkCallback = (void (*)(void))&ScaledAndMaskInitJmp_00405a00;
    v = *(unsigned int *)(g_scaledInit_00542044 * 4);
    g_eventQueueCurrent = v;
    if (v == 0) return;
    func_004bae62();
}
