/**
 * Auto-split from misc_matchesQ.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004c4210 (37b)
 *   push    esi
 *   push    edi
 *   xor     esi, esi
 *   mov     edi, 0x00f8fade
 * .loop:
 *   test    byte ptr [edi], 4
 *   jne     .skip
 *   push    esi
 *   call    F
 *   add     esp, 4
 * .skip:
 *   inc     esi
 *   add     edi, 0x1c
 *   cmp     si, 0x0898
 *   jl      .loop
 *   pop     edi
 *   pop     esi
 *   ret
 */
extern int Helper_AudioStop(int);
void IterateCallSkip_004c4210(void) {
    int i = 0;
    unsigned char *p = (unsigned char *)0x00f8fade;
    do {
        if ((*p & 4) == 0) {
            Helper_AudioStop(i);
        }
        i++;
        p += 0x1c;
    } while ((short)i < 0x0898);
}
