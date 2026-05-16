/**
 * 2 "state install + tail-jmp or forward" helpers (33 bytes each).
 *
 * Pattern:
 *   mov     eax, [g_state]
 *   test    eax, eax
 *   mov     [g_walkCallback], eax
 *   jne     .forward
 *   jmp     T_default
 * .forward:
 *   mov     eax, [esp+4]
 *   push    eax
 *   call    T_forward
 *   add     esp, 4
 *   ret
 */
#include "engine/scenegraph.h"

extern unsigned int g_active_0053a408;
extern unsigned int g_active_00537e88;

extern void CallSetPause_0041f830(void);
extern void ArgSarAddDerefJmp_0048e710(int);

/* @addr 0x0048e6b0 */
void StateInstallOrForward_0048e6b0(int arg) {
    unsigned int v = g_active_0053a408;
    g_walkCallback = (void (*)(void))v;
    if (v == 0) {
        CallSetPause_0041f830();
        return;
    }
    ArgSarAddDerefJmp_0048e710(arg);
}

/* @addr 0x0048e6e0 */
void StateInstallOrForward_0048e6e0(int arg) {
    unsigned int v = g_active_00537e88;
    g_walkCallback = (void (*)(void))v;
    if (v == 0) {
        CallSetPause_0041f830();
        return;
    }
    ArgSarAddDerefJmp_0048e710(arg);
}
