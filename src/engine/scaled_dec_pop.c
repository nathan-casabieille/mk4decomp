/**
 * 2 "scaled-base + dec list + pop into slot" helpers (35 bytes each).
 *
 * Both stubs emit identical bytes (the compiler did not deduplicate
 * them); they share the body but live at distinct addresses.
 *
 * Pattern:
 *   mov     edx, [g_baseSel_00542060]
 *   mov     ecx, [edx*4 + 4]
 *   dec     ecx
 *   mov     [g_scaledInit_00542044], ecx
 *   mov     eax, [ecx*4 + 0]
 *   mov     [edx*4 + 4], eax
 *   ret
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00404bd0 */
__declspec(naked) void ScaledDecPop_00404bd0(void) {
    __asm {
        mov     edx, dword ptr [g_baseSel_00542060]
        mov     ecx, dword ptr [edx*4 + 4]
        dec     ecx
        mov     dword ptr [g_scaledInit_00542044], ecx
        mov     eax, dword ptr [ecx*4 + 0]
        mov     dword ptr [edx*4 + 4], ecx
        ret
    }
}

/* @addr 0x00404c40 */
__declspec(naked) void ScaledDecPop_00404c40(void) {
    __asm {
        mov     edx, dword ptr [g_baseSel_00542060]
        mov     ecx, dword ptr [edx*4 + 4]
        dec     ecx
        mov     dword ptr [g_scaledInit_00542044], ecx
        mov     eax, dword ptr [ecx*4 + 0]
        mov     dword ptr [edx*4 + 4], ecx
        ret
    }
}
