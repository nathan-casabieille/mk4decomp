/**
 * 2 "clamp two values to 0x10000" helpers (55 bytes each).
 *
 * Pattern:
 *   mov     eax, [g_X]
 *   cmp     eax, 0x00010000
 *   jle     .skipX
 *   mov     eax, 0x00010000
 *   mov     [g_X], eax
 * .skipX:
 *   mov     eax, [g_Y]
 *   cmp     eax, 0x00010000
 *   mov     [g_walkCallback], eax
 *   jle     .skipY
 *   mov     eax, 0x00010000
 *   mov     [g_walkCallback], eax
 *   mov     [g_Y], eax
 * .skipY:
 *   ret
 */
#include "engine/scenegraph.h"

extern unsigned int g_clamp_0053a6dc;
extern unsigned int g_clamp_0053a328;
extern unsigned int g_clamp_00537f2c;
extern unsigned int g_clamp_0053e348;

/* @addr 0x004226a0 */
__declspec(naked) void ClampTwoToMax_004226a0(void) {
    __asm {
        mov     eax, dword ptr [g_clamp_0053a6dc]
        cmp     eax, 0x00010000
        _emit   7eh
        _emit   05h
        mov     eax, 0x00010000
        mov     dword ptr [g_clamp_0053a6dc], eax
        mov     eax, dword ptr [g_clamp_0053a328]
        cmp     eax, 0x00010000
        mov     dword ptr [g_walkCallback], eax
        _emit   7eh
        _emit   0ah
        mov     eax, 0x00010000
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_clamp_0053a328], eax
        ret
    }
}

/* @addr 0x004226e0 */
__declspec(naked) void ClampTwoToMax_004226e0(void) {
    __asm {
        mov     eax, dword ptr [g_clamp_00537f2c]
        cmp     eax, 0x00010000
        _emit   7eh
        _emit   05h
        mov     eax, 0x00010000
        mov     dword ptr [g_clamp_00537f2c], eax
        mov     eax, dword ptr [g_clamp_0053e348]
        cmp     eax, 0x00010000
        mov     dword ptr [g_walkCallback], eax
        _emit   7eh
        _emit   0ah
        mov     eax, 0x00010000
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [g_clamp_0053e348], eax
        ret
    }
}
