/**
 * Auto-split from misc_matchesH.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00435230 (37b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   cmp     [g_walkCallback], 0x00013333
 *   jle     +5
 *   jmp     +0x11
 *   jmp     T
 *   ret
 */
extern void CmpP2P1ScaledJmp(void);
extern void InstallSelfDualPath(void);
extern void InstallSelfPacked0x2005(void);
void CallPauseCmpDoubleJmp(void) {
    CmpP2P1ScaledJmp();
    if (g_framePauseFlag != 0) {
        return;
    }
    if ((int)g_walkCallback > 0x13333) {
        InstallSelfDualPath();
    } else {
        InstallSelfPacked0x2005();
    }
}
