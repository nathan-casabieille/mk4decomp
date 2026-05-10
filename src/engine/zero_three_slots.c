/**
 * 2 "zero g_walkCallback + three scaled slots" helpers (41 bytes).
 *
 * Both stubs emit identical bytes; the C compiler did not deduplicate
 * them.
 *
 * Pattern:
 *   mov     eax, [g_fightGroupHead]
 *   xor     ecx, ecx
 *   shl     eax, 2                    ; eax = unpacked base
 *   mov     [g_walkCallback], ecx     ; first store of zero
 *   mov     [eax + 0x78], ecx
 *   mov     ecx, [g_walkCallback]     ; reload (still zero)
 *   mov     [eax + 0x7c], ecx
 *   mov     edx, [g_walkCallback]     ; reload (still zero)
 *   mov     [eax + 0x80], edx
 *   ret
 *
 * The reloads are wasteful but match the original codegen.
 */
#include "engine/scenegraph.h"

/* @addr 0x00490780 */
__declspec(naked) void ZeroThreeSlots_00490780(void) {
    __asm {
        mov     eax, dword ptr [g_fightGroupHead]
        xor     ecx, ecx
        shl     eax, 2
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x78], ecx
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [eax + 0x7c], ecx
        mov     edx, dword ptr [g_walkCallback]
        mov     dword ptr [eax + 0x80], edx
        ret
    }
}

/* @addr 0x004ac010 */
__declspec(naked) void ZeroThreeSlots_004ac010(void) {
    __asm {
        mov     eax, dword ptr [g_fightGroupHead]
        xor     ecx, ecx
        shl     eax, 2
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [eax + 0x78], ecx
        mov     ecx, dword ptr [g_walkCallback]
        mov     dword ptr [eax + 0x7c], ecx
        mov     edx, dword ptr [g_walkCallback]
        mov     dword ptr [eax + 0x80], edx
        ret
    }
}
