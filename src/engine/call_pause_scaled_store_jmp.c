/**
 * 2 "call + pause guard + scaled store + tail-jmp" helpers (38b).
 *
 * Pattern:
 *   call    FuncA
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, [g_fightGroupHead]
 *   mov     ecx, [g_eventQueueCurrent]
 *   mov     [eax*4 + 0x28], ecx
 *   jmp     Tail
 * .ret:
 *   ret
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern void func_00406ba0(void);
extern void func_00428850(void);
extern void func_004288e0(void);

/* @addr 0x00428820 */
__declspec(naked) void CallPauseScaledStoreJmp_00428820(void) {
    __asm {
        call    func_00406ba0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   17h
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [g_eventQueueCurrent]
        mov     dword ptr [eax*4 + 0x28], ecx
        jmp     func_00428850
        ret
    }
}

/* @addr 0x004288b0 */
__declspec(naked) void CallPauseScaledStoreJmp_004288b0(void) {
    __asm {
        call    func_00406ba0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   17h
        mov     eax, dword ptr [g_fightGroupHead]
        mov     ecx, dword ptr [g_eventQueueCurrent]
        mov     dword ptr [eax*4 + 0x28], ecx
        jmp     func_004288e0
        ret
    }
}
