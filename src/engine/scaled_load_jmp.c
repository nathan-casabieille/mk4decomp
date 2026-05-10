/**
 * 3 "scaled-load + tail-jmp" wrappers (23 bytes each).
 *
 * Pattern:
 *   mov     eax, [g_fightGroupHead]
 *   mov     ecx, [eax*4 + 0x28]      ; load member at offset 0x28 of fight group
 *   mov     [g_walkCallback], ecx     ; install as walk callback
 *   jmp     Target
 *
 * Walks one level into the fight-group head node, copies a function
 * pointer into the walk-callback slot, and tail-jumps into the
 * dispatch handler.
 */
#include "engine/scenegraph.h"

extern void func_00429530(void);
extern void func_004295a0(void);
extern void func_00429610(void);

/* @addr 0x00428d20 */
__declspec(naked) void ScaledLoadJmp_00428d20(void) {
    __asm {
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [eax*4 + 0x28]
        mov     dword ptr [g_walkCallback], ecx
        jmp     func_00429530
    }
}

/* @addr 0x00429210 */
__declspec(naked) void ScaledLoadJmp_00429210(void) {
    __asm {
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [eax*4 + 0x28]
        mov     dword ptr [g_walkCallback], ecx
        jmp     func_004295a0
    }
}

/* @addr 0x00429390 */
__declspec(naked) void ScaledLoadJmp_00429390(void) {
    __asm {
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [eax*4 + 0x28]
        mov     dword ptr [g_walkCallback], ecx
        jmp     func_00429610
    }
}
