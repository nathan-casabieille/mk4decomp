/**
 * Auto-split from misc_matchesQ.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004ab350 (40b)
 *   mov     eax, [g_eventQueueWorkType]
 *   test    eax, eax
 *   jle     +0x19
 *   fild    dword ptr [g_eventQueueWorkType]
 *   fmul    qword ptr [0x004d27b0]
 *   fsqrt
 *   fmul    qword ptr [0x004d27b8]
 *   call    F
 *   mov     [g_walkCallback], eax
 *   ret
 */
extern double g_const_004d27b0;
extern double g_const_004d27b8;
extern int func_004cb7b0(void);

void FpuSqrtMul_004ab350(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueWorkType]
        test    eax, eax
        _emit   7eh
        _emit   19h
        fild    dword ptr [g_eventQueueWorkType]
        fmul    qword ptr [g_const_004d27b0]
        fsqrt
        fmul    qword ptr [g_const_004d27b8]
        call    func_004cb7b0
        mov     dword ptr [g_walkCallback], eax
        }
}

