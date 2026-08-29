/**
 * Auto-split from misc_matchesA.c
 */
#include "engine/scenegraph.h"

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


/* @addr 0x004bdae0 (22b)
 *   mov     eax, [g_currentNodeIdx]
 *   mov     ecx, [g_pendingNodeType]
 *   push    eax
 *   push    ecx
 *   call    F
 *   add     esp, 8
 *   ret
 */
/* The two globals hold RAW VAs here (the original pushes them straight
 * into the cdecl); the twin takes host pointers, so translate. */
extern void MatrixTransform3x3Q12(short *, short *);
void Push2GlobalsCall(void) {
    MatrixTransform3x3Q12((short *)MK4_PTR(g_pendingNodeType),
                          (short *)MK4_PTR(g_currentNodeIdx));
}
