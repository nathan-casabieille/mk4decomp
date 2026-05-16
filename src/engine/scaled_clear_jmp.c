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

extern void InstallSelf3WayChainCmp_00428d80(void);
extern void EsiInstallBitCallChain_00429530(void);
extern void InstallSelfBitGated_00428eb0(void);

/* @addr 0x00428d40 */
void ScaledClearJmp_00428d40(void) {
    g_walkCallback = (void (*)(void))0;
    *(unsigned int *)(g_fightGroupHead * 4 + 0x28) = 0;
    InstallSelf3WayChainCmp_00428d80();
}

/* @addr 0x00428d60 */
void ScaledClearJmp_00428d60(void) {
    g_walkCallback = (void (*)(void))0;
    *(unsigned int *)(g_fightGroupHead * 4 + 0x28) = 0;
    EsiInstallBitCallChain_00429530();
}

/* @addr 0x00428e90 */
void ScaledClearJmp_00428e90(void) {
    g_walkCallback = (void (*)(void))0;
    *(unsigned int *)(g_fightGroupHead * 4 + 0x28) = 0;
    InstallSelfBitGated_00428eb0();
}
