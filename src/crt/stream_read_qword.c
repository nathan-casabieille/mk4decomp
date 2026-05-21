/**
 * Auto-split from misc_matchesA.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004c83a0 (18b)
 *   mov     eax, [esp+4]
 *   mov     ecx, [eax]
 *   add     ecx, 8
 *   mov     [eax], ecx
 *   mov     eax, [ecx-8]
 *   mov     edx, [ecx-4]
 *   ret
 */
u64 StreamReadQword_004c83a0(u32 *stream) {
    u32 newpos = *stream + 8;
    *stream = newpos;
    return *(u64 *)(newpos - 8);
}
