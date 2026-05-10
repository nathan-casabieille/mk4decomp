/**
 * 2 "scaled-load + inc + tail-jmp" wrappers (24 bytes each).
 *
 * Pattern:
 *   mov     eax, [g_fightGroupHead]
 *   mov     ecx, [eax*4 + 0x28]
 *   inc     ecx
 *   mov     [g_X], ecx
 *   jmp     Target
 *
 * Variant of ScaledLoadJmp (23b) that adds 1 to the loaded value
 * before storing it. Different destination globals per stub.
 */
#include "engine/scenegraph.h"

extern void func_00428e70(void);
extern void func_00429960(void);

/* @addr 0x00428d00 */
__declspec(naked) void ScaledLoadIncJmp_00428d00(void) {
    __asm {
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [eax*4 + 0x28]
        inc     ecx
        mov     dword ptr [g_eventQueueCurrent], ecx
        jmp     func_00428e70
    }
}

/* @addr 0x00429840 */
__declspec(naked) void ScaledLoadIncJmp_00429840(void) {
    __asm {
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [eax*4 + 0x28]
        inc     ecx
        mov     dword ptr [g_walkCallback], ecx
        jmp     func_00429960
    }
}
