/**
 * ESF (Eurocom Sound Format) loader.
 */
#include "engine/esf.h"
#include "engine/fsys.h"
#include "platform/install.h"   /* ShowErrorMessage */

static const char k_esf_open_err[]  = "ESF_Open()";
static const char k_esf_rb[]        = "rb";

/*
 * Open an ESF file by name, validate its magic, optionally write
 * the per-file PCM format (bits / rate / channels) into out args,
 * and return the decoded byte count.
 *
 * The 8-byte file header lives at +0..+7:
 *   [0..3] = "ESF\x06" magic (little-endian 0x06465345)
 *   [4..7] = state word, packed:
 *     bits 0..28  = byte count
 *     bit 29      = bits-per-sample select (1 = 16-bit, else 8-bit)
 *     bit 30      = sample-rate select     (1 = 22050, else 11025)
 *     bit 31      = channels-1             (1 = stereo, 0 = mono)
 *
 * @addr 0x004b1090
 */
__declspec(naked) int ESF_Open(const char *filename, int *bits, int *rate, int *channels)
{
    __asm {
        call    ESF_Close
        mov     ecx, [esp+4]                ; filename
        xor     eax, eax
        mov     [g_esf_magic], eax
        push    offset k_esf_rb
        push    ecx
        mov     [g_esf_state], eax
        call    FSYS_fopen
        add     esp, 8
        mov     [g_esf_handle], eax
        push    eax
        push    1
        push    8
        push    offset g_esf_magic
        call    FSYS_fread
        mov     eax, [g_esf_magic]
        add     esp, 16
        cmp     eax, 06465345h              ; "ESF\x06"
        je      magic_ok
        push    offset k_esf_open_err
        call    ShowErrorMessage
        add     esp, 4
magic_ok:
        mov     eax, [esp+8]                ; bits out arg
        test    eax, eax
        jz      skip_bits
        mov     edx, [g_esf_state]
        shr     edx, 29
        and     dl, 1
        neg     dl
        sbb     edx, edx
        and     edx, 8
        add     edx, 8
        mov     [eax], edx                  ; *bits = (state>>29)&1 ? 16 : 8
skip_bits:
        mov     eax, [esp+0Ch]              ; rate out arg
        test    eax, eax
        jz      skip_rate
        mov     ecx, [g_esf_state]
        shr     ecx, 30
        and     cl, 1
        neg     cl
        sbb     ecx, ecx
        and     ecx, 02B11h                 ; mask
        add     ecx, 02B11h                 ; +11025
        mov     [eax], ecx                  ; *rate = (state>>30)&1 ? 22050 : 11025
skip_rate:
        mov     eax, [esp+10h]              ; channels out arg
        test    eax, eax
        jz      skip_channels
        mov     edx, [g_esf_state]
        shr     edx, 31
        mov     [eax], edx
skip_channels:
        mov     eax, [g_esf_state]
        and     eax, 1FFFFFFFh
        ret
    }
}

/*
 * Read decoded PCM into the destination buffer. Handles raw 8-bit
 * PCM (state bit 29 = 0) and IMA ADPCM (state bit 29 = 1). For
 * ADPCM, the compressed nibble stream is read into the tail end
 * of the destination buffer first, then decoded in place.
 *
 * @addr 0x004b1150
 */
__declspec(naked) void ESF_ReadData(void *dst)
{
    __asm {
        push    ecx                            ; reserve 4 bytes (ADPCM state local)
        mov     eax, [g_esf_handle]
        push    esi
        test    eax, eax
        push    edi
        mov     dword ptr [esp+8], 0           ; clear ADPCM state
        je      end
        push    0                              ; SEEK_SET
        push    8                              ; offset 8
        push    eax
        call    FSYS_fseek
        mov     eax, [g_esf_state]
        add     esp, 12
        mov     ecx, eax
        shr     ecx, 29
        test    cl, 1
        jz      raw_path
        ; ADPCM path
        mov     edi, [esp+16]                  ; dst arg
        mov     edx, [g_esf_handle]
        mov     ecx, eax
        and     eax, 1FFFFFFFh                 ; raw byte count
        shr     ecx, 2
        and     ecx, 7FFFFFFh                  ; ADPCM compressed count
        add     eax, edi
        sub     eax, ecx
        push    edx
        dec     eax
        push    1
        mov     esi, eax
        push    ecx
        push    esi
        call    FSYS_fread
        mov     ecx, [g_esf_state]
        add     esp, 16
        lea     eax, [esp+8]
        and     ecx, 1FFFFFFFh
        push    eax
        push    ecx
        push    edi
        push    esi
        call    ESF_DecodeADPCM
        add     esp, 16
        pop     edi
        pop     esi
        pop     ecx
        ret
raw_path:
        mov     edx, [g_esf_handle]
        and     eax, 1FFFFFFFh
        push    edx
        push    1
        push    eax
        mov     eax, [esp+28]                  ; dst arg
        push    eax
        call    FSYS_fread
        add     esp, 16
end:
        pop     edi
        pop     esi
        pop     ecx
        ret
    }
}

/*
 * Close the currently-open ESF file. Idempotent: handle == 0 is a
 * no-op except for clearing the slot.
 *
 * @addr 0x004b1200
 */
void ESF_Close(void)
{
    if (g_esf_handle != 0) {
        FSYS_fclose(g_esf_handle);
    }
    g_esf_handle = 0;
}
