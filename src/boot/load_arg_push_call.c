/**
 * Auto-split from misc_matchesA.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004c54b0 (20b)
 *   mov     eax, [0x00f9f850]
 *   mov     ecx, [esp+4]
 *   push    eax
 *   push    ecx
 *   call    F
 *   add     esp, 8
 *   ret
 */
extern unsigned int g_dispatchSave1430_00f9f850;
extern int __cdecl TryAllocWithHandler(int, int);
int LoadArgPushCall(int x) {
    return TryAllocWithHandler(x, g_dispatchSave1430_00f9f850);
}
