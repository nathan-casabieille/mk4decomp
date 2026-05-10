/**
 * Joystick / gamepad enumeration + calibration.
 *
 * For each joystick that responds to joyGetPos + joyGetDevCapsA,
 * derive per-axis calibration as
 *   center + ((max - min) * 33 / 50)
 * via the magic-multiply-by-0x51eb851f / shr 5 idiom (unsigned
 * divide-by-50). Stores the result tables to g_joyCal{A,B,C}
 * and stashes one button byte per device into g_joyButtonState.
 * Tail does a 256-iteration call to Helper_JoyButtonInit for
 * input mapping.
 */
#include "engine/geo.h"
#include "platform/win32.h"
#include <mmsystem.h>

/*
 * @addr 0x004b5230
 *
 * Naked + __asm: the per-iteration body uses lots of register
 * juggling between edx/eax/ecx/edi to compute the magic-divide
 * input as `(max - min) * 33` or `(max - min) * 66`, none of
 * which a C source would express identically in MASM output.
 */
__declspec(naked) void Joystick_Init(void)
{
    __asm {
        sub     esp, 0x1a4
        push    ebx
        push    ebp
        push    esi
        xor     esi, esi
        push    edi
        mov     dword ptr [g_joyCount], esi
        mov     ebx, offset g_joyCalA
        mov     ebp, offset g_joyCalC
joy_loop:
        lea     eax, [esp + 0x10]
        mov     byte ptr [esi + g_joyButtonState], 0
        push    eax
        push    esi
        call    dword ptr [joyGetPos]
        test    eax, eax
        jne     skip_dev                                  ; long form
        mov     ecx, 101
        lea     edi, [esp + 0x20]
        rep     stosd
        lea     ecx, [esp + 0x20]
        push    0x194
        push    ecx
        push    esi
        call    dword ptr [joyGetDevCapsA]
        test    eax, eax
        jne     skip_dev                                  ; long form
        mov     edi, dword ptr [esp + 0x50]
        mov     ecx, dword ptr [esp + 0x4c]
        mov     edx, edi
        mov     eax, ecx
        shl     edx, 5
        shl     eax, 5
        add     edx, edi
        add     eax, ecx
        sub     edx, eax
        mov     eax, 0x51eb851f
        mul     edx
        shr     edx, 5
        add     edx, ecx
        mov     eax, ecx
        mov     dword ptr [esi*4 + g_joyCalB], edx
        mov     edx, edi
        shl     edx, 5
        shl     eax, 5
        add     edx, edi
        add     eax, ecx
        shl     edx, 1
        shl     eax, 1
        sub     edx, eax
        mov     eax, 0x51eb851f
        mul     edx
        mov     edi, dword ptr [esp + 0x48]
        shr     edx, 5
        add     edx, ecx
        mov     ecx, edi
        shl     ecx, 5
        add     ecx, edi
        mov     dword ptr [esi*4 + g_joyCalC], edx
        mov     edx, ecx
        mov     ecx, dword ptr [esp + 0x44]
        mov     eax, ecx
        shl     eax, 5
        add     eax, ecx
        sub     edx, eax
        mov     eax, 0x51eb851f
        mul     edx
        shr     edx, 5
        add     edx, ecx
        mov     eax, ecx
        mov     dword ptr [ebp], edx
        mov     edx, edi
        shl     edx, 5
        shl     eax, 5
        add     edx, edi
        add     eax, ecx
        shl     edx, 1
        shl     eax, 1
        sub     edx, eax
        mov     eax, 0x51eb851f
        mul     edx
        mov     eax, dword ptr [g_joyCount]
        shr     edx, 5
        add     edx, ecx
        mov     cl, byte ptr [esp + 0x5c]
        inc     eax
        mov     dword ptr [ebx], edx
        mov     dword ptr [g_joyCount], eax
        mov     byte ptr [esi + g_joyButtonState], cl
skip_dev:
        add     ebp, 4
        inc     esi
        add     ebx, 4
        cmp     ebp, offset g_joyCalC + 0x40
        jl      joy_loop                                  ; long form
        xor     esi, esi
button_loop:
        push    esi
        call    Helper_JoyButtonInit
        add     esp, 4
        inc     esi
        cmp     esi, 0x100
        jl      button_loop
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 0x1a4
        ret
    }
}
