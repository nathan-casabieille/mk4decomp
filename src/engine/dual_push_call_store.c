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
extern int StoreTwoCall_0049cb40(void *p, int n);
extern void *g_dispatchSave1138_004234f0;
extern void *g_dispatchSave1139_00423570;
extern unsigned int g_dispatchSave99_00538040;
extern unsigned int g_dispatchSave98_00538044;
void DualPushCallStore_004231b0(void) {
    StoreTwoCall_0049cb40(&g_dispatchSave1138_004234f0, 3);
    g_dispatchSave99_00538040 = g_scaledInit_00542044;
    StoreTwoCall_0049cb40(&g_dispatchSave1139_00423570, 4);
    g_dispatchSave98_00538044 = g_scaledInit_00542044;
}
