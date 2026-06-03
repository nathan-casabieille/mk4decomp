/**
 * Auto-split from misc_matchesB.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_currentNodeIdx;

/* @addr 0x004c9a20 (11b)
 *   push    -3
 *   call    F
 *   add     esp, 4
 *   ret
 */
extern int __cdecl CrtSetlocaleInstaller(int);
void PushNeg3CallRet(void) {
    CrtSetlocaleInstaller(-3);
}
