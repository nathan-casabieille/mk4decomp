/**
 * Renderer4 (SW-Win backend) frame presentation - DirectDraw Blt-style call.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004b2840 (74b)
 *   if [0x7af940] != 0: call helper; load 3 globals as args;
 *   push 9 fixed-args + 3 globals (DirectDraw Blt-style call);
 *   IAT call; tail-jmp to second IAT slot. Else: ret.
 */
extern unsigned int g_data_007af940;
extern unsigned int g_data_007af934;
extern unsigned int g_data_007af94c;
extern unsigned int g_data_007af938;
extern void *g_iat_004d2034;
extern void *g_iat_004d2040;
extern void Renderer4_EndScene_SW_Win(void);
__declspec(naked) void Renderer4_PresentFrame(void) {
    __asm {
        mov     eax, dword ptr [g_data_007af940]
        test    eax, eax
        _emit   74h
        _emit   40h
        call    Renderer4_EndScene_SW_Win
        mov     eax, dword ptr [g_data_007af934]
        mov     ecx, dword ptr [g_data_007af94c]
        push    0
        push    eax
        mov     edx, dword ptr [g_data_007af938]
        push    ecx
        push    0xf0
        push    0
        push    0
        push    0
        push    0xf0
        push    0x140
        push    0
        push    0
        push    edx
        call    dword ptr [g_iat_004d2034]
        jmp     dword ptr [g_iat_004d2040]
        ret
    }
}
