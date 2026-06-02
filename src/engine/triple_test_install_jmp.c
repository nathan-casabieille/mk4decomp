/**
 * 2 "triple test+install with three jmp targets" helpers (83b).
 *
 * Pattern:
 *   mov     eax, [g_eventQueueEnd]
 *   mov     [g_eventQueueWorkType], eax
 *   mov     [g_acc_00542078], eax
 *   call    Func
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, [g_dlMode]
 *   test    eax, eax
 *   mov     [g_walkCallback], eax
 *   jne     .skip1
 *   jmp     T1
 * .skip1:
 *   mov     eax, [g_state2]                  ; per-helper
 *   test    eax, eax
 *   mov     [g_walkCallback], eax
 *   jne     .skip2
 *   jmp     T2
 * .skip2:
 *   mov     eax, [g_acc_00542078]
 *   mov     [g_finalDest], eax               ; per-helper
 *   jmp     T3
 * .ret:
 *   ret
 */
#include "engine/scenegraph.h"
#include "game/tick.h"
#include "game/statemachine.h"

extern unsigned int g_acc_00542078;
extern unsigned int g_state2_0053a1bc;
extern unsigned int g_state2_0053a354;
extern unsigned int g_finalDest_0053a178;
extern unsigned int g_finalDest_0053a250;

extern void AudioVoiceSequencerCluster(void);
extern void AudioStateRemap(void);
extern void AudioInstallSelfShiftedChainInit(void);
extern void AudioStateRemapB(void);
extern void AudioInstallSelfChannel8(void);

/* @addr 0x004a0130 */
void TripleTestInstallJmp_004a0130(void) {
    unsigned int v;
    v = g_eventQueueEnd;
    g_eventQueueWorkType = v;
    g_acc_00542078 = v;
    AudioVoiceSequencerCluster();
    if (g_framePauseFlag) return;
    v = g_dlMode;
    g_walkCallback = (void(*)(void))v;
    if (!v) {
        AudioStateRemap();
        return;
    }
    v = g_state2_0053a1bc;
    g_walkCallback = (void(*)(void))v;
    if (!v) {
        AudioStateRemap();
        return;
    }
    g_finalDest_0053a178 = g_acc_00542078;
    AudioInstallSelfShiftedChainInit();
}

/* @addr 0x004a0440 */
void TripleTestInstallJmp_004a0440(void) {
    unsigned int v;
    v = g_eventQueueEnd;
    g_eventQueueWorkType = v;
    g_acc_00542078 = v;
    AudioVoiceSequencerCluster();
    if (g_framePauseFlag) return;
    v = g_dlMode;
    g_walkCallback = (void(*)(void))v;
    if (!v) {
        AudioStateRemapB();
        return;
    }
    v = g_state2_0053a354;
    g_walkCallback = (void(*)(void))v;
    if (!v) {
        AudioStateRemapB();
        return;
    }
    g_finalDest_0053a250 = g_acc_00542078;
    AudioInstallSelfChannel8();
}
