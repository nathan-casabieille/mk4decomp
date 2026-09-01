/**
 * The character select's CURSOR STEP - what the input machine's event nodes
 * actually run, and the last layer between a key press and the highlight
 * moving.
 *
 * The grid is FIVE WIDE and 1-BASED: the two stepping bodies stop at
 * 1 / 6 / 0xb / 0x10 going down and 5 / 0xa / 0xf / 0x12 going up, which are
 * the left and right columns of the 5x3 of portraits plus the RANDOM /
 * GROUP / HIDDEN row.
 *
 *   0x49f640 / 0x49f670 - the P1 and P2 entry stubs the event nodes carry.
 *     Each waits on its own settling flag (0x541d88 / 0x537ea8), stamps
 *     which side it is into 0x535e48, and tails into the increment body.
 *   IndirectDispatch3Entry (0x49f530) - step the index DOWN. It reads the
 *     side's entry out of the table at 0x541fc0, runs that entry's own
 *     handler at [+4] - an indirect call, so the VA has to resolve - and
 *     then walks the index down one cell at a time, asking
 *     LinkedListIndirectDirtyToggle whether each candidate is takeable and
 *     stopping at a column edge.
 *   IndirectStateDispatcher (0x49f6a0) - the same body with INCREMENT and
 *     the mirrored stop set.
 *   LinkedListIndirectDirtyToggle (0x49f7b0) - the takeable test. It scans
 *     the pair table at 0x4f2980 - only four entries, cells 7, 8, 9 and 17 -
 *     for one matching the candidate and calls its validator; a cell with no
 *     entry is free. The polarity is worth stating because it reads
 *     backwards: dirty bit 0 CLEAR on return means TAKE IT. Cells 7, 8 and 9
 *     have validators that just set the bit, so they are always blocked;
 *     cell 17's checks both players and g_dlMode.
 *   GuardedScaledCall (0x48a020) - dispatch the scene word for the cell the
 *     cursor landed on, unless either 0x541dc0 or the value is negative.
 *   SaveStateSnapshot (0x4aba40) / MStackRestore27 (0x4abd50) - the
 *     THIRTY-TWO slot bracket the scan runs under. Note slots 0x54206c
 *     .. 0x542088 appear TWICE in the push list and twice in the pop list:
 *     that is the same eight-slot block bracketed twice, not a
 *     transcription slip.
 *
 * NATIVE-ONLY twins: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void RoundWinTransition(void);
extern void CallSetPause(void);
extern void TaggedSceneDispatch(int tag);
extern void DualTestDirtyToggle_004282c0(void);
extern void *MK4_ResolveCode(unsigned int va);

void IndirectStateDispatcher(void);
void IndirectDispatch3Entry(void);
void LinkedListIndirectDirtyToggle(void);
void SaveStateSnapshot(void);
void MStackRestore27(void);

#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_xformEntityIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#define g_walkSlot6c      (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_slot68          (*(unsigned int *)MK4_VA(unsigned int, 0x542068u))
#define g_slot70          (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_stateBits8c     (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop  (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_selectTable     (*(unsigned int *)MK4_VA(unsigned int, 0x541fc0u))
#define g_selectSide      (*(unsigned int *)MK4_VA(unsigned int, 0x535e48u))
#define g_settlingP1      (*(unsigned int *)MK4_VA(unsigned int, 0x541d88u))
#define g_settlingP2      (*(unsigned int *)MK4_VA(unsigned int, 0x537ea8u))
#define g_dlMode          (*(unsigned int *)MK4_VA(unsigned int, 0x542004u))
#define g_guardP1         (*(unsigned int *)MK4_VA(unsigned int, 0x53a1bcu))
#define g_guardP2         (*(unsigned int *)MK4_VA(unsigned int, 0x53a354u))
#define g_slotDc0         (*(unsigned int *)MK4_VA(unsigned int, 0x541dc0u))

#define AT(i) (*(unsigned int *)MK4_PTR((i) * 4u))

/* the 32 slots the scan brackets, in push order */
static const unsigned int mk4_snap_slots[32] = {
    0x54208cu, 0x53a168u, 0x538138u, 0x535e48u, 0x535e50u, 0x53a1acu,
    0x53a23cu, 0x53a1b0u, 0x542044u, 0x542048u, 0x54204cu, 0x542050u,
    0x542054u, 0x542058u, 0x54205cu, 0x542060u,
    0x54206cu, 0x542070u, 0x542074u, 0x542078u, 0x54207cu, 0x542080u,
    0x542084u, 0x542088u,
    0x54206cu, 0x542070u, 0x542074u, 0x542078u, 0x54207cu, 0x542080u,
    0x542084u, 0x542088u
};

