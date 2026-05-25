/**
 * Auto-split from misc_matchesO.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004362b0 (49b)
 *   call    F
 *   test    eax, eax
 *   jne     +0x27
 *   mov     eax, [g_table_00535ddc]
 *   cmp     eax, 0x00030000
 *   mov     [g_walkCallback], eax
 *   jle     +5
 *   jmp     T1
 *   cmp     eax, 0x00018000
 *   jge     +5
 *   jmp     +0x15
 *   jmp     T2
 *   ret
 */
extern unsigned int g_table_00535ddc;
extern int func_00436090(void);
extern void func_00430b96(void);
extern void func_00436324(void);
extern void func_004362cf(void);
void Cmp30000And18000_004362b0(void) {
    unsigned int v;
    if (func_00436090() != 0) return;
    v = g_table_00535ddc;
    g_walkCallback = (void (*)(void))v;
    if ((int)v > 0x30000) {
        func_00430b96();
        return;
    }
    if ((int)v < 0x18000) {
        func_004362cf();
        return;
    }
    func_00436324();
}
