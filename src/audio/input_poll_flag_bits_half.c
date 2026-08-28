/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_currentNodeIdx;
#endif

/* @addr 0x004a1b50 (76b)
 *   InputPollFlagBits sibling: same shape but probes different bits
 *   in [0x4d50b8] / [0x4d50b4]. Tests 0x20 (cl), then loads
 *   [0x4d50b4] AS a dword (uses ah for 0x40, 0x10, 0x20 high-byte
 *   tests), then cl bit 0x10. Final fallback: (cl & 0x40) >> 6.
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_audioStateDisp50b4;
extern unsigned int g_audioStateMask50b8;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_audioStateDisp50b4 (*(unsigned int *)MK4_VA(unsigned int, 0x4d50b4u))
#define g_audioStateMask50b8 (*(unsigned int *)MK4_VA(unsigned int, 0x4d50b8u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#endif


#ifdef NON_MATCHING
#include "portable/mem_model.h"
/* @addr 0x004a1b50 (76b) - NATIVE twin, the sister of InputPollFlagBits
 * one bit-position up: pad-byte bits 5 and 4, and the SECOND byte of the
 * state dword (ah) bits 6, 4 and 5 - i.e. 0x4000/0x1000/0x2000 of the
 * dword at 0x4d50b4. The fall-through returns pad bit 6. */
int InputPollFlagBitsHalf(void)
{
    unsigned char c = *MK4_VA(unsigned char, 0x4d50b8u);
    unsigned int  v = *MK4_VA(unsigned int, 0x4d50b4u);

    if (c & 0x20)      return 1;
    if (v & 0x4000u)   return 1;
    if (c & 0x10)      return 1;
    if (v & 0x1000u)   return 1;
    if (v & 0x2000u)   return 1;
    return ((int)(signed char)c & 0x40) >> 6;
}
#else
void InputPollFlagBitsHalf(void) {
    __asm {
        mov     cl, byte ptr [g_audioStateMask50b8]
        test    cl, 0x20
        _emit   74h
        _emit   06h
        mov     eax, 1
        ret
        mov     eax, dword ptr [g_audioStateDisp50b4]
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
#endif

