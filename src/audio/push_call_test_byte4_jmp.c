/**
 * Auto-split from misc_matchesBB.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;

/* @addr 0x004a1a10 (55b)
 *   push 0x25a; call F; load dirty al; add esp; test al,4;
 *   jz +5 → jmp T1; load g_scaledInit → ecx; mov eax,0xfffb0000;
 *   store walk and [ecx*4 + 0x6c]; jmp T2.
 */
extern void SaveCallRestoreOrXor_00404a00(int);
extern void func_0041f780_bb(void);
extern void InstallSelfPauseGate_004a1a50(void);
void PushCallTestByte4Jmp_004a1a10(void) {
    SaveCallRestoreOrXor_00404a00(0x25a);
    if ((g_xformDirtyFlags & 4) != 0) {
        func_0041f780_bb();
        return;
    }
    g_walkCallback = (void (*)(void))0xfffb0000;
    *(unsigned int *)(g_scaledInit_00542044 * 4 + 0x6c) = 0xfffb0000;
    InstallSelfPauseGate_004a1a50();
}
