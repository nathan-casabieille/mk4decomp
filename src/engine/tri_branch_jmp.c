/**
 * Auto-split from misc_matchesG.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00434530 (34b)
 *   mov     eax, [g_counter_0053a51c]
 *   cmp     eax, 8
 *   mov     [g_walkCallback], eax
 *   jne     +5
 *   jmp     T1
 *   test    eax, eax
 *   jne     +5
 *   jmp     T2
 *   jmp     +0x0e
 */
extern unsigned int g_counter_0053a51c;
extern void InstallSelfStatePush_00434990(void);
extern void InstallSelfStatePush_004348f0(void);
extern void FlagInitTableSelector_00434560(void);
void TriBranchJmp_00434530(void) {
    unsigned int v = g_counter_0053a51c;
    g_walkCallback = (void (*)(void))v;
    if (v == 8) {
        InstallSelfStatePush_00434990();
        return;
    }
    if (v == 0) {
        InstallSelfStatePush_004348f0();
        return;
    }
    FlagInitTableSelector_00434560();
}
