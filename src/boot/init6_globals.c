/**
 * Auto-split from misc_matchesN.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004051b0 (47b)
 *   xor     eax, eax
 *   mov     [0x0053a188], eax
 *   mov     [0x0053a498], eax
 *   mov     [0x0053a79c], eax
 *   mov     [0x00537f08], eax
 *   mov     [0x0053a380], eax
 *   mov     eax, 1
 *   mov     [g_walkCallback], eax
 *   mov     [0x00535d08], eax
 *   jmp     T
 */
extern unsigned int g_state_0053a188;
extern unsigned int g_state_00537f08;
extern unsigned int g_state_0053a380;
extern unsigned int g_state_00535d08;
extern void func_00404efb(void);
void Init6Globals_004051b0(void) {
    g_state_0053a188 = 0;
    g_gtFightTickCounter = 0;
    g_logicFrameCounter = 0;
    g_state_00537f08 = 0;
    g_state_0053a380 = 0;
    g_walkCallback = (void (*)(void))1;
    g_state_00535d08 = 1;
    func_00404efb();
}
