/**
 * Auto-split from misc_matches8.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x004bd510 (22b)
 *   mov     eax, [g_currentNodeIdx]
 *   lea     ecx, [eax*4 + 0x48]
 *   push    ecx
 *   call    F
 *   add     esp, 4
 *   ret
 */
extern int CleanupCallTwice(void *);
void LeaScaledCall(void) {
    CleanupCallTwice((void *)(g_currentNodeIdx * 4 + 0x48));
}
