/**
 * Auto-split from misc_matchesK.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00495cf0 (38b)
 *   mov     ecx, [g_baseSel_00542060]
 *   mov     eax, 0x0303
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x74], eax
 *   mov     [g_eventQueueNotMask], 0x0002000f
 *   jmp     T
 */
extern void func_0048d8d0(void);
void Const0303InitJmp_00495cf0(void) {
    unsigned int v = 0x0303;
    g_walkCallback = (void (*)(void))v;
    ((ScenegraphNode *)(g_baseSel_00542060 * 4))->fsm_state = v;
    g_eventQueueNotMask = 0x0002000f;
    func_0048d8d0();
}
