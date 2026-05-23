/**
 * Small game-state jump wrappers.
 *
 * Two tiny one-shot functions that don't belong elsewhere:
 *   IndirectJmp_00438160:  jmp [g_eventQueueChild] - indirect call wrapper
 *   Init3333Jmp_00460400:  init 0x3333 state + tail-jmp
 */
#include "engine/scenegraph.h"

/* @addr 0x00438160 (6b): jmp [g_eventQueueIdx]  (indirect jump through global) */
void IndirectJmp_00438160(void) {
    ((void (*)(void))g_eventQueueIdx)();
}

/* @addr 0x00460400 (30b)
 *   mov     eax, 0x3333
 *   mov     [g_eventQueueIdx], 0x00460490
 *   mov     [g_xformScratch2088], eax
 *   mov     [g_currentNodeFlags], eax
 *   jmp     T
 */
extern u32 g_xformScratch2088;
extern u32 g_currentNodeFlags;
extern u32 g_eventQueueIdx;
extern void func_0042ac0a(void);
void Init3333Jmp_00460400(void) {
    unsigned int v = 0x3333;
    g_eventQueueIdx = 0x00460490;
    g_xformScratch2088 = v;
    g_currentNodeFlags = v;
    func_0042ac0a();
}
