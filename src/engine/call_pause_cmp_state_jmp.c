/**
 * Auto-split from misc_matchesP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x0046a520 (50b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, [g_fightStateProgress]
 *   cmp     eax, 0x00030000
 *   mov     [g_walkCallback], eax
 *   jle     +5
 *   jmp     +0x1c
 *   push    0x004eabb0
 *   call    F2
 *   add     esp, 4
 *   ret
 */
extern unsigned int g_fightStateProgress;
extern void ScaledZeroFour(void);
extern void ArgSarStoreJmp(void *p);
extern void *g_dispatchSave1280;
extern void GuardedPushCall_CopyJmp_then_ArgSarStoreJmp_0046a560(void);
void CallPauseCmpStateJmp(void) {
    unsigned int v;
    ScaledZeroFour();
    if (g_framePauseFlag != 0) return;
    v = g_fightStateProgress;
    g_walkCallback = (void (*)(void))v;
    if ((int)v > 0x30000) {
        GuardedPushCall_CopyJmp_then_ArgSarStoreJmp_0046a560();
        return;
    }
    ArgSarStoreJmp(&g_dispatchSave1280);
}
