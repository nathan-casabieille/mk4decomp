/**
 * 3 "conditional player-table lookup" helpers (38 bytes each).
 *
 * Pattern:
 *   mov eax, [g_primary]
 *   mov ecx, [g_fightGroupHead]
 *   mov [g_dest], eax
 *   mov eax, [g_player1NodeIdx]
 *   cmp ecx, eax                  ; same group as player1?
 *   je  skip
 *   mov edx, [g_secondary]        ; else override with secondary
 *   mov [g_dest], edx
 * skip:
 *   ret
 *
 * Installs primary into the destination slot, then if the current
 * fight-group is not the player1 group, swaps in a secondary value.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_primary_0053a774;   /* 0x0053a774 */
extern unsigned int g_secondary_00535d04; /* 0x00535d04 */
extern unsigned int g_primary_0052d74c;   /* 0x0052d74c */
extern unsigned int g_secondary_00538068; /* 0x00538068 */
extern unsigned int g_scaledInit_00542044;

/* @addr 0x0048f270 */
void CondPlayerLookup_0048f270(void) {
    g_walkCallback = (void(*)(void))g_primary_0053a774;
    if (g_fightGroupHead != g_player1NodeIdx) {
        g_walkCallback = (void(*)(void))g_secondary_00535d04;
    }
}

/* @addr 0x0048f950 */
void CondPlayerLookup_0048f950(void) {
    g_walkCallback = (void(*)(void))g_primary_0052d74c;
    if (g_fightGroupHead != g_player1NodeIdx) {
        g_walkCallback = (void(*)(void))g_secondary_00538068;
    }
}

/* @addr 0x004ac120 */
void CondPlayerLookup_004ac120(void) {
    g_scaledInit_00542044 = g_gtPlayerProbe2;
    if (g_fightGroupHead != g_player1NodeIdx) {
        g_scaledInit_00542044 = g_gtPlayerProbe1;
    }
}
