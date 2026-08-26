/**
 * Auto-split from misc_matchesA.c
 */
#include "engine/scenegraph.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
#endif

/* @addr 0x004bd590 (30b): same shape with different addr
 *   mov     eax, [g_dispatchSave266]
 *   test    eax, eax
 *   je      .skip
 *   push    4
 *   call    F
 *   add     esp, 4
 * .skip:
 *   mov     [g_dispatchSave266], 0
 *   ret
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_dispatchSave266;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dispatchSave266 (*(unsigned int *)MK4_VA(unsigned int, 0x52ab00u))
#endif

extern void PackedListVisitor(int);
void TestCallPush4Zero(void) {
    if (g_dispatchSave266 != 0) {
        PackedListVisitor(4);
        g_dispatchSave266 = 0;
    }
}
