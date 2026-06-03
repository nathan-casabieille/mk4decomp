/**
 * Auto-split from misc_matchesS.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004231b0 (53b)
 *   push    3
 *   push    0x004234f0
 *   call    F
 *   mov     eax, [g_currentNodeIdx]
 *   add     esp, 8
 *   mov     [0x00538040], eax
 *   push    4
 *   push    0x00423570
 *   call    F
 *   mov     ecx, [g_currentNodeIdx]
 *   add     esp, 8
 *   mov     [0x00538044], ecx
 *   ret
 */
extern int StoreTwoCall(void *p, int n);
extern void *g_dispatchSave1138;
extern void *g_dispatchSave1139;
extern unsigned int g_dispatchSave99;
extern unsigned int g_dispatchSave98;
void DualPushCallStore(void) {
    StoreTwoCall(&g_dispatchSave1138, 3);
    g_dispatchSave99 = g_currentNodeIdx;
    StoreTwoCall(&g_dispatchSave1139, 4);
    g_dispatchSave98 = g_currentNodeIdx;
}
