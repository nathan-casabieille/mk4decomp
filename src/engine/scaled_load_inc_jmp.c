/**
 * 2 "scaled-load + inc + tail-jmp" wrappers (24 bytes each).
 *
 * Pattern:
 *   mov     eax, [g_fightGroupHead]
 *   mov     ecx, [eax*4 + 0x28]
 *   inc     ecx
 *   mov     [g_X], ecx
 *   jmp     Target
 *
 * Variant of ScaledLoadJmp (23b) that adds 1 to the loaded value
 * before storing it. Different destination globals per stub.
 */
#include "engine/scenegraph.h"

extern void ScaledArrStore_00428e70(void);
extern void ScaledArrStore_00429960(void);

/* @addr 0x00428d00 */
void ScaledLoadIncJmp_00428d00(void) {
    g_eventQueueCurrent = *(unsigned int *)(g_fightGroupHead * 4 + 0x28) + 1;
    ScaledArrStore_00428e70();
}

/* @addr 0x00429840 */
void ScaledLoadIncJmp_00429840(void) {
    g_walkCallback = (void (*)(void))(*(unsigned int *)(g_fightGroupHead * 4 + 0x28) + 1);
    ScaledArrStore_00429960();
}
