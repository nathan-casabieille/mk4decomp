/**
 * Scene graph - dynamic node tree, transform stack, render walker.
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
void *AllocNode(void);                                   /* 0x0049cb60 - 15-byte wrapper */

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

/* Cached "type for the next allocation" - the AllocNode() wrapper
 * forwards this to AllocateNode() so callers don't need to repeat
 * the type argument when they're in a tight loop allocating many
 * nodes of the same kind. */
extern u32        g_pendingNodeType;                     /* 0x0054204c */

/* Index of the entity whose transform is currently being computed
 * (NodeApplyTransform_*_Direct family loads it as a packed_ptr).
 * Not the same slot as g_currentNodeIdx (= 0x542044). */
extern packed_ptr g_xformEntityIdx;                      /* 0x00542048 */

/* Sticky dirty flags ORed into by every NodeApplyTransform_*_Direct
 * call (low byte gets 0x30 set). */
extern u32        g_xformDirtyFlags;                     /* 0x0054208c */

/* 16-bit angle table read by the *_Direct transforms with a 4-byte
 * stride per entry. */
extern s16        g_nodeAngleTable[];                    /* base offset varies per axis */

/* 16-bit matrix table the second arg of BuildRotMatrix_Order* points
 * into (4-byte stride per entry, indexed by g_currentNodeIdx*2). */
extern s16        g_nodeMatrixTable[];                   /* base 0x00ab5210 area */

/* 6-byte scratch buffer (3 packed s16 angles) the *_Direct family
 * fills with negated angles before calling BuildRotMatrix_Order*. */
extern s16        g_xformTempAngles[3];                  /* 0x00ab5208 */

/* Per-walk callback function pointer (caller sets this before
 * invoking WalkSceneGraphSiblings, the function loads it into a
 * register and tail-calls per-sibling). The slot is reused as a
 * "current sibling" scratch during the walk, hence the unsigned int
 * type and the cast-to-fn-ptr at indirect-call sites. */
extern unsigned int g_walkCallback;                      /* 0x0054206c */

/* Per-state index slot the SetState_XX helpers write alongside
 * g_walkCallback. */
extern u32       g_walkStateIndex;                        /* 0x0053a748 */

/* Sibling table read by WalkSceneGraphSiblings; entries are 4-byte
 * stride and accessed at offsets [idx], [idx+1], [idx+2]. */
extern u32        g_siblingTable[];                       /* base offset varies */

/* Matrix-stack pointer (counter increased by NodeApplyMatrix). */
extern int        g_matrixStackTop;                       /* 0x004d57ac */

/* Per-walk loop counter used by NodeApplyMatrix's outer iteration. */
extern int        g_xformLoopCounter;                     /* 0x0053a1ac */

/* Two parallel matrix stacks (keys + values) read/written by
 * NodeApplyMatrix. */
extern u32        g_matrixStackA[];                       /* RELOC base */
extern u32        g_matrixStackB[];                       /* RELOC base */
extern u32        g_xformChainTable[];                    /* RELOC base */

/* DispatchEventQueue cursor + bounds. The dispatcher walks
 * g_eventQueueHead until it reaches the cached g_eventQueueEnd. */
extern u32        g_eventQueueHead;                       /* 0x0053a2f0 */
extern u32        g_eventQueueEnd;                        /* 0x00542054 */
extern u32        g_eventQueueTotal;                      /* 0x00542050 */
extern u32        g_eventQueueWorkType;                   /* 0x00542074 */

/* Per-frame iterator state used by FightFrameStep_Inner during the
 * sibling-walk phase. _Current holds the active head value, _Child
 * the AND-merged child flags, _Idx the iteration counter (compared
 * against the eventQueueEnd cursor), _NotMask the negated mask used
 * to early-out when the predecessor head was already complete. */
extern u32        g_eventQueueCurrent;                    /* 0x00542070 */
extern u32        g_eventQueueChild;                      /* 0x00542080 */
extern u32        g_eventQueueIdx;                        /* 0x00542058 */
extern u32        g_eventQueueNotMask;                    /* 0x0054207c */

/* Per-entity-group state slot used by FightFrameStep when it
 * primes the entity queue for each of the three sub-trees. */
extern packed_ptr g_fightGroupHead;                       /* 0x0054205c */

/* Sticky scratch slot read+stored by AllocateNode tail (between the
 * working-state copy and `inc edx` of g_nodeAllocCounter). */
extern u32        g_xformScratch2088;                     /* 0x00542088 */

/* Per-allocation counter incremented by AllocateNode at the tail. */
extern u32        g_nodeAllocCounter;                     /* 0x00541e64 */

/* Tail-pointer of the current node-allocation linked list (each
 * node's +0xe4 slot points to the next; AllocateNode walks until
 * +0xe4 is null and appends there). */
extern u32        g_nodeListTail;                          /* 0x0052ab3c */

/* 64 × 0xe8-byte node slot area. The first 0xd8 bytes are user
 * "data", followed by a 16-byte header at +0xd8..+0xe7 (ptr_field,
 * type_word, worktype, next_link). AllocateNode scans this array
 * looking for an empty slot (header.ptr_field == 0). The per-field
 * extern aliases below are slot[0]; AllocateNode indexes them with
 * a `[edx + g_nodeSlotN_*]` (edx = idx*0xe8) addressing form. */
extern u8         g_nodeSlotsArea[];                      /* 0x0053e368 (size 64*0xe8) */
extern u32        g_nodeSlotsHdr_ptrField;                /* 0x0053e440 */
extern u16        g_nodeSlotsHdr_typeWord;                /* 0x0053e444 */
extern u32        g_nodeSlotsHdr_workType;                /* 0x0053e448 */
extern u32        g_nodeSlotsHdr_nextLink;                /* 0x0053e44c */
extern u32        g_nodeSlotsHdr_magic;                   /* 0x0053e43c */
extern u32        g_nodeSlotsHdr_end;                     /* 0x00541e40 */


/* === BuildSortKeyLUT support ================================== */

/* The big working buffer cleared by BuildSortKeyLUT (1056 KB at
 * 0xb2d010 - looks like it backs the 24bpp framebuffer / texture
 * scratch). */
extern u32        g_paletteScratch[0x108000];              /* 0x00b2d010 */

/* 768-byte i/3 table populated by BuildSortKeyLUT's tail. */
extern u8         g_div3Table[768];                        /* 0x00f70ff8 */

/* Helper called by BuildSortKeyLUT after clearing the scratch -
 * does some palette/lighting init, takes one cleared-via-the-call
 * stack arg. */
void Helper_PaletteInit(s32 zero_arg);                    /* 0x004bf0c0 */

#ifdef __cplusplus
}
#endif

#endif /* MK4_ENGINE_SCENEGRAPH_H */
