/**
 * Auto-split from misc_matches4.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004089c0 (29b)
 *   call    Setup
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     ret_label
 *   test    byte [g_xformDirtyFlags], 4
 *   jne     ret_label
 *   jmp     Tail
 *   ret
 */
extern void MStackBracket4_ListInsertZeroFill_00408600(void);
extern void MStackPush3LinkedListWalk_004088b0(void);
void GDispatch4_004089c0(void) {
    MStackBracket4_ListInsertZeroFill_00408600();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 4) return;
    MStackPush3LinkedListWalk_004088b0();
}
