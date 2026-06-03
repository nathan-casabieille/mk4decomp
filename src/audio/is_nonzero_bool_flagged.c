/**
 * Auto-split from misc_matches9.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

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
extern int MovsxAnd4Shr(void);
extern int MovsxAnd20Shr5(void);
int IsNonzeroBoolFlagged(void) {
    if (MovsxAnd4Shr() != 0) {
        return 1;
    }
    return MovsxAnd20Shr5() != 0 ? 1 : 0;
}
