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
extern unsigned int g_currentNodeIdx;   /* 0x00542044 */
extern unsigned int g_xformEntityIdx;   /* 0x00542048 */

/* Table address externs - referenced only by `&` to force a
 * relocation; the linker fills the imm32 with the table's VA. */
extern unsigned int g_sceneInitBlob_005420f0;   /* 0x005420f0 */
extern unsigned int g_sceneInitBlob_004e56d8;   /* 0x004e56d8 */
extern unsigned int g_sceneInitBlob_004e7c90;   /* 0x004e7c90 */
extern unsigned int g_sceneInitBlob_004e7c48;   /* 0x004e7c48 */
extern unsigned int g_sceneInitBlob_00542ea8;   /* 0x00542ea8 */
extern unsigned int g_sceneInitBlob_00542ef8;   /* 0x00542ef8 */
extern unsigned int g_sceneInitBlob_00542e48;   /* 0x00542e48 */
extern unsigned int g_sceneInitBlob_00542d00;   /* 0x00542d00 */
extern unsigned int g_sceneInitBlob_00542fb0;   /* 0x00542fb0 */
extern unsigned int g_dispCfgBlob_004f1ba0;   /* 0x004f1ba0 */
extern unsigned int g_dispCfgBlob_004f1be8;   /* 0x004f1be8 */

/* Externs for jump targets. */
extern void Phase4SevenPackedDispatch(void);   /* 0x00417e40 */
extern void TwoStageSetupTripleCopy(void);   /* 0x00441e50 */
extern void TripleBlockChainScaledInits(void);   /* 0x00450f10 */
extern void MStackChainInstallDispatch(void);   /* 0x0048d500 */
extern void GuardedDirtyXformFromTable(void);   /* 0x0048f6d0 */
extern void GameModeHandlerCluster(void);   /* 0x004955d0 */

/* The wrappers. */
/* @addr 0x00417e20 */
void ScaledInit_Phase4SevenPackedDispatch_g_eventQueueTotal(void) {
    g_eventQueueTotal = (unsigned int)&g_sceneInitBlob_005420f0 >> 2;
    Phase4SevenPackedDispatch();
}

/* @addr 0x00441e10 */
void ScaledInit_TwoStageSetupTripleCopy_g_walkCallback_00441e10(void) {
    g_walkCallback = (void (*)(void))((unsigned int)&g_sceneInitBlob_004e56d8 >> 2);
    TwoStageSetupTripleCopy();
}

/* @addr 0x00441e30 */
void ScaledInit_TwoStageSetupTripleCopy_g_walkCallback_00441e30(void) {
    g_walkCallback = (void (*)(void))((unsigned int)&g_sceneInitBlob_004e56d8 >> 2);
    TwoStageSetupTripleCopy();
}

/* @addr 0x00450ed0 */
void ScaledInit_TripleBlockChainScaledInits_g_walkCallback_00450ed0(void) {
    g_walkCallback = (void (*)(void))((unsigned int)&g_sceneInitBlob_004e7c90 >> 2);
    TripleBlockChainScaledInits();
}

/* @addr 0x00450ef0 */
void ScaledInit_TripleBlockChainScaledInits_g_walkCallback_00450ef0(void) {
    g_walkCallback = (void (*)(void))((unsigned int)&g_sceneInitBlob_004e7c48 >> 2);
    TripleBlockChainScaledInits();
}

/* @addr 0x0048d430 */
void ScaledInit_MStackChainInstallDispatch_g_scaledInit_0048d430(void) {
    g_currentNodeIdx = (unsigned int)&g_sceneInitBlob_00542ea8 >> 2;
    MStackChainInstallDispatch();
}

/* @addr 0x0048d450 */
void ScaledInit_MStackChainInstallDispatch_g_scaledInit_0048d450(void) {
    g_currentNodeIdx = (unsigned int)&g_sceneInitBlob_00542ef8 >> 2;
    MStackChainInstallDispatch();
}

/* @addr 0x0048d470 */
void ScaledInit_MStackChainInstallDispatch_g_scaledInit_0048d470(void) {
    g_currentNodeIdx = (unsigned int)&g_sceneInitBlob_00542e48 >> 2;
    MStackChainInstallDispatch();
}

/* @addr 0x0048d490 */
void ScaledInit_MStackChainInstallDispatch_g_scaledInit_0048d490(void) {
    g_currentNodeIdx = (unsigned int)&g_sceneInitBlob_00542d00 >> 2;
    MStackChainInstallDispatch();
}

/* @addr 0x0048f720 */
void ScaledInit_GuardedDirtyXformFromTable_g_scaledInit(void) {
    g_currentNodeIdx = (unsigned int)&g_sceneInitBlob_00542fb0 >> 2;
    GuardedDirtyXformFromTable();
}

/* @addr 0x00495590 */
void ScaledInit_GameModeHandlerCluster_g_scaledInit_00495590(void) {
    g_xformEntityIdx = (unsigned int)&g_dispCfgBlob_004f1ba0 >> 2;
    GameModeHandlerCluster();
}

/* @addr 0x004955b0 */
void ScaledInit_GameModeHandlerCluster_g_scaledInit_004955b0(void) {
    g_xformEntityIdx = (unsigned int)&g_dispCfgBlob_004f1be8 >> 2;
    GameModeHandlerCluster();
}
