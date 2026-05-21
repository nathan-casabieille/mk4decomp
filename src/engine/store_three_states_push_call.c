/**
 * Save three event-queue states + cdecl call.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern u32 g_eventQueueWorkType;

/* @addr 0x00450680 (53b)
 *   mov     ecx, [g_eventQueueCurrent]
 *   mov     edx, [g_eventQueueChild]
 *   mov     eax, [g_eventQueueWorkType]
 *   push    0x93
 *   push    0x00450790
 *   mov     [g_state_0052d750], eax
 *   mov     [g_state_0052d754], ecx
 *   mov     [g_state_0052d758], edx
 *   call    F
 *   add     esp, 8
 *   ret
 */
extern int func_004acabc(void *p, int n);
extern void *g_data_00450790;
extern unsigned int g_state_0052d750;
extern unsigned int g_state_0052d754;
extern unsigned int g_state_0052d758;
void StoreThreeStatesPushCall_00450680(void) {
    g_state_0052d750 = (unsigned int)g_walkCallback;
    g_state_0052d754 = g_eventQueueCurrent;
    g_state_0052d758 = g_eventQueueWorkType;
    func_004acabc(&g_data_00450790, 0x93);
}
