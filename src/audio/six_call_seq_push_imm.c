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
extern void Config_SaveToRegistry(void);
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
    Config_SaveToRegistry();
    Helper_MenuStub_62B0();
    Helper_AppStub_21C0();
    AudioShutdownSequence_004c4240();
    AuxAudio_Teardown_004ac9b0();
    Helper_GeoStub_5370();
    TestCallZero_004b1de0();
    Helper_GeoStub_5A70();
}

/* @addr 0x004a1d80 (61b): 6 push/call/add-esp sequences */
extern void TableWalkBoundedCmp_004bd890(int);
void SixCallSeqPushImm_004a1d80(void) {
    TableWalkBoundedCmp_004bd890(9);
    TableWalkBoundedCmp_004bd890(2);
    TableWalkBoundedCmp_004bd890(3);
    TableWalkBoundedCmp_004bd890(4);
    TableWalkBoundedCmp_004bd890(5);
    TableWalkBoundedCmp_004bd890(7);
}
