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

/* @addr 0x004b2ff0 (58b)
 *   load two dword globals, then move 16-bit args at [esp+4],[esp+8],[esp+0xc]
 *   into 16-bit globals; flush the dwords back too.
 */
extern s16 g_vtxScreenX;
extern s32 g_vtxOut_z;
extern s16 g_vtxScreenP2X;
extern s32 g_vtxOut2_z;
extern unsigned short g_word_007af95c;
extern unsigned short g_word_007af962;
extern unsigned short g_word_007af968;
void CopyArgs16ToGlobals_004b2ff0(unsigned short a, unsigned short b, unsigned short c) {
    g_vtxScreenP2X = g_vtxScreenX;
    g_vtxOut2_z = g_vtxOut_z;
    g_word_007af95c = a;
    g_word_007af962 = b;
    g_word_007af968 = c;
}
