/**
 * Auto-split from misc_matchesBB.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004a12e0 (63b)
 *   push 0x22f; call F1; add esp; call F2; pause → ret;
 *   push 0x15; push lit; call F3; mov ax,[m16]; add esp 8; push eax;
 *   call F4; add esp 4; jmp T; ret.
 */
extern void TripleStageRollback(int);
extern void RoundWinTransition(void);
extern int StoreTwoCall(void *, int);
extern int TaggedSceneDispatch(unsigned short);
extern void *g_const_004a0060;
extern unsigned short g_word_004e2860;
extern void InstallSelf3WaySubDec(void);
void PushCallPauseStorePushDispatch(void) {
    TripleStageRollback(0x22f);
    RoundWinTransition();
    if (g_framePauseFlag) return;
    StoreTwoCall(&g_const_004a0060, 0x15);
    TaggedSceneDispatch(g_word_004e2860);
    ((int (*)(void))InstallSelf3WaySubDec)();
}
