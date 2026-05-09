/**
 * Per-frame DrawScene dispatcher.
 *
 * Wraps FlushDrawQueue + the per-renderer EndScene in a timeGetTime
 * accounting block that maintains a running ms-spent counter.
 */
#include "engine/render.h"
#include "platform/win32.h"
#include <mmsystem.h>

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
