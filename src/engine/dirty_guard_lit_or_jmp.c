/**
 * 2 "dirty-guard literal-call or tail-jmp" helpers (28 bytes each).
 *
 * Pattern:
 *   cmp     [g_xformScratch2088], 1
 *   jne     .literal_path
 *   jmp     NextFunc                  ; equal: tail-jmp into follow-up
 * .literal_path:
 *   push    LITERAL
 *   call    Sink
 *   add     esp, 4
 *   ret
 *
 * Branches on a scratch flag: if it's exactly 1, defers to the
 * adjacent function; otherwise calls a sink with a per-helper data
 * pointer.
 */
#include "engine/scenegraph.h"

extern void *g_lit_004ed6d0;
extern void *g_lit_004f17a8;
extern void func_0047ef60(void);
extern void func_00496960(void);
extern int  func_004594f0(void *p);

/* @addr 0x0047ef40 */
__declspec(naked) void DirtyGuardLitOrJmp_0047ef40(void) {
    __asm {
        cmp     dword ptr [g_xformScratch2088], 1
        _emit   75h
        _emit   05h
        jmp     func_0047ef60
        push    OFFSET g_lit_004ed6d0
        call    func_004594f0
        add     esp, 4
        ret
    }
}

/* @addr 0x00496940 */
__declspec(naked) void DirtyGuardLitOrJmp_00496940(void) {
    __asm {
        cmp     dword ptr [g_xformScratch2088], 1
        _emit   75h
        _emit   05h
        jmp     func_00496960
        push    OFFSET g_lit_004f17a8
        call    func_004594f0
        add     esp, 4
        ret
    }
}
