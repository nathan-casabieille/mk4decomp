/**
 * Auto-split from misc_matchesH.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_xformDirtyFlags (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#endif


/* @addr 0x00435f20 (43b)
 *   call    F
 *   test    eax, eax
 *   jne     .skip2
 *   call    F2
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   test    byte [g_xformDirtyFlags], 1
 *   je      .ret
 *   jmp     T1
 * .skip2:
 *   jmp     +6
 *   ret
 */
extern int Cmp2CallDirtyCall(void);
extern void DualMul10Tail(void);
extern void PrefixThunkInstallSelf3State(void);
extern void Mul10ThresholdQuad(void);
void DualCallPauseDirtyJmp_00435f20(void) {
    if (Cmp2CallDirtyCall() != 0) {
        return;
    }
    DualMul10Tail();
    if (g_framePauseFlag != 0) {
        return;
    }
    if ((g_xformDirtyFlags & 1) != 0) {
        PrefixThunkInstallSelf3State();
    } else {
        Mul10ThresholdQuad();
    }
}

extern void GuardedDualAndFlagToggle(void);
extern void ScaledXorStore_004903b0(void);
extern void ChainSetupBitToggle(void);

/* @addr 0x00490c30 (43b) */
void DualCallPauseDirtyJmp_00490c30(void) {
    GuardedDualAndFlagToggle();
    if (g_framePauseFlag != 0) {
        return;
    }
    if ((g_xformDirtyFlags & 1) == 0) {
        ScaledXorStore_004903b0();
        if (g_framePauseFlag != 0) {
            return;
        }
    }
    ChainSetupBitToggle();
}
