/**
 * 2 "scaled init + call + pause/dirty guarded scaled store" (56b).
 *
 * Pattern:
 *   mov     eax, IMM_PTR
 *   shr     eax, 2
 *   mov     [g_xformEntityIdx], eax
 *   call    Func
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   test    byte ptr [g_xformDirtyFlags], 4
 *   jne     .ret
 *   mov     ecx, [g_baseSel]
 *   mov     edx, [g_currentNodeIdx]
 *   mov     [ecx*4 + 0x5c], edx
 * .ret:
 *   ret
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_phase4ThreePackedBase;

extern void MStackBracket1_TreeWalkRecursive2(void);
extern void FramePauseScaledStore(void);

/* @addr 0x00445f00 */
extern unsigned int g_table_00511444;
void ScaledInitPauseDirtyStore_00445f00(void) {
    g_xformEntityIdx = (unsigned int)&g_table_00511444 >> 2;
    MStackBracket1_TreeWalkRecursive2();
    if (g_framePauseFlag != 0) {
        return;
    }
    if ((g_xformDirtyFlags & 4) != 0) {
        return;
    }
    *(unsigned int *)(g_baseSel * 4 + 0x5c) = g_currentNodeIdx;
}

/* @addr 0x00446240 */
void ScaledInitPauseDirtyStore_00446240(void) {
    g_xformEntityIdx = (unsigned int)&g_phase4ThreePackedBase >> 2;
    FramePauseScaledStore();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 4) return;
    *(unsigned int*)(g_baseSel * 4 + 0x5c) = g_currentNodeIdx;
}
