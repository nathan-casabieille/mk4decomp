/**
 * 2 "four const stores + call + lit-call + jmp" helpers (88b).
 *
 * Pattern:
 *   mov     eax, [g_baseSel_00542060]
 *   mov     [eax*4 + 0x74], 0x00001011
 *   mov     [g_state_00537e94], 5
 *   mov     [g_walkCallback], 0x00008000
 *   mov     [g_eventQueueCurrent], 0
 *   call    FuncA
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   push    LITERAL
 *   call    FuncB
 *   mov     eax, [g_framePauseFlag]
 *   add     esp, 4
 *   test    eax, eax
 *   jne     .ret
 *   jmp     Tail
 * .ret:
 *   ret
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_state_00537e94;

extern void *g_lit_004ed7e0;
extern void *g_lit_004ed7f0;
extern void func_0048ff30(void);
extern int  func_004908f0(void *p);
extern void func_0047ff80(void);

/* @addr 0x0047fec0 */
__declspec(naked) void FourConstCallLitCallJmp_0047fec0(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     dword ptr [eax*4 + 0x74], 0x00001011
        mov     dword ptr [g_state_00537e94], 5
        mov     dword ptr [g_walkCallback], 0x00008000
        mov     dword ptr [g_eventQueueCurrent], 0
        call    func_0048ff30
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1bh
        push    OFFSET g_lit_004ed7e0
        call    func_004908f0
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_0047ff80
        ret
    }
}

/* @addr 0x0047ff20 */
__declspec(naked) void FourConstCallLitCallJmp_0047ff20(void) {
    __asm {
        mov     eax, dword ptr [g_baseSel_00542060]
        mov     dword ptr [eax*4 + 0x74], 0x00001011
        mov     dword ptr [g_state_00537e94], 5
        mov     dword ptr [g_walkCallback], 0x00008000
        mov     dword ptr [g_eventQueueCurrent], 0
        call    func_0048ff30
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   1bh
        push    OFFSET g_lit_004ed7f0
        call    func_004908f0
        mov     eax, dword ptr [g_framePauseFlag]
        add     esp, 4
        test    eax, eax
        _emit   75h
        _emit   05h
        jmp     func_0047ff80
        ret
    }
}
