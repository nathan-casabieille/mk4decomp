/**
 * 3 "scaled-base SAR + tail-jmp" wrappers.
 *
 * Distinct from src/engine/scaled_init.c which uses SHR. These three
 * use SAR (arithmetic shift), so the encoded byte differs:
 *   c1 e8 02  shr eax, 2
 *   c1 f8 02  sar eax, 2
 *
 * Pattern (18 bytes total):
 *   mov eax, ADDR_OF_TABLE
 *   sar eax, 2
 *   mov [g_scaledBase], eax
 *   jmp Target
 */
#include "engine/scenegraph.h"

extern void func_00436910(void);
extern void func_004677f8(void);

/* @addr 0x004368f0 */
__declspec(naked) void ScaledAddrInit_004368f0(void) {
    __asm {
        mov     eax, 0x004e4780
        sar     eax, 2
        mov     dword ptr [g_eventQueueEnd], eax
        jmp     func_00436910
    }
}

/* @addr 0x004677c0 */
__declspec(naked) void ScaledAddrInit_004677c0(void) {
    __asm {
        mov     eax, 0x004e56d8
        sar     eax, 2
        mov     dword ptr [g_walkCallback], eax
        jmp     func_004677f8
    }
}

/* @addr 0x004677e0 */
__declspec(naked) void ScaledAddrInit_004677e0(void) {
    __asm {
        mov     eax, 0x004e56d8
        sar     eax, 2
        mov     dword ptr [g_walkCallback], eax
        jmp     func_004677f8
    }
}
