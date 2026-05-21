/**
 * Auto-split from misc_matchesCC.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004b2690 (60b): pure call chain - 11 calls + 1 jmp */
extern void TestCallIat_004c44f0(void);
extern void Helper_GfxCleanup(void);
extern void Helper_AppStub_2AE0(void);
extern void Thunk_004b5ac0(void);
extern void RegistryInstallEntry_004ad410(void);
extern void Helper_MenuStub_62B0(void);
extern void Helper_AppStub_21C0(void);
extern void AudioShutdownSequence_004c4240(void);
extern void AuxAudio_Teardown_004ac9b0(void);
extern void Helper_GeoStub_5370(void);
extern void TestCallZero_004b1de0(void);
extern void Helper_GeoStub_5A70(void);
void AppShutdown(void) {
    TestCallIat_004c44f0();
    Helper_GfxCleanup();
    Helper_AppStub_2AE0();
    Thunk_004b5ac0();
    RegistryInstallEntry_004ad410();
    Helper_MenuStub_62B0();
    Helper_AppStub_21C0();
    AudioShutdownSequence_004c4240();
    AuxAudio_Teardown_004ac9b0();
    Helper_GeoStub_5370();
    TestCallZero_004b1de0();
    Helper_GeoStub_5A70();
}

/* @addr 0x004a1bf0 (65b): 3-stage call chain with byte/byte/byte stores */
extern int TestQueueGateState_004a1ba0(void);
extern int InputPollFlagBits_004a1b00(void);
extern int InputPollFlagBitsHalf_004a1b50(void);
extern unsigned char g_byte_00543590;
int TripleCallByteCheck_004a1bf0(void) {
    if (TestQueueGateState_004a1ba0() != 0) {
        g_byte_00543590 = 1;
        return 1;
    }
    if (InputPollFlagBits_004a1b00() != 0) {
        g_byte_00543590 = 1;
        return 1;
    }
    if (InputPollFlagBitsHalf_004a1b50() != 0) {
        g_byte_00543590 = 2;
        return 1;
    }
    return 0;
}
