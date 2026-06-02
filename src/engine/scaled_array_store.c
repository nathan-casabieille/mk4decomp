/**
 * "scaled-base array store + tail-jmp" wrappers (23b).
 * Pattern:
 *   mov eax, [g_idx];
 *   mov ecx, [g_value];
 *   mov [eax*4 + DISP], ecx;
 *   jmp Target;
 */
#include "engine/scenegraph.h"


extern void GuardedSeq_CopyJmp_then_MStackPushDualJmp(void);   /* 0x00428350 */
extern void CallDualStoreXorBit(void);   /* 0x004285e0 */
extern void ScaledChainJmp_00429470(void);   /* 0x00429470 */
extern void EsiInstallBitCallChain_00429530(void);   /* 0x00429530 */
extern void EsiInstallBitCallChain_00429610(void);   /* 0x00429610 */
extern void ScaledChainJmp_004298e0(void);   /* 0x004298e0 */
extern void SetJmp_ScaledArrStore(void);   /* 0x00429950 */
extern void ScaledArrStore_GuardedChainCmpDualBitXor_00429960(void);   /* 0x00429960 */
extern void GuardedChainCmpDualBitXor(void);   /* 0x004299a0 */

/* @addr 0x00428330 - g_X[idx*4 + 0x28] = g_Y; jmp T */
void ScaledArrStore_GuardedSeq_CopyJmp_then_MStackPushDualJmp(void) {
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_idx = (unsigned int)g_walkCallback;
    GuardedSeq_CopyJmp_then_MStackPushDualJmp();
}

/* @addr 0x004285c0 - g_X[idx*4 + 0x24] = g_Y; jmp T */
void ScaledArrStore_CallDualStoreXorBit(void) {
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_end = (unsigned int)g_eventQueueIdx;
    CallDualStoreXorBit();
}

/* @addr 0x00428e70 - g_X[idx*4 + 0x28] = g_Y; jmp T */
void ScaledArrStore_EsiInstallBitCallChain_00428e70(void) {
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_idx = (unsigned int)g_eventQueueCurrent;
    EsiInstallBitCallChain_00429530();
}

/* @addr 0x004293b0 - g_X[idx*4 + 0x28] = g_Y; jmp T */
void ScaledArrStore_EsiInstallBitCallChain_004293b0(void) {
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_idx = (unsigned int)g_walkCallback;
    EsiInstallBitCallChain_00429610();
}

/* @addr 0x00429450 - g_X[idx*4 + 0x24] = g_Y; jmp T */
void ScaledArrStore_ScaledChainJmp_00429450(void) {
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_end = (unsigned int)g_xformEntityIdx;
    ScaledChainJmp_00429470();
}

/* @addr 0x004298c0 - g_X[idx*4 + 0x24] = g_Y; jmp T */
void ScaledArrStore_ScaledChainJmp_004298c0(void) {
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_end = (unsigned int)g_xformEntityIdx;
    ScaledChainJmp_004298e0();
}

/* @addr 0x00429910 - g_X[idx*4 + 0x24] = g_Y; jmp T */
void ScaledArrStore_ScaledArrStore(void) {
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_end = (unsigned int)g_xformEntityIdx;
    ScaledArrStore_GuardedChainCmpDualBitXor_00429960();
}

/* @addr 0x00429930 - g_X[idx*4 + 0x24] = g_Y; jmp T */
void ScaledArrStore_SetJmp_ScaledArrStore(void) {
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_end = (unsigned int)g_xformEntityIdx;
    SetJmp_ScaledArrStore();
}

/* @addr 0x00429960 - g_X[idx*4 + 0x28] = g_Y; jmp T */
void ScaledArrStore_GuardedChainCmpDualBitXor_00429960(void) {
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_idx = (unsigned int)g_walkCallback;
    GuardedChainCmpDualBitXor();
}

/* @addr 0x00429980 - g_X[idx*4 + 0x28] = g_Y; jmp T */
void ScaledArrStore_GuardedChainCmpDualBitXor_00429980(void) {
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_idx = (unsigned int)g_eventQueueChild;
    GuardedChainCmpDualBitXor();
}

