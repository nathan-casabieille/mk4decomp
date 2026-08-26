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

#ifdef NON_MATCHING
#include "portable/mem_model.h"
/* Portable twin - heap init, and the format matches Mem_Free's exactly:
 * clear the whole 3 MB region (0xc0000 dwords from g_memHeapStart), point the
 * first block's back link at itself, then stamp its header FREE with the whole
 * region as its size. The `mov eax, [heap]` is read AFTER the clear, so it is
 * reading zero; the and/or chain is kept as written because that is what the
 * original computes. */
void AppInit_Misc2(void)
{
    unsigned int *heap = (unsigned int *)MK4_VA(unsigned int, 0x007b41a0u);
    unsigned int  i, v;

    for (i = 0; i < 0xc0000u; i++)
        heap[i] = 0;
    v = heap[0];
    *(unsigned int *)MK4_VA(unsigned int, 0x007b41a8u) = 0x007b41a0u;
    heap[0] = ((v & 0xff2ffff4u) | 0x002ffff4u) | 0x80000000u;
}
#else
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

/* @addr 0x004b6300 (58b)
 *   table search ascending from arg+1; clamps arg < -1 to -1; returns count
 *   of contiguous valid entries (each 8 bytes; .second must equal 1, .next != 0).
 */
#ifdef NON_MATCHING
/* Portable twin. Entries are 8 bytes: [+0] non-zero means "present", [+4] is a
 * s16 that is 1 for a selectable row. Walk forward from cur + 1 and return the
 * first index whose row is NOT selectable; walking off the end of the table
 * returns cur unchanged, NOT the last index visited (the original falls out of
 * the loop into `mov eax, edx`).
 *
 * The menu pointer is a `void *`, not the `int` Ghidra emitted: the caller
 * hands over an arena address, which does not survive a 32-bit round trip on a
 * 64-bit host. */
int Menu_FindNextSelectable(int cur, void *menu)
{
    unsigned char *e;
    int i;

    if (cur < -1)
        cur = -1;
    i = cur + 1;
    e = (unsigned char *)menu + i * 8;
    if (*(int *)e == 0)
        return cur;
    for (;;) {
        if (*(short *)(e + 4) != 1)
            return i;
        if (*(int *)(e + 8) == 0)
            return cur;
        e += 8;
        i++;
    }
}
#else
__declspec(naked) void Menu_FindNextSelectable(void) {
    __asm {
        mov     edx, dword ptr [esp + 4]
        push    esi
        cmp     edx, 0xffffffff
        push    edi
        _emit   7dh
        _emit   03h
        or      edx, 0xffffffff
        mov     ecx, dword ptr [esp + 0x10]
        lea     eax, [edx + 1]
        mov     esi, dword ptr [ecx + eax*8]
        lea     ecx, [ecx + eax*8]
        test    esi, esi
        _emit   74h
        _emit   16h
        mov     esi, 1
        cmp     word  ptr [ecx + 4], si
        _emit   75h
        _emit   0dh
        mov     edi, dword ptr [ecx + 8]
        add     ecx, 8
        inc     eax
        test    edi, edi
        _emit   75h
        _emit   0efh
        mov     eax, edx
        pop     edi
        pop     esi
        ret
    }
}
#endif
