/**
 * Auto-split from misc_matches3.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel;

/* @addr 0x00490070 (23b)
 *   mov     eax, [g_baseSel]
 *   mov     ecx, [eax*4 + 0x38]
 *   mov     [g_scaledInit_00542044], ecx
 *   jmp     +9
 */
extern void DualMaskCmpJmp(void);
void ScaledLoadJmp_38(void) {
    g_scaledInit_00542044 = *(unsigned int *)(g_baseSel * 4 + 0x38);
    DualMaskCmpJmp();
}
