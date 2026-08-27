/**
 * Boot-phase 95-byte DualCallPauseAddrSetRecurse cluster (6 sister variants).
 *
 * Each variant: 2-call setup chain, then twice dispatch a recursive
 * sibling with different packed-ptr addresses and worktype values.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"
#include "portable/mem_model.h"

extern void MStackPush2RunCountdown(void);
extern void MStackBracket7_DispatchAndChain(void);

extern void func_004196c0_jj(void);
extern void func_00419780_jj(void);
extern void func_00419840_jj(void);
extern void func_00419980_jj(void);
extern void func_00419a40_jj(void);
extern void func_00419b00_jj(void);
extern unsigned int g_dispatchSave1185;
extern unsigned int g_dispatchSave1184;
extern unsigned int g_dispatchSave1194;
extern unsigned int g_dispatchSave1197;
extern unsigned int g_dispatchSave1189;
extern unsigned int g_dispatchSave1188;
extern unsigned int g_dispatchSave1187;
extern unsigned int g_dispatchSave1186;
extern unsigned int g_dispatchSave1193;
extern unsigned int g_dispatchSave1192;
extern unsigned int g_dispatchSave1191;
extern unsigned int g_dispatchSave1190;

/* @addr 0x00419720 (95b): addr1=0x4d7918/0xa, recurse 0x4196c0, addr2=0x4d78e8/9 */
void DualCallPauseAddrSetRecurse_func_004196c0_jj(void) {
    MStackPush2RunCountdown();
    if (g_framePauseFlag) return;
    MStackBracket7_DispatchAndChain();
    if (g_framePauseFlag) return;
    g_eventQueueWorkType = 0x0a;
    g_pendingNodeType = (unsigned int)MK4_UNPTR(&g_dispatchSave1185) >> 2;
    func_004196c0_jj();
    if (g_framePauseFlag) return;
    g_eventQueueWorkType = 0x09;
    g_pendingNodeType = (unsigned int)MK4_UNPTR(&g_dispatchSave1184) >> 2;
    func_004196c0_jj();
}

/* @addr 0x004197e0 (95b): addr1=0x4d7ac8/6, recurse 0x419780, addr2=0x4d7b58/5 */
void DualCallPauseAddrSetRecurse_func_00419780_jj(void) {
    MStackPush2RunCountdown();
    if (g_framePauseFlag) return;
    MStackBracket7_DispatchAndChain();
    if (g_framePauseFlag) return;
    g_eventQueueWorkType = 0x06;
    g_pendingNodeType = (unsigned int)MK4_UNPTR(&g_dispatchSave1194) >> 2;
    func_00419780_jj();
    if (g_framePauseFlag) return;
    g_eventQueueWorkType = 0x05;
    g_pendingNodeType = (unsigned int)MK4_UNPTR(&g_dispatchSave1197) >> 2;
    func_00419780_jj();
}

/* @addr 0x004198a0 (95b): addr1=0x4d79d8/0xc, recurse 0x419840, addr2=0x4d79a8/0xb */
void DualCallPauseAddrSetRecurse_func_00419840_jj(void) {
    MStackPush2RunCountdown();
    if (g_framePauseFlag) return;
    MStackBracket7_DispatchAndChain();
    if (g_framePauseFlag) return;
    g_eventQueueWorkType = 0x0c;
    g_pendingNodeType = (unsigned int)MK4_UNPTR(&g_dispatchSave1189) >> 2;
    func_00419840_jj();
    if (g_framePauseFlag) return;
    g_eventQueueWorkType = 0x0b;
    g_pendingNodeType = (unsigned int)MK4_UNPTR(&g_dispatchSave1188) >> 2;
    func_00419840_jj();
}

/* @addr 0x004199e0 (95b): addr1=0x4d7978/0xe, recurse 0x419980, addr2=0x4d7948/0xd */
void DualCallPauseAddrSetRecurse_func_00419980_jj(void) {
    MStackPush2RunCountdown();
    if (g_framePauseFlag) return;
    MStackBracket7_DispatchAndChain();
    if (g_framePauseFlag) return;
    g_eventQueueWorkType = 0x0e;
    g_pendingNodeType = (unsigned int)MK4_UNPTR(&g_dispatchSave1187) >> 2;
    func_00419980_jj();
    if (g_framePauseFlag) return;
    g_eventQueueWorkType = 0x0d;
    g_pendingNodeType = (unsigned int)MK4_UNPTR(&g_dispatchSave1186) >> 2;
    func_00419980_jj();
}

/* @addr 0x00419aa0 (95b): addr1=0x4d7a98/8, recurse 0x419a40, addr2=0x4d7a68/7 */
void DualCallPauseAddrSetRecurse_func_00419a40_jj(void) {
    MStackPush2RunCountdown();
    if (g_framePauseFlag) return;
    MStackBracket7_DispatchAndChain();
    if (g_framePauseFlag) return;
    g_eventQueueWorkType = 0x08;
    g_pendingNodeType = (unsigned int)MK4_UNPTR(&g_dispatchSave1193) >> 2;
    func_00419a40_jj();
    if (g_framePauseFlag) return;
    g_eventQueueWorkType = 0x07;
    g_pendingNodeType = (unsigned int)MK4_UNPTR(&g_dispatchSave1192) >> 2;
    func_00419a40_jj();
}

/* @addr 0x00419b60 (95b): addr1=0x4d7a38/0x10, recurse 0x419b00, addr2=0x4d7a08/0xf */
void DualCallPauseAddrSetRecurse_func_00419b00_jj(void) {
    MStackPush2RunCountdown();
    if (g_framePauseFlag) return;
    MStackBracket7_DispatchAndChain();
    if (g_framePauseFlag) return;
    g_eventQueueWorkType = 0x10;
    g_pendingNodeType = (unsigned int)MK4_UNPTR(&g_dispatchSave1191) >> 2;
    func_00419b00_jj();
    if (g_framePauseFlag) return;
    g_eventQueueWorkType = 0x0f;
    g_pendingNodeType = (unsigned int)MK4_UNPTR(&g_dispatchSave1190) >> 2;
    func_00419b00_jj();
}
