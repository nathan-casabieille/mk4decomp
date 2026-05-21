/**
 * Auto-split from misc_matchesQ.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004c5660 (48b)
 *   cmp     cl, 0x40
 *   jae     +0x16
 *   cmp     cl, 0x20
 *   jae     +6
 *   shrd    eax, edx, cl
 *   shr     edx, cl
 *   ret
 *   mov     eax, edx
 *   sar     edx, 0x1f
 *   and     cl, 0x1f
 *   shr     eax, cl
 *   ret
 *   sar     edx, 0x1f
 *   mov     eax, edx
 *   ret
 *   nop * 12  (alignment)
 */
__declspec(naked) void Sar64_004c5660(void) {
    __asm {
        cmp     cl, 0x40
        _emit   73h
        _emit   16h
        cmp     cl, 0x20
        _emit   73h
        _emit   06h
        shrd    eax, edx, cl
        sar     edx, cl
        ret
        mov     eax, edx
        sar     edx, 0x1f
        and     cl, 0x1f
        sar     eax, cl
        ret
        sar     edx, 0x1f
        mov     eax, edx
        ret
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
        _emit   0cch
    }
}
