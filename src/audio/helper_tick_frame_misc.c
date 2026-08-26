/**
 * Auto-extracted during misc_matches reorganization.
 */
#include "engine/scenegraph.h"

/* @addr 0x004a1d50 (48b)
 *   8-iteration loop reading triplets from [0x004f2fd4 - 4 ..],
 *   writing AND-NOT result into [src1] and replacing [src2] with NOT(src1).
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_tickFrameMiscTriplets[];
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_tickFrameMiscTriplets ((unsigned int *)MK4_VA(unsigned int, 0x4f2fd4u))
#endif


#ifdef NON_MATCHING
#include "portable/mem_model.h"
/* Portable twin. The table is 8 consecutive {A, B, C} triplets of VAs, and
 * ecx starts at the MIDDLE slot of the first one, so the asm reads A at
 * [ecx-4], B at [ecx+0], C at [ecx+4] and strides 12. Per triplet:
 *     *B = ~*A & ~*C ;  *C = ~*A
 * Both loads happen before either store (the asm does the same), so the
 * aliasing cases behave identically. The stored words are VAs, hence the
 * MK4_PTR deref rather than a host pointer. */
void Helper_TickFrame_Misc(void)
{
    int i;

    for (i = 0; i < 8; i++) {
        unsigned int *tri = &g_tickFrameMiscTriplets[3 * i];
        unsigned int na = ~*(unsigned int *)MK4_PTR(tri[-1]);
        unsigned int nc = ~*(unsigned int *)MK4_PTR(tri[1]);
        *(unsigned int *)MK4_PTR(tri[0]) = na & nc;
        *(unsigned int *)MK4_PTR(tri[1]) = na;
    }
}
#else
void Helper_TickFrame_Misc(void) {
    __asm {
        mov     ecx, OFFSET g_tickFrameMiscTriplets
        mov     esi, 8
loop_start:
        mov     eax, dword ptr [ecx - 4]
        mov     edx, dword ptr [ecx + 4]
        add     ecx, 0x0c
        mov     eax, dword ptr [eax]
        mov     edi, dword ptr [edx]
        not     eax
        not     edi
        mov     ebx, eax
        and     ebx, edi
        mov     edi, dword ptr [ecx - 0x0c]
        dec     esi
        mov     dword ptr [edi], ebx
        mov     dword ptr [edx], eax
        _emit   75h
        _emit   0e1h
        }
}
#endif
