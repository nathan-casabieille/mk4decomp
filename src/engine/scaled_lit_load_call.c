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

extern unsigned int g_currentNodeIdx;
extern unsigned int g_xformEntityIdx;

extern void *g_lit_004ef4d0;
extern void *g_lit_004ef7d8;
extern void ScaledChainCallPauseSetJmp(void);
extern void Wrapper_IterLoad_0048fd30_004ed980(void);

/* @addr 0x00480fe0 */
void ScaledLitLoadCall_ScaledChainCallPauseSetJmp_then_Wrapper_IterLoad_0048fd30_00480fe0(void) {
    unsigned int idx = ((unsigned int)&g_lit_004ef4d0 >> 2) + (unsigned int)g_walkCallback;
    g_currentNodeIdx = idx;
    g_xformEntityIdx = *(unsigned int*)(idx * 4);
    ScaledChainCallPauseSetJmp();
    if (g_framePauseFlag) return;
    Wrapper_IterLoad_0048fd30_004ed980();
}

/* @addr 0x00481020 */
void ScaledLitLoadCall_ScaledChainCallPauseSetJmp_then_Wrapper_IterLoad_0048fd30_00481020(void) {
    unsigned int idx = ((unsigned int)&g_lit_004ef7d8 >> 2) + (unsigned int)g_walkCallback;
    g_currentNodeIdx = idx;
    g_xformEntityIdx = *(unsigned int*)(idx * 4);
    ScaledChainCallPauseSetJmp();
    if (g_framePauseFlag) return;
    Wrapper_IterLoad_0048fd30_004ed980();
}
