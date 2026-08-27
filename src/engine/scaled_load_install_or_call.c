/**
 * 2 "scaled-load + install + conditional literal-call" helpers (35 bytes).
 *
 * Pattern:
 *   mov     eax, [g_baseSel]
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

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern void *g_litEightFlag;
extern void *g_litNineFlag;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_litEightFlag (*(unsigned int *)MK4_VA(unsigned int, 0x4e4500u))
#define g_litNineFlag (*(unsigned int *)MK4_VA(unsigned int, 0x4e4528u))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif

extern int PackedAdvanceCallTailJmp(void *p);

/* @addr 0x00433960 */
void ScaledLoadInstallOrCall_00433960(void) {
    unsigned int cb = *(unsigned int*)MK4_PTR((g_baseSel * 4 + 0x30));
    g_walkCallback = cb;
    if (cb) {
        PackedAdvanceCallTailJmp(&g_litEightFlag);
    }
}

/* @addr 0x00433990 */
void ScaledLoadInstallOrCall_00433990(void) {
    unsigned int cb = *(unsigned int*)MK4_PTR((g_baseSel * 4 + 0x30));
    g_walkCallback = cb;
    if (cb) {
        PackedAdvanceCallTailJmp(&g_litNineFlag);
    }
}
