/**
 * Auto-split from misc_matchesN.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
#endif

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
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_bootInitSaveSlot;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_bootInitSaveSlot (*(unsigned int *)MK4_VA(unsigned int, 0x541dc4u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_fightGroupHead (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif

extern void BootChainPushAddSignFlag(void);
void CallPauseScaledStoreAdd(void) {
    BootChainPushAddSignFlag();
    if (g_framePauseFlag != 0) return;
    ((ScenegraphNode *)MK4_PTR((g_fightGroupHead * 4)))->queue_idx = (unsigned int)g_walkCallback;
    g_bootInitSaveSlot = g_fightGroupHead + 0x0a;
}
