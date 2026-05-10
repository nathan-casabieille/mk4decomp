/**
 * 2 "scaled-load (offset 0x30) + tail-jmp" wrappers (23 bytes each).
 *
 * Pattern:
 *   mov     eax, [g_A]
 *   mov     ecx, [eax*4 + 0x30]      ; offset 0x30 (vs 0x28 in ScaledLoadJmp)
 *   mov     [g_B], ecx
 *   jmp     Target
 */
#include "engine/scenegraph.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;   /* 0x00542060 */
extern void func_00472fe0(void);
extern void func_00493ed0(void);

/* @addr 0x00472fc0 */
__declspec(naked) void ScaledLoadJmp30_00472fc0(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueEnd]
        mov     ecx, dword ptr [eax*4 + 0x30]
        mov     dword ptr [g_scaledInit_00542044], ecx
        jmp     func_00472fe0
    }
}

/* @addr 0x00493eb0 */
__declspec(naked) void ScaledLoadJmp30_00493eb0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     ecx, dword ptr [eax*4 + 0x30]
        mov     dword ptr [g_walkCallback], ecx
        jmp     func_00493ed0
    }
}
