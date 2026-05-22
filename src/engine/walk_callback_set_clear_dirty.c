/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_state_004d57ac;
extern unsigned int g_scaledInit_00542044;
extern u32 g_eventQueueWorkType;
extern packed_ptr g_xformEntityIdx;
extern u32 g_eventQueueEnd;
extern u32 g_tickW1;
extern packed_ptr g_fightGroupHead;

/* @addr 0x0048e7d0 (66b)
 *   Switch on g_walkCallback: if it equals one of {0x2001, 0x2010,
 *   0x2002, 0x106, 0x107}, set bit 0 of g_xformDirtyFlags; else
 *   clear bit 0. Two distinct return paths.
 */

void WalkCallbackSetClearDirty_0048e7d0(void) {
    __asm {
        mov     eax, dword ptr [g_walkCallback]
        cmp     eax, 0x2001
        _emit   74h
        _emit   1ch
        cmp     eax, 0x2010
        _emit   74h
        _emit   15h
        cmp     eax, 0x2002
        _emit   74h
        _emit   0eh
        cmp     eax, 0x106
        _emit   74h
        _emit   07h
        cmp     eax, 0x107
        _emit   75h
        _emit   0dh
        mov     eax, dword ptr [g_xformDirtyFlags]
        or      al, 1
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
        mov     eax, dword ptr [g_xformDirtyFlags]
        and     al, 0xfe
        mov     dword ptr [g_xformDirtyFlags], eax
        }
}

