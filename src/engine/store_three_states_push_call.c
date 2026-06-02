/**
 * Save three event-queue states + cdecl call.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"


/* @addr 0x00450680 (53b)
 *   mov     ecx, [g_eventQueueCurrent]
 *   mov     edx, [g_eventQueueChild]
 *   mov     eax, [g_eventQueueWorkType]
 *   push    0x93
 *   push    0x00450790
 *   mov     [g_dispatchVar18], eax
 *   mov     [g_dispatchVar17], ecx
 *   mov     [g_dispatchVar16], edx
 *   call    F
 *   add     esp, 8
 *   ret
 */
extern int StoreTwoCall(void *p, int n);
extern void *g_dispatchSave1147;
extern unsigned int g_dispatchVar18;
extern unsigned int g_dispatchVar17;
extern unsigned int g_dispatchVar16;
void StoreThreeStatesPushCall(void) {
    g_dispatchVar18 = (unsigned int)g_walkCallback;
    g_dispatchVar17 = g_eventQueueCurrent;
    g_dispatchVar16 = g_eventQueueWorkType;
    StoreTwoCall(&g_dispatchSave1147, 0x93);
}
