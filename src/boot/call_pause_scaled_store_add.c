/**
 * Auto-split from misc_matchesN.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
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
 *   mov     [g_bootInitSaveSlot], edx
 *   ret
 */
extern unsigned int g_bootInitSaveSlot;
extern void BootChainPushAddSignFlag(void);
void CallPauseScaledStoreAdd(void) {
    BootChainPushAddSignFlag();
    if (g_framePauseFlag != 0) return;
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_idx = (unsigned int)g_walkCallback;
    g_bootInitSaveSlot = g_fightGroupHead + 0x0a;
}
