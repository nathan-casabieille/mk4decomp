/**
 * Auto-split from misc_matchesA.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004c8380 (17b)
 *   mov     eax, [esp+4]
 *   mov     ecx, [eax]
 *   add     ecx, 4
 *   mov     [eax], ecx
 *   mov     eax, ecx
 *   mov     eax, [eax-4]
 *   ret
 */
int StreamReadDword(int **stream) {
    int *p = *stream;
    *stream = p + 1;
    p = *stream;
    return p[-1];
}
