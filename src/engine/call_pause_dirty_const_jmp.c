/**
 * Auto-split from misc_matchesH.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00438ca0 (44b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   test    byte [g_xformDirtyFlags], 1
 *   je      +5
 *   jmp     +0x2a4
 *   mov     [g_walkCallback], 0x0c
 *   jmp     +0x384c5
 *   ret
 */
extern void MStackPush3CmpCall(void);
extern void SetJmp_00438f60(void);
extern void StateDispatchYield(void);
void CallPauseDirtyConstJmp(void) {
    MStackPush3CmpCall();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 1) {
        SetJmp_00438f60();
        return;
    }
    g_walkCallback = (void(*)(void))0x0c;
    StateDispatchYield();
}
