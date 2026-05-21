/**
 * Auto-split from misc_matchesJ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00488ba0 (42b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret              ; jne +0x1b
 *   test    byte [g_xformDirtyFlags], 1
 *   jne     +5                ; if dirty, skip jmp
 *   jmp     T                 ; not dirty, jump out
 *   push    0x004ef1d0
 *   call    F2
 *   add     esp, 4
 *   ret
 */
extern void DualCondMatchSet_00488dc0(void);
extern int func_00459500(void *);
extern void *g_data_004ef1d0;
extern void func_00488bd9(void);
void CallPauseDirtyPushCall_00488ba0(void) {
    DualCondMatchSet_00488dc0();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 1) == 0) {
        func_00488bd9();
        return;
    }
    func_00459500(&g_data_004ef1d0);
}
