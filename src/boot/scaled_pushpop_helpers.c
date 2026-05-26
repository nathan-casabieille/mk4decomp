/**
 * Boot-phase scaled save-restore wrappers.
 *
 * Three related "push global on mstack, call helper, restore global" wrappers
 * that bracket various scaled-init operations. Each pushes either
 * g_scaledInit_00542044 or g_xformEntityIdx onto the mstack, performs a
 * conditional update + callback dispatch, then pops the saved value back.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x004059a0 (90b)
 *   Push g_scaledInit on stack[idx*4]; load scaled[+0x18];
 *   if non-zero, set scaled, call F, pause-test;
 *   then pop stack back into g_scaledInit. Standard "save-restore" wrapper.
 */
extern void ScaledAndMaskInitJmp_00405a00(void);
void PushPopScaled18_004059a0(void) {
    unsigned int v;
    g_matrixStackTop++;
    *(unsigned int *)(g_matrixStackTop * 4) = g_scaledInit_00542044;
    v = ((ScenegraphNode *)(g_scaledInit_00542044 * 4))->child_chain;
    g_walkCallback = (void (*)(void))v;
    if (v != 0) {
        g_scaledInit_00542044 = v;
        ScaledAndMaskInitJmp_00405a00();
        if (g_framePauseFlag != 0) {
            return;
        }
    }
    g_scaledInit_00542044 = *(unsigned int *)(g_matrixStackTop * 4);
    g_matrixStackTop--;
}

/* @addr 0x00405ad0 (90b): same shape but uses g_xformEntityIdx, field +0x14 */
extern void MStackPush2ChainPrepend_00409970(void);
void PushPopScaled14_00405ad0(void) {
    unsigned int v;
    g_matrixStackTop++;
    *(unsigned int *)(g_matrixStackTop * 4) = g_xformEntityIdx;
    v = ((ScenegraphNode *)(g_xformEntityIdx * 4))->not_mask;
    g_walkCallback = (void (*)(void))v;
    if (v != 0) {
        g_xformEntityIdx = v;
    }
    MStackPush2ChainPrepend_00409970();
    if (g_framePauseFlag != 0) {
        return;
    }
    g_xformEntityIdx = *(unsigned int *)(g_matrixStackTop * 4);
    g_matrixStackTop--;
}

/* @addr 0x00408510 (99b): variant with double pause check + g_fightGroupHead +0x1c */
extern void func_00409970_ii(void);
extern void PushSetCallCleanup_00408580(void);
void PushPopScaled1cDoubleCall_00408510(void) {
    unsigned int v;
    g_matrixStackTop++;
    *(unsigned int *)(g_matrixStackTop * 4) = g_xformEntityIdx;
    func_00409970_ii();
    if (g_framePauseFlag != 0) return;
    v = ((ScenegraphNode *)(g_fightGroupHead * 4))->alloc_flags;
    g_xformEntityIdx = v;
    if (v != 0) {
        PushSetCallCleanup_00408580();
        if (g_framePauseFlag != 0) return;
    }
    g_xformEntityIdx = *(unsigned int *)(g_matrixStackTop * 4);
    g_matrixStackTop--;
}
