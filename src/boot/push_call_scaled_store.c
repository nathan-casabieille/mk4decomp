/**
 * Auto-split from misc_matchesE.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004143c0 (37b)
 *   push    0x8f
 *   push    0x004146d0
 *   call    F
 *   mov     eax, [g_scaledInit_00542044]
 *   mov     ecx, [g_baseSel_00542060]
 *   add     esp, 8
 *   mov     [ecx*4 + 0x34], eax
 *   ret
 */
extern int func_0049cb38(int, void *);
extern void *g_dispatchSave1134_004146d0;
void PushCallScaledStore_004143c0(void) {
    func_0049cb38((int)&g_dispatchSave1134_004146d0, 0x8f);
    ((ScenegraphNode *)(g_scaledInit_00542044 * 4))->state_mask = g_baseSel_00542060;
}
