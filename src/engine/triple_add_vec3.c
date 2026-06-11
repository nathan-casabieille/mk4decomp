/**
 * Auto-split from misc_matchesX.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

extern unsigned int g_baseSel;
extern unsigned int g_currentNodeIdx;
extern void Mul10Tail(void);

/* @addr 0x00425130 (61b)
 *   3-component vector add: out[i] = a[i] + b[i] across i=0,1,2
 *   (variant of 0x004250f0 with `add` and slight reg reordering)
 */
/*
 * NON-COAXABLE: for component 2, MSVC /O2 always picks ecx (A ptr) as the
 * accumulator for the commutative add, reusing it for out[2] = A[2]+B[2].
 * Orig uses edx (B ptr) as accumulator instead. Register choice for
 * commutative addition cannot be controlled from C source.
 */
#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void TripleAddVec3(void)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  piVar2 = (int *)(g_eventQueuePending * 4);
  piVar3 = (int *)(g_dualC * 4);
  piVar1 = (int *)((g_currentNodeIdx) * 4);
  *piVar1 = *piVar3 + *piVar2;
  piVar1[1] = piVar2[1] + piVar3[1];
  piVar1[2] = piVar3[2] + piVar2[2];
  return;
}
#else
__declspec(naked) void TripleAddVec3(void) {
    __asm {
        mov     ecx, dword ptr [g_xformEntityIdx]
        mov     edx, dword ptr [g_pendingNodeType]
        mov     eax, dword ptr [g_currentNodeIdx]
        push    esi
        shl     ecx, 2
        shl     edx, 2
        push    edi
        mov     edi, dword ptr [ecx]
        mov     esi, dword ptr [edx]
        shl     eax, 2
        add     esi, edi
        mov     dword ptr [eax], esi
        mov     esi, dword ptr [ecx + 4]
        mov     edi, dword ptr [edx + 4]
        add     esi, edi
        pop     edi
        mov     dword ptr [eax + 4], esi
        mov     edx, dword ptr [edx + 8]
        mov     esi, dword ptr [ecx + 8]
        add     edx, esi
        pop     esi
        mov     dword ptr [eax + 8], edx
        ret
    }
}
#endif
