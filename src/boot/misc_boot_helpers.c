/**
 * Boot-phase miscellaneous helpers.
 *
 * Three unrelated boot-phase functions that don't fit the scaled-pushpop or
 * scaled-init categories:
 *   - StackPushAdd15CallPop: mstack-save g_eventQueueEnd, add 0x15, call, restore
 *   - PushCallScaledClearJmp: chain init w/ dirty-bit dispatch
 *   - ExtractBitsToVec3: extract three bit-fields from g_walkCallback into a vec3
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
#define g_dispatchSave1131 (*(unsigned int *)MK4_VA(unsigned int, 0x408040u))
#define g_eventQueueCurrent (*(unsigned int *)MK4_VA(unsigned int, 0x542070u))
#define g_eventQueueEnd (*(unsigned int *)MK4_VA(unsigned int, 0x542054u))
#define g_fightGroupHead (*(unsigned int *)MK4_VA(unsigned int, 0x54205cu))
#define g_framePauseFlag (*(unsigned int *)MK4_VA(unsigned int, 0x541e6cu))
#define g_matrixStackTop (*(unsigned int *)MK4_VA(unsigned int, 0x4d57acu))
#define g_pendingNodeType (*(unsigned int *)MK4_VA(unsigned int, 0x54204cu))
#define g_walkCallback (*(unsigned int *)MK4_VA(unsigned int, 0x54206cu))
#define g_xformDirtyFlags (*(unsigned int *)MK4_VA(unsigned int, 0x54208cu))
#endif

/* @addr 0x0040a7e0 (69b)
 *   push g_eventQueueEnd, add 0x15, restore at end after call.
 */
extern void Copy3Fields38(void);
void StackPushAdd15CallPop(void) {
    g_matrixStackTop++;
#ifdef MK4_ARENA
    *MK4_NODE(unsigned int, g_matrixStackTop) = g_eventQueueEnd;
#else
    *(unsigned int *)(g_matrixStackTop * 4) = g_eventQueueEnd;
#endif
    g_eventQueueEnd = g_eventQueueEnd + 0x15;
    Copy3Fields38();
#ifdef MK4_ARENA
    g_eventQueueEnd = *MK4_NODE(unsigned int, g_matrixStackTop);
#else
    g_eventQueueEnd = *(unsigned int *)(g_matrixStackTop * 4);
#endif
    g_matrixStackTop--;
}

/* @addr 0x0040bf20 (66b)
 *   push 0x408040; call F; load g_fightGroupHead; push it; call F2;
 *   clear g_scaledInit; call F3; pause-test → ret;
 *   testb 4,[dirty]; if cleared then jmp T; ret.
 */
#ifndef MK4_ARENA   /* aliased below for the relocated targets */
extern void *g_dispatchSave1131;
#endif


extern void ThreeChanPackClamp(void *);
extern void CopyThreeFields(int);
extern void func_00405420_ii(void);
extern void BootMStackBracketedScaledStores(void);
void PushCallScaledClearJmp(void) {
    ThreeChanPackClamp(&g_dispatchSave1131);
    CopyThreeFields(g_fightGroupHead);
    g_currentNodeIdx = 0;
    func_00405420_ii();
    if (g_framePauseFlag) return;
    if (g_xformDirtyFlags & 4) {
        BootMStackBracketedScaledStores();
        return;
    }
}

/* @addr 0x00407c00 (88b)
 *   triple bit-extract from g_walkCallback: low 11 bits, mid 11 bits, high 10 bits;
 *   store each into a 3-vec at g_pendingNodeType*4 with stride 4.
 */

#ifdef NON_MATCHING
#include "portable/mem_model.h"

/* NATIVE twin: three 11-bit fields of the walk value unpacked into the
 * vec3 at the pending index - low and middle scaled by two, the top ten
 * bits by four. */
void ExtractBitsToVec3(void)
{
    unsigned int w = g_walkCallback;
    unsigned int p = g_pendingNodeType;
    unsigned int v;

    *MK4_NODE(unsigned int, p) = (w & 0x7ffu) << 1;
    v = ((w >> 11) & 0x7ffu) << 1;
    g_eventQueueCurrent = v;
    MK4_NODE_AT(unsigned int, p, 4) = v;
    v = (w >> 22) << 2;
    g_walkCallback = v;
    MK4_NODE_AT(unsigned int, p, 8) = v;
}
#else
void ExtractBitsToVec3(void) {
    __asm {
        mov     eax, dword ptr [g_walkCallback]
        mov     ecx, dword ptr [g_pendingNodeType]
        and     eax, 0x7ff
        shl     eax, 1
        mov     dword ptr [ecx*4 + 0], eax
        mov     eax, dword ptr [g_walkCallback]
        mov     edx, dword ptr [g_pendingNodeType]
        shr     eax, 0x0b
        and     eax, 0x7ff
        shl     eax, 1
        mov     dword ptr [g_eventQueueCurrent], eax
        mov     dword ptr [edx*4 + 4], eax
        mov     eax, dword ptr [g_walkCallback]
        mov     ecx, dword ptr [g_pendingNodeType]
        shr     eax, 0x16
        shl     eax, 2
        mov     dword ptr [g_walkCallback], eax
        mov     dword ptr [ecx*4 + 8], eax
        }
}
#endif

