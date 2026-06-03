/**
 * Auto-split from misc_matchesI.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004887d0 (42b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   call    F2
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   push    0x004ef080
 *   call    F3
 *   add     esp, 4
 *   ret
 */
extern void ScaledMove48to58(void);
extern void Wrapper_ScaledChainPushCall_004ef810(void);
extern int ArgSarStoreJmp(void *p);
extern void *g_dispatchSave1312;
void TwoCallsPushCall(void) {
    ScaledMove48to58();
    if (g_framePauseFlag != 0) return;
    Wrapper_ScaledChainPushCall_004ef810();
    if (g_framePauseFlag != 0) return;
    ArgSarStoreJmp(&g_dispatchSave1312);
}
