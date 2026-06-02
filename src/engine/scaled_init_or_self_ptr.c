/**
 * Auto-split from misc_matchesY.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_phaseTimer;

/* @addr 0x0044ef10 (64b): same shape as ScaledInitOrSelfPtr_InstallSelfStackReset,
 *                         store=own, jmp=0x44ef50 */
extern void PoseChainAdvanceCluster(void);
void ScaledInitOrSelfPtr_PoseChainAdvanceCluster(void) {
    unsigned char *base = (unsigned char *)(g_baseSel * 4);
    unsigned int ptr = ((ScenegraphNode *)base)->install_flag;
    ((ScenegraphNode *)base)->install_flag = 0;
    if (ptr) {
        PoseChainAdvanceCluster();
        return;
    }
    *(unsigned int *)(base + 8) = (unsigned int)ScaledInitOrSelfPtr_PoseChainAdvanceCluster;
    ((ScenegraphNode *)base)->install_flag = 1;
    g_pendingNodeType = 1;
    g_framePauseFlag = 1;
}
