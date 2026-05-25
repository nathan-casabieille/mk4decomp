/**
 * Auto-split from misc_matchesM.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004a7db0 (38b)
 *   mov     eax, [0x004f3ae4]
 *   mov     ecx, [0x0054359c]
 *   dec     eax
 *   cmp     ecx, eax
 *   jge     +9
 *   mov     eax, ecx
 *   inc     eax
 *   mov     [0x0054359c], eax
 *   ret
 *   mov     eax, [g_xformDirtyFlags]
 *   or      al, 1
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 */
extern int g_state_004f3ae4;
extern int g_counter_0054359c;
void IncBoundedDirty_004a7db0(void) {
    if (g_counter_0054359c < g_state_004f3ae4 - 1) {
        g_counter_0054359c = g_counter_0054359c + 1;
    } else {
        g_xformDirtyFlags |= 1;
    }
}
