/**
 * 12 "scaled-base init + tail-jmp" wrappers.
 *
 * Pattern:
 *   mov eax, ADDR_OF_TABLE     ; b8 + imm32  (5 bytes)
 *   shr eax, 2                  ; c1 e8 02     (3 bytes)
 *   mov [g_scaledBase], eax     ; a3 + reloc   (5 bytes)
 *   jmp Target                  ; e9 + reloc   (5 bytes)
 *
 * Each helper primes a per-table scaled-base global (the
 * `addr/4` form used by the `[reg*4 + 0]` SIB+disp32=0
 * addressing trick) and tail-calls into the actual handler.
 *
 * The shift can't be constant-folded because `&table` is a
 * link-time relocation, so MSVC SP3 /O2 emits the runtime
 * `mov reg, OFFSET table; shr reg, 2; mov [g], reg` sequence;
 * the trailing void call tail-call-optimizes to `jmp`.
 */
#include "engine/scenegraph.h"

/* New globals. */
extern unsigned int g_scaledInit_00542044;   /* 0x00542044 */
extern unsigned int g_scaledInit_00542048;   /* 0x00542048 */

/* Table address externs - referenced only by `&` to force a
 * relocation; the linker fills the imm32 with the table's VA. */
extern unsigned int g_table_005420f0;   /* 0x005420f0 */
extern unsigned int g_table_004e56d8;   /* 0x004e56d8 */
extern unsigned int g_table_004e7c90;   /* 0x004e7c90 */
extern unsigned int g_table_004e7c48;   /* 0x004e7c48 */
extern unsigned int g_table_00542ea8;   /* 0x00542ea8 */
extern unsigned int g_table_00542ef8;   /* 0x00542ef8 */
extern unsigned int g_table_00542e48;   /* 0x00542e48 */
extern unsigned int g_table_00542d00;   /* 0x00542d00 */
extern unsigned int g_table_00542fb0;   /* 0x00542fb0 */
extern unsigned int g_table_004f1ba0;   /* 0x004f1ba0 */
extern unsigned int g_table_004f1be8;   /* 0x004f1be8 */

/* Externs for jump targets. */
extern void Phase4SevenPackedDispatch_00417e40(void);   /* 0x00417e40 */
extern void TwoStageSetupTripleCopy_00441e50(void);   /* 0x00441e50 */
extern void TripleBlockChainScaledInits_00450f10(void);   /* 0x00450f10 */
extern void MStackChainInstallDispatch_0048d500(void);   /* 0x0048d500 */
extern void GuardedDirtyXformFromTable_0048f6d0(void);   /* 0x0048f6d0 */
extern void GameModeHandlerCluster_004955d0(void);   /* 0x004955d0 */

/* The wrappers. */
/* @addr 0x00417e20 */
void ScaledInit_00417e20(void) {
    g_eventQueueTotal = (unsigned int)&g_table_005420f0 >> 2;
    Phase4SevenPackedDispatch_00417e40();
}

/* @addr 0x00441e10 */
void ScaledInit_00441e10(void) {
    g_walkCallback = (void (*)(void))((unsigned int)&g_table_004e56d8 >> 2);
    TwoStageSetupTripleCopy_00441e50();
}

/* @addr 0x00441e30 */
void ScaledInit_00441e30(void) {
    g_walkCallback = (void (*)(void))((unsigned int)&g_table_004e56d8 >> 2);
    TwoStageSetupTripleCopy_00441e50();
}

/* @addr 0x00450ed0 */
void ScaledInit_00450ed0(void) {
    g_walkCallback = (void (*)(void))((unsigned int)&g_table_004e7c90 >> 2);
    TripleBlockChainScaledInits_00450f10();
}

/* @addr 0x00450ef0 */
void ScaledInit_00450ef0(void) {
    g_walkCallback = (void (*)(void))((unsigned int)&g_table_004e7c48 >> 2);
    TripleBlockChainScaledInits_00450f10();
}

/* @addr 0x0048d430 */
void ScaledInit_0048d430(void) {
    g_scaledInit_00542044 = (unsigned int)&g_table_00542ea8 >> 2;
    MStackChainInstallDispatch_0048d500();
}

/* @addr 0x0048d450 */
void ScaledInit_0048d450(void) {
    g_scaledInit_00542044 = (unsigned int)&g_table_00542ef8 >> 2;
    MStackChainInstallDispatch_0048d500();
}

/* @addr 0x0048d470 */
void ScaledInit_0048d470(void) {
    g_scaledInit_00542044 = (unsigned int)&g_table_00542e48 >> 2;
    MStackChainInstallDispatch_0048d500();
}

/* @addr 0x0048d490 */
void ScaledInit_0048d490(void) {
    g_scaledInit_00542044 = (unsigned int)&g_table_00542d00 >> 2;
    MStackChainInstallDispatch_0048d500();
}

/* @addr 0x0048f720 */
void ScaledInit_0048f720(void) {
    g_scaledInit_00542044 = (unsigned int)&g_table_00542fb0 >> 2;
    GuardedDirtyXformFromTable_0048f6d0();
}

/* @addr 0x00495590 */
void ScaledInit_00495590(void) {
    g_scaledInit_00542048 = (unsigned int)&g_table_004f1ba0 >> 2;
    GameModeHandlerCluster_004955d0();
}

/* @addr 0x004955b0 */
void ScaledInit_004955b0(void) {
    g_scaledInit_00542048 = (unsigned int)&g_table_004f1be8 >> 2;
    GameModeHandlerCluster_004955d0();
}
