/**
 * The MENU SCENE band - what gives the mode-select screen (and every other
 * front-end screen) a CAMERA.
 *
 * The measured symptom: with MK4_MAIN_MENU the rows rendered, but at RGB
 * (8,8,8) on black - every draw-queue record shipped colour word 0, which
 * picks CLUT page 0 and scales by 1/16. The cause was upstream of the
 * rasteriser: the three camera owner nodes StageParticleEmitterInit builds
 * (0x537f78 kind 0x11, 0x541de0 kind 0x12, 0x535e6c kind 0x13, the last one
 * the front-end's own camera at FOV 0xf333) were all still ZERO, so nothing
 * in the walk ever ran the lit path. MK4_TRACE_CAMNODE printed
 * "boot=0 partInit=0 emitter=0" for the whole run.
 *
 * The chain that builds them exists and is entirely converted BUT ONE LINK:
 *
 *   FiveTableWalkInit          (menu states 1 and 2, main_menu_screen.c)
 *     -> BootInitGuardedCallChain   <-- weak no-op
 *          -> CallPauseClear3CallTriple   (phase3_round_end_band.c)
 *               -> StageParticleEmitterInit  (stage_camera_init.c)
 *
 * So the whole screen-enter sequence was silently skipped. This band fills
 * that link and its two hollow leaves:
 *
 *   BootInitGuardedCallChain (0x4265d0): the front-end's SCENE ENTER -
 *     drain the voice queue, wipe the per-match tables, reset the node
 *     pools, walk the scenegraph down, then CallPauseClear3CallTriple
 *     (which is where the cameras come from). The tail runs the slide/event
 *     cluster under an mstack save of walkSlot6c / slot70 / slot74, and on
 *     success arms the tick word 0x543550 = 0x100.
 *   DrainQueueCallEach (0x4a1ec0): hand every entry of the voice pool
 *     (0x543750, count in 0x543748) plus the bound node 0x5437f0 to the
 *     chain-insert, then empty the pool.
 *   PendingMatch_ZeroNDwords (0x45c8e0, the FIRST body only - the symbol
 *     packs 3478 bytes of unrelated dispatch helpers behind it): zero the
 *     match tables and re-seed the event queue head/active on 0x53a4b8.
 *   ZeroNDwords (0x4a5660): rep stosd. The VA form, for the arena.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void MStackPush2ChainLLInsert(void);
extern void Init0AndMax(void);
extern void CopyGlobal(void);
extern void Init6Struct(void);
extern void ScenegraphWalk(void);
extern void CallPauseClear3CallTriple(void);
extern void SlideAttackEventCluster(void);
extern void AndStorePushCallZero(void);

#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_walkSlot6c      (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_slot70          (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_slot74          (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop  (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_dualBitGate     (*(unsigned int *)MK4_VA(unsigned int, 0x53a7b0u))
#define g_tickW1          (*(unsigned int *)MK4_VA(unsigned int, 0x543550u))
#define g_voicePoolCount  (*(unsigned int *)MK4_VA(unsigned int, 0x543748u))
#define g_audioBoundNode  (*(unsigned int *)MK4_VA(unsigned int, 0x5437f0u))
#define g_eventQueueHead  (*(unsigned int *)MK4_VA(unsigned int, 0x53a2f0u))
#define g_eventQueueActive (*(unsigned int *)MK4_VA(unsigned int, 0x53a31cu))

#define VOICE_POOL_VA     0x543750u

/* 0x4a5660 - rep stosd. The pointer is a VA: callers pass the table
 * addresses as literals (0x53a4a0, 0x52ab18, ...). */
void ZeroNDwords(unsigned int dstVA, int n)
{
    int i;

    if (n <= 0)
        return;
    for (i = 0; i < n; i++)
        *MK4_VA(unsigned int, dstVA + (unsigned int)i * 4u) = 0;
}

