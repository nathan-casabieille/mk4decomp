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

extern unsigned int g_chainAccumA;
extern unsigned int g_chainAccumB;
extern unsigned int g_chainAccumCur;

extern void MStackPush3TripleMul10WithAbs(void);

/* @addr 0x0048b480 */
void CallPauseAddDualStore_0048b480(void) {
    unsigned int v;
    MStackPush3TripleMul10WithAbs();
    if (g_framePauseFlag) return;
    v = g_chainAccumA + (unsigned int)g_walkCallback;
    g_chainAccumCur = v;
    g_chainAccumA = v;
}

/* @addr 0x0048b4b0 */
void CallPauseAddDualStore_0048b4b0(void) {
    unsigned int v;
    MStackPush3TripleMul10WithAbs();
    if (g_framePauseFlag) return;
    v = g_chainAccumB + (unsigned int)g_walkCallback;
    g_chainAccumCur = v;
    g_chainAccumB = v;
}
