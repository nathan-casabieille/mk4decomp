/**
 * Auto-split from misc_matches9.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"
#include "portable/mem_model.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) ---
 * Both globals this function touches were missing from here, so under the
 * arena they bound to the HOST symbols in __DATA while the rest of the engine
 * keeps them at 0x541dc4 and 0x54206c - 165 other files alias g_walkCallback.
 * The write to g_bootInitSaveSlot went somewhere nobody reads, and the compare
 * read a stale word, so the guarded call could never fire. */
#ifdef MK4_ARENA
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_bootInitSaveSlot (*(unsigned int *)MK4_VA(unsigned int, 0x541dc4u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif

/* @addr 0x00493ed0 (29b)
 *   mov     ecx, [g_walkCallback]
 *   mov     eax, 0x004f1e20
 *   sar     eax, 2
 *   cmp     eax, ecx
 *   mov     [g_bootInitSaveSlot], eax
 *   jne     +4
 *   jmp     +4
 *   ret
 */
#ifndef MK4_ARENA
extern unsigned int g_bootInitSaveSlot;
#endif
extern void AnimEventUpdateCluster(void);
extern unsigned int g_orphanTbl_004f1e20;
void LoadCmpAddrJmp(void) {
#ifdef MK4_ARENA
    /* the &-form below is the MSVC anti-constant-folding trick; under the
     * arena the plain extern is a HOST global, so UNPTR of its address is
     * garbage (see MStackPackedInit) - use the VA the original encodes */
    unsigned int packed = 0x4f1e20u >> 2;
#else
    unsigned int packed = (unsigned int)((int)MK4_UNPTR(&g_orphanTbl_004f1e20) >> 2);
#endif
    g_bootInitSaveSlot = packed;
    if ((unsigned int)g_walkCallback == packed) {
        AnimEventUpdateCluster();
    }
}
