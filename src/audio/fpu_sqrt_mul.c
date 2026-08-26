/**
 * Auto-split from misc_matchesQ.c
 */
#include "engine/scenegraph.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
#endif

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
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern double g_fpInvFixed16;
extern double g_fpFixed16Scale;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_eventQueueWorkType (*(unsigned int *)MK4_VA(unsigned int, 0x542074u))
#define g_fpFixed16Scale (*(double *)MK4_VA(double, 0x4d27b8u))
#define g_fpInvFixed16 (*(double *)MK4_VA(double, 0x4d27b0u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif

extern int DoubleToInt64(void);

#ifdef NON_MATCHING
/* Portable twin. The `jle +0x19` lands on the `mov [g_walkCallback], eax` -
 * NOT on the ret - so the store happens on BOTH paths: 40 bytes total, and
 * 0x09 + 0x19 = 0x22 is exactly that store. When the counter is <= 0 the FPU
 * chain and the call are skipped and EAX still holds the counter, so the
 * counter itself is what gets stored. (An early `return` here verifies clean
 * at rest and fails the moment the counter is seeded negative.)
 *
 * fild loads the counter as a signed int, and DoubleToInt64 is MSVC's
 * truncate-toward-zero ftol whose low half (eax) is what gets stored - so a
 * (long long) cast, narrowed to 32 bits. __builtin_sqrt, not sqrt(): the
 * original is a bare x87 fsqrt with no errno bookkeeping, and the builtin is
 * what both gcc and clang lower to the hardware instruction. */
void FpuSqrtMul(void)
{
    int v = (int)g_eventQueueWorkType;
    unsigned int r = (unsigned int)v;

    if (v > 0)
        r = (unsigned int)(long long)
            (__builtin_sqrt((double)v * g_fpInvFixed16) * g_fpFixed16Scale);
    g_walkCallback = r;
}
#else
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
#endif
