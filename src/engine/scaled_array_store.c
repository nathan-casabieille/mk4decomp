/**
 * "scaled-base array store + tail-jmp" wrappers (23b).
 * Pattern:
 *   mov eax, [g_idx];
 *   mov ecx, [g_value];
 *   mov [eax*4 + DISP], ecx;
 *   jmp Target;
 */
#include "engine/scenegraph.h"


extern void GuardedSeq_00428350(void);   /* 0x00428350 */
extern void CallDualStoreXorBit_004285e0(void);   /* 0x004285e0 */
extern void ScaledChainJmp_00429470(void);   /* 0x00429470 */
extern void EsiInstallBitCallChain_00429530(void);   /* 0x00429530 */
extern void EsiInstallBitCallChain_00429610(void);   /* 0x00429610 */
extern void ScaledChainJmp_004298e0(void);   /* 0x004298e0 */
extern void SetJmp_00429950(void);   /* 0x00429950 */
extern void ScaledArrStore_00429960(void);   /* 0x00429960 */
extern void GuardedChainCmpDualBitXor_004299a0(void);   /* 0x004299a0 */

/* @addr 0x00428330 - g_X[idx*4 + 0x28] = g_Y; jmp T */
void ScaledArrStore_00428330(void) {
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_idx = (unsigned int)g_walkCallback;
    GuardedSeq_00428350();
}

/* @addr 0x004285c0 - g_X[idx*4 + 0x24] = g_Y; jmp T */
void ScaledArrStore_004285c0(void) {
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_end = (unsigned int)g_eventQueueIdx;
    CallDualStoreXorBit_004285e0();
}

/* @addr 0x00428e70 - g_X[idx*4 + 0x28] = g_Y; jmp T */
void ScaledArrStore_00428e70(void) {
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_idx = (unsigned int)g_eventQueueCurrent;
    EsiInstallBitCallChain_00429530();
}

/* @addr 0x004293b0 - g_X[idx*4 + 0x28] = g_Y; jmp T */
void ScaledArrStore_004293b0(void) {
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_idx = (unsigned int)g_walkCallback;
    EsiInstallBitCallChain_00429610();
}

/* @addr 0x00429450 - g_X[idx*4 + 0x24] = g_Y; jmp T */
void ScaledArrStore_00429450(void) {
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_end = (unsigned int)g_xformEntityIdx;
    ScaledChainJmp_00429470();
}

/* @addr 0x004298c0 - g_X[idx*4 + 0x24] = g_Y; jmp T */
void ScaledArrStore_004298c0(void) {
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_end = (unsigned int)g_xformEntityIdx;
    ScaledChainJmp_004298e0();
}

/* @addr 0x00429910 - g_X[idx*4 + 0x24] = g_Y; jmp T */
void ScaledArrStore_00429910(void) {
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_end = (unsigned int)g_xformEntityIdx;
    ScaledArrStore_00429960();
}

/* @addr 0x00429930 - g_X[idx*4 + 0x24] = g_Y; jmp T */
void ScaledArrStore_00429930(void) {
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_end = (unsigned int)g_xformEntityIdx;
    SetJmp_00429950();
}

/* @addr 0x00429960 - g_X[idx*4 + 0x28] = g_Y; jmp T */
void ScaledArrStore_00429960(void) {
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_idx = (unsigned int)g_walkCallback;
    GuardedChainCmpDualBitXor_004299a0();
}

/* @addr 0x00429980 - g_X[idx*4 + 0x28] = g_Y; jmp T */
void ScaledArrStore_00429980(void) {
    ((ScenegraphNode *)(g_fightGroupHead * 4))->queue_idx = (unsigned int)g_eventQueueChild;
    GuardedChainCmpDualBitXor_004299a0();
}

