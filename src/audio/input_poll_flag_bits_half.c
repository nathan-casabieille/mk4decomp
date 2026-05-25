/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x004a1b50 (76b)
 *   InputPollFlagBits sibling: same shape but probes different bits
 *   in [0x4d50b8] / [0x4d50b4]. Tests 0x20 (cl), then loads
 *   [0x4d50b4] AS a dword (uses ah for 0x40, 0x10, 0x20 high-byte
 *   tests), then cl bit 0x10. Final fallback: (cl & 0x40) >> 6.
 */
extern unsigned int g_byte_004d50b4;
extern unsigned int g_byte_004d50b8;

void InputPollFlagBitsHalf_004a1b50(void) {
    __asm {
        mov     cl, byte ptr [g_byte_004d50b8]
        test    cl, 0x20
        _emit   74h
        _emit   06h
        mov     eax, 1
        ret
        mov     eax, dword ptr [g_byte_004d50b4]
        test    ah, 0x40
        _emit   74h
        _emit   06h
        mov     eax, 1
        ret
        test    cl, 0x10
        _emit   74h
        _emit   06h
        mov     eax, 1
        ret
        test    ah, 0x10
        _emit   74h
        _emit   06h
        mov     eax, 1
        ret
        test    ah, 0x20
        _emit   74h
        _emit   06h
        mov     eax, 1
        ret
        movsx   eax, cl
        and     eax, 0x40
        shr     eax, 6
        }
}

