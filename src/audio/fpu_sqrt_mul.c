/**
 * Auto-split from misc_matchesQ.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

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
extern double g_fpInvFixed16;
extern double g_fpFixed16Scale;
extern int DoubleToInt64(void);

void FpuSqrtMul(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueWorkType]
        test    eax, eax
        _emit   7eh
        _emit   19h
        fild    dword ptr [g_eventQueueWorkType]
        fmul    qword ptr [g_fpInvFixed16]
        fsqrt
        fmul    qword ptr [g_fpFixed16Scale]
        call    DoubleToInt64
        mov     dword ptr [g_walkCallback], eax
        }
}

