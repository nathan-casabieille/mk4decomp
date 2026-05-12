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
void DualConstJmp_00453480(void) {
    g_walkCallback = (void (*)(void))2;
    g_acc_00542078 = 4;
    func_00473f50();
}

/* @addr 0x004534a0 */
void DualConstJmp_004534a0(void) {
    g_walkCallback = (void (*)(void))0x0d;
    g_acc_00542078 = 4;
    func_00473f50();
}

/* @addr 0x004534c0 */
void DualConstJmp_004534c0(void) {
    g_walkCallback = (void (*)(void))0x0e;
    g_acc_00542078 = 4;
    func_00473f50();
}
