/**
 * Auto-split from misc_matches3.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_baseSel_00542060;

/* @addr 0x0048e7b0 (23b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     ecx, [eax*4 + 0x74]
 *   mov     [g_walkCallback], ecx
 *   jmp     +9
 */
extern void func_0048e7cb(void);
void ScaledLoadJmp_74_0048e7b0(void) {
    g_walkCallback = (void (*)(void))((ScenegraphNode *)(g_baseSel_00542060 * 4))->fsm_state;
    func_0048e7cb();
}
