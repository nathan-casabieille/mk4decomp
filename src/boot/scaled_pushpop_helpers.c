/**
 * Boot-phase scaled save-restore wrappers.
 *
 * Three related "push global on mstack, call helper, restore global" wrappers
 * that bracket various scaled-init operations. Each pushes either
 * g_currentNodeIdx or g_xformEntityIdx onto the mstack, performs a
 * conditional update + callback dispatch, then pops the saved value back.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_currentNodeIdx;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_fightGroupHead (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#endif


/* @addr 0x004059a0 (90b)
 *   Push g_scaledInit on stack[idx*4]; load scaled[+0x18];
 *   if non-zero, set scaled, call F, pause-test;
 *   then pop stack back into g_scaledInit. Standard "save-restore" wrapper.
 */
extern void ScaledAndMaskInitJmp(void);
void PushPopScaled18(void) {
    unsigned int v;
    g_matrixStackTop++;
    *(unsigned int *)MK4_PTR((g_matrixStackTop * 4)) = g_currentNodeIdx;
    v = ((ScenegraphNode *)MK4_PTR((g_currentNodeIdx * 4)))->child_chain;
    g_walkCallback = (void (*)(void))v;
    if (v != 0) {
        g_currentNodeIdx = v;
        ScaledAndMaskInitJmp();
        if (g_framePauseFlag != 0) {
            return;
        }
    }
    g_currentNodeIdx = *(unsigned int *)MK4_PTR((g_matrixStackTop * 4));
    g_matrixStackTop--;
}

/* @addr 0x00405ad0 (90b): same shape but uses g_xformEntityIdx, field +0x14 */
extern void MStackPush2ChainPrepend(void);
void PushPopScaled14(void) {
    unsigned int v;
    g_matrixStackTop++;
    *(unsigned int *)MK4_PTR((g_matrixStackTop * 4)) = g_xformEntityIdx;
    v = ((ScenegraphNode *)MK4_PTR((g_xformEntityIdx * 4)))->not_mask;
    g_walkCallback = (void (*)(void))v;
    if (v != 0) {
        g_xformEntityIdx = v;
    }
    MStackPush2ChainPrepend();
    if (g_framePauseFlag != 0) {
        return;
    }
    g_xformEntityIdx = *(unsigned int *)MK4_PTR((g_matrixStackTop * 4));
    g_matrixStackTop--;
}

/* @addr 0x00408510 (99b): variant with double pause check + g_fightGroupHead +0x1c */
extern void func_00409970_ii(void);
extern void PushSetCallCleanup(void);
void PushPopScaled1cDoubleCall(void) {
    unsigned int v;
    g_matrixStackTop++;
    *(unsigned int *)MK4_PTR((g_matrixStackTop * 4)) = g_xformEntityIdx;
    func_00409970_ii();
    if (g_framePauseFlag != 0) return;
    v = ((ScenegraphNode *)MK4_PTR((g_fightGroupHead * 4)))->alloc_flags;
    g_xformEntityIdx = v;
    if (v != 0) {
        PushSetCallCleanup();
        if (g_framePauseFlag != 0) return;
    }
    g_xformEntityIdx = *(unsigned int *)MK4_PTR((g_matrixStackTop * 4));
    g_matrixStackTop--;
}
