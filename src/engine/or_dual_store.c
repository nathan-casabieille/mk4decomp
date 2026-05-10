/**
 * 2 "or with global + dual store" helpers (24 bytes each).
 *
 * Pattern:
 *   mov     eax, [g_A]
 *   mov     ecx, [g_walkCallback]
 *   or      eax, ecx                  ; eax |= g_walkCallback
 *   mov     [g_B], eax
 *   mov     [g_A], eax
 *   ret
 *
 * Combines per-helper global with the walk callback bitfield, then
 * mirrors the result into both an output slot and back into g_A.
 */
#include "engine/scenegraph.h"

extern unsigned int g_or_004d57b0;     /* 0x004d57b0 (mirrors back) */
extern unsigned int g_or_0052ab40;     /* 0x0052ab40 */

/* @addr 0x0048a190 */
__declspec(naked) void OrDualStore_0048a190(void) {
    __asm {
        mov     eax, dword ptr [g_or_004d57b0]
        mov     ecx, dword ptr [g_walkCallback]
        or      eax, ecx
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [g_or_004d57b0], eax
        ret
    }
}

/* @addr 0x0048e4b0 */
__declspec(naked) void OrDualStore_0048e4b0(void) {
    __asm {
        mov     eax, dword ptr [g_or_0052ab40]
        mov     ecx, dword ptr [g_walkCallback]
        or      eax, ecx
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [g_or_0052ab40], eax
        ret
    }
}
