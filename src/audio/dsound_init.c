/**
 * DirectSound initialization + per-channel volume-curve table.
 *
 * Generates a 256-row x 100-col volume-curve table (each cell is
 * three int16s: left/right gain + signed-dB delta), zero-clears the
 * audio channel queue, then creates the IDirectSound + primary
 * buffer via the standard COM call sequence. Returns 1 on success,
 * 0 if either DirectSoundCreate or CreateSoundBuffer failed.
 */
#include "audio/sound.h"
#include "platform/win32.h"

/*
 * @addr 0x004c3ef0
 *
 * Naked + __asm: the FP volume-curve inner loop has a fixed
 * sequence of fld/fmul/fcom/fnstsw/fchs/fyl2x/fstp instructions
 * that pure C code generators won't reproduce verbatim, plus three
 * back-to-back _ftol calls each writing to a different word offset.
 * The trailing DSBUFFERDESC build also uses a "store edx then
 * overwrite with constant" pattern MSVC emits for partially
 * uninitialised structs.
 */
__declspec(naked) s32 DSound_Init(void *hwnd)
{
    __asm {
        sub     esp, 0x20
        mov     eax, dword ptr [esp + 0x24]
        push    ebx
        mov     dword ptr [g_dsoundHwnd], eax
        push    ebp
        xor     ebx, ebx
        mov     eax, 0xf85b62
        push    esi
        push    edi
        mov     dword ptr [g_dsoundFieldE0], ebx
        mov     byte ptr [g_audioMute], bl
        mov     dword ptr [g_dsoundFieldE8], ebx
        mov     dword ptr [g_dsoundFieldE4], ebx
        mov     dword ptr [esp + 0x34], eax
outer_loop:
        cmp     eax, 0xf8fac2
        mov     esi, ebx
        jg      outer_tail
        mov     edi, eax
        mov     ebp, eax
inner_loop:
        cmp     ebx, esi
        mov     dword ptr [esp + 0x10], ebx
        jg      SHORT use_min
        mov     dword ptr [esp + 0x10], esi
use_min:
        fild    dword ptr [esp + 0x10]
        mov     ecx, esi
        sub     ecx, ebx
        cmp     eax, 0xf85b62
        fstp    qword ptr [esp + 0x14]
        mov     dword ptr [esp + 0x10], ecx
        fild    dword ptr [esp + 0x10]
        je      SHORT use_default_one
        test    esi, esi
        je      SHORT use_default_one
        fld     st(0)
        fmulp   st(1), st
        fld     qword ptr [esp + 0x14]
        fmul    qword ptr [esp + 0x14]
        fxch    st(1)
        fmul    qword ptr [k_dsoundC1]
        fxch    st(1)
        fdivp   st(1), st
        jmp     SHORT after_ratio
use_default_one:
        fstp    st(0)
        fld     qword ptr [k_dsoundC1]
after_ratio:
        fcom    qword ptr [k_dsoundC1]
        fnstsw  ax
        test    ah, 0x41
        jne     SHORT skip_clamp_one
        fstp    st(0)
        fld     qword ptr [k_dsoundC1]
skip_clamp_one:
        cmp     ebx, esi
        jle     SHORT skip_neg
        fchs
skip_neg:
        fld     qword ptr [esp + 0x14]
        fmul    qword ptr [k_dsoundC2]
        fldlg2
        fxch    st(1)
        fyl2x
        fmul    qword ptr [k_dsoundC3]
        fcom    qword ptr [k_dsoundC4]
        fnstsw  ax
        test    ah, 0x1
        je      SHORT not_too_high
        fstp    st(0)
        fld     qword ptr [k_dsoundC4]
        jmp     SHORT after_clamp
not_too_high:
        fcom    qword ptr [k_dsoundC5]
        fnstsw  ax
        test    ah, 0x41
        jne     SHORT after_clamp
        fstp    st(0)
        fld     qword ptr [k_dsoundC5]
after_clamp:
        fsub    qword ptr [k_dsoundC6]
        call    _ftol
        mov     word ptr [ebp - 2], ax
        mov     word ptr [edi - 2], ax
        fld     st(0)
        call    _ftol
        fchs
        mov     word ptr [edi], ax
        call    _ftol
        mov     word ptr [ebp + 0], ax
        mov     eax, dword ptr [esp + 0x34]
        inc     esi
        add     edi, 4
        add     ebp, 0x194
        cmp     esi, 0x64
        jle     inner_loop
outer_tail:
        add     eax, 0x198
        inc     ebx
        cmp     eax, 0xf8fac2
        mov     dword ptr [esp + 0x34], eax
        jle     outer_loop
outer_done:
        mov     ecx, 0x3c28
        xor     eax, eax
        mov     edi, offset g_dsoundScratch
        push    0
        rep     stosd
        mov     ecx, 0x10
        or      eax, -1
        mov     edi, offset g_audioChannelQueue
        push    offset g_dsoundContext
        rep     stosd
        push    0
        mov     byte ptr [g_dsoundFieldDc], 0
        call    DirectSoundCreate_thunk
        mov     eax, dword ptr [g_dsoundContext]
        test    eax, eax
        je      SHORT skip_dsound
        mov     ecx, dword ptr [g_dsoundHwnd]
        mov     edx, dword ptr [eax]
        push    3
        push    ecx
        push    eax
        call    dword ptr [edx + 0x18]
        xor     edx, edx
        mov     eax, dword ptr [g_dsoundContext]
        mov     dword ptr [esp + 0x1c], edx
        mov     dword ptr [esp + 0x1c], 0x14
        mov     dword ptr [esp + 0x20], edx
        mov     dword ptr [esp + 0x20], 0x81
        mov     dword ptr [esp + 0x24], edx
        mov     dword ptr [esp + 0x28], edx
        mov     dword ptr [esp + 0x2c], edx
        mov     ecx, dword ptr [eax]
        push    edx
        lea     edx, [esp + 0x20]
        push    offset g_dsoundPrimary
        push    edx
        push    eax
        call    dword ptr [ecx + 0xc]
skip_dsound:
        push    1
        call    Helper_DSI_post1
        add     esp, 4
        push    0x5622
        call    Helper_DSI_post2
        add     esp, 4
        push    0x64
        call    Helper_TitleSetMaxVolume
        mov     eax, dword ptr [g_dsoundContext]
        add     esp, 4
        test    eax, eax
        je      SHORT return_zero
        mov     eax, dword ptr [g_dsoundPrimary]
        test    eax, eax
        je      SHORT return_zero
        mov     eax, 1
        pop     edi
        pop     esi
        pop     ebp
        pop     ebx
        add     esp, 0x20
        ret
return_zero:
        pop     edi
        pop     esi
        pop     ebp
        xor     eax, eax
        pop     ebx
        add     esp, 0x20
        ret
    }
}
