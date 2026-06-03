/**
 * Auto-split from misc_matchesN.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

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
extern unsigned int g_dispatchSave305;
extern unsigned int g_dispatchSave401;
extern unsigned int g_dispatchSave304;
extern unsigned int g_dispatchSave400;
extern void BootInitChainHeavy(void);
void Init6Globals(void) {
    g_dispatchSave305 = 0;
    g_gtFightTickCounter = 0;
    g_logicFrameCounter = 0;
    g_dispatchSave401 = 0;
    g_dispatchSave304 = 0;
    g_walkCallback = (void (*)(void))1;
    g_dispatchSave400 = 1;
    BootInitChainHeavy();
}
