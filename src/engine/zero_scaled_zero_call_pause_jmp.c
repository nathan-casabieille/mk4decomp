/**
 * Auto-split from misc_matchesP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x0045fa90 (46b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     [g_walkCallback], 0
 *   mov     [eax*4 + 0x28], 0
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +5
 *   jmp     +3
 *   ret
 */
extern void CallPauseScaledStoreCopyJmp(void);
extern void SlotPhaseDispatcherBigSwitch(void);
void ZeroScaledZeroCallPauseJmp(void) {
    g_walkCallback = (void (*)(void))0;
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_idx = 0;
    CallPauseScaledStoreCopyJmp();
    if (g_framePauseFlag != 0) return;
    SlotPhaseDispatcherBigSwitch();
}
