/**
 * Const 0x004ec8f8 packed-init + dirty-guarded scaled store.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x00446580 (56b)
 *   mov     eax, 0x004ec8f8
 *   shr     eax, 2
 *   mov     [g_xformEntityIdx], eax
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   test    byte [g_xformDirtyFlags], 4
 *   jne     +0x13
 *   mov     ecx, [g_baseSel]
 *   mov     edx, [g_currentNodeIdx]
 *   mov     [ecx*4 + 0x60], edx
 *   ret
 */
extern void FramePauseScaledStore(void);
extern int g_phase4ThreePackedBase;
void Const4ec8f8DirtyScaledStore(void) {
    g_xformEntityIdx = ((unsigned int)&g_phase4ThreePackedBase) >> 2;
    FramePauseScaledStore();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 4) != 0) return;
    *(unsigned int *)(g_baseSel * 4 + 0x60) = g_currentNodeIdx;
}
