/**
 * Auto-split from misc_matchesO.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x00464800 (47b)
 *   mov     eax, 0x0050b10c
 *   shr     eax, 2
 *   mov     [g_currentNodeIdx], eax
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     ecx, 0x0051131c     ; was 0x00511310 + 0xc?
 *   shr     ecx, 2
 *   mov     [g_currentNodeIdx], ecx
 *   jmp     T
 *   ret
 */
extern void LoadGeoAsset_Default(void);
extern void LoadGeoAsset_Default(void);
extern int g_dispatchSave409;
extern int g_dispatchSave414;
void DualScaledLitInitJmp(void) {
#ifdef MK4_ARENA
    /* The &-form below is the MSVC anti-constant-folding trick, and under
     * the arena it yields the HOST address of the native global rather than
     * the VA - the packed index then points nowhere and the geo loader is
     * handed a record whose name pointer reads as zero (an empty asset
     * name). Same trap as MStackPackedInit. */
    g_currentNodeIdx = 0x0050b10cu >> 2;
    LoadGeoAsset_Default();
    if (g_framePauseFlag != 0) return;
    g_currentNodeIdx = 0x00511310u >> 2;
    LoadGeoAsset_Default();
#else
    g_currentNodeIdx = ((unsigned int)&g_dispatchSave409) >> 2;
    LoadGeoAsset_Default();
    if (g_framePauseFlag != 0) return;
    g_currentNodeIdx = ((unsigned int)&g_dispatchSave414) >> 2;
    LoadGeoAsset_Default();
#endif
}
