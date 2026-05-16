/**
 * 2 "literal-base + scaled load + call + tail-jmp" helpers (53b).
 *
 * Pattern:
 *   mov     ecx, [g_walkCallback]
 *   mov     eax, LITERAL_PTR
 *   shr     eax, 2                          ; pack to scaled form
 *   add     eax, ecx                        ; offset by walkCallback
 *   mov     [g_scaledInit_00542044], eax
 *   mov     eax, [eax*4 + 0]                ; deref via SIB+0
 *   mov     [g_scaledInit_00542048], eax
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

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_scaledInit_00542048;

extern void *g_lit_004ef4d0;
extern void *g_lit_004ef7d8;
extern void ScaledChainCallPauseSetJmp_0048f8e0(void);
extern void Wrapper_00481060(void);

/* @addr 0x00480fe0 */
void ScaledLitLoadCall_00480fe0(void) {
    unsigned int idx = ((unsigned int)&g_lit_004ef4d0 >> 2) + (unsigned int)g_walkCallback;
    g_scaledInit_00542044 = idx;
    g_scaledInit_00542048 = *(unsigned int*)(idx * 4);
    ScaledChainCallPauseSetJmp_0048f8e0();
    if (g_framePauseFlag) return;
    Wrapper_00481060();
}

/* @addr 0x00481020 */
void ScaledLitLoadCall_00481020(void) {
    unsigned int idx = ((unsigned int)&g_lit_004ef7d8 >> 2) + (unsigned int)g_walkCallback;
    g_scaledInit_00542044 = idx;
    g_scaledInit_00542048 = *(unsigned int*)(idx * 4);
    ScaledChainCallPauseSetJmp_0048f8e0();
    if (g_framePauseFlag) return;
    Wrapper_00481060();
}
