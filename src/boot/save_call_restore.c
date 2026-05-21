/**
 * Auto-split from misc_matchesE.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004049d0 (38b)
 *   mov     eax, [esp+4]
 *   push    esi
 *   mov     esi, [g_walkCallback]
 *   mov     [g_walkCallback], eax
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     [g_walkCallback], esi
 * .ret:
 *   pop     esi
 *   ret
 */
extern void TripleCallCountdown_00428080(void);
void SaveCallRestore_004049d0(unsigned int arg) {
    void (*saved)(void) = g_walkCallback;
    g_walkCallback = (void (*)(void))arg;
    TripleCallCountdown_00428080();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = saved;
}
