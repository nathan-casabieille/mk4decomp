/**
 * Auto-split from misc_matchesR.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004cc2b0 (43b)
 *   mov     eax, [esp+4]
 *   mov     ecx, [g_dispatchSave1469]
 *   cmp     eax, ecx
 *   jb      +3
 *   xor     eax, eax
 *   ret
 *   mov     ecx, eax
 *   and     eax, 0x1f
 *   sar     ecx, 5
 *   lea     edx, [eax + eax*8]
 *   mov     eax, [ecx*4 + 0x00fa0de0]
 *   mov     al, byte ptr [eax + edx + 4]
 *   and     eax, 0x40
 *   ret
 */
extern unsigned int g_dispatchSave1469;
extern unsigned int g_crtHandleTable[];
int TestHandleBit(int handle) {
    int hi;
    int lo;
    unsigned char *base;
    if ((unsigned int)handle >= g_dispatchSave1469) return 0;
    hi = handle >> 5;
    lo = handle & 0x1f;
    base = (unsigned char *)g_crtHandleTable[hi];
    return base[lo * 9 * 4 + 4] & 0x40;
}
