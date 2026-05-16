/**
 * 2 "matrix-stack push + swap + equality flag + tail-jmp" (70 bytes).
 *
 * Pattern:
 *   mov     eax, [g_matrixStackTop]
 *   mov     ecx, [g_eventQueueCurrent]
 *   inc     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], ecx                  ; push current
 *   mov     edx, [g_dlNalt1]
 *   mov     eax, [g_player1NodeIdx]
 *   mov     [g_eventQueueCurrent], edx        ; install nalt1
 *   mov     edx, [g_Y]                        ; per-helper
 *   xor     ecx, ecx
 *   cmp     eax, edx
 *   mov     [g_walkCallback], eax
 *   sete    cl
 *   mov     [g_eq_00542098], ecx
 *   jmp     Tail
 */
#include "engine/scenegraph.h"
#include "game/tick.h"
#include "game/statemachine.h"

extern unsigned int g_eq_00542098;

extern void StateSwitchMStackPop_00474f20(void);

/* @addr 0x00474e80 */
__declspec(naked) void MStackPushSwapEqJmp_00474e80(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_eventQueueCurrent]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     edx, dword ptr [g_dlNalt1]
        mov     eax, dword ptr [g_player1NodeIdx]
        mov     dword ptr [g_eventQueueCurrent], edx
        mov     edx, dword ptr [g_eventQueueEnd]
        xor     ecx, ecx
        cmp     eax, edx
        mov     dword ptr [g_walkCallback], eax
        sete    cl
        mov     dword ptr [g_eq_00542098], ecx
        jmp     StateSwitchMStackPop_00474f20
    }
}

/* @addr 0x00474ed0 */
__declspec(naked) void MStackPushSwapEqJmp_00474ed0(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_eventQueueCurrent]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     edx, dword ptr [g_dlNalt1]
        mov     eax, dword ptr [g_player1NodeIdx]
        mov     dword ptr [g_eventQueueCurrent], edx
        mov     edx, dword ptr [g_eventQueueIdx]
        xor     ecx, ecx
        cmp     eax, edx
        mov     dword ptr [g_walkCallback], eax
        sete    cl
        mov     dword ptr [g_eq_00542098], ecx
        jmp     StateSwitchMStackPop_00474f20
    }
}
