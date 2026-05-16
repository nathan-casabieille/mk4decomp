/**
 * 2 "scaled save + call + pause restore + tail-jmp" helpers (50b).
 *
 * Pattern:
 *   mov     eax, [g_A]
 *   mov     ecx, [eax*4 + 0x30]
 *   mov     [g_scaledInit_00542044], ecx
 *   call    Func
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     edx, [g_A]                         ; reload A
 *   mov     [g_scaledInit_00542044], edx       ; restore base
 *   jmp     Tail
 * .ret:
 *   ret
 *
 * Saves a scaled base derived from g_A, calls a worker, then if no
 * pause occurred, restores the scaled base from g_A again and tail-
 * jumps into the continue handler.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern void InstallSelfMagicShift_00472fe0(void);
extern void MStackPush2ChainLLInsert_00406790(void);

/* @addr 0x00472f40 */
__declspec(naked) void ScaledSaveCallRestoreJmp_00472f40(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueEnd]
        mov     ecx, dword ptr [eax*4 + 0x30]
        mov     dword ptr [g_scaledInit_00542044], ecx
        call    InstallSelfMagicShift_00472fe0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   11h
        mov     edx, dword ptr [g_eventQueueEnd]
        mov     dword ptr [g_scaledInit_00542044], edx
        jmp     MStackPush2ChainLLInsert_00406790
        ret
    }
}

/* @addr 0x00472f80 */
__declspec(naked) void ScaledSaveCallRestoreJmp_00472f80(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueIdx]
        mov     ecx, dword ptr [eax*4 + 0x30]
        mov     dword ptr [g_scaledInit_00542044], ecx
        call    InstallSelfMagicShift_00472fe0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   11h
        mov     edx, dword ptr [g_eventQueueIdx]
        mov     dword ptr [g_scaledInit_00542044], edx
        jmp     MStackPush2ChainLLInsert_00406790
        ret
    }
}
