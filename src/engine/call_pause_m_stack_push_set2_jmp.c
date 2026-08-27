/**
 * Auto-split from misc_matchesS.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"
#include "portable/code_va.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x00437930 (52b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, [g_matrixStackTop]
 *   mov     [g_walkCallback], 2
 *   inc     eax
 *   mov     [g_matrixStackTop], eax
 *   mov     [eax*4 + 0], OFFSET InstallSelfThreeStateLeaPlus22
 *   jmp     T
 *   ret
 */
extern void LeaPlus22StoreSelf(void);
extern void InstallSelfThreeStateLeaPlus22(void);
extern void MstackPopScaledChainPlusThunks(void);
void CallPauseMStackPushSet2Jmp(void) {
    unsigned int top;
    LeaPlus22StoreSelf();
    if (g_framePauseFlag != 0) return;
    top = g_matrixStackTop;
    g_walkCallback = (void (*)(void))2;
    top++;
    g_matrixStackTop = top;
    *(unsigned int *)(top * 4) = MK4_CODE_VA(InstallSelfThreeStateLeaPlus22);
    MstackPopScaledChainPlusThunks();
}
