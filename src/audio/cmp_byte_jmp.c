/**
 * Auto-split from misc_matches7.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004a4180 (19b)
 *   cmp     byte ptr [0x00543590], 1
 *   jne     +5
 *   jmp     T1
 *   jmp     T2
 */
extern unsigned char g_gtModeFlag;
extern void Helper_AudioStub_4160(void);
extern void Helper_AudioStub_4140(void);
void CmpByteJmp(void) {
    if (g_gtModeFlag == 1) {
        Helper_AudioStub_4160();
        return;
    }
    Helper_AudioStub_4140();
}
