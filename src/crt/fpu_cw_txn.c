/**
 * Auto-split from misc_matchesGG.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004cc4c0 (59b)
 *   FPU control word transactional update via two helpers (4cc520, 4cc5c0).
 *   Reads cw, computes new value, then sets new cw and returns the masked old value.
 */
extern int DecodeModeFlags(int);
extern int EncodeModeFlags(int);
__declspec(naked) void FpuCwTxn(void) {
    __asm {
        push    ebp
        mov     ebp, esp
        push    ecx
        push    esi
        fstcw   word ptr [ebp - 4]
        mov     eax, dword ptr [ebp - 4]
        push    eax
        call    DecodeModeFlags
        mov     ecx, dword ptr [ebp + 0x0c]
        mov     edx, dword ptr [ebp + 8]
        mov     esi, ecx
        add     esp, 4
        not     ecx
        and     esi, edx
        and     ecx, eax
        or      esi, ecx
        push    esi
        call    EncodeModeFlags
        add     esp, 4
        mov     dword ptr [ebp + 0x0c], eax
        fldcw   word ptr [ebp + 0x0c]
        mov     eax, esi
        pop     esi
        mov     esp, ebp
        pop     ebp
        ret
    }
}
