/**
 * Per-frame "DOWNLOAD Player N" debug helper.
 *
 * Reads g_eventQueueCurrent (0..3) to pick which of the four players
 * to debug-print + reload. Prints a one-line "DOWNLOAD Player N
 * pN_char %d pN_nalt %d" via Helper_DownloadDebugPrint, then looks up
 * a per-character variant byte in g_dlVariantTable, saves the matrix-
 * stack state, calls Helper_DownloadSetup, and (if g_framePauseFlag
 * stayed clear) walks the geo-asset chain via LoadGeoAsset_Textures.
 */
#include "game/statemachine.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"
#include "engine/scenegraph.h"
#include "engine/geo.h"

static const char $SG_dl1[] = "DOWNLOAD Player 1 p1_char %d p1_nalt %d";
static const char $SG_dl2[] = "DOWNLOAD Player 2 p2_char %d p2_nalt %d";
static const char $SG_dl3[] = "DOWNLOAD Player 3 p3_char %d p1_nalt %d";
static const char $SG_dl4[] = "DOWNLOAD Player 4 p4_char %d p2_nalt %d";

/*
 * @addr 0x0048bff0
 *
 * Naked + __asm: 4-way fall-through dispatch on g_eventQueueCurrent
 * with each branch reloading eax from the global; a second pass uses
 * cmp + short-form jne to overwrite esi from the variant table when
 * the right case matches. The leading `push ecx` is the standard
 * MSVC alloca-4 idiom (the slot is read once via `mov esi, [esp+4]`
 * and otherwise serves as scratch).
 */
#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void __fastcall DownloadPlayerChar_Variant(int param_1)

