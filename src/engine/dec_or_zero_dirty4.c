/**
 * Auto-split from misc_matchesW.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern u32 g_eventQueueWorkType;
extern packed_ptr g_xformEntityIdx;

/* @addr 0x00438650 (58b): non-coaxable block-layout - keep hybrid __asm.
 *
 * Semantic: if `v = g_eventQueueChild` is OUT of [0, 0xf0], zero the
 * child and OR dirty bit 2; else decrement child and AND-clear bit 2.
 *
 *   mov     eax, [g_eventQueueChild]
 *   test    eax, eax
 *   jl      +7                     ; v < 0 -> close to ZERO block
 *   cmp     eax, 0xf0
 *   jle     +0x17                  ; v in [0, 0xf0] -> far to DEC block
 *   ; fall-through (v > 0xf0) into ZERO block:
 *   mov     eax, [g_xformDirtyFlags]
 *   mov     [g_eventQueueChild], 0
 *   or      al, 4
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 *   dec     eax                    ; DEC block (jle target)
 *   mov     [g_eventQueueChild], eax
 *   mov     eax, [g_xformDirtyFlags]
 *   and     al, 0xfb
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 *
 * Why hybrid: orig has the OR-condition's "if-body" (ZERO) at the
 * fall-through position and the "else-body" (DEC) as the far jump
 * target. MSVC SP3 with /O2 has a categorical heuristic that does
 * the OPPOSITE for OR/AND conditions: it puts the conditional-jump
 * target body SECOND (far) and the fall-through body FIRST (close).
 * Tried (all diverge 30-50 bytes):
 *   - `if (v < 0 || v > 0xf0) ZERO else DEC`  -> DEC first
 *   - `if (v >= 0 && v <= 0xf0) DEC else ZERO` -> DEC first
 *   - `if (v < 0) goto zero; if (v <= 0xf0) goto dec; zero: ...`
 *     -> MSVC merges OR-conditions and reorders -> DEC first
 *   - Duplicated ZERO bodies (two-if + default) -> MSVC tail-merges
 *     AND pre-zeroes ecx (xor ecx, ecx; mov [m], ecx -- 6b instead
 *     of c7 05 + imm32 -- 10b), changing the byte sequence further
 *
 * The orig was likely compiled with a slightly different MSVC 5.0
 * version (RTM/SP1/SP2) that picked the opposite block-layout heuristic
 * for OR. Disabling /O2 via `#pragma optimize("", off)` adds a full
 * debug-mode prologue which breaks everything else. Keep naked.
 */
void DecOrZeroDirty4_00438650(void) {
    __asm {
        mov     eax, dword ptr [g_eventQueueChild]
        test    eax, eax
        _emit   7ch
        _emit   07h
        cmp     eax, 0xf0
        _emit   7eh
        _emit   17h
        mov     eax, dword ptr [g_xformDirtyFlags]
        mov     dword ptr [g_eventQueueChild], 0
        or      al, 4
        mov     dword ptr [g_xformDirtyFlags], eax
        ret
        dec     eax
        mov     dword ptr [g_eventQueueChild], eax
        mov     eax, dword ptr [g_xformDirtyFlags]
        and     al, 0xfb
        mov     dword ptr [g_xformDirtyFlags], eax
        }
}
