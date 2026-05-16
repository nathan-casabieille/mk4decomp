/**
 * 7 "guarded scaled-base init + tail-jmp" wrappers.
 *
 * Pattern (33 bytes):
 *   call PreFunc                              ; e8 + reloc
 *   mov eax, [g_framePauseFlag]                ; a1 ...
 *   test eax, eax
 *   jne SHORT skip                             ; 75 12
 *   mov eax, IMM                              ; b8 ...
 *   shr eax, 2
 *   mov [g_scaledBase], eax                   ; a3 ...
 *   jmp Target                                 ; e9 + reloc
 *   ret
 */
#include "engine/scenegraph.h"
#include "game/tick.h"   /* g_framePauseFlag */

/* New globals. */
extern unsigned int g_gs_00542048;   /* 0x00542048 */

/* Externs for call/jump targets. */
extern void PendingMatch_0040cd50(void);   /* 0x0040cd50 */
extern void LinkedListSearch_004750f0(void);   /* 0x004750f0 */
extern void TestP1ReplaceCurrent_004751c0(void);   /* 0x004751c0 */
extern void MStackPush8_004ab790(void);   /* 0x004ab790 */

/* The wrappers. */
/* @addr 0x0040cd20 */
__declspec(naked) void GuardedScaled_0040cd20(void) {
    __asm {
        call    MStackPush8_004ab790
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   12h
        mov     eax, 0x004d7238
        shr     eax, 2
        mov     dword ptr [g_eventQueueTotal], eax
        jmp     PendingMatch_0040cd50
        ret
    }
}

/* @addr 0x00474fd0 */
__declspec(naked) void GuardedScaled_00474fd0(void) {
    __asm {
        call    TestP1ReplaceCurrent_004751c0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   12h
        mov     eax, 0x004ecaf0
        shr     eax, 2
        mov     dword ptr [g_gs_00542048], eax
        jmp     LinkedListSearch_004750f0
        ret
    }
}

/* @addr 0x00475000 */
__declspec(naked) void GuardedScaled_00475000(void) {
    __asm {
        call    TestP1ReplaceCurrent_004751c0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   12h
        mov     eax, 0x004ecb10
        shr     eax, 2
        mov     dword ptr [g_gs_00542048], eax
        jmp     LinkedListSearch_004750f0
        ret
    }
}

/* @addr 0x00475030 */
__declspec(naked) void GuardedScaled_00475030(void) {
    __asm {
        call    TestP1ReplaceCurrent_004751c0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   12h
        mov     eax, 0x004ecb20
        shr     eax, 2
        mov     dword ptr [g_gs_00542048], eax
        jmp     LinkedListSearch_004750f0
        ret
    }
}

/* @addr 0x00475060 */
__declspec(naked) void GuardedScaled_00475060(void) {
    __asm {
        call    TestP1ReplaceCurrent_004751c0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   12h
        mov     eax, 0x004ecb28
        shr     eax, 2
        mov     dword ptr [g_gs_00542048], eax
        jmp     LinkedListSearch_004750f0
        ret
    }
}

/* @addr 0x00475090 */
__declspec(naked) void GuardedScaled_00475090(void) {
    __asm {
        call    TestP1ReplaceCurrent_004751c0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   12h
        mov     eax, 0x004ecb40
        shr     eax, 2
        mov     dword ptr [g_gs_00542048], eax
        jmp     LinkedListSearch_004750f0
        ret
    }
}

/* @addr 0x004750c0 */
__declspec(naked) void GuardedScaled_004750c0(void) {
    __asm {
        call    TestP1ReplaceCurrent_004751c0
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   12h
        mov     eax, 0x004ecb48
        shr     eax, 2
        mov     dword ptr [g_gs_00542048], eax
        jmp     LinkedListSearch_004750f0
        ret
    }
}

