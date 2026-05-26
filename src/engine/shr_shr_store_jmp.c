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
 *   jmp     AddDerefJmp_00433e70
 */
extern void AddDerefJmp_00433e70(void);
__declspec(naked) void ShrShrStoreJmp_00433e50(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueCurrent]
        mov     ecx, 0x004e4cf8
        shr     eax, 8
        shr     ecx, 2
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [g_xformEntityIdx], ecx
        jmp     AddDerefJmp_00433e70
    }
}
