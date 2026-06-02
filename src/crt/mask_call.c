/**
 * Auto-split from misc_matchesA.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004cc500 (24b)
 *   mov     eax, [esp+8]
 *   mov     ecx, [esp+4]
 *   and     eax, 0xfff7ffff
 *   push    eax
 *   push    ecx
 *   call    F
 *   add     esp, 8
 *   ret
 */
extern int __cdecl FpuCwTxn(int, int);
int MaskCall(int a, int b) {
    return FpuCwTxn(a, b & 0xfff7ffff);
}
