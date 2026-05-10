/**
 * Full per-frame "DOWNLOAD Player N" debug + reload helper (4-player
 * variant). Differs from DownloadPlayerChar_Variant in that it
 * pre-validates the (p13_char, p24_char) pair, swapping or zeroing
 * fields so the four players never end up on the same character/nalt
 * combination, before printing+loading.
 */
#include "game/statemachine.h"
#include "game/tick.h"
#include "engine/scenegraph.h"
#include "engine/geo.h"

extern const char $SG_dl1[];
extern const char $SG_dl2[];
extern const char $SG_dl3[];
extern const char $SG_dl4[];

/*
 * @addr 0x0048bcf0
 *
 * Naked + __asm: the "char-mismatch correction" cascade is a long
 * series of cmp+jne+mov pairs reusing the eax/ecx pair across
 * branches; the fall-through-into-shared-tail layout for the printf
 * paths reuses ecx/eax/edx loads after each call. Pure C wouldn't
 * line these up the same way.
 */
__declspec(naked) void DownloadPlayerChar(void)
{
    __asm {
        push    ecx
        mov     al, byte ptr [g_dlEnabledFlag]
        push    esi
        test    al, al
        push    edi
        je      exit
        mov     eax, dword ptr [g_dlMode]
        mov     ecx, dword ptr [g_dlChar13]
        mov     esi, dword ptr [g_dlNalt3]
        mov     edx, dword ptr [g_dlNalt4]
        mov     edi, dword ptr [g_dlNalt1]
        cmp     eax, 1
        mov     eax, dword ptr [g_dlNalt2]
        mov     dword ptr [g_dlSomeFlag1], 0
        mov     dword ptr [g_dlSomeFlag2], 1
        mov     dword ptr [g_dlState], 0
        mov     dword ptr [g_dlAux], 1
        jne     SHORT skip_p1nalt_check
        cmp     edi, eax
        je      SHORT have_match
        cmp     esi, edx
        je      SHORT have_match
        cmp     edi, edx
        je      SHORT have_match
        cmp     esi, eax
        je      SHORT have_match
skip_p1nalt_check:
        cmp     edi, eax
        jne     reload_char24
have_match:
        mov     eax, dword ptr [g_dlChar24]
        test    ecx, ecx
        jne     SHORT skip_zz
        test    eax, eax
        jne     SHORT skip_zz
        mov     eax, 1
        mov     dword ptr [g_dlChar24], eax
skip_zz:
        test    ecx, ecx
        jne     SHORT skip_z2
        cmp     eax, 2
        jne     SHORT skip_z2
        mov     eax, 3
        mov     dword ptr [g_dlChar24], eax
skip_z2:
        cmp     ecx, 1
        jne     SHORT skip_1any
        cmp     eax, ecx
        jne     SHORT skip_11
        xor     eax, eax
        mov     dword ptr [g_dlChar24], eax
skip_11:
        cmp     ecx, 1
        jne     SHORT skip_1any
        cmp     eax, 3
        jne     SHORT skip_1any
        mov     eax, 2
        mov     dword ptr [g_dlChar24], eax
skip_1any:
        cmp     ecx, 2
        jne     SHORT skip_2any
        test    eax, eax
        jne     SHORT skip_20
        mov     eax, 1
        mov     dword ptr [g_dlChar24], eax
skip_20:
        cmp     ecx, 2
        jne     SHORT skip_2any
        cmp     eax, ecx
        jne     SHORT skip_2any
        mov     eax, 3
        mov     dword ptr [g_dlChar24], eax
skip_2any:
        cmp     ecx, 3
        jne     SHORT after_validation
        cmp     eax, 1
        jne     SHORT skip_31
        xor     eax, eax
        mov     dword ptr [g_dlChar24], eax
skip_31:
        cmp     ecx, 3
        jne     SHORT after_validation
        cmp     eax, ecx
        jne     SHORT after_validation
        mov     eax, 2
        mov     dword ptr [g_dlChar24], eax
        jmp     SHORT after_validation
reload_char24:
        mov     eax, dword ptr [g_dlChar24]
after_validation:
        mov     edx, dword ptr [g_eventQueueCurrent]
        test    edx, edx
        jne     SHORT skip_p1
        push    ecx
        push    edi
        push    offset $SG_dl1
        call    Helper_DownloadDebugPrint
        mov     ecx, dword ptr [g_dlChar13]
        mov     eax, dword ptr [g_dlChar24]
        mov     edx, dword ptr [g_eventQueueCurrent]
        add     esp, 0xc
skip_p1:
        cmp     edx, 1
        jne     SHORT skip_p2
        push    eax
        mov     eax, dword ptr [g_dlNalt2]
        push    eax
        push    offset $SG_dl2
        call    Helper_DownloadDebugPrint
        mov     ecx, dword ptr [g_dlChar13]
        mov     eax, dword ptr [g_dlChar24]
        mov     edx, dword ptr [g_eventQueueCurrent]
        add     esp, 0xc
skip_p2:
        cmp     edx, 2
        jne     SHORT skip_p3
        push    ecx
        mov     ecx, dword ptr [g_dlNalt3]
        push    ecx
        push    offset $SG_dl3
        call    Helper_DownloadDebugPrint
        mov     ecx, dword ptr [g_dlChar13]
        mov     eax, dword ptr [g_dlChar24]
        mov     edx, dword ptr [g_eventQueueCurrent]
        add     esp, 0xc
skip_p3:
        cmp     edx, 3
        jne     SHORT skip_p4
        mov     edx, dword ptr [g_dlNalt4]
        push    eax
        push    edx
        push    offset $SG_dl4
        call    Helper_DownloadDebugPrint
        mov     ecx, dword ptr [g_dlChar13]
        mov     eax, dword ptr [g_dlChar24]
        mov     edx, dword ptr [g_eventQueueCurrent]
        add     esp, 0xc
skip_p4:
        test    edx, edx
        jne     SHORT skip_v0
        mov     esi, dword ptr [g_dlNalt1]
        mov     edi, dword ptr [g_dlSomeFlag1]
        movsx   esi, byte ptr [ecx + esi*4 + g_dlVariantTable]
        jmp     SHORT after_v0
skip_v0:
        mov     edi, dword ptr [esp + 8]
        mov     esi, dword ptr [esp + 8]
after_v0:
        cmp     edx, 2
        jne     SHORT skip_v2
        mov     esi, dword ptr [g_dlNalt3]
        mov     edi, dword ptr [g_dlSomeFlag1]
        movsx   esi, byte ptr [ecx + esi*4 + g_dlVariantTable]
skip_v2:
        cmp     edx, 1
        jne     SHORT skip_v1
        mov     ecx, dword ptr [g_dlNalt2]
        mov     edi, dword ptr [g_dlSomeFlag2]
        movsx   esi, byte ptr [eax + ecx*4 + g_dlVariantTable]
skip_v1:
        cmp     edx, 3
        jne     SHORT skip_v3
        mov     edx, dword ptr [g_dlNalt4]
        mov     edi, dword ptr [g_dlSomeFlag2]
        movsx   esi, byte ptr [eax + edx*4 + g_dlVariantTable]
skip_v3:
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], ecx
        call    Helper_DownloadSetup
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        jne     do_pop
        mov     eax, dword ptr [g_eventQueueCurrent]
        mov     ecx, dword ptr [g_currentNodeIdx]
        test    eax, eax
        jne     SHORT skip_save0
        mov     dword ptr [g_dlSavedNodeIdx + 0], ecx
skip_save0:
        cmp     eax, 1
        jne     SHORT skip_save1
        mov     dword ptr [g_dlSavedNodeIdx + 4], ecx
skip_save1:
        cmp     eax, 2
        jne     SHORT skip_save2
        mov     dword ptr [g_dlSavedNodeIdx + 8], ecx
skip_save2:
        cmp     eax, 3
        jne     SHORT skip_save3
        mov     dword ptr [g_dlSavedNodeIdx + 0xc], ecx
skip_save3:
        test    edi, edi
        jne     SHORT use_chain1
        mov     edx, dword ptr [ecx*4 + 0xc]
        mov     eax, dword ptr [edx*4 + 4]
        sar     eax, 2
        mov     dword ptr [g_currentNodeIdx], eax
        jmp     SHORT do_load
use_chain1:
        mov     ecx, dword ptr [ecx*4 + 0x10]
        mov     edx, dword ptr [ecx*4 + 4]
        sar     edx, 2
        mov     dword ptr [g_currentNodeIdx], edx
do_load:
        push    esi
        call    LoadGeoAsset_Textures
        mov     eax, dword ptr [g_matrixStackTop]
        add     esp, 4
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_currentNodeIdx], ecx
        mov     dword ptr [g_matrixStackTop], eax
do_pop:
exit:
        pop     edi
        pop     esi
        pop     ecx
        ret
    }
}
