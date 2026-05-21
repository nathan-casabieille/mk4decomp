/**
 * Auto-split from misc_matchesM.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004a1d20 (45b)
 *   mov     eax, [0x004d50b4]
 *   test    eax, eax
 *   jne     +0x1e
 *   mov     eax, [0x004d50b8]
 *   test    eax, eax
 *   jne     +0x15
 *   mov     eax, [0x004d50c0]
 *   test    eax, eax
 *   jne     +0x0c
 *   mov     eax, [0x004d50bc]
 *   test    eax, eax
 *   jne     +3
 *   xor     eax, eax
 *   ret
 *   mov     eax, 1
 *   ret
 */
extern unsigned int g_state_004d50b8;
extern unsigned int g_state_004d50c0;
extern unsigned int g_state_004d50bc;
int Test4StatesAny_004a1d20(void) {
    if (g_state_004d50b4 || g_state_004d50b8 || g_state_004d50c0 || g_state_004d50bc) {
        return 1;
    }
    return 0;
}
