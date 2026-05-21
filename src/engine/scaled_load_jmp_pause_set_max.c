/**
 * Auto-split from misc_matchesY.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_state_004d57ac;
extern unsigned int g_state_00537e94;
extern packed_ptr g_fightGroupHead;

/* @addr 0x00446880 (62b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     ecx, [eax*4 + 0x4c]
 *   mov     [g_scaledInit_00542044], ecx
 *   jmp     T
 *   nop * 9
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +0x0f
 *   mov     eax, 0xfff
 *   mov     [g_walkCallback], eax
 *   mov     [g_state_00537e94], eax
 *   ret
 */
extern void MStackCall_00406340(void);
extern void Cmp2OrSet0b_0048e3e0(void);
/* Entry A (23b @ 0x00446880): load baseSel[+0x4c] into g_scaledInit,
 * tail-jmp MStackCall_00406340. Entry B (sub-entry at +0x20) lives in
 * func_004468a0. The 9-byte nop gap is filled by 0x90-fill. */
void ScaledLoadJmpPauseSetMax_00446880(void) {
    g_scaledInit_00542044 = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x4c);
    MStackCall_00406340();
}

/* @addr 0x004468a0 (30b): call Cmp2OrSet0b, then if !pause set both
 * g_walkCallback and g_state_00537e94 to 0xfff. Orphan sub-entry of the
 * original packed 62-byte block. */
void func_004468a0(void) {
    int v;
    Cmp2OrSet0b_0048e3e0();
    if (g_framePauseFlag != 0) return;
    v = 0xfff;
    g_walkCallback = (void (*)(void))v;
    g_state_00537e94 = v;
}
