/**
 * Auto-split from misc_matchesCC.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
#endif

/* @addr 0x004b2690 (60b): pure call chain - 11 calls + 1 jmp */
extern void TestCallIat(void);
extern void Helper_GfxCleanup(void);
extern void Helper_AppStub_2AE0(void);
extern void Thunk_AppInit_Misc2(void);
extern void Config_SaveToRegistry(void);
extern void Helper_MenuStub_62B0(void);
extern void Helper_AppStub_21C0(void);
extern void AudioShutdownSequence(void);
extern void AuxAudio_Teardown(void);
extern void Helper_GeoStub_5370(void);
extern void TestCallZero(void);
extern void Helper_GeoStub_5A70(void);
#ifndef NON_MATCHING /* stale QQ-split copy */
void AppShutdown(void) {
    TestCallIat();
    Helper_GfxCleanup();
    Helper_AppStub_2AE0();
    Thunk_AppInit_Misc2();
    Config_SaveToRegistry();
    Helper_MenuStub_62B0();
    Helper_AppStub_21C0();
    AudioShutdownSequence();
    AuxAudio_Teardown();
    Helper_GeoStub_5370();
    TestCallZero();
    Helper_GeoStub_5A70();
}
#endif

/* @addr 0x004a1bf0 (65b): 3-stage call chain with byte/byte/byte stores */
extern int TestQueueGateState(void);
extern int InputPollFlagBits(void);
extern int InputPollFlagBitsHalf(void);
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned char g_gtModeFlag;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_gtModeFlag (*(unsigned char *)MK4_VA(unsigned char, 0x543590u))
#endif

int TripleCallByteCheck(void) {
    if (TestQueueGateState() != 0) {
        g_gtModeFlag = 1;
        return 1;
    }
    if (InputPollFlagBits() != 0) {
        g_gtModeFlag = 1;
        return 1;
    }
    if (InputPollFlagBitsHalf() != 0) {
        g_gtModeFlag = 2;
        return 1;
    }
    return 0;
}
