/**
 * Auto-split from misc_matchesNN.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
#endif

/* @addr 0x004ba6c0 (85b)
 *   testb 0x10,[dirty]; if set: load g_pendingNodeType; lea ecx=[eax*4 + 0];
 *   load *ecx; copy 4 dwords from there into globals 0x7af990..0x7af9a0;
 *   load dirty; load word ecx[+0x10]; mask 0xef; store; ret 0.
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern s16 g_vtxMat[];
extern unsigned int g_mat3x3_007af994;
extern unsigned int g_mat3x3_007af998;
extern unsigned int g_mat3x3_007af99c;
extern unsigned short g_wtMatExtraWord;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_baseSel (*(unsigned int *)MK4_VA(unsigned int, 0x542060u))
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_mat3x3_007af994 (*(short *)MK4_VA(short, 0x7af994u))
#define g_mat3x3_007af998 (*(short *)MK4_VA(short, 0x7af998u))
#define g_mat3x3_007af99c (*(short *)MK4_VA(short, 0x7af99cu))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_vtxMat ((short *)MK4_VA(short, 0x7af990u))
#define g_wtMatExtraWord (*(short *)MK4_VA(short, 0x7af9a0u))
#define g_xformDirtyFlags (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#endif

#ifdef NON_MATCHING
#include "portable/mem_model.h"

/* Portable twin. Copies the 3x3 matrix - four dwords plus a trailing halfword -
 * out of the pending node into the working matrix, but only when the dirty bit
 * is set, then clears it. `and al, 0xef` is a byte op on the low half, so only
 * bit 4 clears and the upper 24 bits survive. Always returns 0; the caller in
 * RenderSceneNode tests that result. */
int DirtyTestScaledCopy(void)
{
    if ((g_xformDirtyFlags & 0x10) != 0) {
        unsigned int m = g_pendingNodeType;

        /* The 3x3 is NINE PACKED s16 from 0x007af990, and the original moves
         * them as four dwords plus a trailing halfword. Writing through the
         * s16 array a word at a time would be a different access width, so
         * the dword form is kept - see the packed-matrix note in
         * config/global_widths.yaml. */
        *(unsigned int   *)MK4_VA(unsigned int,   0x7af990u) = MK4_NODE_AT(unsigned int, m, 0);
        *(unsigned int   *)MK4_VA(unsigned int,   0x7af994u) = MK4_NODE_AT(unsigned int, m, 4);
        *(unsigned int   *)MK4_VA(unsigned int,   0x7af998u) = MK4_NODE_AT(unsigned int, m, 8);
        *(unsigned int   *)MK4_VA(unsigned int,   0x7af99cu) = MK4_NODE_AT(unsigned int, m, 0xc);
        *(unsigned short *)MK4_VA(unsigned short, 0x7af9a0u) = MK4_NODE_AT(unsigned short, m, 0x10);
        g_xformDirtyFlags &= 0xffffffefu;
    }
    return 0;
}
#else
void DirtyTestScaledCopy(void) {
    __asm {
        test    byte ptr [g_xformDirtyFlags], 0x10
        _emit   74h
        _emit   49h
        mov     eax, dword ptr [g_pendingNodeType]
        lea     ecx, [eax*4 + 0]
        mov     edx, dword ptr [eax*4 + 0]
        mov     dword ptr [g_vtxMat], edx
        mov     eax, dword ptr [ecx + 4]
        mov     dword ptr [g_mat3x3_007af994], eax
        mov     edx, dword ptr [ecx + 8]
        mov     dword ptr [g_mat3x3_007af998], edx
        mov     eax, dword ptr [ecx + 0x0c]
        mov     dword ptr [g_mat3x3_007af99c], eax
        mov     eax, dword ptr [g_xformDirtyFlags]
        mov     cx,  word  ptr [ecx + 0x10]
        and     al,  0xef
        mov     word  ptr [g_wtMatExtraWord], cx
        mov     dword ptr [g_xformDirtyFlags], eax
        xor     eax, eax
        }
}
#endif
