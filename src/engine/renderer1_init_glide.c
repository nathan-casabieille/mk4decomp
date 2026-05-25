/**
 * Glide (3dfx) renderer init.
 *
 * Generates two FP tables (a 256-entry "0..255" float and a 32-
 * entry bit-pattern float table), opens the Glide context, queries
 * the adapter list via grSstQueryHardware, picks a video mode, and
 * runs the standard sequence of Glide setup calls (grSstSelect,
 * grSstWinOpen, grRenderBuffer, grColorMask, grAlphaCombine, ...).
 * Returns 1 on success, 0 on any failure (with Helper_GlideError
 * called on the way out).
 */
#include "engine/render.h"
#include "platform/win32.h"

/*
 * @addr 0x004b49a0
 *

 * Naked + __asm: long sequence of indirect-thru-IAT-style calls
 * via [g_glideFnTable + N] plus the 256-element fill loop's
 * conversion-via-stack ([esp+0xc] used as a 4-byte fild/fstp
 * scratch slot).  The 32-element bit-pattern fill uses an
 * `and dl, 1; neg dl; sbb edx, edx; and edx, 7; or esi, edx`
 * idiom that no C body would reproduce.
 *
 * NB: pure-C conversion attempted at length (see notes below). Got
 * within 26 bytes (592 vs 618 with stdcall casts + volatile dup
 * stores + int-cast for g_glideTable2). MSVC SP3 caches the zero
 * constant in EBX (callee-saved), emitting 27x `push ebx` (1b)
 * instead of orig's `push 0` (2b); no #pragma optimize variant
 * (g/s/t/w/a/p) nor source restructuring (volatile counter, register
 * hints, separate locals, explicit constant expressions) coaxed
 * MSVC into a caller-saved register for the zero. Kept as naked.
 */

__declspec(naked) int Renderer1_Init_Glide(HWND hwnd)
{
    __asm {
        mov     eax, dword ptr [g_renderer1_active]
        xor     ecx, ecx
        push    esi
        cmp     eax, ecx
        push    edi
        jne     already_inited
        mov     eax, dword ptr [esp + 0xc]
        xor     edx, edx
        mov     dword ptr [g_glideD0], edx
        mov     dword ptr [g_glideHwnd], eax
        mov     dword ptr [g_glideD4], edx
        mov     dword ptr [g_renderer1_busy], ecx
        mov     dword ptr [g_glideD8], edx
        mov     dword ptr [g_renderer1_surface], ecx
        mov     dword ptr [g_glideDC], edx
        mov     byte ptr [g_glideE8], cl
        mov     dword ptr [g_glideE0], edx
        mov     dword ptr [g_glideD0], ecx
        mov     dword ptr [g_glideD4], ecx
        mov     dword ptr [g_glideD8], 3
        mov     dword ptr [g_glideDC], 0xa
        mov     dword ptr [esp + 0xc], ecx
        mov     eax, offset g_glideTable1
fill_table1:
        fild    dword ptr [esp + 0xc]
        mov     edi, dword ptr [esp + 0xc]
        add     eax, 4
        inc     edi
        cmp     eax, offset g_glideTable1 + 0x400
        fstp    dword ptr [eax - 4]
        mov     dword ptr [esp + 0xc], edi
        jl      SHORT fill_table1
        xor     eax, eax
        mov     ecx, offset g_glideTable3
fill_table3:
        mov     edx, eax
        lea     esi, [eax*8]
        and     dl, 1
        neg     dl
        sbb     edx, edx
        add     ecx, 4
        and     edx, 7
        or      esi, edx
        inc     eax
        mov     dword ptr [esp + 0xc], esi
        cmp     ecx, offset g_glideD0
        fild    dword ptr [esp + 0xc]
        fstp    dword ptr [ecx - 4]
        jl      SHORT fill_table3
        call    Helper_GlideOpen
        test    eax, eax
        je      fail_path
        mov     ecx, 0x25
        xor     eax, eax
        mov     edi, offset g_glideAdapterInfo
        push    offset g_glideAdapterInfo
        rep     stosd
        call    dword ptr [g_glideFnTable + 0x44]
        cmp     eax, 1
        jne     fail_path
        cmp     dword ptr [g_glideAdapterInfo], 1
        jl      fail_path
        call    Helper_GlideMode
        call    dword ptr [g_glideFnTable + 0x34]
        push    offset g_glideAdapterInfo
        mov     dword ptr [g_glideF8], 1
        call    dword ptr [g_glideFnTable + 0x48]
        cmp     eax, 1
        jne     SHORT fail_path
        push    0
        call    dword ptr [g_glideFnTable + 0x4c]
        mov     eax, dword ptr [g_glideDC]
        mov     ecx, dword ptr [g_glideD8]
        mov     edx, dword ptr [g_glideD4]
        push    eax
        mov     eax, dword ptr [g_glideD0]
        push    ecx
        push    edx
        push    eax
        call    dword ptr [g_glideFnTable + 0x58]
        mov     dword ptr [g_glideContext], eax
        xor     edi, edi
        mov     esi, offset g_glideTable2
fill_table2:
        push    0
        call    dword ptr [g_glideFnTable + 0x6c]
        mov     ecx, edi
        add     esi, 4
        imul    ecx, dword ptr [g_glideContext]
        add     eax, ecx
        inc     edi
        mov     dword ptr [esi - 4], eax
        cmp     esi, offset g_glideTable2 + 0x40
        jl      SHORT fill_table2
        push    0
        call    dword ptr [g_glideFnTable + 0x6c]
        mov     esi, 8
        push    0
        sub     esi, eax
        call    dword ptr [g_glideFnTable + 0x68]
        mov     edx, dword ptr [g_glideContext]
        add     esi, eax
        shl     edx, 4
        cmp     esi, edx
        jae     SHORT all_ok
fail_path:
        call    Helper_GlideError
        xor     eax, eax
        pop     edi
        pop     esi
        ret
all_ok:
        push    1
        call    Helper_GlidePostInit
        add     esp, 4
        call    dword ptr [g_glideFnTable + 0x28]
        push    2
        call    dword ptr [g_glideFnTable + 0x2c]
        push    0x1e0
        push    0x280
        push    0
        push    0
        call    dword ptr [g_glideFnTable + 0x1c]
        mov     esi, 3
buffer_loop:
        push    0xffff
        push    0
        push    0
        call    dword ptr [g_glideFnTable + 0xc]
        push    0
        call    dword ptr [g_glideFnTable + 0x10]
        dec     esi
        jne     SHORT buffer_loop
        push    0
        push    0
        push    0
        push    0
        push    0
        push    1
        push    0
        call    dword ptr [g_glideFnTable + 0x5c]
        push    0
        push    1
        push    0
        push    1
        push    3
        call    dword ptr [g_glideFnTable + 0x20]
        push    0
        push    2
        push    0
        push    0
        push    1
        call    dword ptr [g_glideFnTable + 8]
        push    1
        push    1
        push    0
        call    dword ptr [g_glideFnTable + 0x64]
        push    0
        push    0
        push    0
        call    dword ptr [g_glideFnTable + 0x70]
        push    1
        call    dword ptr [g_glideFnTable + 0x14]
        push    0
        call    dword ptr [g_glideFnTable + 0x18]
        push    0
        call    dword ptr [g_glideFnTable + 0x24]
        mov     dword ptr [g_renderer1_active], 1
already_inited:
        pop     edi
        mov     eax, 1
        pop     esi
        ret
    }
}
