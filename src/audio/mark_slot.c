/**
 * Auto-split from misc_matchesM.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004ab270 (34b)
 *   mov     ecx, [esp+4]
 *   push    esi
 *   xor     eax, eax
 *   mov     dl, 1
 * .loop:
 *   movsx   esi, byte ptr [eax + 0x004f3ac8]
 *   cmp     esi, ecx
 *   jne     .skip
 *   mov     [eax + 0x004f3ac8], dl
 * .skip:
 *   inc     eax
 *   cmp     eax, 0x10
 *   jl      .loop
 *   pop     esi
 *   ret
 */
extern char g_table_004f3ac8[16];
void MarkSlot_004ab270(int arg) {
    int i;
    for (i = 0; i < 16; i++) {
        if (arg == (int)(signed char)g_table_004f3ac8[i]) {
            g_table_004f3ac8[i] = 1;
        }
    }
}
