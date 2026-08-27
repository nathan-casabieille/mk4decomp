/**
 * Small boot-phase init helpers (one-off matches).
 */
#include "engine/scenegraph.h"
#include "portable/mem_model.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_currentNodeIdx;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_matrixStackTop (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif


/* Table-base extern: &-reference defeats MSVC's constant-folding of
 * `addr >> 2` so the runtime shift survives, matching orig encoding. */
extern unsigned int g_orphanTbl_00538168;   /* 0x00538168 (uninit .data) */

/* @addr 0x004049c0 (14b)
 *   mov     eax, 0x00538168
 *   shr     eax, 2
 *   mov     [g_matrixStackTop], eax
 *   ret
 */
void MStackPackedInit(void) {
    g_matrixStackTop = (int)((unsigned int)MK4_UNPTR(&g_orphanTbl_00538168) >> 2);
}

/* @addr 0x00406ce0 (19b)
 *   mov     eax, [g_currentNodeIdx]
 *   mov     ecx, [g_walkCallback]
 *   mov     [eax*4 + 0x24], ecx
 *   ret
 */
void ScaledStoreIdx24(void) {
    ((ScenegraphNode *)MK4_PTR((g_currentNodeIdx * 4)))->queue_end = (unsigned int)g_walkCallback;
}
