/**
 * Auto-split from misc_matchesJ.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
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
extern void DualCondMatchSet(void);
extern int ArgSarStoreJmp(void *);
extern void *g_dispatchSave1313_004ef1d0;
extern void Wrapper_Cascade5StageInit_004ef1e8(void);
void CallPauseDirtyPushCall(void) {
    DualCondMatchSet();
    if (g_framePauseFlag != 0) return;
    if ((g_xformDirtyFlags & 1) == 0) {
        Wrapper_Cascade5StageInit_004ef1e8();
        return;
    }
    ArgSarStoreJmp(&g_dispatchSave1313_004ef1d0);
}
