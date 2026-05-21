/**
 * Auto-split from misc_matchesN.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004078f0 (48b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, [g_fightGroupHead]
 *   mov     ecx, [g_walkCallback]
 *   mov     [eax*4 + 0x28], ecx
 *   mov     edx, [g_fightGroupHead]
 *   add     edx, 0x0a
 *   mov     [g_state_00541dc4], edx
 *   ret
 */
extern unsigned int g_state_00541dc4;
extern void BootChainPushAddSignFlag_004077b0(void);
void CallPauseScaledStoreAdd_004078f0(void) {
    BootChainPushAddSignFlag_004077b0();
    if (g_framePauseFlag != 0) return;
    *(unsigned int *)(g_fightGroupHead * 4 + 0x28) = (unsigned int)g_walkCallback;
    g_state_00541dc4 = g_fightGroupHead + 0x0a;
}
