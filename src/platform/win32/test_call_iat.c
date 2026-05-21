/**
 * Auto-split from misc_matches9.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004c44f0 (18b)
 *   mov     eax, [g_state_00f9f008]
 *   test    eax, eax
 *   je      .ret
 *   push    1
 *   call    [iat]
 * .ret:
 *   ret
 */
extern unsigned int g_state_00f9f008;
extern void (__stdcall *g_iat_004d2220)(int);
void TestCallIat_004c44f0(void) {
    if (g_state_00f9f008 != 0) {
        g_iat_004d2220(1);
    }
}
