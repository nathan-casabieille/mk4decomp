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

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dlNalt1 (*(unsigned int *)MK4_VA(unsigned int, 0x537f48u))
#define g_dlNalt2 (*(unsigned int *)MK4_VA(unsigned int, 0x5380e0u))
#define g_eventQueueCurrent (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#endif


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
#ifdef NON_MATCHING
#include "portable/mem_model.h"


/* @addr 0x0048bcf0 (741b) - NATIVE twin; the matching build keeps the
 * __asm body below (the correction cascade is a long chain of compares
 * MSVC lays out in an order pure C will not reproduce).
 *
 * Downloads one fighter into the scene. The head is the costume-clash
 * correction: when the same character is picked on both sides (or in the
 * two-vs-two arrangement the mode word selects), the second costume id is
 * nudged to a different one so the pair is visually distinct - 0<->1 and
 * 2<->3 within each half, applied in the fixed order the original tests.
 * Then the slot (0..3, from g_eventQueueCurrent) picks which character
 * index and which "some flag" apply, the variant byte comes from the
 * table at 0x4d5718 indexed by [costume][character], and the setup pass
 * runs with the node bracketed on the matrix stack. The resulting node
 * index is parked in this slot's saved-node global, the geo record is
 * chosen from the node's +0xc or +0x10 chain depending on the flag, and
 * the textures load with the variant as the index.
 *
 * The four debug prints are the original's - they go to the same helper
 * with a format string per slot and no effect on state. */
