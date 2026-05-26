/**
 * Auto-split from misc_matchesN.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00404df0 (47b)
 *   mov     eax, [esp+4]
 *   test    eax, eax
 *   je      .ret
 *   mov     ecx, [eax*4 + 0x54]
 *   mov     [0x00ab4e50], ecx
 *   mov     edx, [eax*4 + 0x58]
 *   mov     [0x00ab4e54], edx
 *   mov     eax, [eax*4 + 0x5c]
 *   mov     [0x00ab4e58], eax
 *   ret
 */
extern unsigned int g_struct_00ab4e50;
extern unsigned int g_struct_00ab4e54;
extern unsigned int g_struct_00ab4e58;
void CopyThreeFields_00404df0(unsigned int arg) {
    if (arg == 0) return;
    g_struct_00ab4e50 = ((ScenegraphNode *)(arg * 4))->position_x;
    g_struct_00ab4e54 = ((ScenegraphNode *)(arg * 4))->position_y;
    g_struct_00ab4e58 = ((ScenegraphNode *)(arg * 4))->position_z;
}
