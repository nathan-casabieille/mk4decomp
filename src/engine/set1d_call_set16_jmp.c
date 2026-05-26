/**
 * Auto-split from misc_matchesI.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004809b0 (40b)
 *   mov     [g_walkCallback], 0x1d
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     [g_walkCallback], 0x16
 *   jmp     T
 *   ret
 */
extern void TableLookupCall_00489ff0(void);
extern void ScaledInit_0048d490(void);
void Set1dCallSet16Jmp_004809b0(void) {
    g_walkCallback = (void (*)(void))0x1d;
    TableLookupCall_00489ff0();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = (void (*)(void))0x16;
    ScaledInit_0048d490();
}
