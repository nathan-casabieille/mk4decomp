/**
 * 2 "copy-call-pause-jmp" helpers (30 bytes each).
 *
 * Pattern:
 *   mov     eax, [g_A]
 *   mov     [g_B], eax
 *   call    Func
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     skip
 *   jmp     Tail
 * skip:
 *   ret
 *
 * The compiler emits two return-equivalent paths (the e9 + ret tail
 * is functionally dead since the e9's rel32 lands directly on the
 * ret), but the encoded layout is preserved here for byte-match.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

extern void func_0048b6c0(void);
extern void func_0048b500(void);
extern void func_00406790(void);
extern void func_0041f780(void);

/* @addr 0x0048b4e0 */
__declspec(naked) void CopyCallPauseJmp_0048b4e0(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueChild]
        mov     dword ptr [g_eventQueueWorkType], eax
        call    func_0048b6c0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_0048b500
        ret
    }
}

/* @addr 0x004a19a0 */
__declspec(naked) void CopyCallPauseJmp_004a19a0(void) {
    __asm {
        mov     eax, dword ptr [g_fightGroupHead]
        mov     dword ptr [g_scaledInit_00542044], eax
        call    func_00406790
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_0041f780
        ret
    }
}
