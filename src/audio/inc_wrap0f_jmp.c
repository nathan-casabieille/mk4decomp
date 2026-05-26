/**
 * Auto-split from misc_matchesL.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004a1120 (36b)
 *   mov     eax, [g_walkCallback]
 *   inc     eax
 *   cmp     eax, 0x0f
 *   mov     [g_walkCallback], eax
 *   ja      +5
 *   jmp     T
 *   mov     [g_walkCallback], 1
 *   jmp     T2
 */
extern void AudioPhaseDispatch_004a1150(void);
extern void AudioPhaseDispatch_004a1150(void);
void IncWrap0fJmp_004a1120(void) {
    unsigned int v = (unsigned int)g_walkCallback + 1;
    g_walkCallback = (void (*)(void))v;
    if (v <= 0x0f) {
        AudioPhaseDispatch_004a1150();
        return;
    }
    g_walkCallback = (void (*)(void))1;
    AudioPhaseDispatch_004a1150();
}
