/**
 * 2 "push arg onto scaled stack" helpers (52 bytes each).
 *
 * Both stubs emit identical bytes.
 *
 * Pattern (decoded):
 *   mov     eax, [g_baseSel_00542060]
 *   mov     edx, [esp+4]                    ; arg
 *   mov     ecx, [eax*4 + 4]                ; load top
 *   lea     eax, [eax*4 + 4]                ; address of slot
 *   mov     [g_scaledInit_00542044], ecx
 *   mov     [ecx*4 + 0], edx                ; store arg via SIB+0
 *   mov     ecx, [g_scaledInit_00542044]    ; reload top
 *   inc     ecx
 *   mov     [g_scaledInit_00542044], ecx
 *   mov     [eax], ecx                      ; persist new top
 *   ret
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00404b90 */
__declspec(naked) void ScaledPushArg_00404b90(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     edx, dword ptr [esp + 4]
        mov     ecx, dword ptr [eax*4 + 4]
        lea     eax, dword ptr [eax*4 + 4]
        mov     dword ptr [g_scaledInit_00542044], ecx
        mov     dword ptr [ecx*4 + 0], edx
        mov     ecx, dword ptr [g_scaledInit_00542044]
        inc     ecx
        mov     dword ptr [g_scaledInit_00542044], ecx
        mov     dword ptr [eax], ecx
        ret
    }
}

/* @addr 0x00404c00 */
__declspec(naked) void ScaledPushArg_00404c00(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     edx, dword ptr [esp + 4]
        mov     ecx, dword ptr [eax*4 + 4]
        lea     eax, dword ptr [eax*4 + 4]
        mov     dword ptr [g_scaledInit_00542044], ecx
        mov     dword ptr [ecx*4 + 0], edx
        mov     ecx, dword ptr [g_scaledInit_00542044]
        inc     ecx
        mov     dword ptr [g_scaledInit_00542044], ecx
        mov     dword ptr [eax], ecx
        ret
    }
}
