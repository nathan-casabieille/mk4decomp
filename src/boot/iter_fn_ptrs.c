/**
 * Auto-split from misc_matchesR.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004c6940 (32b)
 *   push    esi
 *   mov     esi, [esp+8]
 *   push    edi
 *   mov     edi, [esp+0x10]
 *   cmp     esi, edi
 *   jae     .ret
 * .loop:
 *   mov     eax, [esi]
 *   test    eax, eax
 *   je      .skip
 *   call    eax
 * .skip:
 *   add     esi, 4
 *   cmp     esi, edi
 *   jb      .loop
 * .ret:
 *   pop     edi
 *   pop     esi
 *   ret
 */
void IterFnPtrs_004c6940(void (**start)(void), void (**end)(void)) {
    while (start < end) {
        void (*f)(void) = *start;
        if (f != 0) f();
        start++;
    }
}
