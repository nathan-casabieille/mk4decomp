/**
 * Auto-split from misc_matchesE.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0041f840 (38b)
 *   mov     eax, [g_baseSel]
 *   mov     ecx, [eax*4 + 0xd8]
 *   test    ecx, ecx
 *   je      .skip
 *   mov     [eax*4 + 0xd8], -1
 *   mov     [g_framePauseFlag], 1
 * .skip:
 *   ret
 */
void ScaledNeg1SetPause_0041f840(void) {
    ScenegraphNode *node = (ScenegraphNode *)(g_baseSel_00542060 * 4);
    if (node->ptr_field != 0) {
        node->ptr_field = 0xffffffff;
        g_framePauseFlag = 1;
    }
}
