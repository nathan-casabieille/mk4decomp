/**
 * 2 "guarded dispatch" helpers (34 bytes each, mask=4).
 *
 * Variant of GuardedDispatch (mask=1) that tests bit 2 of
 * g_xformDirtyFlags instead of bit 0.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern void CallDualStoreXorBit_004285e0(void);
extern void InstallSelfTri_00484a90(void);
extern void FiveCallGuardSetTail_0046f6b0(void);
extern void DirtyToggleByGate_0048f350(void);
extern void ScaledClearJmp_00428d60(void);
extern void InstallSelfReentry_004890b0(void);

/* @addr 0x00484b40 */
void GuardedDispatch4_00484b40(void) {
    CallDualStoreXorBit_004285e0();
    if (g_framePauseFlag) return;
    if (!(g_xformDirtyFlags & 4)) {
        InstallSelfTri_00484a90();
        return;
    }
    FiveCallGuardSetTail_0046f6b0();
}

/* @addr 0x00489080 */
void GuardedDispatch4_00489080(void) {
    DirtyToggleByGate_0048f350();
    if (g_framePauseFlag) return;
    if (!(g_xformDirtyFlags & 4)) {
        ScaledClearJmp_00428d60();
        return;
    }
    InstallSelfReentry_004890b0();
}
