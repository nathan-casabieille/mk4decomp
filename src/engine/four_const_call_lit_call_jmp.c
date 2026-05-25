/**
 * 2 "four const stores + call + lit-call + jmp" helpers (88b).
 *
 * Pattern:
 *   mov     eax, [g_baseSel_00542060]
 *   mov     [eax*4 + 0x74], 0x00001011
 *   mov     [g_phaseTimer_00537e94], 5
 *   mov     [g_walkCallback], 0x00008000
 *   mov     [g_eventQueueCurrent], 0
 *   call    FuncA
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   push    LITERAL
 *   call    FuncB
 *   mov     eax, [g_framePauseFlag]
 *   add     esp, 4
 *   test    eax, eax
 *   jne     .ret
 *   jmp     Tail
 * .ret:
 *   ret
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_phaseTimer_00537e94;

extern void *g_lit_004ed7e0;
extern void *g_lit_004ed7f0;
extern void Wrapper_0048ff30(void);
extern int  TripleScaledChainStore_004908f0(void *p);
extern void StageEventStartCluster_0047ff80(void);

/* @addr 0x0047fec0 */
void FourConstCallLitCallJmp_0047fec0(void) {
    *(unsigned int*)(g_baseSel_00542060 * 4 + 0x74) = 0x1011;
    g_phaseTimer_00537e94 = 5;
    g_walkCallback = (void(*)(void))0x8000;
    g_eventQueueCurrent = 0;
    Wrapper_0048ff30();
    if (g_framePauseFlag) return;
    TripleScaledChainStore_004908f0(&g_lit_004ed7e0);
    if (g_framePauseFlag) return;
    StageEventStartCluster_0047ff80();
}

/* @addr 0x0047ff20 */
void FourConstCallLitCallJmp_0047ff20(void) {
    *(unsigned int*)(g_baseSel_00542060 * 4 + 0x74) = 0x1011;
    g_phaseTimer_00537e94 = 5;
    g_walkCallback = (void(*)(void))0x8000;
    g_eventQueueCurrent = 0;
    Wrapper_0048ff30();
    if (g_framePauseFlag) return;
    TripleScaledChainStore_004908f0(&g_lit_004ed7f0);
    if (g_framePauseFlag) return;
    StageEventStartCluster_0047ff80();
}
