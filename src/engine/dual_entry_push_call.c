/**
 * Auto-split from misc_matchesV.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern u32 g_eventQueueWorkType;
extern unsigned int g_acc_00542078;
extern packed_ptr g_xformEntityIdx;

/* @addr 0x0046b630 (59b)
 *   push    0x004eafb8
 *   call    F1
 *   add     esp, 4
 *   ret
 *   nop * 2
 *   mov     ecx, [g_baseSel_00542060]
 *   mov     eax, 0x2010
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x74], eax
 *   call    F2
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     +5
 *   jmp     T
 *   ret
 */
extern int func_004594ec(void *);
extern void *g_data_004eafb8;
extern void Wrapper_0048a350(void);
extern void func_0046b687(void);
/* @addr 0x0046b630 (14b): cdecl call func_004594ec(&g_data_004eafb8) + ret.
 * Entry A of the original 59-byte packed block; entry B at +0x10 lives in
 * func_0046b640. The 2-byte nop gap is filled by 0x90-fill. */
void DualEntryPushCall_0046b630(void) {
    func_004594ec(&g_data_004eafb8);
}

/* @addr 0x0046b640 (43b): orphan sub-entry - set walkCallback and
 * baseSel[+0x74] to 0x2010, call Wrapper_0048a350, then if !pause
 * tail-jmp func_0046b687. */
void func_0046b640(void) {
    int v = 0x2010;
    g_walkCallback = (void (*)(void))v;
    *(unsigned int *)(g_baseSel_00542060 * 4 + 0x74) = v;
    Wrapper_0048a350();
    if (g_framePauseFlag != 0) return;
    func_0046b687();
}
