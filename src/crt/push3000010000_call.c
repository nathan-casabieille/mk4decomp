/**
 * Auto-split from misc_matchesA.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004c83e0 (19b)
 *   push    0x00030000
 *   push    0x00010000
 *   call    F
 *   add     esp, 8
 *   ret
 */
extern int __cdecl MaskCall_004cc500(int, int);
void Push3000010000Call_004c83e0(void) {
    MaskCall_004cc500(0x10000, 0x30000);
}
