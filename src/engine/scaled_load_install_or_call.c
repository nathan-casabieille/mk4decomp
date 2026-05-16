/**
 * 2 "scaled-load + install + conditional literal-call" helpers (35 bytes).
 *
 * Pattern:
 *   mov     eax, [g_baseSel_00542060]
 *   mov     eax, [eax*4 + 0x30]
 *   test    eax, eax
 *   mov     [g_walkCallback], eax
 *   je      .ret
 *   push    LITERAL                ; per-helper data ptr
 *   call    FuncX
 *   add     esp, 4
 * .ret:
 *   ret
 *
 * Loads a callback through the scaled selector. If non-zero, also
 * passes a per-helper literal pointer to a follow-up routine.
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel_00542060;
extern void *g_lit_004e4500;
extern void *g_lit_004e4528;
extern int func_004392e0(void *p);

/* @addr 0x00433960 */
void ScaledLoadInstallOrCall_00433960(void) {
    unsigned int cb = *(unsigned int*)(g_baseSel_00542060 * 4 + 0x30);
    g_walkCallback = cb;
    if (cb) {
        func_004392e0(&g_lit_004e4500);
    }
}

/* @addr 0x00433990 */
void ScaledLoadInstallOrCall_00433990(void) {
    unsigned int cb = *(unsigned int*)(g_baseSel_00542060 * 4 + 0x30);
    g_walkCallback = cb;
    if (cb) {
        func_004392e0(&g_lit_004e4528);
    }
}
