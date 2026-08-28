/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_currentNodeIdx;
#endif

/* @addr 0x004a1b00 (74b)
 *   Input poll: if (byte_4d50b8 & 0x02) → 1;
 *               if (byte_4d50b4 & 0x40) → 1;
 *               if (byte_4d50b8 & 0x01) → 1;
 *               if (byte_4d50b4 & 0x10) → 1;
 *               if (byte_4d50b4 & 0x20) → 1;
 *               else (byte_4d50b8 & 0x04) >> 2 (0 or 1).
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned char g_audioStateMask50b8;
extern unsigned char g_audioStateDisp50b4;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_audioStateDisp50b4 (*(unsigned char *)MK4_VA(unsigned char, 0x4d50b4u))
#define g_audioStateMask50b8 (*(unsigned char *)MK4_VA(unsigned char, 0x4d50b8u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#endif

#ifdef NON_MATCHING
#include "portable/mem_model.h"
/* @addr 0x004a1b00 (74b) - NATIVE twin. Any of the five "a button is
 * down" bits reports 1: bits 1 and 0 of the pad byte 0x4d50b8, bits 6, 4
 * and 5 of the state byte 0x4d50b4. The fall-through returns bit 2 of the
 * pad byte, sign-extended then shifted - the same 0/1. */
int InputPollFlagBits(void)
{
    unsigned char a = *MK4_VA(unsigned char, 0x4d50b8u);
    unsigned char c = *MK4_VA(unsigned char, 0x4d50b4u);

    if (a & 2)    return 1;
    if (c & 0x40) return 1;
    if (a & 1)    return 1;
    if (c & 0x10) return 1;
    if (c & 0x20) return 1;
    return ((int)(signed char)a & 4) >> 2;
}
#else
void InputPollFlagBits(void) {
    __asm {
        mov     al, byte ptr [g_audioStateMask50b8]
        test    al, 2
        _emit   74h
        _emit   06h
        mov     eax, 1
        ret
        mov     cl, byte ptr [g_audioStateDisp50b4]
        test    cl, 0x40
        _emit   74h
        _emit   06h
        mov     eax, 1
        ret
        test    al, 1
        _emit   74h
        _emit   06h
        mov     eax, 1
        ret
        test    cl, 0x10
        _emit   74h
        _emit   06h
        mov     eax, 1
        ret
        test    cl, 0x20
        _emit   74h
        _emit   06h
        mov     eax, 1
        ret
        movsx   eax, al
        and     eax, 4
        shr     eax, 2
        }
}
#endif
