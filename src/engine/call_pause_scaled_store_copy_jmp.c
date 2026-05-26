/**
 * Auto-split from misc_matchesO.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00461220 (50b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, [g_fightGroupHead]
 *   mov     ecx, [g_walkCallback]
 *   mov     [eax*4 + 0x24], ecx
 *   mov     edx, [g_fightGroupHead]
 *   mov     [g_eventQueueIdx], edx
 *   jmp     T
 *   ret
 */
extern void StateDispatchTable_00490fc0(void);
extern void func_00406ad0(void);
void CallPauseScaledStoreCopyJmp_00461220(void) {
    StateDispatchTable_00490fc0();
    if (g_framePauseFlag != 0) return;
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_end = (unsigned int)g_walkCallback;
    g_scaledInit_00542044 = g_fightGroupHead;
    func_00406ad0();
}
