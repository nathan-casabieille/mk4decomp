/**
 * TablePushAccumTailJmp (0x429e30, 188b) - THE STAGE LOADER, and the one
 * thing standing between the engine and an arena.
 *
 * It was a weak no-op called exactly once a match. MK4_TRACE_STUBS found
 * it; nothing dispatches it through the trampoline, so it never showed in
 * MK4_TRACE_CODE. Everything it needs was already converted:
 *
 *   TableWalkBoundedCmp(7)   drop the PREVIOUS stage. Kind 7 is an arena,
 *                            and that walk runs GeoLoadFixupLoop, which
 *                            frees rather than fixes up.
 *   TwinLoopSlotFinder       g_walkCallback holds the stage index; the
 *                            finder scans the stage table at 0x4e2948
 *                            (stride 0x40, i.e. 0x10 packed words) for the
 *                            first non-zero record, wrapping on a negative
 *                            one, and leaves the record's packed index in
 *                            0x542058.
 *   LoadGeoAsset_Default     run twice, on the record's +0x00 and +0x04.
 *                            Both are the arena's asset slot - the fifteen
 *                            twelve-byte records at 0x503260 ARE the slots,
 *                            prison being 0x5032d8 - and the two calls
 *                            differ only by the 0x535d64 / 0x537ee0 tag
 *                            staged in g_pendingNodeType.
 *
 * The stage index arrives in g_walkCallback and is preserved across the
 * lookup on the matrix stack, because TwinLoopSlotFinder overwrites it
 * with the record it finds.
 *
 * TailJmpRetNops (0x4bd5d0) is a five-byte `jmp LoadGeoAsset_Default`.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void TableWalkBoundedCmp(int arg);
extern void MStackPush8(void);
extern void MStackPop8(void);
extern void TwinLoopSlotFinder(void);
extern void LoadGeoAsset_Default(void);

#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_stageRecIdx     (*(unsigned int *)MK4_VA(unsigned int, 0x542058u))
#define g_walkCallback    (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop  (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))

#define MSTACK_AT(i)      (*(unsigned int *)MK4_PTR((i) * 4u))

void TailJmpRetNops(void)
{
    LoadGeoAsset_Default();              /* jmp in the original */
}

void TablePushAccumTailJmp(void)
{
    unsigned int top, rec;

    TableWalkBoundedCmp(7);              /* free the outgoing stage */
    MStackPush8();
    if (g_framePauseFlag != 0)
        return;

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    MSTACK_AT(top) = g_walkCallback;     /* the stage index */

    TwinLoopSlotFinder();
    if (g_framePauseFlag != 0)
        return;

    rec = g_stageRecIdx;
    g_pendingNodeType = 0x535d64u >> 2;
    g_currentNodeIdx = *(unsigned int *)MK4_PTR(rec * 4u);
    TailJmpRetNops();
    if (g_framePauseFlag != 0)
        return;

    rec = g_stageRecIdx;
    g_pendingNodeType = 0x537ee0u >> 2;
    g_currentNodeIdx = *(unsigned int *)MK4_PTR(rec * 4u + 4u);
    TailJmpRetNops();
    if (g_framePauseFlag != 0)
        return;

    top = g_matrixStackTop;
    g_walkCallback = MSTACK_AT(top);
    g_matrixStackTop = top - 1;
    MStackPop8();                        /* jmp in the original */
}

#endif /* NON_MATCHING */
