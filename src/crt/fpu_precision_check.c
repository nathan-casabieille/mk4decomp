/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x004c8400 (80b)
 *   FPU precision check: stores 4 doubles into stack, computes
 *   (-2.0 / DBL_MAX_NORMAL) * DBL_MAX_NORMAL - (-2.0), comp w/
 *   threshold 0x4d2b58. Returns 1 if result is precise (not zero,
 *   not C0/C2/C3 conditions in fnstsw ax bits 0x41), else 0.
 */
extern double g_data_004d2b58;
void FPUPrecisionCheck_004c8400(void) {
    __asm {
        push    ebp
        mov     ebp, esp
        sub     esp, 0x18
        mov     dword ptr [ebp - 0x08], 0x80000000
        mov     dword ptr [ebp - 0x04], 0x4147ffff
        mov     dword ptr [ebp - 0x10], 0xc0000000
        mov     dword ptr [ebp - 0x0c], 0x4150017e
        fld     qword ptr [ebp - 0x10]
        fdiv    qword ptr [ebp - 0x08]
        fmul    qword ptr [ebp - 0x08]
        fsubr   qword ptr [ebp - 0x10]
        fstp    qword ptr [ebp - 0x18]
        fld     qword ptr [ebp - 0x18]
        fcomp   qword ptr [g_data_004d2b58]
        fnstsw  ax
        test    ah, 0x41
        _emit   75h
        _emit   09h
        mov     eax, 1
        mov     esp, ebp
        pop     ebp
        ret
        xor     eax, eax
        mov     esp, ebp
        pop     ebp
        }
}
