/**
 * Auto-split from misc_matchesO.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004362b0 (49b)
 *   call    F
 *   test    eax, eax
 *   jne     +0x27
 *   mov     eax, [g_table_00535ddc]
 *   cmp     eax, 0x00030000
 *   mov     [g_walkCallback], eax
 *   jle     +5
 *   jmp     T1
 *   cmp     eax, 0x00018000
 *   jge     +5
 *   jmp     +0x15
 *   jmp     T2
 *   ret
 */
extern unsigned int g_table_00535ddc;
extern int Cmp2CallDirtyCall_004398b0(void);
extern void GuardedSeq_00433bb0(void);
extern void Mul10ThresholdQuad_00435f50(void);
extern void TripleThresholdDispatch_004362f0(void);
void Cmp30000And18000_004362b0(void) {
    unsigned int v;
    if (Cmp2CallDirtyCall_004398b0() != 0) return;
    v = g_table_00535ddc;
    g_walkCallback = (void (*)(void))v;
    if ((int)v > 0x30000) {
        GuardedSeq_00433bb0();
        return;
    }
    if ((int)v < 0x18000) {
        TripleThresholdDispatch_004362f0();
        return;
    }
    Mul10ThresholdQuad_00435f50();
}
