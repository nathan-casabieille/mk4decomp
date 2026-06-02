/**
 * Auto-split from misc_matchesI.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00453750 (38b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, [g_scaledInit_00542044]
 *   mov     ecx, [eax*4 + 0x24]
 *   mov     [g_xformEntityIdx], ecx
 *   jmp     T
 *   ret
 */
extern void DirtyDoubleDeref(void);
extern void MStackPushDispatchBitGate(void);
void CallPauseScaledStoreXJmp(void) {
    DirtyDoubleDeref();
    if (g_framePauseFlag != 0) return;
    g_xformEntityIdx = ((ScenegraphNode *)(g_scaledInit_00542044 * 4))->queue_end;
    MStackPushDispatchBitGate();
}
