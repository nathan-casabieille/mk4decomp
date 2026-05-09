/**
 * ESF (Eurocom Sound Format) loader.
 */
#include "engine/esf.h"
#include "engine/fsys.h"

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
