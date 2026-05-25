/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x004a1ba0 (69b)
 *   push 0xd; call helper; if eax == 0 jmp set-zero-tail.
 *   else: if [0xab4334] != 0: jmp store-1-tail.
 *   if [0x4f2fc8] != 0: jmp store-1-tail.
 *   else: store 1 → [0x4f2fc8] (using mov reg form); ret eax=1.
 *   set-zero-tail: store 0 → [0x4f2fc8]; xor eax,eax; ret.
 *   store-1-tail: store 1 → [0x4f2fc8] (mov imm32 form); xor eax,eax; ret.
 */
extern u32 g_gsmActiveFlag;
extern unsigned int g_dispatchSave1318_004f2fc8;
extern int Helper_JoyButtonInit(int);
int TestQueueGateState_004a1ba0(void) {
    if (Helper_JoyButtonInit(0x0d) == 0) {
        g_dispatchSave1318_004f2fc8 = 0;
        return 0;
    }
    if (g_gsmActiveFlag != 0 || g_dispatchSave1318_004f2fc8 != 0) {
        g_dispatchSave1318_004f2fc8 = 1;
        return 0;
    }
    g_dispatchSave1318_004f2fc8 = 1;
    return 1;
}
