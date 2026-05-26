/**
 * Auto-split from misc_matchesY.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_phaseTimer_00537e94;

/* @addr 0x0044ef10 (64b): same shape as ScaledInitOrSelfPtr_00421f00,
 *                         store=own, jmp=0x44ef50 */
extern void PoseChainAdvanceCluster_0044ef50(void);
void ScaledInitOrSelfPtr_0044ef10(void) {
    unsigned char *base = (unsigned char *)(g_baseSel_00542060 * 4);
    unsigned int ptr = ((ScenegraphNode *)base)->install_flag;
    ((ScenegraphNode *)base)->install_flag = 0;
    if (ptr) {
        PoseChainAdvanceCluster_0044ef50();
        return;
    }
    *(unsigned int *)(base + 8) = (unsigned int)ScaledInitOrSelfPtr_0044ef10;
    ((ScenegraphNode *)base)->install_flag = 1;
    g_pendingNodeType = 1;
    g_framePauseFlag = 1;
}
