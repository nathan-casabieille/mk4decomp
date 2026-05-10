/**
 * 12 "scaled-base init + tail-jmp" wrappers.
 *
 * Pattern:
 *   mov eax, ADDR_OF_TABLE     ; b8 + imm32  (5 bytes)
 *   shr eax, 2                  ; c1 e8 02     (3 bytes)
 *   mov [g_scaledBase], eax     ; a3 + reloc   (5 bytes)
 *   jmp Target                  ; e9 + reloc   (5 bytes)
 *
 * Each helper primes a per-table scaled-base global (the
 * `addr/4` form used by the `[reg*4 + 0]` SIB+disp32=0
 * addressing trick) and tail-calls into the actual handler.
 */
#include "engine/scenegraph.h"

/* New globals. */
extern unsigned int g_scaledInit_00542044;   /* 0x00542044 */
extern unsigned int g_scaledInit_00542048;   /* 0x00542048 */

/* Externs for jump targets. */
extern void func_00417e40(void);   /* 0x00417e40 */
extern void func_00441e50(void);   /* 0x00441e50 */
extern void func_00450f10(void);   /* 0x00450f10 */
extern void func_0048d500(void);   /* 0x0048d500 */
extern void func_0048f6d0(void);   /* 0x0048f6d0 */
extern void func_004955d0(void);   /* 0x004955d0 */

/* The wrappers. */
/* @addr 0x00417e20 */
__declspec(naked) void ScaledInit_00417e20(void) {
    __asm {
        mov     eax, 0x005420f0
        shr     eax, 2
        mov     dword ptr [g_eventQueueTotal], eax
        jmp     func_00417e40
    }
}

/* @addr 0x00441e10 */
__declspec(naked) void ScaledInit_00441e10(void) {
    __asm {
        mov     eax, 0x004e56d8
        shr     eax, 2
        mov     dword ptr [g_walkCallback], eax
        jmp     func_00441e50
    }
}

/* @addr 0x00441e30 */
__declspec(naked) void ScaledInit_00441e30(void) {
    __asm {
        mov     eax, 0x004e56d8
        shr     eax, 2
        mov     dword ptr [g_walkCallback], eax
        jmp     func_00441e50
    }
}

/* @addr 0x00450ed0 */
__declspec(naked) void ScaledInit_00450ed0(void) {
    __asm {
        mov     eax, 0x004e7c90
        shr     eax, 2
        mov     dword ptr [g_walkCallback], eax
        jmp     func_00450f10
    }
}

/* @addr 0x00450ef0 */
__declspec(naked) void ScaledInit_00450ef0(void) {
    __asm {
        mov     eax, 0x004e7c48
        shr     eax, 2
        mov     dword ptr [g_walkCallback], eax
        jmp     func_00450f10
    }
}

/* @addr 0x0048d430 */
__declspec(naked) void ScaledInit_0048d430(void) {
    __asm {
        mov     eax, 0x00542ea8
        shr     eax, 2
        mov     dword ptr [g_scaledInit_00542044], eax
        jmp     func_0048d500
    }
}

/* @addr 0x0048d450 */
__declspec(naked) void ScaledInit_0048d450(void) {
    __asm {
        mov     eax, 0x00542ef8
        shr     eax, 2
        mov     dword ptr [g_scaledInit_00542044], eax
        jmp     func_0048d500
    }
}

/* @addr 0x0048d470 */
__declspec(naked) void ScaledInit_0048d470(void) {
    __asm {
        mov     eax, 0x00542e48
        shr     eax, 2
        mov     dword ptr [g_scaledInit_00542044], eax
        jmp     func_0048d500
    }
}

/* @addr 0x0048d490 */
__declspec(naked) void ScaledInit_0048d490(void) {
    __asm {
        mov     eax, 0x00542d00
        shr     eax, 2
        mov     dword ptr [g_scaledInit_00542044], eax
        jmp     func_0048d500
    }
}

/* @addr 0x0048f720 */
__declspec(naked) void ScaledInit_0048f720(void) {
    __asm {
        mov     eax, 0x00542fb0
        shr     eax, 2
        mov     dword ptr [g_scaledInit_00542044], eax
        jmp     func_0048f6d0
    }
}

/* @addr 0x00495590 */
__declspec(naked) void ScaledInit_00495590(void) {
    __asm {
        mov     eax, 0x004f1ba0
        shr     eax, 2
        mov     dword ptr [g_scaledInit_00542048], eax
        jmp     func_004955d0
    }
}

/* @addr 0x004955b0 */
__declspec(naked) void ScaledInit_004955b0(void) {
    __asm {
        mov     eax, 0x004f1be8
        shr     eax, 2
        mov     dword ptr [g_scaledInit_00542048], eax
        jmp     func_004955d0
    }
}

