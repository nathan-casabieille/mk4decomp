/**
 * 2 "triple install + tail-jmp" helpers (39 bytes each).
 *
 * Pattern:
 *   mov     eax, [g_A]
 *   mov     ecx, [g_B]
 *   mov     edx, [g_C]
 *   mov     [g_scaledInit_00542044], eax
 *   mov     [g_pendingNodeType], ecx
 *   mov     [g_scaledInit_00542048], edx
 *   jmp     Tail
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_scaledInit_00542048;
extern unsigned int g_extra_00535e68;
extern unsigned int g_extra_0053a280;

extern void ChainWalkSelfRecursive_0045daf0(void);

/* @addr 0x0045da80 */
void TripleInstallJmp_0045da80(void) {
    unsigned int a = g_gtPlayerProbe2;
    unsigned int b = g_player1NodeIdx;
    unsigned int c = g_extra_00535e68;
    g_scaledInit_00542044 = a;
    g_pendingNodeType = b;
    g_scaledInit_00542048 = c;
    ChainWalkSelfRecursive_0045daf0();
}

/* @addr 0x0045dab0 */
void TripleInstallJmp_0045dab0(void) {
    unsigned int a = g_gtPlayerProbe1;
    unsigned int b = g_player2NodeIdx;
    unsigned int c = g_extra_0053a280;
    g_scaledInit_00542044 = a;
    g_pendingNodeType = b;
    g_scaledInit_00542048 = c;
    ChainWalkSelfRecursive_0045daf0();
}
