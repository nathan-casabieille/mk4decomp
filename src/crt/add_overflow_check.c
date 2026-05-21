/**
 * Auto-split from misc_matchesFF.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern packed_ptr g_xformEntityIdx;

/* @addr 0x004ce1f0 (35b)
 *   arg1 = [esp+4]; arg2 = [esp+0xc]; ecx = arg2 + arg1;
 *   eax = (ecx < arg1 || ecx >= arg2) ? 1 : 0; *(arg3) = ecx; ret eax.
 */
int AddOverflowCheck_004ce1f0(unsigned int arg1, unsigned int arg2, unsigned int *result) {
    unsigned int sum = arg2 + arg1;
    int ret = 0;
    if (sum < arg1) {
        ret = 1;
    } else if (sum < arg2) {
        ret = 1;
    }
    *result = sum;
    return ret;
}
