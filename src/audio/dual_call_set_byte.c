/**
 * Auto-split from misc_matchesP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004a1cb0 (45b)
 *   call    F
 *   test    eax, eax
 *   je      +0x0b
 *   mov     eax, 1
 *   mov     byte ptr [0x00543590], al
 *   ret
 *   call    F2
 *   test    eax, eax
 *   je      +0x0d
 *   mov     byte ptr [0x00543590], 2
 *   mov     eax, 1
 *   ret
 *   xor     eax, eax
 *   ret
 */
extern int TripleByteCheck_004a1c50(void);
extern int func_004a1c70(void);
extern unsigned char g_byte_00543590;
int DualCallSetByte_004a1cb0(void) {
    if (TripleByteCheck_004a1c50() != 0) {
        g_byte_00543590 = 1;
        return 1;
    }
    if (func_004a1c70() != 0) {
        g_byte_00543590 = 2;
        return 1;
    }
    return 0;
}
