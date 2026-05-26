/**
 * Auto-split from misc_matchesO.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00436ff0 (48b)
 *   mov     [g_walkCallback], 0x14
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, [g_walkCallback]
 *   add     eax, 8
 *   mov     [g_walkCallback], eax
 *   mov     [g_eventQueueChild], eax
 *   jmp     +1
 *   ret
 */
extern void CallPauseInc_004ab670(void);
extern void InstallSelfMStackCountdown_00437020(void);
void Set14CallAddJmp_00436ff0(void) {
    unsigned int v;
    g_walkCallback = (void (*)(void))0x14;
    CallPauseInc_004ab670();
    if (g_framePauseFlag != 0) return;
    v = (unsigned int)g_walkCallback + 8;
    g_walkCallback = (void (*)(void))v;
    g_eventQueueChild = v;
    InstallSelfMStackCountdown_00437020();
}
