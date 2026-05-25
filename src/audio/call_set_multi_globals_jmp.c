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

/* @addr 0x004a9230 (64b): call F + load 1, 0; set 5 globals; jmp T. */
extern void DrainQueueCallEach_004a1ec0(void);
extern unsigned int g_tickFlagF;
extern unsigned int g_phaseIdx_0053a50c;
extern unsigned int g_state_0054355c_hh;
extern unsigned int g_state_00543710_hh;
extern unsigned int g_counter_0054359c;
extern unsigned int g_counter_005433c8;
extern unsigned char g_byte_00543834;
extern void PendingMatch_004a93c0(void);
void CallSetMultiGlobalsJmp_004a9230(void) {
    DrainQueueCallEach_004a1ec0();
    g_tickFlagF = 2;
    g_phaseIdx_0053a50c = 0x0e;
    g_state_0054355c_hh = 1;
    g_state_00543710_hh = 1;
    g_counter_0054359c = 0;
    g_counter_005433c8 = 0;
    g_byte_00543834 = 1;
    PendingMatch_004a93c0();
}
