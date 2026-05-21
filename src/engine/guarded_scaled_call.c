/**
 * Auto-split from misc_matchesJ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0048a020 (45b)
 *   mov     eax, [g_state_00541dc0]
 *   test    eax, eax
 *   jl      +0x23
 *   mov     eax, [g_walkCallback]
 *   test    eax, eax
 *   jl      +0x1a
 *   mov     [g_scaledInit_00542044], eax
 *   mov     eax, [eax*4 + 0]
 *   push    eax
 *   mov     [g_walkCallback], eax
 *   call    F
 *   add     esp, 4
 *   ret
 */
extern unsigned int g_state_00541dc0;
extern int func_004be690_b(int);
void GuardedScaledCall_0048a020(void) {
    unsigned int walk;
    int v;
    if ((int)g_state_00541dc0 < 0) return;
    walk = (unsigned int)g_walkCallback;
    if ((int)walk < 0) return;
    g_scaledInit_00542044 = walk;
    v = *(int *)(walk * 4);
    g_walkCallback = (void (*)(void))v;
    func_004be690_b(v);
}
