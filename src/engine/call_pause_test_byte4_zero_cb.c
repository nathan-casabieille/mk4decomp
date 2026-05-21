/**
 * Auto-split from misc_matchesY.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_state_004d57ac;
extern unsigned int g_state_00537e94;
extern packed_ptr g_fightGroupHead;

/* @addr 0x00451a60 (62b)
 *   call F1; pause → ret
 *   testb 4,[dirty]; je → ret
 *   call F2; pause → ret
 *   call F3; pause → ret
 *   mov [g_walkCallback], 0
 *   ret
 */
extern void SetJmp_00405420(void);
extern void MStackPush2RunCountdown_004089e0(void);
extern void MStackBracket7_DispatchAndChain_004b8fa0(void);
void CallPauseTestByte4ZeroCB_00451a60(void) {
    SetJmp_00405420();
    if (g_framePauseFlag) return;
    if (!(g_xformDirtyFlags & 4)) return;
    MStackPush2RunCountdown_004089e0();
    if (g_framePauseFlag) return;
    MStackBracket7_DispatchAndChain_004b8fa0();
    if (g_framePauseFlag) return;
    g_walkCallback = 0;
}
