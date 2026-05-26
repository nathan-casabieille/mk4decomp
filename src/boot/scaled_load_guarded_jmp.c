/**
 * Auto-split from misc_matches3.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x004066d0 (27b)
 *   mov     eax, [g_scaledInit_00542044]
 *   mov     eax, [eax*4 + 4]
 *   test    eax, eax
 *   mov     [g_walkCallback], eax
 *   je      ret_label
 *   jmp     +6
 *   ret
 */
extern void MStackPushZeroCallPop_004066f0(void);
void ScaledLoadGuardedJmp_004066d0(void) {
    unsigned int v = *(unsigned int*)(g_scaledInit_00542044 * 4 + 4);
    g_walkCallback = (void(*)(void))v;
    if (v) {
        MStackPushZeroCallPop_004066f0();
    }
}
