/**
 * Auto-split from misc_matchesO.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00460910 (46b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, [g_eventQueueCurrent]
 *   cmp     eax, 0x1010
 *   je      +0x13
 *   cmp     eax, 0x1011
 *   je      +0x0c
 *   cmp     eax, 0x0400
 *   je      +5
 *   jmp     +3
 *   ret
 */
extern void func_0048fc10(void);
extern void func_00460941(void);
void CallPauseTriCmpJmp_00460910(void) {
    unsigned int v;
    func_0048fc10();
    if (g_framePauseFlag != 0) return;
    v = g_eventQueueCurrent;
    if (v == 0x1010) return;
    if (v == 0x1011) return;
    if (v == 0x0400) return;
    func_00460941();
}
