/**
 * Auto-split from misc_matchesCC.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

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

/* @addr 0x004b4600 (65b)
 *   if (g_renderer1_active != 0 && g_renderer1_busy != 0):
 *     if eax == 2: push 1, push 1, call IAT, clear g_renderer1_busy;
 *     else:        push 0, push 0, call IAT, clear g_renderer1_busy;
 *   ret.
 */
extern int g_renderer1_active;
extern int g_renderer1_busy;
extern void (__stdcall *g_fnptr_007b0040)(int, int);
void EarlyOutDualPushIATStore(void) {
    unsigned int v;
    if (g_renderer1_active == 0) return;
    v = g_renderer1_busy;
    if (v == 0) return;
    if (v == 2) {
        g_fnptr_007b0040(1, 1);
        g_renderer1_busy = 0;
        return;
    }
    g_fnptr_007b0040(0, 0);
    g_renderer1_busy = 0;
}
