/**
 * Auto-split from misc_matchesJ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00488c00 (37b)
 *   mov     eax, 0x00500d4c
 *   push    0x004ef1f8
 *   shr     eax, 2
 *   mov     [g_xformEntityIdx], eax
 *   mov     [g_walkCallback], 0
 *   call    F
 *   add     esp, 4
 *   ret
 */
extern void *g_dispatchSave1314_004ef1f8;
extern int func_00491508(void *);
extern int g_dispatchSave406_00500d4c;
void LiteralPushCallEntZero_00488c00(void) {
    g_xformEntityIdx = ((unsigned int)&g_dispatchSave406_00500d4c) >> 2;
    g_walkCallback = (void (*)(void))0;
    func_00491508(&g_dispatchSave1314_004ef1f8);
}
