/**
 * Auto-split from misc_matchesP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00487150 (46b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     eax, [eax*4 + 0x30]
 *   test    eax, eax
 *   mov     [g_walkCallback], eax
 *   jne     +5
 *   jmp     T1
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +5
 *   jmp     T2
 *   ret
 */
extern void RoundResultSlotInitTable_00486860(void);
extern void Wrapper_0048a340(void);
extern void GuardedSeq_004871b0(void);
void ScaledTestCallPauseJmpFar_00487150(void) {
    unsigned int v = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x30);
    g_walkCallback = (void (*)(void))v;
    if (v == 0) {
        GuardedSeq_004871b0();
        return;
    }
    RoundResultSlotInitTable_00486860();
    if (g_framePauseFlag != 0) return;
    Wrapper_0048a340();
}
