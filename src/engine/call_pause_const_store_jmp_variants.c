/**
 * Auto-split from misc_matches4.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004350f0 (30b)
 *   call    Setup
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     ret_label
 *   mov     [g_eventQueueChild], 0x1e
 *   jmp     +3
 *   ret
 */
extern void MultiThunkDispatcher_00460470(void);
extern void InstallSelfPair_00435110(void);
void CallPauseConstStoreJmp_004350f0(void) {
    MultiThunkDispatcher_00460470();
    if (g_framePauseFlag) return;
    g_eventQueueChild = 0x1e;
    InstallSelfPair_00435110();
}

/* @addr 0x00438170 (30b): same shape, value=0x78 */
extern void Push80SetWalkNegDualCallPop_004393b0(void);
extern void InstallSelfWaitCmp_00438190(void);
void CallPauseConstStoreJmp_00438170(void) {
    Push80SetWalkNegDualCallPop_004393b0();
    if (g_framePauseFlag) return;
    g_eventQueueChild = 0x78;
    InstallSelfWaitCmp_00438190();
}

/* @addr 0x00481360 (30b): same shape, store walkCallback=0xb5 */
extern void BootChainMaskAndDispatch_00416cb0(void);
extern void MStackBitLoopTripleCall_0049cc30(void);
void CallPauseConstStoreJmp_00481360(void) {
    BootChainMaskAndDispatch_00416cb0();
    if (g_framePauseFlag) return;
    g_walkCallback = (void(*)(void))0xb5;
    MStackBitLoopTripleCall_0049cc30();
}
