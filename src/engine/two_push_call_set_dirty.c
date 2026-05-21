/**
 * Auto-split from misc_matchesD.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00422050 (43b)
 *   push    0x29
 *   push    0x004573e0
 *   call    F1
 *   add     esp, 8
 *   push    0x2c
 *   push    0x00422200
 *   call    F1
 *   mov     eax, [g_xformDirtyFlags]
 *   add     esp, 8
 *   or      al, 1
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 */
extern int func_0049cb40_t(void *, int);
extern void *g_data_004573e0;
extern void *g_data_00422200;
void TwoPushCallSetDirty_00422050(void) {
    func_0049cb40_t(&g_data_004573e0, 0x29);
    func_0049cb40_t(&g_data_00422200, 0x2c);
    g_xformDirtyFlags = g_xformDirtyFlags | 1;
}
