/**
 * Auto-split from misc_matchesG.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00439320 (38b)
 *   push    0x005422f8
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   add     esp, 4
 *   test    eax, eax
 *   jne     .ret
 *   mov     [g_walkCallback], 0x2147
 *   jmp     T
 *   ret
 */
extern int IterLoad_00491050(void *);
extern void *g_data_005422f8;
extern void ScaledOrStore_004903d0(void);
void PushCallSet2147Jmp_00439320(void) {
    IterLoad_00491050(&g_data_005422f8);
    if (g_framePauseFlag != 0) return;
    g_walkCallback = (void (*)(void))0x2147;
    ScaledOrStore_004903d0();
}
