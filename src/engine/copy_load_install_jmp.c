/**
 * 2 "copy + scaled-load + install + tail-jmp" helpers (34 bytes each).
 *
 * Pattern:
 *   mov     eax, [g_A]
 *   mov     ecx, [g_baseSel_00542060]
 *   mov     [g_fightGroupHead], eax
 *   mov     edx, [ecx*4 + 0x30]
 *   mov     [g_scaledInit_00542044], edx
 *   jmp     Tail
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

extern void func_00405e70(void);
extern void func_00405ca0(void);

/* @addr 0x00445ed0 */
__declspec(naked) void CopyLoadInstallJmp_00445ed0(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueIdx]
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     dword ptr [g_fightGroupHead], eax
        mov     edx, dword ptr [ecx*4 + 0x30]
        mov     dword ptr [g_scaledInit_00542044], edx
        jmp     func_00405e70
    }
}

/* @addr 0x00446210 */
__declspec(naked) void CopyLoadInstallJmp_00446210(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueEnd]
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     dword ptr [g_fightGroupHead], eax
        mov     edx, dword ptr [ecx*4 + 0x30]
        mov     dword ptr [g_scaledInit_00542044], edx
        jmp     func_00405ca0
    }
}
