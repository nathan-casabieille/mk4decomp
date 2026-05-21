/**
 * Auto-split from misc_matchesA.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
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
extern unsigned int g_state_00f9f850;
extern int __cdecl func_004c54c2(int, int);
int LoadArgPushCall_004c54b0(int x) {
    return func_004c54c2(x, g_state_00f9f850);
}
