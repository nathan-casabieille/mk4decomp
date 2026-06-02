/**
 * 2 "scaled-load + dec + branch on zero" helpers (38 bytes each).
 *
 * Pattern:
 *   mov     ecx, [g_baseSel]
 *   mov     eax, [ecx*4 + 0x30]
 *   dec     eax
 *   mov     [g_walkCallback], eax
 *   jne     .nonzero
 *   jmp     T_zero
 * .nonzero:
 *   mov     [ecx*4 + 0x30], eax        ; persist decremented counter
 *   jmp     T_continue
 *
 * Decrements a per-base counter through the scaled selector. If it
 * just hit zero, tail-jumps to the "expired" handler (and does not
 * write the zero back). Otherwise persists the new value and tail-
 * jumps into the continue handler.
 */
#include "engine/scenegraph.h"

extern unsigned int g_baseSel;

extern void ThunkPlus4FieldCjCopy(void);
extern void FourEntryAlarmInstall(void);
extern void StoreFightFieldCallTailJmp(void);
extern void FourPackedSubInitCmpDispatch(void);

/* @addr 0x00466460 */
void ScaledDecBranch_00466460(void) {
    unsigned int idx = g_baseSel;
    unsigned int v = *(unsigned int*)(idx*4 + 0x30) - 1;
    g_walkCallback = v;
    if (v == 0) {
        ThunkPlus4FieldCjCopy();
        return;
    }
    *(unsigned int*)(idx*4 + 0x30) = v;
    FourEntryAlarmInstall();
}

/* @addr 0x00466770 */
void ScaledDecBranch_00466770(void) {
    unsigned int idx = g_baseSel;
    unsigned int v = *(unsigned int*)(idx*4 + 0x30) - 1;
    g_walkCallback = v;
    if (v == 0) {
        StoreFightFieldCallTailJmp();
        return;
    }
    *(unsigned int*)(idx*4 + 0x30) = v;
    FourPackedSubInitCmpDispatch();
}
