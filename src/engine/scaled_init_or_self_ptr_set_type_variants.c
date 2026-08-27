/**
 * Auto-split from misc_matchesKK.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"
#include "portable/code_va.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* === ScaledInitOrSelfPtrSetType cluster (68b each) === */

/* @addr 0x00434d60: jmp=0x00436120, type=8, ptr=own */
extern void ThresholdInitInstallSelfChain(void);
extern void ScaledInitOrSelfPtrSetType_00434d60(void);
void ScaledInitOrSelfPtrSetType_00434d60(void) {
    unsigned char *base = (unsigned char *)(g_baseSel * 4);
    unsigned int v = ((ScenegraphNode *)base)->install_flag;
    ((ScenegraphNode *)base)->install_flag = 0;
    if (v != 0) {
        ThresholdInitInstallSelfChain();
        return;
    }
    *(unsigned int *)(base + 8) = MK4_CODE_VA(ScaledInitOrSelfPtrSetType_00434d60);
    ((ScenegraphNode *)base)->install_flag = 1;
    g_pendingNodeType = 8;
    g_framePauseFlag = 1;
}

/* @addr 0x0046a5e0: jmp=0x0046a630, type=3, ptr=own */
extern void QuadEntryGateChain(void);
extern void ScaledInitOrSelfPtrSetType_0046a5e0(void);
void ScaledInitOrSelfPtrSetType_0046a5e0(void) {
    unsigned char *base = (unsigned char *)(g_baseSel * 4);
    unsigned int v = ((ScenegraphNode *)base)->install_flag;
    ((ScenegraphNode *)base)->install_flag = 0;
    if (v != 0) {
        QuadEntryGateChain();
        return;
    }
    *(unsigned int *)(base + 8) = MK4_CODE_VA(ScaledInitOrSelfPtrSetType_0046a5e0);
    ((ScenegraphNode *)base)->install_flag = 1;
    g_pendingNodeType = 3;
    g_framePauseFlag = 1;
}

/* @addr 0x0047a620: jmp=0x0047a670, type=0xa, ptr=own */
extern void TripleSubInstallSelfPair(void);
extern void ScaledInitOrSelfPtrSetType_0047a620(void);
void ScaledInitOrSelfPtrSetType_0047a620(void) {
    unsigned char *base = (unsigned char *)(g_baseSel * 4);
    unsigned int v = ((ScenegraphNode *)base)->install_flag;
    ((ScenegraphNode *)base)->install_flag = 0;
    if (v != 0) {
        TripleSubInstallSelfPair();
        return;
    }
    *(unsigned int *)(base + 8) = MK4_CODE_VA(ScaledInitOrSelfPtrSetType_0047a620);
    ((ScenegraphNode *)base)->install_flag = 1;
    g_pendingNodeType = 0xa;
    g_framePauseFlag = 1;
}
