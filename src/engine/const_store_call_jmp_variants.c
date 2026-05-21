/**
 * Auto-split from misc_matches4.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x00448fa0 (30b)
 *   mov     [g_walkCallback], 3
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     ret_label
 *   jmp     Tail
 *   ret
 */
extern void func_00408c0a(void);
extern void func_00475778(void);
void ConstStoreCallJmp_00448fa0(void) {
    g_walkCallback = (void(*)(void))3;
    func_00408c0a();
    if (g_framePauseFlag) return;
    func_00475778();
}

/* @addr 0x0046ff60 (30b): same shape, value=4 */
extern void func_0048a046(void);
extern void func_0046ff8e(void);
void ConstStoreCallJmp_0046ff60(void) {
    g_walkCallback = (void(*)(void))4;
    func_0048a046();
    if (g_framePauseFlag) return;
    func_0046ff8e();
}
