/**
 * Auto-split from misc_matchesI.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004887d0 (42b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   call    F2
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   push    0x004ef080
 *   call    F3
 *   add     esp, 4
 *   ret
 */
extern void func_00489520(void);
extern void Wrapper_0048a280(void);
extern int ArgSarStoreJmp_004594f0(void *p);
extern void *g_dispatchSave1312_004ef080;
void TwoCallsPushCall_004887d0(void) {
    func_00489520();
    if (g_framePauseFlag != 0) return;
    Wrapper_0048a280();
    if (g_framePauseFlag != 0) return;
    ArgSarStoreJmp_004594f0(&g_dispatchSave1312_004ef080);
}
