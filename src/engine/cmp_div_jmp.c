/**
 * Auto-split from misc_matches7.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

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
extern void func_0049cf60(void);
void CmpDivJmp_0049d080(void) {
    int v = (int)g_walkCallback;
    if (v > 2) {
        g_walkCallback = (void (*)(void))(v / 2);
    }
    func_0049cf60();
}
