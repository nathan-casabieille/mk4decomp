/**
 * 2 "two-call + pause guard + tail-jmp" helpers (34 bytes each).
 *
 * Pattern:
 *   call    FuncA
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     ret_label
 *   call    FuncB
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     ret_label
 *   jmp     Tail
 * ret_label:
 *   ret
 */
#include "game/tick.h"

extern void ScaledStore501Set8Jmp_0042c390(void);
extern void Cascade3ChainInit_0048fa50(void);
extern void StoreLitRetSet2_0042c3b0(void);
extern void GateDispatch6c_00494580(void);
extern void CjTableThresholdDispatch_00488f00(void);
extern void AggressorRunInitCluster_004813b0(void);

/* @addr 0x0042b690 */
__declspec(naked) void TwoCallTail_0042b690(void) {
    __asm {
        call    ScaledStore501Set8Jmp_0042c390
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   13h
        call    Cascade3ChainInit_0048fa50
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     StoreLitRetSet2_0042c3b0
        ret
    }
}

/* @addr 0x00481380 */
__declspec(naked) void TwoCallTail_00481380(void) {
    __asm {
        call    GateDispatch6c_00494580
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   13h
        call    CjTableThresholdDispatch_00488f00
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     AggressorRunInitCluster_004813b0
        ret
    }
}
