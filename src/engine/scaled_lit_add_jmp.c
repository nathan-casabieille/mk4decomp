/**
 * Auto-split from misc_matchesJ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00480fb0 (38b)
 *   mov     ecx, [g_walkCallback]
 *   mov     eax, 0x004ef4d0
 *   shr     eax, 2
 *   add     eax, ecx
 *   mov     [g_scaledInit_00542044], eax
 *   mov     eax, [eax*4 + 0]
 *   mov     [g_xformEntityIdx], eax
 *   jmp     T
 */
extern void func_0048f8be(void);
extern int g_dispatchSave1315_004ef4d0;
void ScaledLitAddJmp_00480fb0(void) {
    unsigned int v = (((unsigned int)&g_dispatchSave1315_004ef4d0) >> 2) + (unsigned int)g_walkCallback;
    g_scaledInit_00542044 = v;
    g_xformEntityIdx = *(unsigned int *)(v * 4);
    func_0048f8be();
}
