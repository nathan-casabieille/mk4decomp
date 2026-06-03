/**
 * Auto-split from misc_matchesN.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

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
extern unsigned int g_pointPosX;
extern unsigned int g_pointPosY;
extern unsigned int g_pointPosZ;
void CopyThreeFields(unsigned int arg) {
    if (arg == 0) return;
    g_pointPosX = ((ScenegraphNode *)(arg * 4))->position_x;
    g_pointPosY = ((ScenegraphNode *)(arg * 4))->position_y;
    g_pointPosZ = ((ScenegraphNode *)(arg * 4))->position_z;
}
