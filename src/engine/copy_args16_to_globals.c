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
#ifndef NON_MATCHING   /* the native build takes src/platform/win32/app_shutdown.c */
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

/* @addr 0x004b2ff0 (58b)
 *   load two dword globals, then move 16-bit args at [esp+4],[esp+8],[esp+0xc]
 *   into 16-bit globals; flush the dwords back too.
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_vtxScreenX;
extern s32 g_vtxOut_z;
extern unsigned int g_vtxScreenP2X;
extern s32 g_vtxOut2_z;
extern unsigned short g_vtxSaved16_a;
extern unsigned short g_vtxSaved16_b;
extern unsigned short g_vtxSaved16_c;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_vtxOut2_z (*(int *)MK4_VA(int, 0x7af988u))
#define g_vtxOut_z (*(int *)MK4_VA(int, 0x7af98cu))
#define g_vtxSaved16_a (*(unsigned short *)MK4_VA(unsigned short, 0x7af95cu))
#define g_vtxSaved16_b (*(unsigned short *)MK4_VA(unsigned short, 0x7af962u))
#define g_vtxSaved16_c (*(unsigned short *)MK4_VA(unsigned short, 0x7af968u))
#define g_vtxScreenP2X (*(unsigned int *)MK4_VA(unsigned int, 0x7af9b8u))
#define g_vtxScreenX (*(unsigned int *)MK4_VA(unsigned int, 0x7af9bcu))
#endif

void CopyArgs16ToGlobals(unsigned short a, unsigned short b, unsigned short c) {
    g_vtxScreenP2X = g_vtxScreenX;
    g_vtxOut2_z = g_vtxOut_z;
    g_vtxSaved16_a = a;
    g_vtxSaved16_b = b;
    g_vtxSaved16_c = c;
}
