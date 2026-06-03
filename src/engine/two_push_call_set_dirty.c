/**
 * Auto-split from misc_matchesD.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

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
extern void *g_dispatchSave1148;
extern void *g_dispatchSave1137;
void TwoPushCallSetDirty(void) {
    func_0049cb40_t(&g_dispatchSave1148, 0x29);
    func_0049cb40_t(&g_dispatchSave1137, 0x2c);
    g_xformDirtyFlags = g_xformDirtyFlags | 1;
}
