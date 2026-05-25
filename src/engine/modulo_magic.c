/**
 * Auto-split from misc_matchesFF.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0042afc0 (64b)
 *   modulo using 32x32->64 magic-number division: ecx %= 0x6487e (range modulus).
 *   Bound-clamps and adds offsets via g_state_004d5320..00d4d532c.
 */
extern unsigned int g_state_004d5320;
extern unsigned int g_state_004d5324;
extern unsigned int g_state_004d532c;
__declspec(naked) void ModuloMagic_0042afc0(void) {
    __asm {
        mov     ecx, dword ptr [esp + 4]
        mov     eax, dword ptr [g_state_004d5320]
        cmp     ecx, eax
        _emit   7eh
        _emit   0ch
        mov     edx, dword ptr [g_state_004d5324]
sub_loop:
        sub     ecx, edx
        cmp     ecx, eax
        _emit   7fh
        _emit   0fah
        mov     edx, dword ptr [g_state_004d532c]
        cmp     ecx, edx
        _emit   7fh
        _emit   1ah
        sub     edx, ecx
        mov     eax, 0xa2f99905
        add     edx, 0x6487e
        mul     edx
        shr     edx, 0x12
        imul    edx, edx, 0x6487e
        add     ecx, edx
        mov     eax, ecx
        ret
    }
}
