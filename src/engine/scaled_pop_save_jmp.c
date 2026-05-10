/**
 * 2 "scaled pop + save deref + persist + tail-jmp" helpers (44b).
 *
 * Pattern:
 *   mov     ecx, [g_baseSel_00542060]
 *   mov     eax, [ecx*4 + 4]
 *   dec     eax
 *   mov     [g_scaledInit_00542044], eax     ; save dec'd top
 *   mov     edx, [eax*4 + 0]                 ; deref via SIB+0
 *   mov     [g_scaledInit_00542048], edx     ; save popped element
 *   mov     [ecx*4 + 4], eax                 ; persist new top
 *   jmp     Tail
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_scaledInit_00542048;

extern void func_00438060(void);
extern void func_0043aa80(void);

/* @addr 0x00438440 */
__declspec(naked) void ScaledPopSaveJmp_00438440(void) {
    __asm {
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     eax, dword ptr [ecx*4 + 4]
        dec     eax
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     edx, dword ptr [eax*4 + 0]
        mov     dword ptr [g_scaledInit_00542048], edx
        mov     dword ptr [ecx*4 + 4], eax
        jmp     func_00438060
    }
}

/* @addr 0x0043bb20 */
__declspec(naked) void ScaledPopSaveJmp_0043bb20(void) {
    __asm {
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     eax, dword ptr [ecx*4 + 4]
        dec     eax
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     edx, dword ptr [eax*4 + 0]
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [ecx*4 + 4], eax
        jmp     func_0043aa80
    }
}
