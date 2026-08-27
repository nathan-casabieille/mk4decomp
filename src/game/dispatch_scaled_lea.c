/**
 * Auto-split from misc_matchesPP.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_currentNodeIdx;
#endif

/* @addr 0x004b8f50 (70b)
 *   ecx = [0xab4e2c]; edx = [0xab4e30]; eax = [0x52aac4];
 *   if ecx != edx: store ecx → [0xab4e30].
 *   if eax == 2: eax = [0x53a50c]; eax *= 3; ecx = eax*2 + 0x4f6240;
 *     store ecx → [0xab4e2c]; ret.
 *   else: edx = eax*3; eax = edx*2 + 0x4f62a8; store → [0xab4e2c]; ret.
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_dispatchSave1571;
extern unsigned int g_phaseIdx;
extern unsigned int g_tickFlagF;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dispatchSave1571 (*(unsigned int *)MK4_VA(unsigned int, 0xab4e30u))
#define g_phaseIdx (*(unsigned int *)MK4_VA(unsigned int, 0x53a50cu))
#define g_tickCurConfig (*(unsigned int *)MK4_VA(unsigned int, 0xab4e2cu))
#define g_tickFlagF (*(unsigned int *)MK4_VA(unsigned int, 0x52aac4u))
#endif


#ifdef NON_MATCHING
#include "portable/mem_model.h"

/* Portable twin. Picks the tick config record for the frame: one of two
 * six-byte-strided tables, 0x004f6240 or 0x004f62a8.
 *
 * The two paths do NOT index by the same thing, which is easy to miss - eax
 * holds g_tickFlagF from entry and is only reloaded with g_phaseIdx on the
 * `== 2` path, so the fallback scales the FLAG. The stored value is a VA, as
 * in the original: every consumer dereferences g_tickCurConfig through the
 * seam. */
void DispatchScaledLEA(void)
{
    unsigned int cfg  = g_tickCurConfig;
    unsigned int flag = g_tickFlagF;

    if (cfg != g_dispatchSave1571)
        g_dispatchSave1571 = cfg;

    if (flag == 2)
        g_tickCurConfig = 0x004f6240u + g_phaseIdx * 6u;
    else
        g_tickCurConfig = 0x004f62a8u + flag * 6u;
}
#else
void DispatchScaledLEA(void) {
    __asm {
        mov     ecx, dword ptr [g_tickCurConfig]
        mov     edx, dword ptr [g_dispatchSave1571]
        mov     eax, dword ptr [g_tickFlagF]
        cmp     ecx, edx
        _emit   74h
        _emit   06h
        mov     dword ptr [g_dispatchSave1571], ecx
        cmp     eax, 2
        _emit   75h
        _emit   16h
        mov     eax, dword ptr [g_phaseIdx]
        lea     eax, [eax + eax*2]
        lea     ecx, [eax*2 + 0x004f6240]
        mov     dword ptr [g_tickCurConfig], ecx
        ret
        lea     edx, [eax + eax*2]
        lea     eax, [edx*2 + 0x004f62a8]
        mov     dword ptr [g_tickCurConfig], eax
        }
}

#endif
