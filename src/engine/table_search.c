/**
 * Auto-split from misc_matchesQ.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004be760 (46b)
 *   mov     ax, word ptr [esp+4]
 *   cmp     ax, 0x64
 *   jge     +0x20
 *   movsx   edx, ax
 *   xor     ecx, ecx
 *   mov     eax, 0x004f7d40
 * .loop:
 *   cmp     [eax], edx
 *   je      .found
 *   add     eax, 4
 *   inc     ecx
 *   cmp     eax, 0x004f7d80
 *   jl      .loop
 *   xor     eax, eax
 *   ret
 * .found:
 *   lea     eax, [ecx + 2]
 *   ret
 *   xor     eax, eax
 *   ret
 */
extern int g_orphanTbl_004f7d40[16];
#ifdef NON_MATCHING
#include "portable/mem_model.h"
/* @addr 0x004be760 (46b) - NATIVE twin.
 *
 * Linear search of the 16-entry sound-id table at 0x4f7d40 for the id
 * passed as a 16-bit argument. Returns the slot index PLUS TWO on a hit,
 * zero on a miss - and zero straight away for an id of 100 or more, which
 * is how the caller spells "not a table sound". */
int TableSearch(short id)
{
    unsigned int i;

    if (id >= 100) return 0;
    for (i = 0; i < 16; i++)
        if (*MK4_VA(int, 0x4f7d40u + i * 4u) == (int)id)
            return (int)i + 2;
    return 0;
}
#else
void TableSearch(void) {
    __asm {
        mov     ax, word ptr [esp + 4]
        cmp     ax, 0x64
        _emit   7dh
        _emit   20h
        movsx   edx, ax
        xor     ecx, ecx
        mov     eax, 0x004f7d40
        cmp     edx, dword ptr [eax]
        _emit   74h
        _emit   0eh
        add     eax, 4
        inc     ecx
        cmp     eax, 0x004f7d80
        _emit   7ch
        _emit   0f1h
        xor     eax, eax
        ret
        lea     eax, [ecx + 2]
        ret
        xor     eax, eax
        }
}
#endif
