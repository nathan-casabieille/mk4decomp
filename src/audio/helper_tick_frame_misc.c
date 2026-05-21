/**
 * Auto-extracted during misc_matches reorganization.
 */
#include "engine/scenegraph.h"

/* @addr 0x004a1d50 (48b)
 *   8-iteration loop reading triplets from [0x004f2fd4 - 4 ..],
 *   writing AND-NOT result into [src1] and replacing [src2] with NOT(src1).
 */
extern unsigned int g_table_004f2fd4[];
void Helper_TickFrame_Misc(void) {
    __asm {
        mov     ecx, OFFSET g_table_004f2fd4
        mov     esi, 8
loop_start:
        mov     eax, dword ptr [ecx - 4]
        mov     edx, dword ptr [ecx + 4]
        add     ecx, 0x0c
        mov     eax, dword ptr [eax]
        mov     edi, dword ptr [edx]
        not     eax
        not     edi
        mov     ebx, eax
        and     ebx, edi
        mov     edi, dword ptr [ecx - 0x0c]
        dec     esi
        mov     dword ptr [edi], ebx
        mov     dword ptr [edx], eax
        _emit   75h
        _emit   0e1h
        }
}

