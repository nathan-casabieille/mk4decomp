/**
 * 2 "triple install + tail-jmp" helpers (39 bytes each).
 *
 * Pattern:
 *   mov     eax, [g_A]
 *   mov     ecx, [g_B]
 *   mov     edx, [g_C]
 *   mov     [g_currentNodeIdx], eax
 *   mov     [g_pendingNodeType], ecx
 *   mov     [g_xformEntityIdx], edx
 *   jmp     Tail
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_currentNodeIdx;
extern unsigned int g_xformEntityIdx;
extern unsigned int g_extra_00535e68;
extern unsigned int g_extra_0053a280;

extern void ChainWalkSelfRecursive(void);

/* @addr 0x0045da80 */
void TripleInstallJmp_0045da80(void) {
    unsigned int a = g_gtPlayerProbe2;
    unsigned int b = g_player1NodeIdx;
    unsigned int c = g_extra_00535e68;
    g_currentNodeIdx = a;
    g_pendingNodeType = b;
    g_xformEntityIdx = c;
    ChainWalkSelfRecursive();
}

/* @addr 0x0045dab0 */
void TripleInstallJmp_0045dab0(void) {
    unsigned int a = g_gtPlayerProbe1;
    unsigned int b = g_player2NodeIdx;
    unsigned int c = g_extra_0053a280;
    g_currentNodeIdx = a;
    g_pendingNodeType = b;
    g_xformEntityIdx = c;
    ChainWalkSelfRecursive();
}
