/**
 * Auto-split from misc_matchesA.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
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
extern int __cdecl FpuCwTxn_004cc4c0(int, int);
int MaskCall_004cc500(int a, int b) {
    return FpuCwTxn_004cc4c0(a, b & 0xfff7ffff);
}
