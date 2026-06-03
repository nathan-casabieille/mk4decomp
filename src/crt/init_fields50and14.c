/**
 * Auto-split from misc_matchesA.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004c9dd0 (19b)
 *   mov     eax, [esp+4]
 *   mov     [eax + 0x50], 0x00522880
 *   mov     [eax + 0x14], 1
 *   ret
 */
extern void *g_crtIfaceVtable;
void InitFields50and14(char *p) {
    *(void **)(p + 0x50) = &g_crtIfaceVtable;
    *(int  *)(p + 0x14) = 1;
}
