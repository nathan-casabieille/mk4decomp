/**
 * 3 "scaled-clear + tail-jmp" wrappers (25 bytes each).
 *
 * Pattern:
 *   mov     ecx, [g_fightGroupHead]
 *   xor     eax, eax
 *   mov     [g_walkCallback], eax
 *   mov     [ecx*4 + 0x28], eax       ; clear fight-group member 0x28
 *   jmp     Target
 *
 * Inverse of ScaledLoadJmp: zeros both the global callback slot and
 * the per-fight-group slot at offset 0x28, then tail-jumps into the
 * dispatch handler.
 */
#include "engine/scenegraph.h"

extern void InstallSelf3WayChainCmp(void);
extern void EsiInstallBitCallChain_CopyJmp_GuardedChainPushSetCallPop_g_currentNodeIdx_00429530(void);
extern void InstallSelfBitGated(void);

/* @addr 0x00428d40 */
void ScaledClearJmp_InstallSelf3WayChainCmp(void) {
    g_walkCallback = (void (*)(void))0;
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_idx = 0;
    InstallSelf3WayChainCmp();
}

/* @addr 0x00428d60 */
void ScaledClearJmp_EsiInstallBitCallChain(void) {
    g_walkCallback = (void (*)(void))0;
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_idx = 0;
    EsiInstallBitCallChain_CopyJmp_GuardedChainPushSetCallPop_g_currentNodeIdx_00429530();
}

/* @addr 0x00428e90 */
void ScaledClearJmp_InstallSelfBitGated(void) {
    g_walkCallback = (void (*)(void))0;
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_idx = 0;
    InstallSelfBitGated();
}
