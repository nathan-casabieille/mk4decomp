/**
 * Auto-split from misc_matchesK.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00491080 (43b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     ecx, [g_eventQueueIdx]
 *   mov     [eax*4 + 0x24], ecx
 *   mov     edx, [g_fightGroupHead]
 *   xor     eax, eax
 *   mov     [g_walkCallback], eax
 *   mov     [edx*4 + 0x28], eax
 *   jmp     T
 */
extern void ScaledLoadOrSetJmp_00406b20(void);
void DualScaledStoreZero_00491080(void) {
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_end = g_xformEntityIdx;
    g_walkCallback = (void (*)(void))0;
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_idx = 0;
    ScaledLoadOrSetJmp_00406b20();
}
