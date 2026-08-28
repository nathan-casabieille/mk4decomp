/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_gsmActiveFlag (*(unsigned int *)MK4_VA(unsigned int, 0xab4334u))
#endif
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_currentNodeIdx;
#endif

/* @addr 0x004a1ba0 (69b)
 *   push 0xd; call helper; if eax == 0 jmp set-zero-tail.
 *   else: if [0xab4334] != 0: jmp store-1-tail.
 *   if [0x4f2fc8] != 0: jmp store-1-tail.
 *   else: store 1 → [0x4f2fc8] (using mov reg form); ret eax=1.
 *   set-zero-tail: store 0 → [0x4f2fc8]; xor eax,eax; ret.
 *   store-1-tail: store 1 → [0x4f2fc8] (mov imm32 form); xor eax,eax; ret.
 */
#ifndef MK4_ARENA
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern u32 g_gsmActiveFlag;
#endif
#endif
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_dispatchSave1318;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dispatchSave1318 (*(unsigned int *)MK4_VA(unsigned int, 0x4f2fc8u))
#define g_gsmActiveFlag (*(unsigned int *)MK4_VA(unsigned int, 0xab4334u))
#endif

extern int Input_GetAsyncKey(int);
int TestQueueGateState(void) {
    if (Input_GetAsyncKey(0x0d) == 0) {
        g_dispatchSave1318 = 0;
        return 0;
    }
    if (g_gsmActiveFlag != 0 || g_dispatchSave1318 != 0) {
        g_dispatchSave1318 = 1;
        return 0;
    }
    g_dispatchSave1318 = 1;
    return 1;
}
