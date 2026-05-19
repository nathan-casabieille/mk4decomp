/**
 * Build the z-sort-key LUT and the i/3 byte table.
 *
 * Two-pass init called once at boot:
 *  - clear g_paletteScratch (1 MB), then run Helper_PaletteInit
 *  - fill g_zSortKeyLUT[i] = round(i * 65536 / (31 * i + 65536))
 *    for i in [0..65535]
 *  - fill g_div3Table[i] = i / 3 for i in [0..767]
 */
#include "engine/scenegraph.h"
#include "engine/render.h"

extern void *memset(void *, int, unsigned int);
#pragma intrinsic(memset)

/* Declaration order is reversed from .rdata pool order: MSVC SP3 emits
 * the second fmul operand FIRST in code, so to get `fmul k_31` ahead of
 * `fmul k_inv_65536` in the loop body, k_31 must follow k_inv_65536 in
 * source. The orig .rdata pool is k_31, k_inv_65536, k_neg_one. */
static const double k_inv_65536  = 1.52587890625e-05;/* 0x004d2a58 = 1/65536 */
static const double k_31         = 31.0;             /* 0x004d2a50 */
static const double k_neg_one    = -1.0;             /* 0x004d2a60 */

/*
 * @addr 0x004bf290 (130 bytes)
 *
 * Pure-C reformulation. The loop computes
 *   sort = (s32)(i / (i * 31 / 65536 + 1))
 * but encoded as -k_neg_one so the .rdata pool keeps a literal -1.0.
 */
void BuildSortKeyLUT(void)
{
    int i;
    int j;

    memset(g_paletteScratch, 0, 0x108000 * 4);
    Helper_PaletteInit(0);

    for (i = 0; i < 0x10000; i++) {
        double di = (double)i;
        double denom = di * k_31 * k_inv_65536 - k_neg_one;
        g_zSortKeyLUT[i] = (u16)(s32)(di / denom);
    }

    for (j = 0; j < 0x300; j++) {
        g_div3Table[j] = (u8)(j / 3);
    }
}
