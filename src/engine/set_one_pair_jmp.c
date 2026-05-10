/**
 * 2 "set two globals to 1 + tail-jmp" helpers (20 bytes each).
 *
 * Pattern:
 *   mov     eax, 1
 *   mov     [g_walkCallback], eax
 *   mov     [g_other], eax
 *   jmp     Target
 *
 * Marks two related state slots as "active" with a single 32-bit
 * write each, then tail-jumps into the dispatcher.
 */
#include "engine/scenegraph.h"

extern unsigned int g_active_0053a408;
extern unsigned int g_active_00537e88;
extern void func_004a0130(void);
extern void func_004a0440(void);

/* @addr 0x004a0110 */
__declspec(naked) void SetOnePairJmp_004a0110(void) {
    __asm {
        mov     eax, 1
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_active_0053a408], eax
        jmp     func_004a0130
    }
}

/* @addr 0x004a0420 */
__declspec(naked) void SetOnePairJmp_004a0420(void) {
    __asm {
        mov     eax, 1
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_active_00537e88], eax
        jmp     func_004a0440
    }
}
