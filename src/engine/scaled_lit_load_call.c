/**
 * 2 "literal-base + scaled load + call + tail-jmp" helpers (53b).
 *
 * Pattern:
 *   mov     ecx, [g_walkCallback]
 *   mov     eax, LITERAL_PTR
 *   shr     eax, 2                          ; pack to scaled form
 *   add     eax, ecx                        ; offset by walkCallback
 *   mov     [g_currentNodeIdx], eax
 *   mov     eax, [eax*4 + 0]                ; deref via SIB+0
 *   mov     [g_xformEntityIdx], eax
 *   call    Func
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   jmp     Tail
 * .ret:
 *   ret
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_currentNodeIdx;
extern unsigned int g_xformEntityIdx;
#endif

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern void *g_litScaledArg4d;
extern void *g_litScaledArgd8;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_litScaledArg4d (*(unsigned int *)MK4_VA(unsigned int, 0x4ef4d0u))
#define g_litScaledArgd8 (*(unsigned int *)MK4_VA(unsigned int, 0x4ef7d8u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#endif

extern void ScaledChainCallPauseSetJmp(void);
extern void Wrapper_IterLoad_0048fd30_004ed980(void);

/* @addr 0x00480fe0 */
void ScaledLitLoadCall_ScaledChainCallPauseSetJmp_then_Wrapper_IterLoad_0048fd30_00480fe0(void) {
    unsigned int idx = ((unsigned int)MK4_UNPTR(&g_litScaledArg4d) >> 2) + (unsigned int)g_walkCallback;
    g_currentNodeIdx = idx;
    g_xformEntityIdx = *(unsigned int*)(idx * 4);
    ScaledChainCallPauseSetJmp();
    if (g_framePauseFlag) return;
    Wrapper_IterLoad_0048fd30_004ed980();
}

/* @addr 0x00481020 */
void ScaledLitLoadCall_ScaledChainCallPauseSetJmp_then_Wrapper_IterLoad_0048fd30_00481020(void) {
    unsigned int idx = ((unsigned int)MK4_UNPTR(&g_litScaledArgd8) >> 2) + (unsigned int)g_walkCallback;
    g_currentNodeIdx = idx;
    g_xformEntityIdx = *(unsigned int*)(idx * 4);
    ScaledChainCallPauseSetJmp();
    if (g_framePauseFlag) return;
    Wrapper_IterLoad_0048fd30_004ed980();
}
