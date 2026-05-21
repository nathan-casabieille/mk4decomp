/**
 * Auto-split from misc_matches9.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004a1d00 (27b)
 *   call    F
 *   test    eax, eax
 *   je      .return0
 *   mov     eax, 1
 *   ret
 * .return0:
 *   call    F2
 *   neg     eax
 *   sbb     eax, eax
 *   neg     eax
 *   ret
 */
extern int MovsxAnd4Shr_004a1ce0(void);
extern int MovsxAnd20Shr5_004a1cf0(void);
int IsNonzeroBoolFlagged_004a1d00(void) {
    if (MovsxAnd4Shr_004a1ce0() != 0) {
        return 1;
    }
    return MovsxAnd20Shr5_004a1cf0() != 0 ? 1 : 0;
}
