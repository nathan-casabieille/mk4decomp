/**
 * 2 "scaled load + two guarded calls + dual const store" (67 bytes).
 *
 * Pattern:
 *   mov     eax, [g_baseSel_00542060]
 *   mov     ecx, [eax*4 + 0x4c]
 *   mov     [g_fightGroupHead], ecx
 *   call    FuncA
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   call    FuncB
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     [g_walkCallback], 2
 *   mov     [g_acc_00542078], 3
 * .ret:
 *   ret
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_acc_00542078;

extern void MStackPush2RunCountdown_004089e0(void);
extern void MStackBracket7_DispatchAndChain_004b8fa0(void);

/* @addr 0x0044ba30 */
void ScaledLoadTwoCallDualConst_0044ba30(void) {
    g_fightGroupHead = *(unsigned int*)(g_baseSel_00542060 * 4 + 0x4c);
    MStackPush2RunCountdown_004089e0();
    if (g_framePauseFlag) return;
    MStackBracket7_DispatchAndChain_004b8fa0();
    if (g_framePauseFlag) return;
    g_walkCallback = (void(*)(void))2;
    g_acc_00542078 = 3;
}

/* @addr 0x00467c30 */
void ScaledLoadTwoCallDualConst_00467c30(void) {
    g_fightGroupHead = *(unsigned int*)(g_baseSel_00542060 * 4 + 0x4c);
    MStackPush2RunCountdown_004089e0();
    if (g_framePauseFlag) return;
    MStackBracket7_DispatchAndChain_004b8fa0();
    if (g_framePauseFlag) return;
    g_walkCallback = (void(*)(void))2;
    g_acc_00542078 = 3;
}
