/**
 * 2 "scaled load + two guarded calls + literal install + jmp" (66b).
 *
 * Pattern:
 *   mov     eax, [g_baseSel_00542060]
 *   mov     ecx, [eax*4 + 0x64]
 *   mov     [g_fightGroupHead], ecx
 *   call    FuncA
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   call    FuncB
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     edx, IMM_PTR
 *   shr     edx, 2
 *   mov     [g_eventQueueEnd], edx
 *   jmp     Tail
 * .ret:
 *   ret
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern void MStackPush2RunCountdown_004089e0(void);
extern void MStackBracket7_DispatchAndChain_004b8fa0(void);
extern void StunDownCluster_00451fc0(void);

/* @addr 0x00451f20 */
__declspec(naked) void ScaledLoadTwoCallLit_00451f20(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     ecx, dword ptr [eax*4 + 0x64]
        mov     dword ptr [g_fightGroupHead], ecx
        call    MStackPush2RunCountdown_004089e0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   21h
        call    MStackBracket7_DispatchAndChain_004b8fa0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   13h
        mov     edx, 0x004e7ae8
        shr     edx, 2
        mov     dword ptr [g_eventQueueEnd], edx
        jmp     StunDownCluster_00451fc0
        ret
    }
}

/* @addr 0x00451f70 */
__declspec(naked) void ScaledLoadTwoCallLit_00451f70(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     ecx, dword ptr [eax*4 + 0x64]
        mov     dword ptr [g_fightGroupHead], ecx
        call    MStackPush2RunCountdown_004089e0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   21h
        call    MStackBracket7_DispatchAndChain_004b8fa0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   13h
        mov     edx, 0x004e7a78
        shr     edx, 2
        mov     dword ptr [g_eventQueueEnd], edx
        jmp     StunDownCluster_00451fc0
        ret
    }
}
