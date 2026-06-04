/**
 * Naked: two-register load-shr-store interleave (orig schedules both
 * loads first, then both shifts, then both stores via eax AND ecx).
 * MSVC SP3 pure C reuses eax for both values, losing the interleave.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x00433e50 (32b)
 *   mov     eax, [g_eventQueueCurrent]
 *   mov     ecx, 0x004e4cf8
 *   shr     eax, 8
 *   shr     ecx, 2
 *   mov     [g_eventQueueCurrent], eax
 *   mov     [g_xformEntityIdx], ecx
 *   jmp     AddDerefJmp
 */
extern void AddDerefJmp(void);
#ifdef NON_MATCHING
/* Portable: shift the queue cursor, store the packed-ptr of 0x004e4cf8
 * (addr >> 2) into the xform index, then tail-call AddDerefJmp (the orig
 * `jmp`). Matching keeps the two-register load/shr/store interleave that
 * MSVC SP3 will not emit from C (see #else).
 * NOTE: 0x004e4cf8 is an absolute VA; Phase 1 (memory model) will route
 * it through GLOBAL()/packed-ptr translation for non-flat targets. */
void ShrShrStoreJmp(void) {
    g_eventQueueCurrent >>= 8;
    g_xformEntityIdx = 0x004e4cf8u >> 2;
    AddDerefJmp();
}
#else
__declspec(naked) void ShrShrStoreJmp(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueCurrent]
        mov     ecx, 0x004e4cf8
        shr     eax, 8
        shr     ecx, 2
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [g_xformEntityIdx], ecx
        jmp     AddDerefJmp
    }
}
#endif
