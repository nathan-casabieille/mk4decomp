/**
 * Auto-split from misc_matchesI.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;

/* @addr 0x00473450 (44b)
 *   mov     eax, [g_fightGroupHead]
 *   mov     eax, [eax*4 + 0x18]
 *   test    eax, eax
 *   mov     [g_walkCallback], eax
 *   jne     +0x0d
 *   mov     eax, [g_xformDirtyFlags]
 *   and     al, 0xfe
 *   mov     [g_xformDirtyFlags], eax
 *   ret
 *   mov     [g_currentNodeIdx], eax
 *   jmp     +4
 */
extern void SizeGateInstallSelfThenSubMul10(void);
void ScaledLoadDirtyOrSetJmp(void) {
    unsigned int v = ((ScenegraphNode *)(g_fightGroupHead * 4))->child_chain;
    g_walkCallback = (void (*)(void))v;
    if (v == 0) {
        g_xformDirtyFlags = g_xformDirtyFlags & 0xfffffffeu;
        return;
    }
    g_currentNodeIdx = v;
    SizeGateInstallSelfThenSubMul10();
}
