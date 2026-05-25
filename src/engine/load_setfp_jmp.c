/**
 * 5 "load+set-callback+store+tail-jmp" wrappers (25b).
 */
#include "engine/scenegraph.h"

extern unsigned int g_bootChainPair1_00541e84;   /* 0x00541e84 */
extern unsigned int g_data_00541e88;   /* 0x00541e88 */
extern unsigned int g_data_00541e8c;   /* 0x00541e8c */
extern unsigned int g_lit_00541e90;   /* 0x00541e90 */
extern unsigned int g_data_00541e98;   /* 0x00541e98 */

extern void ScaledOr4DirtyClear_00409320(void);   /* 0x00409320 */
extern void Helper_TickAlt(void);   /* 0x004bae90 */

/* @addr 0x00409380 */
void LoadSetFpJmp_00409380(void) {
    unsigned int v = g_data_00541e8c;
    g_walkCallback = ScaledOr4DirtyClear_00409320;
    g_currentNodeIdx = v;
    Helper_TickAlt();
}

/* @addr 0x004093a0 */
void LoadSetFpJmp_004093a0(void) {
    unsigned int v = g_data_00541e88;
    g_walkCallback = ScaledOr4DirtyClear_00409320;
    g_currentNodeIdx = v;
    Helper_TickAlt();
}

/* @addr 0x004093c0 */
void LoadSetFpJmp_004093c0(void) {
    unsigned int v = g_bootChainPair1_00541e84;
    g_walkCallback = ScaledOr4DirtyClear_00409320;
    g_currentNodeIdx = v;
    Helper_TickAlt();
}

/* @addr 0x004093e0 */
void LoadSetFpJmp_004093e0(void) {
    unsigned int v = g_lit_00541e90;
    g_walkCallback = ScaledOr4DirtyClear_00409320;
    g_currentNodeIdx = v;
    Helper_TickAlt();
}

/* @addr 0x00409400 */
void LoadSetFpJmp_00409400(void) {
    unsigned int v = g_data_00541e98;
    g_walkCallback = ScaledOr4DirtyClear_00409320;
    g_currentNodeIdx = v;
    Helper_TickAlt();
}

