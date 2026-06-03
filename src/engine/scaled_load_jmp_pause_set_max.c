/**
 * Auto-split from misc_matchesY.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_phaseTimer;

/* @addr 0x00446880 (62b)
 *   mov     eax, [g_baseSel]
 *   mov     ecx, [eax*4 + 0x4c]
 *   mov     [g_currentNodeIdx], ecx
 *   jmp     T
 *   nop * 9
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +0x0f
 *   mov     eax, 0xfff
 *   mov     [g_walkCallback], eax
 *   mov     [g_phaseTimer], eax
 *   ret
 */
extern void MStackCall_MStackPush2ChainPrepend_00406340(void);
extern void Cmp2OrSet0b(void);
/* Entry A (23b @ 0x00446880): load baseSel[+0x4c] into g_scaledInit,
 * tail-jmp MStackCall_MStackPush2ChainPrepend_00406340. Entry B (sub-entry at +0x20) lives in
 * Cmp2OrSet0b_then_SetWalkPhaseFff_004468a0. The 9-byte nop gap is filled by 0x90-fill. */
void ScaledLoadJmpPauseSetMax(void) {
    g_currentNodeIdx = *(unsigned int *)(g_baseSel * 4 + 0x4c);
    MStackCall_MStackPush2ChainPrepend_00406340();
}

/* @addr 0x004468a0 (30b): call Cmp2OrSet0b, then if !pause set both
 * g_walkCallback and g_phaseTimer to 0xfff. Orphan sub-entry of the
 * original packed 62-byte block. */
void Cmp2OrSet0b_then_SetWalkPhaseFff_004468a0(void) {
    int v;
    Cmp2OrSet0b();
    if (g_framePauseFlag != 0) return;
    v = 0xfff;
    g_walkCallback = (void (*)(void))v;
    g_phaseTimer = v;
}
