/**
 * Auto-split from misc_matchesM.c
 */
#include "engine/scenegraph.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
#endif

/* @addr 0x004ab600 (39b)
 *   mov     eax, [0x004d5100]
 *   mov     ecx, [0x004d5104]
 *   add     eax, ecx
 *   mov     edx, eax
 *   mov     [0x004d5100], eax
 *   sar     edx, 0x1f
 *   add     edx, eax
 *   mov     [g_walkCallback], edx
 *   add     ecx, edx
 *   mov     [0x004d5104], ecx
 *   ret
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern int g_dispatchSave1163;
extern int g_dispatchSave1164;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dispatchSave1163 (*(int *)MK4_VA(int, 0x4d5100u))
#define g_dispatchSave1164 (*(int *)MK4_VA(int, 0x4d5104u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif

void DualAddSar(void) {
    int a = g_dispatchSave1163;
    int b = g_dispatchSave1164;
    int sum = a + b;
    int temp = (sum >> 31) + sum;
    g_dispatchSave1163 = sum;
    g_walkCallback = (void (*)(void))sum;
    g_dispatchSave1164 += temp;
}
