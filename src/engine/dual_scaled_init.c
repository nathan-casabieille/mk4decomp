/**
 * 4 "dual scaled-base init + tail-jmp" wrappers.
 *
 * Pattern (32 bytes):
 *   mov eax, ADDR_A
 *   mov ecx, ADDR_B
 *   shr eax, 2
 *   shr ecx, 2
 *   mov [g_scaledInit_00542044], eax
 *   mov [g_scaledInit_00542048], ecx
 *   jmp Target
 *
 * All four prime the same pair of scaled-base globals (0x00542044
 * and 0x00542048) with different table addresses, then tail-jmp
 * into the same handler at 0x0045d960. MSVC SP3 /O2's scheduler
 * interleaves the two independent `addr >> 2` chains naturally
 * (load both, shift both, store both), matching the orig layout.
 */
#include "engine/scenegraph.h"

extern unsigned int g_scaledInit_00542044;
extern unsigned int g_scaledInit_00542048;
extern void DualSwapTwoCallsJmp_0045d960(void);

/* Table-base externs - &-references defeat constant-folding of `>> 2`. */
extern unsigned int g_table_0052ab18;   /* 0x0052ab18 */
extern unsigned int g_table_0053a2a0;   /* 0x0053a2a0 */
extern unsigned int g_table_0053a330;   /* 0x0053a330 */
extern unsigned int g_table_0053a258;   /* 0x0053a258 */
extern unsigned int g_table_00541e00;   /* 0x00541e00 */
extern unsigned int g_table_0053a2f8;   /* 0x0053a2f8 */
extern unsigned int g_table_0053a750;   /* 0x0053a750 */
extern unsigned int g_table_00538048;   /* 0x00538048 */

/* @addr 0x0045d8e0 */
void DualScaledInit_0045d8e0(void) {
    g_scaledInit_00542044 = (unsigned int)&g_table_0052ab18 >> 2;
    g_scaledInit_00542048 = (unsigned int)&g_table_0053a2a0 >> 2;
    DualSwapTwoCallsJmp_0045d960();
}

/* @addr 0x0045d900 */
void DualScaledInit_0045d900(void) {
    g_scaledInit_00542044 = (unsigned int)&g_table_0053a330 >> 2;
    g_scaledInit_00542048 = (unsigned int)&g_table_0053a258 >> 2;
    DualSwapTwoCallsJmp_0045d960();
}

/* @addr 0x0045d920 */
void DualScaledInit_0045d920(void) {
    g_scaledInit_00542044 = (unsigned int)&g_table_00541e00 >> 2;
    g_scaledInit_00542048 = (unsigned int)&g_table_0053a2f8 >> 2;
    DualSwapTwoCallsJmp_0045d960();
}

/* @addr 0x0045d940 */
void DualScaledInit_0045d940(void) {
    g_scaledInit_00542044 = (unsigned int)&g_table_0053a750 >> 2;
    g_scaledInit_00542048 = (unsigned int)&g_table_00538048 >> 2;
    DualSwapTwoCallsJmp_0045d960();
}
