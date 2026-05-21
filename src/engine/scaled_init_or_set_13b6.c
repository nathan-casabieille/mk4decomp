/**
 * Auto-split from misc_matchesW.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern u32 g_eventQueueWorkType;
extern packed_ptr g_xformEntityIdx;

/* @addr 0x00446600 (58b)
 *   mov     eax, [g_baseSel_00542060]
 *   mov     ecx, 1
 *   mov     eax, [eax*4 + 0x60]
 *   mov     [g_walkCallback], ecx
 *   mov     [g_scaledInit_00542044], eax
 *   shl     eax, 2
 *   mov     [eax + 0x1c], ecx
 *   mov     ecx, [eax + 0x20]
 *   or      ch, 1
 *   mov     [eax + 0x20], ecx
 *   mov     ecx, 0x13b6
 *   mov     [g_walkCallback], ecx
 *   mov     [eax + 0x38], ecx
 *   ret
 */
void ScaledInitOrSet13b6_00446600(void) {
    unsigned int idx;
    unsigned int one;
    unsigned int field;
    unsigned int v;
    idx = *(unsigned int *)(g_baseSel_00542060 * 4 + 0x60);
    one = 1;
    g_walkCallback = (void (*)(void))one;
    g_scaledInit_00542044 = idx;
    idx <<= 2;
    *(unsigned int *)(idx + 0x1c) = one;
    field = *(unsigned int *)(idx + 0x20);
    field |= 0x100;
    *(unsigned int *)(idx + 0x20) = field;
    v = 0x13b6;
    g_walkCallback = (void (*)(void))v;
    *(unsigned int *)(idx + 0x38) = v;
}
