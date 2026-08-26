/**
 * Auto-split from misc_matchesDD.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
#endif

/* @addr 0x004b5a80 (52b)
 *   rep stos zero-fill 0xc0000 dwords starting at 0x007b41a0;
 *   then mask + or bits, set [0x007b41a8] = 0x007b41a0 (self-link list head).
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern u8 g_memHeapStart[];
extern unsigned int g_dispatchSave1654;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dispatchSave1654 (*(unsigned int *)MK4_VA(unsigned int, 0x7b41a8u))
#define g_memHeapStart (*(unsigned char *)MK4_VA(unsigned char, 0x7b41a0u))
#endif

/* Both auto-split halves of misc_matchesDD.c carry this same function. The
 * matching build tolerates the pair, but linking two definitions natively is a
 * duplicate symbol, so the portable one lives in table_search_asc.c and this
 * copy is matching-only. */
#ifndef NON_MATCHING
__declspec(naked) void AppInit_Misc2(void) {
    __asm {
        push    edi
        mov     ecx, 0xc0000
        xor     eax, eax
        mov     edi, OFFSET g_memHeapStart
        rep stosd
        mov     eax, dword ptr [g_memHeapStart]
        mov     dword ptr [g_dispatchSave1654], OFFSET g_memHeapStart
        and     eax, 0xff2ffff4
        pop     edi
        or      eax, 0x002ffff4
        or      eax, 0x80000000
        mov     dword ptr [g_memHeapStart], eax
        ret
    }
}
#endif

/* @addr 0x004b62c0 (55b)
 *   table search descending from arg-1; each entry is 8 bytes.
 *   while (eax >= 0 && tab[eax].first != 0) { if (tab[eax].second != 1) break; eax--; }
 *   complex tail computing the final index.
 */
#ifdef NON_MATCHING
/* Portable twin - the mirror of Menu_FindNextSelectable, walking down from
 * cur - 1. Falling off the bottom returns 0 when cur < 1 and cur otherwise:
 * `setl al ; dec eax ; and eax, edx` builds a 0 / all-ones mask from that test.
 *
 * The menu pointer is a `void *`, not the `int` Ghidra emitted - an arena
 * address does not survive a 32-bit round trip on a 64-bit host. */
int Menu_FindPrevSelectable(int cur, void *menu)
{
    unsigned char *e;
    int i = cur - 1;

    if (i >= 0) {
        e = (unsigned char *)menu + i * 8;
        while (*(int *)e != 0) {
            if (*(short *)(e + 4) != 1)
                return i;
            i--;
            e -= 8;
            if (i < 0)
                break;
        }
    }
    return cur < 1 ? 0 : cur;
}
#else
__declspec(naked) void Menu_FindPrevSelectable(void) {
    __asm {
        mov     edx, dword ptr [esp + 4]
        push    esi
        mov     esi, 1
        lea     eax, [edx - 1]
        test    eax, eax
        _emit   7ch
        _emit   1ah
        mov     ecx, dword ptr [esp + 0x0c]
        lea     ecx, [ecx + eax*8]
        cmp     dword ptr [ecx], 0
        _emit   74h
        _emit   0eh
        cmp     word  ptr [ecx + 4], si
        _emit   75h
        _emit   12h
        dec     eax
        sub     ecx, 8
        test    eax, eax
        _emit   7dh
        _emit   0edh
        xor     eax, eax
        cmp     edx, esi
        setl    al
        dec     eax
        and     eax, edx
        pop     esi
        ret
    }
}
#endif
