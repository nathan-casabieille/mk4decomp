/**
 * 3 "dual const-store + tail-jmp" helpers (25 bytes each).
 *
 * Pattern:
 *   mov     [g_walkCallback], IMM_A     ; per-helper
 *   mov     [g_acc_00542078], 4
 *   jmp     Tail
 */
#include "engine/scenegraph.h"

extern unsigned int g_acc_00542078;
extern void func_00473f50(void);

/* @addr 0x00453480 */
__declspec(naked) void DualConstJmp_00453480(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 2
        mov     dword ptr [g_acc_00542078], 4
        jmp     func_00473f50
    }
}

/* @addr 0x004534a0 */
__declspec(naked) void DualConstJmp_004534a0(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 0x0d
        mov     dword ptr [g_acc_00542078], 4
        jmp     func_00473f50
    }
}

/* @addr 0x004534c0 */
__declspec(naked) void DualConstJmp_004534c0(void) {
    __asm {
        mov     dword ptr [g_walkCallback], 0x0e
        mov     dword ptr [g_acc_00542078], 4
        jmp     func_00473f50
    }
}
