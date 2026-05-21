/**
 * Auto-split from misc_matchesS.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00429800 (52b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     ecx, [eax*4 + 0x24]
 *   mov     [g_scaledInit_00542044], ecx
 *   mov     eax, [eax*4 + 0x28]
 *   inc     eax
 *   mov     [g_walkCallback], eax
 *   mov     edx, [ecx*4 + 4]
 *   cmp     eax, edx
 *   jl      +5
 *   jmp     +0xb1
 *   jmp     +0x12c
 */
extern void func_0042985c(void);
extern void func_004298d7(void);
void ScaledIncCmpDualJmp_00429800(void) {
    unsigned int idx;
    unsigned int scaled;
    unsigned int v;
    int cmp_val;
    idx = g_fightGroupHead;
    scaled = *(unsigned int *)(idx * 4 + 0x24);
    g_scaledInit_00542044 = scaled;
    v = *(unsigned int *)(idx * 4 + 0x28) + 1;
    g_walkCallback = (void (*)(void))v;
    cmp_val = *(int *)(scaled * 4 + 4);
    if ((int)v >= cmp_val) {
        func_0042985c();
        return;
    }
    func_004298d7();
}