{
  if (g_eventQueueCurrent == 0) {
    Helper_DownloadDebugPrint(MK4_VA(char, 0x004f058c),g_dlNalt1,g_dlChar13);
  }
  if (g_eventQueueCurrent == 1) {
    Helper_DownloadDebugPrint(MK4_VA(char, 0x004f0564),g_dlNalt2,g_dlChar24);
  }
  if (g_eventQueueCurrent == 2) {
    Helper_DownloadDebugPrint(MK4_VA(char, 0x004f053c),g_dlNalt3,g_dlChar13);
  }
  if (g_eventQueueCurrent == 3) {
    Helper_DownloadDebugPrint(MK4_VA(char, 0x004f0514),g_dlNalt4,g_dlChar24);
  }
  if (g_eventQueueCurrent == 0) {
    param_1 = (int)(char)(&g_dlVariantTable)[g_dlNalt1 * 4 + g_dlChar13];
  }
  if (g_eventQueueCurrent == 2) {
    param_1 = (int)(char)(&g_dlVariantTable)[g_dlNalt3 * 4 + g_dlChar13];
  }
  if (g_eventQueueCurrent == 1) {
    param_1 = (int)(char)(&g_dlVariantTable)[g_dlNalt2 * 4 + g_dlChar24];
  }
  if (g_eventQueueCurrent == 3) {
    param_1 = (int)(char)(&g_dlVariantTable)[g_dlNalt4 * 4 + g_dlChar24];
  }
  g_matrixStackTop = g_matrixStackTop + 1;
  *MK4_NODE(int, (int)g_matrixStackTop) = g_eventQueueCurrent;
  g_matrixStackTop = g_matrixStackTop + 1;
  *MK4_NODE(int, (int)g_matrixStackTop) = (g_currentNodeIdx);
  Helper_DownloadSetup();
  if (g_framePauseFlag == 0) {
    (g_currentNodeIdx) =
         MK4_NODE_AT(int, *(int *)(((uint)(g_eventQueueWorkType != 0) + (g_currentNodeIdx)) * 4 + 0xc), 4) >> 2;
    LoadGeoAsset_Textures(param_1);
    (g_currentNodeIdx) = *MK4_NODE(int, (int)g_matrixStackTop);
    g_eventQueueCurrent = *MK4_NODE(int, (int)(g_matrixStackTop + -1));
    g_matrixStackTop = g_matrixStackTop + -2;
  }
  return;
}
#else
__declspec(naked) void DownloadPlayerChar_Variant(void)
{
    __asm {
        push    ecx
        mov     eax, dword ptr [g_eventQueueCurrent]
        push    esi
        test    eax, eax
        jne     SHORT skip_p1
        mov     eax, dword ptr [g_dlChar13]
        mov     ecx, dword ptr [g_dlNalt1]
        push    eax
        push    ecx
        push    offset $SG_dl1
        call    Helper_DownloadDebugPrint
        mov     eax, dword ptr [g_eventQueueCurrent]
        add     esp, 0xc
skip_p1:
        cmp     eax, 1
        jne     SHORT skip_p2
        mov     edx, dword ptr [g_dlChar24]
        mov     eax, dword ptr [g_dlNalt2]
        push    edx
        push    eax
        push    offset $SG_dl2
        call    Helper_DownloadDebugPrint
        mov     eax, dword ptr [g_eventQueueCurrent]
        add     esp, 0xc
skip_p2:
        cmp     eax, 2
        jne     SHORT skip_p3
        mov     ecx, dword ptr [g_dlChar13]
        mov     edx, dword ptr [g_dlNalt3]
        push    ecx
        push    edx
        push    offset $SG_dl3
        call    Helper_DownloadDebugPrint
        mov     eax, dword ptr [g_eventQueueCurrent]
        add     esp, 0xc
skip_p3:
        cmp     eax, 3
        jne     SHORT skip_p4
        mov     eax, dword ptr [g_dlChar24]
        mov     ecx, dword ptr [g_dlNalt4]
        push    eax
        push    ecx
        push    offset $SG_dl4
        call    Helper_DownloadDebugPrint
        mov     eax, dword ptr [g_eventQueueCurrent]
        add     esp, 0xc
skip_p4:
        mov     ecx, dword ptr [g_dlChar13]
        test    eax, eax
        jne     SHORT use_default
        mov     edx, dword ptr [g_dlNalt1]
        movsx   esi, byte ptr [ecx + edx*4 + g_dlVariantTable]
        jmp     SHORT after_p0
use_default:
        mov     esi, dword ptr [esp + 4]
after_p0:
        cmp     eax, 2
        jne     SHORT after_p2
        mov     edx, dword ptr [g_dlNalt3]
        movsx   esi, byte ptr [ecx + edx*4 + g_dlVariantTable]
after_p2:
        mov     ecx, dword ptr [g_dlChar24]
        cmp     eax, 1
        jne     SHORT after_p1
        mov     edx, dword ptr [g_dlNalt2]
        movsx   esi, byte ptr [ecx + edx*4 + g_dlVariantTable]
after_p1:
        cmp     eax, 3
        jne     SHORT after_p3
        mov     edx, dword ptr [g_dlNalt4]
        movsx   esi, byte ptr [ecx + edx*4 + g_dlVariantTable]
after_p3:
        mov     ecx, dword ptr [g_matrixStackTop]
        inc     ecx
        mov     dword ptr [g_matrixStackTop], ecx
        mov     dword ptr [ecx*4], eax
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_currentNodeIdx]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4], ecx
        call    Helper_DownloadSetup
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        ; orig short-form jne (75 64); MASM picks long for this
        ; particular forward jcc, so _emit it.
        _emit   75h
        _emit   64h
        mov     ecx, dword ptr [g_eventQueueWorkType]
        xor     eax, eax
        test    ecx, ecx
        je      SHORT skip_set1
        mov     eax, 1
skip_set1:
        mov     edx, dword ptr [g_currentNodeIdx]
        push    esi
        add     eax, edx
        mov     eax, dword ptr [eax*4 + 0xc]
        mov     ecx, dword ptr [eax*4 + 4]
        sar     ecx, 2
        mov     dword ptr [g_currentNodeIdx], ecx
        call    LoadGeoAsset_Textures
        mov     eax, dword ptr [g_matrixStackTop]
        add     esp, 4
        mov     edx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_currentNodeIdx], edx
        mov     dword ptr [g_matrixStackTop], eax
        mov     ecx, dword ptr [eax*4]
        dec     eax
        mov     dword ptr [g_eventQueueCurrent], ecx
        mov     dword ptr [g_matrixStackTop], eax
exit:
        pop     esi
        pop     ecx
        ret
    }
}
#endif
