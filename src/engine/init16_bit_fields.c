/**
 * Auto-split from misc_matchesA.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004bcc50 (24b)
 *   xor     eax, eax
 *   mov     word ptr [0x00ab47fc], 0x1000
 *   mov     word ptr [0x00ab47f8], ax
 *   mov     word ptr [0x00ab47fa], ax
 *   ret
 */
extern unsigned short g_word_00ab47fc;
extern unsigned short g_word_00ab47f8;
extern unsigned short g_word_00ab47fa;
void Init16BitFields_004bcc50(void) {
    g_word_00ab47fc = 0x1000;
    g_word_00ab47f8 = 0;
    g_word_00ab47fa = 0;
}
