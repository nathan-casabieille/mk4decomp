/**
 * 2 "scaled load + two guarded calls + literal install + jmp" (66b).
 *
 * Pattern:
 *   mov     eax, [g_baseSel]
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

extern unsigned int g_baseSel;
extern void MStackPush2RunCountdown(void);
extern void MStackBracket7_DispatchAndChain(void);
extern void StunDownCluster(void);

/* @addr 0x00451f20 */
extern unsigned int g_dispatchSave1259;
void ScaledLoadTwoCallLit_00451f20(void) {
    g_fightGroupHead = *(unsigned int *)(g_baseSel * 4 + 0x64);
    MStackPush2RunCountdown();
    if (g_framePauseFlag != 0) return;
    MStackBracket7_DispatchAndChain();
    if (g_framePauseFlag != 0) return;
    g_eventQueueEnd = (unsigned int)&g_dispatchSave1259 >> 2;
    StunDownCluster();
}

/* @addr 0x00451f70 */
extern unsigned int g_dispatchSave1258;
void ScaledLoadTwoCallLit_00451f70(void) {
    g_fightGroupHead = *(unsigned int *)(g_baseSel * 4 + 0x64);
    MStackPush2RunCountdown();
    if (g_framePauseFlag != 0) return;
    MStackBracket7_DispatchAndChain();
    if (g_framePauseFlag != 0) return;
    g_eventQueueEnd = (unsigned int)&g_dispatchSave1258 >> 2;
    StunDownCluster();
}
