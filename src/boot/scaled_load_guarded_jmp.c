/**
 * Auto-split from misc_matches3.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;

/* @addr 0x004066d0 (27b)
 *   mov     eax, [g_currentNodeIdx]
 *   mov     eax, [eax*4 + 4]
 *   test    eax, eax
 *   mov     [g_walkCallback], eax
 *   je      ret_label
 *   jmp     +6
 *   ret
 */
extern void MStackPushZeroCallPop(void);
void ScaledLoadGuardedJmp(void) {
    unsigned int v = *(unsigned int*)(g_currentNodeIdx * 4 + 4);
    g_walkCallback = (void(*)(void))v;
    if (v) {
        MStackPushZeroCallPop();
    }
}
