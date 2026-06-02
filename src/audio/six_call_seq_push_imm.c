/**
 * Auto-split from misc_matchesCC.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004b2690 (60b): pure call chain - 11 calls + 1 jmp */
extern void TestCallIat(void);
extern void Helper_GfxCleanup(void);
extern void Helper_AppStub_2AE0(void);
extern void Thunk_004b5ac0(void);
extern void Config_SaveToRegistry(void);
extern void Helper_MenuStub_62B0(void);
extern void Helper_AppStub_21C0(void);
extern void AudioShutdownSequence(void);
extern void AuxAudio_Teardown(void);
extern void Helper_GeoStub_5370(void);
extern void TestCallZero(void);
extern void Helper_GeoStub_5A70(void);
void AppShutdown(void) {
    TestCallIat();
    Helper_GfxCleanup();
    Helper_AppStub_2AE0();
    Thunk_004b5ac0();
    Config_SaveToRegistry();
    Helper_MenuStub_62B0();
    Helper_AppStub_21C0();
    AudioShutdownSequence();
    AuxAudio_Teardown();
    Helper_GeoStub_5370();
    TestCallZero();
    Helper_GeoStub_5A70();
}

/* @addr 0x004a1d80 (61b): 6 push/call/add-esp sequences */
extern void TableWalkBoundedCmp(int);
void SixCallSeqPushImm(void) {
    TableWalkBoundedCmp(9);
    TableWalkBoundedCmp(2);
    TableWalkBoundedCmp(3);
    TableWalkBoundedCmp(4);
    TableWalkBoundedCmp(5);
    TableWalkBoundedCmp(7);
}
