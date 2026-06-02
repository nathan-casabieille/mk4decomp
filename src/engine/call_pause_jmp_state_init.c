/**
 * Auto-split from misc_matchesOO.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_scaledInit_00542044;
extern unsigned int g_phaseTimer;

/* @addr 0x004370e0 (20b): call LeaPlus22StoreSelf; if !pause tail-jmp
 * CjInstallSelfRouter. Entry A of the original 84-byte packed block; entry B
 * (at +0x20) lives in func_LeaPlus22StoreSelf_then_MstackPopScaledChainPlusThunks. The 12-byte nop gap is filled
 * by 0x90-fill. */
extern void LeaPlus22StoreSelf(void);
extern void CjInstallSelfRouter(void);
extern void DualCallPauseJmpDual(void);
extern void MstackPopScaledChainPlusThunks(void);
void CallPauseJmpStateInit(void) {
    LeaPlus22StoreSelf();
    if (g_framePauseFlag != 0) return;
    CjInstallSelfRouter();
}
