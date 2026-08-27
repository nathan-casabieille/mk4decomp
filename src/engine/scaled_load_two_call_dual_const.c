/**
 * 2 "scaled load + two guarded calls + dual const store" (67 bytes).
 *
 * Pattern:
 *   mov     eax, [g_baseSel]
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
 *   mov     [g_chainAccumCur], 3
 * .ret:
 *   ret
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_chainAccumCur;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_chainAccumCur (*(unsigned int *)MK4_VA(unsigned int, 0x542078u))
#define g_fightGroupHead (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif


extern void MStackPush2RunCountdown(void);
extern void MStackBracket7_DispatchAndChain(void);

/* @addr 0x0044ba30 */
void ScaledLoadTwoCallDualConst_MStackPush2RunCountdown_then_MStackBracket7_DispatchAndChain_0044ba30(void) {
    g_fightGroupHead = *(unsigned int*)MK4_PTR((g_baseSel * 4 + 0x4c));
    MStackPush2RunCountdown();
    if (g_framePauseFlag) return;
    MStackBracket7_DispatchAndChain();
    if (g_framePauseFlag) return;
    g_walkCallback = (void(*)(void))2;
    g_chainAccumCur = 3;
}

/* @addr 0x00467c30 */
void ScaledLoadTwoCallDualConst_MStackPush2RunCountdown_then_MStackBracket7_DispatchAndChain_00467c30(void) {
    g_fightGroupHead = *(unsigned int*)MK4_PTR((g_baseSel * 4 + 0x4c));
    MStackPush2RunCountdown();
    if (g_framePauseFlag) return;
    MStackBracket7_DispatchAndChain();
    if (g_framePauseFlag) return;
    g_walkCallback = (void(*)(void))2;
    g_chainAccumCur = 3;
}
