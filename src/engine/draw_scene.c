/**
 * Per-frame DrawScene dispatcher.
 *
 * Wraps FlushDrawQueue + the per-renderer EndScene in a timeGetTime
 * accounting block that maintains a running ms-spent counter.
 */
#include "engine/render.h"
#include "platform/win32.h"
#include "portable/mmsystem_shim.h"

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_clampedRendererMode (*(unsigned int *)MK4_VA(unsigned int, 0x4f4b3cu))
#define g_drawSceneTimeMs (*(unsigned int *)MK4_VA(unsigned int, 0x7afa00u))
#endif


/*
 * @addr 0x004b42e0
 *
 * Source case order is 1, 2, 3, 5, 4 (matching the original) so
 * that case 4 ends up last in memory; the original's final case
 * has a slightly different codegen because of that placement.
 */
void DrawScene(void)
{
    g_drawSceneTimeMs -= timeGetTime();
    FlushDrawQueue();
    switch (g_clampedRendererMode) {
        case 1: Renderer1_EndScene_Glide();      break;
        case 2: Renderer2_EndScene_D3D();        break;
        case 3: Renderer3_EndScene_SW_FS();      break;
        case 5: Renderer5_EndScene_SW_FS_Hi();   break;
        case 4: Renderer4_EndScene_SW_Win();     break;
    }
    g_drawSceneTimeMs += timeGetTime();
}
