/**
 * Auto-split from misc_matchesO.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0042fc40 (50b)
 *   mov     eax, [g_eventQueueWorkType]
 *   mov     ecx, [g_acc_00542078]
 *   sub     eax, 0x0a3d
 *   cmp     ecx, eax
 *   mov     [g_eventQueueWorkType], eax
 *   jle     +5
 *   jmp     T1
 *   call    F
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +5
 *   jmp     T2
 *   ret
 */
extern u32 g_eventQueueWorkType;
extern unsigned int g_acc_00542078;
extern void func_0042fb6c(void);
extern void func_0042fc62(void);
extern void func_0042f87c(void);
void SubCmpCallPauseJmp_0042fc40(void) {
    unsigned int new_wt;
    int acc;
    new_wt = g_eventQueueWorkType;
    new_wt -= 0x0a3d;
    acc = (int)g_acc_00542078;
    g_eventQueueWorkType = new_wt;
    if (acc > (int)new_wt) {
        func_0042fb6c();
        return;
    }
    func_0042fc62();
    if (g_framePauseFlag != 0) return;
    func_0042f87c();
}
