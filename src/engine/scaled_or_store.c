/**
 * 3 "scaled-load + or 1 + dual-store" helpers (28 bytes each).
 *
 * Pattern:
 *   mov     ecx, [g_baseSelector]
 *   mov     eax, [ecx*4 + 0x34]
 *   or      al, 1
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x34], eax
 *   ret
 *
 * Sets bit 0 of the per-base entry at offset 0x34, mirrors the new
 * value into the global walk callback slot, and writes it back.
 */
#include "engine/scenegraph.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x00441df0 */
__declspec(naked) void ScaledOrStore_00441df0(void) {
    __asm {
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     eax, dword ptr [ecx*4 + 0x34]
        or      al, 1
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x34], eax
        ret
    }
}

/* @addr 0x004677a0 */
__declspec(naked) void ScaledOrStore_004677a0(void) {
    __asm {
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     eax, dword ptr [ecx*4 + 0x34]
        or      al, 1
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x34], eax
        ret
    }
}

/* @addr 0x004903d0 */
__declspec(naked) void ScaledOrStore_004903d0(void) {
    __asm {
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [ecx*4 + 0x34]
        or      al, 1
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x34], eax
        ret
    }
}
