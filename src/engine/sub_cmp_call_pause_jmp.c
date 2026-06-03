/**
 * Auto-split from misc_matchesO.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x0042fc40 (50b)
 *   mov     eax, [g_eventQueueWorkType]
 *   mov     ecx, [g_acc_00542078]
 *   sub     eax, 0x0a3d
 *   cmp     ecx, eax
 *   mov     [g_eventQueueWorkType], eax
 *   jle     +5
 *   jmp     T1
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +5
 *   jmp     T2
 *   ret
 */
extern unsigned int g_acc_00542078;
extern void GuardedSeq_DualMulScaleStore_then_PhaseInstall2DInterpDispatch_0042fb80(void);
extern void PoseBlendDriver(void);
extern void PhaseInstall2DInterpDispatch(void);
void SubCmpCallPauseJmp(void) {
    unsigned int new_wt;
    int acc;
    new_wt = g_eventQueueWorkType;
    new_wt -= 0x0a3d;
    acc = (int)g_acc_00542078;
    g_eventQueueWorkType = new_wt;
    if (acc > (int)new_wt) {
        GuardedSeq_DualMulScaleStore_then_PhaseInstall2DInterpDispatch_0042fb80();
        return;
    }
    PoseBlendDriver();
    if (g_framePauseFlag != 0) return;
    PhaseInstall2DInterpDispatch();
}
