/**
 * Auto-extracted during misc_matches reorganization.
 */
#include "engine/scenegraph.h"

/* @addr 0x004b46d0 (27b)
 *   mov     eax, [g_X1]
 *   test    eax, eax
 *   je      .doit
 *   mov     eax, [g_X2]
 *   test    eax, eax
 *   jne     .ret
 * .doit:
 *   push    1
 *   call    [iat]
 * .ret:
 *   ret
 */
extern unsigned int g_state_007affe4;
extern unsigned int g_state_007afff0;
extern void (__stdcall *g_iat_007b0010)(int);
void Renderer1_PresentFrame(void) {
    if (g_state_007affe4 == 0) {
        return;
    }
    if (g_state_007afff0 != 0) {
        return;
    }
    g_iat_007b0010(1);
}

