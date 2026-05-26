/**
 * Auto-split from misc_matchesOO.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_phaseTimer_00537e94;

/* @addr 0x004370e0 (20b): call LeaPlus22StoreSelf; if !pause tail-jmp
 * CjInstallSelfRouter_00470480. Entry A of the original 84-byte packed block; entry B
 * (at +0x20) lives in func_00437100. The 12-byte nop gap is filled
 * by 0x90-fill. */
extern void LeaPlus22StoreSelf_0048e4d0(void);
extern void CjInstallSelfRouter_00470480(void);
extern void DualCallPauseJmpDual_00439190(void);
extern void MstackPopScaledChainPlusThunks_00471250(void);
void CallPauseJmpStateInit_004370e0(void) {
    LeaPlus22StoreSelf_0048e4d0();
    if (g_framePauseFlag != 0) return;
    CjInstallSelfRouter_00470480();
}
