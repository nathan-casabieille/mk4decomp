/**
 * Push-arg call + pause-check + clear dirty bit 0.
 */
#include "engine/scenegraph.h"

/* @addr 0x0042c9c0 (35b)
 *   push    0x004e3540
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   add     esp, 4
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, [g_xformDirtyFlags]
 *   and     al, 0xfe
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 */
extern int ArgSarStoreJmp_004594f0(void *);
extern void *g_data_004e3540;
void PushCallPauseDirtyClear_0042c9c0(void) {
    ArgSarStoreJmp_004594f0(&g_data_004e3540);
    if (g_framePauseFlag != 0) return;
    g_xformDirtyFlags = g_xformDirtyFlags & 0xFFFFFFFEu;
}
