/**
 * Auto-split from misc_matchesFF.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern packed_ptr g_xformEntityIdx;

void BitTestFreeClear_004c8ae0(struct BitTestS *p) {
    if ((p->field_c & 0x83) != 0 && (p->field_c & 8) != 0) {
        FreeImpl_004c55f0(p->field8);
        p->field_c &= 0xfffffbf7u;
        p->field0 = 0;
        p->field8 = 0;
        p->field4 = 0;
    }
}