void DownloadPlayerChar(void)
{
    unsigned int mode, c13, c24, slot, flag;
    int variant;
    unsigned int fin1, fin2, n1, n2, node;

    if (*MK4_VA(unsigned char, 0x54371cu) == 0) return;

    mode = *MK4_VA(unsigned int, 0x542004u);
    c13  = *MK4_VA(unsigned int, 0x541ec4u);
    fin1 = *MK4_VA(unsigned int, 0x53a178u);
    fin2 = *MK4_VA(unsigned int, 0x53a250u);
    n1   = g_dlNalt1;
    n2   = g_dlNalt2;
    *MK4_VA(unsigned int, 0x53a510u) = 0;
    *MK4_VA(unsigned int, 0x52aafcu) = 1;
    *MK4_VA(unsigned int, 0x541e34u) = 0;
    *MK4_VA(unsigned int, 0x541e38u) = 1;

    if ((mode == 1 && (n1 == n2 || fin1 == fin2 || n1 == fin2 || fin1 == n2))
        || n1 == n2) {
        c24 = *MK4_VA(unsigned int, 0x541ec8u);
        if (c13 == 0 && c24 == 0) {
            c24 = 1; *MK4_VA(unsigned int, 0x541ec8u) = c24;
        }
        if (c13 == 0 && c24 == 2) {
            c24 = 3; *MK4_VA(unsigned int, 0x541ec8u) = c24;
        }
        if (c13 == 1 && c24 == 1) {
            c24 = 0; *MK4_VA(unsigned int, 0x541ec8u) = c24;
        }
        if (c13 == 1 && c24 == 3) {
            c24 = 2; *MK4_VA(unsigned int, 0x541ec8u) = c24;
        }
        if (c13 == 2 && c24 == 0) {
            c24 = 1; *MK4_VA(unsigned int, 0x541ec8u) = c24;
        }
        if (c13 == 2 && c24 == 2) {
            c24 = 3; *MK4_VA(unsigned int, 0x541ec8u) = c24;
        }
        if (c13 == 3 && c24 == 1) {
            c24 = 0; *MK4_VA(unsigned int, 0x541ec8u) = c24;
        }
        if (c13 == 3 && c24 == 3) {
            c24 = 2; *MK4_VA(unsigned int, 0x541ec8u) = c24;
        }
    } else {
        c24 = *MK4_VA(unsigned int, 0x541ec8u);
    }

    slot = g_eventQueueCurrent;
    if (slot == 0) {
        Helper_DownloadDebugPrint((const char *)MK4_PTR(0x4f058cu),
                                  (int)g_dlNalt1, (int)c13);
        c13 = *MK4_VA(unsigned int, 0x541ec4u);
        c24 = *MK4_VA(unsigned int, 0x541ec8u);
        slot = g_eventQueueCurrent;
    }
    if (slot == 1) {
        Helper_DownloadDebugPrint((const char *)MK4_PTR(0x4f0564u),
                                  (int)g_dlNalt2, (int)c24);
        c13 = *MK4_VA(unsigned int, 0x541ec4u);
        c24 = *MK4_VA(unsigned int, 0x541ec8u);
        slot = g_eventQueueCurrent;
    }
    if (slot == 2) {
        Helper_DownloadDebugPrint((const char *)MK4_PTR(0x4f053cu),
                                  (int)*MK4_VA(unsigned int, 0x53a178u),
                                  (int)c13);
        c13 = *MK4_VA(unsigned int, 0x541ec4u);
        c24 = *MK4_VA(unsigned int, 0x541ec8u);
        slot = g_eventQueueCurrent;
    }
    if (slot == 3) {
        Helper_DownloadDebugPrint((const char *)MK4_PTR(0x4f0514u),
                                  (int)*MK4_VA(unsigned int, 0x53a250u),
                                  (int)c24);
        c13 = *MK4_VA(unsigned int, 0x541ec4u);
        c24 = *MK4_VA(unsigned int, 0x541ec8u);
        slot = g_eventQueueCurrent;
    }

    variant = 0;
    flag = 0;
    if (slot == 0) {
        flag = *MK4_VA(unsigned int, 0x53a510u);
        variant = *MK4_VA(signed char,
                          0x4d5718u + c13 + g_dlNalt1 * 4u);
    }
    if (slot == 2) {
        flag = *MK4_VA(unsigned int, 0x53a510u);
        variant = *MK4_VA(signed char,
                          0x4d5718u + c13 + *MK4_VA(unsigned int, 0x53a178u) * 4u);
    }
    if (slot == 1) {
        flag = *MK4_VA(unsigned int, 0x52aafcu);
        variant = *MK4_VA(signed char,
                          0x4d5718u + c24 + g_dlNalt2 * 4u);
    }
    if (slot == 3) {
        flag = *MK4_VA(unsigned int, 0x52aafcu);
        variant = *MK4_VA(signed char,
                          0x4d5718u + c24 + *MK4_VA(unsigned int, 0x53a250u) * 4u);
    }

    g_matrixStackTop++;
    *MK4_NODE(unsigned int, g_matrixStackTop) = g_currentNodeIdx;
    Helper_DownloadSetup();
    if (g_framePauseFlag != 0) return;          /* bracket leaked */

    slot = g_eventQueueCurrent;
    node = g_currentNodeIdx;
    if (slot == 0) *MK4_VA(unsigned int, 0x541ed4u) = node;
    if (slot == 1) *MK4_VA(unsigned int, 0x541ed8u) = node;
    if (slot == 2) *MK4_VA(unsigned int, 0x541edcu) = node;
    if (slot == 3) *MK4_VA(unsigned int, 0x541ee0u) = node;

    if (flag == 0)
        g_currentNodeIdx = (unsigned int)
            ((int)MK4_NODE_AT(unsigned int,
                              MK4_NODE_AT(unsigned int, node, 0xc), 4) >> 2);
    else
        g_currentNodeIdx = (unsigned int)
            ((int)MK4_NODE_AT(unsigned int,
                              MK4_NODE_AT(unsigned int, node, 0x10), 4) >> 2);

    LoadGeoAsset_Textures(variant);

    g_currentNodeIdx = *MK4_NODE(unsigned int, g_matrixStackTop);
    g_matrixStackTop--;
}
#else
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
#endif
