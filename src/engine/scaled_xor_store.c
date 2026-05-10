/**
 * 2 "scaled-load + xor 1 + dual-store" helpers (29 bytes each).
 *
 * Pattern:
 *   mov     ecx, [g_baseSelector]
 *   mov     eax, [ecx*4 + 0x34]
 *   xor     eax, 1
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x34], eax
 *   ret
 *
 * Toggles bit 0 of the per-base entry at offset 0x34, mirrors the
 * new value into the global walk callback slot. Variant of
 * ScaledOrStore (uses xor instead of or).
 */
#include "engine/scenegraph.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x004900f0 */
__declspec(naked) void ScaledXorStore_004900f0(void) {
    __asm {
        mov     ecx, dword ptr [g_scaledInit_00542044]
        mov     eax, dword ptr [ecx*4 + 0x34]
        xor     eax, 1
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x34], eax
        ret
    }
}

/* @addr 0x004903b0 */
__declspec(naked) void ScaledXorStore_004903b0(void) {
    __asm {
        mov     ecx, dword ptr [g_fightGroupHead]
        mov     eax, dword ptr [ecx*4 + 0x34]
        xor     eax, 1
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 0x34], eax
        ret
    }
}
