/**
 * Boot-phase scaled-init field manipulators.
 *
 * Three hybrid/pure-C helpers that read or modify the scaled-init / dirty-flag
 * state during boot. Two are hybrid because of MSVC SP3 flag-preservation
 * across stores; one is pure C.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_currentNodeIdx;
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_eventQueueCurrent (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_eventQueueEnd (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformDirtyFlags (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#endif


/* @addr 0x004084b0 (81b)
 *   load scaled, eventQueueCurrent; load scaled[+0x1c] into eax;
 *   if eventQueueCurrent < eax, store eax into eventQueueCurrent;
 *   load scaled[0]; if non-zero set walk = own VA, call F, pause-test;
 *   clear dirty bit 1; ret.
 */
extern void Helper_TickAlt(void);
extern void BootGatedInitInstallPair(void);
extern void SlotInitAndChainLink(void);

#ifdef NON_MATCHING
#include "portable/mem_model.h"
#include "portable/code_va.h"
/* @addr 0x004084b0 (81b) - NATIVE twin.
 *
 * Raises the element counter to the node's +0x1c value if that is larger,
 * then, when the node's word 0 is set, re-installs ITSELF as the walk
 * callback and runs the alt tick over it. Clearing dirty bit 0 on the way
 * out is the "counted" signal the list installer above reads. */
void ScaledLoadCallSet1c(void)
{
    unsigned int lim = MK4_NODE_AT(unsigned int, g_currentNodeIdx, 0x1c);
    unsigned int w;

    if ((int)g_eventQueueCurrent < (int)lim)
        g_eventQueueCurrent = lim;

    w = *MK4_NODE(unsigned int, g_currentNodeIdx);
    g_walkCallback = w;
    if (w != 0) {
        g_walkCallback = MK4_CODE_VA(ScaledLoadCallSet1c);
        Helper_TickAlt();
        if (g_framePauseFlag != 0) return;
    }
    g_xformDirtyFlags &= 0xfffffffeu;
}
#else
void ScaledLoadCallSet1c(void) {
    __asm {
        mov     ecx, dword ptr [g_currentNodeIdx]
        mov     edx, dword ptr [g_eventQueueCurrent]
        mov     eax, dword ptr [ecx*4 + 0x1c]
        cmp     edx, eax
        _emit   7dh
        _emit   05h
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     eax, dword ptr [ecx*4 + 0]
        test    eax, eax
        mov     dword ptr [g_walkCallback], eax
        _emit   74h
        _emit   18h
        mov     dword ptr [g_walkCallback], 0x004084b0
        call    Helper_TickAlt
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   75h
        _emit   0ch
        mov     eax, dword ptr [g_xformDirtyFlags]
        and     al,  0xfe
        mov     dword ptr [g_xformDirtyFlags], eax
        }
}
#endif

/* @addr 0x004147b0 (87b)
 *   set dirty |= 4; if g_scaledInit != 0:
 *     dirty ^= 4 (back); load scaled+0x18 → scaled; load scaled+0x28 → eax;
 *     set walk = 0x414600 + store at [eax*4 + 0x10]; ret.
 */
#ifndef NON_MATCHING
void SetDirty4XorScaledLoad(void) {
    __asm {
        mov     eax, dword ptr [g_xformDirtyFlags]
        mov     ecx, 4
        or      eax, ecx
        mov     dword ptr [g_xformDirtyFlags], eax
        mov     eax, dword ptr [g_currentNodeIdx]
        test    eax, eax
        _emit   74h
        _emit   3ch
        mov     edx, dword ptr [g_xformDirtyFlags]
        xor     edx, ecx
        test    eax, eax
        mov     dword ptr [g_xformDirtyFlags], edx
        _emit   74h
        _emit   2ah
        mov     eax, dword ptr [eax*4 + 0x18]
        mov     ecx, 0x00414600
        mov     dword ptr [g_currentNodeIdx], eax
        mov     eax, dword ptr [eax*4 + 0x28]
        mov     dword ptr [g_walkCallback], ecx
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [eax*4 + 0x10], ecx
        }
}
#endif

/* @addr 0x004196c0 (83b)
 *   call F; pause → ret; testb 4,[dirty] → ret;
 *   load g_eventQueueEnd; mov [eax*4 + 0x30]=0x81; load g_xformEntityIdx;
 *   set walk = 0x14ccc + store at [ecx*4 + 0x48]; eventQueueEnd+0x15 → g_scaledInit;
 *   jmp T.
 */
void CallPauseDirty4ScaledSet_tag_0x81(void) {
    SlotInitAndChainLink();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 4) return;
#ifdef MK4_ARENA
    MK4_NODE_AT(unsigned int, g_eventQueueEnd, 0) = 0x81;
#else
    ((FightGroupNode *)(g_eventQueueEnd * 4))->tag = 0x81;
#endif
    g_walkCallback = 0x14ccc;
#ifdef MK4_ARENA
    MK4_NODE_AT(unsigned int, g_xformEntityIdx, 0x48) = 0x14ccc;
#else
    *(unsigned int *)(g_xformEntityIdx * 4 + 0x48) = 0x14ccc;
#endif
    g_currentNodeIdx = g_eventQueueEnd + 0x15;
    BootGatedInitInstallPair();
}

