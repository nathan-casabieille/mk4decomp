/**
 * Auto-split from misc_matchesH.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00435230 (37b)
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   cmp     [g_walkCallback], 0x00013333
 *   jle     +5
 *   jmp     +0x11
 *   jmp     T
 *   ret
 */
extern void func_00485e50(void);
extern void func_0043524c(void);
extern void func_00437a91(void);
void CallPauseCmpDoubleJmp_00435230(void) {
    func_00485e50();
    if (g_framePauseFlag != 0) {
        return;
    }
    if ((int)g_walkCallback > 0x13333) {
        func_0043524c();
    } else {
        func_00437a91();
    }
}
