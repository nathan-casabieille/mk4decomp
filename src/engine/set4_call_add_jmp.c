/**
 * Auto-split from misc_matchesI.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00472890 (37b)
 *   mov     [g_walkCallback], 4
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .skip
 *   add     dword ptr [g_walkCallback], 0x42
 *   jmp     T
 * .skip:
 *   ret
 */
extern void func_004ab620_b(void);
extern void GatedWordPushCall_00489f90(void);
void Set4CallAddJmp_00472890(void) {
    g_walkCallback = (void (*)(void))4;
    func_004ab620_b();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = (void (*)(void))((unsigned int)g_walkCallback + 0x42);
    GatedWordPushCall_00489f90();
}
