/**
 * Auto-split from misc_matchesJ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00488c30 (43b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, 0x005006e0
 *   mov     [g_walkCallback], 0
 *   shr     eax, 2
 *   mov     [g_xformEntityIdx], eax
 *   jmp     +6
 *   ret
 */
extern void ScaledXorStore_004903b0(void);
extern void Wrapper_00488c60(void);
extern int g_dispatchSave405_005006e0;
void CallPauseLitInitJmp_00488c30(void) {
    ScaledXorStore_004903b0();
    if (g_framePauseFlag != 0) return;
    g_walkCallback = (void (*)(void))0;
    g_xformEntityIdx = ((unsigned int)&g_dispatchSave405_005006e0) >> 2;
    Wrapper_00488c60();
}
