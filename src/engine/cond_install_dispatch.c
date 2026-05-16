/**
 * 3 "conditional install + dispatch + xform-flag clear" helpers (58b).
 *
 * Pattern:
 *   mov     eax, [g_scaledInit_00542044]
 *   mov     eax, [eax*4 + 0x0c]
 *   test    eax, eax
 *   mov     [g_walkCallback], eax
 *   je      .after_dispatch
 *   mov     [g_walkCallback], OFFSET fnLiteral   ; override with literal fn ptr
 *   call    func_004baea0
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

extern unsigned int g_scaledInit_00542044;
extern void ScaledOr4Jmp_00476e00(void);
extern void func_00476e90(void);
extern void ScaledAndFBJmp_00476fe0(void);
extern void func_004baea0(void);

/* @addr 0x00476e20 */
void CondInstallDispatch_00476e20(void) {
    unsigned int cb = *(unsigned int*)(g_scaledInit_00542044 * 4 + 0x0c);
    g_walkCallback = (void(*)(void))cb;
    if (cb) {
        g_walkCallback = ScaledOr4Jmp_00476e00;
        func_004baea0();
        if (g_framePauseFlag) return;
    }
    g_xformDirtyFlags = g_xformDirtyFlags & 0xFFFFFFFEu;
}

/* @addr 0x00476ed0 */
void CondInstallDispatch_00476ed0(void) {
    unsigned int cb = *(unsigned int*)(g_scaledInit_00542044 * 4 + 0x0c);
    g_walkCallback = (void(*)(void))cb;
    if (cb) {
        g_walkCallback = func_00476e90;
        func_004baea0();
        if (g_framePauseFlag) return;
    }
    g_xformDirtyFlags = g_xformDirtyFlags & 0xFFFFFFFEu;
}

/* @addr 0x00477000 */
void CondInstallDispatch_00477000(void) {
    unsigned int cb = *(unsigned int*)(g_scaledInit_00542044 * 4 + 0x0c);
    g_walkCallback = (void(*)(void))cb;
    if (cb) {
        g_walkCallback = ScaledAndFBJmp_00476fe0;
        func_004baea0();
        if (g_framePauseFlag) return;
    }
    g_xformDirtyFlags = g_xformDirtyFlags & 0xFFFFFFFEu;
}
