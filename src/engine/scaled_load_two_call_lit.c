/**
 * 2 "scaled load + two guarded calls + literal install + jmp" (66b).
 *
 * Pattern:
 *   mov     eax, [g_baseSel_00542060]
 *   mov     ecx, [eax*4 + 0x64]
 *   mov     [g_fightGroupHead], ecx
 *   call    FuncA
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   call    FuncB
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     edx, IMM_PTR
 *   shr     edx, 2
 *   mov     [g_eventQueueEnd], edx
 *   jmp     Tail
 * .ret:
 *   ret
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern void MStackPush2RunCountdown_004089e0(void);
extern void MStackBracket7_DispatchAndChain_004b8fa0(void);
extern void StunDownCluster_00451fc0(void);

/* @addr 0x00451f20 */
extern unsigned int g_data_004e7ae8;
void ScaledLoadTwoCallLit_00451f20(void) {
    g_fightGroupHead = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x64);
    MStackPush2RunCountdown_004089e0();
    if (g_framePauseFlag != 0) return;
    MStackBracket7_DispatchAndChain_004b8fa0();
    if (g_framePauseFlag != 0) return;
    g_eventQueueEnd = (unsigned int)&g_data_004e7ae8 >> 2;
    StunDownCluster_00451fc0();
}

/* @addr 0x00451f70 */
extern unsigned int g_data_004e7a78;
void ScaledLoadTwoCallLit_00451f70(void) {
    g_fightGroupHead = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x64);
    MStackPush2RunCountdown_004089e0();
    if (g_framePauseFlag != 0) return;
    MStackBracket7_DispatchAndChain_004b8fa0();
    if (g_framePauseFlag != 0) return;
    g_eventQueueEnd = (unsigned int)&g_data_004e7a78 >> 2;
    StunDownCluster_00451fc0();
}
