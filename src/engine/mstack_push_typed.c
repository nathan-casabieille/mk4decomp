/**
 * 3 "matrix-stack push + typed work + tail-jmp" helpers (39 bytes).
 *
 * Pattern:
 *   mov     eax, [g_matrixStackTop]
 *   mov     ecx, [g_eventQueueWorkType]
 *   inc     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], ecx                  ; raw addr push
 *   mov     [g_eventQueueWorkType], TAGGED    ; type-tagged update
 *   jmp     Target
 *
 * Pushes the current work-type onto the matrix stack, replaces it
 * with a per-helper type-tagged value (0x09000100 / 0x0a000100 /
 * 0x0b000100), and tail-jumps into the shared dispatcher.
 */
#include "engine/scenegraph.h"

extern void func_0044cfc8(void);

/* @addr 0x0044cf50 */
__declspec(naked) void MStackPushTyped_0044cf50(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_eventQueueWorkType]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     dword ptr [g_eventQueueWorkType], 0x09000100
        jmp     func_0044cfc8
    }
}

/* @addr 0x0044cf80 */
__declspec(naked) void MStackPushTyped_0044cf80(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_eventQueueWorkType]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     dword ptr [g_eventQueueWorkType], 0x0a000100
        jmp     func_0044cfc8
    }
}

/* @addr 0x0044cfb0 */
__declspec(naked) void MStackPushTyped_0044cfb0(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_eventQueueWorkType]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], ecx
        mov     dword ptr [g_eventQueueWorkType], 0x0b000100
        jmp     func_0044cfc8
    }
}
