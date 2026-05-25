/**
 * Auto-split from misc_matchesW.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00490030 (54b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     ecx, [g_baseSel_00542060]
 *   mov     [g_scaledInit_00542044], eax
 *   mov     edx, [ecx*4 + 0x38]
 *   mov     [g_fightGroupHead], edx
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +0x0a
 *   mov     eax, [g_scaledInit_00542044]
 *   mov     [g_fightGroupHead], eax
 *   ret
 */
extern void func_00490074(void);
void SwapCallRestore_00490030(void) {
    g_scaledInit_00542044 = g_fightGroupHead;
    g_fightGroupHead = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x38);
    func_00490074();
    if (g_framePauseFlag != 0) return;
    g_fightGroupHead = g_scaledInit_00542044;
}
