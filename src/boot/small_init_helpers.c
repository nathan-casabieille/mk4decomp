/**
 * Small boot-phase init helpers (one-off matches).
 */
#include "engine/scenegraph.h"

extern unsigned int g_scaledInit_00542044;

/* Table-base extern: &-reference defeats MSVC's constant-folding of
 * `addr >> 2` so the runtime shift survives, matching orig encoding. */
extern unsigned int g_table_00538168;   /* 0x00538168 (uninit .data) */

/* @addr 0x004049c0 (14b)
 *   mov     eax, 0x00538168
 *   shr     eax, 2
 *   mov     [g_matrixStackTop], eax
 *   ret
 */
void MStackPackedInit_004049c0(void) {
    g_matrixStackTop = (int)((unsigned int)&g_table_00538168 >> 2);
}

/* @addr 0x00406ce0 (19b)
 *   mov     eax, [g_scaledInit_00542044]
 *   mov     ecx, [g_walkCallback]
 *   mov     [eax*4 + 0x24], ecx
 *   ret
 */
void ScaledStoreIdx24_00406ce0(void) {
    ((ScenegraphNode *)(g_scaledInit_00542044 * 4))->queue_end = (unsigned int)g_walkCallback;
}
