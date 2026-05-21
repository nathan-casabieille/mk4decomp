/**
 * Auto-split from misc_matchesX.c
 */
#include "engine/scenegraph.h"
#include "game/tick.h"

extern unsigned int g_baseSel_00542060;
extern unsigned int g_scaledInit_00542044;
extern u32 g_eventQueueWorkType;
extern packed_ptr g_xformEntityIdx;
extern u32 g_pendingNodeType;
extern const int g_sinTable[];
extern void Mul10Tail_00404af0(void);

/* @addr 0x004250f0 (61b)
 *   3-component vector subtract: out[i] = a[i] - b[i] across i=0,1,2
 *   a = [g_xformEntityIdx*4], b = [g_pendingNodeType*4],
 *   out = [g_currentNodeIdx*4]
 */
__declspec(naked) void TripleSubVec3_004250f0(void) {
    __asm {
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     edx, dword ptr [g_pendingNodeType]
        mov     eax, dword ptr [g_scaledInit_00542044]
        push    esi
        shl     ecx, 2
        shl     edx, 2
        mov     esi, dword ptr [ecx]
        push    edi
        mov     edi, dword ptr [edx]
        shl     eax, 2
        sub     esi, edi
        mov     dword ptr [eax], esi
        mov     esi, dword ptr [ecx + 4]
        mov     edi, dword ptr [edx + 4]
        sub     esi, edi
        pop     edi
        mov     dword ptr [eax + 4], esi
        mov     ecx, dword ptr [ecx + 8]
        mov     esi, dword ptr [edx + 8]
        sub     ecx, esi
        pop     esi
        mov     dword ptr [eax + 8], ecx
        ret
    }
}
