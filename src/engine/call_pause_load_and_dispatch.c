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

/* @addr 0x004235f0 (64b)
 *   call F; pause → ret;
 *   load g_or → walk; and 4 → g_xformScratch94;
 *   jz → call F2; pause → ret;
 *   set [g_eventQueueNotMask] = 0x1002f; jmp T.
 */
extern void ZeroSlotsGatedDispatch(void);
extern unsigned int g_or;
extern unsigned int g_xformScratch94;
extern void ScaledLoadCmp0fJmp(void);
extern void HitReactionDispatcher(void);
void CallPauseLoadAndDispatch(void) {
    unsigned int v;
    ZeroSlotsGatedDispatch();
    if (g_framePauseFlag != 0) return;
    v = g_or;
    g_walkCallback = (void (*)(void))v;
    v = v & 4;
    g_xformScratch94 = v;
    if (v != 0) {
        ScaledLoadCmp0fJmp();
        if (g_framePauseFlag != 0) return;
    }
    g_eventQueueNotMask = 0x1002f;
    HitReactionDispatcher();
}
