/**
 * 3 "conditional install + dispatch + xform-flag clear" helpers (58b).
 *
 * Pattern:
 *   mov     eax, [g_currentNodeIdx]
 *   mov     eax, [eax*4 + 0x0c]
 *   test    eax, eax
 *   mov     [g_walkCallback], eax
 *   je      .after_dispatch
 *   mov     [g_walkCallback], OFFSET fnLiteral   ; override with literal fn ptr
 *   call    Helper_TickAlt
 * .after_dispatch:
 *   mov     eax, [g_framePauseFlag]
 *   test    eax, eax
 *   jne     .ret
 *   mov     eax, [g_xformDirtyFlags]
 *   and     al, 0xfe
 *   mov     [g_xformDirtyFlags], eax
 * .ret:
 *   ret
 *
 * Loads a callback from a per-helper table slot. If non-null, also
 * stamps in a literal function pointer and dispatches. Then clears
 * bit 0 of g_xformDirtyFlags unless paused.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_currentNodeIdx;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformDirtyFlags (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#endif

extern void ScaledOr4Jmp(void);
extern void func_00476e90(void);
extern void ScaledAndFBJmp(void);
extern void Helper_TickAlt(void);

/* @addr 0x00476e20 */
void CondInstallDispatch_00476e20(void) {
    unsigned int cb = ((ScenegraphNode *)MK4_PTR((g_currentNodeIdx * 4)))->alloc_work_type;
    g_walkCallback = (void(*)(void))cb;
    if (cb) {
        g_walkCallback = ScaledOr4Jmp;
        Helper_TickAlt();
        if (g_framePauseFlag) return;
    }
    g_xformDirtyFlags = g_xformDirtyFlags & 0xFFFFFFFEu;
}

/* @addr 0x00476ed0 */
void CondInstallDispatch_00476ed0(void) {
    unsigned int cb = ((ScenegraphNode *)MK4_PTR((g_currentNodeIdx * 4)))->alloc_work_type;
    g_walkCallback = (void(*)(void))cb;
    if (cb) {
        g_walkCallback = func_00476e90;
        Helper_TickAlt();
        if (g_framePauseFlag) return;
    }
    g_xformDirtyFlags = g_xformDirtyFlags & 0xFFFFFFFEu;
}

/* @addr 0x00477000 */
void CondInstallDispatch_00477000(void) {
    unsigned int cb = ((ScenegraphNode *)MK4_PTR((g_currentNodeIdx * 4)))->alloc_work_type;
    g_walkCallback = (void(*)(void))cb;
    if (cb) {
        g_walkCallback = ScaledAndFBJmp;
        Helper_TickAlt();
        if (g_framePauseFlag) return;
    }
    g_xformDirtyFlags = g_xformDirtyFlags & 0xFFFFFFFEu;
}
