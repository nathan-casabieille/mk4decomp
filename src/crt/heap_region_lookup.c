/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004c7370 (89b crt) - heap region lookup: walks linked list at
 *   0x520130 to find which heap region contains the pointer in [esp+4].
 *   On match (16-byte aligned, page-offset >= 0x100): returns metadata ptr;
 *   else: returns 0.
 */
void* HeapRegionLookup_004c7370(void) {
    __asm {
        mov     ecx, dword ptr [esp + 4]
        mov     eax, 0x520130
loop4c7370:
        cmp     ecx, [eax + 0x10]
        _emit   76h
        _emit   05h
        cmp     ecx, [eax + 0x14]
        _emit   72h
        _emit   0bh
        mov     eax, [eax]
        cmp     eax, 0x520130
        _emit   74h
        _emit   3ah
        _emit   0ebh
        _emit   0ebh
        test    cl, 0xf
        _emit   75h
        _emit   33h
        mov     edx, ecx
        and     edx, 0xfff
        cmp     edx, 0x100
        _emit   72h
        _emit   23h
        mov     edx, dword ptr [esp + 8]
        mov     [edx], eax
        mov     edx, dword ptr [esp + 0xc]
        mov     eax, ecx
        and     eax, 0xfffff000
        sub     ecx, eax
        mov     [edx], eax
        sub     ecx, 0x100
        sar     ecx, 4
        lea     eax, [ecx + eax + 8]
        ret
        xor     eax, eax
        }
}

