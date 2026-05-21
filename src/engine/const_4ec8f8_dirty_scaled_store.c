/**
 * Const 0x004ec8f8 packed-init + dirty-guarded scaled store.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00446580 (56b)
 *   mov     eax, 0x004ec8f8
 *   shr     eax, 2
 *   mov     [g_xformEntityIdx], eax
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   test    byte [g_xformDirtyFlags], 4
 *   jne     +0x13
 *   mov     ecx, [g_baseSel_00542060]
 *   mov     edx, [g_scaledInit_00542044]
 *   mov     [ecx*4 + 0x60], edx
 *   ret
 */
extern packed_ptr g_xformEntityIdx;
extern void FramePauseScaledStore_00406c10(void);
extern int g_data_004ec8f8;
void Const4ec8f8DirtyScaledStore_00446580(void) {
    g_xformEntityIdx = ((unsigned int)&g_data_004ec8f8) >> 2;
    FramePauseScaledStore_00406c10();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 4) != 0) return;
    *(unsigned int *)(g_baseSel_00542060 * 4 + 0x60) = g_scaledInit_00542044;
}
