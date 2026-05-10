/**
 * 2 "scaled-load + dec + branch on zero" helpers (38 bytes each).
 *
 * Pattern:
 *   mov     ecx, [g_baseSel_00542060]
 *   mov     eax, [ecx*4 + 0x30]
 *   dec     eax
 *   mov     [g_walkCallback], eax
 *   jne     .nonzero
 *   jmp     T_zero
 * .nonzero:
 *   mov     [ecx*4 + 0x30], eax        ; persist decremented counter
 *   jmp     T_continue
 *
 * Decrements a per-base counter through the scaled selector. If it
 * just hit zero, tail-jumps to the "expired" handler (and does not
 * write the zero back). Otherwise persists the new value and tail-
 * jumps into the continue handler.
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;

extern void func_00466490(void);
extern void func_004662e0(void);
extern void func_004667a0(void);
extern void func_004665b0(void);

/* @addr 0x00466460 */
__declspec(naked) void ScaledDecBranch_00466460(void) {
    __asm {
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     eax, dword ptr [ecx*4 + 0x30]
        dec     eax
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   05h
        jmp     func_00466490
        mov     dword ptr [ecx*4 + 0x30], eax
        jmp     func_004662e0
    }
}

/* @addr 0x00466770 */
__declspec(naked) void ScaledDecBranch_00466770(void) {
    __asm {
        mov     ecx, dword ptr [g_baseSel_00542060]
        mov     eax, dword ptr [ecx*4 + 0x30]
        dec     eax
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   05h
        jmp     func_004667a0
        mov     dword ptr [ecx*4 + 0x30], eax
        jmp     func_004665b0
    }
}
