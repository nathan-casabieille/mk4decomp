/**
 * Auto-split from misc_matches3.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
extern unsigned int g_baseSel;

/* @addr 0x00490070 (23b)
 *   mov     eax, [g_baseSel]
 *   mov     ecx, [eax*4 + 0x38]
 *   mov     [g_currentNodeIdx], ecx
 *   jmp     +9
 */
extern void DualMaskCmpJmp(void);
void ScaledLoadJmp_38(void) {
    g_currentNodeIdx = *(unsigned int *)(g_baseSel * 4 + 0x38);
    DualMaskCmpJmp();
}