/* 0x4a1ec0 - empty the voice pool through the chain-insert */
void DrainQueueCallEach(void)
{
    unsigned int i, n;

    n = g_voicePoolCount;
    for (i = 0; (int)i < (int)n; i++) {
        unsigned int *slot = MK4_VA(unsigned int, VOICE_POOL_VA + i * 4u);

        g_currentNodeIdx = *slot;
        MStackPush2ChainLLInsert();
        n = g_voicePoolCount;                    /* reloaded every pass */
        *slot = 0;
    }
    g_currentNodeIdx = g_audioBoundNode;
    g_audioBoundNode = 0;
    MStackPush2ChainLLInsert();
    g_voicePoolCount = 0;
}

/* 0x45c8e0 - wipe the per-match tables, re-seed the event queue.
 * ONLY the first body of the packed 0x45c8e0 symbol. */
void PendingMatch_ZeroNDwords(void)
{
    unsigned int seed;

    ZeroNDwords(0x53a4a0u, 0x1b);
    g_eventQueueActive = 0;
    g_eventQueueHead = 0;
    ZeroNDwords(0x52ab18u, 8);
    ZeroNDwords(0x541e00u, 8);
    ZeroNDwords(0x53a330u, 8);
    ZeroNDwords(0x53a750u, 8);
    ZeroNDwords(0x53a2a0u, 8);
    ZeroNDwords(0x53a2f8u, 8);
    ZeroNDwords(0x53a258u, 8);
    ZeroNDwords(0x538048u, 8);

    seed = 0x53a4b8u >> 2;
    g_currentNodeIdx = seed;
    g_eventQueueHead = seed;
    g_eventQueueActive = seed;

    *MK4_VA(unsigned int, 0x52aae8u) = 0;
    *MK4_VA(unsigned int, 0x52aa84u) = 0;
    *MK4_VA(unsigned int, 0x541dfcu) = 0;
    *MK4_VA(unsigned int, 0x52aa88u) = 0;
    *MK4_VA(unsigned int, 0x541e40u) = 0;
    *MK4_VA(unsigned int, 0x52aab8u) = 0;
    *MK4_VA(unsigned int, 0x541e3cu) = 0;
    *MK4_VA(unsigned int, 0x541db4u) = 0;
    *MK4_VA(unsigned int, 0x541e44u) = 0;
    *MK4_VA(unsigned int, 0x541e24u) = 0;

    /* the six group heads get -1, not 0 (or eax, -1 after the seed) */
    g_walkSlot6c = 0xffffffffu;
    *MK4_VA(unsigned int, 0x53a4a0u) = 0xffffffffu;
    *MK4_VA(unsigned int, 0x53a4a4u) = 0xffffffffu;
    *MK4_VA(unsigned int, 0x53a4a8u) = 0xffffffffu;
    *MK4_VA(unsigned int, 0x53a4acu) = 0xffffffffu;
    *MK4_VA(unsigned int, 0x53a4b0u) = 0xffffffffu;
    *MK4_VA(unsigned int, 0x53a4b4u) = 0xffffffffu;
}

/* 0x4265d0 - the front-end's SCENE ENTER */
void BootInitGuardedCallChain(void)
{
    unsigned int top;

    DrainQueueCallEach();
    PendingMatch_ZeroNDwords();
    Init0AndMax();
    g_walkSlot6c = 0;
    CopyGlobal();
    Init6Struct();
    ScenegraphWalk();
    CallPauseClear3CallTriple();
    if (g_framePauseFlag != 0)
        return;

    g_walkSlot6c = 0;
    g_dualBitGate = 0;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = 0;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_slot70;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_slot74;

    SlideAttackEventCluster();
    if (g_framePauseFlag != 0)
        return;                                  /* mstack leak, as original */
    AndStorePushCallZero();
    if (g_framePauseFlag != 0)
        return;                                  /* mstack leak, as original */

    top = g_matrixStackTop;
    g_slot74 = *(unsigned int *)MK4_PTR(top * 4);
    top -= 1;
    g_matrixStackTop = top;
    g_slot70 = *(unsigned int *)MK4_PTR(top * 4);
    top -= 1;
    g_matrixStackTop = top;
    g_walkSlot6c = *(unsigned int *)MK4_PTR(top * 4);
    g_matrixStackTop = top - 1;
    g_tickW1 = 0x100;
}

#endif /* NON_MATCHING */
