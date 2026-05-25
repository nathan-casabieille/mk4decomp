/**
 * Auto-split from misc_matchesHH.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004cde40 (57b)
 *   pack a double from 3 dword args: high/low 32 bits + biased exponent.
 *   builds the 16-bit sign+exponent word at [esp+6], then fld it.
 */
void PackDoubleFromInts_004cde40(void) {
    __asm {
        sub     esp, 8
        mov     eax, dword ptr [esp + 0x0c]
        mov     ecx, dword ptr [esp + 0x10]
        mov     edx, dword ptr [esp + 0x14]
        _emit   89h     /* mov [esp + 0], eax (force disp8 form) */
        _emit   44h
        _emit   24h
        _emit   00h
        mov     dword ptr [esp + 4], ecx
        mov     ecx, dword ptr [esp + 0x12]
        lea     eax, [edx + 0x3fe]
        and     ecx, 0x800f
        shl     eax, 4
        or      ecx, eax
        mov     word  ptr [esp + 6], cx
        _emit   0ddh    /* fld qword [esp + 0] (force disp8 form) */
        _emit   44h
        _emit   24h
        _emit   00h
        add     esp, 8
        }
}
