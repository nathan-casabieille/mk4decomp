/**
 * Auto-split from misc_matchesS.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004231b0 (53b)
 *   push    3
 *   push    0x004234f0
 *   call    F
 *   mov     eax, [g_scaledInit_00542044]
 *   add     esp, 8
 *   mov     [0x00538040], eax
 *   push    4
 *   push    0x00423570
 *   call    F
 *   mov     ecx, [g_scaledInit_00542044]
 *   add     esp, 8
 *   mov     [0x00538044], ecx
 *   ret
 */
extern int func_0049cb34(void *p, int n);
extern void *g_data_004234f0;
extern void *g_data_00423570;
extern unsigned int g_state_00538040;
extern unsigned int g_state_00538044;
void DualPushCallStore_004231b0(void) {
    func_0049cb34(&g_data_004234f0, 3);
    g_state_00538040 = g_scaledInit_00542044;
    func_0049cb34(&g_data_00423570, 4);
    g_state_00538044 = g_scaledInit_00542044;
}
