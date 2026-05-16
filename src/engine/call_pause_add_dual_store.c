/**
 * 2 "call + pause guard + add into dual store" helpers (38b).
 *
 * Pattern:
 *   call    Func
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, [g_X]
 *   mov     ecx, [g_walkCallback]
 *   add     eax, ecx
 *   mov     [g_Y], eax
 *   mov     [g_X], eax
 * .ret:
 *   ret
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_acc_0053a438;
extern unsigned int g_acc_0053a440;
extern unsigned int g_acc_00542078;

extern void MStackPush3TripleMul10WithAbs_0048b500(void);

/* @addr 0x0048b480 */
void CallPauseAddDualStore_0048b480(void) {
    unsigned int v;
    MStackPush3TripleMul10WithAbs_0048b500();
    if (g_framePauseFlag) return;
    v = g_acc_0053a438 + (unsigned int)g_walkCallback;
    g_acc_00542078 = v;
    g_acc_0053a438 = v;
}

/* @addr 0x0048b4b0 */
void CallPauseAddDualStore_0048b4b0(void) {
    unsigned int v;
    MStackPush3TripleMul10WithAbs_0048b500();
    if (g_framePauseFlag) return;
    v = g_acc_0053a440 + (unsigned int)g_walkCallback;
    g_acc_00542078 = v;
    g_acc_0053a440 = v;
}
