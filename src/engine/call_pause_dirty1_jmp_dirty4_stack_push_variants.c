/**
 * Auto-split from misc_matchesOO.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_phaseTimer_00537e94;

/* @addr 0x00428850 (84b)
 *   call F1; pause → ret; testb 1,[dirty]; je +5 → jmp T1;
 *   call F2; pause → ret; testb 4,[dirty]; je +0x1b →ret-tail;
 *   inc g_matrixStackTop; push 0x00428950 onto stack[idx*4]; jmp T2.
 */
extern void GuardedSeq_004297b0(void);
extern void func_00436670(void);
extern void func_0048f330(void);
extern void func_00428950_oo(void);
extern void func_004939a0(void);
extern void InstallSelfCallBitGate_00483ae0(void);

__declspec(naked) void CallPauseDirty1JmpDirty4StackPush_00428850(void) {
    __asm {
        call    GuardedSeq_004297b0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   45h
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   74h
        _emit   05h
        jmp     func_00436670
        call    func_0048f330
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   29h
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   74h
        _emit   1bh
        mov     eax, dword ptr [g_matrixStackTop]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], OFFSET func_00428950_oo
        jmp     func_004939a0
        _emit   0e9h
        _emit   0adh
        _emit   00h
        _emit   00h
        _emit   00h
        ret
    }
}

/* @addr 0x00483a80 (84b): same shape, push 0x00483ae0 instead of 0x00428950 */
extern void func_0047d860(void);
extern void func_00488bf0(void);
extern void func_0048f330_oo(void);
extern void func_0042b988_oo(void);
__declspec(naked) void CallPauseDirty1JmpDirty4StackPush_00483a80(void) {
    __asm {
        call    func_0047d860
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   45h
        test    byte ptr [g_xformDirtyFlags], 1
        _emit   74h
        _emit   05h
        jmp     func_00488bf0
        call    func_0048f330_oo
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   29h
        test    byte ptr [g_xformDirtyFlags], 4
        _emit   74h
        _emit   1bh
        mov     eax, dword ptr [g_matrixStackTop]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + 0], OFFSET InstallSelfCallBitGate_00483ae0
        jmp     func_0042b988_oo
        _emit   0e9h
        _emit   0dh
        _emit   00h
        _emit   00h
        _emit   00h
        ret
    }
}
