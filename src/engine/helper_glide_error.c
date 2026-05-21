/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/*
 * @addr 0x004b5120 (97b engine.geo) - DirectDraw release helper:
 *   close glide scene, dual-push IAT store, query state, free
 *   primary if present (calling virt vt[0x38] when set), null the
 *   three trackers and reinit the dsound buffer.
 */
void Helper_GlideError(void) {
    Renderer1_EndScene_Glide();
    EarlyOutDualPushIATStore_004b4600();
    ((int(*)(int))Helper_GlidePostInit)(0);
    if (g_x_007b0000 != 0) {
        if (g_x_007affff8 != 0) {
            if (g_x_007b0038 != 0) {
                ((void(*)(void))g_x_007b0038)();
            }
        }
        ((void(__stdcall *)(unsigned int))g_iat_004d205c)(g_x_007b0000);
        g_x_007b0000 = 0;
    }
    DSoundBufferInit146_004b5190();
    g_x_007affff8 = 0;
    g_x_007affff4 = 0;
}

