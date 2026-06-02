/**
 * Push-arg call + pause-check + set walk=1 + tail-jmp.
 */
#include "engine/scenegraph.h"

/* @addr 0x00438f20 (38b)
 *   push    0x004e4a1c
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   add     esp, 4
 *   test    eax, eax
 *   jne     .ret
 *   mov     [g_walkCallback], 1
 *   jmp     T
 */
extern u32 g_framePauseFlag;
extern int QuadBlockArgInstallChain(void *p);
extern void *g_dispatchSave1238_004e4a1c;
extern void StateDispatchYield(void);
void PushCallPauseSet1Jmp_00438f20(void) {
    QuadBlockArgInstallChain(&g_dispatchSave1238_004e4a1c);
    if (g_framePauseFlag != 0) return;
    g_walkCallback = (void (*)(void))1;
    StateDispatchYield();
}
