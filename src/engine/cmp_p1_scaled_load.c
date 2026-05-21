/**
 * Compare-player1 + scaled-load sister wrappers.
 *
 * Two paired functions reading the active player's scaled-init field
 * (offset +0x74 or +0x7c) into g_walkCallback, with player1/player2
 * probe selection based on whether g_fightGroupHead matches player1.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_scaledInit_00542044;

/* @addr 0x0045f5d0 (50b)
 *   mov     ecx, [g_fightGroupHead]
 *   mov     edx, [g_player1NodeIdx]
 *   mov     eax, [g_gtPlayerProbe2]
 *   cmp     ecx, edx
 *   mov     [g_scaledInit_00542044], eax
 *   je      +0x0a
 *   mov     eax, [g_gtPlayerProbe1]
 *   mov     [g_scaledInit_00542044], eax
 *   mov     edx, [eax*4 + 0x74]
 *   mov     [g_walkCallback], edx
 *   ret
 */
void CmpP1ScaledLoad74_0045f5d0(void) {
    unsigned int v = g_gtPlayerProbe2;
    g_scaledInit_00542044 = v;
    if (g_fightGroupHead != g_player1NodeIdx) {
        v = g_gtPlayerProbe1;
        g_scaledInit_00542044 = v;
    }
    g_walkCallback = (void (*)(void))*(unsigned int *)(v * 4 + 0x74);
}

/* @addr 0x0045f610 (50b): same shape with offset 0x7c */
void CmpP1ScaledLoad7c_0045f610(void) {
    unsigned int v = g_gtPlayerProbe2;
    g_scaledInit_00542044 = v;
    if (g_fightGroupHead != g_player1NodeIdx) {
        v = g_gtPlayerProbe1;
        g_scaledInit_00542044 = v;
    }
    g_walkCallback = (void (*)(void))*(unsigned int *)(v * 4 + 0x7c);
}
