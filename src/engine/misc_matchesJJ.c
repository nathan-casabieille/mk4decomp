/**
 * Forty-fifth batch of one-off matches.
 * 83b/95b cluster of "CallPauseDirty4ScaledSet" / "DualCallPauseAddrSetRecurse"
 * variants from the entity-init dispatch table.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern packed_ptr g_xformEntityIdx;
extern u32 g_eventQueueEnd;
extern u32 g_eventQueueWorkType;
extern u32 g_pendingNodeType;

extern void SlotInitAndChainLink_004191b0(void);
extern void BootGatedInitInstallPair_00412280(void);
extern void MStackPush2RunCountdown_004089e0(void);
extern void MStackBracket7_DispatchAndChain_004b8fa0(void);

/* === 83b cluster: CallPauseDirty4ScaledSetVariant === */

/* @addr 0x00419780 (83b): val1=0x83, imm=0x11999 */
void CallPauseDirty4ScaledSet_00419780(void) {
    SlotInitAndChainLink_004191b0();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 4) return;
    *(unsigned int *)(g_eventQueueEnd * 4 + 0x30) = 0x83;
    g_walkCallback = (void(*)(void))0x11999;
    *(unsigned int *)(g_xformEntityIdx * 4 + 0x48) = 0x11999;
    g_scaledInit_00542044 = g_eventQueueEnd + 0x15;
    BootGatedInitInstallPair_00412280();
}

/* @addr 0x00419840 (83b): val1=0x86, imm=0x11999 */
void CallPauseDirty4ScaledSet_00419840(void) {
    SlotInitAndChainLink_004191b0();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 4) return;
    *(unsigned int *)(g_eventQueueEnd * 4 + 0x30) = 0x86;
    g_walkCallback = (void(*)(void))0x11999;
    *(unsigned int *)(g_xformEntityIdx * 4 + 0x48) = 0x11999;
    g_scaledInit_00542044 = g_eventQueueEnd + 0x15;
    BootGatedInitInstallPair_00412280();
}

/* @addr 0x00419980 (83b): val1=0x87, imm=0x11999 */
void CallPauseDirty4ScaledSet_00419980(void) {
    SlotInitAndChainLink_004191b0();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 4) return;
    *(unsigned int *)(g_eventQueueEnd * 4 + 0x30) = 0x87;
    g_walkCallback = (void(*)(void))0x11999;
    *(unsigned int *)(g_xformEntityIdx * 4 + 0x48) = 0x11999;
    g_scaledInit_00542044 = g_eventQueueEnd + 0x15;
    BootGatedInitInstallPair_00412280();
}

/* @addr 0x00419a40 (83b): val1=0x82, imm=0x11999 */
void CallPauseDirty4ScaledSet_00419a40(void) {
    SlotInitAndChainLink_004191b0();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 4) return;
    *(unsigned int *)(g_eventQueueEnd * 4 + 0x30) = 0x82;
    g_walkCallback = (void(*)(void))0x11999;
    *(unsigned int *)(g_xformEntityIdx * 4 + 0x48) = 0x11999;
    g_scaledInit_00542044 = g_eventQueueEnd + 0x15;
    BootGatedInitInstallPair_00412280();
}

/* @addr 0x00419b00 (83b): val1=0x88, imm=0x13333 */
void CallPauseDirty4ScaledSet_00419b00(void) {
    SlotInitAndChainLink_004191b0();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 4) return;
    *(unsigned int *)(g_eventQueueEnd * 4 + 0x30) = 0x88;
    g_walkCallback = (void(*)(void))0x13333;
    *(unsigned int *)(g_xformEntityIdx * 4 + 0x48) = 0x13333;
    g_scaledInit_00542044 = g_eventQueueEnd + 0x15;
    BootGatedInitInstallPair_00412280();
}

/* === 95b cluster: DualCallPauseAddrSetRecurseSet === */

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
