/**
 * Auto-split from misc_matchesH.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformDirtyFlags (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#endif


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
extern void SetJmp_StateDispatchYield_00438f60(void);
extern void StateDispatchYield(void);
void CallPauseDirtyConstJmp(void) {
    MStackPush3CmpCall();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 1) {
        SetJmp_StateDispatchYield_00438f60();
        return;
    }
    g_walkCallback = (void(*)(void))0x0c;
    StateDispatchYield();
}
