/**
 * Auto-split from misc_matches7.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x00404af0 (18b)
 *   mov     eax, [esp+4]
 *   mov     ecx, 0x10
 *   imul    dword ptr [esp+8]
 *   jmp     +0x0c0b5e
 */
extern void Sar64(void);
#ifdef NON_MATCHING
/* Signed 16.16 fixed-point multiply: full 64-bit product of the two args
 * shifted right by 16. The matching #else computes the 64-bit `imul`,
 * loads the shift count (0x10) into ecx, and tail-jmps to Sar64 (the
 * shared >>16 epilogue). Behavior here is identical; byte form is not.
 * TODO(Phase 3): unify the prototype to int(int,int) at all call sites -
 * many files still carry `extern void Mul10Tail(...)` from the naked era. */
int Mul10Tail(int a, int b) {
    return (int)(((long long)a * (long long)b) >> 16);
}
#else
__declspec(naked) void Mul10Tail(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        mov     ecx, 0x10
        imul    dword ptr [esp + 8]
        jmp     Sar64
    }
}
#endif
