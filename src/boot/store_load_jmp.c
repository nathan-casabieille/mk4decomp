/**
 * Auto-split from misc_matchesD.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00404ef0 (33b)
 *   mov     eax, [esp+4]
 *   mov     ecx, [g_baseSel]
 *   mov     [g_pendingNodeType], eax
 *   mov     edx, [ecx*4 + 0x0c]
 *   mov     [g_eventQueueWorkType], edx
 *   jmp     T
 */
void StoreLoadJmp(unsigned int arg) {
    g_pendingNodeType = arg;
    g_eventQueueWorkType = ((ScenegraphNode *)(g_baseSel * 4))->alloc_work_type;
    AllocNode();
}
