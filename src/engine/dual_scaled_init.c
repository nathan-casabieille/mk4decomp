/**
 * 4 "dual scaled-base init + tail-jmp" wrappers.
 *
 * Pattern (32 bytes):
 *   mov eax, ADDR_A
 *   mov ecx, ADDR_B
 *   shr eax, 2
 *   shr ecx, 2
 *   mov [g_scaledInit_00542044], eax
 *   mov [g_scaledInit_00542048], ecx
 *   jmp Target
 *
 * All four prime the same pair of scaled-base globals (0x00542044
 * and 0x00542048) with different table addresses, then tail-jmp
 * into the same handler at 0x0045d960.
 */
#include "engine/scenegraph.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_scaledInit_00542048;
extern void DualSwapTwoCallsJmp_0045d960(void);

/* @addr 0x0045d8e0 */
__declspec(naked) void DualScaledInit_0045d8e0(void) {
    __asm {
        mov     eax, 0x0052ab18
        mov     ecx, 0x0053a2a0
        shr     eax, 2
        shr     ecx, 2
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [g_scaledInit_00542048], ecx
        jmp     DualSwapTwoCallsJmp_0045d960
    }
}

/* @addr 0x0045d900 */
__declspec(naked) void DualScaledInit_0045d900(void) {
    __asm {
        mov     eax, 0x0053a330
        mov     ecx, 0x0053a258
        shr     eax, 2
        shr     ecx, 2
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [g_scaledInit_00542048], ecx
        jmp     DualSwapTwoCallsJmp_0045d960
    }
}

/* @addr 0x0045d920 */
__declspec(naked) void DualScaledInit_0045d920(void) {
    __asm {
        mov     eax, 0x00541e00
        mov     ecx, 0x0053a2f8
        shr     eax, 2
        shr     ecx, 2
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [g_scaledInit_00542048], ecx
        jmp     DualSwapTwoCallsJmp_0045d960
    }
}

/* @addr 0x0045d940 */
__declspec(naked) void DualScaledInit_0045d940(void) {
    __asm {
        mov     eax, 0x0053a750
        mov     ecx, 0x00538048
        shr     eax, 2
        shr     ecx, 2
        mov     dword ptr [g_scaledInit_00542044], eax
        mov     dword ptr [g_scaledInit_00542048], ecx
        jmp     DualSwapTwoCallsJmp_0045d960
    }
}
