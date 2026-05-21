/**
 * Auto-split from misc_matchesFF.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern packed_ptr g_xformEntityIdx;

/* @addr 0x004cd320 (34b)
 *   arg = [esp+4]; eax = arg & 0x1f, ecx = arg >> 5;
 *   edx = eax * 9 (lea eax + eax*8);
 *   eax = g_table_00fa0de0[ecx]; ecx = eax + edx*4 + 0x0c;
 *   call IAT [g_iat_004d213c](ecx).
 */
extern unsigned int g_table_00fa0de0[];
extern void (__stdcall *g_iat_004d213c)(void *);
void DivMod32IAT_004cd320(int arg) {
    int lo = arg & 0x1f;
    int hi = arg >> 5;
    void *p = (char *)g_table_00fa0de0[hi] + lo * 9 * 4 + 0x0c;
    g_iat_004d213c(p);
}
