/**
 * Auto-split from misc_matchesB.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x004c9a20 (11b)
 *   push    -3
 *   call    F
 *   add     esp, 4
 *   ret
 */
extern int __cdecl CrtSetlocaleInstaller_004c9520(int);
void PushNeg3CallRet_004c9a20(void) {
    CrtSetlocaleInstaller_004c9520(-3);
}
