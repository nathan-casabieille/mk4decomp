/**
 * Auto-split from misc_matches3.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;

/* @addr 0x00429790 (23b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     ecx, [eax*4 + 0x24]
 *   mov     [g_currentNodeIdx], ecx
 *   jmp     +0x29
 */
extern void ScaledIncCmpJmp(void);
void ScaledLoadJmp_24(void) {
    g_currentNodeIdx = ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_end;
    ScaledIncCmpJmp();
}
