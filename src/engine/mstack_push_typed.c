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
void MStackPushTyped_0044cf50(void) {
    unsigned int top = g_matrixStackTop;
    unsigned int wt = g_eventQueueWorkType;
    top++;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = wt;
    g_eventQueueWorkType = 0x09000100;
    func_0044cfc8();
}

/* @addr 0x0044cf80 */
void MStackPushTyped_0044cf80(void) {
    unsigned int top = g_matrixStackTop;
    unsigned int wt = g_eventQueueWorkType;
    top++;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = wt;
    g_eventQueueWorkType = 0x0a000100;
    func_0044cfc8();
}

/* @addr 0x0044cfb0 */
void MStackPushTyped_0044cfb0(void) {
    unsigned int top = g_matrixStackTop;
    unsigned int wt = g_eventQueueWorkType;
    top++;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = wt;
    g_eventQueueWorkType = 0x0b000100;
    func_0044cfc8();
}
