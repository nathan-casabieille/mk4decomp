/**
 * Auto-split from misc_matchesP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0045fa90 (46b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     [g_walkCallback], 0
 *   mov     [eax*4 + 0x28], 0
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +5
 *   jmp     +3
 *   ret
 */
extern void func_004611c0(void);
extern void func_0045faec(void);
void ZeroScaledZeroCallPauseJmp_0045fa90(void) {
    g_walkCallback = (void (*)(void))0;
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_idx = 0;
    func_004611c0();
    if (g_framePauseFlag != 0) return;
    func_0045faec();
}
