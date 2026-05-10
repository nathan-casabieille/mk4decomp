/**
 * 2 "scaled iterator step + persist" helpers (45 bytes each).
 *
 * Both stubs emit identical bytes.
 *
 * Pattern:
 *   mov     ecx, [g_baseSel_00542060]
 *   mov     eax, [ecx*4 + 0x48]              ; load packed_ptr
 *   mov     [g_eventQueueTotal], eax
 *   mov     edx, [eax*4 + 0]                 ; deref via SIB+0
 *   inc     eax                              ; advance packed
 *   mov     [g_walkCallback], edx
 *   mov     [g_eventQueueTotal], eax         ; persist advanced
 *   mov     [ecx*4 + 0x48], eax              ; persist into slot
 *   ret
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;

/* @addr 0x0045c020 */
__declspec(naked) void ScaledIterStep_0045c020(void) {
    __asm {
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     eax, dword ptr [ecx*4 + 0x48]
        mov     dword ptr [g_eventQueueTotal], eax
        mov     edx, dword ptr [eax*4 + 0]
        inc     eax
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [g_eventQueueTotal], eax
        mov     dword ptr [ecx*4 + 0x48], eax
        ret
    }
}

/* @addr 0x0045c050 */
__declspec(naked) void ScaledIterStep_0045c050(void) {
    __asm {
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     eax, dword ptr [ecx*4 + 0x48]
        mov     dword ptr [g_eventQueueTotal], eax
        mov     edx, dword ptr [eax*4 + 0]
        inc     eax
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [g_eventQueueTotal], eax
        mov     dword ptr [ecx*4 + 0x48], eax
        ret
    }
}
