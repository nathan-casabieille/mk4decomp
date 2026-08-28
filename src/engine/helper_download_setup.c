/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x0048bc40 (174b game) - mstack-push 2, table-search nonzero, mstack-pop 2. */
extern unsigned int g_matrixStack_arr;
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_dispatchArg;
extern unsigned int g_currentNodeIdx;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dispatchArg (*(unsigned int *)MK4_VA(unsigned int, 0x535e48u))
#define g_matrixStackTop (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#endif


#ifdef NON_MATCHING
#include "portable/mem_model.h"
/* @addr 0x0048bc40 (174b) - NATIVE twin.
 *
 * Resolves the scene node for the character in g_walkCallback. The table
 * at 0x4f02d0 holds one entry per eight node words; the scan starts at
 * character*8 and steps by eight, skipping empty slots. A NEGATIVE entry
 * means "wrap" - the scan restarts from the table base - and the first
 * positive entry ends it, leaving g_currentNodeIdx pointing at that slot.
 * That node is what DownloadPlayerChar then hangs the geometry on. Both
 * scratch globals are bracketed on the matrix stack. */
void Helper_DownloadSetup(void)
{
    unsigned int base = 0x4f02d0u >> 2;
    unsigned int off, v;

    g_matrixStackTop++;
    *MK4_NODE(unsigned int, g_matrixStackTop) = g_walkCallback;
    g_matrixStackTop++;
    *MK4_NODE(unsigned int, g_matrixStackTop) = g_dispatchArg;

    off = g_walkCallback * 8u;
    g_dispatchArg = off;
    g_currentNodeIdx = base;
    for (;;) {
        v = *MK4_NODE(unsigned int, base + off);
        g_walkCallback = v;
        if (v != 0) {
            if ((int)v >= 0) break;
            off = 0;
            g_dispatchArg = 0;
            continue;
        }
        off += 8;
        g_dispatchArg = off;
    }
    g_currentNodeIdx = base + off;

    g_dispatchArg = *MK4_NODE(unsigned int, g_matrixStackTop);
    g_matrixStackTop--;
    g_walkCallback = *MK4_NODE(unsigned int, g_matrixStackTop);
    g_matrixStackTop--;
}
#else
void Helper_DownloadSetup(void) {
    __asm {
        mov     eax, dword ptr [g_matrixStackTop]
        mov     ecx, dword ptr [g_walkCallback]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + g_matrixStack_arr], ecx
        mov     eax, dword ptr [g_matrixStackTop]
        mov     edx, dword ptr [g_dispatchArg]
        inc     eax
        mov     dword ptr [g_matrixStackTop], eax
        mov     dword ptr [eax*4 + g_matrixStack_arr], edx
        mov     eax, dword ptr [g_walkCallback]
        mov     edx, 0x004f02d0
        lea     ecx, [eax*8 + 0]
        shr     edx, 2
        mov     dword ptr [g_dispatchArg], ecx
        mov     dword ptr [g_currentNodeIdx], edx
        lea     eax, [edx + ecx]
        mov     eax, dword ptr [eax*4 + 0]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   75h
        _emit   0bh
        add     ecx, 8
        mov     dword ptr [g_dispatchArg], ecx
        _emit   0ebh
        _emit   0e2h
        _emit   7dh
        _emit   0ah
        xor     ecx, ecx
        mov     dword ptr [g_dispatchArg], ecx
        _emit   0ebh
        _emit   0d6h
        mov     eax, dword ptr [g_matrixStackTop]
        add     edx, ecx
        mov     dword ptr [g_currentNodeIdx], edx
        mov     ecx, dword ptr [eax*4 + g_matrixStack_arr]
        dec     eax
        mov     dword ptr [g_dispatchArg], ecx
        mov     dword ptr [g_matrixStackTop], eax
        mov     edx, dword ptr [eax*4 + g_matrixStack_arr]
        dec     eax
        mov     dword ptr [g_walkCallback], edx
        mov     dword ptr [g_matrixStackTop], eax
        }
}
#endif


