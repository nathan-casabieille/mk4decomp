/**
 * Auto-split from misc_matches3.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x00429790 (23b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     ecx, [eax*4 + 0x24]
 *   mov     [g_scaledInit_00542044], ecx
 *   jmp     +0x29
 */
extern void func_004297c0(void);
void ScaledLoadJmp_24_00429790(void) {
    g_scaledInit_00542044 = ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_end;
    func_004297c0();
}
