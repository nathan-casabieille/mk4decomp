/**
 * Auto-extracted from misc_matchesQQ.c during reorganization.
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

/* @addr 0x004b9770 (197b engine.render) - dispatch + reorder + scaled chain copy.
 *   call DispatchScaledLEA; ecx = [0x52ab10] + 0x18; g_scaledInit = packed_ptr(0xab4878);
 *   g_xformEntityIdx = ecx; call NodeApplyTransform; pause? -> tail copy.
 *   push 0xab4d58, 0xab4878; call Word9Reorder; add esp, 8.
 *   Two memcpy-shl4 loops: [0x52aa90 .. +9 dwords] = [0xab4878 .. +9 words]*16;
 *     [0x537f50 .. +9 dwords] = [0xab4d58 .. +9 words]*16.
 *   ecx = [0x52ab10] + 0x15 (packed_ptr ofs); g_xformEntityIdx = ecx;
 *   [0xab4d18..0x20] = chain[ecx+0..+8]; [0xab4e24] = chain[ecx+0x58].
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern unsigned int g_currentNodeIdx;
extern unsigned int g_eventQueueSeed;
extern unsigned int g_dispatchSave1551;
extern unsigned int g_dispatchSave1552;
extern unsigned int g_dispatchSave1553;
extern unsigned int g_dispatchSave1569;
#endif
extern void DispatchScaledLEA(void);
extern void NodeApplyTransform_C(void);
#ifdef NON_MATCHING
extern void Word9Reorder(unsigned short *src, unsigned short *dst);
#else
extern void Word9Reorder(void);
#endif

/* --- MK4_ARENA: fixed-VA globals as arena aliases (alias_globals.py) --- */
#ifdef MK4_ARENA
#include "portable/mem_model.h"
#define g_currentNodeIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542044u))
#define g_dispatchSave1551 (*(unsigned int *)MK4_VA(unsigned int, 0xab4d18u))
#define g_dispatchSave1552 (*(unsigned int *)MK4_VA(unsigned int, 0xab4d1cu))
#define g_dispatchSave1553 (*(unsigned int *)MK4_VA(unsigned int, 0xab4d20u))
#define g_dispatchSave1569 (*(unsigned int *)MK4_VA(unsigned int, 0xab4e24u))
#define g_eventQueueSeed (*(unsigned int *)MK4_VA(unsigned int, 0x52ab10u))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_xformEntityIdx (*(unsigned int *)MK4_VA(unsigned int, 0x542048u))
#endif


extern unsigned int g_matrixStack_arr;

#ifdef NON_MATCHING
#include "portable/mem_model.h"

/* Portable twin. Runs the pre-tick transform for the shared matrix pair, then
 * publishes both 3x3s to the two consumers that want them as Q4 DWORDS rather
 * than packed s16 - the `movsx` plus `shl 4` in each loop is a widening, not a
 * copy, so neither destination can be written at the source's access width.
 *
 * The two loops are bounded by ADDRESS in the original (`cmp eax, 0xab488a`),
 * nine elements each. */
void Helper_PreTick(void)
{
    unsigned int seed;
    int i;

    DispatchScaledLEA();
    seed = g_eventQueueSeed;
    g_currentNodeIdx = (unsigned int)MK4_UNPTR(MK4_VA(void, 0xab4878u)) >> 2;
    g_xformEntityIdx = seed + 0x18;
    NodeApplyTransform_C();
    if (g_framePauseFlag != 0)
        return;

    Word9Reorder(MK4_VA(unsigned short, 0xab4878u),
                 MK4_VA(unsigned short, 0xab4d58u));

    for (i = 0; i < 9; i++)
        MK4_VA(int, 0x52aa90u)[i] = (int)MK4_VA(short, 0xab4878u)[i] << 4;
    for (i = 0; i < 9; i++)
        MK4_VA(int, 0x537f50u)[i] = (int)MK4_VA(short, 0xab4d58u)[i] << 4;

    g_xformEntityIdx = seed + 0x15;
    g_dispatchSave1551 = MK4_NODE_AT(unsigned int, g_xformEntityIdx, 0);
    g_dispatchSave1552 = MK4_NODE_AT(unsigned int, g_xformEntityIdx, 4);
    g_dispatchSave1553 = MK4_NODE_AT(unsigned int, g_xformEntityIdx, 8);
    g_dispatchSave1569 = MK4_NODE_AT(unsigned int, seed, 0x58);
}
#else
void Helper_PreTick(void) {
    __asm {
        call    DispatchScaledLEA
        mov     ecx, dword ptr [g_eventQueueSeed]
        mov     eax, 0x00ab4878
        sar     eax, 2
        add     ecx, 0x18
        mov     dword ptr [g_currentNodeIdx], eax
        mov     dword ptr [g_xformEntityIdx], ecx
        call    NodeApplyTransform_C
        mov     eax, dword ptr [g_framePauseFlag]
        test    eax, eax
        _emit   0fh
        _emit   85h
        _emit   91h
        _emit   00h
        _emit   00h
        _emit   00h
        push    0x00ab4d58
        push    0x00ab4878
        call    Word9Reorder
        add     esp, 8
        mov     ecx, 0x0052aa90
        mov     eax, 0x00ab4878
        movsx   edx, word ptr [eax]
        shl     edx, 4
        mov     [ecx], edx
        add     eax, 2
        add     ecx, 4
        cmp     eax, 0x00ab488a
        _emit   7ch
        _emit   0ebh
        mov     ecx, 0x00537f50
        mov     eax, 0x00ab4d58
        movsx   edx, word ptr [eax]
        shl     edx, 4
        mov     [ecx], edx
        add     eax, 2
        add     ecx, 4
        cmp     eax, 0x00ab4d6a
        _emit   7ch
        _emit   0ebh
        mov     ecx, dword ptr [g_eventQueueSeed]
        lea     eax, [ecx + 0x15]
        mov     dword ptr [g_xformEntityIdx], eax
        mov     edx, [eax*4 + g_matrixStack_arr]
        mov     dword ptr [g_dispatchSave1551], edx
        mov     edx, [eax*4 + 4]
        mov     dword ptr [g_dispatchSave1552], edx
        mov     eax, [eax*4 + 8]
        mov     dword ptr [g_dispatchSave1553], eax
        mov     ecx, [ecx*4 + 0x58]
        mov     dword ptr [g_dispatchSave1569], ecx
        }
}


#endif
