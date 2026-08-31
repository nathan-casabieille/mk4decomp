/**
 * Auto-split from misc_matches7.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#endif


/* @addr 0x0041f810 (28b)
 *   mov     eax, [g_pendingNodeType]
 *   shl     eax, 2
 *   mov     ecx, [eax + 0xd8]
 *   test    ecx, ecx
 *   je      .ret
 *   push    eax
 *   call    F
 *   add     esp, 4
 *   ret
 */
/* NodeUnlink takes a HOST pointer (see src/boot/node_unlink.c): it compares
 * MK4_UNPTR(node) against the VAs in the slot table. Handing it the raw VA
 * made every comparison miss, so it took the "not found" bare return, left
 * +0xd8 set, and TripleStageRollback's dirty-bit loop never terminated -
 * the arcade join screen hung the pump on the second confirm. */
extern void NodeUnlink(void *);
void LoadShlDerefCallSkip(void) {
    unsigned int p = g_pendingNodeType * 4;
    if (((ScenegraphNode *)MK4_PTR(p))->ptr_field) {
        NodeUnlink(MK4_PTR(p));
    }
}
