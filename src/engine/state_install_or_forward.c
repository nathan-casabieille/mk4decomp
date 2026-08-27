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

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_active_0053a408;
extern unsigned int g_active_00537e88;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_active_00537e88 (*(unsigned int *)MK4_VA(unsigned int, 0x537e88u))
#define g_active_0053a408 (*(unsigned int *)MK4_VA(unsigned int, 0x53a408u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif


extern void CallSetPause(void);
extern void ArgSarAddDerefJmp(int);

/* @addr 0x0048e6b0 */
void StateInstallOrForward_0048e6b0(int arg) {
    unsigned int v = g_active_0053a408;
#ifdef NON_MATCHING
    g_walkCallback = v;          /* aliased as a plain u32 slot under the arena */
#else
    g_walkCallback = (void (*)(void))v;
#endif
    if (v == 0) {
        CallSetPause();
        return;
    }
    ArgSarAddDerefJmp(arg);
}

/* @addr 0x0048e6e0 */
void StateInstallOrForward_0048e6e0(int arg) {
    unsigned int v = g_active_00537e88;
#ifdef NON_MATCHING
    g_walkCallback = v;          /* aliased as a plain u32 slot under the arena */
#else
    g_walkCallback = (void (*)(void))v;
#endif
    if (v == 0) {
        CallSetPause();
        return;
    }
    ArgSarAddDerefJmp(arg);
}
