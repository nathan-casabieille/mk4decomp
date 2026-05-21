/**
 * Auto-split from misc_matchesB.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x0048bad0 (11b)
 *   push    0
 *   call    F
 *   add     esp, 4
 *   ret
 */
extern int __cdecl func_004887ff(int);
void PushZeroCallRet_0048bad0(void) {
    func_004887ff(0);
}
