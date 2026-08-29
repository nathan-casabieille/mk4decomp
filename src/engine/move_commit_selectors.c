/**
 * MoveCommitPackedDispatcher's selector bank - 18 packed thunks the
 * animation tracks call as events (via ChainNodeAdvanceCallback). Each
 * points g_xformEntityIdx at a static move table (the mirror flag at
 * 0x542074 picks the flipped variant) and runs the pose list walker;
 * two of them tail into a phase helper. The first packed entry is the
 * commit head: GameMusicState4Way then MStackBitLoopTripleCall(0xb1).
 *
 * GENERATED from the original bytes (tools: this session); the matching
 * build synthesizes the originals.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void MStackPush4LLWalkPop4(void);
extern void Phase4TrampolineMainHelpers(void);
extern void PushSetEventQueueCallStore(void);
extern void GameMusicState4Way(void);
extern void MStackBitLoopTripleCall(void);

#define g_xformEntityIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_mirrorFlag74    (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_walkSlot6c      (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))

void MoveCommitPackedDispatcher(void)
{
    GameMusicState4Way();
    if (g_framePauseFlag != 0)
        return;
    g_walkSlot6c = 0xb1;
    MStackBitLoopTripleCall();      /* jmp in the original */
}

void MoveSel_0048d110(void)
{
    g_xformEntityIdx = 0x515f8cu >> 2;
    if (g_mirrorFlag74 != 0)
        g_xformEntityIdx = 0x516048u >> 2;
    MStackPush4LLWalkPop4();   /* jmp in the original */
}

void MoveSel_0048d140(void)
{
    g_xformEntityIdx = 0x516054u >> 2;
    if (g_mirrorFlag74 != 0)
        g_xformEntityIdx = 0x51605cu >> 2;
    MStackPush4LLWalkPop4();
    if (g_framePauseFlag != 0)
        return;
    Phase4TrampolineMainHelpers();
}

void MoveSel_0048d180(void)
{
    g_xformEntityIdx = 0x5161ecu >> 2;
    if (g_mirrorFlag74 != 0)
        g_xformEntityIdx = 0x51650cu >> 2;
    MStackPush4LLWalkPop4();   /* jmp in the original */
}

void MoveSel_0048d1b0(void)
{
    g_xformEntityIdx = 0x5166a4u >> 2;
    MStackPush4LLWalkPop4();   /* jmp in the original */
}

void MoveSel_0048d1d0(void)
{
    g_xformEntityIdx = 0x5166b4u >> 2;
    if (g_mirrorFlag74 != 0)
        g_xformEntityIdx = 0x5166c0u >> 2;
    MStackPush4LLWalkPop4();
    if (g_framePauseFlag != 0)
        return;
    PushSetEventQueueCallStore();
}

void MoveSel_0048d210(void)
{
    g_xformEntityIdx = 0x516854u >> 2;
    if (g_mirrorFlag74 != 0)
        g_xformEntityIdx = 0x516b74u >> 2;
    MStackPush4LLWalkPop4();   /* jmp in the original */
}

void MoveSel_0048d240(void)
{
    g_xformEntityIdx = 0x506becu >> 2;
    MStackPush4LLWalkPop4();   /* jmp in the original */
}

void MoveSel_0048d260(void)
{
    g_xformEntityIdx = 0x516d0cu >> 2;
    if (g_mirrorFlag74 != 0)
        g_xformEntityIdx = 0x516d14u >> 2;
    MStackPush4LLWalkPop4();   /* jmp in the original */
}

void MoveSel_0048d290(void)
{
    g_xformEntityIdx = 0x506c04u >> 2;
    MStackPush4LLWalkPop4();   /* jmp in the original */
}

void MoveSel_0048d2b0(void)
{
    g_xformEntityIdx = 0x51c260u >> 2;
    if (g_mirrorFlag74 != 0)
        g_xformEntityIdx = 0x51c2bcu >> 2;
    MStackPush4LLWalkPop4();   /* jmp in the original */
}

void MoveSel_0048d2e0(void)
{
    g_xformEntityIdx = 0x51c2c4u >> 2;
    if (g_mirrorFlag74 != 0)
        g_xformEntityIdx = 0x51c2ccu >> 2;
    MStackPush4LLWalkPop4();   /* jmp in the original */
}

void MoveSel_0048d310(void)
{
    g_xformEntityIdx = 0x51c2d4u >> 2;
    if (g_mirrorFlag74 != 0)
        g_xformEntityIdx = 0x51c2dcu >> 2;
    MStackPush4LLWalkPop4();   /* jmp in the original */
}

void MoveSel_0048d340(void)
{
    g_xformEntityIdx = 0x51c2e8u >> 2;
    if (g_mirrorFlag74 != 0)
        g_xformEntityIdx = 0x51c2f0u >> 2;
    MStackPush4LLWalkPop4();   /* jmp in the original */
}

void MoveSel_0048d370(void)
{
    g_xformEntityIdx = 0x51c1fcu >> 2;
    if (g_mirrorFlag74 != 0)
        g_xformEntityIdx = 0x51c204u >> 2;
    MStackPush4LLWalkPop4();   /* jmp in the original */
}

void MoveSel_0048d3a0(void)
{
    g_xformEntityIdx = 0x51c2f8u >> 2;
    if (g_mirrorFlag74 != 0)
        g_xformEntityIdx = 0x51c300u >> 2;
    MStackPush4LLWalkPop4();   /* jmp in the original */
}

void MoveSel_0048d3d0(void)
{
    g_xformEntityIdx = 0x51c2e4u >> 2;
    MStackPush4LLWalkPop4();   /* jmp in the original */
}

void MoveSel_0048d3f0(void)
{
    g_xformEntityIdx = 0x516d1cu >> 2;
    MStackPush4LLWalkPop4();   /* jmp in the original */
}

void MoveSel_0048d410(void)
{
    g_xformEntityIdx = 0x51c308u >> 2;
    MStackPush4LLWalkPop4();   /* jmp in the original */
}

#endif /* NON_MATCHING */
