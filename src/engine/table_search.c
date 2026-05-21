/**
 * Auto-split from misc_matchesQ.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004be760 (46b)
 *   mov     ax, word ptr [esp+4]
 *   cmp     ax, 0x64
 *   jge     +0x20
 *   movsx   edx, ax
 *   xor     ecx, ecx
 *   mov     eax, 0x004f7d40
 * .loop:
 *   cmp     [eax], edx
 *   je      .found
 *   add     eax, 4
 *   inc     ecx
 *   cmp     eax, 0x004f7d80
 *   jl      .loop
 *   xor     eax, eax
 *   ret
 * .found:
 *   lea     eax, [ecx + 2]
 *   ret
 *   xor     eax, eax
 *   ret
 */
extern int g_table_004f7d40[16];
void TableSearch_004be760(void) {
    __asm {
        mov     ax, word ptr [esp + 4]
        cmp     ax, 0x64
        _emit   7dh
        _emit   20h
        movsx   edx, ax
        xor     ecx, ecx
        mov     eax, 0x004f7d40
        cmp     edx, dword ptr [eax]
        _emit   74h
        _emit   0eh
        add     eax, 4
        inc     ecx
        cmp     eax, 0x004f7d80
        _emit   7ch
        _emit   0f1h
        xor     eax, eax
        ret
        lea     eax, [ecx + 2]
        ret
        xor     eax, eax
        }
}
