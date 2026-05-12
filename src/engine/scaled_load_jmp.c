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
void ScaledLoadJmp_00428d20(void) {
    unsigned int idx = g_fightGroupHead;
    g_walkCallback = (void (*)(void))*(unsigned int *)(idx * 4 + 0x28);
    func_00429530();
}

/* @addr 0x00429210 */
void ScaledLoadJmp_00429210(void) {
    unsigned int idx = g_fightGroupHead;
    g_walkCallback = (void (*)(void))*(unsigned int *)(idx * 4 + 0x28);
    func_004295a0();
}

/* @addr 0x00429390 */
void ScaledLoadJmp_00429390(void) {
    unsigned int idx = g_fightGroupHead;
    g_walkCallback = (void (*)(void))*(unsigned int *)(idx * 4 + 0x28);
    func_00429610();
}
