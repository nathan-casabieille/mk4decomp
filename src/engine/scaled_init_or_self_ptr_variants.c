/**
 * Auto-split from misc_matchesZ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x00474b10 (64b): ScaledInitOrSelfPtr, store=own, jmp=0x474b50 */
extern void NetEntityScanAndPunish(void);
void ScaledInitOrSelfPtr_NetEntityScanAndPunish(void) {
    unsigned char *base = (unsigned char *)(g_baseSel * 4);
    unsigned int ptr = ((ScenegraphNode *)base)->install_flag;
    ((ScenegraphNode *)base)->install_flag = 0;
    if (ptr) {
        NetEntityScanAndPunish();
        return;
    }
    *(unsigned int *)(base + 8) = (unsigned int)ScaledInitOrSelfPtr_NetEntityScanAndPunish;
    ((ScenegraphNode *)base)->install_flag = 1;
    g_pendingNodeType = 1;
    g_framePauseFlag = 1;
}

/* @addr 0x00489130 (64b): ScaledInitOrSelfPtr, store=own, jmp=0x41f780 */
extern void func_0041f780_z(void);
void ScaledInitOrSelfPtr_func_0041f780_z(void) {
    unsigned char *base = (unsigned char *)(g_baseSel * 4);
    unsigned int ptr = ((ScenegraphNode *)base)->install_flag;
    ((ScenegraphNode *)base)->install_flag = 0;
    if (ptr) {
        func_0041f780_z();
        return;
    }
    *(unsigned int *)(base + 8) = (unsigned int)ScaledInitOrSelfPtr_func_0041f780_z;
    ((ScenegraphNode *)base)->install_flag = 1;
    g_pendingNodeType = 1;
    g_framePauseFlag = 1;
}

/* @addr 0x00421f00 (64b): ScaledInitOrSelfPtr, store=own, jmp=0x421f40 */
extern void InstallSelfStackReset(void);
void ScaledInitOrSelfPtr_InstallSelfStackReset(void) {
    unsigned char *base = (unsigned char *)(g_baseSel * 4);
    unsigned int ptr = ((ScenegraphNode *)base)->install_flag;
    ((ScenegraphNode *)base)->install_flag = 0;
    if (ptr) {
        InstallSelfStackReset();
        return;
    }
    *(unsigned int *)(base + 8) = (unsigned int)ScaledInitOrSelfPtr_InstallSelfStackReset;
    ((ScenegraphNode *)base)->install_flag = 1;
    g_pendingNodeType = 1;
    g_framePauseFlag = 1;
}

/* @addr 0x00428950 (64b): ScaledInitOrSelfPtr, store=own, jmp=0x428850 */
extern void CallPauseDirty1JmpDirty4StackPush_GuardedSeq_GuardedChainCmpDualBitXor_then_ScaledIncCmpJmp(void);
void ScaledInitOrSelfPtr_CallPauseDirty1JmpDirty4StackPush(void) {
    unsigned char *base = (unsigned char *)(g_baseSel * 4);
    unsigned int ptr = ((ScenegraphNode *)base)->install_flag;
    ((ScenegraphNode *)base)->install_flag = 0;
    if (ptr) {
        CallPauseDirty1JmpDirty4StackPush_GuardedSeq_GuardedChainCmpDualBitXor_then_ScaledIncCmpJmp();
        return;
    }
    *(unsigned int *)(base + 8) = (unsigned int)ScaledInitOrSelfPtr_CallPauseDirty1JmpDirty4StackPush;
    ((ScenegraphNode *)base)->install_flag = 1;
    g_pendingNodeType = 1;
    g_framePauseFlag = 1;
}

/* @addr 0x00429680 (64b): ScaledInitOrSelfPtr, store=own, jmp=0x41f780 */
extern void StackPopDispatchTagged(void);
void ScaledInitOrSelfPtr_StackPopDispatchTagged(void) {
    unsigned char *base = (unsigned char *)(g_baseSel * 4);
    unsigned int ptr = ((ScenegraphNode *)base)->install_flag;
    ((ScenegraphNode *)base)->install_flag = 0;
    if (ptr) {
        StackPopDispatchTagged();
        return;
    }
    *(unsigned int *)(base + 8) = (unsigned int)ScaledInitOrSelfPtr_StackPopDispatchTagged;
    ((ScenegraphNode *)base)->install_flag = 1;
    g_pendingNodeType = 1;
    g_framePauseFlag = 1;
}

/* @addr 0x00442d90 (64b): ScaledInitOrSelfPtr, store=own, jmp=0x442dd0 */
extern void DualSeqLoopDispatch(void);
void ScaledInitOrSelfPtr_DualSeqLoopDispatch(void) {
    unsigned char *base = (unsigned char *)(g_baseSel * 4);
    unsigned int ptr = ((ScenegraphNode *)base)->install_flag;
    ((ScenegraphNode *)base)->install_flag = 0;
    if (ptr) {
        DualSeqLoopDispatch();
        return;
    }
    *(unsigned int *)(base + 8) = (unsigned int)ScaledInitOrSelfPtr_DualSeqLoopDispatch;
    ((ScenegraphNode *)base)->install_flag = 1;
    g_pendingNodeType = 1;
    g_framePauseFlag = 1;
}
