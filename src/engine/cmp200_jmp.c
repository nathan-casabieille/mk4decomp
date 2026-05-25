/**
 * Auto-split from misc_matches9.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0043bd30 (27b)
 *   mov     eax, [g_X]
 *   cmp     eax, 0x200
 *   mov     [g_walkCallback], eax
 *   jge     +5
 *   jmp     T1
 *   jmp     +5
 */
extern unsigned int g_table_00535ddc;
extern void func_00408f80(void);
extern void func_0043bd5b(void);
void Cmp200Jmp_0043bd30(void) {
    unsigned int v = g_table_00535ddc;
    g_walkCallback = (void (*)(void))v;
    if ((int)v < 0x20000) {
        func_00408f80();
    } else {
        func_0043bd5b();
    }
}
