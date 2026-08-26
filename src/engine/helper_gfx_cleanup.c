/**
 * Auto-extracted during misc_matches reorganization.
 */
#include "engine/scenegraph.h"

/* @addr 0x004b4410 (51b): push 4; 7 calls; clear [g_currentRendererMode] */
extern int Helper_GSM_PlayMusic(int mode);
extern s32 TryInitRenderer(void);
extern void Thunk_FlushDrawQueue(void);
extern void R2_Cleanup(void);
extern void DDraw3_Cleanup(void);
extern void DDraw5_Cleanup(void);
extern void RendererTeardownSW(void);
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern int g_currentRendererMode;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_currentRendererMode (*(int *)MK4_VA(int, 0x4f4b3cu))
#endif

void Helper_GfxCleanup(void) {
    Helper_GSM_PlayMusic(4);
    TryInitRenderer();
    Thunk_FlushDrawQueue();
    R2_Cleanup();
    DDraw3_Cleanup();
    DDraw5_Cleanup();
    RendererTeardownSW();
    g_currentRendererMode = 0;
}

