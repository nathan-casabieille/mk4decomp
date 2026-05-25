/**
 * Boot-phase 83-byte CallPauseDirty4ScaledSet cluster (5 sister variants).
 *
 * Each variant: call SlotInitAndChainLink; if pause or dirty-bit-2 set, ret;
 * else write state slot val1 + walkCallback imm + scaled-init = queueEnd+0x15;
 * tail-call BootGatedInitInstallPair.
 *
 * Diffs across variants: val1 (0x83/0x86/0x87/0x82/0x88) and imm (0x11999/0x13333).
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern void SlotInitAndChainLink_004191b0(void);
extern void BootGatedInitInstallPair_00412280(void);

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
