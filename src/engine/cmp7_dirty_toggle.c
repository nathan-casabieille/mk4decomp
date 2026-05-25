/**
 * Compare-state==7 dirty bit-0 toggle.
 */
#include "engine/scenegraph.h"

/* @addr 0x0042ee10 (36b)
 *   mov     eax, [0x0052aac4]
 *   mov     [g_walkCallback], eax
 *   cmp     eax, 7
 *   mov     eax, [g_xformDirtyFlags]
 *   je      +8
 *   and     al, 0xfe
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 *   or      al, 1
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 */
extern unsigned int g_tickFlagF;
void Cmp7DirtyToggle_0042ee10(void) {
    unsigned int state = g_tickFlagF;
    g_walkCallback = (void (*)(void))state;
    if (state != 7) {
        g_xformDirtyFlags = g_xformDirtyFlags & 0xFFFFFFFEu;
        return;
    }
    g_xformDirtyFlags = g_xformDirtyFlags | 1;
}
