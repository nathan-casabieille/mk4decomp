/**
 * Auto-split from misc_matchesM.c
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004a1080 (35b)
 *   push    0x15
 *   push    0x004a6068        ; was 0x004a6060? actually let me decode
 *   call    F
 *   mov     ax, word ptr [0x004e2860]
 *   add     esp, 8
 *   push    eax
 *   call    F2
 *   add     esp, 4
 *   jmp     T
 */
extern int func_00498b40(void *p, int n);
extern int func_004be698(unsigned short v);
extern void *g_data_004a6068;
extern unsigned short g_word_004e2860;
extern void func_00428c10(void);
int Push15PushDataCallWordCallJmp_004a1080(void) {
    func_00498b40(&g_data_004a6068, 0x15);
    func_004be698(g_word_004e2860);
    return ((int (*)(void))func_00428c10)();
}
