/**
 * Auto-split from misc_matchesX.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern u32 g_eventQueueWorkType;
extern packed_ptr g_xformEntityIdx;
extern u32 g_pendingNodeType;
extern const int g_sinTable[];
extern void Mul10Tail_00404af0(void);

/* @addr 0x0041f1f0 (54b)
 *   mov     eax, [g_eventQueueWorkType]
 *   push    eax
 *   push    0x028be602
 *   call    Mul10Tail
 *   sar     eax, 0x10
 *   sub     eax, 0x400
 *   add     esp, 8
 *   and     eax, 0xfff
 *   mov     [g_eventQueueWorkType], eax
 *   mov     ecx, [eax*4 + g_sinTable]
 *   sar     ecx, 0x0c
 *   mov     [g_walkCallback], ecx
 *   ret
 */
void RandSarMod0xFFFSub400_0041f1f0(void) {
    int r;
    unsigned int idx;
    r = ((int (*)(int, int))Mul10Tail_00404af0)(0x028be602, (int)g_eventQueueWorkType);
    r = (r >> 16) - 0x400;
    idx = (unsigned int)r & 0xfff;
    g_eventQueueWorkType = idx;
    g_walkCallback = (void (*)(void))(g_sinTable[idx] >> 12);
}
