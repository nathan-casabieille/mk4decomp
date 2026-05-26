/**
 * Auto-split from misc_matchesS.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00437930 (52b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, [g_matrixStackTop]
 *   mov     [g_walkCallback], 2
 *   inc     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], OFFSET InstallSelfThreeStateLeaPlus22_00437970
 *   jmp     T
 *   ret
 */
extern void LeaPlus22StoreSelf_0048e4d0(void);
extern void InstallSelfThreeStateLeaPlus22_00437970(void);
extern void MstackPopScaledChainPlusThunks_00471250(void);
void CallPauseMStackPushSet2Jmp_00437930(void) {
    unsigned int top;
    LeaPlus22StoreSelf_0048e4d0();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_walkCallback = (void (*)(void))2;
    top++;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = (unsigned int)&InstallSelfThreeStateLeaPlus22_00437970;
    MstackPopScaledChainPlusThunks_00471250();
}
