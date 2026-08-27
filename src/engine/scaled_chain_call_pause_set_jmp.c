/**
 * Auto-split from misc_matchesP.c
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
#endif


/* @addr 0x0048f8e0 (48b)
 *   mov     eax, [g_baseSel]
 *   mov     ecx, [eax*4 + 0x3c]
 *   mov     [g_currentNodeIdx], ecx
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +0x0f
 *   mov     [g_currentNodeIdx], 0x0048fa20
 *   jmp     T
 *   ret
 */
extern void Thunk_ChainNodeInit(void);
extern void MStackPush4IndirectCall(void);
void ScaledChainCallPauseSetJmp(void) {
    g_currentNodeIdx = ((ScenegraphNode *)MK4_PTR((g_baseSel * 4)))->child_a;
    Thunk_ChainNodeInit();
    if (g_framePauseFlag != 0) return;
    g_currentNodeIdx = 0x0048fa20;
    MStackPush4IndirectCall();
}
