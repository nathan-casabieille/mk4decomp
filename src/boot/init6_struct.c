/**
 * Auto-split from misc_matchesE.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00404e20 (41b): zero a struct of various sizes
 *   xor     eax, eax
 *   mov     [0x00ab4e50], eax
 *   mov     [0x00ab4e54], eax
 *   mov     [0x00ab4e58], eax
 *   mov     eax, 0x8000
 *   mov     [0x00ab4e44], ax
 *   mov     [0x00ab4e48], ax
 *   mov     [0x00ab4e4c], ax
 *   ret
 */
extern unsigned int g_struct_00ab4e44;
extern unsigned int g_struct_00ab4e48;
extern unsigned int g_struct_00ab4e4c;
extern unsigned int g_struct_00ab4e50;
extern unsigned int g_struct_00ab4e54;
extern unsigned int g_struct_00ab4e58;
void Init6Struct_00404e20(void) {
    g_struct_00ab4e50 = 0;
    g_struct_00ab4e54 = 0;
    g_struct_00ab4e58 = 0;
    *(unsigned short *)&g_struct_00ab4e44 = 0x8000;
    *(unsigned short *)&g_struct_00ab4e48 = 0x8000;
    *(unsigned short *)&g_struct_00ab4e4c = 0x8000;
}
