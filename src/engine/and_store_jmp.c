/**
 * Auto-split from misc_matches7.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0049cc10 (24b)
 *   mov     eax, [g_eventQueueCurrent]
 *   mov     ecx, [g_walkCallback]
 *   and     ecx, eax
 *   mov     [g_walkCallback], ecx
 *   jmp     T
 */
extern void ChainSearch_0041f9c0(void);
void AndStoreJmp_0049cc10(void) {
    g_walkCallback = (void(*)(void))((unsigned int)g_walkCallback & g_eventQueueCurrent);
    ChainSearch_0041f9c0();
}
