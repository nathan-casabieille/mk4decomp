/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"
#include "engine/geo.h"     /* g_memHeapStart / g_memHeapEnd */

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_currentNodeIdx;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_memHeapEnd ((unsigned int *)MK4_VA(unsigned int, 0xab4194u))
#define g_memHeapStart ((unsigned int *)MK4_VA(unsigned int, 0x7b41a0u))
#endif


/* @addr 0x004b5c90 (80b)
 *   Walks a packed list at 0x7b41a0 (entries 12+ bytes each):
 *   each entry's first dword has top-2-bit flag (0xc0000000 →
 *   skip) and a 24-bit "next-offset". When passing target arg,
 *   match if 0xff (any) or if (entry.tag6bit) == arg.
 *   Calls helper(entry+0xc) on match. Loops until offset
 *   exceeds 0xab4194.
 */
extern void Mem_Free(void *);
#ifdef NON_MATCHING
#include "portable/mem_model.h"
/* Portable twin (was a raw Ghidra lift; three 64-bit defects fixed).
 *
 *  - the walk stepped with `(int)puVar2 + delta`, which truncates an arena
 *    pointer on a 64-bit host; it strides in BYTES off a char pointer now.
 *  - entry[1] and the word it points at are stored VAs, so both need the
 *    MK4_PTR seam rather than being used as host pointers directly.
 *  - the bound was written `&g_memHeapEnd`; as an arena alias - and in the
 *    co-exec harness's generated defines - the name IS the address, so taking
 *    its address again reads the VALUE stored there instead. Indexing element
 *    zero is what makes both spellings resolve to the address.
 *
 * Per entry: skip if either of the top two bits is set; otherwise match when
 * the arg is 0xffffffff (any) or equals the 6-bit tag in bits 24..29. On a
 * match free entry[1]'s target if it is non-null, else the entry body at
 * +0x0c. The next entry is the 24-bit offset in the first dword. */
void PackedListVisitor(uint param_1)
{
    uint *entry = (uint *)&g_memHeapStart[0];
    uint *end   = (uint *)&g_memHeapEnd[0];

    do {
        if ((*entry & 0xc0000000) == 0 &&
            (param_1 == 0xffffffff || param_1 == (*entry >> 0x18 & 0x3f))) {
            uint  slot = entry[1];
            uint  val  = slot ? *(uint *)MK4_PTR(slot) : 0;

            Mem_Free(val ? MK4_PTR(val) : (void *)(entry + 3));
        }
        entry = (uint *)((unsigned char *)entry + (*entry & 0xffffff));
    } while (entry < end);
}
#else
__declspec(naked) void PackedListVisitor(void) {
    __asm {
        push    esi
        push    edi
        mov     edi, dword ptr [esp + 0x0c]
        mov     esi, OFFSET g_memHeapStart
loop_top:
        mov     eax, dword ptr [esi]
        test    eax, 0xc0000000
        _emit   75h
        _emit   28h
        cmp     edi, -1
        _emit   74h
        _emit   0ah
        shr     eax, 0x18
        and     eax, 0x3f
        cmp     edi, eax
        _emit   75h
        _emit   19h
        mov     eax, dword ptr [esi + 4]
        test    eax, eax
        _emit   74h
        _emit   06h
        mov     eax, dword ptr [eax]
        test    eax, eax
        _emit   75h
        _emit   03h
        lea     eax, [esi + 0x0c]
        push    eax
        call    Mem_Free
        add     esp, 4
        mov     eax, dword ptr [esi]
        and     eax, 0xffffff
        add     esi, eax
        cmp     esi, 0x00ab4194
        jb      loop_top
        pop     edi
        pop     esi
        ret
    }
}
#endif
