/**
 * Auto-split from misc_matchesGG.c
 */
#include "engine/scenegraph.h"
#include "portable/ghidra_types.h"
#include "game/tick.h"

/* @addr 0x004cf740 (40b)
 *   FPU control word read/modify (preserves FPU state across helper).
 *   fstcw [ebp-4]; ((arg2 & arg1) | (~arg2 & cw)) → ebp+0xc; fldcw; ret movsx (cw).
 */
#ifdef NON_MATCHING
/* Ghidra-decompiled twin - behavior not yet runtime-verified */
int FpuMaskMerge(void)

{
  short in_FPUControlWord;
  
  return (int)in_FPUControlWord;
}
#else
__declspec(naked) void FpuMaskMerge(void) {
    __asm {
        push    ebp
        mov     ebp, esp
        push    ecx
        fstcw   word ptr [ebp - 4]
        mov     eax, dword ptr [ebp + 0x0c]
        mov     ecx, dword ptr [ebp + 8]
        mov     edx, eax
        and     edx, ecx
        mov     ecx, dword ptr [ebp - 4]
        not     eax
        and     eax, ecx
        or      edx, eax
        mov     dword ptr [ebp + 0x0c], edx
        fldcw   word ptr [ebp + 0x0c]
        movsx   eax, cx
        mov     esp, ebp
        pop     ebp
        ret
    }
}
#endif
