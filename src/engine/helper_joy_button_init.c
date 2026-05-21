/**
 * Auto-extracted during misc_matches reorganization.
 */
#include "engine/scenegraph.h"

/* @addr 0x004b5450 (18b)
 *   mov     eax, [esp+4]
 *   push    eax
 *   call    [iat]
 *   shr     eax, 0xf
 *   and     eax, 1
 *   ret
 */
extern unsigned int (__stdcall *g_iat_004d21c0)(int);
int Helper_JoyButtonInit(int arg) {
    return (g_iat_004d21c0(arg) >> 15) & 1;
}

