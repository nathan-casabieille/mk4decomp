/**
 * Auto-split from misc_matchesB.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x004cca30 (29b): linear search a 4-stride array
 *   mov     ecx, [esp+4]
 *   xor     eax, eax
 * .loop:
 *   cmp     dword ptr [ecx], 0
 *   jne     .found
 *   inc     eax
 *   add     ecx, 4
 *   cmp     eax, 3
 *   jl      .loop
 *   mov     eax, 1
 *   ret
 * .found:
 *   xor     eax, eax
 *   ret
 */
int LinearSearchArray_004cca30(const int *arr) {
    int i;
    for (i = 0; i < 3; i++) {
        if (arr[i] != 0) {
            return 0;
        }
    }
    return 1;
}
