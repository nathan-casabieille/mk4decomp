/**
 * 4-bit IMA ADPCM decoder.
 *
 * Reads sample_count nibbles from src and writes 16-bit PCM samples
 * to dst. State is a packed (predictor << 8) | step_index in 32
 * bits. Each pair of samples consumes one input byte (high nibble
 * first, low nibble second).
 */
#include "audio/sound.h"

/*
 * @addr 0x004ac200
 *
 * Naked + __asm: the body alternates between high-nibble and
 * low-nibble decoding via a `sete cl; mov ebp, ecx` toggle, threads
 * the running predictor through edi across nibble computations,
 * and reuses the arg1 / arg3 stack slots as inner-loop locals.
 */
__declspec(naked) void ESF_DecodeADPCM(const u8 *src, s16 *dst,
                                       s32 sample_count, u32 *state)
{
    __asm {
        sub     esp, 8
        mov     eax, dword ptr [esp + 0x10]            ; arg2 (dst)
        mov     edx, dword ptr [esp + 0x18]            ; arg4 (state)
        push    ebx
        push    ebp
        mov     dword ptr [esp + 8], eax               ; local0 = dst
        mov     eax, dword ptr [edx]                    ; eax = *state
        push    esi
        push    edi
        mov     ecx, dword ptr [esp + 0x1c]            ; arg1 (src)
        mov     edi, eax                                ; edi = full state
        and     eax, 0xff                               ; step_index
        xor     ebp, ebp                                ; nibble toggle = 0
        mov     ebx, eax                                ; ebx = step_index
        mov     eax, dword ptr [esp + 0x24]            ; arg3 (sample_count)
        sar     eax, 1                                  ; / 2 = byte count
        mov     esi, dword ptr [ebx*4 + g_imaStepTable]
        mov     dword ptr [esp + 0x20], ecx            ; save src ptr to local
        sar     edi, 8                                  ; predictor
        test    eax, eax
        jle     epi                                      ; long form
        mov     dword ptr [esp + 0x1c], eax            ; save loop counter
loop_top:
        test    ebp, ebp
        jz      load_byte
        mov     eax, dword ptr [esp + 0x24]
        jmp     have_nibble
load_byte:
        mov     ecx, dword ptr [esp + 0x20]
        movsx   eax, byte ptr [ecx]
        inc     ecx
        mov     dword ptr [esp + 0x24], eax
        mov     dword ptr [esp + 0x20], ecx
        sar     eax, 4
have_nibble:
        and     eax, 0xf
        xor     ecx, ecx
        test    ebp, ebp
        sete    cl
        mov     ebp, ecx
        mov     ecx, dword ptr [eax*4 + g_imaIndexTable]
        add     ebx, ecx
        mov     dword ptr [esp + 0x14], ebp
        jns     no_neg_clamp
        xor     ebx, ebx
        jmp     compute_delta
no_neg_clamp:
        cmp     ebx, 0x58
        jle     compute_delta
        mov     ebx, 0x58
compute_delta:
        mov     edx, eax
        mov     ecx, esi
        and     eax, 7
        and     edx, 8
        sar     ecx, 3
        test    al, 4
        jz      no_full
        add     ecx, esi
no_full:
        test    al, 2
        jz      no_half
        mov     ebp, esi
        sar     ebp, 1
        add     ecx, ebp
        mov     ebp, dword ptr [esp + 0x14]      ; restore only when ebp was clobbered
no_half:
        test    al, 1
        jz      no_quarter
        sar     esi, 2
        add     ecx, esi
no_quarter:
        test    edx, edx
        jz      add_delta
        sub     edi, ecx
        jmp     clamp_top
add_delta:
        add     edi, ecx
clamp_top:
        cmp     edi, 0x7fff
        jle     check_min
        mov     edi, 0x7fff
        jmp     write_sample
check_min:
        cmp     edi, 0xffff8000
        jge     write_sample
        mov     edi, 0xffff8000
write_sample:
        mov     eax, dword ptr [esp + 0x10]
        mov     esi, dword ptr [ebx*4 + g_imaStepTable]
        mov     word ptr [eax], di
        add     eax, 2
        mov     dword ptr [esp + 0x10], eax
        mov     eax, dword ptr [esp + 0x1c]
        dec     eax
        mov     dword ptr [esp + 0x1c], eax
        jne     loop_top                                ; long form
epi:
        mov     edx, dword ptr [esp + 0x28]
        and     ebx, 0xff
        shl     edi, 8
        or      ebx, edi
        pop     edi
        pop     esi
        mov     dword ptr [edx], ebx
        pop     ebp
        pop     ebx
        add     esp, 8
        ret
    }
}
