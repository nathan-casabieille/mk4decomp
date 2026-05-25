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
extern int g_renderer1_active;
extern int g_renderer1_busy;
extern void (__stdcall *g_iat_007b0010)(int);
void Renderer1_PresentFrame(void) {
    if (g_renderer1_active == 0) {
        return;
    }
    if (g_renderer1_busy != 0) {
        return;
    }
    g_iat_007b0010(1);
}

