/**
 * Auto-split from misc_matchesV.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_acc_00542078;

/* @addr 0x0047c5e0 (57b)
 *   mov     ecx, [g_baseSel_00542060]
 *   mov     eax, 0x200d
 *   mov     edx, 0x004ed3e0
 *   mov     [g_walkCallback], eax
 *   shr     edx, 2
 *   mov     [ecx*4 + 0x74], eax
 *   mov     [g_scaledInit_00542044], edx
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +5
 *   jmp     +8
 *   ret
 */
extern void func_0048f6f0(void);
extern void func_0047c61b(void);
extern int g_dispatchSave1304_004ed3e0;
void Set200dCallPauseJmp_0047c5e0(void) {
    g_walkCallback = (void (*)(void))0x200d;
    ((ScenegraphNode *)(g_baseSel_00542060 * 4))->fsm_state = 0x200d;
    g_scaledInit_00542044 = ((unsigned int)&g_dispatchSave1304_004ed3e0) >> 2;
    func_0048f6f0();
    if (g_framePauseFlag != 0) return;
    func_0047c61b();
}
