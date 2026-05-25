/**
 * Auto-split from misc_matchesKK.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* === ScaledInitOrSelfPtrSetType cluster (68b each) === */

/* @addr 0x00434d60: jmp=0x00436120, type=8, ptr=own */
extern void ThresholdInitInstallSelfChain_00436120(void);
extern void ScaledInitOrSelfPtrSetType_00434d60(void);
void ScaledInitOrSelfPtrSetType_00434d60(void) {
    unsigned char *base = (unsigned char *)(g_baseSel_00542060 * 4);
    unsigned int v = *(unsigned int *)(base + 0x84);
    *(unsigned int *)(base + 0x84) = 0;
    if (v != 0) {
        ThresholdInitInstallSelfChain_00436120();
        return;
    }
    *(unsigned int *)(base + 8) = (unsigned int)&ScaledInitOrSelfPtrSetType_00434d60;
    *(unsigned int *)(base + 0x84) = 1;
    g_pendingNodeType = 8;
    g_framePauseFlag = 1;
}

/* @addr 0x0046a5e0: jmp=0x0046a630, type=3, ptr=own */
extern void QuadEntryGateChain_0046a630(void);
extern void ScaledInitOrSelfPtrSetType_0046a5e0(void);
void ScaledInitOrSelfPtrSetType_0046a5e0(void) {
    unsigned char *base = (unsigned char *)(g_baseSel_00542060 * 4);
    unsigned int v = *(unsigned int *)(base + 0x84);
    *(unsigned int *)(base + 0x84) = 0;
    if (v != 0) {
        QuadEntryGateChain_0046a630();
        return;
    }
    *(unsigned int *)(base + 8) = (unsigned int)&ScaledInitOrSelfPtrSetType_0046a5e0;
    *(unsigned int *)(base + 0x84) = 1;
    g_pendingNodeType = 3;
    g_framePauseFlag = 1;
}

/* @addr 0x0047a620: jmp=0x0047a670, type=0xa, ptr=own */
extern void TripleSubInstallSelfPair_0047a670(void);
extern void ScaledInitOrSelfPtrSetType_0047a620(void);
void ScaledInitOrSelfPtrSetType_0047a620(void) {
    unsigned char *base = (unsigned char *)(g_baseSel_00542060 * 4);
    unsigned int v = *(unsigned int *)(base + 0x84);
    *(unsigned int *)(base + 0x84) = 0;
    if (v != 0) {
        TripleSubInstallSelfPair_0047a670();
        return;
    }
    *(unsigned int *)(base + 8) = (unsigned int)&ScaledInitOrSelfPtrSetType_0047a620;
    *(unsigned int *)(base + 0x84) = 1;
    g_pendingNodeType = 0xa;
    g_framePauseFlag = 1;
}
