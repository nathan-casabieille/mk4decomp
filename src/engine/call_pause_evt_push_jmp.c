/**
 * Call + pause-check + event-counter increment with tail-jmp.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x00422880 (44b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, [g_eventQueueCurrent]
 *   mov     ecx, [g_xformEntityIdx]
 *   inc     eax
 *   mov     [g_eventQueueCurrent], eax
 *   mov     [ecx*4 + 0], eax
 *   jmp     T
 */
extern packed_ptr g_xformEntityIdx;
extern void SwapOrPassSet_0048fbf0(void);
extern void func_00478328(void);
void CallPauseEvtPushJmp_00422880(void) {
    unsigned int v;
    SwapOrPassSet_0048fbf0();
    if (g_framePauseFlag != 0) return;
    v = g_eventQueueCurrent + 1;
    g_eventQueueCurrent = v;
    *(unsigned int *)(g_xformEntityIdx * 4) = v;
    func_00478328();
}
