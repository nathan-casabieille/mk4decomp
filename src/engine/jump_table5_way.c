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

/* @addr 0x004b41c0 (64b): 5-way jump-table dispatcher.
 *   call F; eax=arg-1; if (eax > 4) ret; jmp [tab + eax*4]
 *   table swaps entries 4<->5 (table[3]=case5, table[4]=case4).
 */
extern int Renderer_GetMode(void);
extern void EarlyOutDualPushIATStore_004b4600(void);
extern void VtRelease_Modal_004ad590(void);
extern void Renderer3_EndScene_SW_FS(void);
extern void Renderer5_EndScene_SW_FS_Hi(void);
extern void Renderer4_EndScene_SW_Win(void);
void JumpTable5Way_004b41c0(void) {
    switch (Renderer_GetMode()) {
        case 1: EarlyOutDualPushIATStore_004b4600(); return;
        case 2: VtRelease_Modal_004ad590(); return;
        case 3: Renderer3_EndScene_SW_FS(); return;
        case 5: Renderer5_EndScene_SW_FS_Hi(); return;
        case 4: Renderer4_EndScene_SW_Win(); return;
    }
}
