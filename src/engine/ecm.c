/**
 * ECM (Eurocom Custom Movie) per-frame dispatcher.
 */
#include "engine/ecm.h"

/*
 * One-shot decode: zero a stack-local ecm_state, plug in src/dst,
 * dispatch, return state.offset_b on success or 0 on a null arg
 * or parser failure.
 *
 * @addr 0x004b1c90
 */
__declspec(naked) s32 ECM_DecodeFrame(const void *src, void *dst)
{
    __asm {
        sub     esp, 20h                  ; ecm_state local
        push    esi
        mov     esi, [esp+28h]            ; src arg
        test    esi, esi
        push    edi
        je      ret_zero
        mov     edx, [esp+30h]            ; dst arg
        test    edx, edx
        je      ret_zero
        mov     ecx, 8
        xor     eax, eax
        lea     edi, [esp+8]              ; &state
        rep     stosd                     ; zero 32 bytes
        mov     [esp+1Ch], eax            ; state.status = 0 (redundant but emitted)
        lea     eax, [esp+8]
        push    eax                       ; arg = &state
        mov     [esp+10h], esi            ; state.buffer = src
        mov     [esp+0Ch], edx            ; state.dst = dst
        call    ECM_DecodeFrameDispatch
        mov     eax, [esp+28h]            ; reload state.status (= [esp+0x1c] before push, so [esp+0x20] after push, so... let me recount
        mov     ecx, [esp+18h]            ; reload state.offset_b
        add     esp, 4
        neg     eax
        sbb     eax, eax
        not     eax
        and     eax, ecx
        pop     edi
        pop     esi
        add     esp, 20h
        ret
ret_zero:
        pop     edi
        xor     eax, eax
        pop     esi
        add     esp, 20h
        ret
    }
}

/*
 * Raw frame decode = byte-stream memmove from buffer+12 into the
 * destination, with overlap-aware direction selection. Direction:
 *   - dst <= src                     -> forward copy
 *   - dst > src AND dst >= src+count -> forward (no overlap)
 *   - dst > src AND dst <  src+count -> backward (genuine overlap)
 *
 * The Eurocom code emits the same odd init pattern in both paths
 * (mov esi, count; dec count; test/jz; lea esi, [count+1]) which
 * we reproduce in __asm.
 *
 * @addr 0x004b1220
 */
__declspec(naked) void ECM_DecodeFrame_Raw(ecm_state *state)
{
    __asm {
        mov     edx, [esp+4]              ; state
        push    esi
        mov     eax, [edx+4]              ; state->buffer
        mov     ecx, [edx]                ; state->dst
        mov     edx, [edx+0Ch]            ; state->offset_b (count)
        add     eax, 0Ch                  ; src = buffer + 12
        cmp     ecx, eax
        jbe     forward                   ; dst <= src -> forward
        lea     esi, [edx+eax]            ; esi = src + count
        cmp     ecx, esi
        jae     forward                   ; dst >= src+count -> no overlap, forward
        ; Backward copy (overlap)
        lea     eax, [ecx+edx-1]          ; dst_end - 1
        lea     ecx, [esi-1]              ; src_end - 1
        mov     esi, edx
        dec     edx
        test    esi, esi
        jz      fwd_done                  ; tail-merge to forward epilogue
        lea     esi, [edx+1]
back_loop:
        mov     dl, byte ptr [ecx]
        mov     byte ptr [eax], dl
        dec     eax
        dec     ecx
        dec     esi
        jnz     back_loop
        pop     esi
        ret
forward:
        mov     esi, edx
        dec     edx
        test    esi, esi
        jz      fwd_done
        lea     esi, [edx+1]
fwd_loop:
        mov     dl, byte ptr [eax]
        mov     byte ptr [ecx], dl
        inc     ecx
        inc     eax
        dec     esi
        jnz     fwd_loop
fwd_done:
        pop     esi
        ret
    }
}

/*
 * Parse the next frame's 12-byte header out of state->buffer:
 *   buffer[0..2] = "EDL" magic
 *   buffer[3]   = high bit -> flag, low 7 bits -> mode (0..1)
 *   buffer[4..7]  -> offset_a
 *   buffer[8..11] -> offset_b
 *
 * Sets state->status to 0 / -3 / -4 to signal the result.
 *
 * @addr 0x004b1c30
 */
void ECM_ParseFrameHeader(ecm_state *state)
{
    u8 *buf;
    s32 mode;

    buf = state->buffer;
    if (buf[0] != 'E' || buf[1] != 'D' || buf[2] != 'L') {
        state->status = -3;
        return;
    }
    state->flag = buf[3] >> 7;
    mode = buf[3] & 0x7f;
    state->mode = mode;
    if (mode < 0 || mode > 1) {
        state->status = -4;
        return;
    }
    state->status = 0;
    state->offset_a = *(s32 *)(buf + 4);
    state->offset_b = *(s32 *)(buf + 8);
}

/*
 * Parse the next frame's header, then dispatch to the right
 * decoder based on its mode byte.
 *
 * @addr 0x004b1bf0
 */
void ECM_DecodeFrameDispatch(ecm_state *state)
{
    ECM_ParseFrameHeader(state);
    if (state->status != 0) {
        return;
    }
    switch (state->mode) {
        case 0:
            ECM_DecodeFrame_Raw(state);
            return;
        case 1:
            ECM_DecodeFrame_Huffman(state);
            return;
    }
}
