/**
 * Auto-split from misc_matchesA.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004c9dd0 (19b)
 *   mov     eax, [esp+4]
 *   mov     [eax + 0x50], 0x00522880
 *   mov     [eax + 0x14], 1
 *   ret
 */
extern void *g_table_00522880;
void InitFields50and14_004c9dd0(char *p) {
    *(void **)(p + 0x50) = &g_table_00522880;
    *(int  *)(p + 0x14) = 1;
}
