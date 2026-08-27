/**
 * Auto-split from misc_matchesA.c
 */
#include "engine/scenegraph.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
#endif

/* @addr 0x004b1de0 (29b)
 *   mov     eax, [g_fsys_archive]
 *   test    eax, eax
 *   je      .skip
 *   push    eax
 *   call    F
 *   add     esp, 4
 * .skip:
 *   mov     [g_fsys_archive], 0
 *   ret
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern void * g_fsys_archive;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_fsys_archive (*(unsigned int *)MK4_VA(unsigned int, 0x7af4e0u))
#endif

extern void Helper_FClose(void *p);
void TestCallZero(void) {
    void *v = (void *)MK4_PTR(g_fsys_archive);
    if (v != 0) {
        Helper_FClose(v);
    }
    g_fsys_archive = 0;
}
