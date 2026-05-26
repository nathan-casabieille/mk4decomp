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
extern int QuadBlockArgInstallChain_0043a950(void *p);
extern void *g_dispatchSave1238_004e4a1c;
extern void StateDispatchYield_00471190(void);
void PushCallPauseSet1Jmp_00438f20(void) {
    QuadBlockArgInstallChain_0043a950(&g_dispatchSave1238_004e4a1c);
    if (g_framePauseFlag != 0) return;
    g_walkCallback = (void (*)(void))1;
    StateDispatchYield_00471190();
}
