/**
 * 2 "guarded dispatch" helpers (34 bytes each, mask=4).
 *
 * Variant of GuardedDispatch (mask=1) that tests bit 2 of
 * g_xformDirtyFlags instead of bit 0.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern void CallDualStoreXorBit(void);
extern void InstallSelfTri(void);
extern void FiveCallGuardSetTail(void);
extern void DirtyToggleByGate(void);
extern void ScaledClearJmp_EsiInstallBitCallChain(void);
extern void InstallSelfReentry(void);

/* @addr 0x00484b40 */
void GuardedDispatch4_00484b40(void) {
    CallDualStoreXorBit();
    if (g_framePauseFlag) return;
    if (!(g_xformDirtyFlags & 4)) {
        InstallSelfTri();
        return;
    }
    FiveCallGuardSetTail();
}

/* @addr 0x00489080 */
void GuardedDispatch4_00489080(void) {
    DirtyToggleByGate();
    if (g_framePauseFlag) return;
    if (!(g_xformDirtyFlags & 4)) {
        ScaledClearJmp_EsiInstallBitCallChain();
        return;
    }
    InstallSelfReentry();
}
