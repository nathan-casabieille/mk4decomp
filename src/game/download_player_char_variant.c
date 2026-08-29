/**
 * DownloadPlayerChar_Variant - 0x0048bff0 (405b game.download)
 *
 * The per-player spawn wrapper GuardedDualPushTailJmp brackets. Reads the
 * player slot from 0x542070 (0..3), picks the character index global for
 * that slot (P1 0x537f48, P2 0x5380e0, P3 0x53a178, P4 0x53a250), fetches
 * the costume-variant byte from the table at 0x4d5718 (row = 0x541ec4 for
 * P1/P3, 0x541ec8 for P2/P4; column = charIdx*4), mstack-pushes the slot
 * and the current node, runs Helper_DownloadSetup (the geo download; on
 * pause the pushes leak - the usual abort pattern), then re-roots
 * g_currentNodeIdx at the built node's sub-record ((node+flag)[0xc] where
 * flag = 0x542074 != 0, then that record's +4 pointer, sar 2 to packed)
 * and applies the costume textures via LoadGeoAsset_Textures(variant).
 *
 * The retail binary's Helper_DownloadDebugPrint (0x48bfe0) is a single
 * ret - the "DOWNLOAD Player N ..." printf was compiled out - so the
 * format-string calls are dropped here.
 *
 * NATIVE-ONLY twin: the matching build synthesizes the original bytes.
 */
#ifdef NON_MATCHING

#include "portable/mem_model.h"

extern void Helper_DownloadSetup(void);
extern void LoadGeoAsset_Textures(int index);

#define g_playerSlot      (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_setupFlag74     (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_currentNodeIdx  (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_framePauseFlag  (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop  (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_charP1          (*(unsigned int *)MK4_VA(unsigned int, 0x537f48u))
#define g_charP2          (*(unsigned int *)MK4_VA(unsigned int, 0x5380e0u))
#define g_charP3          (*(unsigned int *)MK4_VA(unsigned int, 0x53a178u))
#define g_charP4          (*(unsigned int *)MK4_VA(unsigned int, 0x53a250u))
#define g_variantRowA     (*(unsigned int *)MK4_VA(unsigned int, 0x541ec4u))
#define g_variantRowB     (*(unsigned int *)MK4_VA(unsigned int, 0x541ec8u))

void DownloadPlayerChar_Variant(void)
{
    unsigned int slot = g_playerSlot;
    unsigned int top;
    int variant = 0;

    /* the four cmp blocks reduce to a per-slot pick: row A for P1/P3,
     * row B for P2/P4, column = that slot's character index */
    if (slot == 0)
        variant = *(signed char *)MK4_PTR(g_variantRowA + g_charP1 * 4 + 0x4d5718u);
    else if (slot == 2)
        variant = *(signed char *)MK4_PTR(g_variantRowA + g_charP3 * 4 + 0x4d5718u);
    else if (slot == 1)
        variant = *(signed char *)MK4_PTR(g_variantRowB + g_charP2 * 4 + 0x4d5718u);
    else if (slot == 3)
        variant = *(signed char *)MK4_PTR(g_variantRowB + g_charP4 * 4 + 0x4d5718u);

    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = slot;
    top = g_matrixStackTop + 1;
    g_matrixStackTop = top;
    *(unsigned int *)MK4_PTR(top * 4) = g_currentNodeIdx;

    Helper_DownloadSetup();
    if (g_framePauseFlag != 0)
        return;                     /* abort: the two pushes leak */

    {
        unsigned int flag = (g_setupFlag74 != 0) ? 1u : 0u;
        unsigned int sub  = *(unsigned int *)MK4_PTR((flag + g_currentNodeIdx) * 4 + 0xc);
        g_currentNodeIdx  = (unsigned int)((int)*(unsigned int *)MK4_PTR(sub * 4 + 4) >> 2);
        LoadGeoAsset_Textures(variant);
    }

    top = g_matrixStackTop;
    g_currentNodeIdx = *(unsigned int *)MK4_PTR(top * 4);
    g_matrixStackTop = top - 1;
    top = g_matrixStackTop;
    g_playerSlot = *(unsigned int *)MK4_PTR(top * 4);
    g_matrixStackTop = top - 1;
}

#endif /* NON_MATCHING */
