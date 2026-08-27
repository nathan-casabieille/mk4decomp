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
extern unsigned int g_dispatchSave1583;
extern unsigned int g_dispatchSave1582;
#endif
#ifdef NON_MATCHING
extern void SetHi6(unsigned int *hdr, unsigned int lo6);
extern void StoreAtMinus8(int *hdr, int va);
#else
extern void SetHi6(void);
extern void StoreAtMinus8(void);
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dispatchSave1582 (*(unsigned int *)MK4_VA(unsigned int, 0xab5200u))
#define g_dispatchSave1583 (*(unsigned int *)MK4_VA(unsigned int, 0xab5204u))
#define g_dispatchSave1654 (*(unsigned int *)MK4_VA(unsigned int, 0x7b41a8u))
#define g_memHeapStart ((unsigned char *)MK4_VA(unsigned char, 0x7b41a0u))
#endif


#include "portable/mem_model.h"

#ifndef NON_MATCHING   /* the native build takes the twin in src/game/table_search_asc.c */
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

/* @addr 0x004bd530 (56b)
 *   if (arg && *arg) {
 *     call free([*arg], 4); call free([*arg], &g_dispatchSave1583);
 *     g_dispatchSave1582 = 1; *arg = 0;
 *   }
 */
#endif

#ifdef NON_MATCHING
/* Already pure C in the matching build; the only reason this file was not in
 * the native source list is the naked AppInit_Misc2 above it. The second
 * argument is an owner-slot VA, not a host pointer, so it goes through
 * MK4_UNPTR. */
void CleanupCallTwice(unsigned int *arg) {
    if (*arg != 0) {
        /* *arg is a stored 32-bit slot, so it holds a VA; both helpers
         * dereference their first argument, so it has to come back through
         * the seam. The second is an owner-slot VA and stays one. */
        SetHi6(MK4_VA(unsigned int, *arg), 4);
        StoreAtMinus8(MK4_VA(int, *arg), (int)MK4_UNPTR(&g_dispatchSave1583));
        g_dispatchSave1582 = 1;
        *arg = 0;
    }
}
#else
void CleanupCallTwice(int *arg) {
    if (*arg != 0) {
        SetHi6(*arg, 4);
        StoreAtMinus8(*arg, (int)&g_dispatchSave1583);
        g_dispatchSave1582 = 1;
        *arg = 0;
    }
}
#endif
