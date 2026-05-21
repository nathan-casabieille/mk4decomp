/**
 * Auto-split from misc_matchesB.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x004b5ae0 (29b)
 *   mov     eax, [esp+4]
 *   mov     ecx, [esp+8]
 *   and     ecx, 0x3f
 *   mov     edx, [eax-0xc]
 *   shl     ecx, 0x18
 *   and     edx, 0xc0ffffff
 *   or      ecx, edx
 *   mov     [eax-0xc], ecx
 *   ret
 */
void SetHi6_004b5ae0(unsigned int *p, unsigned int v) {
    p[-3] = (p[-3] & 0xc0ffffffu) | ((v & 0x3fu) << 24);
}
