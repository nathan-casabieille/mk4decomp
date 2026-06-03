/**
 * Auto-split from misc_matchesB.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_currentNodeIdx;

/* @addr 0x0042f840 (12b)
 *   mov     byte ptr [g_handWalkState148], 0
 *   jmp     T
 */
extern unsigned char g_handWalkState148;
extern void Phase4ThreePackedInstallSelf(void);
void StoreByteJmp(void) {
    g_handWalkState148 = 0;
    Phase4ThreePackedInstallSelf();
}
