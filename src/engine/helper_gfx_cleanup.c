/**
 * Auto-extracted during misc_matches reorganization.
 */
#include "engine/scenegraph.h"

/* @addr 0x004b4410 (51b): push 4; 7 calls; clear [g_clampedRendererMode] */
extern int Helper_GSM_PlayMusic(int mode);
extern s32 TryInitRenderer(void);
extern void Thunk_004bf320(void);
extern void R2_Cleanup(void);
extern void DDraw3_Cleanup(void);
extern void DDraw5_Cleanup(void);
extern void RendererTeardownSW_004b2a40(void);
extern int g_clampedRendererMode;
void Helper_GfxCleanup(void) {
    Helper_GSM_PlayMusic(4);
    TryInitRenderer();
    Thunk_004bf320();
    R2_Cleanup();
    DDraw3_Cleanup();
    DDraw5_Cleanup();
    RendererTeardownSW_004b2a40();
    g_clampedRendererMode = 0;
}

