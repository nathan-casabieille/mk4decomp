/**
 * Auto-split from misc_matchesW.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0045e590 (55b)
 *   mov     eax, [g_table_00535ddc]
 *   cmp     eax, 0x1cccc
 *   mov     [g_walkCallback], eax
 *   jge     +0x0d
 *   mov     eax, [g_xformDirtyFlags]
 *   and     al, 0xfe
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 *   cmp     eax, 0x30000
 *   jle     +0x0d
 *   mov     eax, [g_xformDirtyFlags]
 *   and     al, 0xfe
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 *   jmp     +0x79
 */
extern unsigned int g_state_00535ddc_w;
extern void func_0045e60c(void);
void RangeCheckJmp_0045e590(void) {
    int v = (int)g_state_00535ddc_w;
    g_walkCallback = (void (*)(void))v;
    if (v < 0x1cccc) {
        g_xformDirtyFlags = g_xformDirtyFlags & 0xfffffffeu;
        return;
    }
    if (v > 0x30000) {
        g_xformDirtyFlags = g_xformDirtyFlags & 0xfffffffeu;
        return;
    }
    func_0045e60c();
}
