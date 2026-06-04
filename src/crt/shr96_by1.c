/**
 * Auto-split from misc_matchesGG.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

/* @addr 0x004ce2c0 (45b)
 *   96-bit shift right by 1: counterpart of Shl96By1.
 */
/*
 * NON-COAXABLE: MSVC /O2 assigns edi to the first-used callee-saved
 * variable (cd2=high_copy), but orig has edi=cd1=mid_copy; MSVC
 * stores p[2] early and uses a different instruction interleaving.
 * esi/edi allocation order is not controllable from C source.
 */
#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
void Shr96By1(uint *param_1)

{
  uint uVar1;
  
  uVar1 = param_1[1];
  param_1[1] = uVar1 >> 1 | param_1[2] << 0x1f;
  param_1[2] = param_1[2] >> 1;
  *param_1 = *param_1 >> 1 | uVar1 << 0x1f;
  return;
}
#else
__declspec(naked) void Shr96By1(void) {
    __asm {
        mov     eax, dword ptr [esp + 4]
        push    esi
        push    edi
        mov     edx, dword ptr [eax + 8]
        mov     ecx, dword ptr [eax + 4]
        mov     esi, edx
        mov     edi, ecx
        shl     esi, 0x1f
        shr     ecx, 1
        or      ecx, esi
        mov     dword ptr [eax + 4], ecx
        mov     ecx, dword ptr [eax]
        shl     edi, 0x1f
        shr     ecx, 1
        shr     edx, 1
        or      ecx, edi
        pop     edi
        mov     dword ptr [eax + 8], edx
        mov     dword ptr [eax], ecx
        pop     esi
        ret
    }
}
#endif
