/**
 * Auto-split from misc_matchesA.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

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
extern int Snd3DSourceCleanupFiltered(int, int);
void Loop16Init(void) {
    int i;
    for (i = 0; i < 16; i++) {
        Snd3DSourceCleanupFiltered(-1, i);
    }
}
