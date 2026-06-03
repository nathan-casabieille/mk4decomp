/**
 * Auto-split from misc_matches8.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004ab670 (21b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +6
 *   inc     dword ptr [g_walkCallback]
 *   ret
 */
extern void StorePauseImulShr16(void);
void CallPauseInc(void) {
    StorePauseImulShr16();
    if (g_framePauseFlag == 0) {
        g_walkCallback = (void (*)(void))((unsigned int)g_walkCallback + 1);
    }
}
