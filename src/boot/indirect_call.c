/**
 * Auto-split from misc_matchesR.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004c6ec0 (32b)
 *   mov     eax, [0x00f9f854]
 *   test    eax, eax
 *   je      .skip
 *   mov     ecx, [esp+4]
 *   push    ecx
 *   call    eax
 *   add     esp, 4
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, 1
 *   ret
 * .ret:
 *   xor     eax, eax
 *   ret
 */
extern int (*g_dispatchSave1431_00f9f854)(int);
int IndirectCall_004c6ec0(int arg) {
    if (g_dispatchSave1431_00f9f854 != 0 && g_dispatchSave1431_00f9f854(arg) != 0) {
        return 1;
    }
    return 0;
}
