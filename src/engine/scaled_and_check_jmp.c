/**
 * Auto-split from misc_matchesI.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00470f60 (35b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     eax, [eax*4 + 0x40]
 *   mov     [g_walkCallback], eax
 *   and     eax, 0x200
 *   mov     [g_xformScratch94], eax
 *   je      .skip
 *   jmp     T
 * .skip:
 *   ret
 */
extern unsigned int g_xformScratch94;
extern void func_00490374(void);
void ScaledAndCheckJmp_00470f60(void) {
    unsigned int v = ((FightGroupNode *)(g_fightGroupHead * 4))->bits;
    unsigned int masked;
    g_walkCallback = (void (*)(void))v;
    masked = v & 0x200;
    g_xformScratch94 = masked;
    if (masked == 0) return;
    func_00490374();
}
