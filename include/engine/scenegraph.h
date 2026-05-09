/**
 * Scene graph — dynamic node tree, transform stack, render walker.
 *
 * The engine maintains a hierarchical scene graph of up to 63
 * dynamically-allocated nodes (each 232 bytes), plus static fixed
 * indices for the boot-time entities (HUD, players, etc.).
 *
 * Each node has a type/mode flag word at +0x20 that selects one of
 * 9 transform handlers in g_nodeDispatchTable. The render walker
 * (RenderSceneNode) recurses through children, applying each
 * handler to update the transform stack.
 *
 * See analysis/notes/architecture.md for the full description.
 */
#ifndef MK4_ENGINE_SCENEGRAPH_H
#define MK4_ENGINE_SCENEGRAPH_H

#include "../types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define NODE_SIZE_BYTES   0xE8       /* 232 bytes per node */
#define NODE_POOL_COUNT   63
#define NODE_DISPATCH_SIZE 16

/* Node descriptor offsets (within the 232-byte struct). */
#define NODE_OFF_TYPE     0x00
#define NODE_OFF_FLAGS    0x20       /* type bits 24-26, mode bit 8 */
#define NODE_OFF_PLAYER   0x30       /* player_id (1..4) */
#define NODE_OFF_STATE    0x34
#define NODE_OFF_POS_Y    0x58
#define NODE_OFF_FSM      0x74       /* state-machine value */
#define NODE_OFF_MAGIC    0xD4       /* 0x12345678 sanity tag */
#define NODE_OFF_NEXT     0xE4       /* linked list next ptr */

/* Magic value at NODE_OFF_MAGIC for live nodes. */
#define NODE_LIVE_MAGIC   0x12345678

/* === Allocator ============================================== */

void *AllocateNode(u32 type);                            /* 0x0041f290 */
void *AllocNode(void);                                   /* 0x0049cb60 — 15-byte wrapper */

/* === Walker / dispatch ====================================== */

/* Recursive scene-graph walker. Reads the current node's flags,
 * dispatches to one of 9 transform handlers, then recurses. */
void RenderSceneNode(void);                              /* 0x004ba720 */

/* Walks sibling linked list invoking the callback in DAT_0054206c
 * on each node. */
void WalkSceneGraphSiblings(void);                       /* 0x004ba130 */

/* Per-frame entity update orchestrator (calls WalkSceneGraphSiblings
 * 6 times across logical subtrees with the LAB_004ba1c0 callback). */
void TickAllEntities(void);                              /* 0x004b9e50 */

/* === Transform handlers (16-entry dispatch table) ============ */

void NodeApplyTransform_A(void);                         /* 0x004bdb50 */
void NodeApplyTransform_B(void);                         /* 0x004bdca0 */
void NodeApplyTransform_C(void);                         /* 0x004bde90 */
void NodeApplyTransform_C_Inverse(void);                 /* 0x004bdfb0 */
void NodeApplyTransform_A_Direct(void);                  /* 0x004bdc00 */
void NodeApplyTransform_B_Direct(void);                  /* 0x004bdd50 */
void NodeApplyTransform_C_Direct(void);                  /* 0x004bdf40 */
void NodeApplyTransform_B_Swapped(void);                 /* 0x004be130 */
void NodeApplyMatrix(void);                              /* 0x004be050 */

/* === Rotation matrix builders ================================ */

void BuildRotMatrix_OrderA(s16 *angles, s16 *mat3x3);    /* 0x004b3800 */
void BuildRotMatrix_OrderB(s16 *angles, s16 *mat3x3);    /* 0x004b3940 */
void BuildRotMatrix_OrderC(s16 *angles, s16 *mat3x3);    /* 0x004b36c0 */

/* 4096-entry sine LUT (BAM-indexed; 0x1000 = 2π). */
extern const s32 g_sinTable[4096];                       /* 0x007b01a0 */

/* 16-entry function-pointer dispatch table. */
typedef void (*NodeHandlerFn)(void);
extern NodeHandlerFn g_nodeDispatchTable[NODE_DISPATCH_SIZE];  /* 0x004f7888 */

/* Current node iteration state (used by walkers + handlers). */
extern packed_ptr g_currentNodeIdx;                      /* 0x00542044 */
extern u32        g_currentNodeFlags;                    /* 0x00542084 */

#ifdef __cplusplus
}
#endif

#endif /* MK4_ENGINE_SCENEGRAPH_H */
