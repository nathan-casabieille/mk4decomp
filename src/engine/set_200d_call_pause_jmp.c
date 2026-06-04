/**
 * Auto-split from misc_matchesV.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
extern unsigned int g_chainAccumCur;

/* @addr 0x0047c5e0 (57b)
 *   mov     ecx, [g_baseSel]
 *   mov     eax, 0x200d
 *   mov     edx, 0x004ed3e0
 *   mov     [g_walkCallback], eax
 *   shr     edx, 2
 *   mov     [ecx*4 + 0x74], eax
 *   mov     [g_currentNodeIdx], edx
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +5
 *   jmp     +8
 *   ret
 */
extern void GuardedDirtyXformFromTable(void);
extern void OneSetCmpJmpLoadCall(void);
extern int g_dispatchSave1304;
void Set200dCallPauseJmp(void) {
    g_walkCallback = (void (*)(void))0x200d;
    ((ScenegraphNode *)(g_baseSel * 4))->fsm_state = 0x200d;
    g_currentNodeIdx = ((unsigned int)&g_dispatchSave1304) >> 2;
    GuardedDirtyXformFromTable();
    if (g_framePauseFlag != 0) return;
    OneSetCmpJmpLoadCall();
}
