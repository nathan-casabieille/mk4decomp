/**
 * Auto-split from misc_matchesP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0046fbe0 (49b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     al, byte ptr [g_xformDirtyFlags]
 *   mov     [g_walkCallback], 0x0e14
 *   test    al, 1
 *   jne     +0x0a
 *   mov     [g_walkCallback], 0xfffff1ec
 *   jmp     +0x50
 *   ret
 */
extern void MStackPush2ChainSwap_0048f090(void);
extern void PushCallSignClampDualStore_0046fc60(void);
void CallPauseDirtyTwoSetsJmp_0046fbe0(void) {
    MStackPush2ChainSwap_0048f090();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = (void (*)(void))0x0e14;
    if ((g_xformDirtyFlags & 1) == 0) {
        g_walkCallback = (void (*)(void))0xfffff1ec;
    }
    PushCallSignClampDualStore_0046fc60();
}

/* @addr 0x0046fc20 (49b): same as 0x0046fbe0 with constants swapped */
extern void MStackPush2ChainSwap_0048f090(void);
extern void PushCallSignClampDualStore_0046fc60(void);
void CallPauseDirtyTwoSetsJmp_0046fc20(void) {
    MStackPush2ChainSwap_0048f090();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = (void (*)(void))0xfffff1ec;
    if ((g_xformDirtyFlags & 1) == 0) {
        g_walkCallback = (void (*)(void))0x0e14;
    }
    PushCallSignClampDualStore_0046fc60();
}
