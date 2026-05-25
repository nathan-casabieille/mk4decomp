/**
 * Boot-phase 95-byte DualCallPauseAddrSetRecurse cluster (6 sister variants).
 *
 * Each variant: 2-call setup chain, then twice dispatch a recursive
 * sibling with different packed-ptr addresses and worktype values.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern void MStackPush2RunCountdown_004089e0(void);
extern void MStackBracket7_DispatchAndChain_004b8fa0(void);

extern void func_004196c0_jj(void);
extern void func_00419780_jj(void);
extern void func_00419840_jj(void);
extern void func_00419980_jj(void);
extern void func_00419a40_jj(void);
extern void func_00419b00_jj(void);
extern unsigned int g_data_004d7918;
extern unsigned int g_data_004d78e8;
extern unsigned int g_data_004d7ac8;
extern unsigned int g_data_004d7b58;
extern unsigned int g_data_004d79d8;
extern unsigned int g_data_004d79a8;
extern unsigned int g_data_004d7978;
extern unsigned int g_data_004d7948;
extern unsigned int g_data_004d7a98;
extern unsigned int g_data_004d7a68;
extern unsigned int g_data_004d7a38;
extern unsigned int g_data_004d7a08;

/* @addr 0x00419720 (95b): addr1=0x4d7918/0xa, recurse 0x4196c0, addr2=0x4d78e8/9 */
void DualCallPauseAddrSetRecurse_00419720(void) {
    MStackPush2RunCountdown_004089e0();
    if (g_framePauseFlag) return;
    MStackBracket7_DispatchAndChain_004b8fa0();
    if (g_framePauseFlag) return;
    g_eventQueueWorkType = 0x0a;
    g_pendingNodeType = (unsigned int)&g_data_004d7918 >> 2;
    func_004196c0_jj();
    if (g_framePauseFlag) return;
    g_eventQueueWorkType = 0x09;
    g_pendingNodeType = (unsigned int)&g_data_004d78e8 >> 2;
    func_004196c0_jj();
}

/* @addr 0x004197e0 (95b): addr1=0x4d7ac8/6, recurse 0x419780, addr2=0x4d7b58/5 */
void DualCallPauseAddrSetRecurse_004197e0(void) {
    MStackPush2RunCountdown_004089e0();
    if (g_framePauseFlag) return;
    MStackBracket7_DispatchAndChain_004b8fa0();
    if (g_framePauseFlag) return;
    g_eventQueueWorkType = 0x06;
    g_pendingNodeType = (unsigned int)&g_data_004d7ac8 >> 2;
    func_00419780_jj();
    if (g_framePauseFlag) return;
    g_eventQueueWorkType = 0x05;
    g_pendingNodeType = (unsigned int)&g_data_004d7b58 >> 2;
    func_00419780_jj();
}

/* @addr 0x004198a0 (95b): addr1=0x4d79d8/0xc, recurse 0x419840, addr2=0x4d79a8/0xb */
void DualCallPauseAddrSetRecurse_004198a0(void) {
    MStackPush2RunCountdown_004089e0();
    if (g_framePauseFlag) return;
    MStackBracket7_DispatchAndChain_004b8fa0();
    if (g_framePauseFlag) return;
    g_eventQueueWorkType = 0x0c;
    g_pendingNodeType = (unsigned int)&g_data_004d79d8 >> 2;
    func_00419840_jj();
    if (g_framePauseFlag) return;
    g_eventQueueWorkType = 0x0b;
    g_pendingNodeType = (unsigned int)&g_data_004d79a8 >> 2;
    func_00419840_jj();
}

/* @addr 0x004199e0 (95b): addr1=0x4d7978/0xe, recurse 0x419980, addr2=0x4d7948/0xd */
void DualCallPauseAddrSetRecurse_004199e0(void) {
    MStackPush2RunCountdown_004089e0();
    if (g_framePauseFlag) return;
    MStackBracket7_DispatchAndChain_004b8fa0();
    if (g_framePauseFlag) return;
    g_eventQueueWorkType = 0x0e;
    g_pendingNodeType = (unsigned int)&g_data_004d7978 >> 2;
    func_00419980_jj();
    if (g_framePauseFlag) return;
    g_eventQueueWorkType = 0x0d;
    g_pendingNodeType = (unsigned int)&g_data_004d7948 >> 2;
    func_00419980_jj();
}

/* @addr 0x00419aa0 (95b): addr1=0x4d7a98/8, recurse 0x419a40, addr2=0x4d7a68/7 */
void DualCallPauseAddrSetRecurse_00419aa0(void) {
    MStackPush2RunCountdown_004089e0();
    if (g_framePauseFlag) return;
    MStackBracket7_DispatchAndChain_004b8fa0();
    if (g_framePauseFlag) return;
    g_eventQueueWorkType = 0x08;
    g_pendingNodeType = (unsigned int)&g_data_004d7a98 >> 2;
    func_00419a40_jj();
    if (g_framePauseFlag) return;
    g_eventQueueWorkType = 0x07;
    g_pendingNodeType = (unsigned int)&g_data_004d7a68 >> 2;
    func_00419a40_jj();
}

/* @addr 0x00419b60 (95b): addr1=0x4d7a38/0x10, recurse 0x419b00, addr2=0x4d7a08/0xf */
void DualCallPauseAddrSetRecurse_00419b60(void) {
    MStackPush2RunCountdown_004089e0();
    if (g_framePauseFlag) return;
    MStackBracket7_DispatchAndChain_004b8fa0();
    if (g_framePauseFlag) return;
    g_eventQueueWorkType = 0x10;
    g_pendingNodeType = (unsigned int)&g_data_004d7a38 >> 2;
    func_00419b00_jj();
    if (g_framePauseFlag) return;
    g_eventQueueWorkType = 0x0f;
    g_pendingNodeType = (unsigned int)&g_data_004d7a08 >> 2;
    func_00419b00_jj();
}
