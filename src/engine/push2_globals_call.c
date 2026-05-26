/**
 * Auto-split from misc_matchesA.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004bdae0 (22b)
 *   mov     eax, [g_scaledInit_00542044]
 *   mov     ecx, [g_pendingNodeType]
 *   push    eax
 *   push    ecx
 *   call    F
 *   add     esp, 8
 *   ret
 */
extern int __cdecl MatrixTransform3x3Q12_004b3b80(unsigned int, unsigned int);
void Push2GlobalsCall_004bdae0(void) {
    MatrixTransform3x3Q12_004b3b80(g_pendingNodeType, g_scaledInit_00542044);
}
