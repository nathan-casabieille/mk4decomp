/**
 * Auto-split from misc_matchesP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00487150 (46b)
 *   mov     eax, [g_baseSel]
 *   mov     eax, [eax*4 + 0x30]
 *   test    eax, eax
 *   mov     [g_walkCallback], eax
 *   jne     +5
 *   jmp     T1
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +5
 *   jmp     T2
 *   ret
 */
extern void RoundResultSlotInitTable(void);
extern void Wrapper_ScaledChainPushCall_004ef8c8(void);
extern void GuardedSeq_CmpJmpTwoBranch_then_Wrapper_ScaledChainPushCall(void);
void ScaledTestCallPauseJmpFar(void) {
    unsigned int v = *(unsigned int *)(g_baseSel * 4 + 0x30);
    g_walkCallback = (void (*)(void))v;
    if (v == 0) {
        GuardedSeq_CmpJmpTwoBranch_then_Wrapper_ScaledChainPushCall();
        return;
    }
    RoundResultSlotInitTable();
    if (g_framePauseFlag != 0) return;
    Wrapper_ScaledChainPushCall_004ef8c8();
}
