/**
 * 5 "load+set-callback+store+tail-jmp" wrappers (25b).
 */
#include "engine/scenegraph.h"

extern unsigned int g_bootChainPair1;   /* 0x00541e84 */
extern unsigned int g_bootChainScaled1;   /* 0x00541e88 */
extern unsigned int g_bootChainScaled2;   /* 0x00541e8c */
extern unsigned int g_lit_00541e90;   /* 0x00541e90 */
extern unsigned int g_bootChainState3;   /* 0x00541e98 */

extern void ScaledOr4DirtyClear(void);   /* 0x00409320 */
extern void Helper_TickAlt(void);   /* 0x004bae90 */

/* @addr 0x00409380 */
void LoadSetFpJmp_g_bootChainScaled2(void) {
    unsigned int v = g_bootChainScaled2;
    g_walkCallback = ScaledOr4DirtyClear;
    g_currentNodeIdx = v;
    Helper_TickAlt();
}

/* @addr 0x004093a0 */
void LoadSetFpJmp_g_bootChainScaled1(void) {
    unsigned int v = g_bootChainScaled1;
    g_walkCallback = ScaledOr4DirtyClear;
    g_currentNodeIdx = v;
    Helper_TickAlt();
}

/* @addr 0x004093c0 */
void LoadSetFpJmp_g_bootChainPair1(void) {
    unsigned int v = g_bootChainPair1;
    g_walkCallback = ScaledOr4DirtyClear;
    g_currentNodeIdx = v;
    Helper_TickAlt();
}

/* @addr 0x004093e0 */
void LoadSetFpJmp_g_lit_00541e90(void) {
    unsigned int v = g_lit_00541e90;
    g_walkCallback = ScaledOr4DirtyClear;
    g_currentNodeIdx = v;
    Helper_TickAlt();
}

/* @addr 0x00409400 */
void LoadSetFpJmp_g_bootChainState3(void) {
    unsigned int v = g_bootChainState3;
    g_walkCallback = ScaledOr4DirtyClear;
    g_currentNodeIdx = v;
    Helper_TickAlt();
}

