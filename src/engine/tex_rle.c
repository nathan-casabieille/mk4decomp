/**
 * RLE-555 texture decode into the staging buffer.
 *
 * Each input row is a stream of 16-bit codes. If the high bit is
 * set, the next byte is a run length and the masked code (XOR'd
 * with g_texXorKey when non-zero) is repeated that many times.
 * Otherwise the code is written verbatim.
 */
#include "engine/geo.h"
#include "platform/win32.h"

/*
 * @addr 0x004bd5f0
 *
 * Naked + __asm: the early-out for "row_pixels < 1 || row_count < 1"
 * jumps directly into the MIDDLE of the epilogue (past the two pops
 * for esi/ebx, which weren't pushed yet at that point). Pure C
 * wouldn't generate that asymmetric epilogue.
 */
__declspec(naked) void Tex_DecodeRLE16(s32 row_width, s32 row_pixels,
                                       s32 row_count, const u8 *src,
                                       s32 arg5)
{
    __asm {
        sub     esp, 8
        push    ebp
        mov     ebp, dword ptr [esp + 0x14]         ; row_pixels
        push    edi
        mov     edi, offset g_texStripeBuf
        cmp     ebp, 1
        mov     dword ptr [esp + 8], edi            ; local0 = out ptr
        jl      short_epi                            ; long form (>127 fwd)
        mov     eax, dword ptr [esp + 0x1c]         ; row_count
        cmp     eax, 1
        jl      short_epi                            ; long form
        mov     edx, dword ptr [esp + 0x14]         ; row_width (arg)
        mov     ecx, 0xe
        push    esi
        cmp     edx, ecx
        push    ebx
        jbe     no_clamp
        mov     dword ptr [esp + 0x1c], ecx         ; arg slot for row_width = 14
no_clamp:
        test    eax, eax
        jle     skip_reload                          ; eax already = arg3 here, skip reload
        mov     ebx, dword ptr [esp + 0x28]         ; src
        mov     dword ptr [esp + 0x14], eax         ; local1 = remaining rows
row_loop:
        xor     esi, esi
        test    ebp, ebp
        jle     row_done
inner_loop:
        mov     ax, word ptr [ebx]
        add     ebx, 2
        test    ah, 0x80
        jz      not_rle
        and     eax, 0x7fff
        test    ax, ax
        jz      no_xor
        xor     eax, dword ptr [g_texXorKey]
no_xor:
        xor     edx, edx
        mov     dl, byte ptr [ebx]
        test    edx, edx
        jle     skip_run
        mov     bp, ax
        mov     ecx, edx
        shl     ebp, 16
        mov     bp, ax
        lea     edi, [edi + esi*2]
        mov     eax, ebp
        mov     ebp, dword ptr [esp + 0x20]
        shr     ecx, 1
        rep     stosd
        adc     ecx, ecx
        add     esi, edx
        ; orig encodes prefixes as 66 f3 ab (operand size first);
        ; MASM defaults to f3 66 ab. _emit forces the orig order.
        _emit   66h
        _emit   0F3h
        _emit   0ABh
        mov     edi, dword ptr [esp + 0x10]
skip_run:
        inc     ebx
        jmp     after_pixel
not_rle:
        mov     word ptr [edi + esi*2], ax
        inc     esi
after_pixel:
        cmp     esi, ebp
        jl      inner_loop
row_done:
        mov     eax, dword ptr [esp + 0x14]
        add     edi, 0x200
        dec     eax
        mov     dword ptr [esp + 0x10], edi
        mov     dword ptr [esp + 0x14], eax
        jne     row_loop
post_loop:
        mov     eax, dword ptr [esp + 0x24]
skip_reload:
        push    eax
        mov     eax, dword ptr [esp + 0x20]
        push    ebp
        push    0
        push    0
        push    eax
        call    Helper_TexUpload
        add     esp, 0x14
        pop     ebx
        pop     esi
short_epi:
        pop     edi
        pop     ebp
        add     esp, 8
        ret
    }
}
