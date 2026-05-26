/**
 * Auto-split from misc_matchesBB.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004a12e0 (63b)
 *   push 0x22f; call F1; add esp; call F2; pause → ret;
 *   push 0x15; push lit; call F3; mov ax,[m16]; add esp 8; push eax;
 *   call F4; add esp 4; jmp T; ret.
 */
extern void TripleStageRollback_00404a50(int);
extern void RoundWinTransition_0049e7e0(void);
extern int StoreTwoCall_0049cb40(void *, int);
extern int TaggedSceneDispatch_004be690(unsigned short);
extern void *g_const_004a0060;
extern unsigned short g_word_004e2860;
extern void InstallSelf3WaySubDec_004a1320(void);
void PushCallPauseStorePushDispatch_004a12e0(void) {
    TripleStageRollback_00404a50(0x22f);
    RoundWinTransition_0049e7e0();
    if (g_framePauseFlag) return;
    StoreTwoCall_0049cb40(&g_const_004a0060, 0x15);
    TaggedSceneDispatch_004be690(g_word_004e2860);
    ((int (*)(void))InstallSelf3WaySubDec_004a1320)();
}
