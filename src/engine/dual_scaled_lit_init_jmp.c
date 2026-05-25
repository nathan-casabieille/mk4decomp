/**
 * Auto-split from misc_matchesO.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00464800 (47b)
 *   mov     eax, 0x0050b10c
 *   shr     eax, 2
 *   mov     [g_scaledInit_00542044], eax
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     ecx, 0x0051131c     ; was 0x00511310 + 0xc?
 *   shr     ecx, 2
 *   mov     [g_scaledInit_00542044], ecx
 *   jmp     T
 *   ret
 */
extern void func_004bd5a4(void);
extern void func_004bd584(void);
extern int g_dispatchSave409_0050b10c;
extern int g_dispatchSave414_00511310;
void DualScaledLitInitJmp_00464800(void) {
    g_scaledInit_00542044 = ((unsigned int)&g_dispatchSave409_0050b10c) >> 2;
    func_004bd5a4();
    if (g_framePauseFlag != 0) return;
    g_scaledInit_00542044 = ((unsigned int)&g_dispatchSave414_00511310) >> 2;
    func_004bd584();
}
