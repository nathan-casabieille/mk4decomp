/**
 * Auto-split from misc_matchesB.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_currentNodeIdx;

/* @addr 0x0048bad0 (11b)
 *   push    0
 *   call    F
 *   add     esp, 4
 *   ret
 */
extern int __cdecl MStackAngleWrapDispatch(int);
void PushZeroCallRet(void) {
    MStackAngleWrapDispatch(0);
}
