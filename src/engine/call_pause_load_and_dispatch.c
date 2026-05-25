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

/* @addr 0x004235f0 (64b)
 *   call F; pause → ret;
 *   load g_state_0052ab40 → walk; and 4 → g_xformScratch94;
 *   jz → call F2; pause → ret;
 *   set [g_eventQueueNotMask] = 0x1002f; jmp T.
 */
extern void ZeroSlotsGatedDispatch_00423720(void);
extern unsigned int g_state_0052ab40;
extern unsigned int g_xformScratch94;
extern void ScaledLoadCmp0fJmp_004930e0(void);
extern void HitReactionDispatcher_0045f650(void);
void CallPauseLoadAndDispatch_004235f0(void) {
    unsigned int v;
    ZeroSlotsGatedDispatch_00423720();
    if (g_framePauseFlag != 0) return;
    v = g_state_0052ab40;
    g_walkCallback = (void (*)(void))v;
    v = v & 4;
    g_xformScratch94 = v;
    if (v != 0) {
        ScaledLoadCmp0fJmp_004930e0();
        if (g_framePauseFlag != 0) return;
    }
    g_eventQueueNotMask = 0x1002f;
    HitReactionDispatcher_0045f650();
}
