/**
 * Auto-split from misc_matches7.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x0049d080 (25b)
 *   mov     eax, [g_walkCallback]
 *   cmp     eax, 2
 *   jle     .keep
 *   cdq
 *   sub     eax, edx
 *   sar     eax, 1
 *   mov     [g_walkCallback], eax
 *   jmp     T
 */
extern void MStackPush3HelperCondToggle(void);
void CmpDivJmp(void) {
    int v = (int)g_walkCallback;
    if (v > 2) {
        g_walkCallback = (void (*)(void))(v / 2);
    }
    MStackPush3HelperCondToggle();
}