/* 0x4aba40 */
void SaveStateSnapshot(void)
{
    unsigned int top = g_matrixStackTop;
    int i;

    for (i = 0; i < 32; i++) {
        top += 1;
        g_matrixStackTop = top;
        AT(top) = *MK4_VA(unsigned int, mk4_snap_slots[i]);
    }
    g_slot68 = *MK4_VA(unsigned int, 0x53e358u);
}

/* 0x4abd50 */
void MStackRestore27(void)
{
    unsigned int top = g_matrixStackTop;
    int i;

    for (i = 31; i >= 0; i--) {
        *MK4_VA(unsigned int, mk4_snap_slots[i]) = AT(top);
        top -= 1;
        g_matrixStackTop = top;
    }
}

/* 0x48a020 */
void GuardedScaledCall(void)
{
    unsigned int v;

    if ((int)g_slotDc0 < 0) return;
    if ((int)g_walkSlot6c < 0) return;
    g_currentNodeIdx = g_walkSlot6c;
    v = AT(g_walkSlot6c);
    g_walkSlot6c = v;
    TaggedSceneDispatch((int)v);
}

/* 0x49f8d0 / 0x49f8e0 / 0x49f8f0 - cells 7, 8 and 9: always blocked */
void SelectCellBlocked_0049f8d0(void) { g_stateBits8c |= 1u; }
void SelectCellBlocked_0049f8e0(void) { g_stateBits8c |= 1u; }
void SelectCellBlocked_0049f8f0(void) { g_stateBits8c |= 1u; }

/* 0x49f870 - cell 17: blocked unless the OTHER side is already committed */
void SelectCellGuard_0049f870(void)
{
    unsigned int v;

    DualTestDirtyToggle_004282c0();
    if (g_framePauseFlag != 0) return;
    if ((g_stateBits8c & 1u) == 0) { g_stateBits8c &= ~1u; return; }

    g_walkSlot6c = g_dlMode;
    if (g_dlMode != 0) {
        v = (g_selectSide == 0) ? g_guardP1 : g_guardP2;
        g_walkSlot6c = v;
        if (v != 0) { g_stateBits8c &= ~1u; return; }
    }
    g_stateBits8c |= 1u;
}

/* 0x49f7b0 - is the candidate cell takeable? dirty bit 0 CLEAR means yes */
void LinkedListIndirectDirtyToggle(void)
{
    unsigned int p, val, cb;

    SaveStateSnapshot();

    p = 0x4f2980u >> 2;
    g_currentNodeIdx = p;
    val = AT(p);
    p += 1;
    g_slot70 = val;
    g_currentNodeIdx = p;
    cb = AT(p);
    p += 1;
    g_xformEntityIdx = cb;
    g_currentNodeIdx = p;

    while ((int)val >= 0) {
        if (val == g_walkSlot6c) {               /* 0x49f834 */
            ((void (*)(void))MK4_ResolveCode(cb))();
            if (g_framePauseFlag != 0)
                return;                          /* bracket leak, as original */
            if ((g_stateBits8c & 1u) == 0) {     /* validator says free */
                MStackRestore27();
                g_stateBits8c |= 1u;
                return;
            }
            MStackRestore27();
            g_stateBits8c &= ~1u;
            return;
        }
        val = AT(p);
        p += 1;
        g_slot70 = val;
        g_currentNodeIdx = p;
        cb = AT(p);
        p += 1;
        g_xformEntityIdx = cb;
        g_currentNodeIdx = p;
    }

    MStackRestore27();
    g_stateBits8c &= ~1u;
}

