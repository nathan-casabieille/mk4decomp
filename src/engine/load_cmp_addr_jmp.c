/**
 * Auto-split from misc_matches9.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"
#include "portable/mem_model.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

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
extern unsigned int g_bootInitSaveSlot;
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
