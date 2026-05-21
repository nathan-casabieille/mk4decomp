/**
 * Auto-split from misc_matchesA.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004c4370 (22b)
 *   push    esi
 *   xor     esi, esi
 * .loop:
 *   push    esi
 *   push    -1
 *   call    F
 *   add     esp, 8
 *   inc     esi
 *   cmp     esi, 0x10
 *   jl      .loop
 *   pop     esi
 *   ret
 */
extern int Snd3DSourceCleanupFiltered_004c3be0(int, int);
void Loop16Init_004c4370(void) {
    int i;
    for (i = 0; i < 16; i++) {
        Snd3DSourceCleanupFiltered_004c3be0(-1, i);
    }
}
