/**
 * Auto-split from misc_matchesD.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00404ef0 (33b)
 *   mov     eax, [esp+4]
 *   mov     ecx, [g_baseSel_00542060]
 *   mov     [g_pendingNodeType], eax
 *   mov     edx, [ecx*4 + 0x0c]
 *   mov     [g_eventQueueWorkType], edx
 *   jmp     T
 */
extern void func_0049cb44(void);
void StoreLoadJmp_00404ef0(unsigned int arg) {
    g_pendingNodeType = arg;
    g_eventQueueWorkType = ((ScenegraphNode *)(g_baseSel_00542060 * 4))->alloc_work_type;
    func_0049cb44();
}
