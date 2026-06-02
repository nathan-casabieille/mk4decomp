/**
 * Auto-split from misc_matches9.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004c44f0 (18b)
 *   mov     eax, [g_timerInitedSkip]
 *   test    eax, eax
 *   je      .ret
 *   push    1
 *   call    [iat]
 * .ret:
 *   ret
 */
extern s32 g_timerInitedSkip;
extern void (__stdcall *g_iat_timeEndPeriod)(int);
void TestCallIat(void) {
    if (g_timerInitedSkip != 0) {
        g_iat_timeEndPeriod(1);
    }
}
