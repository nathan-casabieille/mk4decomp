/**
 * Auto-split from misc_matchesDD.c
 */
#include "engine/scenegraph.h"
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
#define g_memHeapStart ((unsigned char *)MK4_VA(unsigned char, 0x7b41a0u))
#define g_xformDirtyFlags (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#endif

#ifndef NON_MATCHING   /* the native build takes the twin in cleanup_call_twice.c */
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

/* @addr 0x004be210 (52b)
 *   scaled load; 16-bit neg of 3 word fields at offsets 0,2,4;
 *   set g_xformDirtyFlags |= 0x30.
 */
#ifdef NON_MATCHING
#include "portable/mem_model.h"

/* Already pure C in the matching build; only the raw VA arithmetic needs the
 * memory-model seam. The three words are read and written out of order in the
 * original - they do not alias, so the order is cosmetic and kept as-is. */
void ScaledNegThreeWords(void) {
    short *v = MK4_NODE(short, g_currentNodeIdx);
    short a = v[0];
    short b = v[1];
    short c;

    a = (short)-(int)a;
    v[0] = a;
    c = v[2];
    b = (short)-(int)b;
    c = (short)-(int)c;
    v[1] = b;
    v[2] = c;
    g_xformDirtyFlags |= 0x30;
}
#else
void ScaledNegThreeWords(void) {
    unsigned int idx;
    short a;
    short b;
    short c;
    idx = g_currentNodeIdx * 4;
    a = *(short *)(idx);
    b = *(short *)(idx + 2);
    a = (short)-(int)a;
    *(short *)(idx) = a;
    c = *(short *)(idx + 4);
    b = (short)-(int)b;
    c = (short)-(int)c;
    *(short *)(idx + 2) = b;
    *(short *)(idx + 4) = c;
    g_xformDirtyFlags |= 0x30;
}
#endif
