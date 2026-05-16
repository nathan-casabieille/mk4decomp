/**
 * 2 "scaled-load + dec + branch on zero" helpers (38 bytes each).
 *
 * Pattern:
 *   mov     ecx, [g_baseSel_00542060]
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

extern unsigned int g_baseSel_00542060;

extern void ThunkPlus4FieldCjCopy_00466490(void);
extern void FourEntryAlarmInstall_004662e0(void);
extern void StoreFightFieldCallTailJmp_004667a0(void);
extern void FourPackedSubInitCmpDispatch_004665b0(void);

/* @addr 0x00466460 */
void ScaledDecBranch_00466460(void) {
    unsigned int idx = g_baseSel_00542060;
    unsigned int v = *(unsigned int*)(idx*4 + 0x30) - 1;
    g_walkCallback = v;
    if (v == 0) {
        ThunkPlus4FieldCjCopy_00466490();
        return;
    }
    *(unsigned int*)(idx*4 + 0x30) = v;
    FourEntryAlarmInstall_004662e0();
}

/* @addr 0x00466770 */
void ScaledDecBranch_00466770(void) {
    unsigned int idx = g_baseSel_00542060;
    unsigned int v = *(unsigned int*)(idx*4 + 0x30) - 1;
    g_walkCallback = v;
    if (v == 0) {
        StoreFightFieldCallTailJmp_004667a0();
        return;
    }
    *(unsigned int*)(idx*4 + 0x30) = v;
    FourPackedSubInitCmpDispatch_004665b0();
}
