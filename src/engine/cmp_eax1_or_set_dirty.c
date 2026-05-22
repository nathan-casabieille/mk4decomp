/**
 * Auto-split from misc_matchesW.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern u32 g_eventQueueWorkType;
extern packed_ptr g_xformEntityIdx;

/* @addr 0x00488e90 (56b)
 *   mov     eax, [g_walkCallback]
 *   mov     ecx, 1
 *   cmp     eax, ecx
 *   jne     +7
 *   or      [g_xformDirtyFlags], ecx
 *   ret
 *   mov     eax, [g_state_00537f98]
 *   mov     [g_walkCallback], eax
 *   test    eax, eax
 *   mov     eax, [g_xformDirtyFlags]
 *   je      +8
 *   or      eax, ecx
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 *   and     al, 0xfe
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 */
extern unsigned int g_state_00537f98;

void CmpEax1OrSetDirty_00488e90(void) {
    __asm {
        mov     eax, dword ptr [g_walkCallback]
        mov     ecx, 1
        cmp     eax, ecx
        _emit   75h
        _emit   07h
        or      dword ptr [g_xformDirtyFlags], ecx
        ret
        mov     eax, dword ptr [g_state_00537f98]
        mov     dword ptr [g_walkCallback], eax
        test    eax, eax
        mov     eax, dword ptr [g_xformDirtyFlags]
        _emit   74h
        _emit   08h
        or      eax, ecx
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
        and     al, 0xfe
        mov     dword ptr [g_xformDirtyFlags], eax
        }
}