/* the shared body of the two steppers: `down` picks the direction and the
 * stop set */
static void cursor_step(int down)
{
    unsigned int entry, handler, v;

    g_xformEntityIdx = g_selectTable;
    entry = AT(g_selectTable + g_selectSide);
    g_xformEntityIdx = entry;
    handler = MK4_NODE_AT(unsigned int, entry, 4);
    g_currentNodeIdx = handler;
    ((void (*)(void))MK4_ResolveCode(handler))();
    if (g_framePauseFlag != 0) return;
    if ((g_stateBits8c & 1u) == 0) { CallSetPause(); return; }

    v = AT(g_xformEntityIdx);
    g_currentNodeIdx = v;
    v = AT(v);
    g_walkSlot6c = v;
    if (v == (down ? 1u : 5u)) { CallSetPause(); return; }

    for (;;) {
        if (down) {
            if (v == 6u || v == 0xbu || v == 0x10u) { CallSetPause(); return; }
            v -= 1;
        } else {
            if (v == 0xau || v == 0xfu || v == 0x12u) { CallSetPause(); return; }
            v += 1;
        }
        g_walkSlot6c = v;
        LinkedListIndirectDirtyToggle();
        if (g_framePauseFlag != 0) return;
        if ((g_stateBits8c & 1u) == 0)
            break;                               /* takeable */
        v = g_walkSlot6c;
        if (v == (down ? 1u : 5u)) { CallSetPause(); return; }
    }

    AT(g_currentNodeIdx) = g_walkSlot6c;
    g_slot70 = g_selectSide;
    RoundWinTransition();
    if (g_framePauseFlag != 0) return;
    g_walkSlot6c = MK4_NODE_AT(unsigned int, g_xformEntityIdx, 8);
    GuardedScaledCall();
    if (g_framePauseFlag != 0) return;
    CallSetPause();
}

/* 0x49f530 */
void IndirectDispatch3Entry(void)  { cursor_step(1); }
/* 0x49f6a0 */
void IndirectStateDispatcher(void) { cursor_step(0); }

/* 0x49f4d0 / 0x49f500 - the LEFT stubs: same shape, into the DECREMENT body.
 * The four directions have four different callbacks in the controller's
 * table: slot 0 UP -> 0x49f190, slot 1 DOWN -> 0x49f340, slot 2 LEFT ->
 * 0x49f4d0, slot 3 RIGHT -> 0x49f640. Left and right are the +-1 steppers
 * here; up and down go through 0x49f1f0 and 0x49f3a0, which wrap across the
 * short bottom row (add 0xe, add 4, add 5 and their inverses) and are not
 * converted yet. */
void SelectStepLeftP1_0049f4d0(void)
{
    g_walkSlot6c = g_settlingP1;
    if (g_settlingP1 != 0) { CallSetPause(); return; }
    g_selectSide = 0;
    IndirectDispatch3Entry();
}

void SelectStepLeftP2_0049f500(void)
{
    g_walkSlot6c = g_settlingP2;
    if (g_settlingP2 != 0) { CallSetPause(); return; }
    g_selectSide = 1;
    IndirectDispatch3Entry();
}

/* 0x49f640 - P1's entry stub */
void SelectStepP1_0049f640(void)
{
    g_walkSlot6c = g_settlingP1;
    if (g_settlingP1 != 0) { CallSetPause(); return; }
    g_selectSide = 0;
    IndirectStateDispatcher();
}

/* 0x49f670 - P2's entry stub */
void SelectStepP2_0049f670(void)
{
    g_walkSlot6c = g_settlingP2;
    if (g_settlingP2 != 0) { CallSetPause(); return; }
    g_selectSide = 1;
    IndirectStateDispatcher();
}

#endif /* NON_MATCHING */
